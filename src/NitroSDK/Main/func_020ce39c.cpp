#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" int func_020ce128(void);
extern "C" void func_020ce870(int cmd);
extern "C" void func_020c976c(int);
extern "C" void func_020ce234(int value, int* ptr);

typedef void (*Type_01ff8300_3)(int result, int* arg);

struct Struct_020ce308 {
    int lock;
    Type_01ff8300_3 callback;
    void* unknown_8_;
    void* work;
};

struct Struct_021117ec_5 {
    char unknown_0[0x1c];
    Struct_020ce308 work;
};

extern Struct_021117ec_5 data_021117ec;

// USA: func_020ce39c
extern "C" ARM void func_020ce39c(int* arr, int count) {
    volatile int result;
    int i;
    for (;;) {
        unsigned var2 = DisableIRQInterrupts();
        if (!func_020ce128()) {
            SetIRQInterruptState(var2);
            continue;
        }
        result = -0x10000;
        data_021117ec.work.callback = func_020ce234;
        data_021117ec.work.unknown_8_ = (void*)&result;
        for (i = 0; i < count; i++) {
            func_020ce870(arr[i]);
        }
        SetIRQInterruptState(var2);
        while (result == -0x10000) {
            func_020c976c(0xa3a47);
        }
        if (result == 0) {
            return;
        }
        func_020c976c(0xa3a47);
    }
}
