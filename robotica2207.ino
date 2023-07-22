#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
#include <avr/power.h>
#endif

int nleds = 16;
int pinoLED = 6;
int pinoSom = A5;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(nleds, pinoLED, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin(); // Adicionado ponto-e-vírgula faltando após pixels.begin()
    pixels.setBrightness(0);
    pinMode(pinoSom, INPUT);
}

int brilho = 0;

void loop() {
    int som = analogRead(pinoSom); // Corrigido o nome da variável pinoSom
    brilho = som / 2;

    pixels.setBrightness(brilho);

    for (int i = 0; i < nleds; i++) { // Corrigido o operador de comparação no loop for
        pixels.setPixelColor(i, pixels.Color(0, 0, 255)); // Corrigido o valor do componente azul para 255 (de 225)
    } // end of for
    pixels.show(); // Adicionado pixels.show() para atualizar os LEDs com a nova configuração de cores
} // end of looping
