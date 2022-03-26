#define fsrpin 4

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
int analogReading = analogRead(fsrpin);

  Serial.print("The force sensor value = ");
  Serial.print(analogReading); // print the raw analog reading

  if (analogReading < 10)       // from 0 to 9
    Serial.println(" -> no pressure");
  else if (analogReading < 200) // from 10 to 199
    Serial.println(" -> light touch");
  else if (analogReading < 500) // from 200 to 499
    Serial.println(" -> light squeeze");
  else if (analogReading < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(1000);

}
