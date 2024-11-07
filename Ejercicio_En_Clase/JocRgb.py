from machine import Pin, ADC, PWM
import network
import time
from umqtt.simple import MQTTClient

# Configuración de WiFi
ssid = "UTNG_GUEST"
password = "R3d1nv1t4d0s#UT"
mqtt_server = "broker.emqx.io"
client_id = "ESP32_joystick_ccdm"
topic_dir = b'jfrg/joystick/direction'
topic_btn = b'jfrg/joystick/button'

# Pines del joystick y LED RGB
vrx = ADC(Pin(34))
vry = ADC(Pin(35))
button = Pin(27, Pin.IN, Pin.PULL_UP)

# Configuración de los pines PWM para el LED RGB
red = PWM(Pin(16), freq=500)
green = PWM(Pin(17), freq=500)
blue = PWM(Pin(18), freq=500)

# Conexión a WiFi
def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while not wlan.isconnected():
        time.sleep(0.5)

# Configuración de MQTT
def connect_mqtt():
    client = MQTTClient(client_id, mqtt_server)
    client.connect()
    return client

# Función para establecer el color del LED RGB
def set_color(r, g, b):
    red.duty(r)
    green.duty(g)
    blue.duty(b)

def main():
    connect_wifi()
    client = connect_mqtt()

    while True:
        x_value = vrx.read()
        y_value = vry.read()

        # Control de color basado en joystick
        if x_value < 1000:
            set_color(1023, 0, 0)  # Rojo
            client.publish(topic_dir, b'LEFT')
        elif x_value > 3000:
            set_color(0, 1023, 0)  # Verde
            client.publish(topic_dir, b'RIGHT')
        elif y_value < 1000:
            set_color(0, 0, 1023)  # Azul
            client.publish(topic_dir, b'UP')
        elif y_value > 3000:
            set_color(1023, 1023, 0)  # Amarillo
            client.publish(topic_dir, b'DOWN')
        else:
            set_color(0, 0, 0)  # Apaga el LED

        # Publicar estado del botón y cambiar a color magenta
        if not button.value():
            set_color(1023, 0, 1023)  # Magenta
            client.publish(topic_btn, b'PRESSED')
        else:
            client.publish(topic_btn, b'RELEASED')

        time.sleep(0.2)

main()