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

struct PartyMemberData {
    char unk_0[0x454];
    unsigned short unknown_454_[8];
};

struct GameObject {
    char unk_0[R(0x144, 0x150)];
    PartyMemberData* unknown_150_;
};

struct Party {
    char unk_0[0xf78];
    unsigned char members_[4];
    unsigned char count_;
};

struct Struct_ov006_02157a60 {
    char unk_0[R(0x40, 0x48)];
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    char unk_54[0x20];
    char ingredients_[R(0xd4, 0xd8)];
    char table_[0xc];
};

extern "C" Party* GameState_GetParty(GameState* gameState);
extern "C" void* func_0200ff1c(GameState* gameState, int member);
extern "C" short func_0207c620(unsigned char* lists, unsigned int list);
extern "C" short* func_0207c5f8(unsigned char* lists, unsigned int list);
extern "C" unsigned char* func_0207c60c(void* lists, unsigned int list);
extern "C" void func_ov006_02158fd8(Struct_ov006_02157a60* self, unsigned int category, short item, unsigned char count);
extern "C" void func_ov006_0215373c(void* ingredients, void* table);
extern "C" void func_ov006_021537c8(void* ingredients, short** items, unsigned char** counts, unsigned short* sizes);

extern "C" const unsigned short data_ov006_0215fffe[9];
extern "C" const int data_ov006_02160010[8];

// USA: func_ov006_02158de0
extern "C" ARM void func_ov006_02158de0(Struct_ov006_02157a60* self) {
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, sizeof(sizes));

    for (unsigned char i = 0; i < 9; i++) {
        unsigned short size = sizes[i];
        memset(self->items_[i], -1, size * 2);
        memset(self->unknown_4c_[i], 0, size);
        self->sizes_[i] = 0;
    }
    GameState* gameState = GameState::GetInstance();
    Party* party = GameState_GetParty(gameState);
    for (unsigned short j = 0; j < 0x98; j++)
        func_ov006_02158fd8(self, 8, *(short*)((char*)party + 0xc + j * 2), *((char*)party + 0x13c + j));
    for (unsigned char k = 0; k < party->count_; k++) {
        GameObject* member = (GameObject*)func_0200ff1c(gameState, party->members_[k]);
        if (member != 0) {
            unsigned short* items = member->unknown_150_->unknown_454_;
            for (unsigned char l = 0; l < 8; l++)
                func_ov006_02158fd8(self, 8, items[l], 1);
        }
    }
    for (unsigned char m = 0; m < 8; m++) {
        int list = data_ov006_02160010[m];
        short count = func_0207c620((unsigned char*)party + 0x1d4, list);
        short* var13 = func_0207c5f8((unsigned char*)party + 0x1d4, list);
        unsigned char* var14 = func_0207c60c((char*)party + 0x1d4, list);
        for (short n = 0; n < count; n++)
            func_ov006_02158fd8(self, m, var13[n], var14[n]);
    }
    func_ov006_0215373c(self->ingredients_, self->table_);
    func_ov006_021537c8(self->ingredients_, self->items_, self->unknown_4c_, self->sizes_);
}
