#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov004_0217101c { unsigned int reserved; char* value; };
extern Struct_ov004_0217101c data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern char* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif
extern "C" void* func_ov023_021f6524(void* ctx, int value);

struct Struct_ov004_02166730 { char pad[0x5c]; short unknown_5c_; short unknown_5e_; };

struct Struct_ov004_021549e4_5;
extern "C" void func_ov023_021f9bdc(struct Struct_ov004_021549e4_5* o, int arg1);
extern "C" int func_ov023_021f98e0(void* node, void* obj);

struct Struct_ov004_021549e4_2;
extern "C" unsigned int func_ov023_021f9bb0(struct Struct_ov004_021549e4_2* obj);
struct Struct_ov004_021549e4_4;
extern "C" unsigned short func_ov023_021f9bc0(struct Struct_ov004_021549e4_4* obj);
struct Struct_ov004_021549e4_3;
extern "C" unsigned int func_ov023_021f9b6c(struct Struct_ov004_021549e4_3* obj, unsigned int a, unsigned int b);

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void* func_ov023_021f9cb8(void* unused, void* other, void* node);
extern "C" int func_ov023_021f88b8(void* obj, void* param1, int id);

// USA: func_ov004_02166730
extern "C" ARM int func_ov004_02166730(void* obj, short key) {
    void* found = *(void**)(CONTEXT_VALUE + 8);
    short index = 0;
    while (found != NULL) {
        if (*(short*)((char*)found + 0) == key) break;
        index++;
        found = *(void**)((char*)found + 8);
    }

    short v6 = index / 8;
    short v7 = index % 8;
    Struct_ov004_02166730* node = (Struct_ov004_02166730*)func_ov023_021f6524(obj, 0x5b);
    if (node) {
        short var5 = node->unknown_5e_;
        node->unknown_5c_ = v6;
        node->unknown_5e_ = var5;
        func_ov023_021f9bdc((struct Struct_ov004_021549e4_5*)node, (unsigned short)v7);
        func_ov023_021f98e0(node, obj);
    }

    unsigned int idx = func_ov023_021f9bb0((struct Struct_ov004_021549e4_2*)node);
    unsigned short field2a = func_ov023_021f9bc0((struct Struct_ov004_021549e4_4*)node);
    unsigned int entry = func_ov023_021f9b6c((struct Struct_ov004_021549e4_3*)node, idx, field2a);

    void* base = func_ov011_021849c8(obj);
    void* n2 = func_ov023_021f6880(base, entry);
    if (!n2) return (int)n2;

#if defined(jpn)
    int type = func_ov023_021f6f10(n2);
#else
    int type = func_ov024_021f6f10(n2);
#endif
    if (type != 8) return type;

    void* result = func_ov023_021f9cb8(node, obj, n2);
    if (!result) return (int)result;

    return func_ov023_021f88b8(result, obj, 0x8000);
}
