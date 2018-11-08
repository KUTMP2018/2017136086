int buttonApin = 14;
int buttonBpin = 15;
int buttonCpin = 16;

int  led1 = 12;
int  led2= 11;
int  led3 = 10;

int led_first = 0;
int led_second = 0;
int led_third  = 0;
int led_all = 0;

int clockPin1 = 9;   //Pin connected to SH_CP of 74HC595(6)
int latchPin1 = 8;      //Pin connected to ST_CP of 74HC595(5)
int dataPin1 = 7;    //Pin connected to DS of 74HC595(3)
byte leds1 = 0;

int clockPin2 = 6;   //Pin connected to SH_CP of 74HC595(6)
int latchPin2 = 5;      //Pin connected to ST_CP of 74HC595(5)
int dataPin2 = 4;    //Pin connected to DS of 74HC595(3)
byte leds2 = 0;

int clockPin3 = 3;   //Pin connected to SH_CP of 74HC595(6)
int latchPin3 = 2;      //Pin connected to ST_CP of 74HC595(5)
int dataPin3 = 1;    //Pin connected to DS of 74HC595(3)
byte leds3 = 0;

byte data[] = {B00100000, B00110000,B00111000,B00111100,B00111110,B01111111};

int color1=2; //R
int color2=5; //R
int color3=1; //G
int color4=4; //G
int color5=0; //B
int color6=3; //B

int num_a=0;
int num_b=0;
int num_c=0;
int num_d=1;

void setup() {
  pinMode(buttonApin, INPUT_PULLUP); 
  pinMode(buttonBpin, INPUT_PULLUP); 
  pinMode(buttonCpin, INPUT_PULLUP); 
  
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);   
  pinMode(led3, OUTPUT);
  
  led_first = 0;
  led_second = 0;
  led_third  = 0;

  pinMode(latchPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);  
  pinMode(clockPin1, OUTPUT);

  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);  
  pinMode(clockPin2, OUTPUT);

  pinMode(latchPin3, OUTPUT);
  pinMode(dataPin3, OUTPUT);  
  pinMode(clockPin3, OUTPUT);
}

void loop() {

  if (digitalRead(buttonApin) == LOW)
  {
    num_a++;
    num_b = 0;
    num_c = 0;
    num_d=0;
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    num_b++;
    num_a = 0;
    num_c = 0;
    num_d=0;
  }  
  if (digitalRead(buttonCpin) ==LOW)
  {
    num_c++;
    num_a = 0;
    num_b = 0;
    num_d=0;
  }

  led_off();

  if(led_first < 1)
  {
    digitalWrite(led1, HIGH);
    delay(200);
    digitalWrite(led1, LOW);
    delay(200);
    led_first++;
  }
  
  digitalWrite(led1, HIGH);
  delay(300);

  if(led_second < 1)
  {
    digitalWrite(led2, HIGH);
    delay(200);
    digitalWrite(led2, LOW);
    delay(200);
    led_second++;
  }

  digitalWrite(led2, HIGH);
  delay(300);
   
  if(led_third < 1)
  {
    digitalWrite(led3, HIGH);
    delay(200);
    digitalWrite(led3, LOW);
    delay(200);
    led_third++;
  }

  digitalWrite(led3, HIGH);
  delay(300);
 //--------------------------------------하나만키기 
 if(led_all<1)
 {
  for (int i = 0; i <6; i++)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds1, i);
    updateShiftRegister1();
    delay(100);
    //모든 불을 끈다
    leds1 = 0;
    updateShiftRegister1();
  }

  for (int i = 0; i <6; i++)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds2, i);
    updateShiftRegister2();
    delay(100);
    //모든 불을 끈다
    leds2 = 0;
    updateShiftRegister2();
  }

  for (int i = 0; i <6; i++)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds3, i);
    updateShiftRegister3();
    delay(100);
    //모든 불을 끈다
    leds3 = 0;
    updateShiftRegister3();
  }
  delay(100);
  
  for (int i = 6; i>0; i--)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds3, i-1);
    updateShiftRegister3();
    delay(100);
    //모든 불을 끈다
    leds3 = 0;
    updateShiftRegister3();
  }
  for (int i = 6; i>0; i--)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds2, i-1);
    updateShiftRegister2();
    delay(100);
    //모든 불을 끈다
    leds2 = 0;
    updateShiftRegister2();
  }
    for (int i = 6; i>0; i--)  {
    //leds 값에 i의 bit값을 넣는다
    bitSet(leds1, i-1);
    updateShiftRegister1();
    delay(100);
    //모든 불을 끈다
    leds1 = 0;
    updateShiftRegister1();
    }
  delay(300);
  led_all++;
 }
  //-------------------------------------------------------------------------------------RED
