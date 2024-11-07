#  Ejercicios en Clase

## Control de leds con botones

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | Se utilizaron 2 leds y 2 botones, cada uno de los botones debe ser capaz de encender y apagar un led es decir cada botòn enciende solo a uno de los leds | 
| Python | [`Ver code`]() | [Ver video](https://drive.google.com/file/d/1AKTxPRHEyOziL90IRRrko4tk-SXfV9qr/view?usp=sharing)|


## Movimiento del servo con algun sensor

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion |1er ejercicio: ** El servo debe ser capaz de moverse a ciertos grados al precionar el botoòn que lo controlara  y cuando se vuelva a precionar debe volver a los 0 grados**                                                --2do ejercicio--: **El servo podra moverse a ciertos grados dependiendo del valor sensor del potenciometro **|
| Python | [` Ver code `](Ejercicio_Practico_Integral) | [Ver video](https://drive.google.com/file/d/1AIpmov7TidhN_Jh2-3RsWD_d2wdY3C_S/view?usp=sharing)|
| Arduino| [`Ver code`](ServoConPotenciometro) | [Ver video](https://drive.google.com/file/d/1AC5oKPVdWhzdlUV9nN_HKUjl8zHWlZgh/view?usp=sharing)|

## Semaforo de distancia

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion |Se tendran 3 focos de color  verde,amarillo y rojo y estos se deberàn encender dependiendo las distancias que en el codigo se agregen de rangos para cada uno de los focos se tienen rangos  de distancias distintos y en funcion de esto SOLO se podra encender uno de los focos |
| Python | [`Ver code `](hcsr04SensorDistancia.py) | [Ver video](https://drive.google.com/file/d/1A-hwNdDIS8xq5FPx7vxxOeiEQwwOWt3x/view?usp=sharing)|
| Arduino|  [`Ver code `]() | [Ver video](https://drive.google.com/file/d/19xIHb_7R4w64S_Udkw9vWsZkU9otD0uL/view?usp=sharing)|

## Buzzer con Melodias 

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | En el codigo se agregan ciertas melodias en un array, que se debe configurar su frencuencia par que 
el buzzer pueda transmitirlas con cierta frecuencia, en este caso tenemos canciones navideñas y de guardianes de la galaxia|
| Python | [`Ver code `](Buzzer_Micropython.py) | [Ver video](https://drive.google.com/file/d/1AAjmoooLvhQjshcwhqn8KzXJjW6kUWCy/view?usp=sharing)|
| Arduino|  [`Ver code `](Buzzer.ino) | [Ver video](https://drive.google.com/file/d/19eB0oSnzDcUnYIwruzZWmqiU3ExbXNHM/view?usp=sharing)|

## Matriz con visualizacion de mensaje personalizado

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | La  matriz debera contener un mensaje personalizado respecto a quien lo hizo en este caso yo a mi dos codigos les agregue mi nombre, por lo que debe deslizarse por la pantalla y cuando se acabe debe de limpiarce para volver a empezar |
| Python | [`Ver code `](matriz.py) | [Ver video](https://drive.google.com/file/d/1ABi2V76lF6xqJLvDicl5LZqIRUBEzkhJ/view?usp=drivesdk)|
| Arduino|  [`Ver code `](matriz.ino) | [Ver video](https://drive.google.com/file/d/19lVUj1TPdT2zAMikiiRcs-GJP4iTOJXd/view?usp=sharing)|


## Pantalla oled nivel de potencimetro llenado del bote 

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | En la pantalla oled se mostrara un dibujo de un bote y con ayuda de un potenciometro al momento de girarlo contiene distintos valores y estos deben ser mostrados en la pantalla oled en porcentaje y respecto a ese porcentaje el bote debe de estar llenado a ese porciento |

| Python | [`Ver code `](potenciometro.py) | [Ver video](https://drive.google.com/file/d/19M_GMAKjaOJvWSm0gus6AmKF994hN5I0/view?usp=sharing)|
| Arduino|  [`Ver code `](potenciometro.ino) | [Ver video](https://drive.google.com/file/d/19ODh2S0iyCASbNi6iuqC7BlTdsaNp_qK/view?usp=sharing)|

## Matriz con valores del potencimetro en porcentajes 

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | La matriz deberá mostrar el valor en porcentaje según el ajuste del potenciómetro, reflejando en tiempo real el valor actual del potenciometro a la hora de moverlo |
| Python | [`Ver code `](Matriz_potenciometro.py) | [Ver video](https://drive.google.com/file/d/19IbJ2fNJyRJQ_e43y6gAiABWwwA2t70m/view?usp=sharing)|


## Matriz con valores de distancia 

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | La matriz deberá mostrar los valores de distancia en centímetros, actualizándose en tiempo real según la lectura del sensor de distancia al detectar algùn objeto o persona a una cierta distancia |
| Python | [`Ver code `](matrizYDistancia.py) | [Ver video](https://drive.google.com/file/d/1A2X1m6fNmgKGmHBHlwH-izsxdcJRRhRC/view?usp=sharing)|


## Motor de pasos 

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | El motor de pasos deberá realizar un movimiento de ida y vuelta, completando dos pasos para completar el ciclo, la primera vuelta es 1 paso que son los 180º y se concidera en sentido de las manecillas del reloj, a vuelta de regreso es el 2 paso y son contrarias a las manecillas del reloj|
| Python | [`Ver code `](motor_a_pasos.py) | [Ver video](https://drive.google.com/file/d/19gPhE0jWzs5VsajVb1TH5FP9yiNPhnOo/view?usp=sharing)|
| Arduino|  [`Ver code `](arduinopasoxs.ino) | [Ver video](https://drive.google.com/file/d/1AA_ucY5azf48yMAGxw_wZ6VbWvhufjnP/view?usp=sharing)|

## Joystick

|Opciones| Codigo | Video |
|--|--|--|
| Descripcion | El joystick deberá detectar movimientos hacia arriba, abajo, izquierda y derecha, y al presionar su botón, se encenderá un LED RGB con un color diferente según la dirección seleccionada. |
| Python | [`Ver code `](JocRgb.py) | [Ver video](https://drive.google.com/file/d/19z1mipobkapanD4E2KKAkyuqURhWqQ6l/view?usp=sharing)|
| Arduino|  [`Ver code `](j.ino) | [Ver video](https://drive.google.com/file/d/19fuuekeMPOPNKy-g3c4TM522P0tMpTvM/view?usp=sharing)|


