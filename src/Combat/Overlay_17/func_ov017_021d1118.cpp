#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"
#include "NitroSDK/Memory.h"

extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void* dispatcher, void* packet, int flag);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_GetState(int* obj);
extern "C" int GameState_UpdatePlayClocks(int commit);
extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020ac0b4(void* dst);
extern "C" int func_020a0870(Struct_02061c04* record);
extern "C" int func_020a08a4(Struct_02061c04* record);
extern "C" int func_020a08d8(Struct_02061c04* record);
extern "C" int func_020a090c(Struct_02061c04* record);

struct Struct_ov017_021d1118_8 { unsigned char bytes[6]; };

struct Struct_ov017_021d1118_9 {
    unsigned char payload[14];
    unsigned char recipient : 2;
    unsigned char mode : 2;
    unsigned char unknown_e_4_ : 4;
    unsigned char type : 2;
    unsigned char length : 4;
    unsigned char unknown_f_6_ : 1;
    unsigned char unknown_f_7_ : 1;
};

struct Struct_ov017_021d1118 {
    unsigned char tag;
    char unknown_1_[3];
    Struct_ov017_021d1118_9 body;
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
    short f14;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
};

struct Struct_ov017_021d1118_3 {
    unsigned int unknown_0_;
    unsigned int lo : 19;
    signed int val : 11;
    unsigned int hi : 2;
    char rest[0x7c - 8];
};

struct Struct_ov017_021d1118_4 {
#if defined(jpn)
    char unknown_0_[0x543c];
    Struct_ov017_021d1118_3 block;
    char unknown_54b8_[0x72be - 0x54b8];
#else
    char unknown1_0_[0x569c];
    Struct_ov017_021d1118_3 block;
    char unknown_5718_[0x74fe - 0x5718];
#endif
    Struct_ov017_021d1118_8 unknown_74fe_;
    Struct_ov017_021d1118_8 inline_ov017_021d1118() { return unknown_74fe_; }
};

struct Struct_ov017_021d1118_5 {
    char unknown_0_[0x186];
    unsigned char values[0x49c - 0x186];
    unsigned char flag : 1;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int index;
};

struct Struct_ov017_021d1118_6 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov017_021d1118_5* data;
};

struct Session {
    char unknown_0_[0x100d];
    unsigned char depth;
};

// USA: func_ov017_021d1118
extern "C" ARM void func_ov017_021d1118(int recipient, int flags, bool arg2, unsigned char mode) {
    GameState* gs;
    void* dispatcher;
    Struct_ov017_021d1118_9* body;
    unsigned char* src;
    Session* session;
    int kind;
    int depth;
    int commit;
    int flag;
    int value;
    Struct_ov017_021d1118_6* protagonist;
    Struct_ov017_021d1118_5* data;
    int var12;
    int var13;
    Struct_ov017_021d1118_3* block;
    gs = GameState::GetInstance();
    dispatcher = LinkMessageQueue_GetInstance();
    Struct_ov017_021d1118 packet;
    body = &packet.body;
    packet.tag = 0x1a;
    body->mode = mode;
    body->unknown_f_7_ = arg2;
    body->recipient = recipient;
    block = &((Struct_ov017_021d1118_4*)gs)->block;
    if (flags & 4) {
        body->type = 2;
        body->length = 6;
        Struct_ov017_021d1118_8 var16 = ((Struct_ov017_021d1118_4*)gs)->inline_ov017_021d1118();
        memcpy(body->payload, &var16, body->length);
        func_0205e330(dispatcher, &packet, 0);
    }
    if (flags & 1) {
        session = (Session*)LinkSession_GetInstance();
        kind = LinkSession_GetState((int*)session);
        depth = session->depth;
        commit = 0;
        if ((kind == 5 && depth > 1) || kind == 6) commit = 1;
        GameState_UpdatePlayClocks(commit);
        Struct_02061c04 blk;
        func_020ac4c0(&blk);
        unsigned int var18 = 0;
        func_020ac0b4(&var18);
        flag = 0;
        value = 0;
        protagonist = (Struct_ov017_021d1118_6*)gs->GetProtagonist();
        if (protagonist) {
            data = protagonist->data;
            flag = data->flag;
            value = data->values[data->index];
        }
        Struct_ov017_021d1118_2 rec;
        VectorizedMemset(&rec, 0, sizeof(rec));
        rec.unknown_0_0_ = blk.unknown_0_.elapsed.hours;
        rec.unknown_8_0_ = blk.unknown_0_.elapsed.minutes;
        rec.unknown_4_0_ = blk.unknown_0_.unknown_4_.hours;
        rec.unknown_8_7_ = blk.unknown_0_.unknown_4_.minutes;
        rec.unknown_5_6_ = blk.unknown_8_0_;
        rec.unknown_1_6_ = var18;
        rec.unknown_c_0_ = blk.unknown_10_0_;
        rec.unknown_10_0_ = blk.unknown_b_0_;
        rec.unknown_d_2_ = blk.unknown_d_6_;
        rec.unknown_11_1_ = blk.unknown_11_1_;
        rec.unknown_9_6_ = (unsigned char)func_020a0870(&blk);
        rec.unknown_a_5_ = (unsigned char)func_020a08a4(&blk);
        rec.unknown_f_0_ = (unsigned char)func_020a08d8(&blk);
        rec.unknown_12_7_ = (unsigned char)func_020a090c(&blk);
        rec.f14 = block->val;
        rec.unknown_16_0_ = flag;
        rec.unknown_16_1_ = value;
        body->type = 0;
        body->unknown_f_6_ = 0;
        src = (unsigned char*)&rec;
        for (var12 = sizeof(rec); var12 > 0; src += 14, var12 -= 14) {
            if (var12 > 14) {
                body->length = 14;
            } else {
                body->length = var12;
                if (!(flags & 2)) body->unknown_f_6_ = 1;
            }
            memcpy(body->payload, src, body->length);
            func_0205e330(dispatcher, &packet, 0);
        }
    }
    if (flags & 2) {
        body->type = 1;
        src = (unsigned char*)block;
        for (var13 = sizeof(*block); var13 > 0; src += 14, var13 -= 14) {
            if (var13 > 14) {
                body->length = 14;
            } else {
                body->length = var13;
                body->unknown_f_6_ = 1;
            }
            memcpy(body->payload, src, body->length);
            func_0205e330(dispatcher, &packet, 0);
        }
    }
}
