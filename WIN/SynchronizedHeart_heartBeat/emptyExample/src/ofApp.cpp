#include "ofApp.h"

// Current window size
#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480

// FPS parameter
#define FPS 60

// Serial data buf size
#define BUFSIZE (WINDOW_WIDTH / 2)

// Debug macros
#define FPS_DBG if(debug_fps)
#define SERIAL_DBG if(debug_serial)

static const bool debug_fps = false;
static const bool debug_serial = false;

//--------------------------------------------------------------
void ofApp::setup(){
  // Window shape
  ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
  // Frame rate(aim default 60fps)
  ofSetFrameRate(FPS);
  ofBackground(255, 255, 255);

  /*---- Init param ----*/
  rad = 0;

  /*---- Image ----*/
  img_body.loadImage("body.jpg");
  img_heart.loadImage("heart.jpg");

  /*---- Serial ----*/
  serial.enumerateDevices();
  serial.setup("COM19", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
  SERIAL_DBG {
    printf("%d\n", getParam);
  }
  //deg++;
  //if(deg > 180) deg = 0;

  getParam = serial.readByte();
  rad = getParam * PI / 180;
}

//--------------------------------------------------------------
void ofApp::draw(){
  FPS_DBG {
    // FPS
    int msecNow = ofGetElapsedTimeMillis();
    float fps = 1000.0 / (msecNow - msec);
    msec = msecNow;
    ofSetColor(0, 255, 0);
    char buf[50];
    // FPS表示
    sprintf(buf, "%5.2f fps", fps);
    ofDrawBitmapString(buf, 20, 20);

    // 色を戻しておく
    ofSetColor(255, 255, 255);
  }
  ofSetColor(255, 255, 255);
  // 座標系を再設定
  // Top 360
  ofTranslate(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
  // 座標系を反転
  ofScale(1, -1);

  // body img draw
  img_body.draw(-(img_body.getWidth() / 2), (img_body.getHeight() / 2),
    img_body.getWidth(), -img_body.getHeight());
  // Set alpha
  float alpha = 255 * (sin(rad) + 0.75);
  // Color set and alpha
  ofSetColor(255, 255, 255, alpha);
  // heart image draw
  img_heart.draw(-(img_heart.getWidth() / 2), (img_heart.getHeight() / 2),
    img_heart.getWidth(), -img_heart.getHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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