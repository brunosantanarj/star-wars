[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";
[@bs.val] [@bs.scope "document"]
external querySelector: string => Dom.element = "querySelector";

type state = 
  | FetchingCharacters
  | FetchingError
  | FetchingSuccess(array(CharacterType.contract));

[@react.component]
let make = () => {
  /* let containerRef = React.useRef(Js.Nullable.null); */
  let (characters, setCharacters) = React.useState(() => FetchingCharacters);
  let (page, setPage) = React.useState(() => 1)

  let fetchCharacters = () => {
    Js.Promise.(
      fetch("http://localhost:3000/public/peoples?page=" ++ string_of_int(page))
      |> then_(response => response##json())
      |> then_((jsonResponse) => {
        setCharacters(_prevState => FetchingSuccess(jsonResponse##data##results));
        setPage(_prevState => jsonResponse##data##next);
        Js.Promise.resolve();
      })
      |> catch(_err => {
        setCharacters(_prevState => FetchingError);
        Js.Promise.resolve();
      })
      |> ignore
    );
  };

  let observer = BsIntersectionObserver.Create.intersectionObserver(
    ~cb=(entries, _) => {
      Belt.Array.map(entries, entry => {
        if (entry.isIntersecting) {
          Js.log("NOS");
          fetchCharacters();
        }
      })
      ->ignore;
      ();
    },
    ~options=None,
  );

  React.useEffect1(() => {
    let el = querySelector(".containerRef");
    observer.observe(el);
    Some(() => observer.unobserve(el));

  }, [|page|]);

  <section className="containerRef">
    {switch(characters) {
      | FetchingError => <UserFeedbackText text="Houveram problemas e não conseguimos buscar os personagens" />
      | FetchingCharacters => <Loading />
      | FetchingSuccess(allCharacters) => allCharacters
        ->Belt.Array.map((character) => <CharacterCard character=character />)
        ->React.array
    }}
  </section>
};
