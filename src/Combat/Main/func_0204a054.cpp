#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0204a054_4;
struct Struct_0204a054_5;

struct Struct_0204a054;
struct Struct_0204a054_2;

struct Struct_0204a054_3 {
    char pad[0x58];
    unsigned char unknown_58_;
    unsigned char unknown_59_;
    unsigned char field_5a;
    unsigned char unknown_5b_;
    unsigned short unknown_5c_;
};

struct Struct_020489e8_3 {
    char pad[0x13c];
    struct Struct_0204a054_3* unknown_13c_;
};

// USA: func_0204a054
extern "C" ARM void func_0204a054(struct Struct_020489e8_3* obj) {
    GameState* battleStruct;
    struct Struct_0204a054_3* entry;
    int threshold;
    unsigned short v;
    battleStruct = GameState::GetInstance();
    entry = obj->unknown_13c_;
    if (entry->unknown_5c_ == 0) return;
    threshold = battleStruct->GetEffectiveDeltaTime();
    v = entry->unknown_5c_;
    if ((unsigned int)threshold < v) {
        entry->unknown_5c_ = v - threshold;
        return;
    }
    {
        Struct_0204a054_5* node = (Struct_0204a054_5*)((Object3D*)((Struct_0204a054_4*)obj))->GetAnimationPackageByIndex(entry->unknown_58_);
        if (node != NULL) {
            Struct_0204a054_2* member = (Struct_0204a054_2*)((BCFG*)((Struct_0204a054*)((char*)node + 4)))->GetAnimationRecord(entry->unknown_59_);
            if (member != NULL) {
                ((Object3D*)obj)->SetAnimationByName((char const*)member, entry->field_5a);
            }
        }
    }
    entry->unknown_5c_ = 0;
}
