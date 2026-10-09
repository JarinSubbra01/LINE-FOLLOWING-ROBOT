int ena = 10; //left
int in1 = 7;
int in2 = 6;

int enb = 11; //right
int in3 = 8;
int in4 = 9;


void setmotor(int pwm, int in1,int in2, int speed){
  if(speed>0){ // when the in1 = high and in2 = low the wheel moves forward
    analogWrite(pwm,speed);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }

  else if(speed<0){ // when the in1 = low and in2 = high the wheel moves backward

    speed=-1*speed;
    analogWrite(pwm,speed);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    analogWrite(pwm,0);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);

  }
}

void movelfr(int leftspeed , int rightspeed){
  setmotor(ena,in1,in2,leftspeed);
  setmotor(enb,in3,in4,rightspeed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(enb,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(ena,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  movelfr(200,-200);

}
