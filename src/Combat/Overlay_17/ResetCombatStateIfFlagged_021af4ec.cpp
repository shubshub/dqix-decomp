#include <globaldefs.h>
#include "Resource/Brightness.h"

void* GlobalFlags_GetInstance(void);
int* GetGlobal02109030_020936f8(void);
struct StateFlags3c9;
int CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(struct StateFlags3c9* obj);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void* func_0202ae18(void);
void* GetData02100044_0202ae24(void);
extern "C" void func_0202b0f4(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char* obj);
struct BitArrayObj0205e854;
void* FillBitArray0x1524WithFF(struct BitArrayObj0205e854* obj);

struct ObjResetCombatState_021af4ec {
	unsigned char pad0;
	unsigned char field1;
	unsigned char pad2[6];
	unsigned char field8;
	unsigned char pad3[6];
	unsigned char field15;
};

// USA: func_ov017_021af4ec  (semantic: ResetCombatStateIfFlagged_021af4ec)
extern "C" ARM unsigned char func_ov017_021af4ec(ObjResetCombatState_021af4ec* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x40c3, regionalOffset1=0x40c2};
#else
 enum {regionalOffset0=0x42e3, regionalOffset1=0x42e2};
#endif
	unsigned int* p = (unsigned int*)GlobalFlags_GetInstance();
	struct StateFlags3c9* g = (struct StateFlags3c9*)GetGlobal02109030_020936f8();
	if (CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(g)) {
		FlagWord_SetBits(p, 0x20);
		int f = (int)GetGameResources();
		void* a = func_0202ae18();
		struct BitArrayObj0205e854* d = (struct BitArrayObj0205e854*)GetData02100044_0202ae24();
		obj->field15 = 0;
		SetFlags00((GameResources*)f, 2);
		func_0202b0f4(a);
		ClearTwoBytesAtField_02195748((unsigned char*)f);
		SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)f);
		ClearFlag0x3c9Bit0AndCleanup_020939fc((unsigned char*)g);
		FillBitArray0x1524WithFF(d);
		ClearFlags00((GameResources*)f, 0x40);
		((unsigned char*)f)[regionalOffset0] = 0;
		((unsigned char*)f)[regionalOffset1] = 0;
		obj->field1 = 1;
	}
	return obj->field8;
}
