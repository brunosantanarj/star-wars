module ButtonStyles = {
  open Css;

  let button = style([
    backgroundColor(hex("d2c22c")),
    padding2(~v=px(15), ~h=px(30)),
    borderRadius(px(25)),
    margin3(~top=px(20), ~h=auto, ~bottom=px(10)),
    display(block),
    fontSize(em(1.0)),
    fontFamily(inherit_),
    textTransform(uppercase),
    cursor(pointer),
    lineHeight(em(1.0)),
  ])
}

[@react.component]
let make = (~children) => 
  <button className=ButtonStyles.button>
    {children}
  </button>