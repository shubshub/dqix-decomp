#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, Enum_ov017_021a7b38_1816 = 0x508 };
#else
enum { RegionOffset6fc = 0x6fc, Enum_ov017_021a7b38_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" unsigned short* Zone3D_GetInstance(void* p);
struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
struct ListHead02046b38;
struct ListNode02046b38;
extern "C" int func_02046b38(struct ListHead02046b38* list, struct ListNode02046b38* target);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_021b7104(void* node, void* out);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Ctx021a7b38 {
    char pad0[0x1];
    unsigned char unknown_1_;
    char pad1[0x8 - 0x2];
    int unknown_8_;
    char pad2[0x1a - 0xc];
    unsigned char unknown_1a_;
    char pad3[0x20 - 0x1b];
    int field20;
};

// USA: func_ov017_021a7b38
extern "C" ARM void func_ov017_021a7b38(struct Ctx021a7b38* self, void* context) {
    GameState::GetInstance();
    char* base = (char*)(long)((int)GetGameResources()) + 0x3000;
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + RegionOffset6fc);
    struct ListNode02046b38* node = *(struct ListNode02046b38**)(base + Enum_ov017_021a7b38_1816);
    unsigned short id = *Zone3D_GetInstance(base);
    if (self->unknown_8_ != 0) {
        return;
    }
    if (func_02046b60((struct ListHead02046b60*)list, 0x3)) {
        self->unknown_1_ = 1;
        return;
    }
    if (self->unknown_1a_ != 0) {
        int q = _s32_div_f(id, 0x64);
        if (q * 0x64 != 0x170c && id != 0x2710) {
            self->unknown_1_ = 1;
            return;
        }
    }
    if (!func_02046b38((struct ListHead02046b38*)list, node)) {
        self->field20 = 1;
        func_ov017_021b6f18(node);
        func_ov017_021b7104(node, (char*)self + 0xc);
        func_020469b4((struct TailList020469b4*)list, (struct TailNode020469b4*)node);
    }
    self->unknown_8_ = self->unknown_8_ + 1;
    self->unknown_1_ = 1;
}
