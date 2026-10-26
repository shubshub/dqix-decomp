#include <globaldefs.h>

void InitSlotSystem020cf020(void);
int RTC_GetTime(int a);

extern unsigned int data_020f2304;

// USA: func_020d4dd4
ARM unsigned short IncrementSlotIndex020d4dd4(void) {
    unsigned int buf[3];
    if (data_020f2304 == 0x10000) {
        InitSlotSystem020cf020();
        if (RTC_GetTime((int)buf) == 0) {
            data_020f2304 = (unsigned short)(buf[2] + (buf[1] << 8));
        }
    }
    return data_020f2304 = (unsigned short)(data_020f2304 + 1);
}
