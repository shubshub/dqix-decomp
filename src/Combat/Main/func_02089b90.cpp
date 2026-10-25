#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct_02089b90_2 {
    unsigned short unknown_0_[10];
};

struct Struct_02089b90_3 {
    unsigned char unknown_0_[13];
};

struct Struct_02089b90_4 {
    signed char unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
    short unknown_a_;
    int unknown_c_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    float unknown_14_;
    float unknown_18_;
    struct Struct_02089b90_2 unknown_1c_;
    struct Struct_02089b90_3 unknown_30_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
    unsigned char unknown_3f_;
};

struct Struct_02089b90_5 {
    struct Struct_02089b90_4* unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
};

extern "C" void func_02089edc(struct Struct_02089b90_5* arg0, struct Struct_02089b90_4* arg1);

struct Struct_02108efc_4 {
    struct Struct_02089b90_5* unknown_0_;
    int unknown_4_;
    int unknown_8_;
    SafeAllocator* unknown_c_;
};
extern struct Struct_02108efc_4 data_02108efc;

extern int data_020e8c58[5][5][2];
extern int data_020e8c5c[5][5][2];

struct Struct_02089b90 {
    int unknown_0_;
    void* unknown_4_;
};

int STD_GetStringLength(const char* s);
extern "C" float _fflt(int v);
extern "C" float _fdiv(float arg0, float arg1);

// USA: func_02089b90
extern "C" ARM int func_02089b90(struct Parameter02089b90* p) {
    struct Element02089edc e;
    char* str;
    int i;
    int idx;
    struct Parameter02089b90* base;
    e.b0 = -1;
    e.w4 = 0;
    e.b8 = 0;
    e.ha = 0;
    e.wc = 0;
    e.b10 = 0;
    e.b11 = 0;
    e.b12 = 0;
    e.w14 = 1.0f;
    e.w18 = 1.0f;
    memset(&e.block1c, -1, sizeof(e.block1c));
    memset(&e.block30, -1, sizeof(e.block30));
    e.b3d = 0;
    e.b3e = 0;
    e.b3f = 0;
    if (data_02108efc.pool->field8 == 1) {
        e.b0 = (signed char)((Script::Parameter*)&p[0])->ToInt();
        str = (char*)(void*)((Script::Parameter*)&p[1])->ToString();
        if (str != 0) {
            int len = STD_GetStringLength(str);
            e.w4 = (int)data_02108efc.alloc->Allocate(len + 1);
            memset((void*)e.w4, 0, len + 1);
            memcpy((void*)e.w4, str, len);
        }
        var0.unknown_8_ = (unsigned char)((Script::Parameter*)&arg0[2])->ToInt();
        var0.unknown_a_ = (short)((Script::Parameter*)&arg0[3])->ToInt();
        var0.unknown_c_ = ((Script::Parameter*)&arg0[4])->ToInt();
        var0.unknown_10_ = (unsigned char)((Script::Parameter*)&arg0[5])->ToInt();
        var0.unknown_11_ = (unsigned char)((Script::Parameter*)&arg0[6])->ToInt();
        var0.unknown_12_ = (unsigned char)((Script::Parameter*)&arg0[7])->ToInt();
        var4 = arg0;
        arg0 += 9;
        var3 = ((Script::Parameter*)&var4[8])->ToInt();
        if (var3 >= 0 && var3 <= 5) {
            var0.unknown_14_ = _fdiv(_fflt(data_020e8c58[var0.unknown_8_][var3][0]), 4096.0f);
            var0.unknown_18_ = _fdiv(_fflt(data_020e8c5c[var0.unknown_8_][var3][0]), 4096.0f);
        }
        for (var2 = 0; var2 < 10; var2++) {
            var0.unknown_1c_.unknown_0_[var2] = (short)((Script::Parameter*)arg0)->ToInt();
            arg0++;
        }
        for (var2 = 0; var2 < 13; var2++) {
            var0.unknown_30_.unknown_0_[var2] = (unsigned char)((Script::Parameter*)arg0)->ToInt();
            arg0++;
        }
        var0.unknown_3d_ = (unsigned char)((Script::Parameter*)&arg0[0])->ToInt();
        var0.unknown_3e_ = (unsigned char)((Script::Parameter*)&arg0[1])->ToInt();
        var0.unknown_3f_ = (unsigned char)((Script::Parameter*)&arg0[2])->ToInt();
    }
    func_02089edc(data_02108efc.unknown_0_, &var0);
    return 1;
}
