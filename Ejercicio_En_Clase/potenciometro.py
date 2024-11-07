import machine
import ssd1306
import time

# Configuración del potenciómetro
pot = machine.ADC(machine.Pin(32))

# Configuración del OLED display
i2c = machine.I2C(scl=machine.Pin(22), sda=machine.Pin(21))
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

def draw_tank(x, y, width, height, fill_percentage):
    # Dibujar contorno del tanque
    oled.rect(x, y, width, height, 1)

    # Calcular la altura del llenado
    fill_height = int((fill_percentage / 100) * height)

    # Dibujar el llenado del tanque
    oled.fill_rect(x + 1, y + height - fill_height, width - 2, fill_height, 1)

def mostrar_tanque():
    while True:
        # Leer el valor del potenciómetro (rango de 0 a 4095)
        valor = pot.read()

        # Convertir el valor a porcentaje (0 a 100%)
        porcentaje = int((valor / 4095) * 100)

        # Limpiar la pantalla
        oled.fill(0)

        # Dibujar el tanque en el centro de la pantalla
        draw_tank(50, 10, 28, 44, porcentaje)

        # Mostrar el porcentaje de llenado
        oled.text(str(porcentaje) + '%', 50, 55, 1)

        # Actualizar la pantalla
        oled.show()

        # Esperar un momento antes de leer nuevamente
        time.sleep(0.1)

# Ejecutar la función para mostrar el tanque que se llena y vacía
mostrar_tanque()
