#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0207fdcc_2;
struct Container02080f8c;
struct Struct_ov006_02159fb0;
struct GameStateStub;
struct CombatantObj { char pad0[4]; short id; };
struct Struct_0207d538 { int data[3]; };

struct StoreStruct {
    void* field0;
    char pad4[0x14];
    void* field18;
    char unknown_1c_[0x40];
    char* unknown_5c_;
};

struct Struct_01ff8b48_23 { char data[0x7c]; };
struct ParseEntry { char pad0[5]; signed char unknown_5_0_:6; };

struct Struct_ov006_0215a00c_4 {
    char pad0[0x4c];
    int unknown_4c_;
    char unknown_50_[0x78 - 0x50];
    short unknown_78_[3];
    short field7e;
    unsigned short unknown_80_;
    short unknown_82_;
    char pad84[3];
    unsigned char unknown_87_;
    char unknown_88_[0x92 - 0x88];
    unsigned char unknown_92_;
    char unknown_93_[1];
    unsigned short field94;
    char pad96[2];
};

struct Struct_ov006_0215a00c_5 {
    int field0;
    char pad4[0x10];
    void* field14;
    char pad18[0x1c];
    int field34;
    char unknown_38_[0x158 - 0x38];
    struct Container020e0310 field158;
    char unknown_160_[0x170 - 0x160];
    struct Struct_01ff8b48_23 field170;
    short unknown_1ec_;
    char unknown_1ee_[0x300 - 0x1ee];
    struct Struct_ov006_0215a00c_4 sub;
    char unknown_398_[0x3b0 - 0x398];
    int unknown_3b0_;
};

extern "C" void func_02080c20(struct Struct_0207fdcc_2*, int);
extern "C" void func_020813ec(void*, int);
extern "C" int KeyTable_Get(struct Container020e0310*, int);
extern "C" struct StoreStruct* MessageSystem_GetInstance();
extern "C" void func_02046380(struct StoreStruct*);
extern "C" void* func_020e5294(void*, int);
extern "C" void func_020465c0(struct StoreStruct*, int, int);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void MessageSystem_FormatText(struct StoreStruct*, int, const char*, char*, int, int, int);
extern "C" char* Font_FindCharacter(int, int);
extern "C" void __clear(void*, int);
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_ov006_02159fb0(struct Struct_ov006_02159fb0*);
extern char data_ov006_0215ffd2[];
extern char data_ov006_0215ffea[];

// USA: func_ov006_0215a00c
extern "C" ARM void func_ov006_0215a00c(struct Struct_ov006_0215a00c_5* self) {
    char buf[0x400];
    struct Struct_0207d538 combatant;
    int i;

    unsigned char state = self->sub.unknown_92_;
    if (state == 0) {
        if (self->sub.field94 & 0x20) {
            func_02080c20((struct Struct_0207fdcc_2*)self->field14, 0);
            func_020813ec(self->field14, 0);
        }
        self->sub.field94 &= ~0x20;
        self->sub.unknown_80_ = 0;
        if (KeyTable_Get(&self->field158, self->sub.field7e) == 0) {
            self->sub.field7e = -1;
        }
        self->unknown_3b0_ = -1;
        self->sub.unknown_92_ = self->sub.unknown_92_ + 1;
        return;
    }
    if (state == 1) {
        struct StoreStruct* fmt = MessageSystem_GetInstance();
        char* base = fmt->unknown_5c_;
        memset(base, 0, 0x960);
        func_02046380(fmt);

        unsigned short rem = 0;
        if (self->field34 != 0) {
            void* res = func_020e5294(&self->field170, self->unknown_1ec_);
            if (res != 0) {
                fmt->field18 = res;
            }
            rem = (unsigned short)((self->sub.unknown_82_ / 10) * 10);
        }
        func_020465c0(fmt, 0, self->sub.unknown_87_);
        func_020465c0(fmt, 1, rem);

        struct CombatantObj* gobj = (struct CombatantObj*)((GameState*)((struct GameStateStub*)GameState::GetInstance()))->GetLeader();
        if (gobj != 0) {
            NameText_InitFromPartyMember(&combatant, gobj->id);
            fmt->field0 = &combatant;
        }

        short* var9 = (short*)data_ov006_0215ffd2;
        for (i = 0; ; i++) {
            short cur = *var9;
            if (cur < 0) break;
            if (cur == self->sub.field7e) {
                void* res = func_020e5294(&self->field170, self->sub.unknown_78_[i]);
                if (res != 0) {
                    fmt->field18 = res;
                }
                break;
            }
            var9++;
        }

        const char* msg = (const char*)KeyTable_Get(&self->field158, self->sub.field7e);
        MessageSystem_FormatText(fmt, 0xc, msg, base, 0xe3, 0, 1);

        char* p = base + self->sub.unknown_80_;
        unsigned short pos = self->sub.unknown_80_;
        int old = self->field0 >> 4;
        self->field0 += (self->sub.unknown_4c_ << 4);
        i = self->field0 >> 4;
        int limit = i - old;
        if (self->field0 >= 0xffffff) {
            self->field0 = 0;
        }

        int count = 0;
        int one = 1;
        while (count < limit) {
            signed char ch = ((signed char*)p)[0];
            if (ch == 0) break;
            signed char step = 1;
            if (ch == 0x5c && ((signed char*)p)[1] == 0x6e) {
                p += 2;
                pos += 2;
            } else {
                ParseEntry* e = (ParseEntry*)Font_FindCharacter((int)p, 1);
                if (e != 0) {
                    step = e->unknown_5_0_;
                }
                p += step;
                pos = (unsigned short)(pos + step);
            }
            count++;
        }
        if (self->sub.unknown_80_ >= pos) {
            self->sub.field7e = -1;
        }
        self->sub.unknown_80_ = pos;
        __clear(buf, 0x400);
        memcpy(buf, base, pos);
        func_02080f8c((struct Container02080f8c*)self->field14, 1, (int)buf);
        func_020813ec(self->field14, 1);
        func_02080c20((struct Struct_0207fdcc_2*)self->field14, 1);
        self->unknown_3b0_ = 1;

        short* var22 = (short*)data_ov006_0215ffea;
        for (;;) {
            short cur2 = *var22;
            if (cur2 < 0) break;
            if (cur2 == self->sub.field7e) {
                self->unknown_3b0_ = -1;
                break;
            }
            var22++;
        }
        func_ov006_02159fb0((struct Struct_ov006_02159fb0*)self);
    }
}
