#if defined(jpn)
enum {regionalOffset0=0x124, regionalOffset1=0x12c, regionalOffset2=0x4e0};
#else
enum {regionalOffset0=0x128, regionalOffset1=0x130, regionalOffset2=0x4e4};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

extern "C" void CharacterModel_Update(void* p);
extern "C" void func_ov023_021e4c18(void* obj);
extern "C" void func_ov023_021e463c(void* obj, int scaleCount);
extern "C" void func_ov023_021e447c(void* obj);
extern "C" void func_ov023_021e456c(void* obj);
extern "C" void func_ov023_021e3e98(void* obj);
extern "C" void func_ov005_02154de8(void* arg);

struct Struct_ov023_021e3db0 {
    void* field0;
    char pad4[regionalOffset0 - 0x4];
    void* field128;
    void* field12c;
    char unknown_130_[regionalOffset2 - regionalOffset1];
    unsigned char unknown_4e4_;
};

// USA: func_ov023_021e3db0
extern "C" ARM void func_ov023_021e3db0(struct Struct_ov023_021e3db0* obj) {
    int val = (int)GameState::GetInstance()->GetResources();

    if (obj->field128 != 0) {
        CharacterModel_Update(obj->field128);
    }
    if (obj->field12c != 0) {
        CharacterModel_Update(obj->field12c);
    }

    if (obj->unknown_4e4_ == 0) {
        if (obj->field128 != 0 && *((unsigned char*)obj->field128 + 0xc12) != 0) {
            return;
        }
        SetBrightness((GameResources*)val, 0, 15);
        obj->unknown_4e4_++;
    } else if (obj->unknown_4e4_ == 1) {
        if (!IsBrightnessTransitionActive((GameResources*)val)) {
            obj->unknown_4e4_++;
        }
    } else if (obj->unknown_4e4_ == 2) {
        func_ov023_021e4c18(obj);
        int scaleCount = GameState::GetInstance()->GetTickCount();
        func_ov023_021e463c(obj, scaleCount);
        func_ov023_021e447c(obj);
        func_ov023_021e456c(obj);
        func_ov023_021e3e98(obj);
    }

    if (obj->field0 == 0) {
        return;
    }
    func_ov005_02154de8(obj->field0);
}
