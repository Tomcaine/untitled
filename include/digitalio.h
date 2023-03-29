//
// Created by azubi on 29.03.2023.
//

#ifndef UNTITLED_DIGITALIO_H
#define UNTITLED_DIGITALIO_H

#include <stdint.h>
#include <avr/io.h>
namespace self {
    class digitalio{
        volatile uint8_t *DDR;
        volatile uint8_t *PORT;
        volatile uint8_t *PIN;
        uint8_t opin;

    public:
        digitalio(char port, uint8_t pin){
            switch (port) {
                case 'A':
                    DDR = &DDRA;
                    PORT = &PORTA;
                    PIN = &PINA;
                    break;
                case 'B':
                    DDR = &DDRB;
                    PORT = &PORTB;
                    PIN = &PINB;
                    break;
                case 'C':
                    DDR = &DDRC;
                    PORT = &PORTC;
                    PIN = &PINC;
                    break;
                case 'D':
                    DDR = &DDRD;
                    PORT = &PORTD;
                    PIN = &PIND;
                    break;
            }
            opin = (1 << pin);
        }

        void pinMode(uint8_t output) const;

        void digitalWrite(bool an) const;
        bool digitalRead() const;
    };
}


#endif //UNTITLED_DIGITALIO_H
