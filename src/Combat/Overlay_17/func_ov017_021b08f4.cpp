#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov017_021b08f4_1816 = 0x508, Enum_ov017_021b08f4_1792 = 0x4f0 };
#else
enum { Enum_ov017_021b08f4_1816 = 0x718, Enum_ov017_021b08f4_1792 = 0x700 };
#endif

extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_021682ec(void* p);
extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void func_ov017_021b0bc0(void* obj);
extern "C" int func_ov017_021b0b4c(void*);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);

struct Struct_ov017_021b08f4 {
    char pad0[0x9];
    unsigned char byte9;
    char pad1[0x26 - 0xa];
    unsigned char unknown_26_;
    unsigned char unknown_27_;
    char pad2[0x2c - 0x28];
    unsigned char unknown_2c_;
    char pad3[0x34 - 0x2d];
    int field34;
};

// USA: func_ov017_021b08f4
extern "C" ARM unsigned char func_ov017_021b08f4(Struct_ov017_021b08f4* obj) {
    GameState::GetInstance();
    int ctx = ((int)GetGameResources());
    char* base = (char*)ctx + 0x3000;
    void* var2 = *(void**)(base + Enum_ov017_021b08f4_1816);
    void* p700 = *(void**)(base + Enum_ov017_021b08f4_1792);
    if (*((unsigned char*)var2 + 0x2) != 0) {
        void* var4 = func_ov017_021b8468(var2);
        if (var4 != 0) {
            func_ov000_021682ec(var4);
        }
    }

    if (obj->byte9 == 0) {
        if (obj->unknown_26_ == 0) {
            func_ov017_021d0b30(5, 0, 0);
            if (func_ov017_021b0b4c(obj) != 0) {
                obj->unknown_26_ = obj->unknown_26_ + 1;
            } else {
                obj->unknown_26_ = 2;
            }
        } else if (obj->unknown_26_ == 1) {
            if (FieldTaskQueue_IsEmpty((void**)p700) != 0) {
                obj->unknown_26_ = obj->unknown_26_ + 1;
            }
        } else if (obj->unknown_26_ == 2) {
            if ((obj->unknown_27_ & 0x10) != 0) {
                func_ov017_021b0bc0(obj);
                func_ov017_021d0b30(7, 0, 0);
                obj->unknown_26_ = obj->unknown_26_ + 1;
            }
        }
    } else {
        if (obj->unknown_26_ == 0) {
            if (obj->field34 != 0) {
                if (func_ov017_021b0b4c(obj) != 0) {
                    obj->unknown_26_ = obj->unknown_26_ + 1;
                } else {
                    func_ov017_021d0b30(6, 0, 0);
                    obj->unknown_26_ = 2;
                }
            }
        } else if (obj->unknown_26_ == 1) {
            if (FieldTaskQueue_IsEmpty((void**)p700) != 0) {
                func_ov017_021d0b30(6, 0, 0);
                obj->unknown_26_ = obj->unknown_26_ + 1;
            }
        } else if (obj->unknown_26_ == 2 && obj->unknown_2c_ == 2) {
            func_ov017_021b0bc0(obj);
        }
    }

    return *((unsigned char*)obj + 0xa);
}
