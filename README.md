# Pro-ject 
The Project management Tool that makes you the pro at projecting your projects

the structure of this program is three parts:
Model - a node structure that makes it easy to move tasks (nodes) around memory
    A task has the following private data members:
        "title" - String representing the task
        "Project" - Int (for now) representation of the project that the task corresponds to.
        "DueDate" - int (for now) represents the number of days left to complete the task.
            (negative numbers are days that have passed, 0 is today, and positive numbers are coming up)
            todo: will need to decide how to make a task without a deadline

        "Completed" - Bool True: task complete, False(default): task to be completed


View - Lists of tasks
    Each view can help to structure the tasks into lists that need to be completed for example:
    "today"
        - The tasks would be added to this List and displayed to the user if the task was due today or yester (or due <= 0)
    "Project 1"
        - The tasks would be added to this list and displayed to the user if the task was from project 1 (1)
    "Do Now"
        - The tasks would be added to the list and displayed to the user if it's roots are complete.


Controller - The underlying Driver that arranges views and contains all the tasks in an ordered list (ordered by deadline, then by project).
    The controller keeps track of the day
    Adds tasks to the master list, and keeps it organized


Working definitions:
Dependants - the tasks that can be completed after the current task is done.
Roots - The Tasks that come before a Current Task

Todo:
Define A