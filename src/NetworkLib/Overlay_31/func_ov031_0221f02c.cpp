#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_0224f620_3 {
    int field0, field4, field8, fieldc;
    unsigned char* address;
    unsigned char* key;
    int state;
};

extern Struct_ov031_0224f620_3 data_ov031_0224f620;
extern unsigned char data_ov031_0224f648[6];
extern unsigned char data_ov031_0224f650[0x20];
extern unsigned char data_ov031_02245fb0[];
extern unsigned char data_ov031_02245fb8[];

extern "C" int func_ov031_0220cdd4(int, int, int);
extern "C" int func_ov031_0221ef80(void);

// USA: func_ov031_0221f02c
extern "C" THUMB int func_ov031_0221f02c(const unsigned char* address, const unsigned char* key, int arg2,
                                         int field4) {
    int var0 = DisableIRQInterrupts();
    int i;
    data_ov031_0224f620.field4 = field4;
    if (address != NULL) {
        for (i = 0; i < 6; i++) {
            data_ov031_0224f648[i] = *address++;
        }
        data_ov031_0224f620.address = data_ov031_0224f648;
    } else {
        VectorizedMemset(data_ov031_0224f648, 0xff, 6);
        data_ov031_0224f620.address = data_ov031_02245fb0;
    }
    if (key != NULL && arg2 > 0 && arg2 <= 0x20) {
        for (i = 0; i < arg2; i++) {
            data_ov031_0224f650[i] = *key++;
        }
        for (; i < 0x20; i++) {
            data_ov031_0224f650[i] = 0;
        }
        data_ov031_0224f620.key = data_ov031_0224f650;
    } else {
        VectorizedMemset(data_ov031_0224f650, 0xff, 0x20);
        data_ov031_0224f620.key = data_ov031_02245fb8;
    }
    if (data_ov031_0224f620.state == 3) {
        if (func_ov031_0220cdd4((int)data_ov031_0224f620.address, (int)data_ov031_0224f620.key,
                                        data_ov031_0224f620.field4) == 3) {
            data_ov031_0224f620.state = 6;
            SetIRQInterruptState(var0);
            return 1;
        }
    } else if (func_ov031_0221ef80() == 1) {
        data_ov031_0224f620.state = 6;
        SetIRQInterruptState(var0);
        return 1;
    }
    SetIRQInterruptState(var0);
    return 0;
}
