#include <globaldefs.h>

#include "Resource/TextEncoding.h"

extern KeyValue02032e24 data_020e74ec[];
extern KeyValue02032e24 data_020e74c8[];
extern KeyValue02032e24 data_020e74bc[];
extern KeyValue02032e24 data_020e743c[];
extern KeyValue02032e24 data_020e752c[];

// Main, originally func_020328bc (USA 0x020328bc, EUR 0x020328cc, JPN 0x020323f4)
extern "C" ARM void Text_Utf16ToShiftJis(unsigned char *destination, unsigned short *source, unsigned short count) {
    while (*source != 0 && count-- != 0) {
        unsigned short unicode = *source++;
        unsigned short sjis;
        if (unicode == 0xa5) {
            sjis = 0x5c;
        } else if (unicode == 0x5c) {
            sjis = 0x815f;
        } else if (unicode == 0x203e) {
            sjis = 0x7e;
        } else if (unicode == 0xd || unicode == 0xa) {
            sjis = unicode;
        } else if (unicode >= 0x20 && unicode < 0x7e) {
            sjis = unicode;
        } else if (unicode >= 0xa2 && unicode <= 0xf7) {
            sjis = ShiftJis_LookupUtf16(unicode, data_020e74ec, 0xab);
        } else if (unicode >= 0xff61 && unicode <= 0xff9f) {
            sjis = unicode - 0xfec0;
        } else if (unicode == 0x4edd) {
            sjis = 0x8157;
        } else if (unicode >= 0xff01 && unicode <= 0xffe5) {
            if (unicode >= 0xff10 && unicode <= 0xff19) {
                sjis = unicode - 0x7cc1;
            } else if (unicode >= 0xff21 && unicode <= 0xff3a) {
                sjis = unicode - 0x7cc1;
            } else if (unicode >= 0xff41 && unicode <= 0xff5a) {
                sjis = unicode - 0x7cc0;
            } else {
                sjis = ShiftJis_LookupUtf16(unicode, data_020e74c8, 0x54);
            }
        } else if (unicode >= 0x3000 && unicode <= 0x30fe) {
            if (unicode >= 0x3041 && unicode <= 0x3093) {
                sjis = unicode + 0x525e;
            } else if (unicode >= 0x30a1 && unicode <= 0x30f6) {
                sjis = unicode + 0x529f;
                if (unicode >= 0x30e0) sjis++;
            } else {
                sjis = ShiftJis_LookupUtf16(unicode, data_020e74bc, 0x6c);
            }
        } else if (unicode >= 0x391 && unicode <= 0x3a9) {
            sjis = unicode + 0x800e;
            if (unicode >= 0x3a3) sjis--;
        } else if (unicode >= 0x3b1 && unicode <= 0x3c9) {
            sjis = unicode + 0x800e;
            if (unicode >= 0x3c3) sjis--;
        } else if (unicode == 0x401) {
            sjis = 0x8446;
        } else if (unicode >= 0x410 && unicode <= 0x42f) {
            sjis = unicode + 0x8030;
            if (unicode >= 0x416) sjis++;
        } else if (unicode >= 0x430 && unicode <= 0x44f) {
            sjis = unicode + 0x8040;
            if (unicode >= 0x436) {
                sjis++;
                if (unicode >= 0x43e) sjis++;
            }
        } else if (unicode == 0x451) {
            sjis = 0x8476;
        } else if (unicode >= 0x2500 && unicode <= 0x254b) {
            sjis = ShiftJis_LookupUtf16(unicode, data_020e743c, 0x20);
        } else if ((unicode >= 0x2010 && unicode <= 0x2312) || (unicode >= 0x25a0 && unicode <= 0x266f)) {
            sjis = ShiftJis_LookupUtf16(unicode, data_020e752c, 0xa0);
        } else {
            sjis = 0x8140;
        }
        if (sjis & 0xff00) *destination++ = sjis >> 8;
        *destination++ = sjis;
    }
}
