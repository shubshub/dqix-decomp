#include <globaldefs.h>

struct Struct_ov004_02155d54 { int x, y, z; };

class Struct_ov004_02155d54_3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_02155d54_8(const Struct_ov004_02155d54& v);
    virtual Struct_ov004_02155d54 inline_ov004_02155d54_9();
};

struct Struct_ov004_02155d54_2 {
    unsigned char pad[0xe];
    unsigned short value;
};
extern Struct_ov004_02155d54_2* data_ov004_021707c4;

extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_02155d54_3* func_ov023_021f6880(void* obj, int key);
extern "C" void func_ov023_021f9da0(void* obj, unsigned char v);
extern "C" int func_ov004_0215513c(void* obj, short* pB, short* arg2, short* arg3);
extern "C" int func_ov004_02155090(void);
extern "C" int func_ov004_02155104(void);
extern "C" int func_ov023_021f6378(void* a, int key);
extern "C" void* func_ov023_021f63ac(void* a, int b, int c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void func_ov023_021f64a8(void* a, int b, unsigned short c, int d);
extern "C" int func_ov023_021f6680(void* obj, int id);

// USA: func_ov004_02155d54
extern "C" ARM int func_ov004_02155d54(void* self) {
    func_ov023_021f9da0(func_ov023_021f6880(func_ov011_021849c8(self), 5), 1);

    short b, c, d;
    func_ov004_0215513c(self, &b, &c, &d);

    unsigned short value;
    unsigned short mode = 0xd;
    if (b == 0) {
        value = (short)data_ov004_021707c4->value;
    } else if (c == 8) {
        value = func_ov004_02155090();
        mode = 0xe;
    } else {
        value = func_ov004_02155104();
        mode = 0xf;
    }

#if !defined(jpn)
    Struct_ov004_02155d54_3* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x14);
    if (node) {
        char* entry = (char*)func_ov023_021f63ac(self, 4, func_ov023_021f6378(self, 0x19));
        if (entry == 0 || *entry == 0) {
            Struct_ov004_02155d54_3* src = func_ov023_021f6880(func_ov011_021849c8(self), 0x19);
            if (src) {
                const Struct_ov004_02155d54& v = src->inline_ov004_02155d54_9();
                node->inline_ov004_02155d54_8(v);
            }
        }
    }
#endif

    func_ov023_021f645c(self, 7, mode, 0xf);
    func_ov023_021f64a8(self, 0x14, value, 0xf);
    func_ov023_021f6680(self, 0x10);
    return 0;
}
