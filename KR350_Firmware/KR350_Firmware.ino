#include <AccelStepper.h>
#include <MultiStepper.h>

const int stepA4 = 2;
const int dirA4  = 5;

const int stepA5 = 3;
const int dirA5  = 6;

const int stepA6 = 4;
const int dirA6  = 7;


const int Pos4 = A3;
const int Neg4  = 11;

const int Pos5 = 10;
const int Neg5  = 13;

const int Pos6 = 9;
const int Neg6  = 12;

//Bolian
int StartupSequenceRan = false;

// Define some steppers and the pins the will use
AccelStepper Axis4(AccelStepper::DRIVER, stepA4, dirA4);
AccelStepper Axis5(AccelStepper::DRIVER, stepA5, dirA5);
AccelStepper Axis6(AccelStepper::DRIVER, stepA6, dirA6);

void setup() 
{  
    Serial.begin(9600);

    pinMode(8, OUTPUT); // **** set the enable pin to output
    digitalWrite(8, LOW); // *** set the enable pin low
  
    pinMode(stepA4,OUTPUT);
    pinMode(dirA4,OUTPUT);
  
    pinMode(stepA5,OUTPUT);
    pinMode(dirA5,OUTPUT);
  
    pinMode(stepA6,OUTPUT);
    pinMode(dirA6,OUTPUT);

    pinMode(Pos4, INPUT);
    pinMode(Neg4, INPUT);
    
    pinMode(Pos5, INPUT);
    pinMode(Neg5, INPUT);
    
    pinMode(Pos6, INPUT);
    pinMode(Neg6, INPUT);
    
  
    Axis4.setMaxSpeed(100000000.0);//800
    Axis4.setAcceleration(3000.0);
    
    Axis5.setMaxSpeed(100000000.0);//10000
    Axis5.setAcceleration(30000.0);
    
    Axis6.setMaxSpeed(10000.0);//10000
    Axis6.setAcceleration(3000.0);



}

void StartupSequence() {
    Axis4.setMaxSpeed(10000.0);
    Axis5.setMaxSpeed(10000.0);
    Axis6.setMaxSpeed(10000.0);
    Axis4.moveTo(0);//2100
    Axis5.move(5000);//5000
    Axis6.moveTo(0); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Move one complete");
      Serial.print("\n");
      delay(500);
    }

    Axis4.setMaxSpeed(10000.0);
    Axis5.setMaxSpeed(10000.0);
    Axis6.setMaxSpeed(10000.0);
    Axis4.moveTo(-3000);//2100
    Axis5.move(-3000);//5000
    Axis6.moveTo(0); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Move two complete");
      Serial.print("\n");
      delay(500);
    }

    Axis4.setMaxSpeed(1100.0);
    Axis5.setMaxSpeed(100000.0);
    Axis6.setMaxSpeed(10000.0);
    Axis4.move(-3000);//2100
    Axis5.move(0);//5000
    Axis6.move(-7000); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Move three complete");
      Serial.print("\n");
      delay(500);
    }

    Axis4.setMaxSpeed(10000.0);
    Axis5.setMaxSpeed(10000.0);
    Axis6.setMaxSpeed(10000.0);
    Axis4.move(0);//2100
    Axis5.move(5000);//5000
    Axis6.move(0); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Move four complete");
      Serial.print("\n");
      delay(500);
    }

    //Backlash Compensation
    Axis4.setMaxSpeed(10000.0);
    Axis4.move(600);
    while (Axis4.distanceToGo() !=  0) {
      Axis4.run();
    }
    
    Axis4.setMaxSpeed(10000.0);
    Axis5.setMaxSpeed(10000.0);
    Axis6.setMaxSpeed(10000.0);
    Axis4.move(3000);//2100
    Axis5.move(3000);//5000
    Axis6.move(0); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Move five complete");
      Serial.print("\n");
      delay(500);
    }
    
    Axis4.setMaxSpeed(550.0);
    Axis5.setMaxSpeed(10000.0);
    Axis6.setMaxSpeed(3000.0);
    Axis4.move(2100);//2100
    Axis5.move(0);//5000
    Axis6.moveTo(0); //5000
    while (Axis4.distanceToGo() !=  0 || Axis5.distanceToGo() != 0 || Axis6.distanceToGo() != 0) {
      Axis4.run();
      Axis5.run();
      Axis6.run();
    } if (Axis4.distanceToGo() == 0 && Axis5.distanceToGo() == 0 && Axis6.distanceToGo() == 0) {
      Serial.print("Zero Position");
      Serial.print("\n");
      delay(3000);
    }

}

void ReadInputs() {
  Serial.print("Pos4: ");
  Serial.print(digitalRead(Pos4));
  Serial.print("\n");
  Serial.print("Neg4: ");
  Serial.print(digitalRead(Neg4));
  Serial.print("\n");
  Serial.print("Pos5: ");
  Serial.print(digitalRead(Pos5));
  Serial.print("\n");
  Serial.print("Neg5: ");
  Serial.print(digitalRead(Neg5));
  Serial.print("\n");
  Serial.print("Pos6: ");
  Serial.print(digitalRead(Pos6));
  Serial.print("\n");
  Serial.print("Neg6: ");
  Serial.print(digitalRead(Neg6));
  Serial.print("\n");
  delay(1000);
}

void loop()
{
  //Run Startup Sequence Once
  if (StartupSequenceRan == false) {
    StartupSequence();

    //Bolian
    StartupSequenceRan = true;
  }

  //ReadInputs();

  //Main

  Axis4.setMaxSpeed(10000.0);
  Axis5.setMaxSpeed(10000.0);
  Axis6.setMaxSpeed(10000.0);
    
  //Axis 6 Pos
  while (digitalRead(Pos4) == 1) {
    Axis6.move(1000);
    Axis6.run();
  }
  while (digitalRead(Pos4) == 0 && Axis6.distanceToGo() !=  0) {
    Axis6.run();
  }

  //Axis 6 Neg
  while (digitalRead(Neg4) == 1) {
    Axis6.move(-1000);
    Axis6.run();
  }
  while (digitalRead(Neg4) == 0 && Axis6.distanceToGo() !=  0) {
    Axis6.run();
  }

  //Axis 5 Pos
  while (digitalRead(Pos5) == 1) {
    Axis5.move(1000);
    Axis5.run();
  }
  while (digitalRead(Pos5) == 0 && Axis5.distanceToGo() !=  0) {
    Axis5.run();
  }

  //Axis 5 Neg
  while (digitalRead(Neg5) == 1) {
    Axis5.move(-1000);
    Axis5.run();
  }
  while (digitalRead(Neg5) == 0 && Axis5.distanceToGo() !=  0) {
    Axis5.run();
  }

  //Axis 4 Pos
  while (digitalRead(Pos6) == 1) {
    Axis4.move(1000);
    Axis4.run();
  }
  while (digitalRead(Pos6) == 0 && Axis4.distanceToGo() !=  0) {
    Axis4.run();
  }

  //Axis 4 Neg
  while (digitalRead(Neg6) == 1) {
    Axis4.move(-1000);
    Axis4.run();
  }
  while (digitalRead(Neg6) == 0 && Axis4.distanceToGo() !=  0) {
    Axis4.run();
  }

}
