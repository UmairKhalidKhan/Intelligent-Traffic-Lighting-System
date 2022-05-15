int ledpin[12] = {23, 22, 15, 2, 21, 19, 18, 05, 17, 16, 4, 2};
                //0   1   2  3  4   5   6   7    8   9  10  11
                //r   y   g  r  y   g   r   y    g   r  y    g
                
int delaygreen1 = 5000;
int delaygreen2 = 5000;
int delaygreen3 = 5000;
int delaygreen4 = 5000;


#define default 5000;
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
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[4], HIGH);
    digitalWrite(ledpin[7], HIGH);
    digitalWrite(ledpin[10], HIGH);
    delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  delay(3000);
 

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
    flag = 0 ;
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
