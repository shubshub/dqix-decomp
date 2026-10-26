#include <globaldefs.h>

struct Mutex;
int TryLockMutex(Mutex*);
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);
extern "C" void func_02001878(int status);
extern "C" void func_0200f368();

struct Struct_020015e8 {
    unsigned char pad[0x6c];
    int id;
};

struct Struct_02111304_2 {
    int unk0;
    Struct_020015e8* current;
};

struct Struct_020f2e60 {
    void (*unknown_0_)();
    int unk4;
    int count;
    int unkc;
};

extern void (*data_020f2e70[64])();

extern int data_020f2fb8;
extern Struct_02111304_2 data_02111304;
extern int data_020f2f70;
extern int data_020f2f94;
extern Struct_020f2e60 data_020f2e60;

// USA: func_020015e8
extern "C" ARM void func_020015e8() {
    if (TryLockMutex((Mutex*)&data_020f2fb8) == 0) {
        data_020f2f70 = data_02111304.current->id;
        data_020f2f94 = 1;
    } else if (data_020f2f70 == data_02111304.current->id) {
        data_020f2f94++;
    } else {
        LockMutex((Mutex*)&data_020f2fb8);
        data_020f2f70 = data_02111304.current->id;
        data_020f2f94 = 1;
    }

    Struct_020f2e60* const list = &data_020f2e60;
    if (list->count > 0) {
        void (**const var1)() = data_020f2e70;
        do {
            var1[--list->count]();
        } while (list->count > 0);
    }

    if (--data_020f2f94 == 0) {
        UnlockMutex((Mutex*)&data_020f2fb8);
    }

    if (data_020f2e60.unknown_0_ != 0) {
        data_020f2e60.unknown_0_();
        data_020f2e60.unknown_0_ = 0;
    }

    func_02001878(0);
    func_0200f368();
}
