constexpr uint8_t ENA = 10;
constexpr uint8_t ENB = 11;

//  left-motor direction pins.
constexpr uint8_t IN1 = 7;
constexpr uint8_t IN2 = 6;
// right-motor direction pins.
constexpr uint8_t IN3 = 8;  //constexpr is litter version of const
constexpr uint8_t IN4 = 9;   //uint8_t is used for less bytes and takes positive values only   normal int takes 2 byte where uint8_t takes 1 byte

//ir array value select 2^4 = 16
/*
0 = 0000
1
2
3
4
5
6
7
8
9
10
11
12
13

*/

//main sensor reading code starts from here 


const int MUX_A = A1;
const int MUX_B = A2;
const int MUX_C = A3;
const int MUX_D = A0;
const int MUX_SIG = A7;

void sensorInit() {
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);
  pinMode(MUX_C, OUTPUT);
  pinMode(MUX_D, OUTPUT);
  digitalWrite(MUX_A, LOW);  //initially all mux values are 0 or low
  digitalWrite(MUX_B, LOW);
  digitalWrite(MUX_C, LOW);
  digitalWrite(MUX_D, LOW);
}

void setup() {
  sensorInit();
   Serial.begin(115200);
}
int sensor[14];
void loop() {
  for(int i=0; i<14; i++){// i = 11 -> 1011
    digitalWrite(MUX_A, bitRead(i, 0));// 11-> 1 -> high
    digitalWrite(MUX_B, bitRead(i, 1));// 11 -> 0 -> low
    digitalWrite(MUX_C, bitRead(i, 2));// high
    digitalWrite(MUX_D, bitRead(i, 3));// high
    int value = analogRead(MUX_SIG);

    sensor[i] = value;

    Serial.print("i(");
    Serial.print(i);
    Serial.print("): ");
    Serial.print(value);
    Serial.print(" | ");

  }
  Serial.println(); 
  delay(2000);
}
