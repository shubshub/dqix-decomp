#pragma once

struct KeyValue02032e24 {
    unsigned short value;
    unsigned short key;
};

extern "C" unsigned short ShiftJis_LookupUtf16(unsigned short key, KeyValue02032e24 *entries, int count);
extern "C" void Text_Utf16ToShiftJis(unsigned char *destination, unsigned short *source, unsigned short count);
