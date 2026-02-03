#define moistureSensor A5
#define pumpPin 5

int waterDurationInSec = 3;
int readIntervallInSec = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

void loop()
{
  int moisture = getMoisture();
  Serial.println(moisture);
  if (moisture < 100)
  {
    Serial.println("unter 100");
    waterPlant();
    Serial.println("Fertig");
  }
}

int getMoisture()
{
  delay(readIntervallInSec * 1000);
  int moistureValue = analogRead(moistureSensor);
  return moistureValue;
}

void waterPlant()
{
  digitalWrite(pumpPin, 1);
  delay(waterDurationInSec * 1000);
  digitalWrite(pumpPin, 0);
}

