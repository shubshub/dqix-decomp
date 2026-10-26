#include <globaldefs.h>

struct Struct_0207f524;
extern "C" void* func_0207f6ac(struct Struct_0207f524* list, int id);
extern "C" void func_0204fa0c(void* obj, short a, short b);

struct Struct_02081574 {
    char pad0[0x6];
    short field6;
    short field8;
    char pad1[0x12 - 0xa];
    unsigned char field12;
    unsigned char field13nibble : 4;
    unsigned char unknown_13_4_ : 4;
    char pad2[0x2a - 0x14];
    unsigned char field2a;
};

#if defined(jpn)
enum { Enum_02081574_42 = 0x2a, Enum_02081574_52 = 0x28 };
#else
enum { Enum_02081574_54 = 0x36, Enum_02081574_52 = 0x34 };
#endif

struct Struct_02081574_2 {
    short* ids;
    char unknown4[0x13 - 4];
    unsigned char count;
};

struct Struct_0207f524 {
    Struct_02081574* entries;
    short count;
};

struct Struct_02081574_3 {
    void* table;
    Struct_0207f524 entries;
    char unknownC[Enum_02081574_52 - 0xc];
    short originX;
    short unknown_36_;
};

typedef void (Struct_02081574_3::*Type_0204cd60)(void*, Struct_02081574*);
extern Type_0204cd60 data_020e8a54[];

// USA: func_02081574
extern "C" ARM void func_02081574(void* obj, void* ctx, void* list) {
    Struct_02081574_3* controller = static_cast<Struct_02081574_3*>(obj);
    Struct_02081574_2* group = static_cast<Struct_02081574_2*>(list);
    struct Struct_02081574* e;
    short id;
    unsigned char i;
    if (list == NULL) {
        return;
    }
    for (i = 0; i < group->count; i++) {
        id = group->ids[i];
        e = (struct Struct_02081574*)func_0207f6ac(&controller->entries, id);
        if (e != NULL) {
            if (controller->unknown_36_ == id) {
                short val = e->field8;
                short diff = (short)(e->field6 - controller->originX);
                switch (e->field13nibble) {
                case 8:
                    val = (short)(val - 1);
                    break;
                case 0xc:
                    val = (short)(val + 1);
                    break;
                }
                func_0204fa0c(ctx, diff, val);
            }
            if (!(e->field2a & 1)) {
                (controller->*data_020e8a54[e->field12])(ctx, e);
            }
        }
    }
}
