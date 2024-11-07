## Capturas de Evaluaciones de Fundamentos de Python 1

## Módulo 1 
<img src="https://github.com/user-attachments/assets/3dfffc54-c658-487b-8bde-62cceec5f3f2"/>

## Módulo 2
<img src="https://github.com/user-attachments/assets/c349bcae-fe84-405b-b2e2-8f219137ba44"/>

## Módulo 3
<img src="https://github.com/user-attachments/assets/c3900d5f-84c6-4bf0-93ed-9dd31409139a"/>

## Módulo 4
<img src="https://github.com/user-attachments/assets/794db34a-5197-4843-bcd6-af97452c1a08"/>

## Examen final del Curso
<img src="https://github.com/user-attachments/assets/6f97d3d2-a42f-47d1-a448-294280e29139"/>

## Porcentaje  de evaluaciones finales del Módulo 1 a  Módulo 4 y examen Final del Curso
<img src="https://github.com/user-attachments/assets/165f150f-034a-4593-a072-3afa0f703ecf"/>

## Describe brevemente cómo aplicarías alguno de los conceptos de Python vistos en el curso en tus proyectos de IoT de esta unidad.

 En el ciclo principal (while True), configuraría una rutina de monitoreo con el sensor de distancia, para que esté constantemente verificando si hay un objeto (o persona) cercano. La razón de hacer esto en un bucle infinito es para que el sistema reaccione en tiempo real a la presencia de alguien, esto con ayuda de un sensor de distancia. 

*Lectura del Sensor de Distancia: En cada iteración del bucle, mediría la distancia con el sensor. Dependiendo de la distancia detectada, tomaría decisiones sobre los movimientos de los servos y si el buzzer debe sonar. Por ejemplo, si el objeto se encuentra dentro de un rango específico, activaría los servos para que se muevan a una posición definida, de esta manera utilizo lo aprendido en el mòdulo 3 en la parte de "Condiciones y ejecución condicional"

Control del Buzzer: Para la parte del sonido, crearía una lógica en la cual el buzzer solo se active cuando se cumpla cierta condición de proximidad. Aquí, podría definir una función que controle las notas o melodías a reproducir. La intención es que el buzzer se active de forma intermitente o siguiendo un patrón definido, en lugar de sonar continuamente ya que habra muchos buzzer sonando cuando expongamos

Manejo de los Servos: Configuraría los servos para moverse a diferentes posiciones dependiendo de la distancia, simulando algún tipo de respuesta "inteligente", esto tambièn nos ayudan las condiciones. 

Uso de un Botón para Alternar Funcionalidades: Para el botón, usaría una interrupción que permita activar o desactivar el buzzer, sin interrumpir el funcionamiento principal del sistema. Esto sería útil si quiero tener la opción de controlar manualmente el sonido, permitiendo al usuario activar o desactivar el buzzer sin tener que parar el ciclo de detección de distancia.

Resetear Componentes: Finalmente, al inicio del programa (antes de entrar en el bucle principal), haría una llamada a una función de "reseteo" que asegure que todos los componentes (servos, buzzer) inicien en una posición predeterminada. Esto evitaría que los servos o el buzzer se activen accidentalmente en posiciones o estados no deseados al iniciar el sistema.




