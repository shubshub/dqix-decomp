#include <globaldefs.h>

struct ResetFieldsStruct {
    int f0;
    short f4;
    short unknown_6_;
    short f8;
    char unknown_a_[2];
    int fc;
    short f10;
    char pad12[2];
    int f14;
    short f18;
};

// Main, originally ResetStructFields_02089db4 (USA 0x02089db4, EUR 0x02089dc4, JPN 0x0208a6b0)
extern "C" ARM void PresetTable_Reset(struct ResetFieldsStruct* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->unknown_6_ = 0;
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = 0;
    s->f18 = 0;
}
