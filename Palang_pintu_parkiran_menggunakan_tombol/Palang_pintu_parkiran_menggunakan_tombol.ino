#include <Wire.h> // memasukan library Wire untuk membantu berkomunikasi dengan I2c
#include <LiquidCrystal_I2C.h> // memasukan library LiquidCrystal_I2C agar komunikasi dengan display baik
#include<Servo.h> //memasukan library servo

LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 = alamat ic yang digunakan, 16 = kolom, 2 = baris.

Servo Myservo;
int pos=0;
int trigPin = 2; //trigPin pada HC-SR04 dipasang ke pin 2
int echoPin = 3; //echoPin pada HC-SR04 dipasang ke pin 3
long waktu;
int jarak;

void setup() 
{
lcd.begin(); // menyalakan layar LCD
lcd.backlight(); // menyalakan lampu belakang
pinMode(trigPin, OUTPUT); // trigPin menjadi OUTPUT
pinMode(echoPin, INPUT); // echoPin menjadi INPUT
pinMode(4,INPUT);
Myservo.attach(5);
Serial.begin(9600); // untuk kecepatan pengiriman, biasanya 9600
}

void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(500);
digitalWrite(trigPin, HIGH);
delayMicroseconds(500);
digitalWrite(trigPin, LOW);
waktu = pulseIn(echoPin, HIGH);

jarak = waktu*0.034/2; // rumus jarak dalam cm yaitu waktu*kecepatan. kecepatan gelombang ultrasonik yaitu 0.034/2

lcd.setCursor(0,0); // menampilkan di layar LCD pada baris ketiga kolom pertama.
lcd.print("Selamat Datang "); // buat tulisan jarak dalam cm (max 16 huruf).
lcd.setCursor(0,1);  // menampilkan di layar LCD pada baris pertama kolom kedua.
lcd.print("Di Mall Kokas"); // buat nilai jaraknya (max 16 huruf).

  if(digitalRead(4)==LOW){
  Myservo.write(0);
  
}
  
  if(jarak<10){
    delay(1000);
    Myservo.write(90);
    delay(500);
    }
  
}
