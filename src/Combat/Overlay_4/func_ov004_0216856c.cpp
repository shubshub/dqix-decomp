#include <globaldefs.h>

struct Struct_0203d028_21 {
    char pad[0xd0];
    int field_d0;
};

struct Struct_0203e2c4_2 {
    char pad[0x18];
    struct Struct_0203d028_21* field18;
};

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" void func_02040b2c(struct Struct_0203e2c4_2* self, int value);
extern "C" int func_020415b0(Struct_0203d028_21*, int, int);

extern char data_ov004_021706f7[];

// USA: func_ov004_0216856c
extern "C" ARM int func_ov004_0216856c(void) {
    struct Struct_0203e2c4_2* entry = (struct Struct_0203e2c4_2*)func_0203df78(func_0203cf4c(), 0x67);
    if (entry) {
        func_02040b2c(entry, 0x3244);
        entry->field18->field_d0 = 0;
        func_020415b0(entry->field18, (int)data_ov004_021706f7, 0);
    }
    return 0;
}
