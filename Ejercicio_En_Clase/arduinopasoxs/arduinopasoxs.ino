#include <Stepper.h>

const int stepsPerRevolution = 2048;  

// Pines del controlador ULN2003
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// Inicializa la biblioteca Stepper
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// Variable para almacenar la velocidad
int speed = 9; // Velocidad inicial en RPM

void setup() {
  // Configurar la velocidad inicial
  myStepper.setSpeed(speed);
  // Inicializar el puerto serie
  Serial.begin(115200);
  Serial.println("Controlador de motor paso a paso inicializado.");
  Serial.print("Velocidad actual: ");
  Serial.println(speed);
}

void loop() {
  // Pedir al usuario que ajuste la velocidad
  if (Serial.available() > 0) {
    int inputSpeed = Serial.parseInt();
    if (inputSpeed > 0) {
      speed = inputSpeed;
      myStepper.setSpeed(speed);
      Serial.print("Velocidad ajustada a: ");
      Serial.println(speed);
    } else {
      Serial.println("Por favor, ingresa un número positivo.");
    }
  }

  // Pasar una revolución en una dirección:
  Serial.println("Sentido de las manecillas del reloj");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  // Pasar una revolución en la otra dirección:
  Serial.println("Sentido contrario a las manecillas del reloj");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
