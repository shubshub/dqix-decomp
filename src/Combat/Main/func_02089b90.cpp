#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct_02089b90_2 {
    unsigned short v[10];
};

struct Struct_02089b90_3 {
    unsigned char v[13];
};

struct Struct_02089b90_4 {
    signed char b0;
    int w4;
    unsigned char b8;
    short ha;
    int unknown_c_;
    unsigned char b10;
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
    struct Struct_02089b90_4* base;
    short count;
    short capacity;
    short field8;
};

extern "C" void func_02089edc(struct Struct_02089b90_5* arr, struct Struct_02089b90_4* src);

struct Struct_02108efc_4 {
    struct Struct_02089b90_5* pool;
    int unk4;
    int unknown_8_;
    SafeAllocator* alloc;
};
extern struct Struct_02108efc_4 data_02108efc;

extern int data_020e8c58[5][5][2];
extern int data_020e8c5c[5][5][2];

struct Struct_02089b90 {
    int value;
    void* str;
};

extern "C" int STD_GetStringLength(const char* s);
extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);

// USA: func_02089b90
extern "C" ARM int func_02089b90(struct Struct_02089b90* p) {
    struct Struct_02089b90_4 e;
    char* str;
    int i;
    int idx;
    struct Struct_02089b90* base;
    e.b0 = -1;
    e.w4 = 0;
    e.b8 = 0;
    e.ha = 0;
    e.unknown_c_ = 0;
    e.b10 = 0;
    e.unknown_11_ = 0;
    e.unknown_12_ = 0;
    e.unknown_14_ = 1.0f;
    e.unknown_18_ = 1.0f;
    memset(&e.unknown_1c_, -1, sizeof(e.unknown_1c_));
    memset(&e.unknown_30_, -1, sizeof(e.unknown_30_));
    e.unknown_3d_ = 0;
    e.unknown_3e_ = 0;
    e.unknown_3f_ = 0;
    if (data_02108efc.pool->field8 == 1) {
        e.b0 = (signed char)((Script::Parameter*)&p[0])->ToInt();
        str = (char*)(void*)((Script::Parameter*)&p[1])->ToString();
        if (str != 0) {
            int len = STD_GetStringLength(str);
            e.w4 = (int)data_02108efc.alloc->Allocate(len + 1);
            memset((void*)e.w4, 0, len + 1);
            memcpy((void*)e.w4, str, len);
        }
        e.b8 = (unsigned char)((Script::Parameter*)&p[2])->ToInt();
        e.ha = (short)((Script::Parameter*)&p[3])->ToInt();
        e.unknown_c_ = ((Script::Parameter*)&p[4])->ToInt();
        e.b10 = (unsigned char)((Script::Parameter*)&p[5])->ToInt();
        e.unknown_11_ = (unsigned char)((Script::Parameter*)&p[6])->ToInt();
        e.unknown_12_ = (unsigned char)((Script::Parameter*)&p[7])->ToInt();
        base = p;
        p += 9;
        idx = ((Script::Parameter*)&base[8])->ToInt();
        if (idx >= 0 && idx <= 5) {
            e.unknown_14_ = _fdiv(_fflt(data_020e8c58[e.b8][idx][0]), 4096.0f);
            e.unknown_18_ = _fdiv(_fflt(data_020e8c5c[e.b8][idx][0]), 4096.0f);
        }
        for (i = 0; i < 10; i++) {
            e.unknown_1c_.v[i] = (short)((Script::Parameter*)p)->ToInt();
            p++;
        }
        for (i = 0; i < 13; i++) {
            e.unknown_30_.v[i] = (unsigned char)((Script::Parameter*)p)->ToInt();
            p++;
        }
        e.unknown_3d_ = (unsigned char)((Script::Parameter*)&p[0])->ToInt();
        e.unknown_3e_ = (unsigned char)((Script::Parameter*)&p[1])->ToInt();
        e.unknown_3f_ = (unsigned char)((Script::Parameter*)&p[2])->ToInt();
    }
    func_02089edc(data_02108efc.pool, &e);
    return 1;
}
