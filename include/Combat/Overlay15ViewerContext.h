#pragma once

class SafeAllocator;
class Object3D;
struct Struct_ov015_0218bcb0_2;
struct Struct205563c;

struct Struct_ov015_0218bcb0
{
    char* viewer_;
    Struct_ov015_0218bcb0_2* slot_;
    SafeAllocator* allocators_;
    const char* name_;
    void* unknown_10_;
    void* buffer_;
    unsigned int bufferSize_;
    unsigned char kind_;
    char unknown_1d_[3];
    int* parts_;
    Object3D* objects_;
    Struct205563c* effect_;
    char unknown_2c_[0xc];
    short motion_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    char unknown_3c_[0xc];
    int unknown_48_;
    char unknown_4c_[0x10];
};

extern "C" int func_ov015_0218bcb0(void*);
extern "C" void func_ov015_0218f0c4(void*);
extern "C" void func_ov015_0218c274(Struct_ov015_0218bcb0*, char*, int);
extern "C" void func_ov015_0218c920(void*, int);
