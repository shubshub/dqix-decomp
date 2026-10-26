#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_16;
struct Struct_02086e50;
struct Struct_ov003_02167b34_2;

extern "C" ARM void func_ov003_02167e28(void* self, void* stats, int flag, unsigned char index,
                                        int byteValue, int halfValue, int wordValue);
extern "C" ARM void func_ov003_02167fa4(void* self, int flag, unsigned char* table);
void SetEntryFieldsForRange_02168088(struct Wrapper02168088* obj, int* arr);
extern "C" int func_020813ec(void* list, int arg);
extern "C" void Font_DecodeText(unsigned char* src, char* dst, int n);
void* FindEntryBySignedId02086e50(FindEntryContainer02086e50* p, int id);
int PartyMemberRecord_GetVocation(Struct020865b0* p);

struct Struct_ov003_02167ca8_3 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[13];
    int unknown_1c_[13];
    unsigned char unknown_50_[0xf6 - 0x50];
    unsigned char unknown_f6_[0x14c - 0xf6];
    struct { unsigned int unknown_0_0_ : 10; unsigned int unknown_1_2_ : 10; unsigned int unknown_2_4_ : 10; } unknown_14c_;
    struct { unsigned int unknown_0_0_ : 10; unsigned int unknown_1_2_ : 10; unsigned int unknown_2_4_ : 10; } unknown_150_;
    struct { unsigned int unknown_0_0_ : 10; } unknown_154_;
    struct { unsigned int unknown_0_0_ : 10; unsigned int unknown_1_2_ : 10; unsigned int unknown_2_4_ : 10; } unknown_158_;
    struct { unsigned int unknown_0_0_ : 10; unsigned int unknown_1_2_ : 10; } unknown_15c_;
    unsigned char unknown_160_[0x174 - 0x160];
    unsigned char unknown_174_0_ : 1;
};

struct Struct_ov003_02167ca8 {
    void* unknown_0_[4];
    void* unknown_10_;
    char unknown_14_[0x2e - 0x14];
    char unknown_2e_[0x30];
    char unknown_5e_[0x76 - 0x5e];
    signed char unknown_76_;
};

// USA: func_ov003_02167ca8
#if defined(jpn)
struct Struct_ov003_02167ca8_2 {
    void* unknown_0_[4];
    void* unknown_10_;
    char unknown_14_[0x46 - 0x14];
    signed char unknown_46_;
};

extern "C" ARM void func_ov003_02167ca8(Menu_02167b80* self) {
    Entry02167ca8* entry = (Entry02167ca8*)FindEntryBySignedId02086e50(
        (FindEntryContainer02086e50*)GameState_GetParty(GameState::GetInstance()),
        self->combatantId);
    if (entry == 0) {
        return;
    }
    int index = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
    func_ov003_02167e28(self, (unsigned char*)entry + 0x140, entry->flag, (unsigned char)index,
                        entry->tableF[index], entry->metaValues[index], entry->wordValues[index]);
    func_ov003_02167fa4(self, PartyMemberRecord_GetVocation((Struct020865b0*)entry) & 0xff, entry->tableF6);
    int values[12];
    int a0 = entry->g0.v0;
    int b0 = a0;
    values[0] = b0;
    int a1 = entry->g0.v1;
    int b1 = a1;
    values[1] = b1;
    int a2 = entry->g0.v2;
    int b2 = a2;
    values[2] = b2;
    int a3 = entry->g1.v3;
    int b3 = a3;
    values[3] = b3;
    int a4 = entry->g1.v4;
    values[4] = a4;
    int a5 = entry->g1.v5;
    values[5] = a5;
    int a6 = entry->g2.v6;
    values[6] = a6;
    int a7 = entry->g3.v7;
    values[7] = a7;
    int a8 = entry->g3.v8;
    values[8] = a8;
    int a9 = entry->g3.v9;
    values[9] = a9;
    int a10 = entry->g4.v10;
    values[10] = a10;
    int a11 = entry->g4.v11;
    values[11] = a11;
    SetEntryFieldsForRange_02168088((Wrapper02168088*)self, values);
    func_020813ec(self->list, 0);
}
#else
extern "C" ARM void func_ov003_02167ca8(Menu_02167ca8* self) {
    Entry02167ca8* entry = (Entry02167ca8*)FindEntryBySignedId02086e50(
        (FindEntryContainer02086e50*)GameState_GetParty(GameState::GetInstance()),
        self->combatantId);
    if (entry == 0) {
        return;
    }
    int index = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
    memset(self->stats, 0, 0x30);
    Font_DecodeText((unsigned char*)entry + 0x140, self->stats, 1);
    func_ov003_02167e28(self, self->stats, entry->flag, (unsigned char)index,
                        entry->tableF[index], entry->metaValues[index], entry->wordValues[index]);
    func_ov003_02167fa4(self, PartyMemberRecord_GetVocation((Struct020865b0*)entry) & 0xff, entry->tableF6);
    int values[12];
    int a0 = entry->g0.v0;
    int b0 = a0;
    values[0] = b0;
    int a1 = entry->g0.v1;
    int b1 = a1;
    values[1] = b1;
    int a2 = entry->g0.v2;
    int b2 = a2;
    values[2] = b2;
    int a3 = entry->g1.v3;
    int b3 = a3;
    values[3] = b3;
    int a4 = entry->g1.v4;
    values[4] = a4;
    int a5 = entry->g1.v5;
    values[5] = a5;
    int a6 = entry->g2.v6;
    values[6] = a6;
    int a7 = entry->g3.v7;
    values[7] = a7;
    int a8 = entry->g3.v8;
    values[8] = a8;
    int a9 = entry->g3.v9;
    values[9] = a9;
    int a10 = entry->g4.v10;
    values[10] = a10;
    int a11 = entry->g4.v11;
    values[11] = a11;
    SetEntryFieldsForRange_02168088((Wrapper02168088*)self, values);
    func_020813ec(self->list, 0);
}
#endif
