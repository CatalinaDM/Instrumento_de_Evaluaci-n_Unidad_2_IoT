#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR 
#endif

#define PIN 2

// Configuración de la matriz 8x8
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

int16_t x = matrix.width();
uint8_t color_index = 0;
char text[] = "CATI";
int scroll_limit = sizeof(text) * (6 + 5); // Añadir un espaciado entre caracteres

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(240);
  matrix.setTextColor(matrix.Color(255, 100, 0)); // Color inicial rojo
}

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(text);

  if (--x < -scroll_limit) {
    x = matrix.width();
    color_index = 0; // reinicia el índice de color del arco iris
  }

  matrix.setTextColor(color_wheel(color_index));
  color_index += max(1, 256 / scroll_limit);
  matrix.show();
  delay(100);
}

uint16_t color_wheel(uint8_t pos) {
  pos = 255 - pos;
  if (pos < 85) {
    return matrix.Color((uint16_t)(255 - pos * 3), 0, (pos * 3));
  } else if (pos < 170) {
    pos -= 85;
    return matrix.Color(0, (uint32_t)(pos * 3), (255 - pos * 3));
  } else {
    pos -= 170;
    return matrix.Color((uint16_t)(pos * 3), (uint32_t)(255 - pos * 3), 0);
  }
}