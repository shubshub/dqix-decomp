#include <globaldefs.h>

extern "C" void func_020dbebc(void* a);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_020981e4(int a, int id);
struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);

#if defined(jpn)
static const int kLogOffset=0x41e8, kIdOffset=0x860, kInternalOffset=0x27c;
#else
static const int kLogOffset=0x4498, kIdOffset=0x840, kInternalOffset=0x2cc;
#endif

// USA: GameResources_ReleaseSpecialItemEffect
#pragma optimize_for_size off
// Overlay 17, originally ResetFieldWithLog_0218d5c8 (USA/EUR 0x0218d5c8, JPN 0x0218e1a8)
extern "C" ARM void GameResources_ReleaseSpecialItemEffect(unsigned char* obj) {
	int* var0 = *(int**)(obj + kLogOffset);
	if (var0 != NULL) {
		func_020dbebc(var0);
	}
	unsigned char* base = (unsigned char*)Zone3D_GetInstance();
	unsigned short id = *(unsigned short*)base;
	int r = func_020981e4((int)(base + kIdOffset), id);
	unsigned char* base2 = obj + kInternalOffset;
	if (r != 0) {
		base2 = base2 + 0x930;
	} else {
		base2 = base2 + 0xc40;
	}
	VramState_Rewind((struct Foo0207df50*)base2);
	*(int*)(obj + kLogOffset) = 0;
}
