// C++ code
//

int red = 11;
int green = 12;
int blue = 13;

String colors[] = {"Red", "Yellow", "Green", "Cyan", "Blue", "Magenta"};

const int color_states[][3] = {
  {HIGH, LOW,  LOW},  // 1. Red
  {HIGH, HIGH, LOW},  // 2. Yellow (Red + Green)
  {LOW,  HIGH, LOW},  // 3. Green
  {LOW,  HIGH, HIGH}, // 4. Cyan (Green + Blue)
  {LOW,  LOW,  HIGH}, // 5. Blue
  {HIGH, LOW,  HIGH}  // 6. Magenta (Red + Blue)
};

const int total_colors = 6;

const int transitionTime = 500;

void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  Serial.println("Loop start!\n");
  for (int i=0; i<total_colors; ++i)
  { 
  	digitalWrite(red, color_states[i][0]);
    digitalWrite(green, color_states[i][1]);
    digitalWrite(blue, color_states[i][2]);
    
    Serial.println(colors[i]);
    
    delay(transitionTime);
  }
  Serial.println("\nLoop end!\n");
  delay(transitionTime);
}


// hred, hgreen, lred, hblue, lgreen, hred, lblue

/**
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(blue, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(blue, LOW);
  delay(500);
*/