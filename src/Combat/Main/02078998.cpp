#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct SearchStruct0202c1a4;
extern "C" int rand();
extern "C" void* __clear(void*, int);
struct Struct_02076ccc;
extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int func_02053c6c(unsigned char*);
extern "C" bool func_02076ccc(void*, int);
struct Struct_ov017_021c95ec { int x, y, z; };
extern "C" void func_ov017_021c95ec(int, int, int, int, int, Struct_ov017_021c95ec, int, unsigned char, unsigned char);

struct Struct_02078998 {
    char pad0[0xa];
    unsigned short attack;
    unsigned short unknown_c_;
};
struct Struct_02078998_2 {
    Object3D obj;
    char unknown_ac_[0x13b - 0xac];
    unsigned char unknown_13b_;
    unsigned char unknown_13c_;
    char unknown_13d_[3];
    int priority;
    char unknown_144_[8];
    unsigned int counter;
    char unknown_150_[0x166 - 0x150];
    unsigned short combatantId;
    char unknown_168_[8];
    int height;
    short unknown_174_;
    char unknown_176_[4];
    unsigned char unknown_17a_;
    char unknown_17b_[0x184 - 0x17b];
    Struct_02078998* attributes;
};
static inline void inline_02078998(int id, int nibble, int unused, int mode, Struct_02078998_2* self) {
    Struct_ov017_021c95ec position;
    __clear(&position, sizeof(position));
    func_ov017_021c95ec(id, nibble, unused, mode, self->combatantId, position, 0, 0, 0);
}

// USA: func_02078998
extern "C" ARM void func_02078998(Struct_02078998_2* self) {
    if (self->counter <= 225) {
        Vector3fix position = self->obj.position_;
        int scaledY = self->obj.GetScale().y * 15;
        int var2 = (int)(1.15f * (float)self->obj.GetHeight());
        var2 = FIX32_MULTIPLY(var2, scaledY);
        position.y = var2 + position.y;
        self->unknown_174_ += (112 - self->counter * 2) * 3;
        if (self->unknown_174_ < 0) self->unknown_174_ = 0;
        position.y += self->unknown_174_;
        self->height = position.y;
        self->unknown_17a_ = 1;
    }
    if (self->counter <= 225) return;
    self->unknown_17a_ = 0;
    int* search = (int*)LinkSession_GetInstance();
    if (LinkSession_IsActive(search) && LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) return;
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), self->combatantId);
    if (combatant == NULL) return;
    func_02053c6c((unsigned char*)combatant);
    int var5 = 0;
    int var6 = 0;
    int attack = combatant->baseStats_->primaryStats.attack;
    int var8 = combatant->baseStats_->primaryStats.defense;
    if (self->attributes != NULL) {
        var5 = self->attributes->attack;
        var6 = self->attributes->unknown_c_;
    }
    int mode;
    if ((attack + var8 > (var5 + var6) * 3 || self->priority == -99) && self->priority != 99) {
        switch (self->unknown_13b_) {
        case 0:
            func_02076ccc((Struct_02076ccc*)self, 12);
            mode = 12;
            break;
        case 1:
            func_02076ccc((Struct_02076ccc*)self, 6);
            mode = 6;
            break;
        case 2:
            func_02076ccc((Struct_02076ccc*)self, 7);
            mode = 7;
            break;
        case 3:
            if (rand() % 2) {
                func_02076ccc((Struct_02076ccc*)self, 7);
                mode = 7;
            } else {
                func_02076ccc((Struct_02076ccc*)self, 6);
                mode = 6;
            }
            break;
        }
    } else {
        switch (self->unknown_13c_) {
        case 0:
            func_02076ccc((Struct_02076ccc*)self, 5);
            mode = 5;
            break;
        case 1:
            func_02076ccc((Struct_02076ccc*)self, 4);
            mode = 4;
            break;
        case 2:
            if (rand() % 2) {
                func_02076ccc((Struct_02076ccc*)self, 7);
                mode = 7;
            } else {
                func_02076ccc((Struct_02076ccc*)self, 6);
                mode = 6;
            }
            break;
        }
    }
    if (!LinkSession_IsActive(search) || LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) return;
    unsigned short id = self->obj.GetField06();
    int unused = self->obj.unknown_2_;
    int nibble = (self->obj.actorIndex_ - 112) % 12;
    if (nibble >= 0 && nibble < 12) {
        inline_02078998(id, nibble, unused, mode, self);
    }
}
