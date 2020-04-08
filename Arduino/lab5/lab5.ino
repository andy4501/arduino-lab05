#include <Keypad.h>
int seg7[]={17,16,15,14,13,12,11};
char ch;
//共陰七段顯示器編碼表
char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
//            0   1    2    3    4    5    6    7    8    9 
char bbb[]={0x77,0x7C,0x39,0x5E,0x79,0x71};
//            A    B    C    D    E    F
int i,j;
byte no=0;
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {
{'0','4','8','C'}, 
{'1','5','9','D'},
{'2','6','A','E'}, 
{'3','7','B','F'}
};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {2, 3, 4 ,5};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {6 ,7 ,8 ,9};
// 連到 Keypad 的 4 個 Columns
// 建立 Keypad 物件
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
void setup() {
  // put your setup code here, to run once:
for(i=0;i<7;i++){
    pinMode(seg7[i],OUTPUT);
  }
 Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
    Serial.println(key);
    if(key>='0'&&key<='9')
  {
    no=key-'0';//將ASCII值轉成數值no
  
    OutPort(TAB[no]);
    delay(500);
    
  }

   if(key>='A'&&key<='F')
  {
    no=key-'a';
  
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
