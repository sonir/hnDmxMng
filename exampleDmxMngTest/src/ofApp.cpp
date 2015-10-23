#include "ofApp.h"

using namespace std;




//--------------------------------------------------------------
void ofApp::setup(){

    notice = slNotice::instance();
    notice->addEvent("control",this);
    output.direct_mode = true;
    
    ofSetFrameRate(60);

    
}

//--------------------------------------------------------------
void ofApp::update(){

    osc.update();
    output.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

        ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 40);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    
    if(key=='s') dmx.simpleTrigger(BLB8, 1.0);
    
    if(key=='a'){
        note_t note;
        note.phase = VOID;
        note.node = NODE_A;
        note.type = MAIN_M;
        note.adsr.attack = 1500;
        note.adsr.decay = 1000;
        note.adsr.sustain = 0.3f;
        note.adsr.duration = 600;
        note.adsr.release = 1000;
        note.adsr_sound = note.adsr;
        note.adsr_sound.release = 8000;
        output.setAdsr(note);
    }
    
    if(key=='r')output.allMute();
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key=='s') dmx.simpleTrigger(BLB8, 0.0);

    if(key=='a'){
        
        
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    dmx.simpleTrigger(BLB1, 1.0);
    dmx.simpleTrigger(BLB8, 0.0);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    dmx.simpleTrigger(BLB1, 0.0);
    dmx.simpleTrigger(BLB8, 1.0);
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


//--------------------------------------------------------------

void ofApp::event(event_type tag, void *data){
    
    if(tag=="control"){
        mes_t *param = (mes_t *)data;
        cout << param->ch << "," << param->fval << endl;
        output.setDirectValueWithNode((node_e)param->ch, param->fval);
        
    }
    
}



