[@bs.val] external document: Js.t({..}) = "document";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= GlobalStyle.style;

let makeContainer = () => {

  let content = document##createElement("div");
  content##id #= "app";
  let () = document##body##appendChild(content);

  content;
};

ReactDOMRe.render(
  <Container />,
  makeContainer(),
);
