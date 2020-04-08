module Styles = {

  let container = Css.[
    position(relative),
    zIndex(2),
    paddingLeft(px(20)), 
    paddingRight(px(20))
  ];

  let largeBreakpoint = Css.[
    media("(min-width: 992px)", [
      maxWidth(pct(80.0)),
      margin(auto)
    ])
  ]; 

  let allStyles = [container, largeBreakpoint]->List.concat->Css.style;
};

[@react.component]
let make = () =>
  <div className=Styles.allStyles>
    <Title>{React.string("STAR WARS")}</Title>
    <Characters />
  </div>