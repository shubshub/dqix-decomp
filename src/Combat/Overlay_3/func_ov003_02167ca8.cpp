#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020865b0;
struct FindEntryContainer02086e50;
struct Struct_ov003_02167b34_2;

extern "C" ARM void func_ov003_02167e28(void* self, void* stats, int flag, unsigned char index,
                                        int arg4, int arg5, int arg6);
extern "C" ARM void func_ov003_02167fa4(void* self, int flag, unsigned char* table);
extern "C" void func_ov003_02168088(struct Struct_ov003_02167b34_2* obj, int* arr);
extern "C" int func_020813ec(void* list, int arg);
extern "C" void Font_DecodeText(unsigned char* src, char* dst, int n);
extern "C" void* func_02086e50(FindEntryContainer02086e50* p, int id);
extern "C" int PartyMemberRecord_GetVocation(Struct020865b0* p);

struct Struct_ov003_02167ca8_3 {
    unsigned char pad0[2];
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[13];
    int unknown_1c_[13];
    unsigned char unknown_50_[0xf6 - 0x50];
    unsigned char tableF6[0x14c - 0xf6];
    struct { unsigned int v0 : 10; unsigned int v1 : 10; unsigned int v2 : 10; } g0;
    struct { unsigned int v3 : 10; unsigned int v4 : 10; unsigned int v5 : 10; } unknown_150_;
    struct { unsigned int v6 : 10; } g2;
    struct { unsigned int v7 : 10; unsigned int v8 : 10; unsigned int unknown_2_4_ : 10; } unknown_158_;
    struct { unsigned int v10 : 10; unsigned int unknown_1_2_ : 10; } unknown_15c_;
    unsigned char unknown_160_[0x174 - 0x160];
    unsigned char flag : 1;
};

struct Struct_ov003_02167ca8 {
    void* unknown_0_[4];
    void* list;
    char unknown_14_[0x2e - 0x14];
    char stats[0x30];
    char unknown_5e_[0x76 - 0x5e];
    signed char combatantId;
};

// USA: func_ov003_02167ca8
#if defined(jpn)
struct Struct_ov003_02167ca8_2 {
    void* unknown_0_[4];
    void* list;
    char unknown_14_[0x46 - 0x14];
    signed char combatantId;
};

extern "C" ARM void func_ov003_02167ca8(Struct_ov003_02167ca8_2* self) {
    Struct_ov003_02167ca8_3* entry = (Struct_ov003_02167ca8_3*)func_02086e50(
        (FindEntryContainer02086e50*)GameState_GetParty(GameState::GetInstance()),
        self->combatantId);
    if (entry == 0) {
        return;
    }
    int index = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
    func_ov003_02167e28(self, (unsigned char*)entry + 0x140, entry->flag, (unsigned char)index,
                        entry->unknown_f_[index], entry->unknown_2_[index], entry->unknown_1c_[index]);
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
    int a3 = entry->unknown_150_.v3;
    int b3 = a3;
    values[3] = b3;
    int a4 = entry->unknown_150_.v4;
    values[4] = a4;
    int a5 = entry->unknown_150_.v5;
    values[5] = a5;
    int a6 = entry->g2.v6;
    values[6] = a6;
    int a7 = entry->unknown_158_.v7;
    values[7] = a7;
    int a8 = entry->unknown_158_.v8;
    values[8] = a8;
    int a9 = entry->unknown_158_.unknown_2_4_;
    values[9] = a9;
    int var17 = entry->unknown_15c_.v10;
    values[10] = var17;
    int var18 = entry->unknown_15c_.unknown_1_2_;
    values[11] = var18;
    func_ov003_02168088((Struct_ov003_02167b34_2*)self, values);
    func_020813ec(self->list, 0);
}
#else
extern "C" ARM void func_ov003_02167ca8(Struct_ov003_02167ca8* self) {
    Struct_ov003_02167ca8_3* entry = (Struct_ov003_02167ca8_3*)func_02086e50(
        (FindEntryContainer02086e50*)GameState_GetParty(GameState::GetInstance()),
        self->combatantId);
    if (entry == 0) {
        return;
    }
    int index = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
    memset(self->stats, 0, 0x30);
    Font_DecodeText((unsigned char*)entry + 0x140, self->stats, 1);
    func_ov003_02167e28(self, self->stats, entry->flag, (unsigned char)index,
                        entry->unknown_f_[index], entry->unknown_2_[index], entry->unknown_1c_[index]);
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
    int a3 = entry->unknown_150_.v3;
    int b3 = a3;
    values[3] = b3;
    int a4 = entry->unknown_150_.v4;
    values[4] = a4;
    int a5 = entry->unknown_150_.v5;
    values[5] = a5;
    int a6 = entry->g2.v6;
    values[6] = a6;
    int a7 = entry->unknown_158_.v7;
    values[7] = a7;
    int a8 = entry->unknown_158_.v8;
    values[8] = a8;
    int a9 = entry->unknown_158_.unknown_2_4_;
    values[9] = a9;
    int var36 = entry->unknown_15c_.v10;
    values[10] = var36;
    int var37 = entry->unknown_15c_.unknown_1_2_;
    values[11] = var37;
    func_ov003_02168088((Struct_ov003_02167b34_2*)self, values);
    func_020813ec(self->list, 0);
}
#endif
