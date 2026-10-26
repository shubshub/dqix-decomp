#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021f2e6c {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 5;
    unsigned int unknown_1_6_ : 1;
    unsigned int unknown_1_7_ : 1;
    unsigned int unknown_2_0_ : 1;
    unsigned int unknown_2_1_ : 15;
};
struct Struct_ov023_021f2e6c_3 {
    Struct_ov023_021f2e6c unknown_0_;
    char unknown_4_[0xc];
};
struct Struct_ov023_021f2e6c_4 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    Struct_ov023_021f2e6c_3 unknown_4_[1];
};
struct Struct_ov023_021f2e6c_5 {
    char unknown_0_[4];
    short unknown_4_[8];
    short unknown_14_;
};
struct Struct_ov023_021f2e6c_6 {
    char unknown_0_[0x6c];
    int unknown_6c_;
    int unknown_70_[4];
    char unknown_80_[0x84 - 0x80];
    int unknown_84_;
    int unknown_88_;
    int unknown_8c_;
};
struct Struct_ov023_021f2e6c_7 { int unknown_0_[3]; };
struct Struct_ov023_021f2e6c_8 { char* unknown_0_; char* unknown_4_; int unknown_8_; };
struct Struct_ov023_021f2e6c_9 { int unknown_0_[0x15]; };

