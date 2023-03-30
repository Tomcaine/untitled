#include "digitalio.h"

self::Digitalio led('B', PB3);
self::Digitalio tasta('B', PB0);

bool tasterStatus = false;
bool tasterPrest = false;

void interrupt() {
    if (!tasta.digitalRead()){
        if (!tasterPrest){
            tasterPrest = true;
            tasterStatus = !tasterStatus;
        }
    } else{
        tasterPrest = false;
    }

}

int main() {
    led.pinMode(OUTPUT);
    tasta.pinMode(INPUT);

    while (1) {
        interrupt();
        led.digitalWrite(tasterStatus);
    }
}