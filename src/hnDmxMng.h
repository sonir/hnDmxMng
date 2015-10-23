#include <stdio.h>
#include <iostream>
#include <vector>
#include "Dmx.hpp"
#include "slAdsr.h"
#include "hnOutUnit.h"

class hnDmxMng {

    public:

        hnDmxMng(){

            //Setup ADSR arrays
            for(int i=0; i<CH_NUM; i++){
                
                hnOutUnit sa;
                sa.adsr.exponential = true;
                vals.push_back(sa);
                is_finished.push_back(false);
                params[i]=0.0f;
                
            }

            
            //MK Relation with Node and bulb, organ
            nodes[NODE_A].light_ch = BLB1;
            nodes[NODE_A].sound_ch = ORG_A;
            nodes[NODE_B].light_ch = BLB2;
            nodes[NODE_B].sound_ch = ORG_B;
            nodes[NODE_C].light_ch = BLB3;
            nodes[NODE_C].sound_ch = ORG_C;
            nodes[NODE_D].light_ch = BLB4;
            nodes[NODE_D].sound_ch = ORG_D;
            
            
        };


        void setAdsr(int ch, adsr_t a);
        void setAdsr(note_t note);
        void setOffset(node_e nd, note_type_e flg);
    
        void setDirectValue(int ch, float val);
        void setDirectValueWithNode(node_e node, float val);
        void update();
        float getCurrent(int ch);
    
    
        void allMute();

        bool direct_mode = false; //direct mode uses siple values instead of adsr
        node_t nodes[NODE_NUM];
        float params[CH_NUM];
        vector<hnOutUnit>vals;
        vector<bool>is_finished;
        Dmx dmx;
  
    
};