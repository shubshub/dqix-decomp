#include <globaldefs.h>
#include "Graphics/Model3D.h"

struct Struct_ov025_021ef988_14 {
#if defined(jpn)
    char pad0[4];
#else
    char pad0[0xc];
#endif
    char* slots;
};

struct Struct_ov025_021e509c {
    char pad0[8];
    unsigned char unknown_8_;
    unsigned char slotB;
    char padA[2];
    const char* unknown_c_;
};

struct Struct_ov025_021e509c_2 {
    char pad0[8];
    Model3D* model;
    char unknown_c_[0xac - 0xc];
    int unknown_ac_;
    char unknown_b0_[2];
    short unknown_b2_;
    short boneIndex;
};

extern "C" void* func_02057924(void);
extern "C" Struct_ov025_021e509c_2* func_02058658(void* obj, int id);
extern "C" int* func_ov025_021e8cf0(char* base, int idx);
extern Struct_ov025_021ef988_14 data_ov025_021ef988;

// USA: func_ov025_021e509c
extern "C" ARM int func_ov025_021e509c(Struct_ov025_021e509c* p) {
    void* obj = func_02057924();
    int* var1 = func_ov025_021e8cf0(data_ov025_021ef988.slots, p->unknown_8_);
    int* slotB = func_ov025_021e8cf0(data_ov025_021ef988.slots, p->slotB);
    if (var1 == 0 || slotB == 0) {
        return 1;
    }
    int var3 = *slotB;
    Struct_ov025_021e509c_2* var4 = func_02058658(obj, *var1);
    Struct_ov025_021e509c_2* var5 = func_02058658(obj, var3);
    if (var4 == 0 || var5 == 0) {
        return 1;
    }
    if (var5->unknown_ac_ != 0) {
        return 1;
    }
    var4->unknown_b2_ = var3;
    if (p->unknown_c_ != 0 && var5->model != 0) {
        var4->boneIndex = var5->model->GetBoneIndex(p->unknown_c_);
    }
    return 1;
}
