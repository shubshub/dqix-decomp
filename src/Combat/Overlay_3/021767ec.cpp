#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021767ec_2204 = 0x818 };
enum { Enum_ov003_021767ec_4166 = 0xfc2 };
enum { Enum_ov003_021767ec_4116 = 0xf90 };
enum { Enum_ov003_021767ec_2101 = 0x7b1 };
enum { Enum_ov003_021767ec_2120 = 0x7c4 };
enum { kRegionValue874_7F0 = 0x7f0 };
enum { Enum_ov003_021767ec_13 = 0xc };
enum { Enum_ov003_021767ec_4118 = 0xf92 };
#else
enum { Enum_ov003_021767ec_2204 = 0x89c };
enum { Enum_ov003_021767ec_4166 = 0x1046 };
enum { Enum_ov003_021767ec_4116 = 0x1014 };
enum { Enum_ov003_021767ec_2101 = 0x835 };
enum { Enum_ov003_021767ec_2120 = 0x848 };
enum { kRegionValue874_7F0 = 0x874 };
enum { Enum_ov003_021767ec_13 = 0xd };
enum { Enum_ov003_021767ec_4118 = 0x1016 };
#endif

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_02080b54(void* obj, int id);
extern "C" void func_02080608(void* obj, int id);
extern "C" void func_02081130(void* obj, int id, int flag);

struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" unsigned int func_ov003_02175898(char* obj, void* s);

extern "C" void func_0208077c(void* obj, int id, short value);
extern "C" int func_02080b40(void* obj, int id);

struct Struct_ov003_021767ec;
#if !defined(jpn)
extern "C" void func_ov003_0217818c(char* self, struct Struct_ov003_021767ec* arg1, int id, int value);
#endif

#if !defined(jpn)
extern "C" void func_020805f4(void* obj, int value);
#endif

struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c* obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);

extern "C" void func_020806c4(void* obj, int id);
extern "C" int func_020813ec(void* obj, int id);

// USA: func_ov003_021767ec
extern "C" ARM int func_ov003_021767ec(char* self) {
    struct Struct_0207fdcc_2* o = *(struct Struct_0207fdcc_2**)(self + Enum_ov003_021767ec_2204);
    short var1 = 7;
    short var2 = 13;
    short id2 = 19;

    func_02080c20(o, 3);
    func_02080c68(o, 3, 0);
    func_02080b54(o, 3);
    func_02080608(o, 3);

    unsigned short var4 = *(unsigned short*)(self + Enum_ov003_021767ec_4166);
    func_02081130(o, 3, (var4 & 0x400) != 0);

    short mult = *(short*)(self + Enum_ov003_021767ec_4116);
    unsigned char var6;
    unsigned char idx = mult * 6;
    var6 = idx + 6;

    for (; idx < var6; ) {
        int local1 = 0;
        unsigned int var9 = 0;
        unsigned char limit = *(unsigned char*)(self + Enum_ov003_021767ec_2101);
        if (idx < limit) {
            short key = *(short*)(self + Enum_ov003_021767ec_2120 + idx * 2);
            struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + kRegionValue874_7F0), key);
            if (elem != NULL) {
                local1 = *(unsigned int*)((char*)elem + 4);
                var9 = func_ov003_02175898(self, elem);
                func_0208077c(o, var1, Enum_ov003_021767ec_13);
                func_02080b40(o, var1);
                func_02080b40(o, var2);
                func_02080b40(o, id2);
#if !defined(jpn)
                func_ov003_0217818c(self, (struct Struct_ov003_021767ec*)elem, var2, id2);
#endif
            }
#if !defined(jpn)
            func_020805f4(o, var1);
#endif
            func_02080f8c((struct Container02080f8c*)o, var1, local1);
            func_02080fa8((struct Struct_02080fa8*)o, var2, var9);
            func_020806c4(o, var1);
        }
        var1 = var1 + 1;
        var2 = var2 + 1;
        id2 = id2 + 1;
        idx = idx + 1;
    }

    func_02080b40(o, 0x19);
    func_02080b40(o, 0x1a);
    func_02080b40(o, 0x1b);
    func_02080fa8((struct Struct_02080fa8*)o, 0x19, *(short*)(self + Enum_ov003_021767ec_4116) + 1);
    func_02080fa8((struct Struct_02080fa8*)o, 0x1a, *(short*)(self + Enum_ov003_021767ec_4118));
    return func_020813ec(o, 3);
}
