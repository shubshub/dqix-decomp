#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov012_0218a9ec_5108 = 0x144c, Enum_ov012_0218a9ec_4924 = 0x1314, Enum_ov012_0218a9ec_4984 = 0x1348, Enum_ov012_0218a9ec_22172 = 0x543c };
#else
enum { Enum_ov012_0218a9ec_5108 = 0x13f4, Enum_ov012_0218a9ec_4924 = 0x133c, Enum_ov012_0218a9ec_4984 = 0x1378, Enum_ov012_0218a9ec_22172 = 0x569c };
#endif

struct Struct_02072a68 {
    short unknown_0_;
    void* unknown_4_;
};

struct Struct_02072a68_2 {
    struct Struct_02072a68* unknown_0_;
    short unknown_4_;
};

struct Struct_ov012_0218a9ec {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);

// USA: func_ov012_0218a9ec
extern "C" ARM void func_ov012_0218a9ec(unsigned char* arg0, char* arg1, int arg2) {
    if (arg1 == 0) return;

    int var0 = *(int*)(arg0 + Enum_ov012_0218a9ec_5108) & 7;
    Struct_ov012_0218a9ec* var1 =
        (Struct_ov012_0218a9ec*)((char*)GameState::GetInstance() + Enum_ov012_0218a9ec_22172);

    if (c != 0) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    int i;
    for (i = 0; i < 8; i++) {
        if (i != 0) {
            Text_Append(dst, *(char**)(self + kSeparatorOffset));
        }
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + kStringsOffset),
                                    (short)(((short)profile->female) + i * 2 + 0x7530));
        Text_AppendNTag(dst, i, (const char*)name);
    }
}
