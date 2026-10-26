#include <globaldefs.h>

struct Struct_ov025_021df794_2 {
    unsigned char id;
    unsigned char timer;
};

struct Struct_ov025_021df794 {
    char pad0[0x170];
    int done;
    char unknown_174_[2];
    Struct_ov025_021df794_2 entries[10];
    unsigned char pending;
    unsigned char head;
};

// USA: func_ov025_021df794
extern "C" ARM void func_ov025_021df794(Struct_ov025_021df794* obj) {
    if (obj->pending != 0) {
        int prev = obj->head - 1;
        if (prev < 0) {
            prev = 9;
        }
        if (obj->entries[prev].timer < 0x1c) {
            int slot = obj->head % 10;
            Struct_ov025_021df794_2* e = &obj->entries[slot];
            e->timer = 0x1f;
            e->id = obj->head;
            obj->head++;
            obj->pending--;
            if (obj->head >= 10) {
                obj->head = 0;
            }
        }
    }
    if (obj->pending == 0) {
        obj->done = 1;
    }
    for (int i = 0; i < 10; i++) {
        Struct_ov025_021df794_2* e = &obj->entries[i];
        if (e->timer != 0) {
            if (e->timer > 2) {
                e->timer -= 2;
            } else {
                e->timer = 0;
            }
        }
    }
}
