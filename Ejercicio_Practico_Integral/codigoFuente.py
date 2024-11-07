from machine import Pin, I2C, PWM, SoftI2C
from time import sleep
from ssd1306 import SSD1306_I2C
from dht import DHT11

# Configurar sensor DHT11 en el pin 27
dht_pin = Pin(27)
sensor = DHT11(dht_pin)

# Declarar pines RGB
Red = Pin(16, Pin.OUT)
Green = Pin(17, Pin.OUT)
Blue = Pin(18, Pin.OUT)

# Configurar Pantalla OLED usando I2C
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))
oled = SSD1306_I2C(128, 64, i2c)

# Configurar el pin del servo en el pin 26 para humedad
servo_h = PWM(Pin(26), freq=50)

# Función para mover el servo a un ángulo específico
def move_servo_h(angle):
    min_duty = 26    # Corresponde a 0 grados
    max_duty = 127   # Corresponde a 180 grados
    duty = int(min_duty + (angle / 180) * (max_duty - min_duty))
    servo_h.duty(duty)

while True:
    # Leer temperatura y humedad del sensor
    sensor.measure()
    h = sensor.humidity()
    
    # Mostrar la humedad en la pantalla OLED
    oled.fill(0)
    oled.text("Humedad: {}%".format(h), 0, 0)
    oled.show()
    sleep(2)
    
    # Mover el servo según el valor de humedad
    if h >= 60:
        move_servo_h(180)  # Abre ventilación
    else:
        move_servo_h(0)   # Cierra ventilación
    
    # Cambiar el color del LED RGB según el nivel de humedad
    if h < 40:
        Red.value(1)
        Green.value(0)
        Blue.value(0)
    elif 40 <= h < 60:
        Red.value(0)
        Green.value(1)
        Blue.value(0)
    elif h >= 60:
        Red.value(0)
        Green.value(0)
        Blue.value(1)
    
    sleep(5)
