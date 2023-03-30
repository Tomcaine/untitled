//
// Created by azubi on 29.03.2023.
//

#ifndef UNTITLED_DIGITALIO_H
#define UNTITLED_DIGITALIO_H

#define OUTPUT 1
#define INPUT 0

#include <stdint.h>
#include <avr/io.h>
namespace self {
    class Digitalio{
    public:
        Digitalio(char port, uint8_t pin);

        void pinMode(uint8_t output) const;

        void digitalWrite(bool an) const;
        bool digitalRead() const;


    private:
        volatile uint8_t *_DDR;
        volatile uint8_t *_PORT;
        volatile uint8_t *_PIN;
        uint8_t _pin;
    };
}


#endif //UNTITLED_DIGITALIO_H
