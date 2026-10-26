#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0216512c_54 = 0x2a };
enum { Enum_ov003_0216512c_804 = 0x20c };
enum { kRegion328 = 0x210 };
enum { Enum_ov003_0216512c_1124 = 0x28c };
enum { Enum_ov003_0216512c_1128 = 0x290 };
enum { Enum_ov003_0216512c_1140 = 0x29c };
enum { Enum_ov003_0216512c_1142 = 0x29e };
enum { Enum_ov003_0216512c_1156 = 0x2ac };
enum { Enum_ov003_0216512c_1164 = 0x2b4 };
enum { Enum_ov003_0216512c_1187 = 0x2cb };
enum { Enum_ov003_0216512c_136 = 0x68 };
#else
enum { Enum_ov003_0216512c_54 = 0x36 };
enum { Enum_ov003_0216512c_804 = 0x324 };
enum { kRegion328 = 0x328 };
enum { Enum_ov003_0216512c_1124 = 0x464 };
enum { Enum_ov003_0216512c_1128 = 0x468 };
enum { Enum_ov003_0216512c_1140 = 0x474 };
enum { Enum_ov003_0216512c_1142 = 0x476 };
enum { Enum_ov003_0216512c_1156 = 0x484 };
enum { Enum_ov003_0216512c_1164 = 0x48c };
enum { Enum_ov003_0216512c_1187 = 0x4a3 };
enum { Enum_ov003_0216512c_136 = 0x88 };
#endif
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct Struct_0207fe44 {
    char pad0[Enum_ov003_0216512c_54];
    short unknown_36_;
};

struct Struct_ov003_0216512c {
    char pad0[Enum_ov003_0216512c_804];
    struct Struct_0207fe44* model;
    char unknown_328_[Enum_ov003_0216512c_1124 - kRegion328];
    unsigned int flags;
    char unknown_468_[Enum_ov003_0216512c_1140 - Enum_ov003_0216512c_1128];
    short unknown_474_;
    char unknown_476_[Enum_ov003_0216512c_1156 - Enum_ov003_0216512c_1142];
    short unknown_484_;
    short unknown_486_;
    short unknown_488_;
    short unknown_48a_;
    char unknown_48c_[Enum_ov003_0216512c_1187 - Enum_ov003_0216512c_1164];
    unsigned char code;
    unsigned char step;
};

extern "C" unsigned char* func_020936f8(void);
extern "C" void func_ov003_021612c0(struct Struct_ov003_0216512c* obj);
extern "C" int func_ov003_02161344(struct Struct_ov003_0216512c* obj);
extern "C" void func_0207fe44(struct Struct_0207fe44* obj);
extern "C" void func_ov017_021cea8c(void);
extern "C" void VectorizedMemset(void* dst, int val, int size);
extern "C" void func_020939fc(unsigned char* obj);
extern "C" void func_ov003_02166f80(void* self, int key, int set);

// USA: func_ov003_0216512c
extern "C" ARM void func_ov003_0216512c(struct Struct_ov003_0216512c* obj) {
    unsigned char* global = func_020936f8();
    if (obj->step == 0) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (obj->step == 1) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            func_0207fe44(obj->model);
            obj->unknown_484_ = 0x13;
            obj->step++;
            obj->flags |= 0xc000000;
            func_ov017_021cea8c();
            return;
        }
        obj->unknown_488_ = 0x1b;
        obj->unknown_474_ = obj->unknown_48a_ = 0xaa;
        obj->model->unknown_36_ = obj->unknown_48a_;
        obj->unknown_484_ = 0x12;
        obj->unknown_486_ = 1;
        obj->step = 3;
    } else if (obj->step == 2) {
        GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
        VectorizedMemset(grotto, 0, Enum_ov003_0216512c_136);
        grotto->unknown_0[0] = 0;
        grotto->unknown_0[1] = 0;
        obj->flags |= 0x82;
        obj->code = 6;
        obj->step = 0;
        func_020939fc(global);
    } else if (obj->step == 3) {
        func_ov003_02166f80(obj, obj->unknown_488_, 0);
        obj->code = 10;
        obj->step = 1;
    }
}
