#if defined(jpn)
enum { Enum_ov017_021ca1a4_14104 = 0x3508, Enum_ov017_021ca1a4_21748 = 0x56e8 };
#else
enum { Enum_ov017_021ca1a4_14104 = 0x3718, Enum_ov017_021ca1a4_21748 = 0x54f4 };
#endif

#include <globaldefs.h>

extern "C" int func_020a1eb0(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);

struct Combatant020A36A8;
extern "C" int func_020a36a8(struct Combatant020A36A8* obj);

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

struct Struct_ov017_021c6814 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char unknown_3_;
    signed char field4;
    unsigned char pad5;
    unsigned short field6;
    unsigned short field8;
};
extern "C" void func_ov017_021c6814(unsigned short a, unsigned short b, struct Struct_ov017_021c6814* src, unsigned char flags, signed char arg4, unsigned char arg5);

extern "C" void func_ov000_02162c14(void* b, int idx, struct Struct_ov017_021c6814* out);

extern "C" void func_ov000_02160fa8(void* work, int mask);

struct Struct_ov017_021ca1a4 { char pad[4]; unsigned short field4; };
struct Struct_ov017_021ca1a4_2 { char pad[8]; unsigned short field8; };

// USA: func_ov017_021ca1a4
extern "C" ARM void func_ov017_021ca1a4(int arg0, struct Struct_ov017_021ca1a4* arg1, void* unused, char* arg3) {
    if (func_020a1eb0() != 0) return;

    void* combatant = *(void**)(arg3 + Enum_ov017_021ca1a4_14104);
    void* a = func_ov017_021b8478(combatant);
    void* b = func_ov017_021b8468(combatant);
    if (!a || !b) return;

    if (((struct Struct_ov017_021ca1a4_2*)a)->field8 != arg1->field4) return;

    if (func_020a36a8((struct Combatant020A36A8*)a)) {
        int i;
        struct Struct_ov017_021c6814 buf;
        for (i = 0; i < 4; i++) {
            if (func_020a35e0((unsigned char*)a, i & 0xff) && arg0 != i) {
                func_ov000_02162c14(b, i, &buf);
                int val = *(int*)((char*)b + i * 4 + Enum_ov017_021ca1a4_21748);
                func_ov017_021c6814(((struct Struct_ov017_021ca1a4_2*)a)->field8, (unsigned short)i, &buf, (unsigned char)(val & 0xff), (signed char)arg0, 0);
            }
        }
    } else {
        func_ov000_02160fa8(b, 0x40000000);
    }
}
