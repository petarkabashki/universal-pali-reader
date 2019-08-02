let str = ReasonReact.string;

let url = "https://tipitaka.org/romn/tipitaka_toc.xml";


type tree = {
  text: string,
  src: string
  /* children: Option(array(tree)) */
};

type treeList = list(tree);


type state =
  | NotAsked
  | Loading
  | Failure
  | Success(list(tree));

type action =
  | LoadTopics
  | LoadedTopics(list(tree))
  | LoadTopicsFailed;

module Decode = {
  /* let tree = tree => {text : "Tipitaka", src: "opalapa.xml" }; */
    /* Json.Decode.{
      id: field("id", int, user),
      name: field("name", string, user),
    }; */
  /* let users = json : list(user) => Json.Decode.list(user, json); */
  let tree = text => [ {text : "Tipitaka", src: "opalapa.xml" } ];
};

let fetchTopics = () =>
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.text)
    |> then_(text =>
        text |> Decode.tree |> (topics => Some(topics) |> resolve)
      )
    |> catch(_err => resolve(None))
  );


/* let component = ReasonReact.reducerComponent("Tipitaka"); */
[@react.component]
let make = _children => {
  ...component,
  initialState: () => NotAsked,
  reducer: (action, _state) =>
    switch (action) {
    | LoadTopics =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              fetchTopics()
              |> then_(result =>
                   switch (result) {
                   | Some(topics) => resolve(self.send(LoadedTopics(topics)))
                   | None => resolve(self.send(LoadTopicsFailed))
                   }
                 )
              |> ignore
            )
        ),
      )
    | LoadedTopics(topics) => ReasonReact.Update(Success(topics))
    | LoadTopicsFailed => ReasonReact.Update(Failure)
    },

    
  render: self =>
    switch (self.state) {
    | NotAsked =>
      <div>
        (str("Click to start load Topics"))
        <button onClick=(_event => self.send(LoadTopics))>
          (str("Load Topics"))
        </button>
      </div>
    | Loading => <div> (str("Loading...")) </div>
    | Failure => <div> (str("Something went wrong!")) </div>
    | Success(topics) =>
      <div>
        <h2> (str("Topics")) </h2>
        <ul>
          (
            topics
            |> List.map(topic =>
                 <li key=(topic.text)> (str(topic.text)) </li>
               )
            |> Array.of_list
            |> ReasonReact.array
          )
        </ul>
      </div>
    },
};

/* let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||])); */

/* 
[@react.component]
let make = () => {
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
   */