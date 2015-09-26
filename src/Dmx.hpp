//
//  Dmx.hpp
//  hnAdsr
//
//  Created by sonir on 9/24/15.
//
//

#ifndef Dmx_hpp
#define Dmx_hpp

#include <stdio.h>
#include "Desitination.h"
#include "portSetup.h"


//JUST FOR REFERENCE
//ENUM for Event Hundling
//typedef enum {VOID, ARRIVED, CLIMAX} command_e;
//typedef enum {NODE_A, NODE_B, NODE_C, NODE_D} node_e;
//typedef enum {MAIN_S, MAIN_M, MAIN_L, SUB1, SUB2, SUB3, PARTICLE1, PARTICLE2, PARTICLE3} note_type_e;


class Dmx {
    
    public:
        Dmx(){
            
            dest = new Destination("224.0.0.1", 7770);
//            dest = new Destination("192.168.8.103" , 7770);
            
        }
    
        void setup();
        void triggerWithNode(node_t node, float fval);
        void simpleTrigger(int ch, float fval);
    
        Destination *dest;
    
};


#endif /* Dmx_hpp */
