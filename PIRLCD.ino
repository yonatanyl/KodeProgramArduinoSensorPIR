#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C untuk LCD, sesuaikan dengan alamat LCD Anda
int PIR = 2;
int statusPin = 0;

void setup()
{
  Serial.begin(115200);
  lcd.init();                      // Inisialisasi LCD
  lcd.backlight();                 // Hidupkan backlight LCD
  lcd.setCursor(0, 0);
  lcd.print("Siap Mendeteksi");    // Pesan awal pada LCD
  pinMode(PIR, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  statusPin = digitalRead(PIR);
  if(statusPin == HIGH)
  {
    Serial.println("Gerakan Terdeteksi");
    lcd.setCursor(0, 1);
    lcd.print("Gerakan Terdeteksi ");
    digitalWrite(13, HIGH);
    delay(1000); // Menunda output selama 1 detik
  }
  else
  {
    Serial.println("Tidak ada Gerakan");
    lcd.setCursor(0, 1);
    lcd.print("Tidak ada Gerakan  ");
    digitalWrite(13, LOW);
    delay(1000); // Menunda output selama 1 detik
  }
}
