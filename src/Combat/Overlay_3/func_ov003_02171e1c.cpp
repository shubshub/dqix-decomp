#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov003_02171df0(unsigned char* arr);
extern "C" int memcmp(void* a, void* b, int n);

struct Struct_ov003_02171e1c {
    unsigned char key[6];
    unsigned char age;
    unsigned char pad;
};

struct Struct_ov003_02171e1c_2 {
    unsigned char pad0[0x8];
    Struct_ov003_02171e1c entries[0x32];
    unsigned char pad1[0x198 - (0x8 + 0x32 * 0x8)];
    unsigned char count;
};

// USA: func_ov003_02171e1c
extern "C" ARM void func_ov003_02171e1c(Struct_ov003_02171e1c_2* list, unsigned char* key) {
    if (key == 0) return;
    if (func_ov003_02171df0(key) != 0) return;
    {
        Struct_ov003_02171e1c* found = 0;
        int var1 = 0;
        Struct_ov003_02171e1c* e = list->entries;
        for (int i = 0; i < 0x32; i++, e++) {
            int age = e->age;
            if (age != 0 && memcmp(e, key, 6) == 0) {
                found = e;
                var1 = age;
                e->age = 0x32;
                break;
            }
        }
        if (var1 == 0x32) return;
        if (var1 > 0) {
            Struct_ov003_02171e1c* other = list->entries;
            for (int i = 0; i < 0x32; i++, other++) {
                if (other->age > var1 && other != found) {
                    other->age--;
                }
            }
            return;
        }
    }
    {
        Struct_ov003_02171e1c* empty = 0;
        Struct_ov003_02171e1c* e = list->entries;
        for (int i = 0; i < 0x32; i++, e++) {
            if (e->age != 0) {
                if (--e->age == 0) {
                    memset(e, 0, 6);
                    list->count--;
                }
            }
            if (e->age == 0 && empty == 0) empty = e;
        }
        if (empty == 0) return;
        empty->age = 0x32;
        memcpy(empty, key, 6);
        list->count++;
    }
}
