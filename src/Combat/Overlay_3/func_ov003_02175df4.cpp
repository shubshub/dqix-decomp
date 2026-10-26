#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02175df4_2204 = 0x818 };
enum { Enum_ov003_02175df4_4108 = 0xf88 };
enum { Enum_ov003_02175df4_2208 = 0x81c };
enum { Enum_ov003_02175df4_4124 = 0xf98 };
enum { Enum_ov003_02175df4_4114 = 0xf8e };
enum { Enum_ov003_02175df4_4154 = 0xfb6 };
enum { Enum_ov003_02175df4_4148 = 0xfb0 };
#else
enum { Enum_ov003_02175df4_2204 = 0x89c };
enum { Enum_ov003_02175df4_4108 = 0x100c };
enum { Enum_ov003_02175df4_2208 = 0x8a0 };
enum { Enum_ov003_02175df4_4124 = 0x101c };
enum { Enum_ov003_02175df4_4114 = 0x1012 };
enum { Enum_ov003_02175df4_4154 = 0x103a };
enum { Enum_ov003_02175df4_4148 = 0x1034 };
#endif

struct Struct_0207c484;
struct Struct_02061c04_23;
struct Struct_02061c04_22;

extern "C" int func_0207c484(struct Struct_0207c484* obj, int value, int amount, int key);
extern "C" short func_02080468(void* obj, int id);
extern "C" struct Struct_02061c04_22* func_02053c6c(unsigned char* obj);
extern "C" void func_0208386c(struct Struct_02061c04_22* s, int idx);
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);

struct Struct_ov003_02175df4 {
    char unk_0[0x8];
    unsigned int category_ : 4;
};

struct Struct_ov003_02175df4_2 {
    char unk_0[0x8];
    Struct_ov003_02175df4* unknown_8_;
    char unk_c[Enum_ov003_02175df4_2204 - 0xc];
    void* members_;
    char unknown_8a0_[Enum_ov003_02175df4_4108 - Enum_ov003_02175df4_2208];
    short mode_;
    short slot_;
    short unknown_1010_;
    char unknown_1012_[Enum_ov003_02175df4_4124 - Enum_ov003_02175df4_4114];
    int unknown_101c_[5];
    int kind_;
    char unknown_1034_[Enum_ov003_02175df4_4154 - Enum_ov003_02175df4_4148];
    short key_;
    signed char unknown_103c_;
};

// USA: func_ov003_02175df4
extern "C" ARM int func_ov003_02175df4(Struct_ov003_02175df4_2* self) {
    GameState* bs = GameState::GetInstance();
    char* bag = (char*)GameState_GetParty(bs);
    if (self->mode_ == 0x77) {
        return func_0207c484((struct Struct_0207c484*)(bag + 0x1d4), self->key_, self->unknown_103c_, self->unknown_8_->category_);
    }
    int id;
    switch (self->kind_) {
    case 1:
        id = 0x11;
        break;
    case 2:
        id = 0x12;
        break;
    case 3:
        id = 0x13;
        break;
    case 4:
        id = 0x14;
        break;
    }
    short idx = self->unknown_1010_ - func_02080468(self->members_, id);
    if (self->kind_ > idx) {
        GameObject* member = bs->GetPartyMemberByIndex(self->unknown_101c_[idx]);
        if (member == NULL) {
            return 0;
        }
        short slot = self->slot_ - func_02080468(self->members_, 0x15);
        func_0208386c(func_02053c6c((unsigned char*)member), (signed char)slot);
        return 1;
    }
    func_020a0a08((struct Struct_02061c04_23*)bag, self->key_, self->unknown_103c_);
    return 1;
}
