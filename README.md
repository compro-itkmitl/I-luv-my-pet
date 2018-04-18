# I-luv-my-pet
Computer Programing Project
---
### Introduction
> เนื่องจากปัจจุบันผู้คนมีการเลี้ยงสัตว์อย่างหลากหลายชนิด อาทิเช่น แมว สุนัข ปลา กระต่าย ฯลฯ  และอาจจะต้องพบเจอกับปัญหาการให้อาหารสัตว์ โดยเฉพาะเวลาที่ต้องเดินทางไปทำงานหรือไปเที่ยวต่างจังหวัดหรือต่างประเทศ ทำให้เกิดความกังวลเกี่ยวกับการทานอาหารของสัตว์เลี้ยง ซึ่งโดยปกติเจ้าของจะให้อาหารตามเวลาจึงต้องมีการคิดค้นอุปกรณ์เพื่ออำนวยความสะดวกแก่เจ้าของ ผู้พัฒนาเล็งเห็นถึงปัญหานี้จึงได้คิดค้นและจัดทำเครื่องให้อาหารอัตโนมัติโดยสามารถสั่งได้จากมือถือเพื่อให้สามารถให้อาหารได้ทุกที่ทุกเวลา
---
### Library
* [Servo library](https://github.com/arduino-libraries/Servo)
* [Blynk library](https://github.com/blynkkk/blynk-library/releases/tag/v0.5.2)
* [Time library](https://github.com/PaulStoffregen/Time)
### Installation
---
1. ดาวน์โหลด arduino ide: https://www.arduino.cc/en/Main/Software
2. เพิ่มบอร์ดโดยไปที่เมนู File เลือก Preference ใส่ url: http://arduino.esp8266.com/stable/package_esp8266com_index.json ลงในช่อง Additional Boards Manager URLs แล้วกด OK
3. ไปที เมนู Tools เลือก Board แล้วเลือก Boards Manager
4. พิมพ์คําว่า esp8266 แล้วกด install
5. ไปที่ เมนู Tools เลือก Board จากนั้นเลือก Wemos D1 R1
6. ดาวน์โหลดและติดตั้ง Library
   * ไปที่ เมนู Sketch เลือก Include library แล้วเลือก Add.Zip Library...
   * เลือกไฟล์ Zip จากที่ได้ดาวน์โหลดมา
