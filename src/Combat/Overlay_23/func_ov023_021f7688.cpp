#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov023_021f7688_3;
extern "C" void func_ov023_021f7ca0(struct Struct_ov023_021f7688_3* arg0, void* arg1);

extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" int func_ov023_021f6bb8(void* arg0);
extern "C" void func_ov023_021f6bb0(void* arg0, int arg1);

struct Struct_020534ac_2;

struct Struct_020534ac;

struct Obj021f7aac;
struct PacRecord;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct PacRecord* entry, unsigned int entryLength);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct PacRecord* entry, unsigned int entryLength);

struct Struct_ov023_021f7688_2 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x10 - 0xd];
    int unknown_10_;
    char unknown_14_[0x1c - 0x14];
    int unknown_1c_;
};

// USA: func_ov023_021f7688
extern "C" ARM int func_ov023_021f7688(struct Struct_ov023_021f7688_2* arg0, void* arg1) {
    if (arg0->unknown_10_ == 0) {
        func_ov023_021f7ca0((struct Struct_ov023_021f7688_3*)arg0, arg1);
        return 2;
    }

    void* node = func_ov011_021849c8(keyObj);
    int listPtr = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    int result;
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            if (v1 != 0 && v2 != 0) {
                if (obj->fieldC & 0x2) {
                    func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, (struct PacRecord*)v1, v2);
                } else {
                    func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, (struct PacRecord*)v1, v2);
                }
            }
        }

        ((BackgroundLoader*)(var1))->RemoveTask((int)(var2));
        func_ov023_021f6bb0(var0, -1);
        var3 = 2;
    } else {
        var3 = arg0->unknown_1c_;
    }
    return var3;
}
