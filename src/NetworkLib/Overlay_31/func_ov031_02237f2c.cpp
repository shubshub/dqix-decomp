#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_022381c8(int);
extern "C" ARM void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0223815c(void);
extern "C" void func_ov031_02238000(void);
extern "C" void func_ov031_0223e2c0(int, void*);

struct Struct_ov031_02237f2c {
    Struct_ov031_02222f44_2* header;
    unsigned char pad[0x14 - 4];
    void* field14;
    unsigned char pad2[0x1c - 0x18];
    unsigned char field1c;
};
extern Struct_ov031_02237f2c* data_ov031_02290d10;

extern unsigned short data_ov031_02249336[];

// USA: func_ov031_02237f2c
extern "C" ARM void func_ov031_02237f2c(void* arg) {
    unsigned int var0, var1;
    func_ov031_0223bd28(data_ov031_02290d10->header, 0, &var0, &var1);
    var1 = var1 - 0xc;
    unsigned short threshold = data_ov031_02249336[data_ov031_02290d10->field1c * 2];
    if ((int)var1 > threshold) {
        func_ov031_022381c8(var1);
        return;
    }
    func_ov031_022381c8(threshold);
    if (data_ov031_02290d10->field1c == 5) {
        data_ov031_02290d10->field14 = func_ov031_0223e218(0, (void*)func_ov031_0223815c, 0, 0x78);
    } else {
        data_ov031_02290d10->field14 = func_ov031_0223e218(0, (void*)func_ov031_02238000, 0, 0x78);
    }
    func_ov031_0223e2c0(1, arg);
}
