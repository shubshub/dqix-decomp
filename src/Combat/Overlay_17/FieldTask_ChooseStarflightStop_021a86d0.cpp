#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

#if defined(jpn)
extern "C" char data_ov017_021d7c0c[];
extern "C" void func_0205dfa8(void* arg0);
enum { Enum_ov017_021a86d0_5120 = 0x1000, Enum_ov017_021a86d0_736 = 0x230, Enum_ov017_021a86d0_14076 = 0x34ec, Enum_ov017_021a86d0_14092 = 0x34fc, Enum_ov017_021a86d0_14132 = 0x3524, Enum_ov017_021a86d0_612 = 0x1f4, Enum_ov017_021a86d0_607 = 0x1ef, Enum_ov017_021a86d0_2456 = 0x868, Enum_ov017_021a86d0_2464 = 0x870, Enum_ov017_021a86d0_2324 = 0x7e4, Enum_ov017_021a86d0_2328 = 0x7e8, Enum_ov017_021a86d0_2326 = 0x7e6, Enum_ov017_021a86d0_6574 = 0x17de, Enum_ov017_021a86d0_10164 = 0x27f4, Enum_ov017_021a86d0_10271 = 0x285f };
#else
enum { Enum_ov017_021a86d0_5120 = 0x1400, Enum_ov017_021a86d0_736 = 0x2e0, Enum_ov017_021a86d0_14076 = 0x36fc, Enum_ov017_021a86d0_14092 = 0x370c, Enum_ov017_021a86d0_14132 = 0x3734, Enum_ov017_021a86d0_612 = 0x264, Enum_ov017_021a86d0_607 = 0x25f, Enum_ov017_021a86d0_2456 = 0x998, Enum_ov017_021a86d0_2464 = 0x9a0, Enum_ov017_021a86d0_2324 = 0x914, Enum_ov017_021a86d0_2328 = 0x918, Enum_ov017_021a86d0_2326 = 0x916, Enum_ov017_021a86d0_6574 = 0x19ae, Enum_ov017_021a86d0_10164 = 0x27b4, Enum_ov017_021a86d0_10271 = 0x281f };
#endif

struct Struct_ov017_021a86d0_2 {
    char unknown_0_[0x4];
    unsigned char unknown_4_[0x1c];
    unsigned char unknown_20_[0x50];
    unsigned char unknown_70_[0x40];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[2];
    short unknown_b4_;
    short unknown_b6_;
    short unknown_b8_;
    short unknown_ba_;
    char unknown_bc_[Enum_ov017_021a86d0_607 - 0xe8];
    unsigned char unknown_233_;
    unsigned char unknown_234_;
    char unknown_235_[3];
};

struct Struct_ov017_021a86d0 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    unsigned char unknown_18_[5];
    char unknown_1d_[3];
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    unsigned char unknown_2c_[Enum_ov017_021a86d0_612 - 0x2c];
    unsigned char unknown_264_[0x14];
    unsigned char unknown_278_[0x10];
};

