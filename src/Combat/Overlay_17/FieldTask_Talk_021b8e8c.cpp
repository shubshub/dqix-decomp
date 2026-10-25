#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define data_ov017_021d7c90 data_ov017_021d846c
#define data_ov017_021d7c95 data_ov017_021d8471
enum {
    Enum_ov017_021b8e8c_2112 = 0x860, Enum_ov017_021b8e8c_4 = 0x10, Enum_ov017_021b8e8c_6200 = 0x1708, Enum_ov017_021b8e8c_92 = 0x28, Enum_ov017_021b8e8c_96 = 0x2c,
    Enum_ov017_021b8e8c_2456 = 0x868, Enum_ov017_021b8e8c_2460 = 0x86c, Enum_ov017_021b8e8c_2464 = 0x870, Enum_ov017_021b8e8c_140 = 0x4c, Enum_ov017_021b8e8c_6578 = 0x17e2,
    Enum_ov017_021b8e8c_2400 = 0x800
};
#else
enum {
    Enum_ov017_021b8e8c_2112 = 0x840, Enum_ov017_021b8e8c_4 = 4, Enum_ov017_021b8e8c_6200 = 0x1838, Enum_ov017_021b8e8c_92 = 0x5c, Enum_ov017_021b8e8c_96 = 0x60,
    Enum_ov017_021b8e8c_2456 = 0x998, Enum_ov017_021b8e8c_2460 = 0x99c, Enum_ov017_021b8e8c_2464 = 0x9a0, Enum_ov017_021b8e8c_140 = 0x8c, Enum_ov017_021b8e8c_6578 = 0x19b2,
    Enum_ov017_021b8e8c_2400 = 0x960
};
#endif

struct Obj020397cc;
struct SePlayer;
struct Obj020d7aa0;
struct Vec3_020406f8;
struct Node020406f8;
struct Obj02033834;
struct Owner02040a90;
struct Struct0203cedc;
struct Entry0209854c;
struct TailList020469b4;
struct TailNode020469b4;
struct ListHead02046b60;
struct Obj0208b8c4;

struct Struct_ov017_021b8e8c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021b8e8c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov017_021b8e8c_3 {
    unsigned int unknown_0_;
    char unknown_4_[0x10];
    Struct_0203ca24* unknown_14_;
};

struct Struct_ov017_021b8e8c_4 {
    int unknown_0_;
    char unknown_4_[0x10];
    int unknown_14_;
    char unknown_18_[0x1c];
};

struct Struct_ov017_021b8e8c_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    SafeAllocator unknown_1c_;
    unsigned char unknown_30_[0xe4];
    Struct_ov017_021b8e8c_2* unknown_114_;
    unsigned char* unknown_118_;
    int unknown_11c_;
    int unknown_120_;
    int unknown_124_;
    unsigned char unknown_128_;
    unsigned char unknown_129_;
    char unknown_12a_[2];
    int unknown_12c_;
    unsigned char unknown_130_;
    char unknown_131_[6];
    unsigned char unknown_137_;
    unsigned char unknown_138_;
    unsigned char unknown_139_;
};

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021b8d80(Self021b8e8c* self);
extern "C" unsigned short* Zone3D_GetInstance(void);
char* MessageSystem_GetInstance(void);
void* GetGlobalPtr021075f4_0203cf4c(void);
extern "C" void* Scenario_GetInstance(void);
int GetFieldIfFlag4_020100f8(char* obj);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* FindEntryPointerByKey0203df78(void* base, int key);
void GameObject_EnableControl(void* obj);
Obj020d7aa0* TextQueue_GetInstance(void);
void TextQueue_Reset(struct Obj020d7aa0* obj);
int IsIdInRange020981e4(int a, int id);
int IsInRange1To63_02098268(int a, int x);
extern "C" Vec3_021b8e8c _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(struct Node020406f8* n);
void GameObject_SetFacing(struct Obj02033834* obj, int arg);
int FindEntryByKey0203dfdc(void* base, int key);
int GetFieldFromActiveChild(struct Owner02040a90* obj);
int GetField0x8_02040528(int* obj);
void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
Entry0209854c* FindEntryByFieldC0209854c(struct Entry0209854c* list, int target);
extern "C" void func_ov017_021a967c(TailNode020469b4* node, int id);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
int GetTableEntryOrZero_0218d2c4(int id);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" void func_ov008_02184754(void* obj);
int GetNibble0206ec1c(int a, int b, unsigned char* c, unsigned int d);
void IncrementNibble0206ec64(int a, int b, unsigned char* c, unsigned int d);
extern "C" int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6);
int Text_Append(char* dst, const char* src);
unsigned char* GetData02108d18_0206f504(void);
void Init0206f510(char* obj);
extern "C" int func_0206f550(unsigned char* s, char* in, char* out);
int CommandDispatch0206f6cc(unsigned char* obj, int arg);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void InitAllocatorsAndBuffers0208b8c4(struct Obj0208b8c4* obj, SafeAllocator* allocator);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" void func_0208bb78(void* timer, unsigned int ticks);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
void SetByteB10AndClearB11_02184a3c(char* obj, unsigned char value);
void SetFlag0x2IfByte0xd4Not3_0208beb4(unsigned char* obj);
void SetFields120_138_021bd38c(void* obj, int a, int b);

