int btn3 = 3;
int btn4 = 4;
int btn5 = 5;
int btn7 = 7;
int btn9 = 9;
int led02 = 2;
int led04 = 4;
bool stt_led02 = true;
bool stt_led04 = true;
bool isPressed = false;
int t_pre = 0;
int mode_phongkhach =3 ;
int mode_phongngu =3;
void setup() {
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn9, INPUT);
  pinMode(btn7, INPUT);
  pinMode(led02, OUTPUT);      
}

void loop() {
  if(digitalRead(btn9)==1){
    isPressed=true;
  }
  else{
    if(isPressed)
  {
    mode_phongkhach=(mode_phongkhach==3? mode_phongkhach = 1 : mode_phongkhach+1);
      if(mode_phongkhach == 2){
        t_pre=millis();
        stt_led02 = 1;   
      } 
      isPressed=false;
  }
  }
  switch(mode_phongkhach){
    case 1:
        digitalWrite(led02,1);
      break;
    case 2:
        if(millis()-t_pre>=100){
        digitalWrite(led02,stt_led02);
        stt_led02=!stt_led02;
        t_pre=millis();
      }

      break;   
    default:
    digitalWrite(led02,0);
      break;
  }
//Phòng ngủ

  if(digitalRead(btn7)==1){
    isPressed=true;
  }
  else{
    if(isPressed)
  {
    mode_phongngu=(mode_phongngu==3? mode_phongngu = 1 : mode_phongngu+1);
      if(mode_phongngu == 2){
        t_pre=millis();
        stt_led04 = 1;   
      } 
      isPressed=false;
  }
  }
  switch(mode_phongngu){
    case 1:
        digitalWrite(led04,0);
      break;
    case 2:
        digitalWrite(led04,1);
      break;   
    default:
          if(millis()-t_pre>=100){
        digitalWrite(led04,stt_led04);
        stt_led04=!stt_led04;
        t_pre=millis();
      }
      break;
  }

}
