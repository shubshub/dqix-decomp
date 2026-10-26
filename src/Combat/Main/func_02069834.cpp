#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020696bc(int a, int* out, int c);
extern "C" int MessageSystem_GetInstance();

struct RingBuffer020457e8 {
    char unk0[0x186c];
    int slots[4];
    char unknown_187c_[0x131];
    signed char cursor;
};
extern "C" void func_020457e8(struct RingBuffer020457e8* arg0, int value);

struct Struct_02069834 { void* ptr; };

// USA: func_02069834
extern "C" ARM int func_02069834(Struct_02069834* obj, int input) {
    int val;
    unsigned short buf;
    void* dst;
    func_020696bc(input, &val, 1);
    func_020457e8((struct RingBuffer020457e8*)MessageSystem_GetInstance(), val);
    dst = obj->ptr;
    buf = 0xff1a;
    memcpy(dst, &buf, 2);
    return 2;
}
