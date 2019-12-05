import React from "react";

export default class Filtre extends React.Component {

    constructor(props) {
        super(props);
        this.state = { value: ' ' }
        this.handleChange = this.handleChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }
    handleChange(e) {
        this.setState({ value: e.target.value })
    }

    handleSubmit(event) {
        this.props.filter(this.state.value)
        event.preventDefault()
    }

    render() {
        return (
            <div>
                <form onSubmit={this.handleSubmit}>
                <label> Select Items by Title </label>
                    <input type="text" onChange={this.handleChange} value={this.state.value} />
                    <input type="submit" value="Search" />
                </form>
            </div>
        );
    }
}