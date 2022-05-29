int ledpin[12] = {23, 22, 15, 13, 21, 19, 18, 05, 17, 16, 4, 2};
                //0   1   2    3  4   5   6   7    8   9  10  11
                //r   y   g    r  y   g   r   y    g   r  y    g
                
int delaygreen1 = 5000;
int delaygreen2 = 5000;   
int delaygreen3 = 5000;   
int delaygreen4 = 5000;

int fsrpin[4] = {34, 35, 32, 33};
int fsrreading1;
int fsrreading2;
int fsrreading3;
int fsrreading4;
int flag = 0;
int check = 0; int check2=0;
int thres = 20;  //threshold

#define default 5000;


int checktraffic();

void setup() {
  // put your setup code here, to run once:
  for(int x = 0; x<=12; x++){
  pinMode(ledpin[x], OUTPUT);
  }
  // turn all yellows on
    Serial.begin(9600);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[3], LOW);
    digitalWrite(ledpin[6], LOW);
    digitalWrite(ledpin[9], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[4], HIGH);
    digitalWrite(ledpin[7], HIGH);
    digitalWrite(ledpin[10], HIGH);
    
    delay(5000);

}

void loop() {
    // put your main code here, to run repeatedly:
   //take fsr readings and turn yellow on at signal 1
  fsrreading1= analogRead(fsrpin[0]);
  fsrreading2= analogRead(fsrpin[1]);
  fsrreading3= analogRead(fsrpin[2]); 
  fsrreading4= analogRead(fsrpin[3]); 
  check = checktraffic();
  Serial.println(check);
  delay(3000);
  check2 = checktraffic();
  
if( check == check2){
    switch (flag){
      case 0: break;
      case 1: delaygreen1 = 10000; delaygreen2 = 3000; delaygreen3 = 3000; delaygreen4 = 3000; break;
      case 2: delaygreen1 = 3000; delaygreen2 = 10000; delaygreen3 = 3000; delaygreen4 = 3000; break;
      case 3: delaygreen1 = 3000; delaygreen2 = 3000; delaygreen3 = 10000; delaygreen4 = 3000; break;
      case 4: delaygreen1 = 3000; delaygreen2 = 3000; delaygreen3 = 3000; delaygreen4 = 10000; break; 
      case 5: delaygreen1 = 8000; delaygreen2 = 8000; delaygreen3 = 3000; delaygreen4 = 3000; break;
      case 6: delaygreen1 = 8000; delaygreen2 = 3000; delaygreen3 = 8000; delaygreen4 = 3000; break;
      case 7: delaygreen1 = 8000; delaygreen2 = 3000; delaygreen3 = 3000; delaygreen4 = 8000; break;
      case 8: delaygreen1 = 3000; delaygreen2 = 8000; delaygreen3 = 8000; delaygreen4 = 3000; break;
      case 9: delaygreen1 = 3000; delaygreen2 = 8000; delaygreen3 = 3000; delaygreen4 = 8000; break;
      case 10: delaygreen1 = 3000; delaygreen2 = 3000; delaygreen3 = 8000; delaygreen4 = 8000; break;
      case 11: delaygreen1 = 8000; delaygreen2 = 8000; delaygreen3 = 8000; delaygreen4 = 3000; break; 
      case 12: delaygreen1 = 8000; delaygreen2 = 8000; delaygreen3 = 3000; delaygreen4 = 8000; break;
      case 13: delaygreen1 = 8000; delaygreen2 = 3000; delaygreen3 = 8000; delaygreen4 = 8000; break;
      case 14: delaygreen1 = 3000; delaygreen2 = 8000; delaygreen3 = 8000; delaygreen4 = 8000; break;
      case 15: delaygreen1 = 7000; delaygreen2 = 7000; delaygreen3 = 7000; delaygreen4 = 7000; break;
    }
  } 
  else {
    delaygreen1 = default;
    delaygreen2 = default;
    delaygreen3 = default;
    delaygreen4 = default;
  }
  flag = 0;  //reset flag 
  Serial.println(delaygreen1);
  Serial.println(delaygreen2);
  Serial.println(delaygreen3);
  Serial.println(delaygreen4);
  

    // turn all yellows off, and opposite greens and reds

    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[4], LOW);
    digitalWrite(ledpin[7], LOW);
    digitalWrite(ledpin[10], LOW);
    digitalWrite(ledpin[3], HIGH);
    digitalWrite(ledpin[6], HIGH);
    digitalWrite(ledpin[9], HIGH);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[2], HIGH); //green
    
    delay(delaygreen1);

    
    delaygreen1 = default;
    
    // yellows on(at signal 1 and 2) and dim green
    
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[4], HIGH);
    digitalWrite(ledpin[2], LOW); //green
    
    delay(3000);
    // turn both yellows off, and opposite green and red
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[4], LOW);
    digitalWrite(ledpin[7], LOW);
    digitalWrite(ledpin[10], LOW);
    digitalWrite(ledpin[3], LOW);
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[6], HIGH);
    digitalWrite(ledpin[9], HIGH);
    digitalWrite(ledpin[5], HIGH); //green
    delay(delaygreen2);
    delaygreen2 = default;
     // yellows on(at signal 2 and 3) and dim green
    digitalWrite(ledpin[4], HIGH);
    digitalWrite(ledpin[7], HIGH);
    digitalWrite(ledpin[5], LOW);
    delay(3000);
    // turn both yellows off, and opposite green and red
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[4], LOW);
    digitalWrite(ledpin[7], LOW);
    digitalWrite(ledpin[10], LOW);
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[6], LOW);
    digitalWrite(ledpin[3], HIGH);
    digitalWrite(ledpin[9], HIGH);
    digitalWrite(ledpin[8], HIGH); //green
    delay(delaygreen3);
    delaygreen3 = default;
    // yellows on(at signal 3 and 4) and dim green
    digitalWrite(ledpin[7], HIGH);
    digitalWrite(ledpin[10], HIGH);
    digitalWrite(ledpin[8], LOW);
    delay(3000);
    
    // turn both yellows off, and opposite green and red
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[4], LOW);
    digitalWrite(ledpin[7], LOW);
    digitalWrite(ledpin[10], LOW);
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[3], HIGH);
    digitalWrite(ledpin[9], LOW);
    digitalWrite(ledpin[6], HIGH);
    digitalWrite(ledpin[11], HIGH);  //green
    delay(delaygreen4);
    delaygreen4 = default;
    // yellows on(at signal 4 and 1) and dim green
    
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[10], HIGH);
    digitalWrite(ledpin[11], LOW);

}
//function of checktraffic which takes the sensor readings and returns a flag which indicates a set situation.
int checktraffic(){     //function to check traffic and give output for all unique scenarios. 
  int count =0;
if (fsrreading1 >= thres && fsrreading2 >= thres && fsrreading3 >= thres && fsrreading4 >= thres){
  flag = 15;
  
 }
 while(flag != 15 && count <=1){
    if (fsrreading1 >= thres) {
      if(fsrreading2 >= thres) {
        if(fsrreading3 >= thres) flag = 11;
        else if(fsrreading4 >= thres) flag = 12;
        else flag = 5;
      }
      else if(fsrreading3 >= thres){
        if(fsrreading4 >= thres) flag = 13;
        else flag = 6;
      }
      else if (fsrreading4 >= thres) flag = 7;
      else flag = 1; 
    }
    else if (fsrreading2 >= thres) {
      if(fsrreading3 >= thres) {
       if(fsrreading4 >= thres) flag = 14;
       else flag = 8;
      }
      else if (fsrreading4 >= thres) flag = 9;
      else flag= 2; 
    }
    else if(fsrreading3 >= thres){
      if (fsrreading4 >= thres) flag = 10;
      else flag = 3;
    }
    else if(fsrreading4 >= thres) flag = 4;
  count++;
}
return flag;
}
