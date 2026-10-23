#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
struct Struct_020d3c28 { char unknown_0_[0xa4]; };
#else
struct Struct_020d3c28 { char unknown_0_[0xb8]; };
#endif
struct Struct_02013fb4;
struct Struct_020d3d90;
struct Struct_0203d028;
struct Struct_02054664;
struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
struct Struct_02033834;
struct Struct_02010604;
#if defined(jpn)
struct Struct_ov017_021c1e6c_7 { char unknown_0_[0xb]; unsigned char unknown_10_0_:3, unknown_10_3_:1, unknown_b_4_:4; unsigned char unknown_c_; char unknown_d_[0x13]; };
#else
struct Struct_ov017_021c1e6c_7 { char unknown_0_[0x10]; unsigned char unknown_10_0_:3, unknown_10_3_:1, unknown_10_4_:4; unsigned char unknown_11_; char unknown_12_[0x12]; };
#endif
struct Struct_01ff8b48_14 {
    char unknown_0_[0x56b]; unsigned char unknown_56b_0_:4, unknown_56b_4_:4;
    void inline_ov017_021c1e6c_2(int arg0) { unsigned char var0 = arg0; unknown_56b_0_ = var0; }
};
#if defined(jpn)
struct Struct_ov017_021c1e6c { GameObject unknown_0_; char unknown_13c_[0x144 - 0x13c]; Struct_01ff8b48_14* unknown_150_; char unknown_148_[0x1c4 - 0x154]; Struct_ov017_021c1e6c_7* unknown_1c4_; };
#else
struct Struct_ov017_021c1e6c { GameObject unknown_0_; char unknown_13c_[0x150 - 0x13c]; Struct_01ff8b48_14* unknown_150_; char unknown_154_[0x1c4 - 0x154]; Struct_ov017_021c1e6c_7* unknown_1c4_; };
#endif
struct Struct_ov017_021c1e6c_2 { char unknown_0_[0xf7d]; unsigned char unknown_f7d_; };
#if defined(jpn)
struct Struct_ov017_021c1e6c_3 { char unknown_0_[0x7c88]; int unknown_7f5c_; Vector3i unknown_7f60_; };
#else
struct Struct_ov017_021c1e6c_3 { char unknown_0_[0x7f5c]; int unknown_7f5c_; Vector3i unknown_7f60_; };
#endif
#if defined(jpn)
struct Struct_ov017_021c1e6c_4 { char unknown_0_[0xc00]; };
#else
struct Struct_ov017_021c1e6c_4 { char unknown_0_[0x1000]; };
#endif
struct Struct_ov017_021c1e6c_5 {
#if defined(jpn)
    char unknown_0_[0x3c4]; Struct_ov017_021c1e6c_4 unknown_1d4_[2];
#else
    char unknown1_0_[0x1d4]; Struct_ov017_021c1e6c_4 unknown_1d4_[2];
#endif
    Struct_ov017_021c1e6c_4* inline_ov017_021c1e6c(int arg0) { return &unknown_1d4_[arg0]; }
};
struct Struct_ov017_021c1e6c_6 { char unknown_0_; unsigned char unknown_1_; char unknown_2_[6]; short unknown_8_; unsigned char unknown_a_, unknown_b_; };
extern "C" unsigned short* func_02012fe4();
extern "C" void func_020d3c08(char*);
extern "C" void func_020d3c84(Struct_020d3c28*, Struct_02013fb4*, int);
extern "C" Struct_ov017_021c1e6c_7* func_020d3d90(Struct_020d3d90*, int);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
extern "C" unsigned char func_ov017_02191764(int, int);
extern "C" void* func_0202ae18();
extern "C" int func_0202c508(void*);
extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_02082828(void*);
extern "C" void func_02054664(Struct_02054664*);
extern "C" void func_02053c4c(char*, char*);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void func_020546a0(void*, int);
extern "C" void func_020546b4(void*, int);
extern "C" void func_02059f38(Struct_02059cfc_2*, Struct_02059cfc_3*);
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" void func_ov017_02191508(int, Struct_ov017_021c1e6c_7*);
extern "C" void func_02039830(void*);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
extern "C" int func_0202c540(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void VramState_Restore(char*);
void VramState_Save(char*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char*);
int CheckFlag0x1ceBit2Set_02039d68(unsigned char*);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
#if defined(jpn)
extern char data_ov017_021d87c4[], data_ov017_021d87d8[];
#else
extern char data_ov017_021d7f2c[], data_ov017_021d7f40[], data_ov017_021d7f50[];
#endif

// USA: func_ov017_021c1e6c
extern "C" ARM void func_ov017_021c1e6c(Struct_ov017_021c1e6c_6* arg0) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    GameResources* var2 = GetGameResources();
    unsigned short* var3 = func_02012fe4();
    if (arg0->unknown_a_ == 0) {
#if defined(jpn)
        arg0->unknown_8_ = var1->QueueLoadFile(data_ov017_021d87c4, 0);
#else
        arg0->unknown_8_ = var1->QueueLoadFileInGP2(data_ov017_021d7f2c, data_ov017_021d7f40, 0);
#endif
        arg0->unknown_a_ = 1;
    } else if (arg0->unknown_a_ == 1) {
        if (!var1->GetTaskStatus(arg0->unknown_8_)) return;
        Struct_ov017_021c1e6c_7* var4 = 0;
        if (var1->GetDetailedTaskStatus(arg0->unknown_8_) == 2) {
            void* var5;
            unsigned int var6;
            var1->GetLoadedFileByID(arg0->unknown_8_, &var5, &var6);
            if (var5) {
                Struct_020d3c28 var7;
                func_020d3c08((char*)&var7);
                func_020d3c84(&var7, (Struct_02013fb4*)var5, var6);
                var4 = func_020d3d90((Struct_020d3d90*)&var7, arg0->unknown_b_);
            }
        }
        var1->RemoveTask(arg0->unknown_8_);
        arg0->unknown_8_ = -1;
        if (!var4) { arg0->unknown_1_ = 1; return; }
        int var8;
        unsigned char var9;
        if (var4->unknown_10_3_) {
            int var10 = var4->unknown_10_0_;
            var8 = 3;
            func_ov017_0218f064(var2, var8, 4, 1, var10);
            var9 = func_ov017_02191764(var8, 0);
            arg0->unknown_1_ = 1;
        } else {
            if (func_0202c508(func_0202ae18())) ((Struct_ov017_021c1e6c_2*)func_02010828(var0))->unknown_f7d_ = arg0->unknown_b_;
            var8 = 0xce;
            var9 = 4;
            Struct_ov017_021c1e6c_4* var11 = ((Struct_ov017_021c1e6c_5*)var2)->inline_ov017_021c1e6c(1);
            var2->allocator_11c0.Reset();
            func_0207df50((Struct_0203d028*)var11);
            Struct_ov017_021c1e6c_7* var12 = (Struct_ov017_021c1e6c_7*)var2->allocator_11c0.Allocate(sizeof(Struct_ov017_021c1e6c_7));
            if (!var12) goto configureCombatant;
            memcpy(var12, var4, sizeof(Struct_ov017_021c1e6c_7));
#if defined(jpn)
            void* var13 = var2->allocator_11c0.Allocate(0x8cc);
#else
            void* var13 = var2->allocator_11c0.Allocate(0x964);
#endif
            if (!var13) goto configureCombatant;
            func_02082828(var13);
#if defined(jpn)
            Struct_ov017_021c1e6c* var14 = (Struct_ov017_021c1e6c*)var2->allocator_11c0.Allocate(0x2c8);
#else
            Struct_ov017_021c1e6c* var14 = (Struct_ov017_021c1e6c*)var2->allocator_11c0.Allocate(0x2d4);
#endif
            if (!var14) goto configureCombatant;
            func_02054664((Struct_02054664*)var14);
            func_02053c4c((char*)var14, (char*)var13);
            unsigned char var15 = var12->unknown_10_0_;
            if (var14->unknown_150_) var14->unknown_150_->inline_ov017_021c1e6c_2(var15);
            var14->unknown_1c4_ = var12;
            func_0200fd38(var0, 0xce, &var14->unknown_0_);
            char var16[0x50];
#if defined(jpn)
            sprintf(var16, data_ov017_021d87d8, var4->unknown_c_);
#else
            sprintf(var16, data_ov017_021d7f50, var4->unknown_11_);
#endif
            arg0->unknown_8_ = var1->QueueLoadFile(var16, &var2->allocator_11c0);
            arg0->unknown_a_ = 2;
        }
configureCombatant:
        GameObject* var17 = func_0200ff58(var0, var8);
        if (var17) {
            func_020546a0(var17, 0);
            func_020546b4(var17, var9);
            var17->obj3D_.SetField06(*var3);
            if (var0->GetUnknownGameObject()) {
                func_02059f38((Struct_02059cfc_2*)var17, (Struct_02059cfc_3*)&((Struct_ov017_021c1e6c_3*)var0)->unknown_7f60_);
                func_02033874((Struct_02033834*)var17, ((Struct_ov017_021c1e6c_3*)var0)->unknown_7f5c_);
            }
            if (entry->special) func_ov017_02191508(combatantId, entry);
            GameObject* leader = game->GetUnknownGameObject();
            if (leader) CopyByteField0x253To0x252_02039830(leader);
            func_ov017_02191108(resources, 1, 1, 1, 1);
            func_ov017_02191234(resources);
            if (func_0202c540(func_0202ae18())) CallHelperWithBuf_021907dc((int)resources, 0, 1, 1, 1);
        } else self->done = 1;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->task)) return;
        if (loader->GetDetailedTaskStatus(self->task) == 2) {
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &file, &length);
            if (file) {
                ObjectArchiveLoadInfo info;
                info.allocator = &resources->allocator_11c0;
                info.unk_0 = 0;
                info.unk_10 = 0; info.unk_14 = 0; info.unk_18 = 0; info.packageID = 0;
                info.fileData = file;
                info.unk_8 = length;
                char* pairTables = resources->unknown_11d4;
                GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(game, 0xce);
                if (combatant) {
                    VramState_Restore(pairTables);
                    combatant->obj3D_.LoadFromCCHROrCMOTArchive(&info, 0);
                    VramState_Save(pairTables);
                    combatant->obj3D_.SetScale(0x10a, 0x10a, 0x10a);
                    SetField0x2d0_020546a0(combatant, 0);
                    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
                    ClearFlag0x1ceBit0x4_02039d58((unsigned char*)combatant);
                    for (int i = 0; i < 4; i++) {
                        GameObject* member = GetCombatantWithFlag0x1000_0200ff58(game, i);
                        if (member && CheckFlag0x1ceBit2Set_02039d68((unsigned char*)member)) SetFlag0x1ceBit0x4_02039d48((unsigned char*)combatant);
                    }
                    GameObject* var26 = var0->GetGameObjectByIndex(0);
                    if (var26) {
                        func_02059f38((Struct_02059cfc_2*)var23, (Struct_02059cfc_3*)&((Struct_ov017_021c1e6c_3*)var0)->unknown_7f60_);
                        func_02033874((Struct_02033834*)var23, ((Struct_ov017_021c1e6c_3*)var0)->unknown_7f5c_);
                        var23->obj3D_.SetField06(var26->obj3D_.GetField06());
                    }
                }
            }
        }
        var1->RemoveTask(arg0->unknown_8_);
        arg0->unknown_8_ = -1;
        arg0->unknown_1_ = 1;
    }
}
