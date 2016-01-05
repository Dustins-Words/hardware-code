#include "clickButton/clickButton.h"
#include "neopixel/neopixel.h"
#define NEOPIXEL_PIN D7 //data pin for the neopixel LEDs
#define NEOPIXEL_COUNT 6 //# of LEDs
#define NEOPIXEL_TYPE WS2812B //type of LEDs
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEOPIXEL_TYPE); //setup neopixel strip

    const int buttonPin1 = 1;
        ClickButton button1(buttonPin1, HIGH, CLICKBTN_PULLUP);
    const int buttonPin2 = 2;
        ClickButton button2(buttonPin2, HIGH, CLICKBTN_PULLUP);
    const int buttonPin3 = 3;
        ClickButton button3(buttonPin3, HIGH, CLICKBTN_PULLUP);
    const int buttonPin4 = 4;
        ClickButton button4(buttonPin4, HIGH, CLICKBTN_PULLUP);
    const int buttonPin5 = 5;
        ClickButton button5(buttonPin5, HIGH, CLICKBTN_PULLUP);
    const int buttonPin6 = 6;
        ClickButton button6(buttonPin6, HIGH, CLICKBTN_PULLUP);
    int function = 0;
    char message1[] = "I want to get dressed and start my day";
    char message2[] = "I have a headache";
    char message3[] = "I want to go and play";
    char message4[] = "I wanna dance! 💃";
    char message5[] = "I want a hug";
    char message6[] = "I have an idea";
    int colordelay = 150;
    char message[64] = "abcd";
    int receiveMess(String newMess);
    
    
void setup() {
    
    Spark.variable("message1", message1, STRING);
    Spark.function("receivemess", receiveMess);
    Spark.variable("message2", message2, STRING);
    Spark.variable("message3", message3, STRING);
    Spark.variable("message4", message4, STRING);
    Spark.variable("message5", message5, STRING);
    Spark.variable("message6", message6, STRING);
    
    Serial.begin(9600);
    //Neopixels
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    rainbow(20);
    strip.show();
    colorWipe(strip.Color(255, 0, 0), 25); 
    strip.show();
    colorWipe(strip.Color(0, 255, 0), 25); 
    strip.show();    
    colorWipe(strip.Color(0, 0, 255), 25); 
    strip.show();        
    colorWipe(strip.Color(255, 0, 0), 25); 
    strip.show();        
    //Buttons
    button1.debounceTime   = 20;   // Debounce timer in ms
    button1.multiclickTime = 250;  // Time limit for multi clicks
    button1.longClickTime  = 1000; // time until "held-down clicks" register
    button2.debounceTime   = 20;   // Debounce timer in ms
    button2.multiclickTime = 250;  // Time limit for multi clicks
    button2.longClickTime  = 1000; // time until "held-down clicks" register
    button3.debounceTime   = 20;   // Debounce timer in ms
    button3.multiclickTime = 250;  // Time limit for multi clicks
    button3.longClickTime  = 1000; // time until "held-down clicks" register
    button4.debounceTime   = 20;   // Debounce timer in ms
    button4.multiclickTime = 250;  // Time limit for multi clicks
    button4.longClickTime  = 1000; // time until "held-down clicks" register
    button5.debounceTime   = 20;   // Debounce timer in ms
    button5.multiclickTime = 250;  // Time limit for multi clicks
    button5.longClickTime  = 1000; // time until "held-down clicks" register
    button6.debounceTime   = 20;   // Debounce timer in ms
    button6.multiclickTime = 250;  // Time limit for multi clicks
    button6.longClickTime  = 1000; // time until "held-down clicks" register
    
    pinMode(1, INPUT_PULLDOWN);    // declare pushbutton as input
    pinMode(2, INPUT_PULLDOWN);    // declare pushbutton as input    
    pinMode(3, INPUT_PULLDOWN);    // declare pushbutton as input    
    pinMode(4, INPUT_PULLDOWN);    // declare pushbutton as input    
    pinMode(5, INPUT_PULLDOWN);    // declare pushbutton as input    
    pinMode(6, INPUT_PULLDOWN);    // declare pushbutton as input    
    strip.show(); // Initialize all pixels to 'off'    
    
}

void loop(){
  button1.Update();
  button2.Update();
  button3.Update();
  button4.Update();
  button5.Update();
  button6.Update();


  // Save click codes in LEDfunction, as click codes are reset at next Update()
  if (button1.clicks != 0) 
    function = button1.clicks;
  
  if(button1.clicks == 1){
    Spark.publish("button1","I want to get dressed");    
    strip.setPixelColor(0, 0, 255, 0);
    strip.show();
    delay(colordelay);
    strip.setPixelColor(0, 255, 0, 0);
    strip.show();
    function = 0;
  }
  
    if (button2.clicks != 0) 
    function = button2.clicks;
  
    if(button2.clicks == 1){
        Spark.publish("button2" , "I have a headache");    
        strip.setPixelColor(1, 0, 255, 0);
        strip.show();
        delay(colordelay);
        strip.setPixelColor(1, 255, 0, 0);
        strip.show();
        function = 0;
  }
    if (button3.clicks != 0) 
    function = button3.clicks;
  
    if(button3.clicks == 1){
        Spark.publish("button3" , "I want to go and play");    
        strip.setPixelColor(2, 0, 255, 0);
        strip.show();
        delay(colordelay);
        strip.setPixelColor(2, 255, 0, 0);
        strip.show();
        function = 0;
  }    
  if (button4.clicks != 0) 
    function = button4.clicks;
  
    if(button4.clicks == 1){
        Spark.publish("button4" , "I wanna dance!");    
        strip.setPixelColor(3, 0, 255, 0);
        strip.show();
        delay(colordelay);
        strip.setPixelColor(3, 255, 0, 0);
        strip.show();
        function = 0;
  }    
  
    if (button5.clicks != 0) 
    function = button5.clicks;
  
    if(button5.clicks == 1){
        Spark.publish("button5" , "I want a hug");    
        strip.setPixelColor(4, 0, 255, 0);
        strip.show();
        delay(colordelay);
        strip.setPixelColor(4, 255, 0, 0);
        strip.show();
        function = 0;
  }    
    if (button6.clicks != 0) 
    function = button6.clicks;
  
    if(button6.clicks == 1){
        Spark.publish("button6" , "I have an idea");    
        strip.setPixelColor(5, 0, 255, 0);
        strip.show();
        delay(colordelay);
        strip.setPixelColor(5, 255, 0, 0);
        strip.show();
        function = 0;
  }


}


void colorAll(uint32_t c, uint8_t wait) {
  uint16_t i;
  
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}

// Fill the dots one after the other with a color, wait (ms) after each one
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout, then wait (ms)
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 1 cycle of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
int receiveMess(String newMess)
{
    newMess.toCharArray(message1,64);
    return 0;
}

//Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
