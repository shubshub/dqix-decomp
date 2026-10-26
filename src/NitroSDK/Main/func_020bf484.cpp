#include <globaldefs.h>

struct Mutex;
int LockMutex(Mutex*);
extern "C" void func_020bf1a0(void* entry);

struct Struct_020bc9a8;
extern "C" void func_020bc9a8(struct Struct_020bc9a8* obj);

struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

struct Struct_021103b0_4 { int f0; unsigned char* f4; };
extern struct Struct_021103b0_4 data_021103b0;
extern int data_02110a28;

struct Struct_020bf484 {
    char pad0[0x120];
    int unknown_120_;
    unsigned char unknown_124_;
    char pad1[0x12c - 0x125];
    int unknown_12c_;
    int unknown_130_;
};

// USA: func_020bf484
extern "C" ARM void func_020bf484(int arg0, void* unused1, struct Struct_020bf484* obj) {
    if (arg0 != obj->unknown_12c_) {
        return;
    }

    LockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        LockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }

    func_020bf1a0(obj);
    obj->unknown_12c_ = 0;
    obj->unknown_130_ = 0;
    obj->unknown_124_ = 0;
    if (obj->unknown_120_ > 0) {
        func_020bc9a8((struct Struct_020bc9a8*)obj);
        obj->unknown_120_ = 0;
    }

    UnlockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        UnlockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }
}
