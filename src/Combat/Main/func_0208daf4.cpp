#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Struct_0201d530 {
    int type;
    union { int i; float f; } value;
};

struct Struct02030b7c {
    int field0;
    void* field4;
};

struct Vector3i;

struct Struct_0208daf4 {
    unsigned char byte0;
    char pad1;
    unsigned short unknown_2_;
    unsigned char raw[0x10];
    unsigned char unknown_14_;
    char pad2[3];
    float unknown_18_;
    int vec[3];
    unsigned short unknown_28_;
    unsigned short unknown_2a_;
};

struct Struct_02108fc8 {
    int status;
    unsigned short* unknown_4_;
    struct Struct_0208daf4* dest;
};

extern struct Struct_02108fc8 data_02108fc8;

// USA: func_0208daf4
extern "C" ARM int func_0208daf4(struct Struct_0201d530* obj) {
    int a, b, c, e;
    void* d;
    unsigned short var5;
    struct Struct_0201d530* next;

    if (data_02108fc8.status == 1) {
        return 0;
    }

    a = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 0)))->ToInt();
    b = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 1)))->ToInt();
    c = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 2)))->ToInt();

    var5 = *data_02108fc8.unknown_4_;
    if (b != var5 && c != var5) {
        return 0;
    }

    data_02108fc8.dest->byte0 = (unsigned char)a;
    data_02108fc8.dest->unknown_2_ = (unsigned short)b;
    data_02108fc8.dest->unknown_2a_ = (unsigned short)c;

    d = (void*)((Script::Parameter*)((struct Struct02030b7c*)(obj + 3)))->ToString();
    memcpy(data_02108fc8.dest->raw, d, 0x10);
    data_02108fc8.dest->raw[0xf] = 0;

    e = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 4)))->ToInt();
    data_02108fc8.dest->unknown_14_ = (unsigned char)e;

    data_02108fc8.dest->unknown_18_ = ((Script::Parameter*)((struct Struct_0201d530*)(obj + 5)))->ToFloat();

    next = (Struct_0201d530*)((Script::Parameter*)(obj + 6))->ToVec3fix((Vector3i*)data_02108fc8.dest->vec);
    data_02108fc8.dest->unknown_28_ = (unsigned short)(int)(4096.0f * ((Script::Parameter*)next)->ToFloat());

    data_02108fc8.status = 1;
    return 1;
}
