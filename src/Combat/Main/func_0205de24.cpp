#include <globaldefs.h>

struct Struct_0205d304_2;
extern "C" void func_0205d594(struct Struct_0205d304_2* obj, unsigned char* arg1, unsigned char* arg2);

struct Struct_0205de24 {
    char pad0[0x4];
    void* matched;
    char pad1[0xE0 - 0x8];
};

struct Struct0205de24 {
    char pad0[0x98];
    unsigned char* field98;
    unsigned char* unknown_9c_;
    char pad1[0xb2 - 0xa0];
    unsigned char fieldB2;
    char pad2[0xb4 - 0xb3];
    unsigned char fieldB4;
};

// USA: func_0205de24
extern "C" ARM void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh) {
    if (obj->field98 == 0 || obj->unknown_9c_ == 0) return;
    struct Struct_0205de24* target = (struct Struct_0205de24*)(obj->unknown_9c_ + obj->fieldB4 * 0xE0);
    if (target == 0) return;
    unsigned char* entry;
    unsigned char i = 0;
    unsigned char low, high;
    while (i < obj->fieldB2) {
        entry = obj->field98 + i * 0x20;
        func_0205d594((struct Struct_0205d304_2*)entry, &low, &high);
        if (low == keyLow && high == keyHigh) {
            target->matched = entry;
            return;
        }
        i++;
    }
}
