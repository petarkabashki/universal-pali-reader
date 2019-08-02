/* [@bs.module "./Welcome.js"][@react.component]
external make: (~children: 'children) => React.element = "default"; */


/* [@react.component]
let make = (~name, ~children) => {
  <div>
    <p> {React.string("Hello, " ++ name)} </p>
    children
  </div>
}; */


[@bs.module][@react.component]
external make: (~children: 'children) => React.element = "react-bootstrap/Card.js"; 

