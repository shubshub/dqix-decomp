#include <globaldefs.h>

extern "C" void* func_ov031_022133f8(int flags);
extern "C" int func_ov031_022191e0(void);
extern "C" unsigned int func_ov031_022135ac(unsigned int x);
extern "C" int func_ov031_02219220(void);
extern "C" void func_ov031_02219080(void);

// USA: func_ov031_02215478
extern "C" ARM int func_ov031_02215478(char* obj) {
    char* d = (char*)func_ov031_022133f8(1);
    int status = func_ov031_022191e0();
    if (status != 0) {
        unsigned int idx = func_ov031_022135ac(*(unsigned char*)(obj + 0xd0d));
        if (*(unsigned char*)(d + 0x15) == idx) {
            *(int*)(d + 0x10) = func_ov031_02219220();
        }
        func_ov031_02219080();
        if (status == 0xb) {
            return 0xf;
        }
        unsigned char idx2 = *(unsigned char*)(obj + 0xd13);
        *(unsigned char*)(obj + idx2 * 4 + 0x444) = 1;
        return 0xb;
    }
    return 0xe;
}