extern "C" void __clear(void* arg0, int arg1);

extern char g_sePlayer;
extern char data_ov017_021d7c90;
extern char data_ov017_021d7c95;
extern char data_ov017_021d7cad;
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021b8e8c (USA/EUR 0x021b8e8c, JPN 0x021b9384)
extern "C" ARM void FieldTask_Talk(Self021b8e8c* self, ListHead02046b60* list) {
    if (self->rec == NULL) {
        self->done = 1;
        return;
    }

    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short* area = Zone3D_GetInstance();
    char* msg = MessageSystem_GetInstance();
    void* table = GetGlobalPtr021075f4_0203cf4c();
    GameObject* leader = gs->GetUnknownGameObject();
    void* events = Scenario_GetInstance();
    void* hud;
    unsigned short areaId = *area;
    hud = (void*)GetFieldIfFlag4_020100f8((char*)gs);
    unsigned char* nibbles = (unsigned char*)res->unknown_ptr_44c4;

    if (func_ov017_021959b4() != 0) {
        func_ov017_021b8d80(self);
        MessageSystem_Reset(msg);
        MessageSystem_Stop(msg);
        SetField0x23cTrue_020a27ac(hud);
        ClearFlags00(res, 0x2000);
        self->done = 1;
        return;
    }

    GameObject_DisableControl((Obj020397cc*)leader, 1);

    switch (arg0->unknown_11c_) {
    case 0: {
        if (self->quiet == 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        }
        *(short*)((char*)leader + 0xb2) = 0;
        Vec3_021b8e8c from = *(Vec3_021b8e8c*)((char*)leader + 0x44);
        Entry021b8e8c* entry = (Entry021b8e8c*)FindEntryPointerByKey0203df78(table, self->rec->id);
        if (entry == NULL) {
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            arg0->unknown_1_ = 1;
            break;
        }
        TextQueue_Reset(TextQueue_GetInstance());
        self->lastId = self->rec->id;
        if (IsIdInRange020981e4((int)((char*)area + kAreaList), areaId) &&
            IsInRange1To63_02098268((int)((char*)area + kAreaList), self->rec->id)) {
            self->hasSub = 1;
        }
        Vec3_021b8e8c to = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8((Node020406f8*)entry);
        GameObject_SetFacing((Obj02033834*)leader, fix32ReduceAngle0To2Pi(fix32_Atan2(to.x - from.x, to.z - from.z)));
        *(int*)(msg + kMsgEntry) = FindEntryByKey0203dfdc(table, self->rec->id);
        *(int*)(msg + kMsgEntry + 4) = GetFieldFromActiveChild((Owner02040a90*)entry);
        char* info = (char*)GetField0x8_02040528((int*)entry);
        if (info != NULL && strstr(info + kInfoTag, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            SetCombatFlags0x5c(entry->combat, 1, 0);
        }
        int tableId = GetField5cb0Value_0201079c((char*)gs);
        char prefix[0xc];
        strcpy(prefix, *(char**)((char*)area + 8) + 5);
        prefix[3] = 0;
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        if (self->hasSub != 0) {
            TailList020469b4* tail;
            TailNode020469b4* node = (TailNode020469b4*)res->fieldTasks_[0x22];
            tail = (TailList020469b4*)res->fieldTaskQueue_;
            Entry0209854c* found = FindEntryByFieldC0209854c((Entry0209854c*)((char*)area + kAreaList), *(unsigned short*)info);
            func_ov017_021a967c(node, -1);
            *(Entry0209854c**)((char*)node + 0x54) = found;
            AppendNodeToTail(tail, node);
            self->done = 1;
            break;
        }
        char var20[0x50];
        sprintf(var20, &data_ov017_021d7c95, var16, func_ov017_0218d2c4(var15));
        if (var8 != NULL) {
            func_020a27b8((unsigned char*)var8);
        }
#if defined(jpn)
        arg0->unknown_120_ = var2->QueueLoadFile(var20, NULL);
#else
        char var21[0x10];
        __clear(var21, sizeof(var21));
        sprintf(var21, &data_ov017_021d7cad, *(unsigned short*)var14);
        arg0->unknown_120_ = var2->QueueLoadFileInGP2(var20, var21, NULL);
#endif
        arg0->unknown_11c_ = 1;
        break;
    }
    case 1: {
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (var2->GetTaskStatus(arg0->unknown_120_) == 0) {
            break;
        }
        if (loader->GetDetailedTaskStatus(self->task) != 2) {
            loader->RemoveTask(self->task);
            self->task = -1;
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            self->done = 1;
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
            break;
        }
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        int arg = GetField5cb4Value_020107d0((char*)gs);
        unsigned short id = self->rec->id;
        int lo = GetNibble0206ec1c((int)nibbles, id, nibbles, 0x80);
        int hi = GetNibble0206ec1c((int)nibbles, id, nibbles + 0x80, 0x80);
        char* text = (char*)func_ov017_021ba810(data, length, id, arg, self->f124, lo, hi);
        if (text == NULL) {
            loader->RemoveTask(self->task);
            self->task = -1;
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            self->done = 1;
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
            break;
        }
        func_0206ec64((int)var10, var25, var10, 0x80);
        func_0206ec64((int)var10, var25, var10 + 0x80, 0x80);
        *(int*)(var4 + Enum_ov017_021b8e8c_2460) = arg0->unknown_114_->unknown_3_;
        char* var29 = *(char**)(var4 + Enum_ov017_021b8e8c_92);
        char* var30 = *(char**)(var4 + Enum_ov017_021b8e8c_96);
        memset(var29, 0, Enum_ov017_021b8e8c_2400);
        memset(var30, 0, Enum_ov017_021b8e8c_2400);
#if defined(jpn)
        Struct_ov017_021b8e8c_2* var31 = arg0->unknown_114_;
        if (strlen(var28) + strlen((char*)var31 + 4) >= Enum_ov017_021b8e8c_2400) {
            var28[Enum_ov017_021b8e8c_2400 - 1 - strlen((char*)var31 + 4)] = 0;
        }
#else
        if (strlen(var28) >= Enum_ov017_021b8e8c_2400) {
            var28[Enum_ov017_021b8e8c_2400 - 1] = 0;
        }
#endif
        Text_Append(in, text);
        loader->RemoveTask(self->task);
        self->task = -1;
        unsigned char* script = GetData02108d18_0206f504();
        Init0206f510((char*)script);
        if (func_0206f550(script, in, out) != 0 && CommandDispatch0206f6cc(script, 0) == 0) {
            self->state = 8;
            BlankFunction02094b34(FontBankLoader_GetInstance(), 0x6f, 0x1388, 1, 1);
            break;
        }
        arg0->unknown_11c_ = 3;
        break;
    }
    case 8:
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) != 0) {
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            if (func_02046b60(arg1, 0x2b) != 0 && var8 != NULL) {
                func_020a27b8((unsigned char*)var8);
            }
            arg0->unknown_11c_ = -1;
            arg0->unknown_1_ = 1;
        }
        break;
    case 3: {
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        FontBankLoader* fade = FontBankLoader_GetInstance();
        if (self->hasSub != 0) {
            BlankFunction02094b40(fade);
            BlankFunction02094b34(fade, 0x6e, 0x1ff, 0, 0);
        } else {
            func_02094b34(var33, 0x6f, 0x1388, 1, 1);
        }
        arg0->unknown_11c_ = 4;
        break;
    }
    case 4:
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        func_020a0cc4(0xa000);
        self->allocA.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xa000), 0xa000);
        InitAllocatorsAndBuffers0208b8c4((Obj0208b8c4*)self->timer, &self->allocA);
        char* buffer = *(char**)(msg + kMsgOut);
        int scroll = 1;
        switch (areaId) {
        case 1:
            if (arg0->unknown_114_->unknown_0_ == 0xc8) {
                var35 = 0;
            }
            break;
        case 0xc3b5:
        case 0xc419:
        case 0xc47d:
        case 0xc4e1: {
            unsigned short var36 = arg0->unknown_114_->unknown_0_;
            if (var36 == 0xd0 || var36 == 0x63 || var36 == 0xd3) {
                var35 = 0;
            }
            break;
        }
        }
