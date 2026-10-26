#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0220783c {
    void* unknown_0_;
    short unknown_4_;
    unsigned short unknown_6_;
};
extern "C" int func_ov031_02206fa4(void*);

// USA: func_ov031_0220783c
extern "C" ARM int func_ov031_0220783c(Struct_ov031_0220783c* entries, unsigned int count, long long arg2) {
    bool var0 = arg2 != -1;
    Struct_ov031_0220783c* entry;
    unsigned int i;
    int var3;
    do {
        entry = entries;
        i = var3 = 0;
        if (i < count) {
            do {
                int var4 = entry->unknown_4_ | 0xe0;
                int events = var4 & func_ov031_02206fa4(entry->unknown_0_);
                entry->unknown_6_ = events;
                i++;
                entry++;
                if (events) var3++;
            } while (i < count);
        }
        if (var3 > 0) break;
        if (var0 && arg2 <= 0) break;
        SleepCurrentContext(1);
        arg2 -= 0x20b;
    } while (true);
    return var3;
}
