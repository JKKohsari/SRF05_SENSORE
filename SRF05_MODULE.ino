#include <SRF05Conf.h>
#include <Terminal.h>

SRF05Conf sonar(5 , 6); 
Terminal terminal;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  DistanceUnit unit = terminal.askUnit();
   float velocity = terminal.askVelocityOfSound();
  float threshold = terminal.askThreshold();
  sonar.setUnit(unit);
  sonar.setVelocityOfSound(velocity);
  sonar.setThreshold(threshold);
  // You might want to add a setter for threshold in SRF05Conf or handle separately
  Serial.println("Configuration complete.");
}

void loop() {
  
  float distance = sonar.readDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" ");
  Serial.println(sonar.getUnitString());

Serial.println("----------------");

  if (sonar.detector()) 
    Serial.println("Object Detected!");
  else
    Serial.println("Object not Detected!");

Serial.println("----------------");
    
float optDistance = sonar.readOptDistance();
  Serial.print("Opt Distance: ");
  Serial.print(optDistance);
  Serial.print(" ");
  Serial.println(sonar.getUnitString());


Serial.println("----------------");

  delay(3000);
}
