#include <globaldefs.h>

struct Struct_ov031_02290f8c;
struct Mutex;
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);

struct Struct_020bc9d0;
extern "C" void func_020bcbc4(struct Struct_020bc9d0* obj);

struct Struct_020bf1a0;
extern "C" void func_020bf238(struct Struct_020bf1a0* obj);

struct Struct_021103b0_2 { int f0; unsigned char* f4; };

extern char data_02110a28;
extern struct Struct_021103b0_2 data_021103b0;

// USA: func_020bf1a0
extern "C" ARM void func_020bf1a0(void* obj) {
    LockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        LockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }

    if ((*(int*)((char*)obj + 0x110) << 30) >> 31) {
        func_020bcbc4((struct Struct_020bc9d0*)obj);
    }
    if ((*(int*)((char*)obj + 0x110) << 31) >> 31) {
        void (*fp)(void*) = *(void(**)(void*))((char*)obj + 0x170);
        fp(obj);
    }

    func_020bf238((struct Struct_020bf1a0*)obj);
    UnlockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        UnlockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }
}
