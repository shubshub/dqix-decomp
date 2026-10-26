#include <globaldefs.h>

struct Struct_0203d028_21 {
    char unknown_0_[0xcc];
    const char* animName;
    int animFlags;
};

struct Struct_0203e2c4_2 {
    char unknown_0_[0x18];
    struct Struct_0203d028_21* model;
};

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" void func_02040b2c(struct Struct_0203e2c4_2* self, int value);
extern "C" int func_020415b0(Struct_0203d028_21*, int, int);

extern char data_ov004_021706fd[];

// USA: func_ov004_021685b4
extern "C" ARM int func_ov004_021685b4(void) {
    struct Struct_0203e2c4_2* entry = (struct Struct_0203e2c4_2*)func_0203df78(func_0203cf4c(), 0x67);
    if (entry) {
        func_02040b2c(entry, 0);
        entry->model->animFlags = 1;
        func_020415b0(entry->model, (int)data_ov004_021706fd, 1);
    }
    return 0;
}
