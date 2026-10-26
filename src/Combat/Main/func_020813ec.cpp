#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Struct_0207fdcc_2;
extern "C" int func_02081da8(Struct_0207fdcc_2*, int);
struct Struct_0207f0ac;
extern "C" int func_0207f0ac(Struct_0207f0ac*, int);
struct Struct_020813ec;
extern "C" unsigned int func_02081e18(Struct_020813ec*, int);
struct Struct_020813ec_2;
extern "C" int func_02081de0(Struct_020813ec_2*);
extern "C" int func_020804fc(void *obj, int id);
extern "C" int func_0204f160(unsigned char*, int, int);
struct Struct_020813ec_3;
extern "C" int func_02081498(void*, void*, Struct_020813ec_3*);
extern "C" int func_02081574(void *obj, void *a, void *b);
struct Struct_0204fbf8_2;
extern "C" int func_0204fbf8(Struct_0204fbf8_2*);

// USA: func_020813ec
extern "C" ARM int func_020813ec(void *obj, int id) {
    if (id < 0) {
        return 1;
    }

    int a = func_02081da8((Struct_0207fdcc_2*)obj, id);
    int b = func_0207f0ac((Struct_0207f0ac*)((char *)obj + 0xc), id);
    if (b == 0) {
        return 1;
    }

    unsigned char byteVal = *((unsigned char *)obj + (IS_JPN ? 0x2e : 0x3a));
    unsigned int c = func_02081e18((Struct_020813ec*)obj, byteVal);

    if (a == 0) {
        a = func_02081de0((Struct_020813ec_2*)obj);
        func_020804fc(obj, id);
    }

    if (a != 0) {
        func_0204f160((unsigned char*)a, c, id);
        func_02081498(obj, (void *)a, (Struct_020813ec_3*)b);
        func_02081574(obj, (void *)a, (void *)b);
        func_0204fbf8((Struct_0204fbf8_2*)a);
    }

    return 0;
}
