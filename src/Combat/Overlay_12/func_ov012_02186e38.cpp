#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
enum {
    Enum_ov012_02186e38_4976 = 0x1340,
    Enum_ov012_02186e38_5024 = 0x1368,
    kWindowOffset = 0x90,
    kChoiceBOffset = 0x1434,
    Enum_ov012_02186e38_4924 = 0x1314,
    Enum_ov012_02186e38_22172 = 0x543c,
    Enum_ov012_02186e38_5184 = 0x1498,
    Enum_ov012_02186e38_10310 = 0x2774,
    Enum_ov012_02186e38_310 = 100
};
#else
enum {
    Enum_ov012_02186e38_4976 = 0x1370,
    Enum_ov012_02186e38_5024 = 0x13a0,
    kWindowOffset = 0xac,
    kChoiceBOffset = 0x13dc,
    Enum_ov012_02186e38_4924 = 0x133c,
    Enum_ov012_02186e38_22172 = 0x569c,
    Enum_ov012_02186e38_5184 = 0x1440,
    Enum_ov012_02186e38_10310 = 0x2846,
    Enum_ov012_02186e38_310 = 310
};
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_ov012_02186e38 {
    unsigned int header;
    unsigned int unknown : 9;
    int title : 10;
    int accolade : 11;
    unsigned int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

static inline Struct_ov012_02186e38* inline_ov012_02186e38(GameState* state) {
    return (Struct_ov012_02186e38*)((char*)state + Enum_ov012_02186e38_22172);
}

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);

extern "C" void func_ov012_02189a78(char* base);

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

struct SePlayer;
extern struct SePlayer g_sePlayer;
extern "C" int SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_ov012_02186a7c;
extern "C" int func_ov023_021e6e20(struct Struct_ov012_02186a7c* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" int func_ov012_0218432c(int a);
extern "C" int func_ov023_021e6448(void* self);
#if defined(jpn)
extern "C" void func_ov012_0218adac(void*, int, int);
#else
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* self, int flag);

// USA: func_ov012_02186e38
extern "C" ARM void func_ov012_02186e38(char* self) {
	unsigned char state = *(unsigned char*)(self + Enum_ov012_02186e38_4976);
	if (state == 0) {
		*(unsigned char*)(self + Enum_ov012_02186e38_5024) = 0;
		int v = func_ov012_0218432c(0);
		*(int*)(self + kChoiceBOffset) = v;
		if (v < 0) *(int*)(self + kChoiceBOffset) = 0;

		func_0205de24((struct Struct0205de24*)(self + kWindowOffset), 0, 3);
		func_ov023_021e6e60(self);
		func_ov012_02189a78(self);
		(*(unsigned char*)(self + Enum_ov012_02186e38_4976))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + Enum_ov012_02186e38_5024) = 1;
	*(int*)(self + kChoiceBOffset) = Window_GetSelectedIndex((struct Struct_0205c570*)(self + kWindowOffset));
	if (func_ov023_021e6448(self) != 0) {
		*(int*)(self + kChoiceBOffset) = Window_GetSelectedIndex((struct Struct_0205c570*)(self + kWindowOffset));
	}

	if (func_ov023_021e6de4(self) != 0) {
		SePlayer_Play(&g_sePlayer, 1, 0);
		void* battleStruct = GameState::GetInstance();
		int val = *(int*)(self + kChoiceBOffset);
		void* name = func_02072a68((struct TableA68*)(self + Enum_ov012_02186e38_4924), (short)(val + Enum_ov012_02186e38_10310));
		Struct_ov012_02186e38* profile = inline_ov012_02186e38((GameState*)battleStruct);

		memset(self + Enum_ov012_02186e38_5184, 0, 0x40);
		int len = strlen((char*)name);
		memcpy(self + Enum_ov012_02186e38_5184, name, len);

		profile->title = *(unsigned int*)(self + kChoiceBOffset) + Enum_ov012_02186e38_310;

#if defined(jpn)
		func_ov012_0218adac(self, 0, -1);
#else
		func_ov012_0218adac(self, 0, -1, 0);
#endif
		func_ov012_0218930c(self, 0);
		return;
	}

	if (func_ov023_021e6e20((struct Struct_ov012_02186a7c*)self) == 0) return;
	func_ov012_0218930c(self, 1);
}
