#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_ov004_02153e20 {
    char pad0[0x5c];
    short page;
    short unknown_5e_;
};

struct Struct_ov004_02166bd8 {
    char pad0[0x3a];
    unsigned char hidden;
    char unknown_3b_[9];
    short field44;
    short unknown_46_;
};

struct Struct_02065990_3 {
    char pad0[0xa8];
    unsigned char bits[1];
};

struct Struct_ov004_02166bd8_2 {
    short key;
    unsigned short state : 2;
    unsigned short flag2 : 1;
    unsigned short unknown_2_3_ : 1;
    unsigned short unknown_2_4_ : 1;
    unsigned short reserved : 11;
    char name[4];
    Struct_ov004_02166bd8_2* next;
};

struct Struct_ov004_02166bd8_3 {
    int field0;
    const char* text;
};

struct Struct_0208bf78_5 {
    int pad[4];
};

struct Struct_ov004_02166bd8_4 {
    char pad0[8];
    Struct_ov004_02166bd8_2* head;
    Struct_0208bf78_5 list;
};

struct Struct_ov004_0217101c_3 {
    Struct_ov004_02166bd8_4* lists;
    char** buffers;
};

extern "C" void* Scenario_GetInstance();
extern "C" void func_ov004_02166608(void*);
extern "C" Struct_ov004_02153e20* func_ov023_021f6524(void*, int);
extern "C" Struct_02065990_3* func_02094d6c();
extern "C" void MessageSystem_GetInstance();
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" Struct_ov004_02166bd8_3* func_0208d994(Struct_0208bf78_5*, int);
extern "C" void func_ov023_021f9b30(Struct_ov004_02153e20*, unsigned short, unsigned int, unsigned int);
extern "C" Struct_ov004_02166bd8* func_ov004_02165ea4(void*, int, int);
struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" unsigned int func_020965ac(Struct_02065990_3*, unsigned char);
extern "C" int func_02096100(int, unsigned char*, int);
extern "C" const char* func_ov023_021f63ac(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_02041a28(char*, int);
extern "C" void Text_Append(char*, const char*);
extern "C" void func_ov023_021f63f8(void*, int, char*, int);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" void func_ov023_021f9d14(Struct_ov004_02153e20*, void*);
extern "C" void func_ov023_021f6630(int, int, short, short);

extern Struct_ov004_0217101c_3 data_ov004_0217101c;

// USA: func_ov004_02166bd8
extern "C" ARM int func_ov004_02166bd8(void* a) {
    Scenario_GetInstance();
    func_ov004_02166608(a);
    short page = 0;
    short var1 = 1;
    Struct_ov004_02153e20* grid = func_ov023_021f6524(a, 0x5b);
    if (grid) {
        page = grid->page;
        var1 = grid->unknown_5e_;
    }
    Struct_ov004_02166bd8_2* entry;
    int idA = 0xbe;
    int var5 = 0xc8;
    int var6 = 0xd2;
    int var7 = 0xdc;
    Struct_ov004_02166bd8_4* lists = data_ov004_0217101c.lists;
    entry = lists->head;
    short var9 = page * 8;
    while (entry && var9) {
        var9--;
        entry = entry->next;
    }
    Struct_02065990_3* table = func_02094d6c();
    MessageSystem_GetInstance();
    unsigned char* bits = table->bits;
    for (short i = 0; i < 8; idA++, var5++, var6++, var7++, i++) {
        int shown = 0;
        func_ov023_021f65d4(a, idA, 8);
        func_ov023_021f65d4(a, var5, 8);
        func_ov023_021f65d4(a, var6, 8);
        func_ov023_021f65d4(a, var7, 8);
        if (entry) {
            Struct_ov004_02166bd8_3* found = func_0208d994(&lists->list, entry->key);
            if (found) {
                shown = 1;
                func_ov023_021f9b30(grid, idA, (unsigned short)i, 0);
                int extra = 0;
                if (!entry->unknown_2_4_) {
                    Struct_ov004_02166bd8* node = func_ov004_02165ea4(a, var7, 6);
                    node->field44 = 4;
                    node->unknown_46_ = 0;
                    node->hidden = (i != 0);
                    if (i >= 1 && i <= 3) {
                        int lang = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
                        int mode = 2;
                        switch (lang) {
                        case 4:
                            mode = 3;
                            break;
                        case 3:
                            mode = 1;
                            break;
                        case 5:
                            mode = 3;
                            break;
                        }
                        node->unknown_46_ = mode;
                    }
                    extra = 1;
                }
                unsigned int id = func_020965ac(table, (unsigned char)entry->key);
                int seen = func_02096100((int)table, bits + 0x400, id);
                int type = 10;
                const char* text = found->text;
                switch (entry->state) {
                case 0:
                case 1:
                    if (!seen)
                        text = func_ov023_021f63ac(a, 3, 10);
                    break;
                case 2:
                    type = 11;
                    break;
                case 3:
                    type = 12;
                    break;
                }
                char* buf = data_ov004_0217101c.buffers[i];
                memset(buf, 0, 0x80);
                func_02041a28(buf, 0x1c);
                Text_Append(buf, entry->name);
                func_02041a28(buf, 0x2e);
                if (text)
                    Text_Append(buf, text);
                func_ov023_021f63f8(a, idA, buf, 0xf);
                func_ov004_02165ea4(a, var6, type)->hidden = 0;
                func_ov023_021f6600(a, idA, 8);
                func_ov023_021f6600(a, var6, 8);
                if (extra)
                    func_ov023_021f6600(a, var7, 8);
            }
            entry = entry->next;
        }
        if (!shown)
            func_ov023_021f9b30(grid, 0, (unsigned short)i, 0);
    }
    func_ov023_021f9d14(grid, a);
    func_ov023_021f6630((int)a, 0x17, page, var1);
    return 0;
}
