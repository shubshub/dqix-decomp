#include <globaldefs.h>
#include "NitroSDK/Timing.h"

struct Struct_ov031_0221e964_3 { unsigned char bytes[0xc0]; };
struct Struct_ov031_0221e964 { unsigned char bytes[0x54]; };
struct Struct_ov031_0221e964_2 { int count; Struct_ov031_0221e964 entries[1]; };
struct Struct_ov031_0224f4c0_3 {
    void* (*unknown_0_)(unsigned int);
    unsigned char pad4[8];
    void (*unknown_c_)(void*);
};
struct Struct_ov031_0224f4e0;
extern Struct_ov031_0224f4c0_3 data_ov031_0224f4c0;
extern Struct_ov031_0224f4e0 data_ov031_0224f4e0;
extern "C" int func_ov031_0221f02c(int, int, int, unsigned int);
extern "C" ARM int func_020c7ea0(Struct_ov031_0224f4e0*, int*, int);
extern "C" int func_ov031_0221efe8(Struct_ov031_0221e964_3*, int);
extern "C" int func_ov031_0221f11c();
extern "C" void func_ov031_0221e6e8(Struct_ov031_0221e964_3*, Struct_ov031_0221e964*);
extern "C" void func_ov031_0221e7bc(ProcessorContext**);

// USA: func_ov031_0221e964
extern "C" THUMB int func_ov031_0221e964(Struct_ov031_0221e964_2** output) {
    int result = -1;
    int running = 1;
    int var2 = 0;
    int count = 0;
    int var4 = 0;
    if (!data_ov031_0224f4c0.unknown_0_ || !data_ov031_0224f4c0.unknown_c_) return -1;
    Struct_ov031_0221e964_3* records = (Struct_ov031_0221e964_3*)data_ov031_0224f4c0.unknown_0_(0x3000);
    if (!records) return -1;
    void* allocation = records;
    if (!func_ov031_0221f02c(0, 0, 0, 0x30bffe)) goto release;
    {
        Alarm var7;
        int event;
        ZeroInitializeAlarm(&var7);
        SetTimeout(&var7, 0x003fec42ULL, func_ov031_0221e7bc, (ProcessorContext**)19);
        do {
            func_020c7ea0(&data_ov031_0224f4e0, &event, 1);
            switch (event) {
            case 19:
                if (!var2) {
                    if (var4) count = func_ov031_0221efe8(records, 64);
                    if (!func_ov031_0221f11c()) goto cancel;
                    var2 = 1;
                }
                break;
            case 5:
                if (!var2) {
                    if (var4 < 8) ++var4;
                    else {
                        count = func_ov031_0221efe8(records, 64);
                        if (!func_ov031_0221f11c()) goto cancel;
                        var2 = 1;
                    }
                }
                break;
            case 10:
                running = 0;
                result = 0;
                break;
            case 4:
            case 8:
            case 18:
                break;
            case 0: case 1: case 2: case 3:
            case 6: case 7: case 9:
            case 11: case 12: case 13: case 14: case 15: case 16: case 17:
            default:
                goto cancel;
            }
        } while (running);
        {
            void* var9;
            if (count) {
                var9 = data_ov031_0224f4c0.unknown_0_((count - 1) * 0x54 + 0x58);
                if (!var9) goto cancel;
            } else {
                var9 = data_ov031_0224f4c0.unknown_0_(0x58);
                if (!var9) goto cancel;
            }
            Struct_ov031_0221e964_2* var10 = (Struct_ov031_0221e964_2*)var9;
            *output = var10;
            var10->count = count;
            int i = 0;
            if (count > 0) {
            Struct_ov031_0221e964* entry = var10->entries;
            do {
                func_ov031_0221e6e8(records, entry);
                ++i;
                ++records;
                ++entry;
            } while (i < count);
            }
        }
cancel:
        CancelAlarm(&var7);
        while (func_020c7ea0(&data_ov031_0224f4e0, &event, 0) == 1) {}
    }
release:
    data_ov031_0224f4c0.unknown_c_(allocation);
    return result;
}
