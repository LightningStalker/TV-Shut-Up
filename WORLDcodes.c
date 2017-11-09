#include <avr/io.h>
#include <avr/pgmspace.h>
#include "main.h"

// Samsung code_na000 taken from OEM remote by photodiode/oscilloscope
// table of MUTE codes


#ifdef NA_CODES
const uint16_t code_na000Times[] PROGMEM = {
        57, 57,
        57, 170,
        57, 4660,
        454, 454,
};
const struct IrCode code_na000Code PROGMEM = {
        freq_to_timerval(37900),
        68,             // # of pairs
        2,              // # of bits per index
        code_na000Times,
        {
                0xD5,
                0x00,
                0x15,
                0x00,
                0x15,
                0x40,
                0x00,
                0x15,
                0x6D,
                0x50,
                0x01,
                0x50,
                0x01,
                0x54,
                0x00,
                0x01,
                0x56,
        }
};
#endif

/*
#ifdef EU_CODES
#endif
*/
////////////////////////////////////////////////////////////////


const struct IrCode * const NAmuteCodes[] PROGMEM = {
#ifdef NA_CODES
	&code_na000Code,
#ifndef EU_CODES
#endif
#endif
};

const struct IrCode * const EUmuteCodes[] PROGMEM = {
#ifdef EU_CODES
#ifndef NA_CODES
#endif
#endif
};

const uint8_t num_NAcodes = NUM_ELEM(NAmuteCodes);
const uint8_t num_EUcodes = NUM_ELEM(EUmuteCodes);