Table021f2e6c* GetGlobal02109418_02094d6c(void);
unsigned char* MessageSystem_GetInstance(void);
void InitCombatEntry_021d8b6c(void* p);
extern "C" void func_ov023_021d8af8(void* p);
void CopyShortTriple0x8e4a_ov000_0215fa84(void* obj, short* a, short* b, short* c);
struct FindEntryById02096134Table;
void* FindEntryById02096134(FindEntryById02096134Table*, int);
extern "C" void func_02046380(unsigned char* st);
struct TableA68;
char* FindEntryByKey_02072a68(TableA68*, int);
void NameText_Clear(void* p);
unsigned char* GetCombatantWithFlag0x400_0200fea4(GameState* gs, int id);
extern "C" Triple021f2e6c func_ov023_021ed804(Triple021f2e6c t, void* p);
extern "C" void _Z26SetWords_021edf38_021edf38PvP13Words021edf38(Triple021f2e6c* dst, const Triple021f2e6c& src);
extern "C" void __clear(void* dst, int n);
void DispatchIfCountPositive020dcf7c(int count, void* buf);
void ResetAndDispatchActorContext0209c6d8(void* actor, int arg);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
void SetShortFields0x8e4aTo0x8e4e_ov000_0215fa70(void* obj, short a, short b, short c);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
int AreAllListedCombatantsFlagged_021ed92c(void);
struct Reset_021eefac;
void ResetFields_021eefac(Reset_021eefac*);
struct Buffer020d784c;
void InitStruct020d784c(Buffer020d784c*);
extern "C" int func_ov023_021f4fc8(void);
struct StreamHeader;
void RegisterCallbackObjectAndRunScript_020d7870(void*, void*, StreamHeader*, int, unsigned char);
struct Pair020deb08;
short GetMaxOfHalfwords0And4(Pair020deb08*);
void ZeroInit020de868(void* p);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020dea64(void* a, void* b, void* c, int d, void* e, int flag);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
void InitStateManager0209e3dc(char*, int);
extern "C" void func_0209fd64(Mgr021f2e6c* mgr, SafeAllocator* alloc, void* data, unsigned int len);
void ResetFields0209e46c(char*);
struct IntField0x64_0209fe10;
void SetIntAt0x64_0209fe10(IntField0x64_0209fe10*, int);
struct TaskState0209fe18;
void PollOv017Task0209fe18(TaskState0209fe18*);
struct List794c;
char* FindValueByHalfwordKey_020d794c(List794c*, int);
struct Fields64_021f3a8c;
int AreFields64And68AllOnes_021f3a8c(Fields64_021f3a8c*);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" unsigned char* _Z26FindNodeByShortKey02162d88Pvs(void* self, unsigned short key);
void ResetNameState02048614(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
struct Obj02048850;
struct Param02048850;
void SetupFieldsFromParam02048850(Obj02048850*, Param02048850*);
void CopyObjectFields02048588(unsigned char* src, unsigned char* dst);
struct Bytes02033b88;
int GameObject_ForceMotionState(Bytes02033b88*, int);
void SetSubstructByte0x56_02049f28(unsigned char* obj);
extern "C" void* func_ov000_02160f14(void* self);
extern "C" void func_ov000_0216d370(void* cam, int a, int b, int c);
void SetFlagOrState0216d530(void* cam, int v);
void Camera_SetTarget(struct Camera*, int, int, int);
extern "C" void Camera_SetOrbit(void* cam, int a, int b, int c);
extern "C" void func_ov000_02163b90(void* self, int v);
void ClearSubstructByte0x56_02049f3c(unsigned char* obj);
Blk021f2e6c* GetPtrField0x4_0202ed64(void* cam);
extern "C" void func_ov000_0216d2d0(void* cam);
struct Dst0202ed0c;
struct Src0202ed0c;
void CopyGroupedBlocks0202ed0c(Dst0202ed0c*, Src0202ed0c*);

extern "C" int* _ZZ17GetGlobal021ffefcvE1s;
extern char g_bgmPlayer;
extern char data_ov023_021fe2ca;
extern char data_ov023_021fe2e5;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern char data_ov023_021fd862;
extern char data_ov023_021fe2f7;

#if defined(jpn)
extern char data_ov023_021fd54e[];
extern char data_ov023_021fd578[];
extern char data_ov023_021fd5a2[];
struct BinarySearchByComparatorStruct;
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020de968(int,char*);
extern "C" void func_0204500c(void*,char*,int);
extern "C" int func_020e052c(void*,void*,const char*,void*,short,unsigned char);
#endif
// USA: func_ov023_021f2e6c
extern "C" ARM int func_ov023_021f2e6c(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021f2e6c_21896=0x5778, Enum_ov023_021f2e6c_21904=0x5780, Enum_ov023_021f2e6c_21908=0x5784, Enum_ov023_021f2e6c_21948=0x57ac, Enum_ov023_021f2e6c_21900=0x577c, Enum_ov023_021f2e6c_668=0x218, Enum_ov023_021f2e6c_6578=0x17e2, Enum_ov023_021f2e6c_2456=0x868, Enum_ov023_021f2e6c_3756=0xe28, Enum_ov023_021f2e6c_21952=0x57b0, Enum_ov023_021f2e6c_552=0x2e4, Enum_ov023_021f2e6c_3784=0xe44, Enum_ov023_021f2e6c_21946=0x57aa, Enum_ov023_021f2e6c_21950=0x57ae, Enum_ov023_021f2e6c_21912=0x5788, Enum_ov023_021f2e6c_21944=0x57a8};
#else
 enum {Enum_ov023_021f2e6c_21896=0x5588, Enum_ov023_021f2e6c_21904=0x5590, Enum_ov023_021f2e6c_21908=0x5594, Enum_ov023_021f2e6c_21948=0x55bc, Enum_ov023_021f2e6c_21900=0x558c, Enum_ov023_021f2e6c_668=0x29c, Enum_ov023_021f2e6c_6578=0x19b2, Enum_ov023_021f2e6c_2456=0x998, Enum_ov023_021f2e6c_3756=0xeac, Enum_ov023_021f2e6c_21952=0x55c0, Enum_ov023_021f2e6c_552=0x228, Enum_ov023_021f2e6c_3784=0xec8, Enum_ov023_021f2e6c_21946=0x55ba, Enum_ov023_021f2e6c_21950=0x55be, Enum_ov023_021f2e6c_21912=0x5598, Enum_ov023_021f2e6c_21944=0x55b8};
#endif
    unsigned char* st;
    int* g = _ZZ17GetGlobal021ffefcvE1s;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Table021f2e6c* tbl = GetGlobal02109418_02094d6c();
    st = MessageSystem_GetInstance();
    Entry021f2e6c* found_entries;
    int state = g[0];
    if (state == 0) {
        if (*(void**)(self + regionalOffset0) != 0) {
            InitCombatEntry_021d8b6c(*(void**)(self + regionalOffset0));
            func_ov023_021d8af8(*(void**)(self + regionalOffset0));
            *(void**)(self + regionalOffset0) = 0;
        }
        *(void**)(arg0 + Enum_ov023_021f2e6c_21904) = 0;
        *(void**)(arg0 + Enum_ov023_021f2e6c_21908) = 0;
        *(short*)(arg0 + Enum_ov023_021f2e6c_21948) = 0;
        *(short*)(arg0 + Enum_ov023_021f2e6c_21900) = -1;
        ((SafeAllocator*)(arg0 + 0x30))->Reset();
        if (*(short*)(*(char**)(arg0 + Enum_ov023_021f2e6c_668) + 0x8e4a) > 0) {
            short var6 = 0;
            short var7 = 0;
            short var8 = 0;
            func_ov000_0215fa84(*(void**)(arg0 + Enum_ov023_021f2e6c_668), &var6, &var8, &var7);
            void* var9 = func_02096134((Struct_0205faf4_7*)var3, *(short*)(*(char**)(arg0 + Enum_ov023_021f2e6c_668) + 0x8e4a));
            if (var7 != 0 && var9 != 0) {
                func_02046380(var0);
#if defined(jpn)
                char* msg = data_ov023_021fd54e;
                if (kind == 0x12) msg = data_ov023_021fd578;
                void* name = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)(*(char**)(self + 0x21c) + 0x678), target);
                if (name != 0) MessageSystem_SetStringArgument((Obj02046574*)st, 0, *(char**)name);
                char rawName[0x40];
                __clear(rawName,0x40);
                func_020de968(count,rawName);
                MessageSystem_SetStringArgument((Obj02046574*)st, 1, rawName);
#else
                int var13 = 0x29;
                if (var6 == 0x12) {
                    var13 = 0x2a;
                }
                char* msg = FindEntryByKey_02072a68((TableA68*)(self + 0x5904), key);
                Triple021f2e6c words;
                NameText_Clear(&words);
                GameState* gs = GameState::GetInstance();
                for (int i = 0xc0; i <= 0xc7; i++) {
                    unsigned char* c = GetCombatantWithFlag0x400_0200fea4(gs, i);
                    if (c != 0) {
                        void* p = *(void**)(c + 0x144);
                        if (target == *(short*)((char*)p + 8)) {
                            _Z26SetWords_021edf38_021edf38PvP13Words021edf38(&words, func_ov023_021ed804(words, p));
                            *(Triple021f2e6c**)(st + 0x20) = &words;
                            break;
                        }
                    }
                }
                char bufA[0x80];
                char bufB[0x80];
                Bufs021f2e6c bufs;
                __clear(bufA, 0x80);
                __clear(bufB, 0x80);
                NameText_Clear(&bufs);
                bufs.a = bufA;
                bufs.b = bufB;
                DispatchIfCountPositive020dcf7c(count, &bufs);
                *(Bufs021f2e6c**)(st + 0x18) = &bufs;

#endif
                ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, 0x3e);
#if defined(jpn)
                func_0204500c(var0, var10, 1);
#else
                func_0204500c(var0, var14, 1, 0xe3);
#endif

                var0[Enum_ov023_021f2e6c_6578] = 0;
                *(int*)(var0 + Enum_ov023_021f2e6c_2456) = 1;
                func_ov000_0215fa70(*(void**)(arg0 + Enum_ov023_021f2e6c_668), var6, 0, 0);
                var1[0] = 10;
                return *(int*)(arg0 + Enum_ov023_021f2e6c_3756);
            }
        }
        if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
            return 0xf;
        }
        if (func_ov023_021ed92c() != 0 && *(short*)(*(char**)(arg0 + Enum_ov023_021f2e6c_668) + 0x8e4a) == 0) {
            return 0xf;
        }
        int var23 = var3->unknown_0_;
        Struct_ov023_021f2e6c_3* var24 = var3->unknown_4_;
        int var25 = 0;
        for (int var26 = 0; var26 < var23; var26++) {
            if (var24[var26].unknown_0_.unknown_2_0_ && !var24[var26].unknown_0_.unknown_1_7_) {
                var25 = 1;
                break;
            }
        }
        if (var25 == 0) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
            return 0xf;
        }
        *(IdList021f2e6c**)(self + regionalOffset2) = (IdList021f2e6c*)((SafeAllocator*)(self + 0x30))->Allocate(0x18);
        *(Mgr021f2e6c**)(self + regionalOffset1) = (Mgr021f2e6c*)((SafeAllocator*)(self + 0x30))->Allocate(0x8a0);
        InitStruct020d784c((Buffer020d784c*)(*(IdList021f2e6c**)(self + regionalOffset2)));
        *(SafeAllocator**)(self + regionalOffset9) = (SafeAllocator*)((SafeAllocator*)(self + 0x30))->Allocate(0x14);
        (*(SafeAllocator**)(self + regionalOffset9))->CreateTypeA(((SafeAllocator*)(self + 0x30))->Allocate(0xf000), 0xf000);
        FontBankLoader* h = FontBankLoader_GetInstance();
        BlankFunction02094b40(h);
        BlankFunction02094b30(h, 0x210, 1);
        g[0] = 1;
    } else if (state == 10) {
        if (func_ov023_021f4fc8() != 0) {
            var1[0] = 0;
        }
    } else if (var5 == 11) {
#if defined(jpn)
        var1[2] = var2->QueueLoadFile(data_ov023_021fd5a2, 0);
#else
        var1[2] = var2->QueueLoadFileInGP2(&data_ov023_021fe2ca, &data_ov023_021fe2e5, 0);
#endif

        var1[0]++;
        return *(int*)(arg0 + Enum_ov023_021f2e6c_3756);
    } else if (var5 == 12) {
        if (var2->GetTaskStatus(var1[2]) != 0) {
            unsigned int var28;
            void* var29;
            var2->GetLoadedFileByID(var1[2], &var29, &var28);
            func_020d784c((Struct_020d784c*)(*(Struct_ov023_021f2e6c_5**)(arg0 + Enum_ov023_021f2e6c_21908)));
            int var30;
            Struct_ov023_021f2e6c_3* var31 = var3->unknown_4_;
            var30 = var3->unknown_0_;
            for (int var32 = 0; var32 < var30; var32++) {
                if (var31[var32].unknown_0_.unknown_2_0_ && !var31[var32].unknown_0_.unknown_1_7_) {
                    int var33 = var31[var32].unknown_0_.unknown_0_0_;
                    Struct_ov023_021f2e6c_5* var34 = *(Struct_ov023_021f2e6c_5**)(arg0 + Enum_ov023_021f2e6c_21908);
                    var34->unknown_4_[var34->unknown_14_++] = var33;
                }
            }
            func_020d7870(*(void**)(arg0 + Enum_ov023_021f2e6c_21908), arg0 + 0x30, (Struct_02013fb4*)var29, var28, 0);
            var2->RemoveTask(var1[2]);
            var1[2] = -1;
            var1[0] = 4;
            *(short*)(arg0 + Enum_ov023_021f2e6c_21948) = 1;
        }
    } else if (state == 1) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) != 0) {
            char* heap;
#if defined(jpn)
            char* var36 = arg0 + 0x3ec;
#else
            char* var37 = arg0 + 0x830;
#endif

#if defined(jpn)
            if (func_020deb08((Struct_020deb08*)(var36 + 0x3400)) <= 0) {
#else
            if (func_020deb08((Struct_020deb08*)(var37 + 0x3000)) <= 0) {
#endif

#if defined(jpn)
                func_020de868(var36 + 0x3400);
#else
                func_020de868(var37 + 0x3000);
#endif

                var35 = arg0 + Enum_ov023_021f2e6c_552;
                ((SafeAllocator*)(var35 + 0x5000))->Reset();
#if defined(jpn)
                func_020e052c(sub + 0x3400, heap + 0x5000, g_itemDataArchive, &data_ov023_021fd862, 3, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int size;
                void* file = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
                if (file != 0) {
                    func_020dea64(sub + 0x3000, heap + 0x5000, file, size, &data_ov023_021fd862, 3);

                }
                BackgroundLoader::RemoveLockGlobal();
#endif

            }
            var1[0] = 2;
        }
    } else if (state == 2) {
        found_entries = tbl->entries;
        int count = tbl->count;
        int found = 0;
        for (short i = *(short*)(self + regionalOffset4) + 1; i < count; i++) {
            if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0 || AreAllListedCombatantsFlagged_021ed92c() != 0) {
                if (*(short*)(*(char**)(self + regionalOffset5) + 0x8e4a) != found_entries[i].bits.id) {
                    continue;
                }
            }
            if (var4[var42].unknown_0_.unknown_2_0_ && !var4[var42].unknown_0_.unknown_1_7_) {
                *(short*)(arg0 + Enum_ov023_021f2e6c_21900) = var42;
                var41 = 1;
                break;
            }
        }
        if (var41 == 0) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
            return 0xf;
        }
        char var43[0x40];
        sprintf(var43, &data_ov023_021fe2f7, var4[*(short*)(arg0 + Enum_ov023_021f2e6c_21900)].unknown_0_.unknown_0_0_ / 50 + 1);
        var1[1] = var2->QueueLoadFile(var43, 0);
        var1[0] = 3;
    } else if (var5 == 3) {
        if (var2->GetTaskStatus(var1[1]) != 0) {
            unsigned int var44;
            void* var45 = 0;
            var2->GetLoadedFileByID(var1[1], &var45, &var44);
            if (var45 == 0) {
                func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
                return 0xf;
            }
            void* var46;
            var4 = var3->unknown_4_;
            (*(SafeAllocator**)(arg0 + Enum_ov023_021f2e6c_21952))->Reset();
            var46 = (*(SafeAllocator**)(arg0 + Enum_ov023_021f2e6c_21952))->Allocate(var44);
            memcpy(var46, var45, var44);
            var2->RemoveTask(var1[1]);
            var1[1] = -1;
            func_0209e3dc((char*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904)), (int)(*(void**)(arg0 + Enum_ov023_021f2e6c_668)));
            func_0209fd64(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904), *(SafeAllocator**)(arg0 + Enum_ov023_021f2e6c_21952), var46, var44);
            func_0209e46c((char*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904)));
            func_0209fe10((Struct_0209fe10*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904)), var4[*(short*)(arg0 + Enum_ov023_021f2e6c_21900)].unknown_0_.unknown_0_0_);
            var1[0] = 4;
        }
    } else if (var5 == 4) {
        if (*(short*)(arg0 + Enum_ov023_021f2e6c_21948) == 1) {
            *(short*)(arg0 + Enum_ov023_021f2e6c_21948) = 2;
        } else {
            func_0209fe18((Struct_0209fe18*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904)));
        }
        char* var47 = 0;
        int var48 = (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_6c_;
        if (var48 > 0) {
            if (*(short*)(arg0 + Enum_ov023_021f2e6c_21948) == 2) {
                var47 = func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(arg0 + Enum_ov023_021f2e6c_21908)), (short)var48);
            } else {
                var1[0] = 11;
                return *(int*)(arg0 + Enum_ov023_021f2e6c_3756);
            }
        }
        if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))) != 0 || var47 != 0) {
            Struct_ov023_021f2e6c_3* var49 = var3->unknown_4_;
            if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))) != 0) {
                if (var49[*(short*)(arg0 + Enum_ov023_021f2e6c_21900)].unknown_0_.unknown_1_6_) {
                    var49[*(short*)(arg0 + Enum_ov023_021f2e6c_21900)].unknown_0_.unknown_1_7_ = 1;
                }
            }
            if (var47 != 0) {
                func_02046380(var0);
                for (int var50 = 0; var50 < 4; var50++) {
                    func_020465c0((Struct_020465c0*)var0, var50, (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_70_[var50]);
                }
#if defined(jpn)
                func_0204500c(var0, func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(arg0 + Enum_ov023_021f2e6c_21908)), (short)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_6c_), 1);
