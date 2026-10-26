#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"
#include "NitroSDK/Memory.h"

void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void* dispatcher, void* packet, int flag);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_GetState(int* obj);
int GameState_UpdatePlayClocks(int commit);
int LoadBattleBlock020ac4c0(void* dst);
int CopyOutBattleField0x7ac0_020ac0b4(void* dst);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* record);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* record);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot* record);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot* record);

struct Struct_ov017_021d1118_8 { unsigned char unknown_0_[6]; };

struct Struct_ov017_021d1118_9 {
    unsigned char unknown_0_[14];
    unsigned char unknown_e_0_ : 2;
    unsigned char unknown_e_2_ : 2;
    unsigned char unknown_e_4_ : 4;
    unsigned char unknown_f_0_ : 2;
    unsigned char unknown_f_2_ : 4;
    unsigned char unknown_f_6_ : 1;
    unsigned char unknown_f_7_ : 1;
};

struct Struct_ov017_021d1118 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    Struct_ov017_021d1118_9 unknown_4_;
};

struct Struct_ov017_021d1118_2 {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short unknown_14_;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
};

struct Struct_ov017_021d1118_3 {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 19;
    signed int unknown_6_3_ : 11;
    unsigned int unknown_7_6_ : 2;
    char unknown_8_[0x7c - 8];
};

struct Struct_ov017_021d1118_4 {
#if defined(jpn)
    char unknown_0_[0x543c];
    Struct_ov017_021d1118_3 unknown_569c_;
    char unknown_54b8_[0x72be - 0x54b8];
#else
    char unknown1_0_[0x569c];
    Struct_ov017_021d1118_3 unknown_569c_;
    char unknown_5718_[0x74fe - 0x5718];
#endif
    Struct_ov017_021d1118_8 unknown_74fe_;
    Struct_ov017_021d1118_8 inline_ov017_021d1118() { return unknown_74fe_; }
};

struct Struct_ov017_021d1118_5 {
    char unknown_0_[0x186];
    unsigned char unknown_186_[0x49c - 0x186];
    unsigned char unknown_49c_0_ : 1;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int unknown_950_;
};

struct Struct_ov017_021d1118_6 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov017_021d1118_5* unknown_150_;
};

struct Struct_ov017_021d1118_7 {
    char unknown_0_[0x100d];
    unsigned char unknown_100d_;
};

// USA: func_ov017_021d1118
extern "C" ARM void func_ov017_021d1118(int recipient, int flags, bool segmented, unsigned char mode) {
    GameState* gs;
    void* dispatcher;
    PacketBody* body;
    unsigned char* src;
    Session* session;
    int kind;
    int depth;
    int commit;
    int flag;
    int value;
    ProtagonistObject* protagonist;
    ProtagonistData* data;
    int recordLeft;
    int blockLeft;
    LinkBlock* block;
    gs = GameState::GetInstance();
    dispatcher = LinkMessageQueue_GetInstance();
    Packet packet;
    body = &packet.body;
    packet.tag = 0x1a;
    body->mode = mode;
    body->segmented = segmented;
    body->recipient = recipient;
    block = &((LinkState*)gs)->block;
    if (flags & 4) {
        body->type = 2;
        body->length = 6;
        PacketIdentifier identifier = ((LinkState*)gs)->GetIdentifier();
        memcpy(body->payload, &identifier, body->length);
        func_0205e330(dispatcher, &packet, 0);
    }
    if (flags & 1) {
        session = (Session*)LinkSession_GetInstance();
        kind = LinkSession_GetState((int*)session);
        depth = session->depth;
        commit = 0;
        if ((kind == 5 && depth > 1) || kind == 6) commit = 1;
        GameState_UpdatePlayClocks(commit);
        BattleRecordSnapshot blk;
        LoadBattleBlock020ac4c0(&blk);
        unsigned int score = 0;
        CopyOutBattleField0x7ac0_020ac0b4(&score);
        flag = 0;
        value = 0;
        protagonist = (ProtagonistObject*)gs->GetProtagonist();
        if (protagonist) {
            data = protagonist->data;
            flag = data->flag;
            value = data->values[data->index];
        }
        Struct_ov017_021d1118_2 var19;
        VectorizedMemset(&var19, 0, sizeof(var19));
        var19.unknown_0_0_ = var17.unknown_0_.unknown_0_.unknown_0_;
        var19.unknown_8_0_ = var17.unknown_0_.unknown_0_.unknown_2_;
        var19.unknown_4_0_ = var17.unknown_0_.unknown_4_.unknown_0_;
        var19.unknown_8_7_ = var17.unknown_0_.unknown_4_.unknown_2_;
        var19.unknown_5_6_ = var17.unknown_8_0_;
        var19.unknown_1_6_ = var18;
        var19.unknown_c_0_ = var17.unknown_10_0_;
        var19.unknown_10_0_ = var17.unknown_b_0_;
        var19.unknown_d_2_ = var17.unknown_d_6_;
        var19.unknown_11_1_ = var17.unknown_11_1_;
        var19.unknown_9_6_ = (unsigned char)func_020a0870(&var17);
        var19.unknown_a_5_ = (unsigned char)func_020a08a4(&var17);
        var19.unknown_f_0_ = (unsigned char)func_020a08d8(&var17);
        var19.unknown_12_7_ = (unsigned char)func_020a090c(&var17);
        var19.unknown_14_ = var14->unknown_6_3_;
        var19.unknown_16_0_ = var8;
        var19.unknown_16_1_ = var9;
        var2->unknown_f_0_ = 0;
        var2->unknown_f_6_ = 0;
        var3 = (unsigned char*)&var19;
        for (var12 = sizeof(var19); var12 > 0; var3 += 14, var12 -= 14) {
            if (var12 > 14) {
                var2->unknown_f_2_ = 14;
            } else {
                var2->unknown_f_2_ = var12;
                if (!(arg1 & 2)) var2->unknown_f_6_ = 1;
            }
            memcpy(var2->unknown_0_, var3, var2->unknown_f_2_);
            func_0205e330(var1, &var15, 0);
        }
    }
    if (arg1 & 2) {
        var2->unknown_f_0_ = 1;
        var3 = (unsigned char*)var14;
        for (var13 = sizeof(*var14); var13 > 0; var3 += 14, var13 -= 14) {
            if (var13 > 14) {
                var2->unknown_f_2_ = 14;
            } else {
                var2->unknown_f_2_ = var13;
                var2->unknown_f_6_ = 1;
            }
            memcpy(var2->unknown_0_, var3, var2->unknown_f_2_);
            func_0205e330(var1, &var15, 0);
        }
    }
}
