// C++ code
//

String username;
const int red = 8;
const int green = 9;
const int blue = 10;

uint16_t transitionTime = 300;

uint16_t getUserOption()
{
  Serial.println("Select which LED to blink!");
  Serial.println("1. Red");
  Serial.println("2. Green");
  Serial.println("3. Blue");
  Serial.println("4. Red & Green");
  Serial.println("5. Green & Blue");
  Serial.println("6. Blue & Red");
  Serial.println("7. All of them");
  Serial.print("Your option (1-7): ");
  
  while (Serial.available() == 0) {}
  uint16_t option = Serial.parseInt();
  return option;
}

uint16_t getUserBlinkCount()
{
  Serial.print("Enter the number of times LED(s) blink: ");
  
  while (Serial.available() == 0) {}
  uint16_t count = Serial.parseInt();
  return count;
}

const uint16_t LED_states[8][3] = {
  {LOW, LOW, LOW},
  {HIGH, LOW, LOW},
  {LOW, HIGH, LOW},
  {LOW, LOW, HIGH},
  {HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH},
  {HIGH, LOW, HIGH},
  {HIGH, HIGH, HIGH}
};

void blinkLED(uint16_t option)
{
  if (option < 1 || option > 7) option = 0;
  
  digitalWrite(red, LED_states[option][0]);
  digitalWrite(green, LED_states[option][1]);
  digitalWrite(blue, LED_states[option][2]);
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  Serial.print("Enter your name: ");
  while (Serial.available() == 0) {}
  username = Serial.readStringUntil('\n');
  username.trim();
  Serial.println(username);
  char msg1buffer[120];
  snprintf(msg1buffer, sizeof(msg1buffer), "\nHello %s, please select the blinking options and enter the number of blinks!", username.c_str());
  Serial.println(msg1buffer);
}

void loop()
{ 
  uint16_t user_option = getUserOption();
  Serial.println(user_option);
  
  uint16_t blink_count = getUserBlinkCount();
  char msg2buffer[50];
  snprintf(msg2buffer, sizeof(msg2buffer), "\nLED(s) will blink %u time(s).", blink_count);
  Serial.println(msg2buffer);
  
  while (blink_count > 0)
  {
    blinkLED(user_option);
    delay(transitionTime);
    
    blinkLED(0);
    delay(transitionTime);
    
    blink_count--;
  }
  
  Serial.println("Done!\n");
}