#else
                func_0204500c(var0, func_020d794c((Struct_020d794c*)(*(Struct_ov023_021f2e6c_5**)(arg0 + Enum_ov023_021f2e6c_21908)), (short)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_6c_), 1, 0xe3);
#endif

                var0[Enum_ov023_021f2e6c_6578] = 0;
                *(int*)(var0 + Enum_ov023_021f2e6c_2456) = 1;
                int var51 = (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_84_;
                if (var51 > 0) {
                    unsigned char* var52 = func_ov000_02162d88(arg0, var51);
                    if (var52 != 0) {
                        GameState* var53 = GameState::GetInstance();
                        int var54 = 0xc0;
                        for (int var55 = 0xc0; var55 <= 0xc7; var55++) {
                            unsigned char* var56 = func_0200fea4(var53, var55);
                            if (var56 != 0 && *(int*)(var56 + 0x138) != 0) {
                                var54 = var55;
                                break;
                            }
                        }
                        unsigned char* obj = GetCombatantWithFlag0x400_0200fea4(gs, idx);
                        int saved = *(int*)(obj + 0x138);
                        if (obj != 0 && saved != 0) {
                            int p13c = *(int*)(obj + 0x13c);
                            int p144 = *(int*)(obj + 0x144);
                            ResetNameState02048614(obj);
                            *(short*)(obj + 4) = idx;
                            func_02049c88(obj, p13c);
                            SetupFieldsFromParam02048850((Obj02048850*)obj, (Param02048850*)p144);
                            CopyObjectFields02048588(node, obj);
                            *(int*)(obj + 0x138) = saved;
                            ((Object3D*)obj)->SetField06(*(unsigned short*)(self + regionalOffset11));
                            GameObject_ForceMotionState((Bytes02033b88*)obj, 0);
                            obj[0xc2] |= 0x20;
                            ((Object3D*)obj)->SetInheritedAlpha(0x1f);
                            ((Object3D*)obj)->MakeVisible();
                            SetSubstructByte0x56_02049f28(obj);
                            void* cam = func_ov000_02160f14(self);
                            func_ov000_0216d370(cam, 1, 1, 1);
                            SetFlagOrState0216d530(cam, idx);
                            int height = ((Object3D*)obj)->GetHeight();
                            int y = (int)(((long long)height * 0x4cc + 0x800) >> 12);
                            if (y < 0) {
                                y = 0;
                            }
                            Camera_SetTarget((struct Camera*)cam, 0, y, 0);
                            int z = (int)(((long long)height * 0x2333 + 0x800) >> 12);
                            int y2 = y + 0x800;
                            if (y2 < 0) {
                                y2 = 0;
                            }
                            Camera_SetOrbit(cam, 0, y2, z + 0x4000);
                            func_ov000_02163b90(self, 0);
                            *(short*)(self + regionalOffset12) = idx;
                        }
                    }
                }
                var1[0]++;
            } else {
                var1[0] = 6;
            }
        }
    } else if (var5 == 5) {
        int var66 = 0;
        if (func_ov023_021f4fc8() != 0 || *(unsigned char*)(arg0 + Enum_ov023_021f2e6c_21950) != 0) {
            Struct_ov023_021f2e6c_6* var67 = *(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904);
            if (var67->unknown_84_ > 0 && *(short*)(arg0 + Enum_ov023_021f2e6c_21946) > 0) {
                if (var67->unknown_88_ != 0) {
                    GameState* var68 = GameState::GetInstance();
                    unsigned char* var69 = (unsigned char*)var68->GetGameObjectByIndex(*(short*)(arg0 + Enum_ov023_021f2e6c_21946));
                    if (var69 != 0) {
                        int var70 = ((Object3D*)var69)->GetInheritedAlpha();
                        if (*(unsigned char*)(arg0 + Enum_ov023_021f2e6c_21950) == 0 && var70 == 0x1f) {
                            ((Object3D*)var69)->TransitionInheritedAlpha(0, 500);
                            *(unsigned char*)(arg0 + Enum_ov023_021f2e6c_21950) = 1;
                        }
                        if (var70 <= 0) {
                            ((Object3D*)var69)->MakeHidden();
                            func_02049f3c(var69);
                            *(unsigned char*)(arg0 + Enum_ov023_021f2e6c_21950) = 0;
                            void* var71 = func_ov000_02160f14(arg0);
                            Struct_ov023_021f2e6c_9 var72 = *func_0202ed64(var71);
                            func_ov000_0216d2d0(var71);
                            func_0202ed0c((Struct_0202ed0c_2*)var71, (Struct_0202ed0c*)&var72);
                            func_02048614(var69);
                            *(short*)(arg0 + Enum_ov023_021f2e6c_21946) = 0;
                            var66 = 1;
                        }
                    }
                }
            } else {
                var66 = 1;
            }
        }
        if (var66 != 0) {
            if (func_ov023_021f3a8c((Struct_ov023_021f2e6c_2*)(*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))) != 0) {
                var1[0]++;
            } else {
                (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_6c_ = -1;
                (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_84_ = 0;
                var1[0] = 4;
            }
        }
    } else if (var5 == 6) {
        int var73 = (*(Struct_ov023_021f2e6c_6**)(arg0 + Enum_ov023_021f2e6c_21904))->unknown_8c_;
        if (var73 != 0) {
            *(int*)(arg0 + Enum_ov023_021f2e6c_21912 + *(short*)(arg0 + Enum_ov023_021f2e6c_21944) * 4) = var73;
            (*(short*)(arg0 + Enum_ov023_021f2e6c_21944))++;
        }
        var1[0] = 2;
    }
    return *(int*)(arg0 + Enum_ov023_021f2e6c_3756);
}
