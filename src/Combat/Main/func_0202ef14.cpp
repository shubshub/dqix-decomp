#include <globaldefs.h>

struct Struct_0202ef14_2 {
    int unknown_0_;
};

int Vec3Ease_IsRunning(int*);
void DispatchMemberFn020a0dec(struct DispatchObj020a0dec*);
void RotateOffsetAndAdvance0202e894(void*, int);
int fix32ReduceAngle0To2Pi(int);

struct Struct_0202ef14 {
    char unknown_0_[0x168];
};

typedef void (Struct_0202ef14::*Type_02013158)(void*);

struct Struct_020e73cc {
    Type_02013158 unknown_0_[3];
};

extern const Struct_020e73cc data_020e73cc;
extern const Struct_020e73cc data_020e73e4;

// USA: func_0202ef14
extern "C" ARM void func_0202ef14(struct Struct_0202ef14* arg0) {
    char* var0 = (char*)arg0;
    unsigned int var1 = *(unsigned int*)(var0 + 0x168);
    struct Struct_0202ef14_2* var2[3];
    var2[0] = (struct Struct_0202ef14_2*)(var0 + 0x16c);
    var2[1] = (struct Struct_0202ef14_2*)(var0 + 0x194);
    var2[2] = (struct Struct_0202ef14_2*)(var0 + 0x1bc);

    int i;
    if (flags & 2) {
        struct DispatchTable0202ef14 table = data_020e73e4;
        for (i = 0; i < 3; i++) {
            if (Vec3Ease_IsRunning((int*)arr[i])) {
                DispatchMemberFn020a0dec(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    } else {
        struct DispatchTable0202ef14 table = data_020e73cc;
        for (i = 0; i < 3; i++) {
            if (Vec3Ease_IsRunning((int*)arr[i])) {
                DispatchMemberFn020a0dec(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    }

    if (*(unsigned short*)(var0 + 0x1ee) != 0) {
        *(unsigned short*)(var0 + 0x1ee) -= 1;
        *(unsigned short*)(var0 + 0x7c) = (unsigned short)(*(short*)(var0 + 0x7c) + *(short*)(var0 + 0x1ec));
    }

    if (*(unsigned short*)(var0 + 0x210) != 0) {
        *(unsigned short*)(var0 + 0x210) -= 1;
        func_0202e894(var0, *(short*)(var0 + 0x20e));
    }

    if (*(unsigned short*)(var0 + 0x216) != 0) {
        *(unsigned short*)(var0 + 0x216) -= 1;
        *(unsigned short*)(var0 + 0x212) = (unsigned short)fix32ReduceAngle0To2Pi(*(short*)(var0 + 0x212) + *(short*)(var0 + 0x214));
    }
}
