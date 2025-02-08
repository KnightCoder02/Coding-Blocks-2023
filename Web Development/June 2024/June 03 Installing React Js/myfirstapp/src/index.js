import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import LuckySeven from './components/Luckyseven';
import TaskList from './components/TaskList';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <React.StrictMode>
        <App/>
        <LuckySeven/>
        <TaskList/>
    </React.StrictMode>
);