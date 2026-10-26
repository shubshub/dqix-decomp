#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215f2b4_24 = 0x10 };
#else
enum { Enum_ov006_0215f2b4_24 = 0x18 };
#endif

#include "GameState/GameState.h"


struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);
struct GameResources;
void SetBrightness(GameResources*, int, int);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
int IsBrightnessTransitionActive(GameResources*);

extern int g_bgmPlayer;

struct Struct_ov006_0215f2b4 {
	unsigned char pad0[Enum_ov006_0215f2b4_24];
	struct Struct_020e25e8* f18;
	unsigned char pad1[0x38f - Enum_ov006_0215f2b4_24 - 4];
	unsigned char unknown_38f_;
	unsigned char unknown_390_;
	unsigned char pad2[0x394 - 0x391];
	unsigned short unknown_394_;
};

// USA: func_ov006_0215f2b4
extern "C" ARM void func_ov006_0215f2b4(struct Struct_ov006_0215f2b4* obj) {
	int ctx = (int)GameState::GetInstance()->GetResources();
	if (obj->unknown_390_ == 0) {
		if (obj->f18 != 0) {
			func_020e25e8(obj->f18);
		}
		SetBrightness((GameResources*)ctx, -16, 16);
		if ((obj->unknown_394_ & 2) == 0) {
			BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0xf);
		}
		obj->unknown_390_ += 1;
		return;
	}
	if (obj->unknown_390_ != 1) {
		return;
	}
	if (IsBrightnessTransitionActive((GameResources*)ctx) == 0) {
		obj->unknown_38f_ = 0xd;
		obj->unknown_390_ = 0;
	}
}
