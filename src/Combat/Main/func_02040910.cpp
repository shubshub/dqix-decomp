#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/GameResources.h"
#if defined(jpn)
enum { kRegionalFieldOffset = 0x2e4 };
#else
enum { kRegionalFieldOffset = 0x2f0 };
#endif

struct Struct_0203de84_4 {
    char pad[0x10];
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
};

struct Struct_02040910 {
    char pad[0xd4];
    unsigned char bit0 : 1;
};

extern "C" void func_ov017_0218eafc(int arg0, int arg1);
extern "C" int func_0203cd64(char* obj, int arg1);

// USA: func_02040910
extern "C" ARM int func_02040910(struct Struct_0203de84_4* obj, int arg1) {
    if (obj->field10) {
        ((Object3D*)obj->field10)->Draw(1);
    }
    if (obj->field14) {
        return func_0203cd64((char*)obj->field14, arg1);
    }
    if (obj->field18) {
        struct Struct_02040910* p = (struct Struct_02040910*)obj->field18;
        if (p->bit0) {
            return 1;
        }
        return ((Object3D*)p)->Draw(1);
    }
    if (obj->field1c) {
        void* p = obj->field1c;
        if (*(unsigned char*)((char*)p + kRegionalFieldOffset) != 0) {
            return 1;
        }
        signed short val = *(signed short*)((char*)p + 4);
        int r = (int)GetGameResources();
        func_ov017_0218eafc(r, val);
        return 1;
    }
    return 0;
}
