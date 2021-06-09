#ifndef __FOLLOWFOLLOWER_AGENT__H
#define __FOLLOWFOLLOWER_AGENT__H 

#include "enviro.h"

using namespace enviro;

//Code for Kenneth Hurt - Final Project
//Base code for the FollowFollower was modeled off the in-class example for Chaser. Credit: Klavins Lab

class FollowFollowerController : public Process, public AgentInterface {

    public:
    FollowFollowerController() : Process(), AgentInterface(), x(0), y(0) {}
    double x, y;
    void init() {
        //watch for Event Leader position
        watch("Follower_Posn", [this](Event e){
            //look for x and y coordinates
            x = e.value()["x"];
            y = e.value()["y"];
        });     
    }
    void start() {}
    void update() {
        if(sensor_value(0)>30){
            //move only if sensor value >0
            move_toward(x,y, 28, 10);
        }
        else{
            //if not, rotate but hold position
            track_velocity(0,2);
        }
        //emit another ID for additional "Following Follows" to track.
        emit(Event("Follower_Posn", {{"x",position().x},{"y",position().y}})); 
    }
    void stop() {}
};

//Follower class, modeled from Chaser example in class
class FollowFollower : public Agent {
    public:
    FollowFollower(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    FollowFollowerController c;
};

DECLARE_INTERFACE(FollowFollower)

#endif