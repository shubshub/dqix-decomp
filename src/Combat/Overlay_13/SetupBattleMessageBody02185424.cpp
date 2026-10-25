#include <globaldefs.h>

#if defined(jpn)
extern "C" int func_0204234c(char*, int);
extern "C" int func_020423d4(char*, int, int, int, int);
#endif

struct SkillPointMenu {
#if defined(jpn)
    char unknown0[0x5ac];
#else
    char unknown0[0x620];
#endif
    char texts[0x18];
    unsigned char unknownStateBytes[4];
    unsigned char state;
    unsigned char previousState;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int previousWindowInput;
#endif
    int task;
    void* canvasPixels;
    char* text;
    int selectedSkill;
    int confirmationChoice;
    unsigned char unknownAfterChoice[4];
    int availablePoints;
    int remainingPoints;
    int pointCap;
    int skillPoints[5];
    int allocatedPoints[5];
    unsigned char lockedSkills[5];
    char unknownAfterLocks[8];
    unsigned char skillIds[5];
};

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
int AppendXTag_02041a28(char* dst, int x);
int Text_Append(char* dst, const char* src);
int AppendFormatted02041fac(char* buf, int a, int b);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendPaletteTag(char* dst, int palette);
int AppendYTag_02041a5c(char* dst, int y);
int AppendLineTag02041cc0(char* dst, int a1);
int AppendLineYTag02041d48(char* dst, int a1, int a2, int a3, int a4);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_ov013_02185424  (semantic: SetupBattleMessageBody02185424)
extern "C" ARM void func_ov013_02185424(SkillPointMenu* menu, char* out) {
    char buf[0x100];
    __clear(buf, 0x100);

#if defined(jpn)
    int length = 0x10;
    int x = 0x78 - (int)(((float)length / 4.0f) * 12.0f);
    int heading = KeyTable_Get((Container020e0310*)menu->texts, 0x2718);
    sprintf(buf, (const char*)heading, x);
    Text_Append(out, buf);
#else
    char* str = (char*)KeyTable_Get((struct Container020e0310*)menu->texts, 0x2718);
    int len = Font_GetTextWidth(str, 0);
    AppendXTag_02041a28(buf, (0xf0 - len) >> 1);
    Text_Append(buf, str);
    AppendFormatted02041fac(out, (int)buf, 0x10);

#endif

    if (menu->windowInput == 2) {
        Text_AppendFrameTag(out, menu->selectedSkill, 8, 3, 6, 2);
    }
    Text_AppendCursorTag(out, menu->selectedSkill);

    for (unsigned char id = 0; id < 5; id++) {
        if (menu->lockedSkills[id] == 0) {
            Text_AppendPaletteTag(out, 0xf);
        } else {
            Text_AppendPaletteTag(out, 3);
        }
        int key = (short)(menu->skillIds[id] + 0x64);
        int v1 = KeyTable_Get((struct Container020e0310*)menu->texts, key);
        int fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2711);
        sprintf(buf, (const char*)fmt, id, v1);
        Text_Append(out, buf);
        if (id != 4) {
            int v3 = KeyTable_Get((struct Container020e0310*)menu->texts, 0);
            sprintf(buf, (const char*)v3);
        }
        Text_Append(out, buf);
    }

#if defined(jpn)
    Font_GetTextWidth(out, 0x15);
#else
    AppendYTag_02041a5c(out, 0x15);
#endif

#if defined(jpn)
    for (int i = 0; i < 5; i++) {
        int fmt;
        if (menu->lockedSkills[i] == 1) {
            fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2712);
            sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->allocatedPoints[i], menu->skillPoints[i]);
        } else if (i == menu->selectedSkill) {
            if (menu->allocatedPoints[i] == 0x64) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->allocatedPoints[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else if (menu->allocatedPoints[i] >= 0xa) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->allocatedPoints[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else if (menu->allocatedPoints[i] != 0) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->allocatedPoints[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2714);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->allocatedPoints[i], i + 0xa, menu->skillPoints[i]);
            }
        } else {
            if (menu->allocatedPoints[i] == 0x64) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->allocatedPoints[i], menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else if (menu->allocatedPoints[i] >= 0xa) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->allocatedPoints[i], menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else if (menu->allocatedPoints[i] != 0) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->allocatedPoints[i], menu->skillPoints[i], menu->skillPoints[i] + menu->allocatedPoints[i]);
            }
            else {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2716);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->allocatedPoints[i], menu->skillPoints[i]);
            }
        }
        Text_Append(out, buf);
        if (i != 4) {
            int v0 = KeyTable_Get((Container020e0310*)menu->texts, 0);
            Text_Append(out, (const char*)v0);
        }
    }

#else
    int n, i;
    for (i = 0; i < 5; i++) {
        n = i * 0xd;
        int v674 = menu->skillPoints[i];
        int v688 = menu->allocatedPoints[i];
        int fmt;
        if (menu->lockedSkills[i] == 1) {
            fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2712);
            sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
        } else if (i == menu->selectedSkill) {
            if (v688 == 0) {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2714);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674);
            } else {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, v688, 0xb, v674, v674 + v688);
            }
        } else {
            if (v688 == 0) {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2716);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674);
            } else {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, n + 0x16, v688, v674, v674 + v688);
            }
        }
        Text_Append(out, buf);
        if (i != 4) {
            int v0 = KeyTable_Get((struct Container020e0310*)menu->texts, 0);
            Text_Append(out, (const char*)v0);
        }
    }

#endif
#if defined(jpn)
    func_0204234c(out, 0x57);
    func_020423d4(out, 0x7fff, 0x4a, 0x10, 0x57);
#else
    AppendLineTag02041cc0(out, 0x57);
    AppendLineYTag02041d48(out, 0x7fff, 0x5a, 0x10, 0x57);
#endif

    int fmtEnd = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2717);
    sprintf(buf, (const char*)fmtEnd, menu->remainingPoints);
    Text_Append(out, buf);
}
