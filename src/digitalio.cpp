//
// Created by azubi on 29.03.2023.
//

#include "digitalio.h"

namespace self {
    void digitalio::pinMode(uint8_t output) const {
        if (output){
            *DDR |= opin;
        } else {
            *DDR &= ~opin;
        }
    }

    void digitalio::digitalWrite(bool an) const {
        if (an) {
            *PORT |= opin;
        } else {
            *PORT &= ~opin;
        }

    }
        bool digitalio::digitalRead() const {
            return (*PIN & opin) != 0;
    }
}