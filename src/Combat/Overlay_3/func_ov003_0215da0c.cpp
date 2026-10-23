#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0215da0c_152 = 0xb0 };
enum { Enum_ov003_0215da0c_952 = 0x3d0 };
enum { Enum_ov003_0215da0c_1008 = 0x408 };
enum { Enum_ov003_0215da0c_957 = 0x3d5 };
enum { Enum_ov003_0215da0c_2456 = 0x868 };
#else
enum { Enum_ov003_0215da0c_152 = 0x98 };
enum { Enum_ov003_0215da0c_952 = 0x3b8 };
enum { Enum_ov003_0215da0c_1008 = 0x3f0 };
enum { Enum_ov003_0215da0c_957 = 0x3bd };
enum { Enum_ov003_0215da0c_2456 = 0x998 };
#endif

struct Struct_0201099c_3;
struct Struct_0205d6a0;

char* GetGlobalField0x1c020421a0();
void ReinitController02043204(char* ctrl);
int KeyTable_Get(struct Container020e0310* c, int key);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* list, int flag);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* arg0);
extern "C" void func_ov003_0215cab0(void* arg0, int arg1);

struct Struct_ov003_0215da0c {
    char unknown_0_[0x64];
    char unknown_64_[Enum_ov003_0215da0c_152 - 0x64];
    char unknown_98_[Enum_ov003_0215da0c_952 - Enum_ov003_0215da0c_152];
    unsigned char unknown_3b8_;
    char unknown_3b9_[3];
    unsigned char unknown_3bc_;
    char unknown_3bd_[Enum_ov003_0215da0c_1008 - Enum_ov003_0215da0c_957];
    unsigned char unknown_3f0_;
    unsigned char unknown_3f1_;
    unsigned char unknown_3f2_;
    unsigned char unknown_3f3_;
};

// USA: func_ov003_0215da0c
extern "C" ARM void func_ov003_0215da0c(struct Struct_ov003_0215da0c* arg0) {
    char* var0;
    GameState* var1;
    void* var2;
    unsigned char var3;
    int var4;
    int var5;

    var1 = GameState::GetInstance();
    var0 = func_020421a0();
    var2 = func_0202ae18();

    var4 = 0;
    if (func_0202c508(var2) && var1->GetUnknownGameObject()->obj3D_.unknown_4_ == 0) {
        var4 = 1;
    }
    var5 = 0;
    if (func_0202c508(var2) && var1->GetUnknownGameObject()->obj3D_.unknown_4_ != 0) {
        var5 = 1;
    }

    var3 = arg0->unknown_3b8_;
    if (var3 == 0) {
        if (arg0->unknown_3f3_) {
            func_02043204(var0);
            arg0->unknown_3b8_++;
            return;
        }
        int var6 = 0x442;
        if (arg0->unknown_3f0_) {
            if (var4) {
                arg0->unknown_3f1_ = 1;
                var6 = 0x6e;
            } else if (var5) {
                var6 = 0x74;
            } else {
                var6 = 0x73;
            }
        }
        func_ov003_0215cab0(self, KeyTable_Get((struct Container020e0310*)self->messages, key));
        self->step++;
    }
    if (var3 == 1 && *(int*)(var0 + Enum_ov003_0215da0c_2456) == 0) {
        func_0205d6a0((struct Struct_0205d6a0*)arg0->unknown_98_, 1);
        arg0->unknown_3bc_ = 5;
        arg0->unknown_3b8_ = 0;
    }
}
