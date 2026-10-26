#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

#if defined(jpn)
extern "C" char data_ov017_021d7c0c[];
extern "C" void func_0205dfa8(void* obj);
enum { WorkBuffer = 0x1000, Enum_ov017_021a86d0_736 = 0x230, Enum_ov017_021a86d0_14076 = 0x34ec, Enum_ov017_021a86d0_14092 = 0x34fc, Enum_ov017_021a86d0_14132 = 0x3524, Enum_ov017_021a86d0_612 = 0x1f4, Enum_ov017_021a86d0_607 = 0x1ef, Enum_ov017_021a86d0_2456 = 0x868, Enum_ov017_021a86d0_2464 = 0x870, Enum_ov017_021a86d0_2324 = 0x7e4, Enum_ov017_021a86d0_2328 = 0x7e8, Enum_ov017_021a86d0_2326 = 0x7e6, Enum_ov017_021a86d0_6574 = 0x17de, Enum_ov017_021a86d0_10164 = 0x27f4, Enum_ov017_021a86d0_10271 = 0x285f };
#else
enum { WorkBuffer = 0x1400, Enum_ov017_021a86d0_736 = 0x2e0, Enum_ov017_021a86d0_14076 = 0x36fc, Enum_ov017_021a86d0_14092 = 0x370c, Enum_ov017_021a86d0_14132 = 0x3734, Enum_ov017_021a86d0_612 = 0x264, Enum_ov017_021a86d0_607 = 0x25f, Enum_ov017_021a86d0_2456 = 0x998, Enum_ov017_021a86d0_2464 = 0x9a0, Enum_ov017_021a86d0_2324 = 0x914, Enum_ov017_021a86d0_2328 = 0x918, Enum_ov017_021a86d0_2326 = 0x916, Enum_ov017_021a86d0_6574 = 0x19ae, Enum_ov017_021a86d0_10164 = 0x27b4, Enum_ov017_021a86d0_10271 = 0x281f };
#endif

struct Struct_ov017_021a86d0_2 {
    char pad0[0x4];
    unsigned char unknown_4_[0x1c];
    unsigned char table4c[0x50];
    unsigned char table9c[0x40];
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[2];
    short e0;
    short e2;
    short e4;
    short e6;
    char unknown_bc_[Enum_ov017_021a86d0_607 - 0xe8];
    unsigned char unknown_233_;
    unsigned char unknown_234_;
    char unknown_235_[3];
};

struct Self021a86d0 {
    char pad0;
    unsigned char done;
    char pad2[6];
    int state;
    int result;
    int choice;
    int mode;
    unsigned char members[5];
    char unknown_1d_[3];
    int count;
    int unknown_24_;
    int task;
    unsigned char sub[Enum_ov017_021a86d0_612 - 0x2c];
    unsigned char allocator[0x14];
    unsigned char container[0x10];
};

