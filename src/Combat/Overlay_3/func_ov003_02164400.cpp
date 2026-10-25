#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"
#include "Input/Input.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
#else
#define REGIONAL_OFFSET(jp, us) us
#endif
#define HI(x) REGIONAL_OFFSET((x) - 0x1d8, x)
#define LO(x) REGIONAL_OFFSET((x) - 0x118, x)
enum { Enum_ov003_02164400_55 = REGIONAL_OFFSET(0x1b, 0x37) };

struct Struct_0207fdcc_2 { char unknown_0_[REGIONAL_OFFSET(0x2a, 0x36)]; unsigned short unknown_36_; };

struct Struct_0207fe44;
struct Struct_02038598_4;
struct Struct_02081f20_2;
struct Struct_020a9ea4;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_ov003_02164400;
struct Struct_020469f8;
struct Struct_020469f8_2;
struct Struct_0202bad4_2;
struct Struct_0202bad4;
struct Random;
struct SePlayer;

void* GlobalFlags_GetInstance(void);
int* GetGlobal02109030_020936f8(void);
extern "C" void* func_0202ae18(void);

extern "C" void func_ov003_021612c0(void* arg0);
extern "C" int func_ov003_02161344(void* arg0);
extern "C" int func_ov003_02160a68(void* arg0);
extern "C" int func_ov003_02160854(void* arg0);
extern "C" void func_ov003_0215f698(void* arg0, void* arg1);
struct Struct_ov003_02164400_2;
extern "C" void* func_ov003_0215f650(struct Struct_ov003_02164400_2* arg0, struct Struct_ov003_02164400_2* arg1);
extern "C" void func_ov003_021666c4(void* arg0);
extern "C" void func_ov003_0216664c(void* arg0);
extern "C" void func_ov003_02160344(void* arg0);
extern "C" void func_ov017_021c36a0(void);
extern "C" void func_ov017_021aeedc(struct Struct_ov003_02164400* arg0);
extern "C" void func_020469f8(struct Struct_020469f8* arg0, struct Struct_020469f8_2* arg1);

void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char* obj);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
int IsElementFieldActive020811e8(struct Obj2081* obj, int key);
void CallFunc0204c804OnMatchingKey_0207fdcc(struct Obj2081* obj, int key);
void UpdateEntryFlagsNibble02080cec(void* obj, int a, int b);
void DispatchEntryOp0x8_0208108c(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_0202b0f4(int* obj);
void* MessageSystem_GetInstance(void);
extern "C" int func_020aad1c(int a, int b, int c, int d);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
short FindMappedMemberId02080468(void* obj, int id);
void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
int GetField0xc_0202bae4(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
extern "C" int memcmp(int val, int key, int field5);
struct Random* GetBTRandom(void);
int NextRandomMax(struct Random* random, int maximum);
void SetSublistEntriesFlag1_02080b54(void* obj, int id);
int SetEntryFlagById02080b40(void* obj, int id);
extern struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081*, int);
int WindowPane_IsReady(unsigned char* obj);

extern int g_fileLoadBuffer;
extern struct SePlayer g_sePlayer;

struct Struct_ov003_02164400_3 { char unknown_0_[REGIONAL_OFFSET(0x7fb, 0x9ca)]; unsigned char unknown_9ca_; };

struct Struct_ov003_02164400_4 { unsigned char unknown_0_0_ : 1; unsigned char unknown_0_1_ : 6; unsigned char unknown_0_7_ : 1; };
struct Struct_ov003_02164400_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 6;
    unsigned char unknown_0_7_ : 1;
    char unknown_1_[REGIONAL_OFFSET(0x14, 0x30)];
    unsigned char unknown_31_[6];
};

static inline int inline_ov003_02164400(unsigned char* arg0, unsigned int arg1) {
    return (*(unsigned int*)(arg0 + HI(0x464)) & arg1) != 0;
}

