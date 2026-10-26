#include <globaldefs.h>

extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void func_ov023_021f64a8(void* a, int b, int c, int d);
extern "C" void func_ov004_021536e0(void* a, int b, int c);

struct Struct_ov004_021546c0 { short id; short id2; unsigned char field4; unsigned char field5; };
extern Struct_ov004_021546c0* data_ov004_021707c0;
extern "C" void func_ov004_021546c0(Struct_ov004_021546c0* arr, int key1, int key2, unsigned char* out1, unsigned char* out2);

// USA: func_ov004_02154618
extern "C" ARM int func_ov004_02154618(void* a) {
    short var0, var1, entryIndex;
    func_ov004_02153978(a, &var0, &var1, &entryIndex);
    unsigned short var3 = 0x19 + (unsigned short)entryIndex;
    func_ov023_021f645c(a, 0x27, 4, 0xf);
    func_ov023_021f645c(a, 0x28, var3, 0xf);

    unsigned char out1, out2;
    func_ov004_021546c0(data_ov004_021707c0, var1, entryIndex, &out1, &out2);
    func_ov023_021f64a8(a, 0x38, out2, 0xf);
#if !defined(jpn)
    func_ov004_021536e0(a, 0x38, 0x19);
#endif
    return 0;
}
