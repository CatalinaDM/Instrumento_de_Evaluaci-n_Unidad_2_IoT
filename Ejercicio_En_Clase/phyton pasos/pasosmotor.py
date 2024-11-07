from machine import Pin
from time import sleep

# Pines de control del motor paso a paso
IN1 = Pin(19, Pin.OUT)
IN2 = Pin(18, Pin.OUT)
IN3 = Pin(5, Pin.OUT)
IN4 = Pin(17, Pin.OUT)

# Lista de pines
pins = [IN1, IN2, IN3, IN4]

# Secuencia de pasos para el motor paso a paso
sequence = [
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
]

def mover(direccion, pasos, espera):
    # Asegurarse de que los pasos son positivos
    pasos = abs(pasos)
    
    # Determinar el orden de la secuencia según la dirección
    if direccion == 1:  # Sentido horario
        paso_range = range(pasos)
    else:  # Sentido antihorario
        paso_range = range(pasos - 1, -1, -1)

    # Mover el motor
    for i in paso_range:
        step = sequence[i % len(sequence)]
        for j in range(len(pins)):
            pins[j].value(step[j])
        sleep(espera)

while True:
    mover(1, 1000, 0.002)  # Mover en sentido horario
    sleep(1)
    mover(0, 1000, 0.002)  # Mover en sentido antihorario
    sleep(1)