char* MessageSystem_GetInstance(void);
extern "C" char* Zone3D_GetInstance(void);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void* TextQueue_GetInstance(void);
struct Obj020d7aa0;
void TextQueue_Reset(Obj020d7aa0*);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int plane1, int plane2, int ev1, int ev2);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* arg0, int arg1);
extern "C" Vector3fix func_020406f8(void* arg0);
extern "C" int fix32_Atan2(int arg0, int arg1);
#include "Combat/EntryGetterTypes.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void KeyTable_Load(void* cont, void* alloc, void* data, unsigned int length);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov017_021a933c(void* obj, int key);
void InitBigStruct0205c790(char*);
struct GridCursor;
void GridCursor_SetDimensions(GridCursor*, int, int, int);
void GridCursor_SetCount(GridCursor*, int);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
void ProcessCombatEntry0205cb74(char*, int);
extern "C" void func_0205cc50(void* obj, int a, int b);
struct Struct_0205bcdc;
void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int value);
struct ResetBytesAndSetByte0x16Data;
void ResetBytesAndSetByte0x16_0205c77c(ResetBytesAndSetByte0x16Data*, int);
void SetupGlobalObjType1AndInitSelfPointer_0205cd28(unsigned char* obj);
struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
int GetScaledSumIfActive0205cecc(void* obj);
int CallFunc0205c570AtField0x1c_0205cb64(void* obj);
void MessageSystem_Reset(char* obj);
void SetupGlobalObjType3AndInitSelfPointer_0205ce50(unsigned char* obj);
extern "C" int func_020457e0(char* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
unsigned char* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
void InitContext020e1154(void* p);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char, unsigned short);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
void InitAndResetHeader_0219e310(unsigned char* obj, int arg);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void InitAndAppendState61_021a65c4(void* obj, unsigned char mode, int arg);
extern "C" void func_ov017_021baedc(unsigned char* node, int arg);
int GetField5cb0Value_0201079c(char*);
int GetField5cb4Value_020107d0(char*);
int GetField5cb8Value_02010804(char*);
int Scenario_TestFlag(int, unsigned char*, int);
int ReturnZero_021a01b4(char* res, int value);
void SetField11c_021bbbf8(void*, unsigned short);
void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021a92a0(Self021a86d0* self);

extern char data_ov017_021d77f0[];
extern char data_ov017_021d780a[];
extern char g_mainAllocator[];
extern char g_sePlayer[];

static inline unsigned int inline_ov017_021a86d0(void) {
    return (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
}

static inline void inline_ov017_021a86d0_2(unsigned int arg0) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (arg0 << 8);
}

