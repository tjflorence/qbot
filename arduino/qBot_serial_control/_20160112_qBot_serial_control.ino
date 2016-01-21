// irobot should be at 57600 baud, 8 data bits, 1 stop bit, no flow control
// data sent / received every 15 ms

// 1) read data from serial1(computer, commands), write to serial 2(commands, robot), pause 15 ms 
// 2) request data packet from robot, wait, read data packets from robot
// -- > set packet streaming during setup! try this first, then if doesn't work try per-sample setup
// 3) write data packets to robot
String inputString0 = "";
String inputString1 = "";
boolean stringComplete0 = false;
boolean stringComplete1 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial1.begin(57600);

  while(!Serial){
    // wait for serial port to connect
  }

  

}

void loop() {
  // put your main code here, to run repeatedly:
  

  while (!stringComplete0){
    
    int inChar = Serial.read();
    
    if (isDigit(inChar)) {
      inString += (char)inChar; 
    }
    if (inChar == '\n'){
      stringComplete0 == true;
    }
  }

  Serial1.println(inString)
  stringComplete0 == false;
  inString = "";

  Serial1.flush()
  while(Serial1.available()==0){
    delay(1)
  }
  

}

/*
  
 */