extern "C" char* MessageSystem_GetInstance(void);
extern "C" char* Zone3D_GetInstance(void);
extern "C" void func_0205c904(unsigned char* obj, int value);
extern "C" void* TextQueue_GetInstance(void);
struct Obj020d7aa0;
extern "C" void TextQueue_Reset(Obj020d7aa0*);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int plane1, int plane2, int ev1, int ev2);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* p, int key);
extern "C" Vector3fix func_020406f8(void* node);
extern "C" int fix32_Atan2(int y, int x);
#include "Combat/EntryGetterTypes.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct AllocatorUnion;
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void KeyTable_Load(void* cont, void* alloc, void* data, unsigned int length);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov017_021a933c(void* obj, int key);
extern "C" void func_0205c790(char*);
struct GridCursor;
extern "C" void GridCursor_SetDimensions(GridCursor*, int, int, int);
extern "C" void GridCursor_SetCount(GridCursor*, int);
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_0205cb74(char*, int);
extern "C" void func_0205cc50(void* obj, int a, int b);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int value);
struct Struct_0205c77c;
extern "C" void func_0205c77c(Struct_0205c77c*, int);
extern "C" void func_0205cd28(unsigned char* obj);
struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);
extern "C" int func_0205cecc(void* obj);
extern "C" int func_0205cb64(void* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_0205ce50(unsigned char* obj);
extern "C" int func_020457e0(char* obj);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" unsigned char* GameState_GetZoneTransition(GameState*);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" void func_020e1154(void* p);
extern "C" void func_ov017_021d1c2c(unsigned char, unsigned short);
extern "C" void func_ov017_021d1dc0(unsigned short, int, int*, int, int);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int arg);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" void func_ov017_021a65c4(void* obj, unsigned char mode, int arg);
extern "C" void func_ov017_021baedc(unsigned char* node, int arg);
extern "C" int GameState_GetStoryChapter(char*);
extern "C" int GameState_GetStoryPart(char*);
extern "C" int GameState_GetStoryStep(char*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" int func_ov017_021a01b4(char* res, int value);
extern "C" void func_ov017_021bbbf8(void*, unsigned short);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021a92a0(Self021a86d0* self);

extern char data_ov017_021d77f0[];
extern char data_ov017_021d780a[];
extern char g_mainAllocator[];
extern char g_sePlayer[];

static inline unsigned int inline_ov017_021a86d0(void) {
    return (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
}

static inline void inline_ov017_021a86d0_2(unsigned int plane) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (plane << 8);
}

// Overlay 17, originally func_ov017_021a86d0 (USA/EUR 0x021a86d0, JPN 0x021a8ecc)
extern "C" ARM void FieldTask_ChooseStarflightStop(Self021a86d0* self, void* list) {
    GameState* gs = GameState::GetInstance();
    char* g = MessageSystem_GetInstance();
    char* flags = Zone3D_GetInstance();
    Struct_ov017_021a86d0_2* sub = (Struct_ov017_021a86d0_2*)self->sub;
    func_0205c904(self->sub, gs->GetTickCount());

    if (self->state == 0) {
        TextQueue_Reset((Obj020d7aa0*)TextQueue_GetInstance());
        self->unknown_24_ = inline_ov017_021a86d0();
        inline_ov017_021a86d0_2(0x11);
        GameObject_DisableControl((Obj020397cc*)gs->GetProtagonist(), 1);
        SetFlags04(GetGameResources(), 0x40);
        ColorEffect_ConfigureAlphaBlend((void*)0x4000050, 0x10, 1, 0x1f, 0);
        void* tbl = func_0203cf4c();
        void* node = NULL;
        if (self->mode == 0) {
            node = func_0203df78(tbl, 2);
        } else if (self->mode == 1) {
            node = func_0203df78(tbl, 0xcb);
        }
        if (node != NULL) {
            GameObject* unk = gs->GetLeader();
            Vector3fix target = func_020406f8(node);
            Vector3fix diff;
            Vector3fix_Subtract(&unk->obj3D_.position_, &target, &diff);
            Vector3fix_Normalize(&diff, &diff);
            int angle = fix32_Atan2(diff.x, diff.z);
            if (angle < 0) {
                angle += 0x6488;
            }
            func_02040af0((Struct_0203dce4*)node, angle);
        }
        FontBankLoader* snd = FontBankLoader_GetInstance();
        func_02094b30(snd, 0x205, 0);
        if (func_02094b4c(snd)) {
#if defined(jpn)
            self->task = ((BackgroundLoader*)BackgroundLoader::GetInstance())->QueueLoadFile(data_ov017_021d7c0c, (SafeAllocator*)NULL);
#else
            self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d77f0, data_ov017_021d780a, NULL);
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
            *(int*)(g + Enum_ov017_021a86d0_2456) = 1;
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (*(int*)(g + Enum_ov017_021a86d0_2464) == 3) {
            self->count = 0;
            for (int i = 0; i < 5; i++) {
                if (self->members[i]) {
                    self->count++;
                }
            }
            func_0205c790((char*)self->sub);
            sub->unknown_b1_ = 1;
            sub->unknown_b0_ = 1;
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
                func_0205cb74((char*)self->sub, (int)(KeyTable_Get((Container020e0310*)self->container, self->members[j])));
            }
            func_0205cb74((char*)self->sub, (int)(KeyTable_Get((Container020e0310*)self->container, 6)));
            int n = self->count;
            int y = 0x60 - (n + 1) * 0xe;
            if (n == 2) {
                y = 0x38;
            }
            if (n == 4) {
                y = 0x18;
            }
            sub->e0 = 0x9e - offset;
            sub->e2 = y;
#if defined(jpn)
            func_0205dfa8(self->sub);
#else
            func_0205cc50(self->sub, 0, -4);
#endif
            short left = *(short*)(g + Enum_ov017_021a86d0_2324);
            short width = *(short*)(g + Enum_ov017_021a86d0_2328);
            short top = *(short*)(g + Enum_ov017_021a86d0_2326);
            short var23 = sub->e4;
            short var24 = sub->e6;
            sub->e0 = left + width - var23;
            sub->e2 = top - var24;
#if defined(jpn)
            func_0205dfa8(self->sub);
#else
            func_0205cc50(self->sub, 0, -4);
#endif
            GridCursor_SelectIfValid((Struct_0205bcdc*)sub->table4c, 0);
            GridCursor_SetSelectedIndex(sub->table9c, 0);
            sub->unknown_234_ = 1;
            func_0205c77c((Struct_0205c77c*)sub->unknown_4_, 1);
            sub->unknown_233_ = 1;
            sub->unknown_234_ = 1;
            func_0205c77c((Struct_0205c77c*)sub->unknown_4_, 1);
            func_0205cd28(self->sub);
            self->state = 3;
        }
    } else if (self->state == 3) {
        void* cont = *(void**)(g + Enum_ov017_021a86d0_736);
        SpriteEntryList_AdvanceAnimations((Container0205a330*)cont, gs->GetTickCount());
        g[Enum_ov017_021a86d0_6574] = 0;
        int sel = func_0205cecc(self->sub);
        if (g_keyManager.TestKeysPressed(1)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            sel = func_0205cb64(self->sub);
        } else if (g_keyManager.TestKeysPressed(2)) {
            sel = -2;
        }
        if (self->count > sel && sel >= 0) {
            self->choice = self->members[sel];
            self->state = 5;
        } else if (sel != -1) {
            self->state = 4;
        }
    } else if (self->state == 4) {
        MessageSystem_Reset(g);
        self->state = 100;
    } else if (self->state == 5) {
        self->result = *(unsigned short*)(flags + Enum_ov017_021a86d0_10164);
        if (self->choice == self->result) {
            *(int*)(g + Enum_ov017_021a86d0_2456) = 1;
            func_ov017_021a933c(self, 0x65);
            func_0205ce50(self->sub);
            self->state = 6;
        } else {
            self->state = 99;
            FieldTask_ChooseStarflightStop(self, list);
        }
    } else if (self->state == 6) {
        if (*(int*)(g + Enum_ov017_021a86d0_2464) == 0) {
            *(int*)(g + Enum_ov017_021a86d0_2456) = 1;
            if (func_020457e0(g) == 0) {
                func_ov017_021a933c(self, 0x66);
                self->state = 7;
            } else if (func_020457e0(g) == 1) {
                func_ov017_021a933c(self, 0x67);
                self->state = 2;
            }
        }
    } else if (self->state == 7) {
        g[Enum_ov017_021a86d0_6574] = 0;
        if (*(int*)(g + Enum_ov017_021a86d0_2464) == 0) {
            self->state = 99;
            FieldTask_ChooseStarflightStop(self, list);
        }
    } else if (self->state == 99) {
        int chapter;
        int part;
        unsigned char* bits = Scenario_GetInstance();
        char* res = (char*)GetGameResources();
        void* tail = *(void**)(res + Enum_ov017_021a86d0_14076);
        unsigned char* ctx = GameState_GetZoneTransition(gs);
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
        func_020e1154((void*)0x1f4);
        if (self->result == self->choice) {
            int intro = 1;
            switch (self->choice) {
            case 0:
                break;
            case 1:
                intro = 0;
                *(unsigned short*)ctx = 0x1198;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = -0xd000;
                *(int*)(ctx + 0x14) = 0x4333;
                *(int*)(ctx + 0x18) = -0xd000;
                break;
            case 2:
                *(unsigned short*)ctx = 0x4e27;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = -0x2b000;
                *(int*)(ctx + 0x14) = 0x14cc;
                *(int*)(ctx + 0x18) = -0x22000;
                break;
            case 4:
                *(unsigned short*)ctx = 0x4e42;
                *(short*)(ctx + 0x1c) = 0;
                *(int*)(ctx + 0x10) = 0x4000;
                *(int*)(ctx + 0x14) = 0x14cc;
                *(int*)(ctx + 0x18) = 0x41000;
                break;
            case 3:
                *(unsigned short*)ctx = 0x10cd;
                *(short*)(ctx + 0x1c) = 0x3244;
                intro = 0;
                *(int*)(ctx + 0x10) = 0;
                *(int*)(ctx + 0x14) = -0x6ccc;
                *(int*)(ctx + 0x18) = 0;
                break;
            case 5:
                *(unsigned short*)ctx = 0x1130;
                *(short*)(ctx + 0x1c) = 0x3244;
                intro = 0;
                *(int*)(ctx + 0x10) = 0;
                *(int*)(ctx + 0x14) = -0x5ccc;
                *(int*)(ctx + 0x18) = 0x1000;
                break;
            }
            int buf[3];
            func_ov017_021d1c2c(self->choice, 0);
            func_ov017_021d1dc0(self->choice, 0, buf, 0, 0);
            GameState_SetZoneTransition(gs, ctx);
            unsigned char* header = *(unsigned char**)(res + Enum_ov017_021a86d0_14092);
            FieldTask_InitEnterZone(header, 0);
            func_020469b4((TailList020469b4*)tail, (TailNode020469b4*)header);
            if (intro) {
                func_ov017_021a65c4(res, 1, 0);
            }
        } else {
            unsigned char* node = *(unsigned char**)(res + Enum_ov017_021a86d0_14132);
            func_ov017_021baedc(node, 1);
            int var37 = 0;
            int var38 = 0;
            switch (self->result) {
            case 0:
                break;
            case 2:
                if (self->choice == 4) {
                    var37 = 0x733c;
                } else {
                    var37 = 0x734b;
                }
                break;
            case 4:
                if (self->choice == 2) {
                    var37 = 0x733f;
                } else {
                    var37 = 0x734c;
                }
                break;
            case 1:
                flags[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7342;
                break;
            case 3:
                flags[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7345;
                break;
            case 5:
                flags[Enum_ov017_021a86d0_10271] = 1;
                var37 = 0x7348;
                break;
            }
            switch (self->choice) {
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
            chapter = GameState_GetStoryChapter((char*)gs);
            part = GameState_GetStoryPart((char*)gs);
            int step = GameState_GetStoryStep((char*)gs);
            if (chapter == 10 && part == 8 && step == 1) {
                if (self->mode == 0 && self->choice == 1 &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 4) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 5) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 6) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 7) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 8) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 9) &&
                    Scenario_TestFlag((int)bits, bits + 0x8c, 10)) {
                    var38 = 0x7080;
                }
            } else if (chapter == 0x11 && part == 1 && step == 1 && self->mode == 1 && self->choice == 3) {
                if (Scenario_TestFlag((int)bits, bits + 0x8c, 0x15)) {
                    var38 = 0x721a;
                }
            }
            if (var37 == 0) {
                var37 = var38;
                var38 = 0;
            }
            if (func_ov017_021a01b4(res, var37)) {
                flags[Enum_ov017_021a86d0_10271] = 1;
            }
            *(unsigned short*)(node + 8) = var37;
            func_ov017_021bbbf8(node, var38);
            func_020469b4((TailList020469b4*)tail, (TailNode020469b4*)node);
            int buf[3];
            func_ov017_021d1c2c(self->choice, 0);
            func_ov017_021d1dc0(self->choice, 0, buf, var37, var38);
        }
        self->state = 100;
        MessageSystem_Reset(g);
    } else if (self->state == 100 && *(int*)(g + Enum_ov017_021a86d0_2464) == 0) {
        MessageSystem_Reset(g);
        func_0205ce50(self->sub);
        GameObject_EnableControl(gs->GetProtagonist());
        func_ov017_021a92a0(self);
        self->done = 1;
    }
}
