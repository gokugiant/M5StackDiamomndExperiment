

#include <M5Stack.h>

TFT_eSprite graph1 = TFT_eSprite(&M5.Lcd);  // Sprite object graph1

int grid     = 0;
int tcount   = 0;

//==========================================================================================
void setup() {
    M5.begin();
    M5.Power.begin();
    M5.Lcd.fillScreen(TFT_WHITE);

    // Create a sprite for the graph
    graph1.setColorDepth(8);
    graph1.createSprite(320, 240);
    graph1.fillSprite(
        TFT_BLUE);  // Note: Sprite is filled with black when created    
}

//==========================================================================================
void loop() {
    int rawMeasurement = analogRead(35);
    int mappedMeasurement = map(rawMeasurement, 0, 4095, 239, 0);
  
    Serial.print(Volt);
    Serial.print(":");
    Serial.print(rawMeasurement);
    Serial.print("\n");

    // Draw point in graph1 sprite at far right edge (this will scroll left
    // later)
    graph1.drawFastVLine(319, mappedMeasurement, 1, TFT_RED);  // draw 2 pixel point on graph

    // Push the sprites onto the TFT at specied coordinates
    graph1.pushSprite(0, 0);
  
    // Now scroll the sprites scroll(dt, dy) where:
    // dx is pixels to scroll, left = negative value, right = positive value
    // dy is pixels to scroll, up = negative value, down = positive value
    graph1.scroll(-1, 0);   // scroll graph 1 pixel left, 0 up/down
   
    // Draw the grid on far right edge of sprite as graph has now moved 1 pixel
    // left
    grid++;
    if (grid >= 10) {  // Draw a vertical line if we have scrolled 10 times (10 pixels)
        grid = 0;
        graph1.drawFastVLine(319, 0, 239, TFT_NAVY);  // draw line on graph
    } else {  // Otherwise draw points spaced 10 pixels for the horizontal grid
              // lines
        for (int p = 0; p <= 239; p += 10) graph1.drawPixel(239, p, TFT_NAVY);
    }

  if(M5.BtnA.wasPressed()){
    buttonACallback();
  }
  if(M5.BtnB.wasPressed()){
    buttonBCallback();
  }
  if(M5.BtnC.wasPressed()){
    buttonCCallback();
  }

  M5.update();
}

// Get screen 
const int screenWidth = M5.Lcd.width();
const int screenHeight = M5.Lcd.height();

void setup() {
  M5.begin();
  M5.Power.begin();
  M5.Lcd.fillScreen(BLACK);
  
  Serial.begin(115200);

  // Create a sprite for the graph
  graph1.setColorDepth(8);
  graph1.createSprite(screenWidth, screenHeight);
  graph1.fillSprite(TFT_BLUE);  // Note: Sprite is filled with black when created
}

void buttonACallback() {
 
}

void buttonBCallback() {

}

void buttonCCallback(){
 
}