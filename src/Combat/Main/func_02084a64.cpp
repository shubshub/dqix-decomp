#include <globaldefs.h>

extern "C" int func_02085fb4(unsigned char* actor);
extern "C" int func_02086020(unsigned char* actor);
extern "C" int func_0208608c(unsigned char* actor);
extern "C" int func_020860f8(unsigned char* actor);
extern "C" int func_02086164(unsigned char* actor);
extern "C" int func_020861d0(unsigned char* actor);
extern "C" int func_0208623c(unsigned char* actor);
extern "C" int func_020862a8(unsigned char* obj);
extern "C" int func_02086314(unsigned char* obj);
extern "C" unsigned int func_02084e4c(unsigned int a, unsigned int start, unsigned int length, unsigned int max);

struct Struct_02084a64 {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct Struct_02084a64_2 {
    struct Struct_02084a64 unknown_0_;
    struct Struct_02084a64 w1;
    struct Struct_02084a64 w2;
};

#if defined(jpn)
enum { Enum_02084a64_0 = 0x98 };
#else
enum { Enum_02084a64_0 = 0 };
#endif

// USA: func_02084a64
extern "C" ARM int func_02084a64(unsigned char* obj, int id) {
    int index = *(int*)(obj + 0x950 - Enum_02084a64_0);
    struct Struct_02084a64_2* row = (struct Struct_02084a64_2*)(obj + 0x850 - Enum_02084a64_0) + index;
    unsigned int result = 0;
    int var3 = 0;

    switch (id) {
    case 421: {
        int delta = func_02085fb4(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x91c - Enum_02084a64_0))->f0 + row->unknown_0_.f0;
        unsigned int var6 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->unknown_0_.f0 += var6;
        result = var6;
        break;
    }
    case 423: {
        int delta = func_02086020(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x91c - Enum_02084a64_0))->f1 + row->unknown_0_.f1;
        unsigned int var9 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->unknown_0_.f1 += var9;
        result = var9;
        break;
    }
    case 424: {
        int delta = func_0208608c(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x91c - Enum_02084a64_0))->f2 + row->unknown_0_.f2;
        unsigned int var12 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->unknown_0_.f2 += var12;
        result = var12;
        break;
    }
    case 422: {
        int delta = func_020860f8(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x920 - Enum_02084a64_0))->f0 + row->w1.f0;
        unsigned int var15 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->w1.f0 += var15;
        result = var15;
        break;
    }
    case 428: {
        int delta = func_02086164(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x920 - Enum_02084a64_0))->f1 + row->w1.f1;
        unsigned int var18 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->w1.f1 += var18;
        result = var18;
        break;
    }
    case 426: {
        int delta = func_020861d0(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x920 - Enum_02084a64_0))->f2 + row->w1.f2;
        unsigned int var21 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->w1.f2 += var21;
        result = var21;
        break;
    }
    case 425: {
        int delta = func_0208623c(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x924 - Enum_02084a64_0))->f0 + row->w2.f0;
        unsigned int var24 = func_02084e4c((unsigned int)obj, sum, 2, 999);
        row->w2.f0 += var24;
        result = var24;
        break;
    }
    case 262: {
        int delta = func_020862a8(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x924 - Enum_02084a64_0))->f1 + row->w2.f1;
        unsigned int var27 = func_02084e4c((unsigned int)obj, sum, 3, 999);
        row->w2.f1 += var27;
        result = var27;
        break;
    }
    case 263: {
        int delta = func_02086314(obj);
        int sum = delta + ((struct Struct_02084a64*)(obj + 0x924 - Enum_02084a64_0))->f2 + row->w2.f2;
        unsigned int var30 = func_02084e4c((unsigned int)obj, sum, 3, 999);
        row->w2.f2 += var30;
        result = var30;
        break;
    }
    case 427: {
        unsigned short cur = *(unsigned short*)(obj + 0x564);
        unsigned int var32 = func_02084e4c((unsigned int)obj, cur, 2, 2600);
        unsigned short var33 = (unsigned short)var32;
        *(unsigned short*)(obj + 0x564) = *(unsigned short*)(obj + 0x564) + var33;
        result = var32;
        break;
    }
    default:
        var3 = 1;
        break;
    }

    return var3 ? -1 : (int)result;
}
