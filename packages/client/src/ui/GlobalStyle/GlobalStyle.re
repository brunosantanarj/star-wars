let style = {j|
  * {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
  }
  
  :root {
    --primary-color: #d2c22c;
    --secondary-color: #dedccf;
    --size: 16px;
    --size-md: 25px;
    --size-lg: 41px;
    --size-xl: 67px;
  }
  
  html, body {
    position: relative;
    width: 100%;
    height: 100%;
    padding-bottom: 20px;
    font-family: 'Coustard', serif;
  }
  
  @keyframes move-twink-back {
    from {
      background-position: 0 0;
    }
    to {
      background-position: -10000px 5000px;
    }
  }
  
  body, body:before {
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    width: 100%;
    height: 100%;
    display: block;
  }
  
  body {
    background: #000 url(http://www.script-tutorials.com/demos/360/images/stars.png) repeat top center;
    z-index: 0;
    color: #333;
    font-family: 'Coustard', serif;
    font-size: var(--size);
  }
  
  body:before {
    content: '';
    background: transparent url(http://www.script-tutorials.com/demos/360/images/twinkling.png) repeat top center;
    z-index: 1;
    animation: move-twink-back 200s linear infinite;
  }

  .lds-ripple {
    position: relative;
    width: 64px;
    height: 64px;
    margin: 20px auto;
  }

  .circle {
    position: absolute;
    border: 4px solid #fff;
    opacity: 1;
    border-radius: 50%;
    animation: lds-ripple 1s cubic-bezier(0, 0.2, 0.8, 1) infinite;
  }

  .circle-out {
    animation-delay: -0.5s;
  }

  @keyframes lds-ripple {
    0% {
      top: 28px;
      left: 28px;
      width: 0;
      height: 0;
      opacity: 1;
    }
    100% {
      top: -1px;
      left: -1px;
      width: 58px;
      height: 58px;
      opacity: 0;
    }
  }
|j};
