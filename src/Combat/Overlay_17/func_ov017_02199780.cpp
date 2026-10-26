#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Cache.h"
#include "std_library_functions.h"


struct Struct020dfc40;
extern "C" void KeyTable_Destroy(struct Struct020dfc40* p);

struct Struct_ov017_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
extern "C" void func_ov017_02199684(Struct_ov017_02199684* arr, int count, int value);
extern "C" void func_ov017_021996bc(Struct_ov017_02199684* arr, int count);

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void Window_Destroy(void* obj);

extern "C" void func_ov017_021996fc(unsigned char* base);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

extern "C" int func_ov017_02199964(int size, int colorMode, int arg2, int arg3, int wrap);
extern "C" int func_ov017_02199998(int priority);
extern "C" int func_ov017_021999b4(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" int func_ov017_021999e0(int priority);

struct Struct_ov017_02199780 {
	unsigned short priority : 2;
	unsigned short unknown_0_2_ : 4;
	unsigned short unknown_0_6_ : 1;
	unsigned short colorMode : 1;
	unsigned short unknown_1_0_ : 5;
	unsigned short wrap : 1;
	unsigned short size : 2;
};

// USA: func_ov017_02199780
extern "C" ARM void func_ov017_02199780(unsigned char* self) {
#if defined(jpn)
	if (*(int*)(self + 0x3000 + 0xe60) == 0) {
#else
	if (*(int*)(self + 0x4000 + 0x80) == 0) {
#endif
		return;
	}

#if defined(jpn)
	if (*(int*)(self + 0x3000 + 0xe58) != 0) {
#else
	if (*(int*)(self + 0x4000 + 0x78) != 0) {
#endif
		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x100;

#if defined(jpn)
		int var0 = *(int*)(self + 0x3000 + 0xe5c);
#else
		int var0 = *(int*)(self + 0x4000 + 0x7c);
#endif
		if (var0 >= 0) {
			int var1 = (int)BackgroundLoader::GetInstance();
#if defined(jpn)
			((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(self + 0x3000 + 0xe5c)));
#else
			((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(self + 0x4000 + 0x7c)));
#endif
		}

		*(volatile unsigned short*)0x4000050 = 0;
		*(volatile unsigned short*)0x4000008 = (*(volatile unsigned short*)0x4000008 & ~3) | 1;

#if defined(jpn)
		Struct_ov017_02199780* var2 = *(Struct_ov017_02199780**)(self + 0x3000 + 0xa88);
#else
		Struct_ov017_02199780* var2 = *(Struct_ov017_02199780**)(self + 0x3000 + 0xca8);
#endif
		func_ov017_02199964(var2->size, var2->colorMode, var2->unknown_1_0_, var2->unknown_0_2_, var2->wrap);
		func_ov017_02199998(var2->priority);

#if defined(jpn)
		Struct_ov017_02199780* var3 = *(Struct_ov017_02199780**)(self + 0x3000 + 0xa8c);
#else
		Struct_ov017_02199780* var3 = *(Struct_ov017_02199780**)(self + 0x3000 + 0xcac);
#endif
		func_ov017_021999b4(var3->size, var3->colorMode, var3->unknown_1_0_, var3->unknown_0_2_);
		func_ov017_021999e0(var3->priority);

#if defined(jpn)
		if (*(int*)(self + 0x3000 + 0xe64) != 0) {
			KeyTable_Destroy((Struct020dfc40*)*(int*)(self + 0x3000 + 0xe64));
			*(int*)(self + 0x3000 + 0xe64) = 0;
#else
		if (*(int*)(self + 0x4000 + 0x84) != 0) {
			KeyTable_Destroy((Struct020dfc40*)*(int*)(self + 0x4000 + 0x84));
			*(int*)(self + 0x4000 + 0x84) = 0;
#endif
		}

#if defined(jpn)
		if (*(int*)(self + 0x3000 + 0xe54) != 0) {
			func_ov017_02199684((Struct_ov017_02199684*)(self + 0x294 + 0x3800), 2, 0x800);
			Window_ClearLayers(*(Cont0205d1e0**)(self + 0x3000 + 0xa90));
			Window_FlushLayers(*(Cont0205d274**)(self + 0x3000 + 0xa90));
			Window_TransferLayers(*(Obj0205d2bc**)(self + 0x3000 + 0xa90));
			func_ov017_021996bc((Struct_ov017_02199684*)(self + 0x294 + 0x3800), 2);
			Window_Destroy(*(void**)(self + 0x3000 + 0xa90));
#else
		if (*(int*)(self + 0x4000 + 0x74) != 0) {
			func_ov017_02199684((Struct_ov017_02199684*)(self + 0xb4 + 0x3c00), 2, 0x800);
			Window_ClearLayers(*(Cont0205d1e0**)(self + 0x3000 + 0xcb0));
			Window_FlushLayers(*(Cont0205d274**)(self + 0x3000 + 0xcb0));
			Window_TransferLayers(*(Obj0205d2bc**)(self + 0x3000 + 0xcb0));
			func_ov017_021996bc((Struct_ov017_02199684*)(self + 0xb4 + 0x3c00), 2);
			Window_Destroy(*(void**)(self + 0x3000 + 0xcb0));
#endif

#if defined(jpn)
			memset(*(void**)(self + 0x3000 + 0xe54), 0, 0x20);
			CleanInvalidateCacheRange(*(void**)(self + 0x3000 + 0xe54), 0x20);
			LoadToMainBG1CharacterData(*(int*)(self + 0x3000 + 0xe54), 0, 0x20);
#else
			memset(*(void**)(self + 0x4000 + 0x74), 0, 0x20);
			CleanInvalidateCacheRange(*(void**)(self + 0x4000 + 0x74), 0x20);
			LoadToMainBG1CharacterData(*(int*)(self + 0x4000 + 0x74), 0, 0x20);
#endif
		}

		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
	}

	func_ov017_021996fc(self);
}
