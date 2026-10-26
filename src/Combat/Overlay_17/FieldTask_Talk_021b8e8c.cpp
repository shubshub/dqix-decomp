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
struct Struct_0203de84;
struct Node020406f8;
struct Obj02033834;
struct Struct_02040a90;
struct Struct_0203ca24;
struct Struct_0203d028_12;
struct TailList020469b4;
struct TailNode020469b4;
struct ListHead02046b60;
struct Struct_0208b8c4;

struct Struct_ov017_021b8e8c {
    int x;
    int y;
    int z;
};

struct Struct_ov017_021b8e8c_2 {
    unsigned short id;
    unsigned char pad2;
    unsigned char kind;
};

struct Struct_ov017_021b8e8c_3 {
    unsigned int flags;
    char pad4[0x10];
    Struct_0203ca24* combat;
};

struct Struct_ov017_021b8e8c_4 {
    int id;
    char pad4[0x10];
    int value;
    char pad18[0x1c];
};

struct Self021b8e8c {
    unsigned char kind;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocA;
    SafeAllocator unknown_1c_;
    unsigned char timer[0xe4];
    Struct_ov017_021b8e8c_2* rec;
    unsigned char* sub;
    int state;
    int task;
    int unknown_124_;
    unsigned char unknown_128_;
    unsigned char unknown_129_;
    char unknown_12a_[2];
    int unknown_12c_;
    unsigned char busy;
    char unknown_131_[6];
    unsigned char unknown_137_;
    unsigned char changed;
    unsigned char unknown_139_;
};

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021b8d80(Self021b8e8c* self);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" void* func_0203cf4c(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void func_020a27ac(void* obj);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg1);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void* func_0203df78(void* base, int key);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" Obj020d7aa0* TextQueue_GetInstance(void);
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);
extern "C" int func_020981e4(int a, int id);
extern "C" int func_02098268(int a, int x);
extern "C" Struct_ov017_021b8e8c func_020406f8(struct Node020406f8* n);
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
extern "C" int func_0203dfdc(void* base, int key);
extern "C" int func_02040a90(struct Struct_02040a90* obj);
extern "C" int func_02040528(int* obj);
extern "C" void func_0203cedc(struct Struct_0203ca24* obj, int b, int c);
extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" Struct_0203d028_12* func_0209854c(struct Struct_0203d028_12* list, int target);
extern "C" void func_ov017_021a967c(TailNode020469b4* node, int id);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" int func_ov017_0218d2c4(int id);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" void func_ov008_02184754(void* obj);
extern "C" int func_0206ec1c(int a, int b, unsigned char* c, unsigned int d);
extern "C" void func_0206ec64(int a, int b, unsigned char* c, unsigned int d);
extern "C" int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" unsigned char* func_0206f504(void);
extern "C" void func_0206f510(char* obj);
extern "C" int func_0206f550(unsigned char* s, char* in, char* out);
extern "C" int func_0206f6cc(unsigned char* obj, int arg);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_0208b8c4(struct Struct_0208b8c4* obj, SafeAllocator* allocator);
#if defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" void func_0208bb78(void* timer, unsigned int ticks);
extern "C" int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
extern "C" void func_ov008_02184a3c(char* obj, unsigned char value);
extern "C" void func_0208beb4(unsigned char* obj);
extern "C" void func_ov017_021bd38c(void* obj, int a, int b);

