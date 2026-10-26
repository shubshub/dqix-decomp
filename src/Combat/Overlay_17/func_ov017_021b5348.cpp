#if defined(jpn)
enum { Enum_ov017_021b5348_68 = 0x40, Enum_ov017_021b5348_772 = 0x300, Enum_ov017_021b5348_776 = 0x304 };
#else
enum { Enum_ov017_021b5348_68 = 0x44, Enum_ov017_021b5348_772 = 0x304, Enum_ov017_021b5348_776 = 0x308 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
struct Struct_020534ac_2;
struct Struct_020534ac;
extern "C" void __clear(void* buf, int size);
struct Struct_0209c0c0 {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct Struct_0209c0c0* src, struct Struct_0209c0c0* dst);
struct ZeroWordAndByte0206ee60Struct;
extern "C" void func_0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
struct StreamHeader;
extern "C" void func_0206ee80(void* a, void* b, struct StreamHeader* c, int d, void* e, short f);
extern "C" void func_ov017_021b5648(void* obj);

extern char data_ov017_021d7bdc;

struct Struct_ov017_021b5348_2 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
};

struct Struct_ov017_021b5348 {
    char pad0[Enum_ov017_021b5348_776];
    unsigned char unknown_308_;
};

// USA: func_ov017_021b5348
extern "C" ARM void func_ov017_021b5348(struct Struct_ov017_021b5348_2* obj) {
    void* var0;
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    var0 = obj->sub;
    if (((BackgroundLoader*)((struct Struct_020534ac_2*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct Struct_020534ac*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short var6 = (short)func_0209c0c0((struct Struct_0209c0c0*)(sub + Enum_ov017_021b5348_68), (struct Struct_0209c0c0*)buf);
            func_0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)var0 + Enum_ov017_021b5348_772));
            void* var7 = *(void**)((char*)obj->sub + 0x10);
            func_0206ee80((char*)var0 + Enum_ov017_021b5348_772, var7, (struct StreamHeader*)out1, (short)out2, buf, var6);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    int zero = 0;
    if (((struct Struct_ov017_021b5348*)var0)->unknown_308_ > zero) {
        obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&data_ov017_021d7bdc), (SafeAllocator*)(0));
        obj->field10 = 8;
    } else {
        func_ov017_021b5648(obj);
    }
}
