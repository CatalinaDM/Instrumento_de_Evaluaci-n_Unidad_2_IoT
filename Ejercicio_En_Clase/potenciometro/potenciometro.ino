//potenciómetro arduino

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir dimensiones de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Crear una instancia para la pantalla OLED
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Configuración del potenciómetro
const int potPin = 32;  // Pin analógico para el potenciómetro en ESP32

void setup() {
  // Iniciar comunicación serial para depuración
  Serial.begin(115200);

  // Iniciar la pantalla OLED
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Dirección I2C para el OLED
    Serial.println(F("Error al iniciar la pantalla OLED"));
    for (;;); // Bucle infinito si falla la pantalla
  }

  // Limpiar pantalla
  oled.clearDisplay();
}

void draw_tank(int x, int y, int width, int height, int fill_percentage) {
  // Dibujar el contorno del tanque
  oled.drawRect(x, y, width, height, SSD1306_WHITE);

  // Calcular la altura del llenado
  int fill_height = (fill_percentage * height) / 100;

  // Dibujar el llenado del tanque
  oled.fillRect(x + 1, y + height - fill_height, width - 2, fill_height, SSD1306_WHITE);
}

void mostrar_tanque() {
  // Leer el valor del potenciómetro (rango de 0 a 4095 en ESP32)
  int valor = analogRead(potPin);

  // Convertir el valor a porcentaje (0 a 100%)
  int porcentaje = map(valor, 0, 4095, 0, 100);

  // Limpiar la pantalla
  oled.clearDisplay();

  // Dibujar el tanque en el centro de la pantalla
  draw_tank(50, 10, 28, 44, porcentaje);

  // Mostrar el porcentaje de llenado
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(50, 55);
  oled.print(porcentaje);
  oled.print("%");

  // Actualizar la pantalla
  oled.display();
}

void loop() {
  // Llamar a la función para mostrar el tanque
  mostrar_tanque();

  // Esperar un momento antes de la próxima lectura
  delay(100);
}