#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201c1c8 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Struct_0201c3a4 {
    int unknown_0_;
    void* unknown_4_;
};

int STD_GetStringLength(const char* s);

struct Struct_ov003_0215e498 {
    short unknown_0_;
    short unknown_2_;
    int unknown_4_;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
};
extern "C" void func_ov003_0215e498(struct Struct_ov003_0215e498* arg0);

struct Struct_ov003_0215e510 {
    short unknown_0_;
    short unknown_2_;
    int unknown_4_;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
};
struct Struct_ov003_0215e790;
extern "C" void func_ov003_0215e790(struct Struct_ov003_0215e790* arg0, struct Struct_ov003_0215e510* arg1);

struct Struct_ov003_0215e510_2 {
    struct Struct_0201c1c8 unknown_0_;
    struct Struct_0201c1c8 unknown_8_;
    struct Struct_0201c1c8 unknown_10_;
    struct Struct_0201c3a4 unknown_18_;
    struct Struct_0201c3a4 unknown_20_;
    struct Struct_0201c1c8 unknown_28_;
    struct Struct_0201c1c8 unknown_30_;
    struct Struct_0201c1c8 unknown_38_;
};

struct Struct_ov003_02180cb8 {
    void* unknown_0_;
    struct Struct_ov003_0215e790* unknown_4_;
};
extern struct Globals02180cb8 KeyboardLayout_scriptContext;

// USA: func_ov003_0215e510
extern "C" ARM int func_ov003_0215e510(struct Struct_ov003_0215e510_2* arg0) {
    struct Struct_ov003_0215e510 var0;
    func_ov003_0215e498((struct Struct_ov003_0215e498*)&var0);

    var0.unknown_10_ = (short)((Script::Parameter*)&arg0->unknown_0_)->ToInt();
    var0.unknown_0_ = (short)((Script::Parameter*)&arg0->unknown_8_)->ToInt();
    var0.unknown_2_ = (short)((Script::Parameter*)&arg0->unknown_10_)->ToInt();

    char* text1 = (char*)(void*)((Script::Parameter*)&obj->v3)->ToString();
    if (text1 != NULL) {
        int len1 = STD_GetStringLength(text1);
        if (len1 != 0) {
            char* buf1 = (char*)((SafeAllocator*)KeyboardLayout_scriptContext.allocator)->Allocate(len1 + 1);
            local.f4 = (int)buf1;
            sprintf(buf1, text1);
        }
    }

    char* text2 = (char*)(void*)((Script::Parameter*)&obj->v4)->ToString();
    if (text2 != NULL) {
        int len2 = STD_GetStringLength(text2);
        if (len2 != 0) {
            char* buf2 = (char*)((SafeAllocator*)KeyboardLayout_scriptContext.allocator)->Allocate(len2 + 1);
            local.f8 = (int)buf2;
            sprintf(buf2, text2);
        }
    }

    var0.unknown_c_ = (unsigned char)((Script::Parameter*)&arg0->unknown_28_)->ToInt();
    var0.unknown_d_ = (unsigned char)((Script::Parameter*)&arg0->unknown_30_)->ToInt();
    var0.unknown_e_ = (unsigned char)((Script::Parameter*)&arg0->unknown_38_)->ToInt();

    AppendEntryToArray_0215e790(KeyboardLayout_scriptContext.target, &local);
    return 1;
}
