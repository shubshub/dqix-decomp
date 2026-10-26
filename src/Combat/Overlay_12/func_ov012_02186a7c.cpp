#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218943c func_ov012_02189d18
enum {
    Enum_ov012_02186a7c_4976 = 0x1340,
    Enum_ov012_02186a7c_4977 = 0x1341,
    Enum_ov012_02186a7c_5024 = 0x1368,
    kWindowOffset = 0x90,
    Enum_ov012_02186a7c_356 = 0x148,
    kMainChoiceOffset = 0x142c,
    Enum_ov012_02186a7c_9 = 7
};
#else
enum {
    Enum_ov012_02186a7c_4976 = 0x1370,
    Enum_ov012_02186a7c_4977 = 0x1371,
    Enum_ov012_02186a7c_5024 = 0x13a0,
    kWindowOffset = 0xac,
    Enum_ov012_02186a7c_356 = 0x164,
    kMainChoiceOffset = 0x13d4,
    Enum_ov012_02186a7c_9 = 9
};
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* FontBankLoader_GetInstance();

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);

struct SePlayer;
extern struct SePlayer g_sePlayer;
extern "C" int SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

struct Struct_ov012_02186a7c;
extern "C" int func_ov023_021e6e20(struct Struct_ov012_02186a7c* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" void func_ov012_0218943c(void* self);

// USA: func_ov012_02186a7c
extern "C" ARM void func_ov012_02186a7c(char* self) {
	GameState::GetInstance()->GetResources();
	BackgroundLoader::GetInstance();
	FontBankLoader_GetInstance();

	unsigned char state = *(unsigned char*)(self + Enum_ov012_02186a7c_4976);
	if (state == 0) {
		*(unsigned char*)(self + Enum_ov012_02186a7c_5024) = 0;
		*(int*)(self + kMainChoiceOffset) = 0;
		func_0205de24((struct Struct0205de24*)(self + kWindowOffset), 0, 2);
		func_ov023_021e6e60(self);
		func_ov012_0218943c(self);
		(*(unsigned char*)(self + Enum_ov012_02186a7c_4976))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + Enum_ov012_02186a7c_5024) = 1;
	*(int*)(self + kMainChoiceOffset) = Window_GetSelectedIndex((struct Struct_0205c570*)(self + kWindowOffset));

	int flag = 0;
	if (func_ov023_021e6de4(self) != 0) {
		*(unsigned char*)(self + Enum_ov012_02186a7c_356) = *(unsigned char*)(self + Enum_ov012_02186a7c_4977);
		*(unsigned char*)(self + Enum_ov012_02186a7c_5024) = 0;
		SePlayer_Play(&g_sePlayer, 1, 0);

		int v = *(int*)(self + kMainChoiceOffset);
		switch (v) {
		case 0: *(unsigned char*)(self + Enum_ov012_02186a7c_4977) = 2; *(unsigned char*)(self + Enum_ov012_02186a7c_4976) = flag; break;
		case 1: *(unsigned char*)(self + Enum_ov012_02186a7c_4977) = Enum_ov012_02186a7c_9; *(unsigned char*)(self + Enum_ov012_02186a7c_4976) = flag; break;
		case 2: *(unsigned char*)(self + Enum_ov012_02186a7c_4977) = 0xa; *(unsigned char*)(self + Enum_ov012_02186a7c_4976) = flag; break;
		case 3: *(unsigned char*)(self + Enum_ov012_02186a7c_4977) = 0xd; *(unsigned char*)(self + Enum_ov012_02186a7c_4976) = flag; break;
		case 4: *(unsigned char*)(self + Enum_ov012_02186a7c_4977) = 0xe; *(unsigned char*)(self + Enum_ov012_02186a7c_4976) = flag; break;
		case 5: flag = 1; break;
		}
	} else {
		if (func_ov023_021e6e20((struct Struct_ov012_02186a7c*)self) != 0) flag = 1;
	}

	if (flag == 0) return;
	*(unsigned char*)(self + Enum_ov012_02186a7c_5024) = 0;
	*(int*)(self + kMainChoiceOffset) = 0;
	Window_ClosePane((struct Entry_0205d6a0*)(self + kWindowOffset), 1);
	*(unsigned char*)(self + Enum_ov012_02186a7c_4977) = 0xf;
	*(unsigned char*)(self + Enum_ov012_02186a7c_4976) = 0;
}
