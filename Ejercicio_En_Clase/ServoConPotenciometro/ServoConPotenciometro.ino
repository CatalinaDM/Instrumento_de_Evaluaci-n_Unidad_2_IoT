#include <ESP32Servo.h>

Servo servoMotor;  // Crea un objeto de tipo Servo
int pinPotenciometro = 2; // Pin donde está conectado el potenciómetro
int valorPotenciometro;     // Variable para almacenar el valor del potenciómetro (0-1023)
int angulo;                 // Variable para almacenar el ángulo del servo (0-180)

void setup() {
  servoMotor.attach(5); // Asigna el pin 9 al servo
}

void loop() {
  valorPotenciometro = analogRead(pinPotenciometro);         // Lee el valor del potenciómetro
  angulo = map(valorPotenciometro, 0, 1023, 0, 180);         // Convierte el valor a un ángulo de 0 a 180 grados
  servoMotor.write(angulo);                                  // Mueve el servo al ángulo calculado
  delay(15);                                                 // Pausa para suavizar el movimiento
}
