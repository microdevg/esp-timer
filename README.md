# _Temporizador de alta resolución (temporizador ESP)_

## Usando esp_timerAPI
Un único temporizador está representado por una variable ` esp_timer_handle_t timer_name `. Cada temporizador tiene una función de devolución de llamada asociada. 
Para crear un temporizador, llame a : ` esp_timer_create() `.

Para eliminar el temporizador cuando ya no sea necesario, llame a: `esp_timer_delete() `.

El temporizador se puede iniciar en **modo único** o en **modo periódico**.

Para iniciar el temporizador en modo de una sola vez, llame a  `esp_timer_start_once`
, pasando el intervalo de tiempo después del cual se debe llamar a la devolución de llamada. Cuando se llama a la devolución de llamada, se considera que el temporizador está detenido.

Para iniciar el temporizador en modo periódico, llame `esp_timer_start_periodic()`, pasando el período con el que se debe llamar la devolución de llamada. El cronómetro sigue funcionando hasta que esp_timer_stop()se llama.


## Ejemplo de un temporizador de un periodo `PERIOD_US`

La función `void timer_handler(void* args)` es el *handler* del temporizador y se llama cuando ocurre la interrupción. Para este ejemplo, la interrupción cambia el valor de un LED. La interrupción ocurre cada cierto periodo `PERIOD_US`, el cual se define mediante macros al principio del código.
