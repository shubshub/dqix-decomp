#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_0201d530;
extern "C" void func_ov000_02169b78(void* p);

struct Struct_ov000_02184264_6 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_6 data_ov000_02184264;

// USA: func_ov000_0216a9dc
extern "C" ARM int func_ov000_0216a9dc(char* obj, int count) {
    char* p = (char*)data_ov000_02184264.alloc->Allocate(0xc);
    *(int*)(p + 0x0) = 0;
    *(int*)(p + 0x4) = 0;
    *(int*)(p + 0x0) = 0x1a;

    int idx = 1;
    int tag = *(int*)obj;
    if (tag == 2) {
        *(unsigned char*)(p + 0x8) = 7;
        *(unsigned short*)(p + 0xa) = 0x1000;
    } else if (tag == 1) {
        int val = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
        *(unsigned char*)(p + 0x8) = (unsigned char)val;
        *(unsigned short*)(p + 0xa) = 0x1000;
        obj += 8;
        idx = 2;
    }

    if (idx <= count) {
        int var4 = *(int*)obj;
        if (var4 == 2) {
            float f = ((Script::Parameter*)((struct Struct_0201d530*)obj))->ToFloat();
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)(f * 4096.0f);
        } else if (var4 == 1) {
            int v = ((Script::Parameter*)((struct Variant02030b0c*)obj))->ToInt();
            float var7 = (float)v;
            *(unsigned short*)(p + 0xa) = (unsigned short)(int)((var7 / 1000.0f) * 4096.0f);
        }
    }

    func_ov000_02169b78(p);
    return 1;
}
