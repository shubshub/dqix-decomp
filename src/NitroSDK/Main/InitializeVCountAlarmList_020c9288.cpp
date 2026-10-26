#include <globaldefs.h>

struct Struct_02111654 {
    unsigned short initialized;
    unsigned char pad2[2];
    int f4;
    int f8;
    int fc;
    int f10;
};

extern Struct_02111654 data_02111654;
extern unsigned int DisableSpecificInterrupts(unsigned int mask);

// Main, originally InitModule020c9288 (USA 0x020c9288, EUR 0x020c9298, JPN 0x020cad54)
extern "C" ARM void InitializeVCountAlarmList() {
    if (data_02111654.initialized != 0) {
        return;
    }
    data_02111654.initialized = 1;
    data_02111654.fc = 0;
    data_02111654.f10 = 0;
    DisableSpecificInterrupts(4);
    data_02111654.f8 = 0;
    data_02111654.f4 = 0;
}
