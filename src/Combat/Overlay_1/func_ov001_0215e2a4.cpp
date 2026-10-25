#include <globaldefs.h>
#if defined(jpn)
enum{Enum_ov001_0215e2a4_2104=0x708,Enum_ov001_0215e2a4_2456=0x868};
#else
enum{Enum_ov001_0215e2a4_2104=0x838,Enum_ov001_0215e2a4_2456=0x998};
#endif

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
#if defined(jpn)
extern "C" void func_0204500c(void*, int, int);
#else
extern "C" void func_0204500c(void*, int, int, int);
#endif
int MessageSystem_GetInstance();
struct Table_02153884;
void* FindTableEntry_02153884(struct Table_02153884* t, int key);

extern Struct_ov001_021658d8 data_ov001_021658d8;

struct Struct_ov001_0215e2a4 { char unknown_0_[4]; int unknown_4_; };
struct Struct_ov001_0215e2a4_2 { int unknown_0_; };

// USA: func_ov001_0215e2a4
extern "C" ARM int func_ov001_0215e2a4(Self0215e2a4* self, int mode) {
    char* g = (char*)MessageSystem_GetInstance();
    int type = self->type;
    switch (type) {
    case 0: {
        int var2 = func_ov017_021d60f4(arg0);
        Struct_ov001_0215e2a4* var3 = (Struct_ov001_0215e2a4*)func_ov001_02153884(&data_ov001_021658d8, var2);
        if (var3 == NULL) return 0;
        *(int*)(var0 + 0x1000 + Enum_ov001_0215e2a4_2104) = -1;
        int var4 = 1;
        if (arg1 >= 2) {
            int var5 = func_ov017_021d60f4((char*)arg0 + 0x8);
            if (var5 & 1) var4 = 0;
        }
#if defined(jpn)
        func_0204500c(var0, var3->unknown_4_, var4);
#else
        func_0204500c(var0, var3->unknown_4_, var4, 0xe3);
#endif
        *(int*)(var0 + Enum_ov001_0215e2a4_2456) = 1;
        break;
    }
    case 2: {
        void* var6 = func_ov017_021d612c(arg0);
        *(int*)(var0 + 0x1000 + Enum_ov001_0215e2a4_2104) = -1;
#if defined(jpn)
        func_0204500c(var0, (int)var6, 1);
#else
        func_0204500c(var0, (int)var6, 1, 0xe3);
#endif
        *(int*)(var0 + Enum_ov001_0215e2a4_2456) = 1;
        break;
    }
    }
    return 1;
}
