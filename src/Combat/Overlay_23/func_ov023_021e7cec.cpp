#include <globaldefs.h>

struct Struct_ov023_021fd7fc { unsigned char id; unsigned char f1; unsigned char f2; signed char f3; signed char f4; unsigned char unknown_5_; unsigned char unknown_6_; };
extern Struct_ov023_021fd7fc data_ov023_021fd7fc[];

struct Struct_ov023_021e7cec {
    char pad[0x118];
    unsigned short unknown_118_;
    unsigned short unknown_11a_;
    unsigned short field11c;
    unsigned short unknown_11e_;
    unsigned short unknown_120_;
    unsigned short unknown_122_;
    unsigned short field124;
    unsigned short unknown_126_;
    char pad2[0x129 - 0x128];
    unsigned char unknown_129_;
    char pad3[0x12d - 0x12a];
    unsigned char unknown_12d_;
    unsigned char unknown_12e_;
};

// USA: func_ov023_021e7cec
extern "C" ARM void func_ov023_021e7cec(struct Struct_ov023_021e7cec* obj, unsigned char key, unsigned short p2, unsigned short p3) {
    int i = 0;
    struct Struct_ov023_021fd7fc* entry;
    while (data_ov023_021fd7fc[i].id != 0xff) {
        entry = &data_ov023_021fd7fc[i];
        if (entry->id == key) {
            obj->unknown_129_ = entry->id;
            obj->field11c = p2;
            obj->unknown_11e_ = p3;
            unsigned char t2 = entry->f2;
            unsigned char var3 = entry->f1;
            obj->unknown_120_ = var3;
            obj->unknown_122_ = t2;
            signed char var4 = entry->f4;
            signed char var5 = entry->f3;
            obj->unknown_118_ = var5;
            obj->unknown_11a_ = var4;
            unsigned char var6 = entry->unknown_6_;
            unsigned char var7 = entry->unknown_5_;
            obj->field124 = var7;
            obj->unknown_126_ = var6;
            obj->unknown_12d_ = 0;
            obj->unknown_12e_ = 0;
            if (entry->id == 0x10) {
                obj->unknown_12d_ = 1;
                obj->unknown_12e_ = 1;
            }
            return;
        }
        i++;
    }
}
