#include <globaldefs.h>

extern "C" int func_02080b40(void* obj, int id);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_02080798(void* obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);
extern "C" ARM int func_020dd11c(unsigned int a, unsigned int b);

// USA: func_ov003_02167fa4
extern "C" ARM void func_ov003_02167fa4(void* arg0, int flag, unsigned char* table) {
    void* obj = *(void**)((char*)arg0 + 0x10);
    int idA = 0x1f;
    int var2 = 0x24;
    for (unsigned char k = 0; k < 5; k++) {
        if (flag == 0) {
            func_02080b2c(obj, idA);
            func_02080b2c(obj, var2);
        } else {
            func_02080b40(obj, idA);
            func_02080b40(obj, var2);
            int t = func_020dd11c(flag, k);
            short adj = (short)(t + 0x26);
            unsigned char byteVal = table[t];
            int nibble = 0xf;
            if (byteVal == 0x64) nibble = 0xd;
            func_02080cc0((struct Struct_02080cc0*)obj, var2, nibble);
            func_0208103c(obj, idA, adj);
#if !defined(jpn)
            func_02080798(obj, idA, 1);
#endif
            func_02080fa8((struct Struct_02080fa8*)obj, var2, byteVal);
        }
        idA = (short)(idA + 1);
        var2 = (short)(var2 + 1);
    }
}
