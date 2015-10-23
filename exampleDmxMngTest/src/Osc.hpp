//
//  Osc.hpp
//  hnDmxMngTest
//
//  Created by sonir on 9/26/15.
//
//

#ifndef Osc_hpp
#define Osc_hpp

#include <stdio.h>
#include "slOscManager.h"
#include "slNotice.h"

typedef struct mes_t {
    
    int ch;
    float fval;
    
    
} mes_t;

class Osc : public slOscManager{
    
    public:
        Osc(int port) : slOscManager(port){
            
            notice = slNotice::instance();
            
        }
        
        void fireMessage(ofxOscMessage *m);
    
    slNotice *notice;

    
};
#endif /* Osc_hpp */
