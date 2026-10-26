#include <globaldefs.h>

struct Mutex;
int TryLockMutex(Mutex*);
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);
extern "C" void func_0200159c(int status);

struct Struct_02003ddc {
    unsigned char pad[0x6c];
    int id;
};

struct Struct_02111304_3 {
    int unk0;
    Struct_02003ddc* current;
};

typedef void (*Type_02003ddc)(int slot);

extern int data_020f3060;
extern Struct_02111304_3 data_02111304;
extern int data_020f2f70[];
extern int data_020f2f94[];
extern Type_02003ddc data_020f3394[];

// USA: func_02003ddc
extern "C" ARM int func_02003ddc(int slot) {
    Type_02003ddc handler;

    if (slot < 1 || slot > 7) {
        return -1;
    }

    do {
        if (TryLockMutex((Mutex*)&data_020f3060) == 0) {
            data_020f2f70[7] = data_02111304.current->id;
            data_020f2f94[7] = 1;
            break;
        }
        if (data_020f2f70[7] == data_02111304.current->id) {
            data_020f2f94[7] = data_020f2f94[7] + 1;
            break;
        }
        LockMutex((Mutex*)&data_020f3060);
        data_020f2f70[7] = data_02111304.current->id;
        data_020f2f94[7] = 1;
    } while (0);

    handler = data_020f3394[slot - 1];
    if (handler != (Type_02003ddc)1) {
        data_020f3394[slot - 1] = 0;
    }

    data_020f2f94[7] = data_020f2f94[7] - 1;
    if (data_020f2f94[7] == 0) {
        UnlockMutex((Mutex*)&data_020f3060);
    }

    if (handler == (Type_02003ddc)1 || (handler == 0 && slot == 1)) {
        return 0;
    }
    if (handler == 0) {
        func_0200159c(0);
    }
    handler(slot);
    return 0;
}
