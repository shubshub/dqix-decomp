#pragma once

struct Struct_020e743c {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
};

unsigned short ShiftJis_LookupUtf16(unsigned short key, KeyValue02032e24 *entries, int count);
extern "C" void Text_Utf16ToShiftJis(unsigned char *destination, unsigned short *source, unsigned short count);
