#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_02092b34 {
    SafeAllocator allocator;
    char unknown_14_[0x2c - 0x14];
    int field2c;
    short unknown_30_;
    short field32;
    unsigned char field34;
    unsigned char unknown_35_;
    unsigned char unknown_36_;
    unsigned char unknown_37_;
    unsigned char field38;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
};

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
struct Struct_02092aa4;
extern "C" void func_02092aa4(Struct_02092aa4* obj, int param);

// USA: func_02092b34
extern "C" ARM void func_02092b34(struct Struct_02092b34* obj) {
    if (obj->field2c >= 0) {
        int v = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(v))->RemoveTask((int)(obj->field2c));
        obj->field2c = -1;
    }
    void* g = (void*)MessageSystem_GetInstance();
    MessageSystem_Reset((char*)g);
    MessageSystem_Stop((char*)g);
    if (!(obj->unknown_37_ & 8)) {
        FontBankLoader* g2 = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(g2);
        func_02094b34(g2, 0x6f, 0x1388, 1, 1);
    }
    if (obj->allocator.GetSignedAllocator() != 0) {
        obj->allocator.Destroy();
    }
    func_02092aa4((struct Struct_02092aa4*)obj, 0);
}
