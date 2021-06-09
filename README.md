# EEP-520 Spring 2021 - Kenneth Hurt - Final Project 
This document summarizes the scope of the UW EE-520 end-of-quarter project. The project used the _Enviro_ environment, which runs off the _ELMA_ event manager. These environments are the product of UW and the Klavins Lab.

# Project Description

*Project option 3:* Make a robot that moves around the arena in long, looping path. Call this robot the `Leader`.
   1. Create a `Follower` robot that uses a range finder to stay a respectful distance behind the leader.
   2. Next, add more `Follower` robots to create a train of robots.
   3. Extend or improve the example in which a robot moves around the arena with robots following it. Create a longer train of robots. Create flocking behaviors, and so on.

# Methodology:

The approach was to use a baseline engine from the in-class _Enviro_ examples and edit/add to the included methods in order to achieve the project specifications. Before these could be explored, the _Enviro_ environment had to be established on the local machine. 

Once the appropriate Docker containers were installed, a number of example files were considered for the baseline code. Two of them seemed particularly relevent: the _Wanderer_ and _Chaser_ classes. The _Wanderer_ code was modified to create the 'Leader' robot, which was programed to move loosely around the _Enviro_ arena. The _Chaser_ code was used as a baseline for the 'Follower' robots.

Finally the baseline environment was edited to include block agents. This was to show the aptitude of the robots in navigating obstacles and maintaining their Leader-Follower relationship.

The program was tested for a period of 2 hours. During this time, the robots were able to self-correct any instance of getting 'stuck' behind any of the obstacles.

# Key Challenges:

The 'Leader' robot was fairly easy achieved thanks to the example code provided in class. Created the 'Followers' and keeping them from stalling out was the major hurdle in this project. A number of methods were explored to achieve this, including _attach()_ and _position_, but ultimately the _emit()_ and _watch()_ _Event_ methods achieved what was required. 

Keeping the followers from getting 'stuck' crashing into each other was one final challege. This was eventually solved by using the front _sensor_value()_ to stop the robots as they approached within a certain distance of the robot they were following.

# Running the Code and Using the Project:

1. Download the entire _520-Project-New_ folder from github using the _git pull_ in the terminal window.
2. Lauch the _Enviro_ container in Docker using the following command: 
 
_docker run -p80:80 -p8765:8765 -v c/Users/_username_/520-Project-New:/source -it klavins/enviro:alpha bash_

2. Start _Enviro_ by using: _esm start_
3. Activate the MakeFile using the command: _make_
4. Use the _enviro_ command
5. View the arena and robots by opening http://localhost in your web browser
6. The robots will navigate the arena and self-correct after getting stuck behind any of the obstacles or each other

# Sources:

Supporting credit goes to the following sources:

1. Klavins Lab: _Wanderer_ code. https://github.com/klavinslab/enviro/tree/master/examples/wanderers
2. tbonaciUW: _Chaser_ code. https://github.com/tbonaciUW/EEP_520_Spring2021/tree/main/week9/chaser
3. tbonaciUW: _my_project_ code. https://github.com/tbonaciUW/EEP_520_Spring2021/tree/main/week9/my_project
4. Fellow students in the EE520 course. Thanks to them for their collaboration efforts.
