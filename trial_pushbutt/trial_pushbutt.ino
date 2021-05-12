#define button 3
boolean buttonState;
void setup()
{
 pinMode(button,INPUT_PULLUP);
 Serial.begin(9600);
}
void loop()
{
 digitalWrite(button,HIGH);
 buttonState = digitalRead(button);
 Serial.println(buttonState);
}
