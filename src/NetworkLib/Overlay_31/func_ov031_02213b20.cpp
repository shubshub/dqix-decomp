#include <globaldefs.h>
#include "NitroSDK/Memory.h"


#if defined(jpn)
#define func_020ca408 func_020cbed4
#endif

struct Struct_ov031_02213b20 { unsigned char field0; unsigned char id; unsigned char level; unsigned char flags; };
struct Struct_ov031_02213b20_2 { unsigned char data[0xc0]; };
struct Struct_ov031_02213b20_3 { unsigned char field0[0x444]; Struct_ov031_02213b20 entries[11]; Struct_ov031_02213b20_2 records[11]; };
extern "C" void func_020ca3ec(unsigned int, void*, unsigned int);
extern "C" void func_020ca408(const void*, void*, unsigned int);

// USA: func_ov031_02213b20
extern "C" ARM void func_ov031_02213b20(int index, Struct_ov031_02213b20_3* state) {
    int previous;
    Struct_ov031_02213b20* entries = state->entries;
    Struct_ov031_02213b20_2* records = state->records;
    Struct_ov031_02213b20_2 var3;
    Struct_ov031_02213b20 var4;
    previous = index - 1;
    if (previous >= 0) {
        Struct_ov031_02213b20* var5 = &entries[previous];
        Struct_ov031_02213b20_2* var6 = &records[previous];
        do {
            if (entries[index].level < entries[previous].level) break;
            func_020ca408(var5, &var4, 4);
            func_020ca408(&entries[index], var5, 4);
            func_020ca408(&var4, &entries[index], 4);
            func_020ca408(var6, &var3, 0xc0);
            func_020ca408(&records[index], var6, 0xc0);
            func_020ca408(&var3, &records[index], 0xc0);
            index = previous;
            --var5;
            --var6;
        } while (--previous >= 0);
    }
    func_020ca3ec(0, &entries[10], 4);
    func_020ca3ec(0, &records[10], 0xc0);
}
