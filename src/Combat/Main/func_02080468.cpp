#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f0ac_2;
extern "C" Struct_0207f0ac_2* func_0207f0ac(Struct_0207f0ac* list, int id);

struct Struct_0207f524;
struct Struct_0207f6ac;
extern "C" Struct_0207f6ac* func_0207f6ac(Struct_0207f524* list, int id);

struct Struct_02080468 {
    short* memberIds;
    char pad[0x13 - 4];
    unsigned char count;
};

struct Struct_02080468_2 {
    char pad0[4];
    short f4;
    char pad1[0x18 - 6];
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad2[0x2a - 0x28];
    unsigned char unknown_2a_;
};

// USA: func_02080468
extern "C" ARM short func_02080468(void* obj, int id) {
    short result = -1;
    Struct_02080468* group = (Struct_02080468*)func_0207f0ac((Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (group != NULL) {
        unsigned char i;
        for (i = 0; i < group->count; i++) {
            result = group->memberIds[i];
            Struct_02080468_2* e = (Struct_02080468_2*)func_0207f6ac((Struct_0207f524*)((char*)obj + 4), result);
            if (e == NULL) continue;
            if (e->unknown_2a_ & 2) continue;
            if (e->f18 == 0 && e->f1c == 0 && e->f20 == 0 && e->f24 == 0) continue;
            result = e->f4;
            break;
        }
    }
    return result;
}
