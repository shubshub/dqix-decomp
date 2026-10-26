#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
enum {
    Enum_ov012_02186fd8_4976 = 0x1340,
    Enum_ov012_02186fd8_5024 = 0x1368,
    kWindowOffset = 0x90,
    Enum_ov012_02186fd8_5088 = 0x1438,
    Enum_ov012_02186fd8_4924 = 0x1314,
    Enum_ov012_02186fd8_22172 = 0x543c,
    Enum_ov012_02186fd8_5184 = 0x1498
};
#else
enum {
    Enum_ov012_02186fd8_4976 = 0x1370,
    Enum_ov012_02186fd8_5024 = 0x13a0,
    kWindowOffset = 0xac,
    Enum_ov012_02186fd8_5088 = 0x13e0,
    Enum_ov012_02186fd8_4924 = 0x133c,
    Enum_ov012_02186fd8_22172 = 0x569c,
    Enum_ov012_02186fd8_5184 = 0x1440
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
    return (Struct_ov012_02186e38*)((char*)state + Enum_ov012_02186fd8_22172);
}

extern "C" int func_ov012_0218432c(int a);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" void func_ov012_02189c44(char* self);
struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);
#if defined(jpn)
extern "C" void func_ov012_0218adac(void*, int, int);
#else
extern "C" void func_ov012_0218adac(void* obj, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* obj, int a);
struct Struct_ov012_02186a7c;
extern "C" int func_ov023_021e6e20(struct Struct_ov012_02186a7c* obj);
extern int g_sePlayer;

// USA: func_ov012_02186fd8
extern "C" ARM void func_ov012_02186fd8(char* base) {
    unsigned char state = *(unsigned char*)(base + Enum_ov012_02186fd8_4976);
    if (state == 0) {
        *(unsigned char*)(base + Enum_ov012_02186fd8_5024) = 0;
        int ret = func_ov012_0218432c(1);
        *(int*)(base + Enum_ov012_02186fd8_5088) = ret;
        if (ret < 0) {
            *(int*)(base + Enum_ov012_02186fd8_5088) = 0;
        }

        func_0205de24((struct Struct0205de24*)(base + kWindowOffset), 0, 3);
        func_ov023_021e6e60(base);
        func_ov012_02189c44(base);

        (*(unsigned char*)(base + Enum_ov012_02186fd8_4976))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + Enum_ov012_02186fd8_5024) = 1;
    int sum = Window_GetSelectedIndex((struct Struct_0205c570*)(base + kWindowOffset));
    *(int*)(base + Enum_ov012_02186fd8_5088) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);

        GameState* bs = GameState::GetInstance();
        int key = (short)(*(int*)(base + Enum_ov012_02186fd8_5088) + 0x27d8);
        void* name = func_02072a68((struct TableA68*)(base + Enum_ov012_02186fd8_4924), key);
        Struct_ov012_02186e38* profile = inline_ov012_02186e38(bs);

        memset(base + Enum_ov012_02186fd8_5184, 0, 0x40);
        memcpy(base + Enum_ov012_02186fd8_5184, name, strlen((char*)name));

        profile->title = *(int*)(base + Enum_ov012_02186fd8_5088) + 0xc8;

#if defined(jpn)
        func_ov012_0218adac(base, 0, -1);
#else
        func_ov012_0218adac(base, 0, -1, 0);
#endif
        func_ov012_0218930c(base, 0);
    } else {
        if (func_ov023_021e6e20((struct Struct_ov012_02186a7c*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
