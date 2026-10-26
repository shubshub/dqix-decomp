#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    int value;
};

struct Struct_02071cc8;
struct Struct_02071874;
extern "C" void func_02071cc8(struct Struct_02071cc8*, struct Struct_02071874*);

struct Struct_02071874_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 8;
    unsigned int unknown_3_4_ : 4;
};

struct Struct_02071874_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 1;
    unsigned int unknown_2_5_ : 1;
    unsigned int unknown_2_6_ : 1;
    unsigned int unknown_2_7_ : 8;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_02071874_4 {
    unsigned short n0 : 4;
    unsigned short n1 : 4;
    unsigned short n2 : 4;
    unsigned short n3 : 4;
};

struct Struct_02071874_5 {
    short f0;
    short f2;
    short f4;
    short unknown_6_;
    short f8;
    Struct_02071874_4 fa;
    Struct_02071874_2 fc;
    Struct_02071874_3 f10;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    int f1c;
};
extern "C" void func_02071b38(struct Struct_02071874_5* s);

struct Struct_02108d98 {
    unsigned short field0;
    unsigned short field2;
    short* field4;
    int field8;
    struct Struct_02071cc8* fieldC;
};
extern struct Struct_02108d98 data_02108d98;

// USA: func_02071874
extern "C" ARM int func_02071874(struct Variant02030b0c* cur) {
    struct Struct_02071874_5 entry;
    short id = (short)((Script::Parameter*)(cur++))->ToInt();

    if (data_02108d98.field4 != 0) {
        int found = 0;
        unsigned short i;
        for (i = 0; i < data_02108d98.field0; i++) {
            if (data_02108d98.field4[i] == id) {
                found = 1;
                break;
            }
        }
        if (!found) {
            return 1;
        }
    }

    func_02071b38(&entry);
    entry.f0 = id;
    entry.f2 = (short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.f4 = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.f4 = 0;
        cur++;
    }
    entry.fa.n0 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.unknown_6_ = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.unknown_6_ = 0;
        cur++;
    }
    entry.fa.n1 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    if (cur->tag != 0) {
        entry.f8 = (short)((Script::Parameter*)(cur++))->ToInt();
    } else {
        entry.f8 = 0;
        cur++;
    }
    entry.fa.n2 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    entry.fa.n3 = (unsigned short)((Script::Parameter*)(cur++))->ToInt();
    entry.fc.unknown_0_0_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.fc.unknown_1_2_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.unknown_0_0_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.unknown_1_2_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.unknown_2_4_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.fc.unknown_2_4_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.f10.unknown_2_7_ = ((Script::Parameter*)(cur++))->ToInt();
    entry.f14 = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.unknown_16_ = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.f18 = (short)((Script::Parameter*)(cur++))->ToInt();
    entry.unknown_1a_ = (short)((Script::Parameter*)(cur++))->ToInt();

    func_02071cc8(data_02108d98.fieldC, (struct Struct_02071874*)&entry);
    return 1;
}
