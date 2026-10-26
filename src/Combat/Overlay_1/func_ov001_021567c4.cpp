#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

char* GameState_GetFollowCamera(char* gameState);
void FollowCamera_EnableFollow(void* obj);
void ApplyVecFromField0x246_020a2718(char* actor);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov001_02154da0(void);
extern "C" void func_ov001_02156b20(void* arg0);
extern "C" void func_ov017_021bb27c(void* arg0);

extern char g_bgmPlayer;

struct Struct_ov001_021567c4 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	char unknown_2_[8];
	unsigned short unknown_a_;
	#if defined(jpn)
 char unknown_c_[0x90 - 0xc];
#else
 char unknown1_c_[0x94 - 0xc];
#endif
	int unknown_94_;
};

static inline unsigned char* inline_ov001_021567c4(GameResources* arg0) { SDK_NULL_ASSERT(arg0); return (unsigned char*)arg0->unknown_ptr_3718; }

// USA: func_ov001_021567c4
extern "C" ARM unsigned short func_ov001_021567c4(State_021567c4* self) {
	GameState* gameState = GameState::GetInstance();
	GameResources* resources = GetGameResources();
	gameState->GetLeader();
	char* camera = GameState_GetFollowCamera((char*)gameState);
	GetPtr3718(resources)[1] = 1;
	func_ov001_02154da0();
	SetBrightness(resources, 0, 0x1e);
	FollowCamera_EnableFollow(camera);
	ApplyVecFromField0x246_020a2718(camera);
	func_0209c2e0(&g_bgmPlayer, self->field_0x94, 0);
	ClearMultipleFieldBits_02156b20(self);
	func_ov017_021bb27c(self);
	self->done = 1;
	return self->nextState;
}
