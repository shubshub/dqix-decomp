#include <globaldefs.h>

struct Obj_02184540;
extern "C" int func_ov011_02184540(struct Obj_02184540* obj);
struct Struct_ov004_0215883c_2;
extern "C" int func_ov011_02184548(struct Struct_ov004_0215883c_2* obj);

struct Obj021f7aac;
struct PacRecord;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct PacRecord* entry, unsigned int entryLength);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct PacRecord* entry, unsigned int entryLength);

struct Struct_ov023_021f7688_3 {
    char pad0[0xc];
    unsigned char fieldC;
};

// USA: func_ov023_021f7ca0
extern "C" ARM void func_ov023_021f7ca0(struct Struct_ov023_021f7688_3* obj, void* keyObj) {
    struct PacRecord* entry = (struct PacRecord*)func_ov011_02184540((struct Obj_02184540*)keyObj);
    unsigned int entryLength = func_ov011_02184548((struct Struct_ov004_0215883c_2*)keyObj);
    if (entry != 0 && entryLength != 0) {
        if (obj->fieldC & 0x2) {
            func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, entry, entryLength);
        } else {
            func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, entry, entryLength);
        }
    }
}
