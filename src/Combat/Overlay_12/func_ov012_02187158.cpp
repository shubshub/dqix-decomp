#if defined(jpn)
#define R(j,u) (j)
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_ov012_0218432c(int a);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" int func_ov023_021e6448(void* obj);
extern "C" int func_ov023_021e6de4(char* obj);
struct Struct_ov012_02186a7c { char pad[R(0x90,0xac)]; };
extern "C" int func_ov023_021e6e20(struct Struct_ov012_02186a7c* obj);
#if defined(jpn)
extern "C" void func_ov012_0218adac(void* self, int a, int b);
#else
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* self, int a);
#if defined(jpn)
extern "C" void func_ov012_02189d68(char* base);
#else
extern "C" void func_ov012_02189d68(char* base);
#endif

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;
struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

struct Struct_ov012_02187158 { unsigned short count : 5; unsigned short rest : 11; };

// USA: func_ov012_02187158
extern "C" ARM void func_ov012_02187158(char* base) {
    int state = *(unsigned char*)(base + R(0x1340,0x1370));
    if (state == 0) {
        *(unsigned char*)(base + R(0x1368,0x13a0)) = 0;
        *(int*)(base + R(0x143c,0x13e4)) = 0;
        int var1 = func_ov012_0218432c(2);
        int i;
        for (i = 0; i < ((struct Struct_ov012_02187158*)(base + R(0x1400,0x1300) + R(0x1c,0xc4)))->count; i++) {
            if (var1 == (*(signed char**)(base + 0x1000 + R(0x418,0x3c0)))[i]) {
                *(int*)(base + 0x1000 + R(0x43c,0x3e4)) = i;
                break;
            }
        }
        func_0205de24((struct Struct0205de24*)(base + R(0x90,0xac)), 0, 3);
        func_ov023_021e6e60(base);
        func_ov012_02189d68(base);
        (*(unsigned char*)(base + R(0x1340,0x1370)))++;
        return;
    }
    if (state != 1) return;
    *(unsigned char*)(base + R(0x1368,0x13a0)) = 1;
    *(int*)(base + R(0x143c,0x13e4)) = Window_GetSelectedIndex((struct Struct_0205c570*)(base + R(0x90,0xac)));
    if (func_ov023_021e6448(base)) {
        *(int*)(base + R(0x143c,0x13e4)) = Window_GetSelectedIndex((struct Struct_0205c570*)(base + R(0x90,0xac)));
    }
    if (func_ov023_021e6de4(base)) {
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
        GameState* bs = GameState::GetInstance();
        int val = (*(signed char**)(base + 0x1000 + R(0x418,0x3c0)))[*(int*)(base + 0x1000 + R(0x43c,0x3e4))];
        short key = (short)(val + 0x2710);
        char* name = (char*)func_02072a68((struct TableA68*)(base + R(0x1314,0x133c)), key);
        char* p = (char*)bs + R(0x3c,0x29c) + 0x5400;
        memset(base + R(0x1498,0x1440), 0, 0x40);
        memcpy(base + R(0x1498,0x1440), name, strlen(name));
        int v = *(int*)(p + 0x4);
        *(int*)(p + 0x4) = (v & 0xfff801ff) | ((val & 0x3ff) << 9);
#if defined(jpn)
        func_ov012_0218adac(base, 0, -1);
#else
        func_ov012_0218adac(base, 0, -1, 0);
#endif
        func_ov012_0218930c(base, 0);
        return;
    }
    if (func_ov023_021e6e20((struct Struct_ov012_02186a7c*)base)) {
        func_ov012_0218930c(base, 1);
    }
}
