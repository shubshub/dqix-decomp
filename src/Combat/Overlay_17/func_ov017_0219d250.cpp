#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/MessageSystem.h"
#include "Resource/Brightness.h"


struct Struct_ov017_0219d250_6 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[3];
    signed char unknown_5_;
    signed char unknown_6_;
    signed char unknown_7_;
    unsigned char unknown_8_[4];
    unsigned char unknown_c_0_ : 4;
};

struct Struct_ov017_0219d250_7 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_[5];
    unsigned char unknown_a_;
    unsigned char unknown_b_[0x15];
    int unknown_20_;
    unsigned char unknown_24_[0x3c];
    unsigned char unknown_60_;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
    unsigned char unknown_63_[4];
    unsigned char unknown_67_;
    unsigned char unknown_68_[6];
    unsigned char unknown_6e_;
};

struct Struct_ov017_0219d250_9 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_3_[0x174 - 3];
#else
    unsigned char unknown1_3_[0x178 - 3];
#endif
    unsigned char unknown_178_0_ : 1;
    unsigned char unknown_178_1_ : 7;
    unsigned char unknown_179_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    float unknown_17c_;
};

struct Struct_ov017_0219d250 {
    Object3D unknown_0_;
#if defined(jpn)
    char unknown_ac_[0x150 - 0xac];
#else
    char unknown1_ac_[0x15c - 0xac];
#endif
    int unknown_15c_;
};

struct Struct_ov017_0219d250_2 {
    Object3D unknown_0_;
    char unknown_ac_[0xb8 - 0xac];
    unsigned short unknown_b8_;
    char unknown_ba_[0x130 - 0xba];
    unsigned char* unknown_130_;
};

struct Struct_ov017_0219d250_3 {
    char unknown_0_[4];
    short unknown_4_;
};

struct Struct_ov017_0219d250_4 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov017_0219d250_5 {
#if defined(jpn)
    char unknown_0_[0x3448];
#else
    char unknown1_0_[0x3658];
#endif
    unsigned char unknown_3658_;
    char unknown_3659_[0x36f0 - 0x3659];
    int unknown_36f0_;
    int unknown_36f4_;
    char unknown_36f8_[0x370c - 0x36f8];
    unsigned char* unknown_370c_;
    char unknown_3710_[0x3734 - 0x3710];
    Struct_ov017_0219d250_9* unknown_3734_;
#if defined(jpn)
    char unknown_3528_[0x40c9 - 0x3528];
#else
    char unknown_3738_[0x42e9 - 0x3738];
#endif
    unsigned char unknown_42e9_;
    unsigned char unknown_42ea_;
    char unknown_42eb_;
    unsigned short unknown_42ec_;
#if defined(jpn)
    char unknown_40ce_[0x4214 - 0x40ce];
#else
    char unknown_42ee_[0x44c4 - 0x42ee];
#endif
    void* unknown_44c4_;
};

