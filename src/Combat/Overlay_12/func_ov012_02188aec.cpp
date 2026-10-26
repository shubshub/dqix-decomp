#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov012_0218930c func_ov012_02189be8
enum {
    Enum_ov012_02188aec_22172 = 0x543c,
    Enum_ov012_02188aec_4976 = 0x1340,
    Enum_ov012_02188aec_4977 = 0x1341,
    Enum_ov012_02188aec_5024 = 0x1368,
    Enum_ov012_02188aec_5108 = 0x144c,
    kWindowOffset = 0x90
};
#else
enum {
    Enum_ov012_02188aec_22172 = 0x569c,
    Enum_ov012_02188aec_4976 = 0x1370,
    Enum_ov012_02188aec_4977 = 0x1371,
    Enum_ov012_02188aec_5024 = 0x13a0,
    Enum_ov012_02188aec_5108 = 0x13f4,
    kWindowOffset = 0xac
};
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov012_02188aec {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int remaining : 4;
};
struct Struct0205de24;
struct Struct_0205c570;
struct Struct_ov012_02186a7c;
struct SePlayer;
extern "C" void func_0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov012_0218a974(char*);
extern "C" void func_ov023_021e6e60(char*);
extern "C" int func_ov023_021e6de4(char*);
#if defined(jpn)
extern "C" void func_ov012_0218adac(char*, int, int);
#else
extern "C" void func_ov012_0218adac(char*, int, int, int);
#endif
extern "C" void func_ov012_0218930c(char*, int);
extern SePlayer g_sePlayer;

static inline Struct_ov012_02188aec* inline_ov012_02188aec(GameState* state) {
    return (Struct_ov012_02188aec*)((char*)state + Enum_ov012_02188aec_22172);
}

// USA: func_ov012_02188aec
extern "C" ARM void func_ov012_02188aec(char* self) {
    Struct_ov012_02188aec* profile = inline_ov012_02188aec(GameState::GetInstance());
    if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 0) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        return;
    } else if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 1) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        return;
    } else if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 2) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_5024)) = 0;
        (*(unsigned int*)(self + Enum_ov012_02188aec_5108)) = (profile->unknown_2_5_ - profile->female) / 2;
        func_0205de24((Struct0205de24*)(self + kWindowOffset), 0, 3);
        func_ov023_021e6e60(self);
        func_ov012_0218a974((char*)self);
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        return;
    } else if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 3) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_5024)) = 1;
        int selection = Window_GetSelectedIndex((Struct_0205c570*)(Struct0205de24*)(self + kWindowOffset));
        if ((*(unsigned int*)(self + Enum_ov012_02188aec_5108)) != selection) {
            (*(unsigned int*)(self + Enum_ov012_02188aec_5108)) = selection;
#if defined(jpn)
            func_ov012_0218adac(self, 0, ((*(unsigned int*)(self + Enum_ov012_02188aec_5108)) << 1) + profile->female);
#else
            func_ov012_0218adac(self, 0, ((*(unsigned int*)(self + Enum_ov012_02188aec_5108)) << 1) + profile->female, 0);
#endif
        }
        int var2 = 0;
        if (func_ov023_021e6de4(self)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            Struct_ov012_02188aec* current = inline_ov012_02188aec(GameState::GetInstance());
            current->unknown_2_5_ = ((*(unsigned int*)(self + Enum_ov012_02188aec_5108)) << 1) + current->female;
            current->unknown_3_3_ = 1;
            var2 = 1;
        } else if (func_ov023_021e6e20((Struct_ov012_02186a7c*)self)) {
            (*(unsigned int*)(self + Enum_ov012_02188aec_5108)) = (profile->unknown_2_5_ - profile->female) / 2;
            var2 = 1;
#if defined(jpn)
            func_ov012_0218adac(self, 0, -1);
#else
            func_ov012_0218adac(self, 0, -1, 0);
#endif
        }
        if (var2) (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        return;
    } else if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 4) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976))++;
        return;
    } else if ((*(unsigned char*)(self + Enum_ov012_02188aec_4976)) == 5) {
        (*(unsigned char*)(self + Enum_ov012_02188aec_4977)) = 1;
        (*(unsigned char*)(self + Enum_ov012_02188aec_4976)) = 1;
        func_ov012_0218930c(self, 1);
    }
}
