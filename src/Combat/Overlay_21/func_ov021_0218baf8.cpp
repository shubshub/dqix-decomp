#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int CharacterCreationUI_Update(int handle);
extern "C" void SoundPlayer_PlayPending(void* p);
extern "C" void func_020bbd9c(void);
extern int g_sePlayer;

struct Struct_ov021_0218b5fc_2 {
    unsigned char pad0[0x40];
    int field40;
    unsigned char unknown_44_[0xb8 - 0x44];
    int unknown_b8_;
};

// USA: func_ov021_0218baf8
extern "C" ARM void func_ov021_0218baf8(struct Struct_ov021_0218b5fc_2* obj) {
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (CharacterCreationUI_Update(obj->field40) != 0) {
        obj->unknown_b8_ = 1;
    }
    SoundPlayer_PlayPending(&g_sePlayer);
    func_020bbd9c();
}
