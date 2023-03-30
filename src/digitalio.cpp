//
// Created by azubi on 29.03.2023.
//

#include "digitalio.h"

namespace self {

    Digitalio::Digitalio(char port, uint8_t pin) {
        switch (port) {
            case 'A':
                _DDR = &DDRA;
                _PORT = &PORTA;
                _PIN = &PINA;
                break;
            case 'B':
                _DDR = &DDRB;
                _PORT = &PORTB;
                _PIN = &PINB;
                break;
            case 'C':
                _DDR = &DDRC;
                _PORT = &PORTC;
                _PIN = &PINC;
                break;
            case 'D':
                _DDR = &DDRD;
                _PORT = &PORTD;
                _PIN = &PIND;
                break;
        }
        _pin = (1 << pin);
    }

    void Digitalio::pinMode(uint8_t output) const {
        if (output){
            *_DDR |= _pin;
        } else {
            *_DDR &= ~_pin;
        }
    }

    void Digitalio::digitalWrite(bool an) const {
        if (an) {
            *_PORT |= _pin;
        } else {
            *_PORT &= ~_pin;
        }

    }
        bool Digitalio::digitalRead() const {
            return (*_PIN & _pin) != 0;
    }
}