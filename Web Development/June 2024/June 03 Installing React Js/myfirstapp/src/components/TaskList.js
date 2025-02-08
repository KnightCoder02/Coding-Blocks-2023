import React from 'react'

const tasks = ['Cricket', 'Dance', 'Sing', 'Volleyball', 'football', 'coding']
const TaskList = () => {
  return (
    <div>
        <h2>Task List</h2>
        {tasks.map((t, index) => <div key={index}>
            {t}
            </div> 
        )}
    </div>
  )
}

export default TaskList