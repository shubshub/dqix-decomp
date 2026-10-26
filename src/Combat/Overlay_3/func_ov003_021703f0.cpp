#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short unknown_ae_;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" int WindowPane_IsOpen(unsigned char* obj);

struct ShortArrays0204c610;
extern "C" void func_0204c610(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);

struct Struct_ov003_021703f0 {
    char pad0[1];
    signed char state;
    char pad2[4];
    signed char row;
    char unknown_7_;
    signed char index;
    char unknown_9_[0x3c - 0x9];
    struct Struct_0205d81c* list;
    char unknown_40_[4];
    unsigned char* owner;
};

// USA: func_ov003_021703f0
extern "C" ARM void func_ov003_021703f0(struct Struct_ov003_021703f0* obj, short* outX, short* outY) {
    if (obj->state == 5) {
        if (obj->owner != 0 && WindowPane_IsOpen(obj->owner) != 0) {
#if defined(jpn)
            *outX = 0x2c;
            *outY = obj->index * 17 + 0x3a;
#else
            struct Elem_0205d81c* elem = func_0205d81c(obj->list, 0);
            if (elem == 0) return;
            short var1 = elem->posX << 3;
            short var2 = elem->unknown_ae_ << 3;
            short var3, var4, w, h;
            func_0204c610((struct ShortArrays0204c610*)elem, obj->index, &var3, &var4, &w, &h);
            int x = var3;
            int y = var4;
            x = (short)(x + var1);
            y = (short)(y + var2);
            *outX = x - 0x10;
            *outY = y - 2;
#endif
        } else {
            *outX = 0;
            *outY = 0;
        }
    } else if (obj->state == 4 || obj->state == 2) {
        *outX = 4;
        *outY = obj->row * 16 + 0x2b;
    } else {
        *outX = 0;
        *outY = 0;
    }
}