extern "C" void __clear(void* buf, int n);

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
    void* table = func_0203cf4c();
    GameObject* leader = gs->GetLeader();
    void* events = Scenario_GetInstance();
    void* hud;
    unsigned short areaId = *area;
    hud = (void*)GameState_GetFollowCamera((char*)gs);
    unsigned char* nibbles = (unsigned char*)res->unknown_ptr_44c4;

    if (func_ov017_021959b4() != 0) {
        func_ov017_021b8d80(self);
        MessageSystem_Reset(msg);
        MessageSystem_Stop(msg);
        func_020a27ac(hud);
        ClearFlags00(res, 0x2000);
        self->done = 1;
        return;
    }

    GameObject_DisableControl((Obj020397cc*)leader, 1);

    switch (self->state) {
    case 0: {
        if (self->unknown_139_ == 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        }
        *(short*)((char*)leader + 0xb2) = 0;
        Struct_ov017_021b8e8c from = *(Struct_ov017_021b8e8c*)((char*)leader + 0x44);
        Struct_ov017_021b8e8c_3* entry = (Struct_ov017_021b8e8c_3*)func_0203df78(table, self->rec->id);
        if (entry == NULL) {
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                func_020a27ac(hud);
            }
            self->done = 1;
            break;
        }
        TextQueue_Reset(TextQueue_GetInstance());
        self->unknown_12c_ = self->rec->id;
        if (func_020981e4((int)((char*)area + Enum_ov017_021b8e8c_2112), areaId) &&
            func_02098268((int)((char*)area + Enum_ov017_021b8e8c_2112), self->rec->id)) {
            self->unknown_128_ = 1;
        }
        Struct_ov017_021b8e8c to = func_020406f8((Node020406f8*)entry);
        GameObject_SetFacing((Obj02033834*)leader, fix32ReduceAngle0To2Pi(fix32_Atan2(to.x - from.x, to.z - from.z)));
        *(int*)(msg + Enum_ov017_021b8e8c_6200) = func_0203dfdc(table, self->rec->id);
        *(int*)(msg + Enum_ov017_021b8e8c_6200 + 4) = func_02040a90((Struct_02040a90*)entry);
        char* info = (char*)func_02040528((int*)entry);
        if (info != NULL && strstr(info + Enum_ov017_021b8e8c_4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            func_0203cedc(entry->combat, 1, 0);
        }
        int tableId = GameState_GetStoryChapter((char*)gs);
        char prefix[0xc];
        strcpy(prefix, *(char**)((char*)area + 8) + 5);
        prefix[3] = 0;
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        if (self->unknown_128_ != 0) {
            TailList020469b4* tail;
            TailNode020469b4* node = (TailNode020469b4*)res->fieldTasks_[0x22];
            tail = (TailList020469b4*)res->fieldTaskQueue_;
            Struct_0203d028_12* found = func_0209854c((Struct_0203d028_12*)((char*)area + Enum_ov017_021b8e8c_2112), *(unsigned short*)info);
            func_ov017_021a967c(node, -1);
            *(Struct_0203d028_12**)((char*)node + 0x54) = found;
            func_020469b4(tail, node);
            self->done = 1;
            break;
        }
        char path[0x50];
        sprintf(path, &data_ov017_021d7c95, prefix, func_ov017_0218d2c4(tableId));
        if (hud != NULL) {
            func_020a27b8((unsigned char*)hud);
        }
#if defined(jpn)
        self->task = loader->QueueLoadFile(path, NULL);
#else
        char name[0x10];
        __clear(name, sizeof(name));
        sprintf(name, &data_ov017_021d7cad, *(unsigned short*)info);
        self->task = loader->QueueLoadFileInGP2(path, name, NULL);
#endif
        self->state = 1;
        break;
    }
    case 1: {
        if (self->unknown_128_ != 0) {
            func_ov008_02184754(self->sub);
        }
        if (loader->GetTaskStatus(self->task) == 0) {
            break;
        }
        if (loader->GetDetailedTaskStatus(self->task) != 2) {
            loader->RemoveTask(self->task);
            self->task = -1;
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                func_020a27ac(hud);
            }
            self->done = 1;
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
            break;
        }
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        int arg = GameState_GetStoryPart((char*)gs);
        unsigned short id = self->rec->id;
        int lo = func_0206ec1c((int)nibbles, id, nibbles, 0x80);
        int hi = func_0206ec1c((int)nibbles, id, nibbles + 0x80, 0x80);
        char* text = (char*)func_ov017_021ba810(data, length, id, arg, self->unknown_124_, lo, hi);
        if (text == NULL) {
            loader->RemoveTask(self->task);
            self->task = -1;
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                func_020a27ac(hud);
            }
            self->done = 1;
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
            break;
        }
        func_0206ec64((int)nibbles, id, nibbles, 0x80);
        func_0206ec64((int)nibbles, id, nibbles + 0x80, 0x80);
        *(int*)(msg + Enum_ov017_021b8e8c_2460) = self->rec->kind;
        char* out = *(char**)(msg + Enum_ov017_021b8e8c_92);
        char* in = *(char**)(msg + Enum_ov017_021b8e8c_96);
        memset(out, 0, Enum_ov017_021b8e8c_2400);
        memset(in, 0, Enum_ov017_021b8e8c_2400);
#if defined(jpn)
        Struct_ov017_021b8e8c_2* rec = self->rec;
        if (strlen(text) + strlen((char*)rec + 4) >= Enum_ov017_021b8e8c_2400) {
            text[Enum_ov017_021b8e8c_2400 - 1 - strlen((char*)rec + 4)] = 0;
        }
#else
        if (strlen(text) >= Enum_ov017_021b8e8c_2400) {
            text[Enum_ov017_021b8e8c_2400 - 1] = 0;
        }
