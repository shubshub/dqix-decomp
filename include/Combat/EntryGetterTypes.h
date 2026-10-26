#pragma once

struct Struct_0203cdd0 {
    char pad[0x60];
    int field60;
};

struct Struct_0203e0a0 {
    char pad[0xc];
    void *unknown_c_;
};

struct Struct_0203dce4 {
    int flags;
    unsigned char unknown4[0x10];
    void* child14;
    void* unknown_18_;
    void* child1c;
};

extern "C" void func_02040af0(Struct_0203dce4* entry, int value);
extern "C" int func_020409e0(Struct_0203dce4* entry);
extern "C" int func_02040a20(Struct_0203dce4* entry);

extern "C" int func_0203cdd0(Struct_0203cdd0 *obj);
extern "C" int func_02040528(int *obj);
extern "C" void *func_02040538(Struct_0203e0a0 *p);
