#include "hnDmxMng.h"

void hnDmxMng::setAdsr(int ch, adsr_t a){
    
    vals[ch].setup(a);
    vals[ch].bang();
    
}

void hnDmxMng::setAdsr(note_t note){
    
    
    if( note.type == MAIN_S ||  note.type == MAIN_M ||  note.type == MAIN_L ){
        switch (note.node){
                
            case NODE_A:
                cout << "node_A" << endl;
                setAdsr(nodes[NODE_A].light_ch, note.adsr);
                setAdsr(nodes[NODE_A].sound_ch, note.adsr_sound);
                break;
                
            case NODE_B:
                cout << "node_B" << endl;
                setAdsr(nodes[NODE_B].light_ch, note.adsr);
                setAdsr(nodes[NODE_B].sound_ch, note.adsr_sound);
                break;
                
            case NODE_C:
                cout << "node_C" << endl;
                setAdsr(nodes[NODE_C].light_ch, note.adsr);
                setAdsr(nodes[NODE_C].sound_ch, note.adsr_sound);
                break;
                
            case NODE_D:
                cout << "node_D" << endl;
                setAdsr(nodes[NODE_D].light_ch, note.adsr);
                setAdsr(nodes[NODE_D].sound_ch, note.adsr_sound);
                break;
                
        }
        
        
        
    }else if ( note.type == SUB1 ||  note.type == SUB2 ||  note.type == SUB3 ){
        

            //DO NOTHING BECAUSE SUB BULB IS SAME AS MAIN
//        switch (note.node){
//                
//            case NODE_A:
//                setAdsr(ND_A, note.adsr);
//                break;
//                
//            case NODE_B:
//                setAdsr(ND_B, note.adsr);
//                break;
//                
//            case NODE_C:
//                setAdsr(ND_C, note.adsr);
//                break;
//                
//            case NODE_D:
//                setAdsr(ND_D, note.adsr);
//                break;
//                
//        }
        
        
    } else {
        
        //GLITCH is here.
        
        switch(note.type){
                
            case GLITCH1:
                break;

            case GLITCH2:
                break;

            case GLITCH3:
                break;

            default:
                break;
                
        }
            
    }
}



void hnDmxMng::setDirectValue(int ch, float val){
    
    params[ch]=val;
    
}

void hnDmxMng::setDirectValueWithNode(node_e node, float val){
    
    
    switch (node){

        case NODE_A:
            setDirectValue(nodes[NODE_A].light_ch, val);
            setDirectValue(nodes[NODE_A].sound_ch, val);
            break;

        case NODE_B:
            setDirectValue(nodes[NODE_B].light_ch, val);
            setDirectValue(nodes[NODE_B].sound_ch, val);
            break;

        case NODE_C:
            setDirectValue(nodes[NODE_C].light_ch, val);
            setDirectValue(nodes[NODE_C].sound_ch, val);
            break;

        case NODE_D:
            setDirectValue(nodes[NODE_D].light_ch, val);
            setDirectValue(nodes[NODE_D].sound_ch, val);
            break;
            
    }

    
}



void hnDmxMng::update(){
    
    if(!direct_mode){
        for(int i=0; i<vals.size(); i++){
            
            vals[i].update();
            dmx.simpleTrigger(i,vals[i].getCurrent());

        }
    }else{
    
        for(int i=0; i<CH_NUM;i++){
            dmx.simpleTrigger(i,params[i]);
        }
        
    }
    
}



float hnDmxMng::getCurrent(int ch){
    
    
    return vals[ch].getCurrent();
    
}

void hnDmxMng::allMute(){

    if(direct_mode){
        for(int i=0; i<vals.size(); i++){
            
            adsr_t a;
            a.attack=1;
            a.decay=0;
            a.sustain=0.0f;
            a.release=0;
            a.duration=0;
            vals[i].setup(a);
            dmx.simpleTrigger(i,vals[i].getCurrent());
            
        }
    }else{
        
        for(int i=0; i<CH_NUM; i++){
            params[i] = 0.0;
        }

    }
    
}