//---------------------------------------------- 고정키기
      if(num_a%2==1 && num_b == 0 && num_c == 0){
      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color2);

      updateShiftRegistercolorA2(color1);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color1);

      updateShiftRegistercolorA3(color2);
      
//------------------------------------------------------
      updateShiftRegistercolorB1(color1);

      updateShiftRegistercolorB1(color2);

      updateShiftRegistercolorB2(color1);

      updateShiftRegistercolorB2(color2);
      
      updateShiftRegistercolorB3(color1);

      updateShiftRegistercolorB3(color2);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color2);

      updateShiftRegistercolorA2(color1);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color1);

      updateShiftRegistercolorA3(color2);

// ----------------------------거꾸로
      updateShiftRegistercolorB3(color2);

      updateShiftRegistercolorB3(color1);

      updateShiftRegistercolorB2(color2);

      updateShiftRegistercolorB2(color1);
      
      updateShiftRegistercolorB1(color2);

      updateShiftRegistercolorB1(color1);
      //------
      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color2);

      updateShiftRegistercolorA2(color1);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color1);

      updateShiftRegistercolorA3(color2);
      }
      //--------------------------------------------------------------------------------------RED_속도조절_fast
      else if(num_a%2==0 && num_b == 0 && num_c == 0&&num_d==0){
      updateShiftRegistercolorA1_f(color1);

      updateShiftRegistercolorA1_f(color2);

      updateShiftRegistercolorA2_f(color1);

      updateShiftRegistercolorA2_f(color2);

      updateShiftRegistercolorA3_f(color1);

      updateShiftRegistercolorA3_f(color2);
      
//------------------------------------------------------
      updateShiftRegistercolorB1_f(color1);

      updateShiftRegistercolorB1_f(color2);

      updateShiftRegistercolorB2_f(color1);

      updateShiftRegistercolorB2_f(color2);
      
      updateShiftRegistercolorB3_f(color1);

      updateShiftRegistercolorB3_f(color2);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1_f(color1);

      updateShiftRegistercolorA1_f(color2);

      updateShiftRegistercolorA2_f(color1);

      updateShiftRegistercolorA2_f(color2);

      updateShiftRegistercolorA3_f(color1);

      updateShiftRegistercolorA3_f(color2);

// ----------------------------거꾸로
      updateShiftRegistercolorB3_f(color2);

      updateShiftRegistercolorB3_f(color1);

      updateShiftRegistercolorB2_f(color2);

      updateShiftRegistercolorB2_f(color1);
      
      updateShiftRegistercolorB1_f(color2);

      updateShiftRegistercolorB1_f(color1);
      //------
      updateShiftRegistercolorA1_f(color1);

      updateShiftRegistercolorA1_f(color2);

      updateShiftRegistercolorA2_f(color1);

      updateShiftRegistercolorA2_f(color2);

      updateShiftRegistercolorA3(color1);

      updateShiftRegistercolorA3(color2);
      }
      //--------------------------------------------------------------------------- GREEN
      else if(num_a == 0 && num_b%2==1 && num_c == 0)
      {
      updateShiftRegistercolorA1(color3);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color3);

      updateShiftRegistercolorA2(color4);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color4);

//------------------------------------------------------지속
      updateShiftRegistercolorB1(color3);

      updateShiftRegistercolorB1(color4);

      updateShiftRegistercolorB2(color3);

      updateShiftRegistercolorB2(color4);
      
      updateShiftRegistercolorB3(color3);

      updateShiftRegistercolorB3(color4);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1(color3);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color3);

      updateShiftRegistercolorA2(color4);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color4);

