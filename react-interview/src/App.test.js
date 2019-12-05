import React from 'react';
import ReactDOM from 'react-dom';
import Cinema from './Cinema';

it('renders without crashing', () => {
  const div = document.createElement('div');
  ReactDOM.render(<Cinema />, div);
  ReactDOM.unmountComponentAtNode(div);
});
