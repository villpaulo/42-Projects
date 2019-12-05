
import React from "react";

export default class Filme extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            likeOrDislike: false,
        };
    }
    
    render() {
        const post = this.props.data;
        return (
        
            <div className="card flex-item"> 
                <div className="container">
                <h4><b>{post.title}</b> </h4> 
                <p>{post.media_type}</p> 
                <img src={post.poster_path} className="post-img"/>
                <p> {post.overview} </p>
                <span className="delete-movie"    onClick={() => this.props.handleClick(post.id)}>
                <i className="fa fa-trash"></i>
                </span>
                </div>
            </div>
            );
    }
   
}
