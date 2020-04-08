[@react.component]
let make = () =>
  <>
    <div className="lds-ripple">
      <div className="lds-ripple_first circle" />
      <div className="lds-ripple_out circle circle-out" />
    </div>
    <UserFeedbackText text="Estamos buscando os dados, aguarde um momento" />
  </>