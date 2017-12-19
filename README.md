# Pro-ject

The Project management Tool that makes you the pro at projecting your projects


# Working definitions
1. Dependants - the tasks that can be completed after the current task is done.
2. Roots - The Tasks that come before a Current Task

the structure of this program is three parts

## 1. Model - a node structure that makes it easy to move `Tasks` (nodes) around memory.

A `Task` has the following private data members


* `ID` - unique int for refrenceing in other structures
* `title` - String representing the task
* `dueDate` - int (for now) represents the number of days left to complete the task.
  * (negative numbers are days that have passed, 0 is today, and positive numbers are coming up)
* `priority` - int between 1-4 for the importance of the task. This is calculated and stored in each task each day.
* `completed` - Bool True- task complete, False(default)- task to be completed



## 2. View - What displays Lists of Tasks.

Each view can help to structure the tasks into lists that need to be completed for example:


##### "today"
* The `Tasks` would be added to this List and displayed to the user if the task was due today ( `dueDate == 0` )
##### "etc..."
* Of course there would be other views too. This class should not have any data members. just methods for displaying the controller's `activeView`


## 3. Controller The underlying Driver that arranges views and contains all the tasks in an ordered list (ordered by `priority`, then by `dueDate`).

The controller keeps track of the day.
Adds tasks to the master list, and keeps it organized.
Calculates, Updates and re-prioritizes tasks in the view for optimal order of events based on the task's duration, the proximity of the dueDate and the amount of hours in a day.
 * [ ] it would be awesome if it would recommend tasks that you should ask for extensions on.


A `Controller` has the following private data members
* `allTasks` - an LinkedList of all the Tasks created and ordered as described above.
* `completedTasks` - when a task is completed it is moved to this LinkedList.
  * [ ] - may not need this list?
* `activeView` - Name of the controller`s current view.
* `activeList` - List of Tasks (pointers to Tasks) that apply to the controller`s current view.

