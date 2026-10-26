#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov023_021f7688_3;
extern "C" void func_ov023_021f7ca0(struct Struct_ov023_021f7688_3* obj, void* keyObj);

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

struct Struct_020534ac_2;

struct Struct_020534ac;

struct Obj021f7aac;
struct PacRecord;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct PacRecord* entry, unsigned int entryLength);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct PacRecord* entry, unsigned int entryLength);

struct Struct_ov023_021f7688_2 {
    char pad0[0xc];
    unsigned char fieldC;
    char pad0d[0x10 - 0xd];
    int field10;
    char unknown_14_[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021f7688
extern "C" ARM int func_ov023_021f7688(struct Struct_ov023_021f7688_2* obj, void* keyObj) {
    if (obj->field10 == 0) {
        func_ov023_021f7ca0((struct Struct_ov023_021f7688_3*)obj, keyObj);
        return 2;
    }

    void* node = func_ov011_021849c8(keyObj);
    int var1 = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    int result;
    if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct Struct_020534ac_2*)var1))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            if (v1 != 0 && v2 != 0) {
                if (obj->fieldC & 0x2) {
                    func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, (struct PacRecord*)v1, v2);
                } else {
                    func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, (struct PacRecord*)v1, v2);
                }
            }
        }

        ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        result = 2;
    } else {
        result = obj->field1c;
    }
    return result;
}
