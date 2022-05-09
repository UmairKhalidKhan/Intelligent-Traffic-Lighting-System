#define fsrpin 4
#define ledpin 13
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);  //digital output
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int input = analogRead(fsrpin);
Serial.println(input);
if(input > 20){
  digitalWrite(ledpin, HIGH);
}
 delay(2000);
digitalWrite(ledpin, LOW);
delay(2000);
}
