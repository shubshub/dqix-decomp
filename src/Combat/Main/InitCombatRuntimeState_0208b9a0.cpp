#include <globaldefs.h>

struct Struct020dfc40;
ARM void KeyTable_Reset(struct Struct020dfc40*);

struct StreamHeader0208d82c;
ARM void InitStreamHeader0208d82c(struct StreamHeader0208d82c*);

struct BackgroundGraphics;
ARM void Background_Init(struct BackgroundGraphics*);

ARM void SpriteContext_Init(char*);

// USA: func_0208b9a0  (semantic: InitCombatRuntimeState_0208b9a0)
extern "C" ARM void func_0208b9a0(char* obj, unsigned char flag) {
    *(int*)(obj + 0x0) = 0;
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x4));
    InitStreamHeader0208d82c((struct StreamHeader0208d82c*)(obj + 0x1c));
    *(unsigned char*)(obj + 0x3c) = 0;
    *(unsigned char*)(obj + 0x3d) = 0;
    Background_Init((struct BackgroundGraphics*)(obj + 0x40));
    SpriteContext_Init(obj + 0x60);
    *(int*)(obj + 0xb4) = 0;
    *(int*)(obj + 0xb8) = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
    *(int*)(obj + 0xbc) = -1;
    *(int*)(obj + 0xc0) = -1;
    *(float*)(obj + 0xcc) = 1.0f;
    *(int*)(obj + 0xc8) = 0;
    *(short*)(obj + 0xd2) = -1;
    *(unsigned char*)(obj + 0xd4) = 0;
    *(unsigned char*)(obj + 0xd5) = 0;
    *(unsigned char*)(obj + 0xd6) = 0;
    *(unsigned char*)(obj + 0xd7) = 0;
    *(unsigned char*)(obj + 0xd8) = 1;
    *(unsigned char*)(obj + 0xd9) = 0;
    *(short*)(obj + 0xda) = 0;
    *(unsigned char*)(obj + 0xdc) = 1;
    *(unsigned char*)(obj + 0xdd) = 0;
    *(unsigned char*)(obj + 0xde) = 0;
    *(unsigned char*)(obj + 0xdf) = flag;
    *(unsigned char*)(obj + 0xe0) = 0;
}
