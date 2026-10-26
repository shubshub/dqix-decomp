#include <globaldefs.h>

extern "C" int func_ov031_0220fe44(int arg);
extern "C" ARM int func_ov031_0220ff18(void* obj);
extern "C" ARM void func_ov031_0220fea0(void);
extern "C" ARM void func_ov031_0220fed8(void);
extern "C" ARM int func_ov031_0220fff8(int* obj);

struct Struct_ov031_0220fb28_3 { int f0; int f4; int f8; int fc; int f10; };

extern void* data_ov031_0224e580;

// USA: func_ov031_0220fd78
extern "C" ARM void func_ov031_0220fd78(int val, Struct_ov031_0220fb28_3 *msg) {
    msg->f0 = 0x14;
    msg->f4 = 0x44535359;
    msg->f8 = 0xd5;
    msg->fc = 1;
    msg->f10 = val;

    *(int*)((char*)data_ov031_0224e580 + 0x30) = 0;

    if (func_ov031_0220fe44((int)func_ov031_0220fff8) != 0) {
        if (func_ov031_0220ff18(msg) != 0) {
            func_ov031_0220fea0();
        }
    }
    func_ov031_0220fed8();
}