// ----------------------------거꾸로
      updateShiftRegistercolorB3(color4);

      updateShiftRegistercolorB3(color3);

      updateShiftRegistercolorB2(color4);

      updateShiftRegistercolorB2(color3);
      
      updateShiftRegistercolorB1(color4);

      updateShiftRegistercolorB1(color3);
      //------
      updateShiftRegistercolorA1(color3);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color3);

      updateShiftRegistercolorA2(color4);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color4);
      }
      //-----------------------------------------------------------------------------GREEN_속도조절_fast
      else if(num_a == 0 && num_b%2==0 && num_c == 0&&num_d==0)
      {
      updateShiftRegistercolorA1_f(color3);

      updateShiftRegistercolorA1_f(color4);

      updateShiftRegistercolorA2_f(color3);

      updateShiftRegistercolorA2_f(color4);

      updateShiftRegistercolorA3_f(color3);

      updateShiftRegistercolorA3_f(color4);

//------------------------------------------------------지속
      updateShiftRegistercolorB1_f(color3);

      updateShiftRegistercolorB1_f(color4);

      updateShiftRegistercolorB2_f(color3);

      updateShiftRegistercolorB2_f(color4);
      
      updateShiftRegistercolorB3_f(color3);

      updateShiftRegistercolorB3_f(color4);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1_f(color3);

      updateShiftRegistercolorA1_f(color4);

      updateShiftRegistercolorA2_f(color3);

      updateShiftRegistercolorA2_f(color4);

      updateShiftRegistercolorA3_f(color3);

      updateShiftRegistercolorA3_f(color4);

// ----------------------------거꾸로
      updateShiftRegistercolorB3_f(color4);

      updateShiftRegistercolorB3_f(color3);

      updateShiftRegistercolorB2_f(color4);

      updateShiftRegistercolorB2_f(color3);
      
      updateShiftRegistercolorB1_f(color4);

      updateShiftRegistercolorB1_f(color3);
      //------
      updateShiftRegistercolorA1_f(color3);

      updateShiftRegistercolorA1_f(color4);

      updateShiftRegistercolorA2_f(color3);

      updateShiftRegistercolorA2_f(color4);

      updateShiftRegistercolorA3_f(color3);

      updateShiftRegistercolorA3_f(color4);
      }
//      ----------------------------------------------------------------------BLUE
      
      
      else if(num_a == 0 && num_b == 0 && num_c%2==1){
      updateShiftRegistercolorA1(color5);

      updateShiftRegistercolorA1(color6);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color6);

      updateShiftRegistercolorA3(color5);

      updateShiftRegistercolorA3(color6);

//------------------------------------------------------지속red
      updateShiftRegistercolorB1(color5);
 
      updateShiftRegistercolorB1(color6);

      updateShiftRegistercolorB2(color5);

      updateShiftRegistercolorB2(color6);
      
      updateShiftRegistercolorB3(color5);

      updateShiftRegistercolorB3(color6);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1(color5);

      updateShiftRegistercolorA1(color6);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color6);

      updateShiftRegistercolorA3(color5);

      updateShiftRegistercolorA3(color6);

// ----------------------------거꾸로
      updateShiftRegistercolorB3(color6);

      updateShiftRegistercolorB3(color5);

      updateShiftRegistercolorB2(color6);

      updateShiftRegistercolorB2(color5);
      
      updateShiftRegistercolorB1(color6);

      updateShiftRegistercolorB1(color5);
      //------
      updateShiftRegistercolorA1(color5);

      updateShiftRegistercolorA1(color6);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color6);

      updateShiftRegistercolorA3(color5);

      updateShiftRegistercolorA3(color6);
  }
  //-------------------------------------------------------------------------------BLUE_속도조절_fast
      else if(num_a == 0 && num_b == 0 && num_c%2==0&&num_d==0){
      updateShiftRegistercolorA1_f(color5);

      updateShiftRegistercolorA1_f(color6);

      updateShiftRegistercolorA2_f(color5);

      updateShiftRegistercolorA2_f(color6);

      updateShiftRegistercolorA3_f(color5);

      updateShiftRegistercolorA3_f(color6);

//------------------------------------------------------지속red
      updateShiftRegistercolorB1_f(color5);
 
      updateShiftRegistercolorB1_f(color6);

      updateShiftRegistercolorB2_f(color5);

      updateShiftRegistercolorB2_f(color6);
      
      updateShiftRegistercolorB3_f(color5);

      updateShiftRegistercolorB3_f(color6);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1_f(color5);

      updateShiftRegistercolorA1_f(color6);

      updateShiftRegistercolorA2_f(color5);

      updateShiftRegistercolorA2_f(color6);

      updateShiftRegistercolorA3_f(color5);

      updateShiftRegistercolorA3_f(color6);

// ----------------------------거꾸로
      updateShiftRegistercolorB3_f(color6);

      updateShiftRegistercolorB3_f(color5);

      updateShiftRegistercolorB2_f(color6);

      updateShiftRegistercolorB2_f(color5); 
      
      updateShiftRegistercolorB1_f(color6);

      updateShiftRegistercolorB1_f(color5);
      //------
      updateShiftRegistercolorA1_f(color5);

      updateShiftRegistercolorA1_f(color6);

      updateShiftRegistercolorA2_f(color5);

      updateShiftRegistercolorA2_f(color6);

      updateShiftRegistercolorA3_f(color5);

      updateShiftRegistercolorA3_f(color6);
  }
    //-------------------------------------------------------------------------------------RAINBOW
      else{
      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color6);

