#include <globaldefs.h>
#include "World/FieldTask.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void GameResources_ReleaseSpecialItemEffect(unsigned char* obj);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void FollowCamera_EnableFollow(void* obj);

extern int g_mainAllocator;

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5a30 : FieldTask {
	int step;                      // SearchPotStep
	unsigned char unknownC;        // zeroed by FieldTask_InitSearchPot
	char padD;
	short unknownE;                // likewise
	unsigned short lootableIndex;  // the pot (Zone3D_GetLootable)
	unsigned short itemId;         // the item found, or the gold amount
	short spriteNumber;            // the icon file's number (/data/ani/d_%c%03d.spr)
	unsigned char spriteTimer;     // frames the icon stays (61)
	signed char spriteLetter;      // the icon file's letter
	short holdTimer;               // ms the player is held still (500)
	char pad1a[2];
	void* leader;
	void* sprite;                  // the icon's sprite slot (Zone3D +0x600 + 0x88 * GameState+0x3ac)
	void* container;               // the pot's LootableContainerManager::Container
	int loadTask;                  // BackgroundLoader task, -1 for none
	Vector3fix position;           // the pot's; the icon is drawn above it
	int bobAngle;                  // the icon rises along a sine of this, up to 90 degrees
	void* message;                 // what the step messages show
	SafeAllocator spriteAllocator;
	unsigned char special;         // the pot holds item 0x5617
	char pad55[3];
	SafeAllocator specialAllocator;
};

// Overlay 17, originally func_ov017_021b5a30 (USA/EUR 0x021b5a30, JPN 0x021b5fe4)
extern "C" ARM void SearchPotTask_Release(struct SearchPotTask021b5a30* self) {
	int resources = ((int)GetGameResources());
	if (self->special != 0 && resources != 0) {
		GameResources_ReleaseSpecialItemEffect((unsigned char*)resources);
		self->special = 0;
	}

	void* spriteBuffer = self->spriteAllocator.GetSignedAllocator();
	if (spriteBuffer != NULL) {
		self->spriteAllocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, spriteBuffer);
	}

	void* specialBuffer = self->specialAllocator.GetSignedAllocator();
	if (specialBuffer != NULL) {
		self->specialAllocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, specialBuffer);
	}

	GameState* gs = GameState::GetInstance();
	GameObject* leader = gs->GetLeader();
	if (leader != NULL) {
		GameObject_EnableControl(leader);
	}

	int camera = GameState_GetFollowCamera((char*)gs);
	if (camera != 0) {
		FollowCamera_EnableFollow((void*)camera);
	}

	if (resources != 0) {
		ClearFlags04((GameResources*)resources, 0x80);
	}
}
