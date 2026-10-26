#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" char* GameState_GetFollowCamera(char* gameState);
extern "C" void FollowCamera_EnableFollow(void* obj);
extern "C" void func_020a2718(char* actor);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov001_02154da0(void);
extern "C" void func_ov001_02156b20(void* obj);
extern "C" void func_ov017_021bb27c(void* obj);

extern char g_bgmPlayer;

struct Struct_ov001_021567c4 {
	unsigned char field_0x0;
	unsigned char done;
	char pad2[8];
	unsigned short nextState;
	#if defined(jpn)
 char unknown_c_[0x90 - 0xc];
#else
 char unknown1_c_[0x94 - 0xc];
#endif
	int field_0x94;
};

static inline unsigned char* inline_ov001_021567c4(GameResources* resources) { SDK_NULL_ASSERT(resources); return (unsigned char*)resources->unknown_ptr_3718; }

// USA: func_ov001_021567c4
extern "C" ARM unsigned short func_ov001_021567c4(Struct_ov001_021567c4* self) {
	GameState* gameState = GameState::GetInstance();
	GameResources* resources = GetGameResources();
	gameState->GetLeader();
	char* camera = GameState_GetFollowCamera((char*)gameState);
	inline_ov001_021567c4(resources)[1] = 1;
	func_ov001_02154da0();
	SetBrightness(resources, 0, 0x1e);
	FollowCamera_EnableFollow(camera);
	func_020a2718(camera);
	func_0209c2e0(&g_bgmPlayer, self->field_0x94, 0);
	func_ov001_02156b20(self);
	func_ov017_021bb27c(self);
	self->done = 1;
	return self->nextState;
}
