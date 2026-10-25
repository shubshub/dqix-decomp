#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"
struct Struct_02032e58;

struct Struct_02048150;
struct Struct_ov000_02163a7c;
struct Struct_02010088;
struct Struct_02010604;
struct Struct_0205d6a0 { char unknown_0_[4]; };
struct Struct_ov023_021d9988;
struct Struct_02072a68_2 { char unknown_0_[4]; };
struct Struct_ov023_021eeaac_2 {
    int unknown_0_, unknown_4_; char unknown_8_[9]; signed char unknown_11_;
    unsigned char unknown_12_[4]; char unknown_16_[2]; int unknown_18_;
#if defined(jpn)
    char unknown_1c_[0x118-0x1c]; char unknown_118_[0x2498-0x118]; unsigned char unknown_2788_;
#else
    char unknown1_1c_[0x118-0x1c]; char unknown_118_[0x2788-0x118]; unsigned char unknown_2788_;
#endif

    char unknown_2789_[4]; unsigned char unknown_278d_;
};
struct Struct_ov023_021f03a0 { unsigned char unknown_0_, unknown_1_, unknown_2_, unknown_3_; int unknown_4_; };
struct Struct_ov003_02162f40 { char unknown_0_[0x25]; unsigned char unknown_25_; };
struct Struct_ov023_021f03a0_2 { char unknown_0_[0x11b]; unsigned char unknown_11b_; char unknown_11c_[2]; unsigned char unknown_11e_; char unknown_11f_; void* unknown_120_; };
struct Struct_ov023_021f0a5c_3 { char unknown_0_[0x54]; };
struct Struct_ov000_02160da0 {
    char unknown_0_[0x30]; SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0x218-0x30-sizeof(SafeAllocator)]; void* unknown_29c_; Struct_ov003_02162f40* unknown_2a0_;
#else
    char unknown1_44_[0x29c-0x30-sizeof(SafeAllocator)]; void* unknown_29c_; Struct_ov003_02162f40* unknown_2a0_;
#endif

#if defined(jpn)
    char unknown_220_[0xb94-0x220]; char unknown_c18_[4]; char unknown_b98_[0xe28-0xb98]; int unknown_eac_;
#else
    char unknown_2a4_[0xc18-0x2a4]; char unknown_c18_[4]; char unknown_c1c_[0xeac-0xc1c]; int unknown_eac_;
#endif

#if defined(jpn)
    char unknown_e2c_[0x371c-0xe2c]; char unknown_3760_[0x38a4-0x371c]; Struct_0205d6a0 unknown_38e8_;
#else
    char unknown_eb0_[0x3760-0xeb0]; char unknown_3760_[0x38e8-0x3760]; Struct_0205d6a0 unknown_38e8_;
#endif

#if defined(jpn)
    char unknown_38a8_[0x5778-0x38a8]; Struct_ov023_021f03a0_2* unknown_5588_;
#else
    char unknown_38ec_[0x5588-0x38ec]; Struct_ov023_021f03a0_2* unknown_5588_;
#endif

#if defined(jpn)
    char unknown_577c_[0x5948-0x577c]; int unknown_5758_[4]; int unknown_5768_; unsigned char unknown_576c_;
#else
    char unknown_558c_[0x5758-0x558c]; int unknown_5758_[4]; int unknown_5768_; unsigned char unknown_576c_;
#endif

#if defined(jpn)
    char unknown_595d_[3]; Struct_ov023_021f0a5c_3 unknown_5770_[4]; char unknown_5ab0_[0x5af4-0x5ab0]; Struct_02072a68_2 unknown_5904_;
#else
    char unknown_576d_[3]; Struct_ov023_021f0a5c_3 unknown_5770_[4]; char unknown_58c0_[0x5904-0x58c0]; Struct_02072a68_2 unknown_5904_;
