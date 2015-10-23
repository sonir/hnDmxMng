
//
//  Osc.cpp
//  hnDmxMngTest
//
//  Created by sonir on 9/26/15.
//
//

#include "Osc.hpp"


void Osc::fireMessage(ofxOscMessage *m){
    
    if(m->getAddress() == "/control"){
        
        mes_t mes;
        mes.ch = m->getArgAsInt32(0);
        mes.fval = m->getArgAsFloat(1);
        notice->notify("control" , &mes);
        
        std::cout<< mes.fval << std::endl;

    }
    
}
