#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov012_0218a9ec_5108 = 0x144c, Enum_ov012_0218a9ec_4924 = 0x1314, kSeparatorOffset = 0x1348, Enum_ov012_0218a9ec_22172 = 0x543c };
#else
enum { Enum_ov012_0218a9ec_5108 = 0x13f4, Enum_ov012_0218a9ec_4924 = 0x133c, kSeparatorOffset = 0x1378, Enum_ov012_0218a9ec_22172 = 0x569c };
#endif

struct Struct_02072a68 {
    short key;
    void* value;
};

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};

struct Struct_ov012_0218a9ec {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};

extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

// USA: func_ov012_0218a9ec
extern "C" ARM void func_ov012_0218a9ec(unsigned char* self, char* dst, int c) {
    if (dst == 0) return;

    int cursor = *(int*)(self + Enum_ov012_0218a9ec_5108) & 7;
    Struct_ov012_0218a9ec* profile =
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
        void* name = func_02072a68((struct TableA68*)(self + Enum_ov012_0218a9ec_4924),
                                    (short)(((short)profile->female) + i * 2 + 0x7530));
        Text_AppendNTag(dst, i, (const char*)name);
    }
}