#endif
        Text_Append(in, text);
        loader->RemoveTask(self->task);
        self->task = -1;
        unsigned char* script = func_0206f504();
        func_0206f510((char*)script);
        if (func_0206f550(script, in, out) != 0 && func_0206f6cc(script, 0) == 0) {
            self->state = 8;
            func_02094b34(FontBankLoader_GetInstance(), 0x6f, 0x1388, 1, 1);
            break;
        }
        self->state = 3;
        break;
    }
    case 8:
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            if (hud != NULL) {
                func_020a27ac(hud);
            }
            if (func_02046b60(list, 0x2b) != 0 && hud != NULL) {
                func_020a27b8((unsigned char*)hud);
            }
            self->state = -1;
            self->done = 1;
        }
        break;
    case 3: {
        if (self->unknown_128_ != 0) {
            func_ov008_02184754(self->sub);
        }
        FontBankLoader* fade = FontBankLoader_GetInstance();
        if (self->unknown_128_ != 0) {
            func_02094b40(fade);
            func_02094b34(fade, 0x6e, 0x1ff, 0, 0);
        } else {
            func_02094b34(fade, 0x6f, 0x1388, 1, 1);
        }
        self->state = 4;
        break;
    }
    case 4:
        if (self->unknown_128_ != 0) {
            func_ov008_02184754(self->sub);
        }
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            self->state = 2;
        }
        break;
    case 2: {
        func_020a0cc4(0xa000);
        self->allocA.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xa000), 0xa000);
        func_0208b8c4((Struct_0208b8c4*)self->timer, &self->allocA);
        char* buffer = *(char**)(msg + Enum_ov017_021b8e8c_92);
        int scroll = 1;
        switch (areaId) {
        case 1:
            if (self->rec->id == 0xc8) {
                scroll = 0;
            }
            break;
        case 0xc3b5:
        case 0xc419:
        case 0xc47d:
        case 0xc4e1: {
            unsigned short id = self->rec->id;
            if (id == 0xd0 || id == 0x63 || id == 0xd3) {
                scroll = 0;
            }
            break;
        }
        }
#if defined(jpn)
        func_0204500c(msg, buffer, scroll);
#else
        func_0204500c(msg, buffer, scroll, 0xe3);
#endif
        *(int*)(msg + Enum_ov017_021b8e8c_2456) = 1;
        *(unsigned char*)(msg + Enum_ov017_021b8e8c_6578) = 1;
        *(void**)(msg + Enum_ov017_021b8e8c_140) = self->timer;
        *(int*)(msg + Enum_ov017_021b8e8c_2460) = self->rec->kind;
        self->state = 5;
        func_0208bb78(self->timer, gs->GetTickCount());
        if (func_02046b60((ListHead02046b60*)res->fieldTaskQueue_, 0x17) == 0) {
            break;
        }
        if (hud != NULL) {
            func_020a27ac(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        if (func_0203df78(table, self->rec->id) == NULL) {
            break;
        }
        Struct_ov017_021b8e8c_4 query;
        query.id = self->rec->id;
        query.value = self->unknown_124_;
        if (Scenario_RunTrigger(events, 1, &query) != 0) {
            EventQuery_RunQueuedCommands(&query);
        }
        break;
    }
    case 5: {
        if (self->busy != 0) {
            break;
        }
        func_0208bb78(self->timer, gs->GetTickCount());
        if (self->unknown_128_ != 0) {
            func_ov008_02184754(self->sub);
        }
        if (*(int*)(msg + Enum_ov017_021b8e8c_2464) == 3) {
            MessageSystem_Reset(msg);
            MessageSystem_Stop(msg);
        }
        if (*(int*)(msg + Enum_ov017_021b8e8c_2456) != 0) {
            break;
        }
        if (self->unknown_128_ != 0) {
            if (self->unknown_129_ == 0) {
                func_ov008_02184a3c((char*)self->sub, 0xd);
                self->unknown_129_++;
                break;
            }
            if (self->sub[0xb10] != 0xe) {
                break;
            }
            self->unknown_129_ = 0;
        }
        Struct_ov017_021b8e8c_3* entry = (Struct_ov017_021b8e8c_3*)func_0203df78(table, self->rec->id);
        if (entry == NULL) {
            break;
        }
        char* info = (char*)func_02040528((int*)entry);
        if (info != NULL && strstr(info + Enum_ov017_021b8e8c_4, &data_ov017_021d7c90) != NULL && !(entry->flags & 0x4000) &&
            entry->combat != NULL) {
            func_0203cedc(entry->combat, 1, 1);
        }
        self->state = 6;
        break;
    }
    case 6: {
        if (*(short*)(self->timer + 0xd2) < 0) {
            GameObject_EnableControl(leader);
            if (hud != NULL) {
                func_020a27ac(hud);
            }
            self->done = 1;
            func_ov017_021b8d80(self);
        } else {
            self->state = 7;
        }
        int var40;
        unsigned char* party = (unsigned char*)res->unknown_ptr_array_371c[6];
        var40 = 0;
        if (party[2] != 0) {
            var40 = 1;
        }
        Struct_ov017_021b8e8c_4 query;
        query.id = self->rec->id;
        query.value = self->unknown_124_;
        if (Scenario_RunTrigger(events, 1, &query) != 0) {
            EventQuery_RunQueuedCommands(&query);
        }
        if (var40 == 0 && party[2] != 0) {
            self->changed = 1;
        }
        break;
    }
    case 7:
        func_0208bb78(self->timer, gs->GetTickCount());
        if (*(short*)(self->timer + 0xd2) >= 0) {
            if (self->changed == 0) {
                func_0208beb4(self->timer);
                break;
            }
            func_ov017_021bd38c(res->unknown_ptr_array_371c[6], (int)self->timer, (int)&self->allocA);
            self->unknown_137_ = 1;
        }
        GameObject_EnableControl(leader);
        if (hud != NULL) {
            func_020a27ac(hud);
        }
        self->done = 1;
        func_ov017_021b8d80(self);
        break;
    }
}
