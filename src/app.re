
[@react.component]
let make = () => {
  /* <Welcome>
    {ReasonReact.string("Click me!")}
  </Welcome> */
  let cardHeader = (~children) => <Card.Header>children</Card.Header>;

  <Accordion>
    <Card>
      <Accordion.Toggle as_={cardHeader} eventKey="0">
        {ReasonReact.string("Click me!")}
      </Accordion.Toggle>
      <Accordion.Collapse eventKey="0">
        <Card.Body>{ReasonReact.string("Hello! I'm the body")}</Card.Body>
      </Accordion.Collapse>
    </Card>
    <Card>
      <Accordion.Toggle as_={cardHeader} eventKey="1">
        {ReasonReact.string("Click me! 002")}
      </Accordion.Toggle>
      <Accordion.Collapse eventKey="1">
        <Card.Body>{ReasonReact.string("Hello! I'm the body 002")}</Card.Body>
      </Accordion.Collapse>
    </Card>
    <Card>
      <Accordion.Toggle as_={cardHeader} eventKey="2">
        {ReasonReact.string("Click me! 003")}
      </Accordion.Toggle>
      <Accordion.Collapse eventKey="2">
        <Card.Body>{ReasonReact.string("Hello! I'm the body 003")}</Card.Body>
      </Accordion.Collapse>
    </Card>
  </Accordion>
  };
    /* <Card>
      <Accordion.Toggle as_={Card.Header} eventKey="0">
      {ReasonReact.string("Click me!")}
      </Accordion.Toggle>
      <Accordion.Collapse eventKey="0">
        <Card.Body>{ReasonReact.string("Hello! I'm the body")}</Card.Body>
      </Accordion.Collapse>
    </Card> */


    /* <p> {ReasonReact.string("Click me!")}</p>
    <p>{ReasonReact.string("Hello! I'm the body")}</p> */