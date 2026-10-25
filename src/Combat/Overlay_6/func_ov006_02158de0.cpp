#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_02160010 data_ov006_02161364
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

class GameState {
public:
    static GameState* GetInstance();
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x454];
    unsigned short unknown_454_[8];
};

struct GameObject {
    char unknown_0_[R(0x144, 0x150)];
    Struct_ov005_0215840c_2* unknown_150_;
};

struct Struct_ov000_02182a74 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov006_02157a60 {
    char unknown_0_[R(0x40, 0x48)];
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
    char unknown_54_[0x20];
    char unknown_74_[R(0xd4, 0xd8)];
    char unknown_14c_[0xc];
};

Party* GameState_GetParty(GameState* gameState);
void* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int member);
short GetShortFromArray0xc10_0207c620(unsigned char* lists, unsigned int list);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* lists, unsigned int list);
unsigned char* GetPointerAt0xbf0_0207c60c(void* lists, unsigned int list);
extern "C" void func_ov006_02158fd8(AlchemyMenu* self, unsigned int category, short item, unsigned char count);
extern "C" void func_ov006_0215373c(void* ingredients, void* table);
extern "C" void func_ov006_021537c8(void* ingredients, short** items, unsigned char** counts, unsigned short* sizes);

extern "C" const unsigned short data_ov006_0215fffe[9];
extern "C" const int data_ov006_02160010[8];

// USA: func_ov006_02158de0
extern "C" ARM void func_ov006_02158de0(Struct_ov006_02157a60* arg0) {
    unsigned short var0[9];
    memcpy(var0, data_ov006_0215fffe, sizeof(var0));

    for (unsigned char var1 = 0; var1 < 9; var1++) {
        unsigned short var2 = var0[var1];
        memset(arg0->unknown_48_[var1], -1, var2 * 2);
        memset(arg0->unknown_4c_[var1], 0, var2);
        arg0->unknown_50_[var1] = 0;
    }
    GameState* gameState = GameState::GetInstance();
    Party* party = GameState_GetParty(gameState);
    for (unsigned short j = 0; j < 0x98; j++)
        func_ov006_02158fd8(self, 8, *(short*)((char*)party + 0xc + j * 2), *((char*)party + 0x13c + j));
    for (unsigned char k = 0; k < party->count_; k++) {
        GameObject* member = (GameObject*)GetCombatantWithFlag0x100_0200ff1c(gameState, party->members_[k]);
        if (member != 0) {
            unsigned short* items = member->partyData_->unk_454;
            for (unsigned char l = 0; l < 8; l++)
                func_ov006_02158fd8(self, 8, items[l], 1);
        }
    }
    for (unsigned char var10 = 0; var10 < 8; var10++) {
        int var11 = data_ov006_02160010[var10];
        short var12 = func_0207c620((unsigned char*)var4 + 0x1d4, var11);
        short* var13 = func_0207c5f8((unsigned char*)var4 + 0x1d4, var11);
        unsigned char* var14 = func_0207c60c((char*)var4 + 0x1d4, var11);
        for (short var15 = 0; var15 < var12; var15++)
            func_ov006_02158fd8(arg0, var10, var13[var15], var14[var15]);
    }
    func_ov006_0215373c(arg0->unknown_74_, arg0->unknown_14c_);
    func_ov006_021537c8(arg0->unknown_74_, arg0->unknown_48_, arg0->unknown_4c_, arg0->unknown_50_);
}
