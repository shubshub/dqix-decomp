#include <globaldefs.h>

struct Struct_ov004_021536e0 { int x, y, z; };

class Struct_ov004_021536e0_2 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_021536e0_8(const Struct_ov004_021536e0& v);
    virtual Struct_ov004_021536e0 inline_ov004_021536e0_9();
};

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_021536e0_2* func_ov023_021f6880(void* obj, int key);
extern "C" int func_ov023_021f6378(void* a, int key);
extern "C" void* func_ov023_021f63ac(void* a, int b, int c);

// USA: func_ov004_021536e0
extern "C" ARM void func_ov004_021536e0(void* a, int b, int c) {
    Struct_ov004_021536e0_2* node = func_ov023_021f6880(func_ov011_021849c8(a), b);
    if (!node) return;
    char* entry = (char*)func_ov023_021f63ac(a, 4, func_ov023_021f6378(a, c));
    if (entry != 0 && *entry != 0) return;
    Struct_ov004_021536e0_2* node2 = func_ov023_021f6880(func_ov011_021849c8(a), c);
    if (!node2) return;
    const Struct_ov004_021536e0& v = node2->inline_ov004_021536e0_9();
    node->inline_ov004_021536e0_8(v);
}
