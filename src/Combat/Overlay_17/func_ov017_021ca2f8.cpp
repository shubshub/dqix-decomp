#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_0205e330(void* data, void* buf, int flags);

// USA: func_ov017_021ca2f8
extern "C" ARM void func_ov017_021ca2f8(unsigned char arg0) {
#if defined(jpn)
 enum {Enum_ov017_021ca2f8_1816=0x508};
#else
 enum {Enum_ov017_021ca2f8_1816=0x718};
#endif
	char buf[0x14];
	void* data = LinkMessageQueue_GetInstance();
	GameState::GetInstance();
	void* var2 = *(void**)((char*)((unsigned int)GetGameResources()) + 0x3000 + Enum_ov017_021ca2f8_1816);
	void* var3 = func_ov017_021b8478(var2);
	if (var3 == NULL) {
		return;
	}
	var0[0] = 0x5b;
	unsigned short var4 = *(unsigned short*)((char*)var3 + 8);
	unsigned char* var5 = (unsigned char*)(var0 + 4);
	*(unsigned short*)var5 = var4;
	var5[2] = arg0;
	func_0205e330(var1, var0, 0);
}
