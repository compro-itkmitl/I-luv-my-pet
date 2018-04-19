#include <Servo.h>
//for servo
Servo servo_1; // black for food D8
Servo servo_2; //blue for snack D10
int degree=0;

//for ldr -led
const int ledPin = D9;
const int ldrPin = A0;

//function
void food_autometic();
void food_open();
void food_close();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  //SET PIN
  servo_1.attach(D8); //servo pin 8 food
  servo_2.attach(D10); //serov pin 10 snack
  //for ldr - led
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void food_autometic(){ // control servo 0 degree to 180 degree
  for(degree = 0;degree <180; degree +=1){
    servo_1.write(degree);
    delay(5);
  }
  for(degree = 180; degree >=1; degree -= 1)
  {
    servo_1.write(degree);
    delay(5);
  }
}

void food_open(){
  for(degree = 0;degree <180; degree +=1){
    servo_2.write(degree);
  }
}

void food_close(){
  for(degree = 180; degree >=1; degree -= 1)
  {
    servo_2.write(degree);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  //for ldr - led
  int ldrStatus = analogRead(ldrPin); delay(1);
  Serial.print("LDR value : "); Serial.println(ldrStatus); //check light input for if else
  delay(1500);
  if (ldrStatus <25) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  
  food_autometic();
  delay(1000);
  food_open();
  delay(500);
  food_close();
  delay(500);
}
