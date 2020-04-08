module CharacterCardStyle = {
  open Css;

  let cardContainer = style([
    maxWidth(px(600)),
    backgroundColor(hex("dedccf")),
    padding(px(25)),
    margin3(~top=px(16), ~h=auto, ~bottom=px(16)),
    textAlign(center),
    borderRadius(px(10))
  ]);

  let title = style([
    textAlign(center),
    fontSize(em(2.0))
  ]);

  let image = style([
    maxWidth(pct(100.0)),
    maxHeight(px(500)),
    margin2(~v= px(16), ~h=px(0))
  ])
}

[@react.component]
let make = (~character: CharacterType.contract) => {
  let count = Array.length(character.starships);
  let correctSpelling = count === 1 ? "nave espacial" : "naves espaciais";

  <article className=CharacterCardStyle.cardContainer>
    <h4 className=CharacterCardStyle.title>
      {React.string(character.name)}
    </h4>
    <img src=character.image className=CharacterCardStyle.image />
    <p>
      {React.string(
        "Nasceu no ano de "
        ++ character.birty_year
        ++ " e pesa "
        ++ character.height
        ++ "kgs"
      )}
    </p>

    {if(count === 0) {
      <p>{React.string("Esse personagem não possui naves espaciais.")}</p>
    } else {
      <>
        <p>
          {React.string(
            "Possui "
            ++ string_of_int(count)
            ++ " "
            ++ correctSpelling
          )}
        </p>
        <Button>
            {React.string("Ver naves")}
        </Button>
      </>
    }}
  </article>
}
