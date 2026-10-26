#include <globaldefs.h>
#include "GameState/GameState.h"
struct Battle0219d250;
struct Entry0219d250;
struct Request0219d250;

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a289c(void);
typedef void (*Type_ov017_0219e234)(void*, int);
extern "C" void func_020a28b0(unsigned char* obj, int mask);

struct Struct_ov017_0219e234 {
	unsigned char nibble : 4;
	unsigned char unknown_0_4_ : 3;
	unsigned char high : 1;
};

// USA: func_ov017_0219e234
extern "C" ARM void func_ov017_0219e234(Battle0219d250* a0, Request0219d250* a1, Entry0219d250* a2, void* obj) {
	GameState* battle = GameState::GetInstance();
	int f = GameState_GetFollowCamera((char*)battle);
	if (!f) return;
	struct Struct_ov017_0219e234* b = (struct Struct_ov017_0219e234*)((char*)obj + 0xc);
	if (b->nibble == 0 || b->high == 0) {
		func_020a28a0((unsigned char*)f, 0x10);
		((Type_ov017_0219e234)&func_020a289c)((void*)f, 2);
		return;
	}
	func_020a28b0((unsigned char*)f, 0x10);
}
