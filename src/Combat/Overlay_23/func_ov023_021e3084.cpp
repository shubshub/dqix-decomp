#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3084 func_ov023_021e33dc
#endif
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Graphics.h"

extern "C" int func_ov017_021bdbe4(unsigned char* base);
extern "C" int func_ov017_021bdbd8(unsigned char* base);
extern "C" void CharacterModel_Draw(void* addr, void* pair);

struct Struct_ov023_021e3084 { void* unknown_0_; void* unknown_4_; };

#if defined(jpn)
enum { Enum_ov023_021e3084_308 = 0x130, Enum_ov023_021e3084_1588 = 0x56c, Enum_ov023_021e3084_296 = 0x124 };
#else
enum { Enum_ov023_021e3084_308 = 0x134, Enum_ov023_021e3084_1588 = 0x634, Enum_ov023_021e3084_296 = 0x128 };
#endif

struct Struct_ov023_021e3084_2 {
    unsigned char unknown0[Enum_ov023_021e3084_296];
    void* drawObject;
    unsigned char unknown_12c_[Enum_ov023_021e3084_308 - Enum_ov023_021e3084_296 - sizeof(void*)];
    int unknown_134_;
    unsigned char unknown_138_[Enum_ov023_021e3084_1588 - Enum_ov023_021e3084_308 - sizeof(int)];
    unsigned short flags;
};

// USA: func_ov023_021e3084
extern "C" ARM void func_ov023_021e3084(void* obj) {
    Struct_ov023_021e3084_2* state = (Struct_ov023_021e3084_2*)obj;
    GameState::GetInstance();

    if (state->unknown_134_ > 0) {
        if (--state->unknown_134_ == 0) {
            state->flags |= 8;
        }
    }

    if ((state->flags & 0x20) == 0) {
        return;
    }

    GameResources* resources = GetGameResources();
    Struct_ov023_021e3084 attachments;
    if (resources == NULL) {
        attachments.unknown_4_ = NULL;
        attachments.unknown_0_ = NULL;
    } else {
        attachments.unknown_4_ = (void*)func_ov017_021bdbe4((unsigned char*)resources);
        attachments.unknown_0_ = (void*)func_ov017_021bdbd8((unsigned char*)resources);
    }

    if (state->drawObject != NULL) {
        GXFIFO_MATRIX_PUSH = 0;
        CharacterModel_Draw(state->drawObject, &attachments);
        GXFIFO_MATRIX_POP = 1;
    }
}
