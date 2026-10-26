#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" int func_020457e0(char* obj);
extern "C" void* func_ov011_02184a40(void* obj, unsigned int idx);

struct Struct_ov011_02184ae4 {
    char pad[0xc0];
    unsigned short unknown_c0_;
    unsigned short unknown_c2_;
    unsigned short unknown_c4_;
    unsigned short unknown_c6_;
};

#define SUB(o) ((struct Struct_ov011_02184ae4*)((char*)(o) + 0x100))

// USA: func_ov011_02184ae4
extern "C" ARM void func_ov011_02184ae4(void* obj) {
    if (SUB(obj)->unknown_c4_ == 0 && SUB(obj)->unknown_c6_ == 0 && SUB(obj)->unknown_c0_ == 0 && SUB(obj)->unknown_c2_ == 0) return;

    char* g = (char*)MessageSystem_GetInstance();
    if (*(int*)(g + R(0x868, 0x998)) != 0) return;

    int v = func_020457e0(g);
    switch (v) {
    case 0: {
        unsigned short f = SUB(obj)->unknown_c4_;
        if (f != 0) {
            *(unsigned int*)((char*)obj + 0x10c) = f;
            SUB(obj)->unknown_c4_ = 0;
            SUB(obj)->unknown_c6_ = 0;
        }
        if (SUB(obj)->unknown_c0_ == 0) return;
        func_ov011_02184a40(obj, SUB(obj)->unknown_c0_);
        SUB(obj)->unknown_c0_ = 0;
        SUB(obj)->unknown_c2_ = 0;
        return;
    }
    case 1: {
        unsigned short f = SUB(obj)->unknown_c6_;
        if (f != 0) {
            *(unsigned int*)((char*)obj + 0x10c) = f;
            SUB(obj)->unknown_c4_ = 0;
            SUB(obj)->unknown_c6_ = 0;
        }
        if (SUB(obj)->unknown_c2_ == 0) return;
        func_ov011_02184a40(obj, SUB(obj)->unknown_c2_);
        SUB(obj)->unknown_c0_ = 0;
        SUB(obj)->unknown_c2_ = 0;
        return;
    }
    }
}