#endif

};
struct Struct_02092e0c {
#if defined(jpn)
    char unknown_0_[0x10]; void* unknown_10_; char unknown_14_[0x868-0x14]; int unknown_998_;
#else
    char unknown1_0_[0x10]; void* unknown1_10_; char unknown1_14_[0x998-0x14]; int unknown_998_;
#endif

#if defined(jpn)
    char unknown_86c_[0x17de - 0x86c]; unsigned char unknown_19ae_, unknown_19af_;
#else
    char unknown_99c_[0x19ae - 0x99c]; unsigned char unknown_19ae_, unknown_19af_;
#endif

#if defined(jpn)
    char unknown_17e0_[2]; unsigned char unknown_19b2_; char unknown_17e3_[0x17fb-0x17e3]; unsigned char unknown_19ca_;
#else
    char unknown_19b0_[2]; unsigned char unknown_19b2_; char unknown_19b3_[0x19ca-0x19b3]; unsigned char unknown_19ca_;
#endif

};
struct ActorFlags { char pad0[0xc1]; unsigned char fieldc1; unsigned char low : 4; unsigned char visible : 1; unsigned char high : 3; };
extern "C" Reset_021eefac* _ZZ17GetGlobal021ffefcvE1s;
MessageController* MessageSystem_GetInstance();
extern "C" void* func_0202ae18();
extern "C" int func_02086ef0(Struct_02048150*, int);
extern "C" void func_ov023_021ed988(char*, int);
extern "C" void func_ov000_02163b90(Struct_ov000_02160da0*, int);
extern "C" void func_ov000_021626a0(Struct_ov000_02160da0*, int, int);
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" void func_ov000_021639b4(Struct_ov000_02160da0*);
extern "C" void func_ov000_02167dd8(unsigned char*);
extern "C" int func_ov000_02153e40(void*, short*, int, int);
extern "C" void func_02048cf0(GameObject*, int);
extern "C" void func_ov000_0216e3c4(void*);
unsigned char* GetField02163524(void*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
void ResetCombatantSlot020d7334(unsigned char*, int);
int IsFlag10088Set_02010088(S_10088*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearStateFlags0203400c(ObjectStatePrefix*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
void Window_ClosePane(Entry_0205d6a0*, int);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
extern "C" void func_ov023_021d8a40(BattleEntry*);
void CopyEntryFields_021d8cb4(void*, void*);
void CopyAndStoreLen_021d9988(Obj021d9988*, void*, unsigned int);
extern "C" void func_02046380(MessageController*);
extern "C" void func_ov023_021d8ddc(BattleEntry*, int*);
int GetCheckedSignedByte_02011518(void*, unsigned int);
void NameText_InitFromPartyMember(void*, int);
char* FindEntryByKey_02072a68(TableA68*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_02092e0c*, char*, int, int);
#endif
BattleResultEntry* FindByByteAt118_021f0360(void*, int);
extern "C" int ResourceScriptEntry_LoadLevel(LoadedEntry*, void*, unsigned int, unsigned char, int);
extern "C" int func_ov023_021f4438(BattleWork*);
extern "C" int func_ov023_021f4fc8();
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2*);

#if defined(jpn)
extern "C" void func_0204500c(Struct_02092e0c*,char*,int);
#endif
// USA: func_ov023_021f03a0
extern "C" ARM int func_ov023_021f03a0(Struct_ov000_02160da0* arg0) {
    int var0;
    char var1[256];
#if defined(jpn)

#else
    char var2[12];
#endif

    char filename[40];
    short ids[12];
    GameState* game = GameState::GetInstance();
    Reset_021eefac* state = _ZZ17GetGlobal021ffefcvE1s;
    MessageController* messages = MessageSystem_GetInstance();
    func_0202ae18();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(game), state->actorId);
    if (state->state == 0) {
        if (work->levelUp) ScaleOrResetCombatants_021ed988((char*)work, 0);
        func_ov000_02163b90(work, 1);
        func_ov000_021626a0(work, 4, 0);
        ApplyField41ToGatheredCombatants02163a7c((GatherObj02163a7c*)work);
        func_ov000_021639b4(work);
        ClearFlags04(resources, 0x400);
        RunFlagPassAndSetMode02167dd8_02167dd8((unsigned char*)work);
        void* battle = work->battle;
        int count;
        GameState* combatGame = GameState::GetInstance();
        count = func_ov000_02153e40(battle, ids, 12, 0);
        for (i = 0; i < count; i++) {
            GameObject* actor = combatGame->GetCombatantByIndex(ids[i]);
            if (actor) func_02048cf0(actor, 0);
        }
        func_ov000_0216e3c4(arg0->unknown_c18_);
        unsigned char* var14 = func_ov000_02163524(arg0);
        GameState* var15 = GameState::GetInstance();
        for (int var16 = 0; var16 < 4; var16++) {
            if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var16)) {
                if (var14) func_020d7334(var14, var16);
                GameObject* var17 = var15->GetCombatantByIndex(var16);
                if (var17 && !func_02010088((Struct_02010088*)var17)) {
                    ((Struct_020391ac*)var17)->unknown_c1_ &= ~0xf0;
                    func_02033b88((Struct_02010604*)var17, 0);
                    var17->obj3D_.SkipAnimationTransition();
                    func_0203400c((Struct_02032e58*)var17);
                    var17->obj3D_.MakeVisible();
                }
            }
        }
        for (int var18 = 0; var18 < 8; var18++) {
            GameObject* var19 = func_0200fea4(var15, var18 + 0xc0);
            if (var19 && ((Struct_020391ac*)var19)->unknown_c2_4_) var19->obj3D_.MakeVisible();
        }
        Window_ClosePane(&work->entries, 1);
        SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 0x40000);
        work->allocator.Reset();
        work->result = (BattleEntry*)work->allocator.Allocate(0x12c);
        func_ov023_021d8a40(work->result);
        CopyEntryFields_021d8cb4(work->result, work->entry);
        Reset_021eefac* global = _ZZ17GetGlobal021ffefcvE1s;
        unsigned char countEntries = global->count;
        BattleEntry* result = work->result;
        result->entries = global->entries;
        result->count = countEntries;
        CopyAndStoreLen_021d9988((Obj021d9988*)work->result, _ZZ17GetGlobal021ffefcvE1s->copyData, _ZZ17GetGlobal021ffefcvE1s->copyLength);
        state->state++;
    } else if (state->state == 1) {
        if (work->result->state != 0xff) goto done;
#if defined(jpn)

#else
        func_02046380(var7);
#endif

        func_ov023_021d8ddc(arg0->unknown_5588_, arg0->unknown_5758_);
        BaseCombatStats* var23 = 0;
        if (arg0->unknown_2a0_->unknown_25_) {
            for (int var24 = 0; var24 < 4 && !var23; var24++) {
                int var25 = func_02011518(var5, (unsigned char)var24);
                if (arg0->unknown_5758_[var25]) {
                    GameObject* var26 = func_0200ff1c(var5, var25);
#if defined(jpn)

#else
#if defined(jpn)

#else
                    NameText_InitFromPartyMember(actorName, id);
#endif

#endif

                    var23 = var26->baseStats_;
                }
            }
        } else {
            for (int var27 = 0; var27 < 4; var27++) {
                int var28 = func_02011518(var5, (unsigned char)var27);
                GameObject* var29 = func_0200ff1c(var5, var28);
                if (var29 && func_020a35e0((unsigned char*)arg0->unknown_2a0_, var28) && !func_02010088((Struct_02010088*)var29)) {
#if defined(jpn)

#else
#if defined(jpn)

#else
                    NameText_InitFromPartyMember(actorName, id);
#endif

#endif

                    var23 = var29->baseStats_;
                    break;
                }
            }
        }
        int var30 = 0;
        for (int var31 = 0; var31 < 4; var31++) if (arg0->unknown_5758_[var31]) var30++;
        if (!var23) {
            for (int var32 = 0; var32 < 4; var32++) {
#if defined(jpn)
                GameObject* var33 = func_0200ff1c(var5, var32);
                if (var33 && func_020a35e0((unsigned char*)arg0->unknown_2a0_, var32) && !func_0200ff58(var5, var32))
                    var23 = var33->baseStats_;
#else
                if (GetCombatantWithFlag0x100_0200ff1c(game, i) && TestBitAt0x34_020a35e0((unsigned char*)work->info, i) && !GetCombatantWithFlag0x1000_0200ff58(game, i))
                    NameText_InitFromPartyMember(actorName, i);
#endif

            }
        }
#if defined(jpn)
        if (var30 > 1) sprintf(var1, func_02072a68(&arg0->unknown_5904_, 0x1a), var23);
        else sprintf(var1, func_02072a68(&arg0->unknown_5904_, 0x19), var23);
#else
        var7->unknown1_10_ = var2;
        int var34 = 0x19;
        if (var30 > 1) var34 = 0x1a;
        sprintf(var1, func_02072a68(&arg0->unknown_5904_, var34));
#endif

        strcat(var1, func_02072a68(&arg0->unknown_5904_, 0x22));
#if defined(jpn)
        func_0204500c(var7, var1, 1);
#else
        func_0204500c(var7, var1, 1, 0xe3);
#endif

        var7->unknown_19b2_ = 0;
        var7->unknown_998_ = 1;
        var6->unknown_0_++;
    } else if (var6->unknown_0_ == 2) {
        Struct_ov023_021f03a0* var35 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var6->unknown_11_);
        if (!var35) {
            var6->unknown_11_++;
            if (var6->unknown_11_ >= 4) var6->unknown_0_ = 4;
            return arg0->unknown_eac_;
        }
        sprintf(filename, FindEntryByKey_02072a68(&work->strings, 0), entry->fileId);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 3) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int member = state->member;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        BattleResultEntry* entry = FindByByteAt118_021f0360(_ZZ17GetGlobal021ffefcvE1s, member);
        if (file && ResourceScriptEntry_LoadLevel(&work->loaded[member], file, length, entry->type, entry->experience)) {
            if (!entry->flag) state->loaded[member] = 1;
        }
        var6->unknown_11_++;
        if (var6->unknown_11_ < 4) {
            var6->unknown_0_ = 2;
            return arg0->unknown_eac_;
        }
        var6->unknown_0_++;
    } else if (var6->unknown_0_ == 4) {
        int var40 = 0;
        for (int var41 = 0; var41 < 4; var41++) if (var6->unknown_12_[var41]) { var40 = 1; break; }
        int var42 = func_ov023_021f4438(arg0);
        if (!var40 && !var42 && !arg0->unknown_5768_) {
            var7->unknown_19ae_ = 0;
            var7->unknown_19ca_ = 0;
            var7->unknown_19af_ = 0;
        }
        if (func_ov023_021f4fc8()) {
            func_ov023_021eefac(var6);
            return 7;
        }
    }
done:
    return arg0->unknown_eac_;
}
