/* [@bs.module "./Welcome.jsx"]
[@react.component]
external make: (~name: string, ~children: react.element) => React.element = "default"; */

/* [@bs.module "react-bootstrap/Card.js"] */

[@bs.module][@react.component]
external make: (~children: 'children) => React.element = "react-bootstrap/Card.js"; 

module Header {
    [@bs.module "react-bootstrap/Card.js"][@react.component]
    external make: (~children: 'children) => React.element = "Header"; 
}

module Body {
    [@bs.module "react-bootstrap/Card.js"][@react.component]
    external make: (~children: 'children) => React.element = "Body"; 
}
