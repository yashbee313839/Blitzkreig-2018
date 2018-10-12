#define ipin P1_2
#define cpin P1_3
#define tpin P1_4
int f = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ipin, INPUT);
  pinMode(cpin, OUTPUT);
  pinMode(tpin, OUTPUT);
}

void loop() {
  unsigned int pulse = pulseIn(ipin, LOW);
  if (pulse > 2000 && pulse < 6000)
  {
    digitalWrite(cpin, HIGH);
    digitalWrite(tpin, LOW);
    delay(5000);
    
  }
  else if (pulse > 6000 && pulse < 10000)
  {
    digitalWrite(tpin, HIGH);
    digitalWrite(cpin, LOW);
    delay(5000);
  }
}
