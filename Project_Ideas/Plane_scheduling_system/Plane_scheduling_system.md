## SCHEDULING PLANE LANDING 

### Project idea

Design a efficient scheduling algorithm for planes landing procedure, assuming there is only one runway. Every plane takes fixed amount of time to land. And thus the scheduling algorithm takes the time entry and returns if the timing is feasible or not.

***Requirements:***

* Set a plane landing timing if it is feasible.
* Get the plane that lands before a certain plane.
* Get the plane that lands after a certain plane.
* Remove the plane time if it has landed.
* Get how many planes will land before time T.
* Get the current plane to land.

***Implementaion:***

Version 1 : Binary Search Tree. O(h) 