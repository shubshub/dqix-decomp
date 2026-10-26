#include <globaldefs.h>

#if defined(jpn)
extern "C" int func_0204234c(char*, int);
extern "C" int func_020423d4(char*, int, int, int, int);
#endif

struct Struct_ov013_021846a0_2 {
#if defined(jpn)
    char unknown0[0x5ac];
#else
    char unknown0[0x620];
#endif
    char texts[0x18];
    unsigned char unknown_638_[4];
    unsigned char state;
    unsigned char unknown_63d_;
    unsigned char step;
    bool stateChanged;
    bool subScreen;
    unsigned int ticks;
    int windowInput;
#if !defined(jpn)
    int unknown_64c_;
#endif
    int task;
    void* unknown_654_;
    char* text;
    int selectedSkill;
    int confirmationChoice;
    unsigned char unknown_664_[4];
    int unknown_668_;
    int unknown_66c_;
    int unknown_670_;
    int skillPoints[5];
    int unknown_688_[5];
    unsigned char unknown_69c_[5];
    char unknown_6a1_[8];
    unsigned char unknown_6a9_[5];
};

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void* __clear(void* dst, int count);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int func_02041a28(char* dst, int x);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int func_02041fac(char* buf, int a, int b);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_AppendPaletteTag(char* dst, int palette);
extern "C" int func_02041a5c(char* dst, int y);
extern "C" int func_02041cc0(char* dst, int a1);
extern "C" int func_02041d48(char* dst, int a1, int a2, int a3, int a4);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_ov013_02185424
extern "C" ARM void func_ov013_02185424(Struct_ov013_021846a0_2* menu, char* out) {
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
    func_02041a28(buf, (0xf0 - len) >> 1);
    Text_Append(buf, str);
    func_02041fac(out, (int)buf, 0x10);

#endif

    if (menu->windowInput == 2) {
        Text_AppendFrameTag(out, menu->selectedSkill, 8, 3, 6, 2);
    }
    Text_AppendCursorTag(out, menu->selectedSkill);

    for (unsigned char id = 0; id < 5; id++) {
        if (menu->unknown_69c_[id] == 0) {
            Text_AppendPaletteTag(out, 0xf);
        } else {
            Text_AppendPaletteTag(out, 3);
        }
        int key = (short)(menu->unknown_6a9_[id] + 0x64);
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
    func_02041a5c(out, 0x15);
#endif

#if defined(jpn)
    for (int i = 0; i < 5; i++) {
        int fmt;
        if (menu->unknown_69c_[i] == 1) {
            fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2712);
            sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->unknown_688_[i], menu->skillPoints[i]);
        } else if (i == menu->selectedSkill) {
            if (menu->unknown_688_[i] == 0x64) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->unknown_688_[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else if (menu->unknown_688_[i] >= 0xa) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->unknown_688_[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else if (menu->unknown_688_[i] != 0) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->unknown_688_[i], i + 0xa, menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2714);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, i + 5, menu->unknown_688_[i], i + 0xa, menu->skillPoints[i]);
            }
        } else {
            if (menu->unknown_688_[i] == 0x64) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->unknown_688_[i], menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else if (menu->unknown_688_[i] >= 0xa) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->unknown_688_[i], menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else if (menu->unknown_688_[i] != 0) {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->unknown_688_[i], menu->skillPoints[i], menu->skillPoints[i] + menu->unknown_688_[i]);
            }
            else {
                fmt = KeyTable_Get((Container020e0310*)menu->texts, 0x2716);
                sprintf(buf, (const char*)fmt, i * 0xd + 0x16, menu->unknown_688_[i], menu->skillPoints[i]);
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
        int var16 = menu->skillPoints[i];
        int var17 = menu->unknown_688_[i];
        int fmt;
        if (menu->unknown_69c_[i] == 1) {
            fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2712);
            sprintf(buf, (const char*)fmt, n + 0x16, var17, var16);
        } else if (i == menu->selectedSkill) {
            if (var17 == 0) {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2714);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, var17, 0xb, var16);
            } else {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2713);
                sprintf(buf, (const char*)fmt, n + 0x16, 0xa, var17, 0xb, var16, var16 + var17);
            }
        } else {
            if (var17 == 0) {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2716);
                sprintf(buf, (const char*)fmt, n + 0x16, var17, var16);
            } else {
                fmt = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2715);
                sprintf(buf, (const char*)fmt, n + 0x16, var17, var16, var16 + var17);
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
    func_02041cc0(out, 0x57);
    func_02041d48(out, 0x7fff, 0x5a, 0x10, 0x57);
#endif

    int fmtEnd = KeyTable_Get((struct Container020e0310*)menu->texts, 0x2717);
    sprintf(buf, (const char*)fmtEnd, menu->unknown_66c_);
    Text_Append(out, buf);
}
