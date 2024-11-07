/*u8 , #include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "tu_SSID";
const char* password = "tu_password";
const char* mqtt_server = "IP_del_broker_Mosquitto";

WiFiClient espClient;
PubSubClient client(espClient);*/

const int redPin = 16;    // Pin del LED RGB para el color rojo
const int greenPin = 17;  // Pin del LED RGB para el color verde
const int bluePin = 18;   // Pin del LED RGB para el color azul
const int vrxPin = 34;    // Eje X del joystick
const int vryPin = 35;    // Eje Y del joystick
const int swPin = 27;     // Botón del joystick

void setup() {
  Serial.begin(115200);
  //setup_wifi();
  //client.setServer(mqtt_server, 1883);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
}

void loop() {
  //if (!client.connected()) {
    //reconnect();
  //}
  //client.loop();

  int vrxValue = analogRead(vrxPin);
  int vryValue = analogRead(vryPin);
  int swValue = digitalRead(swPin);

  // Cambia el color del LED RGB según el movimiento del joystick
  if (vrxValue < 1000) {
    setColor(255, 0, 0);  // Rojo (izquierda)
    //client.publish("joystick/direction", "LEFT");
  } else if (vrxValue > 3000) {
    setColor(0, 255, 0);  // Verde (derecha)
    //client.publish("joystick/direction", "RIGHT");
  } else if (vryValue < 1000) {
    setColor(0, 0, 255);  // Azul (arriba)
    //client.publish("joystick/direction", "UP");
  } else if (vryValue > 3000) {
    setColor(255, 255, 0);  // Amarillo (abajo)
    //client.publish("joystick/direction", "DOWN");
  } else {
    setColor(0, 0, 0);  // Apaga el LED
  }

  // Publicar estado del botón y cambiar a color magenta
  if (swValue == LOW) {
    setColor(255, 0, 255);  // Magenta si se presiona el botón
    //client.publish("joystick/button", "PRESSED");
  } else {
    //client.publish("joystick/button", "RELEASED");
  }

  delay(200);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

/*void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("joystick/#");
    } else {
      delay(5000);
    }
  }
}*/