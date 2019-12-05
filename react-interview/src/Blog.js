import React from "react";
import axios from 'axios'

import Filtre from "./Filtre.js";
import Post from "./Post.js";


export default class Cinema extends React.Component {
    constructor(props) {
       super(props);
       this.state = {
        sourceData: [],
        data: [],
      };
    }

     componentDidMount() {
      axios.get('https://api.themoviedb.org/4/list/1?page=1&api_key=c34a3abefc9fd33c2fa83884832c216f', { params:{}, headers: {'Authorization': null}}).then((data) =>
      {
      this.setState({data: data.data.results, sourceData: data.data.results})
      })
      }

      removeElement(id) {
      const sourceData =   this.state.sourceData.filter(data => data.id !==id);
      const data =   this.state.data.filter(data => data.id !==id);
      this.setState({ sourceData, data });
      }

      filterList(title) {
        const { sourceData} = this.state;
        const data = sourceData.filter((data)=> data.title === title );
        this.setState({ data });
      }

      updateDatePagination(currentPage,numberByPage) {
     this.setState({ page:currentPage,numberByPage});
      }


    render() {
      const listdata = this.state.data ? this.state.data.map((post,idx) =>  <Post data={post} key={idx} handleClick={ i => this.removeElement(i)}  />  ) : null

      return (
            <div className="wrapper">
            <h2>Blog</h2>
            <Filtre filter={ title => this.filterList(title)}  />
            <div className="flex"> {listdata}</div>
            </div>
        );
    };
}

