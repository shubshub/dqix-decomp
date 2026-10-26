#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int CharacterCreationUI_Update(int handle);
void SoundPlayer_PlayPending(void* p);
extern "C" void func_020bbd9c(void);
extern int g_sePlayer;

struct Obj0218baf8 {
    unsigned char pad0[0x40];
    int field40;
    unsigned char pad44[0xb8 - 0x44];
    int fieldb8;
};

// USA: func_ov021_0218baf8
ARM void ReleaseLocksAndReset_0218baf8(struct Obj0218baf8* obj) {
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (CharacterCreationUI_Update(obj->field40) != 0) {
        obj->fieldb8 = 1;
    }
    SoundPlayer_PlayPending(&g_sePlayer);
    func_020bbd9c();
}
