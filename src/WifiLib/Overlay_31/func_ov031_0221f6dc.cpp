#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>
#include <NitroSDK/Memory.h>

enum Enum_ov031_0221f6dc {
    Enum_ov031_0221f6dc_0,
    Enum_ov031_0221f6dc_1,
    Enum_ov031_0221f6dc_2,
    Enum_ov031_0221f6dc_3,
    Enum_ov031_0221f6dc_4,
    Enum_ov031_0221f6dc_5,
    Enum_ov031_0221f6dc_6,
    Enum_ov031_0221f6dc_7,
    Enum_ov031_0221f6dc_8,
    Enum_ov031_0221f6dc_9
};

struct Struct_ov031_0224f670_3 {
    unsigned char unknown_0_[0x2c];
    Enum_ov031_0221f6dc stage;
    unsigned char unknown_30_[0x14];
    unsigned char* address;
    unsigned char* payload;
    unsigned char unknown_4c_[0x14];
    unsigned long unknown_60_;
};

extern Struct_ov031_0224f670_3 data_ov031_0224f670;
extern unsigned char data_ov031_0224fb28[6];
extern unsigned char data_ov031_02245fb0[8];
extern unsigned char data_ov031_0224fb60[32];
extern unsigned char data_ov031_02245fb8[32];
extern "C" int func_ov031_0220cdd4(int, int, int);
extern "C" int func_ov031_0221f630();

// USA: func_ov031_0221f6dc
extern "C" THUMB int func_ov031_0221f6dc(unsigned char* address, unsigned char* payload, int length, unsigned long arg3) {
    int i;
    unsigned long var1;
    var1 = DisableIRQInterrupts();
    data_ov031_0224f670.unknown_60_ = arg3;
    data_ov031_0224f670.address = data_ov031_0224fb28;
    if (address != 0) {
        for (i = 0; i < 6; i++) {
            data_ov031_0224fb28[i] = *address++;
        }
    } else {
        VectorizedMemset(data_ov031_0224fb28, 255, 6);
        data_ov031_0224f670.address = data_ov031_02245fb0;
    }
    data_ov031_0224f670.payload = data_ov031_0224fb60;
    if (payload != 0 && length > 0 && length < 32) {
        for (i = 0; i < length; i++) {
            data_ov031_0224fb60[i] = *payload++;
        }
        for (; i < 32; i++) {
            data_ov031_0224fb60[i] = 0;
        }
    } else {
        VectorizedMemset(data_ov031_0224fb60, 255, 32);
        data_ov031_0224f670.payload = data_ov031_02245fb8;
    }
    if (data_ov031_0224f670.stage == Enum_ov031_0221f6dc_3) {
        if (func_ov031_0220cdd4(
                (int)data_ov031_0224fb28, (int)data_ov031_0224f670.payload,
                data_ov031_0224f670.unknown_60_) == 3) {
            data_ov031_0224f670.stage = Enum_ov031_0221f6dc_6;
            SetIRQInterruptState(var1);
            return 1;
        }
    } else if (func_ov031_0221f630() == 1) {
        data_ov031_0224f670.stage = Enum_ov031_0221f6dc_6;
        SetIRQInterruptState(var1);
        return 1;
    }
    SetIRQInterruptState(var1);
    return 0;
}
