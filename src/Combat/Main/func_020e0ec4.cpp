#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02000c9c_8;

struct Struct_020200c0_3 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};

void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
int GameState_GetLanguage(Struct0200fb08*);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee91a[];
extern short data_020ee92c[];
extern short data_020ee914[];
enum { Enum_020e0ec4_14 = 3 };
#else
extern short data_020ee8e8[];
extern short data_020ee8cc[];
extern short data_020ee904[];
extern const short data_020ee820[];
enum { Enum_020e0ec4_14 = 14 };
#endif
extern short data_020ee920[];

// JPN: func_020e2ad4
// USA: func_020e0ec4
extern "C" ARM void func_020e0ec4(void* arg0, void* arg1, int arg2, int) {
    struct Struct_020200c0_3 var0[Enum_020e0ec4_14];
#if defined(jpn)
    func_02023064(var0, Enum_020e0ec4_14, data_020ee920, data_020ee91a, data_020ee92c, data_020ee914);
#else
    func_02023064(var0, Enum_020e0ec4_14, data_020ee920, data_020ee8cc, data_020ee8e8, data_020ee904);
#endif
    struct Struct_020200c0_4 var1;
    func_0205b20c(&var1);
    func_0205b220(&var1, (int)arg1 + arg2);
    func_0205b228(&var1, (int)var0, Enum_020e0ec4_14);

#if defined(jpn)
    func_0205b234(&var1, (short)44, (short)18, (int)((char*)arg0 + 0x680), (unsigned char)10, (unsigned char)15);
#else
    int idx = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
    func_0205b234(&localObj, data_020ee820[idx], (short)6, (int)((char*)obj + 0x2ec + 0x400), (unsigned char)0xf, (unsigned char)0);
#endif
}