extern "C" char* Zone3D_GetInstance(void);
char* MessageSystem_GetInstance(void);
void* ZoneRecords_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" void* func_02011584(void*);
extern "C" Struct_ov017_0219d250_7* func_0200fd0c(GameState* arg0);
extern "C" void* func_0202ae18(void);
void* GetGlobalPtr021075f4_0203cf4c(void);
extern "C" void* Scenario_GetInstance(void);
void ClearMonsterFlagEntries_02191bdc(unsigned char*, int);
struct SearchTable;
Entry0219d250* FindEntryByHalfwordKey_02099950(SearchTable*, int);
extern "C" int func_0202c540(void* search);
void SetField5cb0AndRecordByte0_02010774(char*, int);
void SetField5cb4AndRecordByte1_020107a8(char*, int);
void SetSlotByte020107dc(char*, int);
struct SearchStruct;
int TestBitBySignedByteIndex_0202c1c0(SearchStruct*, int);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" int func_0206e558(void* flags);
extern "C" int func_ov017_0219c774(Entry0219d250* entry, int a, int b);
void* GetGlobal02109030_020936f8(void);
extern "C" void func_02094030(void* p, int a, int b, int c);
void InitStruct0203e074(char*);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
int GetShortAt0xb8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
void BgmPlayer_FadeOut(Actor0209c678*, int);
Entry0219d250* GetElementStride0x10_020999d8(unsigned char*, unsigned int);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
void ClearBytesAndZeroBlock02039d24(unsigned char*);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
extern "C" void func_020531f0(void* obj);
void ClearField0xc4KeepBit0x8000_0203409c(unsigned char* obj);
void MessageSystem_Reset(char* c);
extern "C" void MessageSystem_Stop(char* c);
void SetBitIfValueInTable_0219e290(void*, unsigned short);
void Clear0x80Bytes0206ebc8(void* p);
void Clear0x80BytesAt0x800206ebdc(unsigned char*);
extern "C" void func_ov017_021a316c(Battle0219d250* self);
extern "C" void func_ov017_0219de70(Battle0219d250* self, Entry0219d250* other, Entry0219d250* entry);
void SetByte0x63d5_02012040(void*);
unsigned char GameState_GetProtagonistIndex(GameState* gs);
extern "C" void func_ov017_0218f5a4(Battle0219d250* self, int id, int b, int c, int d);
extern "C" void func_0208fa8c(void* p);
struct Entry_02028bd0;
void* FindInlineEntryById(Entry_02028bd0*, int);
struct EntryArg_0219e014;
void ProcessEntryFlagsAndCombatants_0219e014(unsigned char*, EntryArg_0219e014*);
extern "C" void func_020288e0(void* table);
void SetFlagsForFlaggedCombatants_0219e0ec(void* self);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(Struct_0203cfb4*);
struct Struct_0205859c;
extern "C" void func_0205859c(Struct_0205859c*);
extern "C" void func_ov017_0219e234(Struct_ov017_0219d250_5*, Struct_ov017_0219d250_7*, Struct_ov017_0219d250_6*, void*);
extern "C" void func_ov017_0219fda0(Struct_ov017_0219d250_5* arg0);
extern "C" void func_ov017_0219fec0(void* arg0);
extern "C" int func_020981e4(int, int);
extern "C" int func_0202b7d8(int* arg0);
extern "C" void func_ov017_02191108(Struct_ov017_0219d250_5* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_0202c508(void* arg0);
extern "C" void func_ov017_021907dc(int, int, int, int, int);

extern char g_bgmPlayer;

#if defined(jpn)
enum { Enum_ov017_0219d250_10198 = 0x2816 };
#else
enum { Enum_ov017_0219d250_10198 = 0x27d6 };
#endif

// USA: func_ov017_0219d250
extern "C" ARM void func_ov017_0219d250(Struct_ov017_0219d250_5* arg0, unsigned char arg1) {
    Struct_ov017_0219d250_9* var0;
    Struct_ov017_0219d250_7* var1;
    int var2;
    Struct_ov017_0219d250_6* var3;
    Struct_ov017_0219d250_6* var4;
    GameState* var5;
    char* var6;
    void* var7;
    void* var8;
    GameObject* var9;
    GameObject* var10;
    void* var11;
    void* var12;
    void* var13;
    Struct_ov017_0219d250_4* var14;
    int var15;
    TimeOfDay var16;
    Struct_ov017_0219d250_2* var17;
    int var18;
    int var19;
    void* var20;
    void* var21;
    GameState* var22;
    unsigned char* var23;
    int var24;
    int var25;
    unsigned short var26;

    gs = GameState::GetInstance();
    char* field = Zone3D_GetInstance();
    controller = MessageSystem_GetInstance();
    entryTable = ZoneRecords_GetInstance();
    combatants = func_02057924();
    hero = gs->GetProtagonist();
    unknown = gs->GetUnknownGameObject();
    searchTable = GetPtrField0x468_02011584(gs);
    request = GetField0x3f8Address_0200fd0c(gs);
    search = func_0202ae18();
    extRegion = GetGlobalPtr021075f4_0203cf4c();
    party = (GrottoIds0219d250*)GameState_GetParty(gs);
    char* status = (char*)&((Zone3D*)field)->grotto_;
    Scenario_GetInstance();
    header = self->header;
    if (hero == NULL || unknown == NULL) {
        return;
    }

    func_ov017_02191bdc((unsigned char*)arg0, 1);
    var2 = var1->unknown_0_;
    var15 = var9->obj3D_.GetField06();
    var3 = func_02099950((Struct_02095924_2*)var11, var2);
    var4 = func_02099950((Struct_02095924_2*)var11, var15);
    var0 = arg0->unknown_3734_;

    if (var0->unknown_2_ != 0 && var0->unknown_178_0_ && func_0202c540(var12)) {
        func_02010774((char*)var5, var0->unknown_179_);
        func_020107a8((char*)var5, var0->unknown_17a_);
        func_020107dc((char*)var5, var0->unknown_17b_);
    } else {
        var16 = var5->GetTimeOfDay();
        if (func_0202c540(var12) && var1->unknown_60_ == 0 && arg0->unknown_3734_->unknown_2_ == 0) {
            GameObject* var29 = var5->GetPartyMemberByIndex(0);
            if ((var29 != NULL && var2 == var29->obj3D_.GetField06()) || var1->unknown_62_ != 0) {
                if (var1->unknown_62_ != 0) {
                    var25 = 1;
                } else {
                    var25 = 0;
                }
                gs2 = GameState::GetInstance();
                search2 = func_0202ae18();
                flags = Scenario_GetInstance();
                present = 1;
                key = entry->id;
                changed = 0;
                for (i = 1; i < 4; i++) {
                    if (TestBitBySignedByteIndex_0202c1c0((SearchStruct*)search2, i) &&
                        i != GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search2)) {
                        Combatant0219d250* c = (Combatant0219d250*)GetCombatantWithFlag0x100_0200ff1c(gs2, i);
                        if (c != NULL && (key == c->obj3D.GetField06() || key == c->field15c)) {
                            present = 0;
                            break;
                        }
                    }
                }
                Struct_ov017_0219d250* var31 = (Struct_ov017_0219d250*)func_0200ff1c(var22, 0);
                if (var31 != NULL && (var26 == var31->unknown_0_.GetField06() || var26 == var31->unknown_15c_)) {
                    var19 = 1;
                }
                if (var25) {
                    var19 = 1;
                }
                if (var19) {
                    int var32 = func_0206e558(var20) ? 1 : 0;
                    int var33 = func_ov017_0219c774(var3, 1, 0);
                    var24 = (var32 | var33) ? 1 : 0;
                }
                if (var24) {
                    if (arg0->unknown_42e9_ != 0) {
                        func_02094030(func_020936f8(), 0x4e23, -1, 0);
                    }
                    var1->unknown_6e_ &= ~2;
                    func_0203e074((char*)var13);
                }
                if (func_0209cd50(id) != GetShortAt0xb8((ShortField0xb8_0209cae8*)&g_bgmPlayer) &&
                    request->f20 <= 0) {
                    BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
                    header[0xa] = 1;
                }
            }
        }
        arg0->unknown_42e9_ = 0;
        TimeOfDay var34 = var5->GetTimeOfDay();
        if ((var16 == 0 && var34 != 0) || (var16 != 0 && var34 == 0)) {
            var1->unknown_6e_ &= ~2;
            func_0203e074((char*)var13);
        }
    }

    var0->unknown_178_0_ = 0;
    var0->unknown_178_1_ = 0;
    var0->unknown_179_ = 0;
    var0->unknown_17a_ = 0;
    var0->unknown_17b_ = 0;
    var0->unknown_17c_ = -1.0f;
    if (var1->unknown_67_ != 0) {
        var1->unknown_6e_ &= ~2;
        func_0203e074((char*)var13);
    }
    if (var3 == NULL) {
        var3 = func_020999d8((unsigned char*)var11, 0);
        var2 = var3->unknown_0_;
        var1->unknown_0_ = var2;
    }
    func_ov017_0219cdc0(var2, 1, -1);

    for (int var35 = 0; var35 < var14->unknown_f7c_; var35++) {
        var17 = (Struct_ov017_0219d250_2*)var5->GetPartyMemberByIndex(var14->unknown_f78_[var35]);
        if (var17 != NULL) {
            _ZN8Object3D10SetField06Et(&var17->unknown_0_, var2);
            var17->unknown_0_.SetInheritedAlpha(0x1f);
            var17->unknown_b8_ = 0;
            func_02039d24((unsigned char*)var17);
            if (var2 != var15) {
                var17->unknown_130_[8] = 0;
                func_ov017_021c9e00(var14->unknown_f78_[var35], 1, 0, 1);
            }
        }
    }

    if (func_020535c8((signed char*)var10)) {
        func_020531f0(var10);
    }
    ClearField0xc4KeepBit0x8000_0203409c((unsigned char*)hero);
    if (((MessageSystem*)controller)->active != NULL) {
        MessageSystem_Reset(controller);
    }
    MessageSystem_Stop(controller);

    int var36;
    if (var4 == NULL) {
        var36 = 1;
    } else {
        var36 = var4->unknown_5_ != var3->unknown_5_ || var4->unknown_6_ != var3->unknown_6_ || var4->unknown_7_ != var3->unknown_7_;
    }
    func_ov017_0219e290(arg0, var1->unknown_0_);
    if (var1->unknown_a_ == 0) {
        if (var36) {
            func_0206ebc8(arg0->unknown_44c4_);
        }
        if (var2 != var15) {
            func_0206ebdc((unsigned char*)arg0->unknown_44c4_);
        }
    }
    if (var2 != var15) {
        var1->unknown_6e_ &= ~2;
    }
    if (!(var1->unknown_6e_ & 2)) {
        func_ov017_021a316c(arg0);
        if (((Zone3D*)var27)->internalAllocator_.GetSignedAllocator()) {
            ((Zone3D*)var27)->internalAllocator_.Destroy();
            ((Zone3D*)var27)->internalAllocator_.ResetAllocatorPointer();
        }
        func_ov017_0219de70(arg0, var4, var3);
    }
    if (var3->unknown_c_0_ == 2 && var3->unknown_0_ != 0x170c) {
        func_02012040(var5);
    }
    if (request->pending != 0) {
        func_ov017_0218f5a4(self, GameState_GetProtagonistIndex(gs), 1, 0, 0);
        request->pending = 0;
    }
    func_0208fa8c(var28);
    func_ov017_0219e014((unsigned char*)arg0, (Struct_ov017_0219d250_8*)(func_02028bd0((Struct_020fdd44*)var7, var15)));
    func_020288e0(var7);
    func_ov017_0219e0ec(arg0);
    func_0203cfb4((Struct_0203cfb4*)var13);
    func_0205859c((Struct_0205859c*)var8);
    func_ov017_0219e234(arg0, var1, var4, var3);
    arg0->unknown_36f0_ = 0;
    arg0->unknown_36f4_ = 0;
    arg0->unknown_42ea_ = var5->GetTimeOfDay();
    arg0->unknown_42ec_ = 0;
    if (!(var1->unknown_6e_ & 1)) {
        SetFlags04((GameResources*)arg0, 1);
    }
    if ((var4 == NULL || var4->unknown_0_ != 3) && var3->unknown_0_ == 3) {
        func_ov017_0219fda0(arg0);
    } else if (var4 != NULL && var4->unknown_0_ == 3 && var3->unknown_0_ != 3) {
        func_ov017_0219fec0(arg0);
    }
    arg0->unknown_3658_ = 0;
    ((Zone3D*)var27)->SwitchZone(var1->unknown_0_, var1->unknown_4_);
    if (func_020981e4((int)(((Zone3D*)var27)->unk_840), var2) || func_020981e4((int)(((Zone3D*)var27)->unk_840), var15)) {
        if (func_0202b7d8((int*)var12) == 0) {
            func_ov017_02191108(arg0, 1, 1, 1, 1);
        } else {
            for (int var37 = 0; var37 < 4; var37++) {
                if (func_0202c508(var12)) {
                    func_ov017_02191108(arg0, 1, 1, 1, 1);
                } else {
                    func_ov017_021907dc((int)arg0, 0, 1, 1, 1);
                }
            }
        }
    }
    *(unsigned short*)(var27 + Enum_ov017_0219d250_10198) = 0;
    for (int var38 = 0; var38 < 4; var38++) {
        if (var17 != NULL && var38 != ((Struct_ov017_0219d250_3*)var10)->unknown_4_) {
            var17->unknown_0_.DisableFlag(0x1010);
        }
    }
}
