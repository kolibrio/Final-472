const int PWM_A = 3;  // SN754410NE IN1 (Pin 2)
const int PWM_B = 2;  // SN754410NE IN2 (Pin 7) - Complementary

byte trigPin = 6;    // Trigger is connected to this pin
byte echoPin = 5;    // Echo is connected to this pin


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Configure
  analogWriteFrequency(PWM_A, 40000);  
  analogWriteFrequency(PWM_B, 40000);  
  analogWriteResolution(12);  // 12-bit resolution (0-4095)

  Serial.begin(9600);
}

void loop() {

  float modulationDepth = 0.9; // 90% modulation depth
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send 10µs pulse to trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration
  long duration = pulseIn(echoPin, HIGH);
  // Calculate distance (in cm)
  // Speed of sound is 343 m/s or 0.0343 cm/µs
  // Distance is round trip, so divide by 2
  float distance = duration * 0.0343 / 2;

  digitalWrite(LED_BUILTIN, HIGH);

  for (int i = 0; i < 888/distance; i++) {
    // Generate wave
    float para = 2048 * (1.0 + modulationDepth * sin(1.8 * PI * distance * i));
   
    analogWrite(PWM_A, (int)para);
    analogWrite(PWM_B, 4095 - (int)para);  // complimentary
    delay(1);
  }
}