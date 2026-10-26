#include <globaldefs.h>

struct Struct_ov000_0215d414_2 {
    unsigned char* data;
    unsigned short ids[3];
    unsigned short field_a;
    unsigned char counts[3];
};

struct Struct_ov000_0215d414 {
    unsigned short id;
    char pad2[0xa - 0x2];
    unsigned char total : 4;
    unsigned char matched : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov000_0215d414_3 {
    unsigned char used;
    char pad1;
    unsigned short id;
    int field4;
};

struct Struct_ov000_0215d414_4 {
    char pad0[0x81b0];
    unsigned char total;
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unknown_81b1_6_ : 2;
    unsigned short unknown_81b2_;
    struct Struct_ov000_0215d414 groups[3];
    struct Struct_ov000_0215d414_3 unique[3];
    char unknown_8214_[0x8e18 - 0x8214];
    unsigned char* data;
    char unknown_8e1c_[0x8e49 - 0x8e1c];
    unsigned char mode;
};

// USA: func_ov000_0215d414
extern "C" ARM void func_ov000_0215d414(struct Struct_ov000_0215d414_4* obj, struct Struct_ov000_0215d414_2* src) {
    unsigned char var0 = 0;
    unsigned char total = 0;
    unsigned char var2 = 0;
    long i;

    obj->data = src->data;
    for (i = 0; i < 3; i++) {
        struct Struct_ov000_0215d414* group = &obj->groups[var0];
        if (src->counts[i] != 0) {
            int found = 0;
            int j;
            for (j = 0; j < var2; j++) {
                if (obj->unique[j].id == src->ids[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                struct Struct_ov000_0215d414_3* entry = &obj->unique[var2++];
                entry->id = src->ids[i];
                entry->used = 1;
                entry->field4 = 0;
            }
            group->id = src->ids[i];
            var0++;
            group->total = src->counts[i];
            group->matched = src->counts[i];
            total += group->total;
        }
    }
    obj->unknown_81b1_6_ = var2;
    obj->total = total;
    obj->counter = total;
    obj->groupCount = var0;
    obj->unknown_81b2_ = src->field_a;
    obj->mode = obj->data[0x35];
}
