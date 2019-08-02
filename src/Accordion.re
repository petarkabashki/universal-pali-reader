/* [@bs.obj]
external makeProps: (~children: 'children, ~key: string=?, unit) => {. "children": 'children} = "";

[@bs.module "react-bootstrap/Accordion.js"]
external make: ({. "children": string}) => React.element = "default"; */

/* [@bs.module "react-bootstrap/Accordion.js"][@react.component]
external make: (~children=React.null) => React.element = "default"; */

[@bs.module][@react.component]
external make: (~children: 'children) => React.element = "react-bootstrap/Accordion.js"; 

module Toggle {
    [@bs.module "react-bootstrap/Accordion.js"][@react.component]
    external make: (~as_: 'as_, ~eventKey: 'eventKey, ~children: 'children) => React.element = "Toggle"; 
}

module Collapse {
    [@bs.module "react-bootstrap/Accordion.js"][@react.component]
    external make: (~eventKey: 'eventKey, ~children: 'children) => React.element = "Collapse"; 
}
