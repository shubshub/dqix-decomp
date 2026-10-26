#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216052c_40 = 0x20 };
enum { Enum_ov003_0216052c_804 = 0x20c };
enum { kRegion328 = 0x210 };
enum { Enum_ov003_0216052c_1124 = 0x28c };
#else
enum { Enum_ov003_0216052c_40 = 0x28 };
enum { Enum_ov003_0216052c_804 = 0x324 };
enum { kRegion328 = 0x328 };
enum { Enum_ov003_0216052c_1124 = 0x464 };
#endif

struct Struct_0207fdcc_2;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int func_020811d0(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080a6c(void* param0, int id, short param2, short* param3, short* param4, short* arg5, short* arg6);
extern "C" void func_ov003_021604f4(char* obj, int valA, int valB, short index, unsigned char flag);

struct Struct_ov003_0216052c {
    short ids[3];
};

struct Struct_ov003_0217f3ec {
    char pad0[Enum_ov003_0216052c_40];
    struct Struct_ov003_0216052c elements;
};

extern struct Struct_ov003_0217f3ec data_ov003_0217f3ec;
extern short data_ov003_0217f448[3][2];

struct Struct_ov003_0216052c_2 {
    char pad0[Enum_ov003_0216052c_804];
    struct Struct_0207fdcc_2* model;
    char unknown_328_[Enum_ov003_0216052c_1124 - kRegion328];
    unsigned int flags;
};

// USA: func_ov003_0216052c
extern "C" ARM void func_ov003_0216052c(struct Struct_ov003_0216052c_2* obj) {
    if (obj->model == NULL) {
        return;
    }
    if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
        return;
    }
    struct Struct_0207fdcc_2* model = obj->model;
    if (!(obj->flags & 0x10000)) {
        return;
    }
    struct Struct_ov003_0216052c elements = data_ov003_0217f3ec.elements;
    for (int i = 0; i < 3; i++) {
        short id = elements.ids[i];
        if (func_020811d0(model, id)) {
            unsigned char slot = 1;
            for (unsigned char j = 0; j < 2; j++) {
                short part = data_ov003_0217f448[i][j];
                if (part >= 0) {
                    short x, y, w, h;
                    func_02080a6c(model, id, part, &x, &y, &w, &h);
#if !defined(jpn)
                    h = (16 - h) >> 1;
#endif
                    short posX = x + w + 6;
#if defined(jpn)
                    short var12 = y - 3;
#else
                    short var12 = y - h + 1;
#endif
                    func_ov003_021604f4((char*)obj, posX, var12, 0, slot++);
                }
            }
            return;
        }
    }
}
