# Temporizador Periódico

Este projeto implementa um semáforo utilizando um temporizador periódico de 3 segundos, utilizando a função `add_repeating_timer_ms()` do Pico SDK.

## 🚀 Requisitos

- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores de 330 Ω
- Ferramenta Educacional BitDogLab
- Simulador Wokwi

## 📌 Funcionalidades

- O semáforo inicia na cor vermelha, muda para amarelo e depois para verde.
- A troca de cores ocorre a cada 3 segundos.
- A função de call-back do temporizador gerencia a mudança de estado dos LEDs.
- O loop principal imprime mensagens a cada 1 segundo via porta serial.
- Teste adicional com LED RGB nos GPIOs 11, 12 e 13 via BitDogLab.

## 🔧 Configuração e Execução

1. Instale o **Pico SDK** e configure o ambiente no **VS Code**.
2. Clone este repositório:
   ```sh
   git clone https://github.com/KaianS/C5O123A-T1.git
   cd C5O123A-T1
3. Compile e execute o projeto
