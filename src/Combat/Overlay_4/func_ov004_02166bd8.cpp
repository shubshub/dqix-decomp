#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_ov004_02153e20 {
    char unknown_0_[0x5c];
    short unknown_5c_;
    short unknown_5e_;
};

struct Struct_ov004_02166bd8 {
    char unknown_0_[0x3a];
    unsigned char unknown_3a_;
    char unknown_3b_[9];
    short unknown_44_;
    short unknown_46_;
};

struct Struct_02065990_3 {
    char unknown_0_[0xa8];
    unsigned char unknown_a8_[1];
};

struct Struct_ov004_02166bd8_2 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 1;
    unsigned short unknown_2_3_ : 1;
    unsigned short unknown_2_4_ : 1;
    unsigned short unknown_2_5_ : 11;
    char unknown_4_[4];
    Struct_ov004_02166bd8_2* unknown_8_;
};

struct Struct_ov004_02166bd8_3 {
    int unknown_0_;
    const char* unknown_4_;
};

struct Struct_0208bf78_5 {
    int unknown_0_[4];
};

struct Struct_ov004_02166bd8_4 {
    char unknown_0_[8];
    Struct_ov004_02166bd8_2* unknown_8_;
    Struct_0208bf78_5 unknown_c_;
};

struct Struct_ov004_0217101c_3 {
    Struct_ov004_02166bd8_4* unknown_0_;
    char** unknown_4_;
};

extern "C" void* Scenario_GetInstance();
void DispatchStateTransitions_02166608(void*);
extern "C" Grid021f9b30* func_ov023_021f6524(void*, int);
GetTableByteOrFFData* GetGlobal02109418_02094d6c();
void MessageSystem_GetInstance();
extern "C" void func_ov023_021f65d4(void*, int, int);
Found0208d994* FindElementByKey0208d994(List0208d994*, int);
extern "C" void _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30*, unsigned short, unsigned int, unsigned int);
Node02165ea4* SetFieldIfType1_02165ea4_02165ea4(void*, int, int);
struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08*);
unsigned int GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int TestBitInByteArray02096100(int, unsigned char*, int);
const char* Lookup4Entry_021f63ac(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
void AppendXTag_02041a28(char*, int);
void Text_Append(char*, const char*);
extern "C" void func_ov023_021f63f8(void*, int, char*, int);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" void func_ov023_021f9d14(Struct_ov004_02153e20*, void*);
extern "C" void func_ov023_021f6630(int, int, short, short);

extern Struct_ov004_0217101c_3 data_ov004_0217101c;

// USA: func_ov004_02166bd8
extern "C" ARM int func_ov004_02166bd8(void* a) {
    Scenario_GetInstance();
    DispatchStateTransitions_02166608(a);
    short page = 0;
    short field5e = 1;
    Grid021f9b30* grid = func_ov023_021f6524(a, 0x5b);
    if (grid) {
        page = grid->page;
        field5e = grid->field5e;
    }
    Struct_ov004_02166bd8_2* var3;
    int var4 = 0xbe;
    int var5 = 0xc8;
    int var6 = 0xd2;
    int var7 = 0xdc;
    Struct_ov004_02166bd8_4* var8 = data_ov004_0217101c.unknown_0_;
    var3 = var8->unknown_8_;
    short var9 = var0 * 8;
    while (var3 && var9) {
        var9--;
        var3 = var3->unknown_8_;
    }
    GetTableByteOrFFData* table = GetGlobal02109418_02094d6c();
    MessageSystem_GetInstance();
    unsigned char* bits = table->bits;
    for (short i = 0; i < 8; idA++, idB++, idC++, idD++, i++) {
        int shown = 0;
        func_ov023_021f65d4(a, idA, 8);
        func_ov023_021f65d4(a, idB, 8);
        func_ov023_021f65d4(a, idC, 8);
        func_ov023_021f65d4(a, idD, 8);
        if (entry) {
            Found0208d994* found = FindElementByKey0208d994(&lists->list, entry->key);
            if (found) {
                shown = 1;
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, idA, (unsigned short)i, 0);
                int extra = 0;
                if (!entry->skipNode) {
                    Node02165ea4* node = SetFieldIfType1_02165ea4_02165ea4(a, idD, 6);
                    node->field44 = 4;
                    node->field46 = 0;
                    node->hidden = (i != 0);
                    if (i >= 1 && i <= 3) {
                        int lang = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
                        int mode = 2;
                        switch (lang) {
                        case 4:
                            var18 = 3;
                            break;
                        case 3:
                            var18 = 1;
                            break;
                        case 5:
                            var18 = 3;
                            break;
                        }
                        var16->unknown_46_ = var18;
                    }
                    var15 = 1;
                }
                unsigned int var19 = func_020965ac(var10, (unsigned char)var3->unknown_0_);
                int var20 = func_02096100((int)var10, var11 + 0x400, var19);
                int var21 = 10;
                const char* var22 = var14->unknown_4_;
                switch (var3->unknown_2_0_) {
                case 0:
                case 1:
                    if (!var20)
                        var22 = func_ov023_021f63ac(arg0, 3, 10);
                    break;
                case 2:
                    var21 = 11;
                    break;
                case 3:
                    var21 = 12;
                    break;
                }
                char* buf = data_ov004_0217101c.buffers[i];
                memset(buf, 0, 0x80);
                AppendXTag_02041a28(buf, 0x1c);
                Text_Append(buf, entry->name);
                AppendXTag_02041a28(buf, 0x2e);
                if (text)
                    Text_Append(buf, text);
                func_ov023_021f63f8(a, idA, buf, 0xf);
                SetFieldIfType1_02165ea4_02165ea4(a, idC, type)->hidden = 0;
                ClearNodeMaskById_021f6600(a, idA, 8);
                ClearNodeMaskById_021f6600(a, idC, 8);
                if (extra)
                    ClearNodeMaskById_021f6600(a, idD, 8);
            }
            var3 = var3->unknown_8_;
        }
        if (!var13)
            func_ov023_021f9b30(var2, 0, (unsigned short)var12, 0);
    }
    func_ov023_021f9d14(var2, arg0);
    func_ov023_021f6630((int)arg0, 0x17, var0, var1);
    return 0;
}
