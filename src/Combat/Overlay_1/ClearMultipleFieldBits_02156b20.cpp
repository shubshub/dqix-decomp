#include <globaldefs.h>
#include "Resource/Brightness.h"

int GetState0209ca68(char* obj);
extern "C" void func_0209c530(void* p);
extern "C" void* Zone3D_GetInstance(void);

extern char g_bgmPlayer;

// USA: func_ov001_02156b20
ARM void ClearMultipleFieldBits_02156b20(void*) {
	unsigned int* obj = (unsigned int*)GetGameResources();
	if (GetState0209ca68(&g_bgmPlayer) == 2) {
		func_0209c530(&g_bgmPlayer);
	}
	unsigned short v = *(unsigned short*)Zone3D_GetInstance();
	if (v != 0x2710) {
		ClearFlags04((GameResources*)obj, 0x4);
	}
	ClearFlags04((GameResources*)obj, 0x40);
	ClearFlags04((GameResources*)obj, 0x10);
	ClearFlags04((GameResources*)obj, 0x2);
	ClearFlags00((GameResources*)obj, 0x4);
}
