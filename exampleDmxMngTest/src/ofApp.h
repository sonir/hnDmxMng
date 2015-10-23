#pragma once

#define PORT 57110

#include "ofMain.h"
#include "hnDmxMng.h"
#include "slOscManager.h"
#include "Osc.hpp"

class ofApp : public ofBaseApp, slObserver{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void event(event_type tag, void *data);
    
        Dmx dmx;
        hnDmxMng output;
        Osc osc = Osc(PORT);
        slNotice *notice;
    
    
};
