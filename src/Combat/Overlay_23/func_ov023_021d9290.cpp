struct Container020e0310;
struct Struct_ov023_021d9290_3 {
    unsigned char id;
    unsigned char vocation;
    unsigned char level;
    unsigned char unknown_3_;
    int experience;
#if defined(jpn)
    char name[0xc];
#else
    char name[0x30];
#endif
};

struct Struct_ov023_021d9290_2 {
    Container020e0310* texts;
    char unknown_4_[0xc0 - 4];
    short width;
    short height;
    char unknown_c4_[0xdc - 0xc4];
    int unknown_dc_[4];
    char unknown_ec_[0x119 - 0xec];
    unsigned char rows;
    char unknown_11a_[0x120 - 0x11a];
    Struct_ov023_021d9290_3* members;
    unsigned char memberIds[4];
    unsigned char memberCount;
};

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"


struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int Font_GetTextWidth(void*, int);
extern "C" int func_02041a28(char*, int);
extern "C" int func_02041b00(char*, int);
extern "C" int func_02041fac(char*, int, int);
extern "C" void __clear(void*, int);
extern "C" void* func_ov023_021d994c(void*, int);
extern "C" int Text_Append(char*, const char*);
extern "C" void func_02046380(int);
extern "C" ARM void NameText_InitFromPartyMember(void*, int);
extern "C" int func_020426a4(int, int);
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct*, int, int);
extern "C" void MessageSystem_FormatText(int, int, void*, void*, int, int, int);
extern "C" int func_02041a90(char*, int, int);
extern "C" int sprintf(char*, const char*, ...);

struct Struct_ov023_021d9290 {
    void* f0;
    void* f4;
    int f8;
};

// USA: func_ov023_021d9290
extern "C" ARM void func_ov023_021d9290(char* obj, char* buf, unsigned char count) {
    Struct_ov023_021d9290_2* window = (Struct_ov023_021d9290_2*)obj;
    if (!buf) return;

    GameState::GetInstance();
    int g = MessageSystem_GetInstance();

    char* fieldStr = (char*)KeyTable_Get(window->texts, 0x75f8);
    int len = Font_GetTextWidth(fieldStr, 0);
    func_02041a28(buf, (0xc0 - len) >> 1);
    func_02041b00(buf, 1);
    func_02041fac(buf, (int)fieldStr, 0x10);

    unsigned char* idArr = window->memberIds;
    int a2 = window->height;
    int b = window->rows;
    int var7 = window->memberCount;
    int found = 0;
    signed char adj = (signed char)(((a2 << 3) - (b * 10 + 0x1d)) / (b - 1));
    int var10 = a2 << 3;

    if (window->members == NULL) return;

    char* fieldStr2 = (char*)KeyTable_Get(window->texts, 0x75f9);
    int i;
    for (i = 0; i < var7; i++) {
        if (window->unknown_dc_[i] != 0 && count != 0) {
            int id = idArr[i];
            Struct_ov023_021d9290_3* entry = (Struct_ov023_021d9290_3*)func_ov023_021d994c(obj, id);
            if (entry != NULL) {
                char buf1[0x100];
                char buf2[0x100];
                __clear(buf1, 0x100);
                __clear(buf2, 0x100);
                if (found != 0) {
                    char* fieldStr0 = (char*)KeyTable_Get(window->texts, 0);
                    Text_Append(buf, fieldStr0);
                    func_02041b00(buf, adj);
                }
                func_02046380(g);
                struct Struct_ov023_021d9290 local;
                NameText_InitFromPartyMember(&local, id);
                void* val = entry->name;
                local.f0 = val;
                local.f4 = val;
                *(void**)(g + 0x10) = &local;
                int var20 = func_020426a4(8, window->unknown_dc_[i]);
                sprintf(buf2, fieldStr2, 0x94 - var20);
                func_020465c0((struct StoreStruct*)g, 1, window->unknown_dc_[i]);
                MessageSystem_FormatText(g, 0xa, buf2, buf1, 0x100, 0, 0);
                Text_Append(buf, buf1);
                found = 1;
                count = count - 1;
            }
        }
    }

    if (found == 0) {
        char* fieldStr3 = (char*)KeyTable_Get(window->texts, 0x75fa);
        int len3 = Font_GetTextWidth(fieldStr3, 0);
        len3 = 0xc0 - len3;
        func_02041a90(buf, len3 >> 1, (var10 - 0x1a) / 2 + 0x10);
        Text_Append(buf, fieldStr3);
    }
}
