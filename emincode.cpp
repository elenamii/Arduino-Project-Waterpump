#define moistureSensor A5
#define pumpPin 7

int waterDurationInSec = 3;
int readIntervalInSec = 10;


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
  
  if(moisture < 100)
  {

    waterPlant();

  }

}

int getMoisture()
{
  delay(readIntervalInSec * 1000);
  int moistureValue = analogRead(moistureSensor);
  return moistureValue;
}

void waterPlant()
{
  digitalWrite(pumpPin, HIGH);
  delay(waterDurationInSec * 1000);
  digitalWrite(pumpPin, LOW);
}