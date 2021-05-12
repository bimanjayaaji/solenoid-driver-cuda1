// pin-pin sudah dikonfigurasi menurut elektronika driver
// cek pin untuk kondisi (if-else) utama

void setup() 
{
Serial.begin(9600);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(A6,INPUT);
pinMode(A5,OUTPUT);
pinMode(3,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(4,OUTPUT);
digitalWrite(4,LOW);

//a1 01
//TCCR1A=0xA1;
//TCCR1B=0x01;

TCCR1A=0xA1;
TCCR1B=0x01;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
}

void loop()
{  
// Serial.println(digitalRead(3));
// delay(50);
// Serial.println(digitalRead(5));
// delay(50);

// OCR1B=110;  
// digitalWrite(8,LOW);
// digitalWrite(11,HIGH);
// Serial.println(digitalRead(3));  
// Serial.println(analogRead(A0));  
                                      
  if (digitalRead(3)==0) //                                                                                                                 
  {
   digitalWrite(A5,HIGH); // menutup relay untuk di sambungkan ke capacitor 
   if (analogRead(A6)>450)
   {
    OCR1AL=100;
    digitalWrite(8,LOW);
   }
   else 
   {   
    OCR1AL=0;
    digitalWrite(8,HIGH); 
   }
  }
  else 
  {
    digitalWrite(A5,LOW); // membuka relay // bisa di pakai untuk mengosongkan kapasitor 
    OCR1AL=0;
    digitalWrite(8,HIGH);

    if(digitalRead(5) == 0){
      digitalWrite(4,HIGH);
      delay(5);
      digitalWrite(4,LOW);
    }
  }

//   digitalWrite(A5,HIGH); // menutup relay untuk di sambungkan ke capacitor 
////   digitalWrite(9,HIGH); // modar optone   
////   digitalWrite(8,LOW);
//   delay(500);
////   digitalWrite(9,LOW); // modar optone   
////   digitalWrite(8,LOW); 
//  digitalWrite(A5,LOW); // menutup relay untuk di sambungkan ke capacitor 
//   delay(500);
}
