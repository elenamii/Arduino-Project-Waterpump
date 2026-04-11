#define pumpPin 5

int waterDurationInSec = 3;
long timer = 1000*60*60*24;

void setup()
{
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

void loop()
{
  delay(timer);
  waterPlant();
}


void waterPlant()
{
  digitalWrite(pumpPin, 1);
  delay(waterDurationInSec * 1000);
  digitalWrite(pumpPin, 0);
}
