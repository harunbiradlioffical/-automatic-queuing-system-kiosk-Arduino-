const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
const int BUTTON_3_PIN = 4;
const int BUTTON_4_PIN = 5;

String roomNames[4] = {"01 nolu Asm", "02 nolu Asm", "03 nolu Asm", "06 nolu Asm"};

int room1Counter = 1;
int room2Counter = 1;
int room3Counter = 1;
int room4Counter = 1;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(BUTTON_1_PIN) == LOW){
    printRoomInfo(roomNames[0], room1Counter);
    room1Counter = incrementCounter(room1Counter);
    feed(6);
    cut();
    delay(1000);

  }
  if(digitalRead(BUTTON_2_PIN) == LOW){
    printRoomInfo(roomNames[1], room2Counter);
    room2Counter = incrementCounter(room2Counter);
    feed(6);
    cut();
    delay(1000);
  }
  if(digitalRead(BUTTON_3_PIN) == LOW){
    printRoomInfo(roomNames[2], room3Counter);
    room3Counter = incrementCounter(room3Counter);
    feed(3);
    cut();
    delay(1000);
  }
  if(digitalRead(BUTTON_4_PIN) == LOW){
    printRoomInfo(roomNames[3], room4Counter);
    room4Counter = incrementCounter(room4Counter);
    feed(6);
    cut();
    delay(1000);
  }
}

void printRoomInfo(String roomName, int counter){
  size(2);
  color(0);
  justification(1);
  Serial.println(roomName);
  Serial.print("Sira No: ");
  Serial.println(counter);
}

int incrementCounter(int counter){
  counter++;
  if(counter > 10000){
    counter = 1;
  }
  return counter;
}

void begin(){
  Serial.write(27);
  Serial.write(64);
  Serial.write(10);
}

void justification(int just){
  Serial.write(27);
  Serial.write(97);
  Serial.write(just);
  Serial.write(10);
}

void feed(int lines){
  Serial.write(27);
  Serial.write(100);
  Serial.write(lines);
  Serial.write(10);
}

void cut(){
  feed(3);
  Serial.write(27);
  Serial.write(105);
  Serial.write(10);
}

void color(bool col){
  Serial.write(29);
  Serial.write(66);
  Serial.write(col);
  Serial.write(10);
}

void size(int siz){
  Serial.write(29);
  Serial.write(33);
  Serial.write(siz);
  Serial.write(10);
}
