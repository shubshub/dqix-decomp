#include <globaldefs.h>

extern "C" int func_ov004_021635d0(int* arg0, int* arg1);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void func_ov023_021f9ba8(void* obj, unsigned short v);
extern "C" void func_ov004_02164084(void* obj);
extern "C" int func_ov023_021f98e0(void*, void*);

extern char* data_ov004_02171010;

struct Struct_ov004_02165910 { char pad[0x5c]; short unknown_5c_; short unknown_5e_; char pad2[0x61 - 0x5e - 2]; unsigned char unknown_61_; };

#if defined(jpn)
enum { Enum_ov004_02165910_6144 = 0x1900 };
#else
enum { Enum_ov004_02165910_6144 = 0x1800 };
#endif

// USA: func_ov004_02165910
extern "C" ARM int func_ov004_02165910(void* obj) {
    int var0, var1;
    var1 = 0;
    var0 = 0;
    if (func_ov004_021635d0(&var1, &var0)) {
        struct Struct_ov004_02165910* node = (struct Struct_ov004_02165910*)func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
        if (node) {
#if defined(jpn)
            if (func_ov023_021f6f10(node) == 7) {
#else
            if (func_ov024_021f6f10(node) == 7) {
#endif
                *(short*)((char*)data_ov004_02171010 + Enum_ov004_02165910_6144 + 0xf6) = (short)var1;
                short var3 = *(short*)((char*)data_ov004_02171010 + Enum_ov004_02165910_6144 + 0xf8);
                short var4 = *(short*)((char*)data_ov004_02171010 + Enum_ov004_02165910_6144 + 0xf6);
                node->unknown_5c_ = var4;
                node->unknown_5e_ = var3;
                func_ov023_021f9ba8(node, (unsigned short)var0);
                func_ov004_02164084(obj);
                func_ov023_021f9ba8(node, (unsigned short)var0);
                func_ov023_021f98e0(node, obj);
            }
        }
    }

    struct Struct_ov004_02165910* node2 = (struct Struct_ov004_02165910*)func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
    if (!node2) {
        goto ret0;
    }
#if defined(jpn)
    if (func_ov023_021f6f10(node2) == 7) {
#else
    if (func_ov024_021f6f10(node2) == 7) {
#endif
        goto setf61;
    }
ret0:
    return 0;
setf61:
    node2->unknown_61_ = 0;
    return 0;
}
