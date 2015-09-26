//
//  Dmx.cpp
//  hnAdsr
//
//  Created by sonir on 9/24/15.
//
//
#include "Dmx.hpp"


void Dmx::setup(){
    
    
}


void Dmx::triggerWithNode(node_t node, float fval){
    
    dest->send("/dmx/universe/0" , node.sound_ch, fval);
    dest->send("/dmx/universe/0" , node.light_ch, fval);
    
}



void Dmx::simpleTrigger(int ch, float fval){
    
    
    dest->send("/dmx/universe/0" , ch, fval);
    
}