// Overlay 17, originally func_ov017_021a86d0 (USA/EUR 0x021a86d0, JPN 0x021a8ecc)
extern "C" ARM void FieldTask_ChooseStarflightStop(Self021a86d0* self, void* list) {
    GameState* gs = GameState::GetInstance();
    char* g = MessageSystem_GetInstance();
    char* flags = Zone3D_GetInstance();
    Sub021a86d0* sub = (Sub021a86d0*)self->sub;
    SetupAndDispatch0205c904(self->sub, gs->GetTickCount());

    if (self->state == 0) {
        TextQueue_Reset((Obj020d7aa0*)TextQueue_GetInstance());
        self->planes = GX_GetVisiblePlane();
        GX_SetVisiblePlane(0x11);
        GameObject_DisableControl((Obj020397cc*)gs->GetProtagonist(), 1);
        SetFlags04(GetGameResources(), 0x40);
        ColorEffect_ConfigureAlphaBlend((void*)0x4000050, 0x10, 1, 0x1f, 0);
        void* var4 = func_0203cf4c();
        void* var5 = NULL;
        if (arg0->unknown_14_ == 0) {
            var5 = func_0203df78(var4, 2);
        } else if (arg0->unknown_14_ == 1) {
            var5 = func_0203df78(var4, 0xcb);
        }
        if (var5 != NULL) {
            GameObject* var6 = var0->GetUnknownGameObject();
            Vector3fix var7 = func_020406f8(var5);
            Vector3fix var8;
            Vector3fix_Subtract(&var6->obj3D_.position_, &var7, &var8);
            Vector3fix_Normalize(&var8, &var8);
            int var9 = fix32_Atan2(var8.x, var8.z);
            if (var9 < 0) {
                var9 += 0x6488;
            }
            func_02040af0((Struct_0203dce4*)var5, var9);
        }
        FontBankLoader* snd = FontBankLoader_GetInstance();
        BlankFunction02094b30(snd, 0x205, 0);
        if (AlwaysTrue02094b4c(snd)) {
#if defined(jpn)
            arg0->unknown_28_ = ((BackgroundLoader*)BackgroundLoader::GetInstance())->QueueLoadFile(data_ov017_021d7c0c, (SafeAllocator*)NULL);
#else
            arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d77f0, data_ov017_021d780a, NULL);
#endif
            ((SafeAllocator*)self->allocator)->CreateTypeA(AllocatorUnion_AllocateRounded((AllocatorUnion*)g_mainAllocator, WorkBuffer), WorkBuffer);
            self->state = 1;
        }
    } else if (self->state == 1) {
        void* loader = BackgroundLoader::GetInstance();
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task, &data, &length);
            ((SafeAllocator*)self->allocator)->Reset();
            KeyTable_Load(self->container, self->allocator, data, length);
            ((BackgroundLoader*)loader)->RemoveTask(self->task);
            self->task = -1;
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)((char*)gs->GetProtagonist() + 0x134));
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_ov017_021a933c(self, 0x64);
            *(int*)(g + MessageState) = 1;
            self->state = 2;
        }
    } else if (arg0->unknown_8_ == 2) {
        if (*(int*)(var1 + Enum_ov017_021a86d0_2464) == 3) {
            arg0->unknown_20_ = 0;
            for (int var14 = 0; var14 < 5; var14++) {
                if (arg0->unknown_18_[var14]) {
                    arg0->unknown_20_++;
                }
            }
            InitBigStruct0205c790((char*)self->sub);
            sub->dd = 1;
            sub->dc = 1;
            int count = self->count;
            GridCursor_SetDimensions((GridCursor*)sub->table4c, 1, count + 1, 0);
            GridCursor_SetDimensions((GridCursor*)sub->table9c, 1, count + 1, 0);
            GridCursor_SetCount((GridCursor*)sub->table4c, count + 1);
            GridCursor_SetCount((GridCursor*)sub->table9c, count + 1);
            int offset = 0;
            for (int j = 0; j < self->count; j++) {
                if (self->members[j] == 4) {
                    offset = 0xc;
                }
                ProcessCombatEntry0205cb74((char*)self->sub, (int)(KeyTable_Get((Container020e0310*)self->container, self->members[j])));
            }
            ProcessCombatEntry0205cb74((char*)self->sub, (int)(KeyTable_Get((Container020e0310*)self->container, 6)));
            int n = self->count;
            int y = 0x60 - (n + 1) * 0xe;
            if (n == 2) {
                y = 0x38;
            }
            if (var18 == 4) {
                var19 = 0x18;
            }
            var3->unknown_b4_ = 0x9e - var16;
            var3->unknown_b6_ = var19;
#if defined(jpn)
            func_0205dfa8(arg0->unknown_2c_);
#else
            func_0205cc50(arg0->unknown_2c_, 0, -4);
#endif
            short var20 = *(short*)(var1 + Enum_ov017_021a86d0_2324);
            short var21 = *(short*)(var1 + Enum_ov017_021a86d0_2328);
            short var22 = *(short*)(var1 + Enum_ov017_021a86d0_2326);
            short var23 = var3->unknown_b8_;
            short var24 = var3->unknown_ba_;
            var3->unknown_b4_ = var20 + var21 - var23;
            var3->unknown_b6_ = var22 - var24;
#if defined(jpn)
            func_0205dfa8(arg0->unknown_2c_);
#else
            func_0205cc50(arg0->unknown_2c_, 0, -4);
#endif
            GridCursor_SelectIfValid((Struct_0205bcdc*)sub->table4c, 0);
            GridCursor_SetSelectedIndex(sub->table9c, 0);
            sub->b260 = 1;
            ResetBytesAndSetByte0x16_0205c77c((ResetBytesAndSetByte0x16Data*)sub->resetData, 1);
            sub->b25f = 1;
            sub->b260 = 1;
            ResetBytesAndSetByte0x16_0205c77c((ResetBytesAndSetByte0x16Data*)sub->resetData, 1);
            SetupGlobalObjType1AndInitSelfPointer_0205cd28(self->sub);
            self->state = 3;
        }
    } else if (self->state == 3) {
        void* cont = *(void**)(g + MessageContainer);
        SpriteEntryList_AdvanceAnimations((Container0205a330*)cont, gs->GetTickCount());
        g[MessageDone] = 0;
        int sel = GetScaledSumIfActive0205cecc(self->sub);
        if (g_keyManager.TestKeysPressed(1)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            sel = CallFunc0205c570AtField0x1c_0205cb64(self->sub);
        } else if (g_keyManager.TestKeysPressed(2)) {
            var26 = -2;
        }
        if (arg0->unknown_20_ > var26 && var26 >= 0) {
            arg0->unknown_10_ = arg0->unknown_18_[var26];
            arg0->unknown_8_ = 5;
        } else if (var26 != -1) {
            arg0->unknown_8_ = 4;
        }
    } else if (self->state == 4) {
        MessageSystem_Reset(g);
        self->state = 100;
    } else if (self->state == 5) {
        self->result = *(unsigned short*)(flags + GrottoResult);
        if (self->choice == self->result) {
            *(int*)(g + MessageState) = 1;
            func_ov017_021a933c(self, 0x65);
            SetupGlobalObjType3AndInitSelfPointer_0205ce50(self->sub);
            self->state = 6;
        } else {
            self->state = 99;
            FieldTask_ChooseStarflightStop(self, list);
        }
    } else if (arg0->unknown_8_ == 6) {
        if (*(int*)(var1 + Enum_ov017_021a86d0_2464) == 0) {
            *(int*)(var1 + Enum_ov017_021a86d0_2456) = 1;
            if (func_020457e0(var1) == 0) {
                func_ov017_021a933c(arg0, 0x66);
                arg0->unknown_8_ = 7;
            } else if (func_020457e0(var1) == 1) {
                func_ov017_021a933c(arg0, 0x67);
                arg0->unknown_8_ = 2;
            }
        }
    } else if (self->state == 7) {
        g[MessageDone] = 0;
        if (*(int*)(g + MessageResult) == 0) {
            self->state = 99;
            FieldTask_ChooseStarflightStop(self, list);
        }
    } else if (self->state == 99) {
        int chapter;
        int part;
        unsigned char* bits = Scenario_GetInstance();
        char* res = (char*)GetGameResources();
        void* tail = *(void**)(res + ResourceTail);
        unsigned char* ctx = GetField0x3f8Address_0200fd0c(gs);
        VectorizedMemset(ctx, 0, 0x70);
        ctx[4] = 1;
        ctx[8] = 1;
        ctx[9] = 1;
        ((signed char*)ctx)[0xb] = -1;
        *(int*)(ctx + 0x20) = -1;
        *(int*)(ctx + 0x24) = -1;
        *(int*)(ctx + 0x28) = -1;
        *(int*)(ctx + 0x2c) = -1;
        *(short*)(ctx + 0x1e) = -1;
        ctx[0xc] = 0;
        *(short*)(ctx + 0x6c) = -1;
        ctx[7] = 1;
        InitContext020e1154((void*)0x1f4);
        if (self->result == self->choice) {
            int intro = 1;
            switch (self->choice) {
            case 0:
                break;
            case 1:
                var33 = 0;
                *(unsigned short*)var32 = 0x1198;
                *(short*)(var32 + 0x1c) = 0;
                *(int*)(var32 + 0x10) = -0xd000;
                *(int*)(var32 + 0x14) = 0x4333;
                *(int*)(var32 + 0x18) = -0xd000;
                break;
            case 2:
                *(unsigned short*)var32 = 0x4e27;
                *(short*)(var32 + 0x1c) = 0;
                *(int*)(var32 + 0x10) = -0x2b000;
                *(int*)(var32 + 0x14) = 0x14cc;
                *(int*)(var32 + 0x18) = -0x22000;
                break;
            case 4:
                *(unsigned short*)var32 = 0x4e42;
                *(short*)(var32 + 0x1c) = 0;
                *(int*)(var32 + 0x10) = 0x4000;
                *(int*)(var32 + 0x14) = 0x14cc;
                *(int*)(var32 + 0x18) = 0x41000;
                break;
            case 3:
                *(unsigned short*)var32 = 0x10cd;
                *(short*)(var32 + 0x1c) = 0x3244;
                var33 = 0;
                *(int*)(var32 + 0x10) = 0;
                *(int*)(var32 + 0x14) = -0x6ccc;
                *(int*)(var32 + 0x18) = 0;
                break;
            case 5:
                *(unsigned short*)var32 = 0x1130;
                *(short*)(var32 + 0x1c) = 0x3244;
                var33 = 0;
                *(int*)(var32 + 0x10) = 0;
                *(int*)(var32 + 0x14) = -0x5ccc;
                *(int*)(var32 + 0x18) = 0x1000;
                break;
            }
            int var34[3];
            func_ov017_021d1c2c(arg0->unknown_10_, 0);
            func_ov017_021d1dc0(arg0->unknown_10_, 0, var34, 0, 0);
            func_0200fcfc(var0, var32);
            unsigned char* var35 = *(unsigned char**)(var30 + Enum_ov017_021a86d0_14092);
            func_ov017_0219e310(var35, 0);
            func_020469b4((Struct_0201bdac_2*)var31, (Struct_0201bdac*)var35);
            if (var33) {
                func_ov017_021a65c4(var30, 1, 0);
            }
        } else {
            unsigned char* var36 = *(unsigned char**)(var30 + Enum_ov017_021a86d0_14132);
            func_ov017_021baedc(var36, 1);
            int var37 = 0;
            int var38 = 0;
            switch (arg0->unknown_c_) {
            case 0:
                break;
            case 2:
                if (arg0->unknown_10_ == 4) {
                    var37 = 0x733c;
                } else {
                    var37 = 0x734b;
                }
                break;
            case 4:
                if (arg0->unknown_10_ == 2) {
                    var37 = 0x733f;
                } else {
                    var37 = 0x734c;
                }
                break;
            case 1:
                var2[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7342;
                break;
            case 3:
                var2[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7345;
                break;
            case 5:
                var2[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7348;
                break;
            }
            switch (arg0->unknown_10_) {
            case 0:
                break;
            case 2:
                var38 = 0x733d;
                break;
            case 4:
                var38 = 0x7340;
                break;
            case 1:
                var38 = 0x7343;
                break;
            case 3:
                var38 = 0x7346;
                break;
            case 5:
                var38 = 0x7349;
                break;
            }
            chapter = GetField5cb0Value_0201079c((char*)gs);
            part = GetField5cb4Value_020107d0((char*)gs);
            int step = GetField5cb8Value_02010804((char*)gs);
            if (chapter == 10 && part == 8 && step == 1) {
                if (self->mode == 0 && self->choice == 1 &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 4) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 5) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 6) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 7) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 8) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 9) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 10)) {
                    msgB = 0x7080;
                }
            } else if (chapter == 0x11 && part == 1 && step == 1 && self->mode == 1 && self->choice == 3) {
                if (Scenario_TestFlag((int)bits, bits + 0x8c, 0x15)) {
                    msgB = 0x721a;
                }
            }
            if (var37 == 0) {
                var37 = var38;
                var38 = 0;
            }
            if (func_ov017_021a01b4(var30, var37)) {
                var2[Enum_ov017_021a86d0_10271] = 1;
            }
            *(unsigned short*)(var36 + 8) = var37;
            func_ov017_021bbbf8(var36, var38);
            func_020469b4((Struct_0201bdac_2*)var31, (Struct_0201bdac*)var36);
            int var40[3];
            func_ov017_021d1c2c(arg0->unknown_10_, 0);
            func_ov017_021d1dc0(arg0->unknown_10_, 0, var40, var37, var38);
        }
        self->state = 100;
        MessageSystem_Reset(g);
    } else if (self->state == 100 && *(int*)(g + MessageResult) == 0) {
        MessageSystem_Reset(g);
        SetupGlobalObjType3AndInitSelfPointer_0205ce50(self->sub);
        GameObject_EnableControl(gs->GetProtagonist());
        func_ov017_021a92a0(self);
        self->done = 1;
    }
}
