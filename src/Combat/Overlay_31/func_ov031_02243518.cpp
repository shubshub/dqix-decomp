#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_ov031_02243518 {
    SafeAllocator primary;
    SafeAllocator unknown_14_;
    SafeAllocator* external;
    unsigned char unknown_2c_;
    char unknown_2d_[3];
    int unknown_30_;
    unsigned char unknown_34_, unknown_35_, unknown_36_, unknown_37_;
    int unknown_38_, unknown_3c_, unknown_40_;
    unsigned char unknown_44_;
    char unknown_45_[3];
    int unknown_48_;
    void* buffer;
    char unknown_50_[0x2c0];
    char unknown_310_[0x64];
    unsigned char mode;
    char unknown_375_[7];
    int unknown_37c_, unknown_380_, unknown_384_, unknown_388_, unknown_38c_;
    unsigned char unknown_390_, unknown_391_;
    char unknown_392_[2];
    int unknown_394_;
    unsigned char unknown_398_, unknown_399_, unknown_39a_, unknown_39b_;
    int unknown_39c_, unknown_3a0_;
    int unknown_3a4_[11];
    unsigned char unknown_3d0_;
    char unknown_3d1_[3];
    char unknown_3d4_[0x58];
    int unknown_42c_, unknown_430_, unknown_434_;
    unsigned char unknown_438_, unknown_439_;
    char unknown_43a_[2];
    char unknown_43c_[0x600];
};
extern SafeAllocator data_ov031_02291e3c;
extern "C" void VectorizedMemset(void*, int, unsigned int);

// USA: func_ov031_02243518
extern "C" ARM int func_ov031_02243518(Struct_ov031_02243518* state, int flags) {
    GameState::GetInstance();
    state->unknown_2c_ = 0;
    state->unknown_34_ = 1;
    state->unknown_35_ = 0;
    state->unknown_37_ = 0;
    state->unknown_36_ = 0;
    state->mode = flags;
    unsigned char mode = state->mode;
    if (mode & 2) {
        state->mode = 2;
        state->unknown_2c_ = 0;
    } else if (mode & 0x20) {
        state->mode = 0x20;
        state->unknown_2c_ = 0;
        state->unknown_34_ = 7;
    } else if (mode & 1) {
        state->unknown_2c_ = 0;
    } else if (mode & 4) {
        state->unknown_2c_ = 0;
    }
    state->unknown_44_ = 0;
    state->unknown_38_ = 0;
    state->unknown_3c_ = 0;
    state->unknown_40_ = 0;
    state->unknown_48_ = 0;
    state->buffer = 0;
    VectorizedMemset(state->unknown_50_, 0, 0x2c0);
    data_ov031_02291e3c.ResetAllocatorPointer();
    state->primary.ResetAllocatorPointer();
    state->unknown_14_.ResetAllocatorPointer();
    state->external = 0;
    state->unknown_37c_ = 0;
    state->unknown_380_ = 0;
    state->unknown_384_ = 0;
    state->unknown_388_ = 0;
    state->unknown_38c_ = 0;
    state->unknown_390_ = 0;
    state->unknown_391_ = 0;
    state->unknown_394_ = 0;
    state->unknown_398_ = 0;
    state->unknown_399_ = 0;
    state->unknown_39a_ = 0;
    state->unknown_39b_ = 0;
    state->unknown_30_ = 0;
    state->unknown_39c_ = -1;
    state->unknown_3a0_ = -1;
    state->unknown_3a4_[0] = 0;
    state->unknown_3a4_[1] = 0;
    state->unknown_3a4_[2] = 0;
    state->unknown_3a4_[3] = 0;
    state->unknown_3a4_[4] = 0;
    state->unknown_3a4_[5] = 0;
    state->unknown_3a4_[6] = 0;
    state->unknown_3a4_[7] = 0;
    state->unknown_3a4_[8] = 0;
    state->unknown_3a4_[9] = 0;
    state->unknown_3a4_[10] = 0;
    state->unknown_3d0_ = 0;
    VectorizedMemset(state->unknown_3d4_, 0, 0x58);
    state->unknown_42c_ = -1;
    state->unknown_430_ = 0;
    state->unknown_434_ = 0;
    state->unknown_438_ = 0;
    state->unknown_439_ = 0;
    memset(state->unknown_43c_, 0, 0x600);
    return 1;
}
