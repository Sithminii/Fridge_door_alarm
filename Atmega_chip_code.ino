//Fridge door alarm ATmega328P code

//Defining ATmega328P pin names
const int buzzer = 13; //buzzer pin
const int hallSensor = 7; //hall effect sensor pin
#define push_button1 12
#define push_button2 11
#define push_button3 10
#define esp 6 

//Declaring variables
unsigned long gap;
int alarmState = 0;
int previousSensorState = 0;
unsigned long previousMillis = 0;
unsigned long firstAlarmMillis = 0;
unsigned long secondAlarmMillis = 0;
unsigned long thirdAlarmMillis = 0;

void setup() {
  //Declaring input output pins
  pinMode(buzzer, OUTPUT);
  pinMode(LED,OUTPUT); //new
  pinMode(hallSensor, INPUT);
  pinMode(push_button1,INPUT);
  pinMode(push_button2,INPUT);
  pinMode(push_button3,INPUT);
  pinMode(esp, OUTPUT);
}

void loop() {
  int sensorState = digitalRead(hallSensor);
  
  if (sensorState != previousSensorState) {
    previousSensorState = sensorState;
    
//Assigning alarm duration to each push button
    if (digitalRead(push_button1) == LOW){
      gap = 60000; //alarm gap 1 minute
    }
    else if (digitalRead(push_button2) == LOW){
      gap = 120000; //alarm gap 2 minutes
    }
    else if (digitalRead(push_button3) == LOW){
      gap = 600000; //alarm gap 10 minutes
    }
  

    
    if (sensorState == HIGH) { //door is opened
      alarmState = 1;
      firstAlarmMillis = millis() + gap;
      secondAlarmMillis = firstAlarmMillis + gap;
      thirdAlarmMillis = secondAlarmMillis + gap;
      digitalWrite(esp, HIGH);
    }
    else { //door is closed
      alarmState = 0;
      previousMillis = 0;
      digitalWrite(esp, LOW);
    }
  }
  
  unsigned long currentMillis = millis();

  //First alarm
  if (alarmState == 1 && currentMillis >= firstAlarmMillis) {
    digitalWrite(buzzer, HIGH);
    delay(10000); //first alarm duration
    digitalWrite(buzzer, LOW);
    alarmState = 2;
  }

  //Second alarm
  if (alarmState == 2 && currentMillis >= secondAlarmMillis) {
    digitalWrite(buzzer, HIGH);
    delay(10000); //second alarm duration
    digitalWrite(buzzer, LOW);
    alarmState = 3;
  }

  //Third alarm
  if (alarmState == 3 && currentMillis >= thirdAlarmMillis) {
    digitalWrite(buzzer, HIGH);
    delay(10000); //third alarm duration
    digitalWrite(buzzer, LOW);
    alarmState = 0;
    previousMillis = 0;
  }
}
