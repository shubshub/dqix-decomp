#include <globaldefs.h>

struct Struct0205d888 {
    char pad0[0x98];
    int field98;
    void* unknown_9c_;
    char pad1[0x14];
    unsigned char fieldB4;
};
extern "C" void* Window_GetTopPane(struct Struct0205d888* p);

struct Entry_0205d6a0 {
    char pad0[0x98];
    int unknown_98_;
    int f9c;
    char pad1[0xb3 - 0xa0];
    unsigned char unknown_b3_;
};
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

struct Elem_0205d81c {
    char pad0[0xC4];
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};
struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* unknown_9c_;
    char pad1[0xB3 - 0xA0];
    unsigned char unknown_b3_;
    unsigned char fieldB4;
};
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);

extern unsigned char data_ov000_021834cc[8];
extern unsigned char data_ov000_021834cd[8];

// USA: func_ov000_0217629c
extern "C" ARM void func_ov000_0217629c(void* self) {
    if (*(void**)((char*)self + 0x38) == 0) return;
    int var0 = 1;
    void* entry = Window_GetTopPane((struct Struct0205d888*)*(void**)((char*)self + 0x38));
    int idx;
    for (idx = 0; idx < 4; idx++) {
        if (data_ov000_021834cc[idx << 1] == ((struct Elem_0205d81c*)entry)->fieldC4) {
            var0 = 2;
            break;
        }
    }
    int i;
    for (i = 0; i < var0; i++) {
        Window_ClosePane((struct Entry_0205d6a0*)*(void**)((char*)self + 0x38), 0);
    }
    entry = Window_GetTopPane((struct Struct0205d888*)*(void**)((char*)self + 0x38));
    if (entry == 0) return;
    for (idx = 0; idx < 4; idx++) {
        if (data_ov000_021834cc[idx << 1] == ((struct Elem_0205d81c*)entry)->fieldC4) {
            int key = data_ov000_021834cd[idx << 1];
            struct Elem_0205d81c* elem = func_0205d81c((struct Struct_0205d81c*)*(void**)((char*)self + 0x38), key);
            if (elem != 0) {
                *(short*)((char*)elem + 0xc2) = 0;
            }
            return;
        }
    }
}
