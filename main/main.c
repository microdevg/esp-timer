#include <stdio.h>
#include <driver/gpio.h>
#include "esp_timer.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


#define LED_GPIO            2
#define TIMER_NAME          "timer 1"
#define PERIOD_US           (1000000)



bool led_state = false;

void timer_handler(void* args);


void timer_handler(void* args){
    led_state = !led_state;
    gpio_set_level(LED_GPIO,led_state);
}


esp_timer_handle_t t1 ;

esp_timer_create_args_t  timer_args ={
    .name =TIMER_NAME,
    .callback = &timer_handler,
    .dispatch_method =ESP_TIMER_ISR 
};


void app_main(void)
{

    // Configuracion de led 
    gpio_set_direction(LED_GPIO,GPIO_MODE_OUTPUT);
    led_state = false;
   // esp_timer_init();
    esp_timer_create(&timer_args,&t1);
    esp_timer_start_periodic(t1,PERIOD_US);


    while (1)
    {
        vTaskDelay(500/portTICK_PERIOD_MS);
        printf("led:%s\n",(led_state)?"OFF":"ON");
    }
    


}