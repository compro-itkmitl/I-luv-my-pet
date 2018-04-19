#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <time.h>
//for wifi and blynk
char auth[] = "595c0a3da8714c898b9d6be1fcdaa44e"; //auth for blynk
const char* ssid = "COMPRO";
const char* password = "HelloWorld";

//for ldr -led
const int ledPin = D9;
const int ldrPin = A0;

//for servo
Servo servo_1; // black for food D8
Servo servo_2; //blue for snack D10
int degree=0;

//for time
int timezone = 7 * 3600; //TimeZone
int dst = 0; //Date Swing Time

//function
void food_autometic();
void food_open();
void food_close();
void snack_autometic();
void snack_open();
void snack_close();


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
    servo_1.write(degree);
  }
}

void food_close(){
  for(degree = 180; degree >=1; degree -= 1)
  {
    servo_1.write(degree);
  }
}

void snack_autometic(){ // control servo 0 degree to 180 degree
  for(degree = 0;degree <180; degree +=1){
    servo_2.write(degree);
    delay(5);
  }
  for(degree = 180; degree >=1; degree -= 1)
  {
    servo_2.write(degree);
    delay(5);
  }
}

void snack_open(){
  for(degree = 0;degree <180; degree +=1){
    servo_2.write(degree);
  }
}

void snack_close(){
  for(degree = 180; degree >=1; degree -= 1)
  {
    servo_2.write(degree);
  }
}


void setup() {

  Serial.begin(115200);
  delay(10);
//   Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to WIFI... : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wi-Fi connected successfully");
//  start blynk
  Blynk.begin(auth, ssid, password);//for 

//SET PIN
  servo_1.attach(D8); //servo pin 8 food
  servo_2.attach(D10); //serov pin 10 snack
  //for ldr - led
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  
  //for time
  Serial.setDebugOutput(true);
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //ดึงเวลาจาก Server
}

//blynk input
BLYNK_WRITE(V3) { //control value of food
  int value = param.asInt();
  if(value == 1){
    food_open();
  }
  else{
    food_close();
  }
}
BLYNK_WRITE(V4){ //autometic food
  int value = param.asInt();
  if(value == 1){
    food_autometic();
  }
  else{
    value == 0;
  }
}
BLYNK_WRITE(V5) { //control value of snack
  int value = param.asInt();
  if(value == 1){
    snack_open();
  }
  else{
    snack_close();
  }
}
BLYNK_WRITE(V6){ //autometic snack
  int value = param.asInt();
  if(value == 1){
    snack_autometic();
  }
  else{
    value == 0;
  }
}

void loop(){
  Blynk.run();
  
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

  //time
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  if((p_tm->tm_sec == 0)&&(p_tm->tm_min == 57)&&(p_tm->tm_hour == 11)){
    food_autometic();
  }
  if ((p_tm->tm_sec == 0)&&(p_tm->tm_min == 57)&&(p_tm->tm_hour == 11) && (p_tm->tm_wday == 4)){ //notification to phone (Sunday = 0)
    Blynk.notify("Check Your Feeder Matchine");
  }
}
