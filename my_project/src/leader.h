#ifndef __LEADER_AGENT__H
#define __LEADER_AGENT__H 

#include <string>
#include <math.h>
#include "enviro.h"

//Code for Kenneth Hurt - Final Project
//Base code for the Leader was modeled off the in-class example for Wanderers. Credit: Klavins Lab


namespace {

    using namespace enviro;

    //class from Wanderer base code. Used for moving the Leader foward in a straight line until its sensor sees a wall
    class MovingForward : public State, public AgentInterface { 
        public:
        double x,y;
        void entry(const Event& e) {}
        void during() {
            //emit Leader position so that followers can watch for the Event
            emit(Event("Leader_Posn", {{"x",position().x},{"y",position().y}})); 
            track_velocity(6,0);
            if ( sensor_value(0) < 40 ) {
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };
    //class from Wanderer base code. Used for rotating the Leader once it hits an obstacle
    class Rotating : public State, public AgentInterface { 
        public:
        //rate determined to achieve ~90degrees rotation upon hitting a wall
        void entry(const Event& e) { rate = 0.8;} 
        void during() { 
            track_velocity(0,rate); 
            if ( sensor_value(0) > 140 ) {
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        double rate;
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;        
    };
    //Wanderer Controller from Wanderer base code. Used for Leader
    class WandererController : public StateMachine, public AgentInterface { 

        public:
        WandererController() : StateMachine() {

            set_initial(moving_forward);
            tick_name = "tick_" + std::to_string(rand()%1000); 
            add_transition(tick_name, moving_forward, rotating);
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.set_tick_name(tick_name);
            rotating.set_tick_name(tick_name);

        }

        MovingForward moving_forward;
        Rotating rotating;
        std::string tick_name;

    };
    //Wanderer class from in-class example as well
    class Wanderer : public Agent {

        public:
        Wanderer(json spec, World& world) : Agent(spec, world) {
            add_process(wc);
        }

        WandererController wc;

    };





    DECLARE_INTERFACE(LEADER);

}

#endif