#if defined(jpn)
        func_0204500c(var4, var34, var35);
#else
        func_0204500c(var4, var34, var35, 0xe3);
#endif
        *(int*)(msg + kMsgBusy) = 1;
        *(unsigned char*)(msg + kMsgFlag) = 1;
        *(void**)(msg + kMsgTimer) = self->timer;
        *(int*)(msg + kMsgKind) = self->rec->kind;
        self->state = 5;
        func_0208bb78(self->timer, gs->GetTickCount());
        if (ListContainsId((ListHead02046b60*)res->fieldTaskQueue_, 0x17) == 0) {
            break;
        }
        if (var8 != NULL) {
            func_020a27ac(var8);
        }
        arg0->unknown_1_ = 1;
        func_ov017_021b8d80(arg0);
        if (func_0203df78(var5, arg0->unknown_114_->unknown_0_) == NULL) {
            break;
        }
        Query021b8e8c query;
        query.id = self->rec->id;
        query.value = self->f124;
        if (Scenario_RunTrigger(events, 1, &query) != 0) {
            EventQuery_RunQueuedCommands(&query);
        }
        break;
    }
    case 5: {
        if (arg0->unknown_130_ != 0) {
            break;
        }
        func_0208bb78(arg0->unknown_30_, var0->GetTickCount());
        if (arg0->unknown_128_ != 0) {
            func_ov008_02184754(arg0->unknown_118_);
        }
        if (*(int*)(msg + kMsgMode) == 3) {
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
        }
        if (*(int*)(var4 + Enum_ov017_021b8e8c_2456) != 0) {
            break;
        }
        if (arg0->unknown_128_ != 0) {
            if (arg0->unknown_129_ == 0) {
                func_ov008_02184a3c((char*)arg0->unknown_118_, 0xd);
                arg0->unknown_129_++;
                break;
            }
            if (arg0->unknown_118_[0xb10] != 0xe) {
                break;
            }
            arg0->unknown_129_ = 0;
        }
        Struct_ov017_021b8e8c_3* var38 = (Struct_ov017_021b8e8c_3*)func_0203df78(var5, arg0->unknown_114_->unknown_0_);
        if (var38 == NULL) {
            break;
        }
        char* var39 = (char*)func_02040528((int*)var38);
        if (var39 != NULL && strstr(var39 + Enum_ov017_021b8e8c_4, &data_ov017_021d7c90) != NULL && !(var38->unknown_0_ & 0x4000) &&
            var38->unknown_14_ != NULL) {
            func_0203cedc(var38->unknown_14_, 1, 1);
        }
        arg0->unknown_11c_ = 6;
        break;
    }
    case 6: {
        if (*(short*)(self->timer + 0xd2) < 0) {
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                SetField0x23cTrue_020a27ac(hud);
            }
            arg0->unknown_1_ = 1;
            func_ov017_021b8d80(arg0);
        } else {
            arg0->unknown_11c_ = 7;
        }
        int was;
        unsigned char* party = (unsigned char*)res->unknown_ptr_array_371c[6];
        was = 0;
        if (party[2] != 0) {
            was = 1;
        }
        Query021b8e8c query;
        query.id = self->rec->id;
        query.value = self->f124;
        if (Scenario_RunTrigger(events, 1, &query) != 0) {
            EventQuery_RunQueuedCommands(&query);
        }
        if (var40 == 0 && var41[2] != 0) {
            arg0->unknown_138_ = 1;
        }
        break;
    }
    case 7:
        func_0208bb78(arg0->unknown_30_, var0->GetTickCount());
        if (*(short*)(arg0->unknown_30_ + 0xd2) >= 0) {
            if (arg0->unknown_138_ == 0) {
                func_0208beb4(arg0->unknown_30_);
                break;
            }
            SetFields120_138_021bd38c(res->unknown_ptr_array_371c[6], (int)self->timer, (int)&self->allocA);
            self->finished = 1;
        }
        GameObject_EnableControl(leader);
        if (hud != NULL) {
            SetField0x23cTrue_020a27ac(hud);
        }
        arg0->unknown_1_ = 1;
        func_ov017_021b8d80(arg0);
        break;
    }
}
