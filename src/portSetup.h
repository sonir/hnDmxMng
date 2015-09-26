//
//  portSetup.h
//  hnDmxMngTest
//
//  Created by sonir on 9/25/15.
//
//

#ifndef portSetup_h
#define portSetup_h

//SYS DEFINES
#define CH_NUM 12
#define NODE_NUM 4

#include "slAdsr.h"


typedef struct node_t {
    
    int sound_ch;
    int light_ch;
    
} node_t;



//PORT MAPPING

//ORGAN
#define ORG_A 9
#define ORG_B 10
#define ORG_C 11
#define ORG_D 12

//LIGHT
#define BLB1 1
#define BLB2 2
#define BLB3 3
#define BLB4 4
#define BLB5 5
#define BLB6 6
#define BLB7 7
#define BLB8 8

//LIGHT_FOR_ORGAN
#define ORG_L_A BLB1
#define ORG_L_B BLB2
#define ORG_L_C BLB3
#define ORG_L_D BLB4

//LIGHT_FOR_SUB
#define SUB_A BLB5
#define SUB_B BLB6
#define SUB_C BLB7
#define SUB_D BLB8


//Setup NODE and BLB x SOUND EXISTS IN hmDmzMng.h

//ENUM for Event Hundling
typedef enum {VOID, ARRIVED, CLIMAX} command_e;
typedef enum {NODE_A, NODE_B, NODE_C, NODE_D} node_e;
typedef enum {MAIN_S, MAIN_M, MAIN_L, SUB1, SUB2, SUB3, GLITCH1, GLITCH2, GLITCH3} note_type_e;
typedef enum {RED,GREEN,BLUE,BLACK} color_e;

typedef struct note_t { //Using trigger with duration (=sustain_time)
    
    command_e phase;
    node_e node;
    note_type_e type;
    float duration;
    adsr_t adsr;
    adsr_t adsr_sound;
    float amp;
    
}note_t;


#endif /* portSetup_h */
