int btn1 = 1;
int btn2 = 2;
int btn3 = 3;
int btn4 = 4;
int btn5 = 5;
int btn6 = 6;
int btn8 = 8;
int btn7 = 7;
int btn9 = 9;
int led01 = 0;
int led02 = 10;
int led03 = 11;
int led04 = 12;
int led05 = 13;
bool stt_led02 = true;
bool stt_led04 = true;
bool stt_all = true;
bool isPressed1 = false;
bool isPressed2 = false;
bool isPressed3 = false;
bool isPressed4 = false;
bool isPressed5 = false;
bool isPressed6 = false;
bool isPressed7 = false;
bool isPressed8 = false;
bool isPressed9=false;
int t_pre02 = 0;
int t_pre04 = 0;
int t_preAll = 0;
int mode_baochay =2;
int mode_phongkhach =3;
int mode_phongngu =3;
int mode_phongbep =2;
int mode_phongwc =2;
void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn6, INPUT);
  pinMode(btn7, INPUT);
  pinMode(btn8, INPUT);
  pinMode(btn9, INPUT);
  pinMode(led01, OUTPUT); 
  pinMode(led02, OUTPUT);     
  pinMode(led03, OUTPUT); 
  pinMode(led04, OUTPUT);
  pinMode(led05, OUTPUT); 
}

void loop() {
  //Phòng khách
  if(digitalRead(btn9)==1){
    isPressed9=true;
  }
  else{
    if(isPressed9)
  {
    mode_phongkhach=(mode_phongkhach==3? mode_phongkhach = 1 : mode_phongkhach+1);
      if(mode_phongkhach == 2){
        t_pre02=millis();
        stt_led02 = 1;   
      } 
      isPressed9=false;
  }
  }
    if(mode_baochay!=1){

  switch(mode_phongkhach){
    case 1:
        digitalWrite(led02,1);
      break;
    case 2:
        if(millis()-t_pre02>=100){
        digitalWrite(led02,stt_led02);
        stt_led02=!stt_led02;
        t_pre02=millis();
      }
      break;   
    case 3:
    digitalWrite(led02,0);
      break;
  }
    }
//Phòng ngủ

  if(digitalRead(btn7)==1){
    isPressed7=true;
  }
  else{
    if(isPressed7)
  {
    mode_phongngu=(mode_phongngu==3? mode_phongngu = 1 : mode_phongngu+1);
      if(mode_phongngu == 2){
        t_pre04=millis();
        stt_led04 = 1;   
      } 
      isPressed7=false;
  }
  }
    if(mode_baochay!=1){

  switch(mode_phongngu){
    case 1:
        digitalWrite(led04,1);
      break;
    case 2:
          if(millis()-t_pre04>=100){
        digitalWrite(led04,stt_led04);
        stt_led04=!stt_led04;
        t_pre04=millis();
      }
      break;
    case 3:
        digitalWrite(led04,0);
      break;   

  }
    }

  //Phòng bếp
  if(digitalRead(btn6)==HIGH){
    isPressed6=true;
  }
  else{ 
     if(isPressed6){
      mode_phongbep=(mode_phongbep==2?mode_phongbep=1:mode_phongbep+1);
      isPressed6=false;
    }
      if(mode_baochay!=1){
        switch(mode_phongbep){
          case 1:
            digitalWrite(led03,HIGH);
          break;

          case 2:
              digitalWrite(led03,LOW);
          break;
      }
    }
  }

  //Phòng WC
    if(digitalRead(btn8)==HIGH){
    isPressed8=true;
  }
  else{ 
     if(isPressed8)
      mode_phongwc=(mode_phongwc==2?mode_phongwc=1:mode_phongwc+1);
      isPressed8=false;
  }
  if(mode_baochay!=1){
    switch(mode_phongwc){
      case 1:
        digitalWrite(led05,HIGH);
      break;
      case 2:
          digitalWrite(led05,LOW);
      break; 
    }
}
 
  //Nút tắt hết đèn khi ra khỏi nhà
  if(digitalRead(btn3)==1){
      isPressed3=true;
  }
  else{
      if(mode_baochay!=1){
        if(isPressed3){
          digitalWrite(led01,0);
          digitalWrite(led02,0);
          digitalWrite(led03,0);
          digitalWrite(led04,0);
          digitalWrite(led05,0);
        }
        isPressed3=false;
      }
  }
  //Nút báo cháy
    if(digitalRead(btn5)==HIGH){
    isPressed5=true;
  }
  else{ 
     if(isPressed5){
      mode_baochay=(mode_baochay==2?mode_baochay=1:mode_baochay+1);
      if(mode_baochay==1){
        t_preAll=millis();
        stt_all = 1;
      }
      isPressed5=false;
    }
    switch(mode_baochay){
      case 1:
          if(millis()-t_preAll>=500){
              digitalWrite(led01,stt_all);
              digitalWrite(led02,stt_all);
              digitalWrite(led03,stt_all);
              digitalWrite(led04,stt_all);
              digitalWrite(led05,stt_all);
        stt_all=!stt_all;
        t_preAll=millis();
      }
      break;
      case 2:
              digitalWrite(led01,0);
              digitalWrite(led02,0);
              digitalWrite(led03,0);
              digitalWrite(led04,0);
              digitalWrite(led05,0);


      break;
  }
}


}
