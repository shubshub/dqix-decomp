#include <globaldefs.h>

void ResetTask020dbebc(void* a);
extern "C" void* Zone3D_GetInstance(void);
int IsIdInRange020981e4(int a, int id);
struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);

#if defined(jpn)
static const int kLogOffset=0x41e8, kIdOffset=0x860, kInternalOffset=0x27c;
#else
static const int kLogOffset=0x4498, kIdOffset=0x840, kInternalOffset=0x2cc;
#endif

// USA: func_ov017_0218d5c8
#pragma optimize_for_size off
// Overlay 17, originally ResetFieldWithLog_0218d5c8 (USA/EUR 0x0218d5c8, JPN 0x0218e1a8)
ARM void GameResources_ReleaseSpecialItemEffect(unsigned char* obj) {
	int* logPtr = *(int**)(obj + kLogOffset);
	if (logPtr != NULL) {
		ResetTask020dbebc(logPtr);
	}
	unsigned char* base = (unsigned char*)Zone3D_GetInstance();
	unsigned short id = *(unsigned short*)base;
	int r = IsIdInRange020981e4((int)(base + kIdOffset), id);
	unsigned char* base2 = obj + kInternalOffset;
	if (r != 0) {
		base2 = base2 + 0x930;
	} else {
		base2 = base2 + 0xc40;
	}
	VramState_Rewind((struct Foo0207df50*)base2);
	*(int*)(obj + kLogOffset) = 0;
}
