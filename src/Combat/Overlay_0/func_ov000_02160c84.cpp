#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov023_021d8c60;
struct Obj0203a588;

struct Obj020444e0 {
    char pad0[0x38];
    void* field38;
#if defined(jpn)
    char unknown_3c_[0x868 - 0x3c];
#else
    char unknown1_3c_[0x998 - 0x3c];
#endif
    void* unknown_998_;
};

struct Struct_ov000_02160c84 {
#if defined(jpn)
    char pad0[0xe24];
    int phase;
    char unknown_e28_[0x371c - 0xe28];
    char unknown_3760_[0x5768 - 0x371c];
    void* unknown_5574_;
    void* unknown_576c_;
    char unknown_5770_[0x5778 - 0x5770];
    struct Struct_ov023_021d8c60* unknown_5588_;
    char unknown_577c_[0x57bc - 0x577c];
    void* unknown_55cc_;
    char unknown_57c0_[0x57e4 - 0x57c0];
    unsigned int flags;
    char unknown_57e8_[0x71ec - 0x57e8];
#else
    char pad0[0xea8];
    int phase;
    char unknown_eac_[0x3760 - 0xeac];
    char unknown_3760_[0x5574 - 0x3760];
    void* unknown_5574_;
    void* unknown_5578_;
    char unknown_557c_[0x5588 - 0x557c];
    struct Struct_ov023_021d8c60* unknown_5588_;
    char unknown_558c_[0x55cc - 0x558c];
    void* unknown_55cc_;
    char unknown_55d0_[0x55f4 - 0x55d0];
    unsigned int flags;
    char unknown_55f8_[0x6ffc - 0x55f8];
#endif
    char unknown_6ffc_[1];
};

extern "C" void func_ov023_021eb4b8(void* obj);
extern "C" void func_ov000_02175480(void* obj);
extern "C" void func_ov013_02184a58(void* obj);
extern "C" void func_ov023_021d8c60(struct Struct_ov023_021d8c60* obj);
extern "C" struct Obj0203a588* NumberPopups_GetInstance(void);
extern "C" int func_020a1fa8(void);
extern "C" struct Obj020444e0* MessageSystem_GetInstance();
extern "C" void func_020444e0(struct Obj020444e0* obj);
extern "C" void func_ov013_02187784(void* obj);
extern "C" void func_ov000_02173954(char* obj);
extern "C" void NumberPopups_Draw(struct Obj0203a588* data);
extern "C" void func_ov000_0218251c(void* obj);
extern "C" void func_ov026_021dddcc(struct Struct_ov000_02160c84* self);

// USA: func_ov000_02160c84
extern "C" ARM void func_ov000_02160c84(struct Struct_ov000_02160c84* work) {
    if (work->flags & 0x200) {
        if (work->unknown_55cc_) {
            func_ov023_021eb4b8(work->unknown_55cc_);
        }
        if (work->unknown_5574_) {
            func_ov000_02175480(work->unknown_3760_);
            func_ov013_02184a58(work->unknown_5574_);
#if !defined(jpn)
            if (work->unknown_5578_) {
                func_ov013_02187784(work->unknown_5578_);
            }
#endif
        } else if (work->unknown_5588_) {
            func_ov000_02175480(work->unknown_3760_);
            func_ov023_021d8c60(work->unknown_5588_);
        } else if (!(work->flags & 0x40000)) {
            func_ov000_02173954(work->unknown_3760_);
        }
        NumberPopups_Draw(NumberPopups_GetInstance());
        func_ov000_0218251c(work->unknown_6ffc_);
        if (work->phase == 7 && func_020a1fa8() == 3) {
            func_ov026_021dddcc(work);
        }
    }
    GameState::GetInstance()->GetTickCount();
    struct Obj020444e0* global = MessageSystem_GetInstance();
    if (global->unknown_998_) {
        func_020444e0(global);
    }
}
