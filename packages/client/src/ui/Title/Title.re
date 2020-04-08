module TitleStyles = {
  open Css;

  let title = style([
    fontSize(em(4.0)),
    textAlign(center),
    marginTop(px(41)),
    color(hex("d2c22c"))
  ]);
};

[@react.component]
let make = (~children) => <h1 className=TitleStyles.title>{children}</h1>