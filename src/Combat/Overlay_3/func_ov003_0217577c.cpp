#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0217577c_4171 = 0xfc7 };
enum { Enum_ov003_0217577c_4172 = 0xfc8 };
enum { Enum_ov003_0217577c_2204 = 0x818 };
#else
enum { Enum_ov003_0217577c_4171 = 0x104b };
enum { Enum_ov003_0217577c_4172 = 0x104c };
enum { Enum_ov003_0217577c_2204 = 0x89c };
#endif

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void func_020809c4(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void func_ov003_0217585c(void* obj, int a, int b, int idx, unsigned char c);

struct Struct_ov003_0217577c {
    char pad[Enum_ov003_0217577c_2204];
    struct Struct_0207fdcc_2* unknown_89c_;
};

// USA: func_ov003_0217577c
extern "C" ARM void func_ov003_0217577c(void* objRaw) {
    Struct_ov003_0217577c* obj = (Struct_ov003_0217577c*)objRaw;
    struct Struct_0207fdcc_2* target = obj->unknown_89c_;
    struct Struct_0207fdcc* e = func_02081da8(target, 9);
    if (e == 0) return;
    if (!WindowPane_IsReady((unsigned char*)e)) return;

    short out1, out2;
    int flag1 = 0;
    if (*(unsigned char*)((char*)objRaw + Enum_ov003_0217577c_4171) != 0) flag1 = 1;
    func_020809c4(target, 9, 0x58, &out1, &out2);
    func_ov003_0217585c(objRaw, out1 + flag1, out2 + flag1, 0x1d, 0x1e);

    int flag2 = 0;
    if (*(unsigned char*)((char*)objRaw + Enum_ov003_0217577c_4172) != 0) flag2 = 1;
    func_020809c4(target, 9, 0x59, &out1, &out2);
    func_ov003_0217585c(objRaw, out1 + flag2, out2 + flag2, 0x1e, 0x1f);
}
