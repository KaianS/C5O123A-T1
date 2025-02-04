#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_YELLOW 11
#define LED_GREEN 12

volatile uint8_t state = 0;

bool repeating_timer_callback(repeating_timer_t *rt) {
    gpio_put(LED_RED, state == 0);    // Vermelho no estado 0
    gpio_put(LED_YELLOW, state == 1); // Amarelo no estado 1
    gpio_put(LED_GREEN, state == 2);  // Verde no estado 2
    state = (state + 1) % 3;          // Ciclo 0→1→2→0...
    return true;
}

int main() {
    stdio_init_all();
    
    // Configuração dos pinos
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Timer periódico de 3 segundos
    repeating_timer_t timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while(true) {
        printf("Estado atual: %d\n", state); // Monitoramento via serial
        sleep_ms(1000);
    }
}
