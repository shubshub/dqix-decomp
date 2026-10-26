#include <globaldefs.h>

extern "C" void func_0202c848(int arg);
extern char data_021015a0;
extern "C" int func_0202d180(void);
extern "C" int func_0202d224(void);

struct Struct_0202d108 {
    char pad0[2];
    unsigned short field2;
};

// USA: func_0202d108
extern "C" ARM void func_0202d108(struct Struct_0202d108* p) {
    unsigned short v = p->field2;
    if (v != 0) {
        func_0202c848(v);
        return;
    }
    *(int*)(&data_021015a0 + 0x10) = 1;
    if (*(unsigned short*)(&data_021015a0 + 0x4) == 0) {
        return;
    }
    *(unsigned short*)(&data_021015a0 + 0x4) = 0;
    if (*(int*)(&data_021015a0 + 0x30) != 0) {
        int r = func_0202d180();
        if (r == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
        return;
    }
    {
        int r = func_0202d224();
        if (r == 0) {
            *(int*)(&data_021015a0 + 0x10) = 9;
        }
    }
}
