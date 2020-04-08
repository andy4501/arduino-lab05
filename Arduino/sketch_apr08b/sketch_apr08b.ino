int seg7[]={17,16,15,14,13,12,11};
char ch;
//共陰七段顯示器編碼表
char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
//            0   1    2    3    4    5    6    7    8    9 
char bbb[]={0x77,0x7C,0x39,0x5E,0x79,0x71};
//            A    B    C    D    E    F
int i,j;
byte no=0;

void setup() {
  // put your setup code here, to run once:
for(i=0;i<7;i++){
    pinMode(seg7[i],OUTPUT);
  }
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){//判斷串列富緩衝區有無資料
  ch=Serial.read();//從串列富緩衝區中讀取一個字元
  Serial.print(ch);
  
  if(ch>='a'&&ch<='f')
  {
    no=ch-'a';
  
    OutPort(bbb[no]);
    delay(500);
    
  }
    if(ch>='A'&&ch<='F')
  {
    no=ch-'A';
  
    OutPort(bbb[no]);
    delay(500);
    
  }
}
}
void OutPort(byte dat){
  for(j=0;j<7;j++){
    if(dat%2==1)
      digitalWrite(seg7[j],HIGH);
    else
      digitalWrite(seg7[j],LOW);
      dat=dat/2;
  }
}
