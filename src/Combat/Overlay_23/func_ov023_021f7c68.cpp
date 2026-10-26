#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov023_021f7c68_72 = 0x44, BUFFER_OFFSET = 0x24 };
#else
enum { Enum_ov023_021f7c68_72 = 0x48, BUFFER_OFFSET = 0x28 };
#endif

struct Struct_0204b988;
extern "C" void func_0204b988(struct Struct_0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);

struct Struct_ov023_021f7c68 { char pad[Enum_ov023_021f7c68_72]; int unknown_48_; unsigned char unknown_4c_, unknown_4d_, unknown_4e_; };

// USA: func_ov023_021f7c68
extern "C" ARM void func_ov023_021f7c68(Struct_ov023_021f7c68* obj, unsigned char a, unsigned char b, unsigned char c) {
    obj->unknown_4c_ = a;
    obj->unknown_4d_ = b;
    obj->unknown_4e_ = c;
    obj->unknown_48_ = 1;
    func_0204b988((struct Struct_0204b988*)((char*)obj + BUFFER_OFFSET), obj->unknown_4c_, obj->unknown_4d_, obj->unknown_4e_, 0xffff);
}
