module UserFeedbackTextStyle = {
  open Css;

  let text = style([
    fontSize(em(1.5)),
    textAlign(center),
    margin2(~v=px(10), ~h=px(10)),
    color(white)
  ])
}

[@react.component]
let make = (~text) =>
  <h5 className=UserFeedbackTextStyle.text>{React.string(text)}</h5>