//------------------------------------------------------
      updateShiftRegistercolorB1(color1);

      updateShiftRegistercolorB1(color4);

      updateShiftRegistercolorB2(color5);

      updateShiftRegistercolorB2(color2);
      
      updateShiftRegistercolorB3(color3);

      updateShiftRegistercolorB3(color6);
 
 //----------------------------------------내려오기

      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color6);

// ----------------------------거꾸로
      updateShiftRegistercolorB3(color6);

      updateShiftRegistercolorB3(color3);

      updateShiftRegistercolorB2(color2);

      updateShiftRegistercolorB2(color5);
      
      updateShiftRegistercolorB1(color4);

      updateShiftRegistercolorB1(color1);
      //------
      updateShiftRegistercolorA1(color1);

      updateShiftRegistercolorA1(color4);

      updateShiftRegistercolorA2(color5);

      updateShiftRegistercolorA2(color2);

      updateShiftRegistercolorA3(color3);

      updateShiftRegistercolorA3(color6);
      }
}

void updateShiftRegister1() {
   digitalWrite(latchPin1, LOW);
   shiftOut(dataPin1, clockPin1, LSBFIRST, leds1);
   digitalWrite(latchPin1, HIGH);
  }
void updateShiftRegister2() {
   digitalWrite(latchPin2, LOW);
   shiftOut(dataPin2, clockPin2, LSBFIRST, leds2);
   digitalWrite(latchPin2, HIGH);
  }
void updateShiftRegister3() {
   digitalWrite(latchPin3, LOW);
   shiftOut(dataPin3, clockPin3, LSBFIRST, leds3);
   digitalWrite(latchPin3, HIGH);
  }
//-----------------------------------A: 순서대로 내려오기
void updateShiftRegistercolorA1(int color) {
      bitSet(leds1, color);
      updateShiftRegister1();      
      delay(100);
      leds1 = 0;
      updateShiftRegister1();
}
void updateShiftRegistercolorA2(int color) {
      bitSet(leds2, color);
      updateShiftRegister2();      
      delay(100);
      leds2 = 0;
      updateShiftRegister2();
}
void updateShiftRegistercolorA3(int color) {
      bitSet(leds3, color);
      updateShiftRegister3();      
      delay(100);
      leds3 = 0;
      updateShiftRegister3();
}
//----------------------------------채워서 내려오기
void updateShiftRegistercolorB1(int color) {
      bitSet(leds1, color);
      updateShiftRegister1();
      delay(100);
}
void updateShiftRegistercolorB2(int color) {
      bitSet(leds2, color);
      updateShiftRegister2();
      delay(100);
}
void updateShiftRegistercolorB3(int color) {
      bitSet(leds3, color);
      updateShiftRegister3();
      delay(100);
}

//----------------------------------------------------------------------속도조절

void updateShiftRegistercolorA1_f(int color) {
      bitSet(leds1, color);
      updateShiftRegister1();      
      delay(50);
      leds1 = 0;
      updateShiftRegister1();
}
void updateShiftRegistercolorA2_f(int color) {
      bitSet(leds2, color);
      updateShiftRegister2();      
      delay(50);
      leds2 = 0;
      updateShiftRegister2();
}
void updateShiftRegistercolorA3_f(int color) {
      bitSet(leds3, color);
      updateShiftRegister3();      
      delay(50);
      leds3 = 0;
      updateShiftRegister3();
}
//----------------------------------채워서 내려오기
void updateShiftRegistercolorB1_f(int color) {
      bitSet(leds1, color);
      updateShiftRegister1();
      delay(50);
}
void updateShiftRegistercolorB2_f(int color) {
      bitSet(leds2, color);
      updateShiftRegister2();
      delay(50);
}
void updateShiftRegistercolorB3_f(int color) {
      bitSet(leds3, color);
      updateShiftRegister3();
      delay(50);
}
//---------------------------------------------------------------------------------모든불끄기

void led_off()
{
    for (int i = 0; i <6; i++)  {
    //모든 불을 끈다
    leds1 = 0;
    updateShiftRegister1();
  }
      for (int i = 0; i <6; i++)  {
    //모든 불을 끈다
    leds2 = 0;
    updateShiftRegister2();
  }
      for (int i = 0; i <6; i++)  {
    //모든 불을 끈다
    leds3 = 0;
    updateShiftRegister3();
  }
}
