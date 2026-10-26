#include <globaldefs.h>

#include "Combat/Main/CandidateFilter.h"
#include <std_library_functions.h>

struct Struct_0209e1cc {
    unsigned short unknown0 : 2;
    unsigned short kind : 4;
    unsigned short unknown6 : 10;
};

struct Struct_0209e1cc_2 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown4 : 4;
};

struct Struct_0209e1cc_3 {
    unsigned char bytes[4];
};

struct Struct_0209e1cc_4 {
    unsigned int unknown_0_;
    unsigned char unknown_4_[4];
    unsigned int unknown_8_;
    unsigned char unknown_c_[12];
    Struct_0209e1cc unknown_18_;
    Struct_0209e1cc unknown_1a_;
    Struct_0209e1cc_2 unknown_1c_;
    Struct_0209e1cc_2 unknown_1d_;
    unsigned char unknown_1e_[10];
    Struct_0209e1cc_3 unknown_28_;
    Struct_0209e1cc_3 unknown_2c_;
};

// USA: func_0209e1cc
extern "C" ARM int func_0209e1cc(void *receiver, void *record, int mode, int parameter) {
    unsigned int mask;
    Struct_0209e1cc_4 *candidate;
    unsigned int kind;
    unsigned int var3;
    Struct_0209e1cc_3 payload;
    unsigned int flags;

    mask      = static_cast<unsigned int>(parameter);
    candidate = static_cast<Struct_0209e1cc_4 *>(record);

    if (mode == 0) {
        kind           = candidate->unknown_18_.kind;
        flags          = candidate->unknown_0_;
        var3 = candidate->unknown_1c_.unknown_0_0_;
        memcpy(&payload, &candidate->unknown_28_, sizeof(payload));
    } else {
        kind           = candidate->unknown_1a_.kind;
        var3 = candidate->unknown_1d_.unknown_0_0_;
        flags          = candidate->unknown_8_;
        memcpy(&payload, &candidate->unknown_2c_, sizeof(payload));
    }

    if ((mask & 0x1) && (flags & 0x80000) && kind == 2) return 1;
    if ((mask & 0x2) && (flags & 0x80000) && kind == 3) return 1;
    if ((mask & 0x4) && (flags & 0x80000) && kind == 5) return 1;
    if ((mask & 0x8) && (flags & 0x80000) && kind == 4) return 1;
    if ((mask & 0x10) && (flags & 0x80000) && kind == 7) return 1;
    if ((mask & 0x20) && (flags & 0x80000) && kind == 6) return 1;
    if ((mask & 0x40) && (flags & 0x80000) && kind == 8) return 1;
    if ((mask & 0x80) && (flags & 0x80000) && kind == 10) return 1;
    if ((mask & 0x100) && (flags & 0x80000) && kind == 9) return 1;
    if ((mask & 0x200) && (flags & 0x80000) && kind == 1) return 1;
    if ((mask & 0x400) && var3 == 1) return 1;
    if ((mask & 0x800) && var3 == 2) return 1;
    if ((mask & 0x1000) && var3 == 4) return 1;
    if ((mask & 0x2000) && var3 == 5) return 1;
    if ((mask & 0x4000) && var3 == 6) return 1;
    if ((mask & 0x8000) && var3 == 7) return 1;
    if ((mask & 0x10000) && var3 == 8) return 1;
    return 0;
}
