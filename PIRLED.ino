int PIR = 2;
int statusPin = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(PIR, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  statusPin = digitalRead(PIR);
  if(statusPin == HIGH)
  {
    Serial.println("Gerakan Terdeteksi");
    digitalWrite(13, HIGH);
    delay(1000); // Menunda output selama 1 detik
  }
  else
  {
    Serial.println("Tidak ada Gerakan");
    digitalWrite(13, LOW);
    delay(1000); // Menunda output selama 1 detik
  }
}