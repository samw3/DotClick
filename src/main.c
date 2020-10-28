#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint8_t dot_click(uint16_t dot, uint8_t input)
{
    static uint16_t pong = 231;
    static int8_t xDir = 1;
    static int8_t yDir = 1;
    static bool blip = false;

    if (dot == 0) {
        blip = false;
        if ((pong & 0x7f) == 0x7f) {xDir = -1;blip = true;}
        if ((pong & 0x7f) == 0) {xDir = 1;blip = true;}
        if (pong < 128) {yDir = 1;blip = true;}
        if (pong > 9088) {yDir = -1;blip = true;}
        pong += xDir + yDir * 128;
    }
    return (dot==pong?15:(((dot>>10)+2)&0xf)) << 4 | (blip?(((dot>>9)&1)<<3):8);
}
