import React from "react";

class Welcome extends React.Component {
    render() {
      return React.createElement("div", null, React.createElement("h1", null, "Hello, this.props.name"), React.createElement("div", null, this.props.children));
    }
}