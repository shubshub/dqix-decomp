#include <globaldefs.h>
#include "Resource/Script.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"


#if defined(jpn)
enum { kResourceHeaderOffset = 0x4fc, Enum_ov017_021ab860_1260 = 0x4ec,
       Enum_ov017_021ab860_17582 = 0x41fe, Enum_ov017_021ab860_17584 = 0x4200 };
#define data_ov017_021d83bc data_ov017_021d8c7c
#define data_ov017_021d78c4 data_ov017_021d7e2c
#define data_ov017_021d78a4 data_ov017_021d7e0c
#else
enum { kResourceHeaderOffset = 0x70c, Enum_ov017_021ab860_1788 = 0x6fc,
       Enum_ov017_021ab860_17582 = 0x44ae, Enum_ov017_021ab860_17584 = 0x44b0 };
#endif

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* memset(void* dst, int val, unsigned int size);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int obj, unsigned char* bits, int index);
extern "C" int GameState_IsInGrotto(GameState* gameState);
struct Obj021abb68;
extern "C" void func_ov017_021abb68(struct Obj021abb68* obj, unsigned char arg);
struct List02046a3c;
struct Node02046a3c;
extern "C" void func_02046a3c(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" int func_ov017_0219ff58(GameResources* res, int a, int b, int c);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Active021ab860 {
    unsigned short zoneId;
    unsigned short pad2;
    unsigned short group;
    char pad6[2];
    int header;
};

struct Struct_ov017_021d83b0_2 {
    int header;
    unsigned short key;
    unsigned short group;
    unsigned short entryId;
    char unknown_a_[2];
    Vector3i vec;
    short unknown_18_;
};
extern Struct_ov017_021d83b0_2 data_ov017_021d83b0;
extern Vector3i data_ov017_021d83bc;
extern char data_ov017_021d78c4[];
extern Script::OpcodeLookupEntry data_ov017_021d78a4[];

struct Struct_ov017_021ab860_3 {
    char pad0[0xc];
    int zoneId;
    Vector3i unknown_10_;
};

struct Entry3f8_021ab860 {
    unsigned short entryId;
    char pad2[2];
    unsigned char unknown_4_;
    char pad5[2];
    unsigned char unknown_7_;
    unsigned char b8;
    unsigned char unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    Vector3i vec;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_, unknown_24_, unknown_28_, unknown_2c_;
    char unknown_30_[0x6c - 0x30];
    short unknown_6c_;
    char unknown_6e_[2];
};

// USA: func_ov017_021ab860
extern "C" ARM int func_ov017_021ab860(int arg0, unsigned char arg1) {
    GameState* gs = GameState::GetInstance();
    gs->GetResources();
    data_ov017_021d83b0.header = ((Active021ab860*)Zone3D_GetInstance())->header;
    data_ov017_021d83b0.key = 0;
    data_ov017_021d83b0.group = 0;
    data_ov017_021d83b0.entryId = 0;
    memset(&data_ov017_021d83bc, 0, sizeof(Vector3i));
    data_ov017_021d83b0.unknown_18_ = 0;
    unsigned char* save = Scenario_GetInstance();
    if (Scenario_TestFlag((int)save, save + 0x8c, 0x113a) != 0) {
        return 1;
    }
    if (GameState_IsInGrotto(gs) != 0) {
        int status;
        GameState* state = GameState::GetInstance();
        Active021ab860* active = (Active021ab860*)Zone3D_GetInstance();
        Struct_ov017_021ab860_3* grotto = (Struct_ov017_021ab860_3*)state->GetGrottoStruct();
        if (grotto == NULL) {
            status = 0;
        } else {
            data_ov017_021d83b0.key = active->group;
            data_ov017_021d83b0.group = active->zoneId;
            data_ov017_021d83b0.entryId = grotto->zoneId;
            data_ov017_021d83b0.unknown_18_ = 0;
            data_ov017_021d83bc = grotto->unknown_10_;
            data_ov017_021d83b0.vec.z += 0x2000;
            status = 4;
        }
        if (status == 0) {
            return 0;
        }
    } else {
        int status;
        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->FreeAllocations();
        task = loader->QueueLoadFile(data_ov017_021d78c4, NULL);
        if (task < 0) {
            status = 0;
        } else {
            while (loader->GetTaskStatus(task) == 0) {
                loader->RemoveAllLocks();
            }
            if (loader->GetDetailedTaskStatus(task) != 2) {
                loader->RemoveTask(task);
                status = 0;
            } else {
                unsigned int length;
                void* data;
                loader->GetLoadedFileByID(task, &data, &length);
                Script script;
                script.Initialize();
                script.SetOpcodeLookup(data_ov017_021d78a4);
                script.Load(data, length);
                script.Execute();
                loader->RemoveTask(task);
                status = 4;
            }
        }
        if (status == 0) {
            return 0;
        }
    }
    if (data_ov017_021d83b0.entryId != 0) {
        GameResources* res = GetGameResources();
        func_ov017_021abb68((struct Obj021abb68*)res->fieldTasks_[6], arg1);
        func_02046a3c((struct List02046a3c*)res->fieldTaskQueue_,
                            (struct Node02046a3c*)res->fieldTasks_[6]);
        int busy = func_ov017_0219ff58(res, 1, 0, 0);
        if (busy != 0) {
            return 3;
        }
        if (busy == 0) {
            Entry3f8_021ab860* e = (Entry3f8_021ab860*)GameState_GetZoneTransition(gs);
            VectorizedMemset(e, 0, sizeof(Entry3f8_021ab860));
            e->unknown_4_ = 1;
            e->b8 = 1;
            e->unknown_9_ = 1;
            e->unknown_b_ = -1;
            e->unknown_20_ = -1;
            e->unknown_24_ = -1;
            e->unknown_28_ = -1;
            e->unknown_2c_ = -1;
            e->unknown_1e_ = -1;
            e->unknown_c_ = 0;
            e->unknown_6c_ = -1;
            e->entryId = data_ov017_021d83b0.entryId;
            e->vec = data_ov017_021d83bc;
            e->unknown_1c_ = data_ov017_021d83b0.unknown_18_;
            e->unknown_7_ = 1;
            GameState_SetZoneTransition(gs, e);
        }
        struct TailList020469b4* tail;
        unsigned char* header = (unsigned char*)res->unknown_ptr_array_3700[3];
        tail = (struct TailList020469b4*)res->fieldTaskQueue_;
        FieldTask_InitEnterZone(header, 0);
        func_020469b4(tail, (struct TailNode020469b4*)header);
        *(short*)((unsigned char*)res + Enum_ov017_021ab860_17582) = 0;
        *(short*)((unsigned char*)res + Enum_ov017_021ab860_17584) = 0;
        return 3;
    }
    return 0;
}