static inline void inline_020def98(struct Struct_ov003_02164400_2* arg0, struct Struct_ov003_02164400_2* arg1) {
    struct Struct_ov003_02164400_2 var0 = *arg1;
    func_ov003_0215f650(arg1, arg0);
    func_ov003_0215f650(arg0, &var0);
}

// USA: func_ov003_02164400
extern "C" ARM void func_ov003_02164400(unsigned char* self) {
    unsigned char* cur;
    void* flagWord;
    int* globalPtr;
    void* r8val;
    struct Obj2081* elementObj;
    short* msg484;
    unsigned char state;
    int work;
    flagWord = GlobalFlags_GetInstance();
    globalPtr = GetGlobal02109030_020936f8();
    r8val = func_0202ae18();
    state = self[HI(0x4a4)];
    elementObj = *(struct Obj2081**)(self + LO(0x324));
    msg484 = (short*)(self + HI(0x484));

    if (var6 == 0) {
        func_ov003_021612c0(arg0);
        arg0[HI(0x4a4)] = 1;
        return;
    }
    if (var6 == 1) {
        int var8 = func_ov003_02161344(arg0);
        if (var8 != -1) {
            if (var8 == 1) {
                arg0[HI(0x4a4)] = 2;
                func_0207fe44((struct Struct_0207fe44*)var4);
                func_020939fc((unsigned char*)var2);
            }
        } else {
            *(short*)(arg0 + HI(0x488)) = 0x19;
            *(short*)(arg0 + HI(0x48a)) = 0xa6;
            *(short*)(arg0 + HI(0x474)) = 0xa6;
            var5[0] = 5;
            var5[1] = 1;
            arg0[HI(0x4a3)] = 0xa;
            arg0[HI(0x4a4)] = 1;
        }
        return;
    }
    if (var6 == 2) {
        var5[0] = 0x35;
        arg0[HI(0x4a4)] = 3;
        if (arg0[HI(0x4be)] == 0) return;
        *(short*)(arg0 + HI(0x484)) = 6;
        arg0[HI(0x4a4)] = 5;
        return;
    }
    if (var6 == 3) {
        func_ov003_021612c0(arg0);
        arg0[HI(0x4a4)] = 4;
        return;
    }
    if (var6 == 4) {
        int var9 = func_ov003_02161344(arg0);
        if (var9 != -1) {
            if (var9 == 1) {
                var5[0] = 0x1a;
                arg0[HI(0x4a4)] = 0xb;
            }
        } else {
            var5[0] = 0x34;
            var5[1] = 1;
            arg0[HI(0x4a3)] = 0xa;
            arg0[HI(0x4a4)] = 0;
        }
        return;
    }
    if (var6 == 0xb) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() != 0) return;
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x80);
        ClearStruct020a9ea4((struct Struct020a9ea4*)(self + HI(0x4b4)));
        self[HI(0x4a4)] = 0xc;
        return;
    }
    if (var6 == 0xc) {
        *(unsigned int*)(arg0 + HI(0x464)) |= 0x2000000;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c((int)(self + HI(0x4b4)), (int)&g_fileLoadBuffer, 0xa, 0) == 1) {
            self[HI(0x4be)] = 1;
            *(unsigned int*)(self + HI(0x464)) &= ~0x2000000u;
            *(short*)(self + HI(0x484)) = 0x30;
            *(short*)(self + HI(0x486)) = 6;
            self[HI(0x4a4)] = 5;
            FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        }
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (var6 == 5) {
        if (func_020811e8(var4, 0x10) != 0) {
            *(int*)(arg0 + HI(0x45c)) = 0;
            func_0207fdcc(var4, 0x10);
            *(unsigned int*)(arg0 + HI(0x464)) |= 0x180000;
        } else {
            memset(arg0, 0, LO(0x226));
            *(short*)(arg0 + LO(0x226)) = 0;
            func_02080cec(var4, 0xf, 0xf);
#if !defined(jpn)
            func_0208108c(var4, 0x43);
            func_0208108c(var4, 0x44);
#endif
            func_020813ec(var4, 0xf);
            func_0208203c((struct Struct_02081f20_2*)(arg0 + LO(0x308)));
            *(void**)(arg0 + HI(0x470)) = 0;
            arg0[HI(0x4a4)] = 6;
            func_0202b0f4((int*)var3);
            func_020939fc((unsigned char*)var2);
            func_ov017_021c36a0();
            *(short*)(self + HI(0x476)) = 0;
            *(short*)(self + HI(0x478)) = 0;
            ResetAndSetFlag0x3c9Bit0_020939dc((unsigned char*)globalPtr);
            FlagWord_ClearBits((struct FlagWord020466f4*)flagWord, 0x20);
        }
        return;
    }
    if (var6 == 6) {
        *(void**)(arg0 + HI(0x470)) = 0;
        func_ov003_0215f698(arg0, arg0 + LO(0x226));
        if (*(short*)(arg0 + LO(0x226)) != 0) {
            *(unsigned short*)(arg0 + HI(0x476)) = *(unsigned short*)(arg0 + HI(0x476)) + *(int*)(arg0 + HI(0x460));
            *(short*)(arg0 + HI(0x478)) = 0;
            if (*(unsigned short*)(arg0 + HI(0x476)) > 0x3c) {
                var5[0] = 0xa;
                func_0207fdcc(var4, 0xf);
                arg0[HI(0x4a4)] = 7;
                return;
            }
        } else {
            *(short*)(arg0 + HI(0x476)) = 0;
            *(unsigned short*)(arg0 + HI(0x478)) = *(unsigned short*)(arg0 + HI(0x478)) + *(int*)(arg0 + HI(0x460));
            if (*(unsigned short*)(arg0 + HI(0x478)) > 0x12c) {
                func_02080cec(var4, 0xf, 2);
                func_020813ec(var4, 0xf);
                func_0207fe44((struct Struct_0207fe44*)var4);
                *(unsigned int*)(arg0 + HI(0x464)) |= 0x80000;
                var5[0] = 7;
                var5[1] = 1;
                arg0[HI(0x4a3)] = 0xa;
                arg0[HI(0x4a4)] = 0;
                func_0202b0f4((int*)var3);
                func_020939fc((unsigned char*)var2);
                return;
            }
        }
        if (func_ov003_02160a68(arg0) == 0) return;
        {
            ((struct GlobalBig1000*)((char*)MessageSystem_GetInstance() + 0x1000))->flag9ca = 1;
        }
        func_0207fe44((struct Struct_0207fe44*)var4);
        *(unsigned int*)(arg0 + HI(0x464)) |= 0x80000;
        var5[0] = 9;
        var5[1] = 1;
        arg0[HI(0x4a3)] = 0xa;
        arg0[HI(0x4a4)] = 0;
        func_0202b0f4((int*)var3);
        func_020939fc((unsigned char*)var2);
        return;
    }
    if (var6 == 7) {
        short* var10 = (short*)(arg0 + LO(0x226));
        while (*(short*)(arg0 + LO(0x226)) > 8) {
            struct Random* var11 = GetBTRandom();
            int var12 = NextRandomMax(var11, *(short*)(arg0 + LO(0x226)));
            int var13;
            memset(arg0 + var12 * Enum_ov003_02164400_55, 0, Enum_ov003_02164400_55);
            *var10 = *var10 - 1;
            for (var13 = var12; var13 != *(short*)(arg0 + LO(0x226)); ) {
                func_ov003_0215f650((struct Struct_ov003_02164400_2*)(arg0 + var13 * Enum_ov003_02164400_55), (struct Struct_ov003_02164400_2*)(arg0 + (var13 + 1) * Enum_ov003_02164400_55));
                var13++;
                arg0[var13 * Enum_ov003_02164400_55] &= ~0x80;
            }
        }

        {
            struct Struct_ov003_02164400_2* var14 = (struct Struct_ov003_02164400_2*)arg0;
            short var15;
            int var16;
            for (var16 = 0; var16 < ((short*)arg0)[REGIONAL_OFFSET(0x87, 0x113)] - 1; var16 = (short)(var16 + 1)) {
                struct Struct_ov003_02164400_2* var17;
                struct Struct_ov003_02164400_2* var18 = &var14[(short)var16];
                for (var15 = var16 + 1; var15 < *(short*)(arg0 + LO(0x226)); var15++) {
                    var17 = &var14[var15];
                    if (strcmp(var18->unknown_1_, var17->unknown_1_) == 1) {
                        inline_020def98(var18, var17);
                    }
                }
            }
            for (var16 = 0; var16 < ((short*)arg0)[REGIONAL_OFFSET(0x87, 0x113)] - 1; var16 = (short)(var16 + 1)) {
                struct Struct_ov003_02164400_2* var19;
                struct Struct_ov003_02164400_2* var20 = &var14[(short)var16];
                for (var15 = var16 + 1; var15 < *(short*)(arg0 + LO(0x226)); var15++) {
                    var19 = &var14[var15];
                    if (strcmp(var20->unknown_1_, var19->unknown_1_) == 0 && var20->unknown_0_1_ < var19->unknown_0_1_) {
                        struct Struct_ov003_02164400_2 var21 = *var19;
                        func_ov003_0215f650(var19, var20);
                        func_ov003_0215f650(var20, &var21);
                    }
                }
            }
        }

        {
        short* var22 = (short*)0 + 7;
        func_02081198((struct Struct_02081198*)var4, (int)var22, 1);
        func_02081164((struct Struct_02081164*)var4, (int)var22, 1);
        func_020813ec(var4, (int)var22);
        }
        *(unsigned int*)(arg0 + HI(0x464)) |= 0x180000;
        *(short*)(arg0 + HI(0x488)) = 0x10;
        {
            short var23 = func_02080468(var4, *(short*)(arg0 + HI(0x488)));
            *(short*)(arg0 + HI(0x496)) = var23;
            *(short*)(arg0 + HI(0x474)) = var23;
        }
        var4->unknown_36_ = *(short*)(arg0 + HI(0x496));
        arg0[HI(0x4a0)] = 0;
        func_ov003_021666c4(arg0);
        func_0208203c((struct Struct_02081f20_2*)(arg0 + LO(0x308)));
        *(void**)(arg0 + HI(0x470)) = 0;
        arg0[HI(0x4a4)] = 8;
        *(short*)(arg0 + HI(0x478)) = 0;
        return;
    }
    if (var6 == 8) {
        *(unsigned int*)(arg0 + HI(0x464)) |= 1;
        *(void**)(arg0 + HI(0x470)) = arg0 + HI(0x496);
        func_ov003_0216664c(arg0);
        *(unsigned short*)(arg0 + HI(0x478)) = *(unsigned short*)(arg0 + HI(0x478)) + *(int*)(arg0 + HI(0x460));
        var7 = 0;
        if (*(unsigned short*)(arg0 + HI(0x478)) > 0x3c) {
            func_ov003_021666c4(arg0);
            *(unsigned short*)(arg0 + HI(0x478)) = *(unsigned short*)(arg0 + HI(0x478)) - 0x3c;
            var7 = 1;
        }
        func_ov003_0215f698(arg0, arg0 + LO(0x226));
        if (var7 == 0 && inline_ov003_02164400(arg0, 0x1000000)) {
            func_ov003_021666c4(arg0);
        }
        if (func_ov003_02160854(self) != 0) {
            int idx = FindMappedMemberId02080468(elementObj, *(short*)(self + HI(0x488)));
            *(short*)(self + HI(0x498)) = *(short*)(self + HI(0x496)) - idx;
            *(short*)(self + HI(0x498)) = *(short*)(self + HI(0x498)) + (((signed char)self[HI(0x4a0)]) << 2);
            if (*(short*)(self + HI(0x498)) < *(short*)(self + LO(0x226))) {
                SePlayer_Play(&g_sePlayer, 1, 0);
                ResetWithSub0208203c((struct Obj0208203c*)(self + LO(0x308)));
                *(void**)(self + HI(0x470)) = 0;
                struct RecordByte0* rb = (struct RecordByte0*)(self + (*(short*)(self + HI(0x498))) * kRec37);
                int inv = 4 - rb->rank;
                if (rb->used == 0) {
                    msg484[0] = 0x37;
                    self[HI(0x4a4)] = 5;
                } else if (inv == 0) {
                    msg484[0] = 0x33;
                    self[HI(0x4a4)] = 5;
                } else {
                    ((struct GlobalBig1000*)((char*)MessageSystem_GetInstance() + 0x1000))->flag9ca = 0;
                    msg484[0] = 0xb;
                    self[HI(0x4a4)] = 9;
                }
                *(unsigned int*)(arg0 + HI(0x464)) |= 4;
                return;
            }
        }
        if (func_ov003_02160a68(arg0) == 0) return;
        func_0207fe44((struct Struct_0207fe44*)var4);
        var5[0] = 1;
        arg0[HI(0x4a3)] = 0xa;
        arg0[HI(0x4a4)] = 0;
        *(unsigned int*)(arg0 + HI(0x464)) = (*(unsigned int*)(arg0 + HI(0x464)) | 0x80000) & ~0xf00000u;
        func_0202b0f4((int*)var3);
        func_020939fc((unsigned char*)var2);
        return;
    }
    if (var6 == 9) {
        func_ov003_021612c0(arg0);
        arg0[HI(0x4a4)] = 0xa;
        return;
    }
    if (var6 == 0xa) {
        int var27 = func_ov003_02161344(arg0);
        if (var27 != -1) {
            if (var27 == 1) {
                *(short*)(arg0 + HI(0x47a)) = 0;
                arg0[HI(0x4a4)] = 0xd;
                var5[0] = 0x38;
                *(unsigned int*)(arg0 + HI(0x464)) |= 4;
                func_0207fdcc(var4, 0x10);
                func_0207fdcc(var4, 0xe);
                *(unsigned int*)(arg0 + HI(0x464)) |= 0x80000;
            }
        } else {
            var5[0] = 0xc;
            arg0[HI(0x4a4)] = 5;
        }
        return;
    }
    if (var6 == 0xd) {
        if (*(unsigned short*)(arg0 + HI(0x47a)) == 0) {
            *(short*)(arg0 + HI(0x488)) = 0x11;
            func_02080b54(var4, 0x11);
            func_02080b40(var4, 0x51);
#if !defined(jpn)
            func_0208108c(var4, 0x51);
#endif
            func_020813ec(var4, *(short*)(arg0 + HI(0x488)));
            func_0208203c((struct Struct_02081f20_2*)(arg0 + LO(0x308)));
            *(void**)(arg0 + HI(0x470)) = 0;
            *(unsigned short*)(arg0 + HI(0x47a)) = *(unsigned short*)(arg0 + HI(0x47a)) + 1;
        }
        void* var28 = func_02081da8(var4, 0x11);
        if (var28 == 0) {
            *(short*)(arg0 + HI(0x484)) = 0x30;
            arg0[HI(0x4a4)] = arg0[HI(0x4a4)] + 1;
            *(short*)(arg0 + HI(0x47a)) = 0;
            arg0[HI(0x4a4)] = 0xe;
        }
        if (WindowPane_IsReady((unsigned char*)found) == 0) return;
        *(short*)(self + HI(0x47a)) = 0;
        self[HI(0x4a4)] = 0xe;
        return;
    }
    if (var6 == 0xe) {
        int var29 = 0;
        if (*(unsigned short*)(arg0 + HI(0x47a)) > 0x78 || func_ov003_02160a68(arg0) != 0 ||
            g_touchInput.pressed_ != 0) {
            var29 = 1;
        }

        void* arr;
        int idx;
        int count;
        cur = self + (*(short*)(self + HI(0x498))) * kRec37;
        arr = func_0202ae18();
        count = GetField0xc_0202bae4(arr);
        for (idx = 0; idx < count; idx++) {
            struct Element0202bad4* elem = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)arr, idx);
            if (memcmp((int)(cur + REGIONAL_OFFSET(0x15, 0x31)), (int)((char*)elem + 4), 6) == 0) goto found;
        }
        var31 = -1;
    var28:
        {
        if (idx < 0 || ((struct RecordByte0*)(self + (*(short*)(self + HI(0x498))) * kRec37))->used == 0) {
            if (flag != 0) {
                CallFunc0204c804OnMatchingKey_0207fdcc(elementObj, 0x11);
                ((struct GlobalBig1000*)((char*)MessageSystem_GetInstance() + 0x1000))->flag9ca = 1;
                msg484[0] = 0x37;
                *(unsigned int*)(self + HI(0x464)) |= 4;
                *(short*)(self + HI(0x47a)) = 0;
                self[HI(0x4a4)] = 5;
                func_ov003_02160344(self);
            } else {
                *(unsigned short*)(arg0 + HI(0x47a)) = *(unsigned short*)(arg0 + HI(0x47a)) + 1;
            }
            return;
        }

        *(int*)(self + HI(0x4b0)) = 0;
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x80000);
        {
            char* var34 = (char*)GetGameResources() + 0x3000;
            struct Struct_ov003_02164400* var35 = *(struct Struct_ov003_02164400**)(var34 + REGIONAL_OFFSET(0x90c, 0xb2c));
            struct Struct_020469f8* var36 = *(struct Struct_020469f8**)(var34 + REGIONAL_OFFSET(0x4ec, 0x6fc));
            func_ov017_021aeedc(var35);
            memcpy((char*)var35 + 9, arg0 + (*(short*)(arg0 + HI(0x498))) * Enum_ov003_02164400_55 + REGIONAL_OFFSET(0x15, 0x31), 6);
            {
                int var37;
                for (var37 = 0; var37 < 6; var37++) { }
            }
            func_020469f8(var36, (struct Struct_020469f8_2*)var35);
        }
        *(short*)(arg0 + HI(0x47a)) = 0;
        arg0[HI(0x4a4)] = 0xf;
        return;
        }
    }
    if (var6 == 0xf) {
        char* var38 = (char*)GetGameResources() + 0x3000;
        void* var39 = *(void**)(var38 + REGIONAL_OFFSET(0x90c, 0xb2c));
        signed char var40 = *((signed char*)var39 + 0xf);
        if (var40 == 1) {
            func_0207fdcc(var4, 0x11);
            arg0[HI(0x4a4)] = 0x11;
        } else if (var40 == -1) {
            func_0207fe44((struct Struct_0207fe44*)var4);
            *(short*)(arg0 + HI(0x47a)) = 0;
            arg0[HI(0x4a4)] = 5;
            func_ov003_02160344(arg0);
        } else if (var40 == 0) {
            func_0207fe44((struct Struct_0207fe44*)var4);
            var5[0] = 0x37;
            *(short*)(arg0 + HI(0x47a)) = 0;
            arg0[HI(0x4a4)] = 5;
            *(unsigned int*)(arg0 + HI(0x464)) |= 4;
        }
        *(short*)(arg0 + HI(0x47a)) = 0;
        return;
    }
    if (state == 0x11) {
        ((struct GlobalBig1000*)((char*)MessageSystem_GetInstance() + 0x1000))->flag9ca = 0;
        msg484[0] = 0x36;
        *(unsigned int*)(self + HI(0x464)) |= 0x0c004042;
        self[HI(0x4a3)] = 6;
        self[HI(0x4a4)] = 0;
        return;
    }
}
