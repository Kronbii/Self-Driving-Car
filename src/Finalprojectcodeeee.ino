#define Bw1 4
#define Bw2 2
#define Bw3 5
#define Bw4 3
#define Bw5 12
#define Bw6 13
#define IR 8
#define Rightpos 10
#define Rightneg 11
#define Leftpos 9
#define Leftneg 6
// - 3 (V2) - 5 (V4) - 2 (V1) - 4 (V3)
int V1;
int V2;
int V3;
int V4;
int V5;
int V6;
// 6 Low 9 high > forward motion 
// 10 high 11 low > forward motion 
int IRreading;
bool onTrack;
void moveCar(int Leftspeed1, int Leftspeed2, int Rightspeed1, int Rightspeed2){
 analogWrite(Leftpos, Leftspeed1);
 analogWrite(Leftneg, Leftspeed2);
 analogWrite(Rightpos, Rightspeed1);
 analogWrite(Rightneg, Rightspeed2);
}
void setup(){
 //B/w sensors
 pinMode(Bw1, INPUT);
 pinMode(Bw2, INPUT);
 pinMode(Bw3, INPUT);
 pinMode(Bw4, INPUT);
 pinMode(Bw5,INPUT);
 pinMode(Bw6,INPUT);
 //IR sensor
 pinMode(IR, INPUT);
 //Motors
 pinMode(Rightpos,OUTPUT);
 pinMode(Rightneg,OUTPUT);
 pinMode(Leftpos,OUTPUT);
 pinMode(Leftneg,OUTPUT);
 
}
void loop(){
 
 V1= digitalRead(Bw1);
 V2= digitalRead(Bw2);
 V3= digitalRead(Bw3);
 V4= digitalRead(Bw4);
 V5= digitalRead(Bw5);
 V6= digitalRead(Bw6);
 IRreading= digitalRead(IR);
moveCar(120,0,120,0);
if (V1 == 1){
 moveCar(255,0,0,255);
}
else if (V2 == 1){
 moveCar(255,0,0,100);
}
else if (V3 == 1){
 moveCar(0,150,255,0);
}
else if (V4 == 1){
 moveCar(0,255,255,0);
}
else if (V5== 1)
moveCar(255,0,0,255);
else if (V6== 1)
moveCar(0,255,255,0);
else if (V1==1 && V2==1 && V3==1 && V4==1 && V5==1 && V6==1 )
moveCar(120,0,120,0);
}
