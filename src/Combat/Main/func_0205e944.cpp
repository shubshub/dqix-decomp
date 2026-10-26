#include <globaldefs.h>

extern "C" void func_020bbf34(int index, int value);
extern float data_020e7dd4[];

struct Struct_0205e944 {
    unsigned char pad0[0xc8];
    int fc8;
    unsigned char fcc;
};

// USA: func_0205e944
extern "C" ARM void func_0205e944(Struct_0205e944* obj, int level) {
    float f;
    int value;
    obj->fc8 = level;
    f = (float)level;
    f = f * data_020e7dd4[obj->fcc - 1];
    value = (int)f;
    func_020bbf34(0xa, value);
    func_020bbf34(0xb, value);
    func_020bbf34(0xc, value);
    func_020bbf34(0xd, value);
    func_020bbf34(0xe, value);
    func_020bbf34(0xf, value);
    func_020bbf34(0xa, value);
    func_020bbf34(0xc, value);
    func_020bbf34(0xd, value);
    func_020bbf34(0x10, value);
}
