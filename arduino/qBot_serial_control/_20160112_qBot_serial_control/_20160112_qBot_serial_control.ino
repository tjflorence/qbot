// irobot should be at 57600 baud, 8 data bits, 1 stop bit, no flow control
// data sent / received every 15 ms

// 1) read data from serial1(computer, commands), write to serial 2(commands, robot), pause 15 ms
// 2) request data packet from robot, wait, read data packets from robot
// -- > set packet streaming during setup! try this first, then if doesn't work try per-sample setup
// 3) write data packets to robot
String inString = "";
boolean stringComplete0 = false;
boolean stringComplete1 = false;
const char setSafeMode[] = {char(131)};
const char setStream[] = {char(148), char(6), char(7), char(9), char(10), char(11), char(12), char(25)};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(57600);

 // while (!Serial) {
    // wait for serial port to connect
 //   delay(1);
 // }

  Serial1.write(setSafeMode, 1);
  delay(15);
  Serial1.write(setStream, 8);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    while (!stringComplete0) {

      int inChar = Serial.read();

      if (isDigit(inChar)) {
        inString += char(inChar);
      }

      if (inChar == '\n') {
        stringComplete0 == true;
      }
    }
  }

  Serial1.println(inString);
  stringComplete0 = false;
  inString = "";

  Serial1.flush();
  delay(15);

  if(Serial1.available()>0){
  while (!stringComplete1) {

    int inChar = Serial1.read();

    if (isDigit(inChar)) {
      inString += char(inChar);
    }

    if (inChar == '\n') {
      stringComplete1 = true;
    }
  }
  }
  
  Serial.println(inString);
  stringComplete1 = false;
  inString = "";

}

/*

*/
