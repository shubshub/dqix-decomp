#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02098f20(int arg0, int arg1, int arg2);

struct Struct_ov023_021fd72c { int v[12]; };
extern struct Struct_ov023_021fd72c data_ov023_021fd72c;

// USA: func_ov023_021e61f4
extern "C" ARM void func_ov023_021e61f4(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x1373, regionalOffset1=0x1454, regionalOffset2=0x1456, regionalOffset3=0x1457};
#else
 enum {regionalOffset0=0x13ab, regionalOffset1=0x13fc, regionalOffset2=0x13fe, regionalOffset3=0x13ff};
#endif
    struct Struct_ov023_021fd72c var0 = data_ov023_021fd72c;
    char* base = (char*)obj;
    *(unsigned char*)(base + regionalOffset0) = 0;

    GameState::GetInstance();

    int age = func_02098f20(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2), *(unsigned char*)(base + regionalOffset3));
    if (age < 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x2;
    if (age > 0) *(unsigned char*)(base + regionalOffset0) |= 0x1;

    if (*(unsigned char*)(base + regionalOffset2) < 12) {
        int var3 = func_02098f20(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2) + 1, *(unsigned char*)(base + regionalOffset3));
        if (var3 >= 0) *(unsigned char*)(base + regionalOffset0) |= 0x4;
    }
    if (*(unsigned char*)(base + regionalOffset2) > 1) {
        int var4 = func_02098f20(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2) - 1, *(unsigned char*)(base + regionalOffset3));
        if (var4 <= 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x8;
    }

    if (*(unsigned short*)(base + regionalOffset1) % 4 == 0) var0.v[1] = 29;
    unsigned char month = *(unsigned char*)(base + regionalOffset2);
    unsigned char day = *(unsigned char*)(base + regionalOffset3);
    if (day < var0.v[month - 1]) {
        int var7 = func_02098f20(*(unsigned short*)(base + regionalOffset1), month, day + 1);
        if (var7 >= 0) *(unsigned char*)(base + regionalOffset0) |= 0x10;
    }

    if (*(unsigned char*)(base + regionalOffset3) > 1) {
        int var8 = func_02098f20(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2), *(unsigned char*)(base + regionalOffset3) - 1);
        if (var8 <= 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x20;
    }
}
