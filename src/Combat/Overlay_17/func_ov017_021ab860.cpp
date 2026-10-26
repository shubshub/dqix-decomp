#include <globaldefs.h>
#include "Resource/Script.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/CopyRecord0200fbb4.h"


#if defined(jpn)
enum { Enum_ov017_021ab860_1276 = 0x4fc, Enum_ov017_021ab860_1260 = 0x4ec,
       Enum_ov017_021ab860_17582 = 0x41fe, Enum_ov017_021ab860_17584 = 0x4200 };
#define data_ov017_021d83bc data_ov017_021d8c7c
#define data_ov017_021d78c4 data_ov017_021d7e2c
#define data_ov017_021d78a4 data_ov017_021d7e0c
#else
enum { Enum_ov017_021ab860_1804 = 0x70c, Enum_ov017_021ab860_1788 = 0x6fc,
       Enum_ov017_021ab860_17582 = 0x44ae, Enum_ov017_021ab860_17584 = 0x44b0 };
#endif

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* memset(void* dst, int val, unsigned int size);
extern "C" unsigned char* Scenario_GetInstance(void);
int Scenario_TestFlag(int obj, unsigned char* bits, int index);
int GameState_IsInGrotto(GameState* gameState);
struct Obj021abb68;
void InitState28_021abb68(struct Obj021abb68* obj, unsigned char arg);
struct List02046a3c;
struct Node02046a3c;
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" int func_ov017_0219ff58(GameResources* res, int a, int b, int c);
void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
void FieldTask_InitEnterZone(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_021ab860_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    char unknown_6_[2];
    int unknown_8_;
};

struct Struct_ov017_021d83b0_2 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    char unknown_a_[2];
    Vector3i unknown_c_;
    short unknown_18_;
};
extern Struct_ov017_021d83b0_2 data_ov017_021d83b0;
extern Vector3i data_ov017_021d83bc;
extern char data_ov017_021d78c4[];
extern Script::OpcodeLookupEntry data_ov017_021d78a4[];

struct Struct_ov017_021ab860_3 {
    char unknown_0_[0xc];
    int unknown_c_;
    Vector3i unknown_10_;
};

struct Struct_ov017_021ab860_4 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    Vector3i unknown_10_;
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
    data_ov017_021d83b0.field_0x18 = 0;
    unsigned char* save = Scenario_GetInstance();
    if (Scenario_TestFlag((int)save, save + 0x8c, 0x113a) != 0) {
        return 1;
    }
    if (GameState_IsInGrotto(gs) != 0) {
        int status;
        GameState* state = GameState::GetInstance();
        Active021ab860* active = (Active021ab860*)Zone3D_GetInstance();
        Grotto021ab860* grotto = (Grotto021ab860*)state->GetGrottoStruct();
        if (grotto == NULL) {
            status = 0;
        } else {
            data_ov017_021d83b0.unknown_4_ = var4->unknown_4_;
            data_ov017_021d83b0.unknown_6_ = var4->unknown_0_;
            data_ov017_021d83b0.unknown_8_ = var5->unknown_c_;
            data_ov017_021d83b0.unknown_18_ = 0;
            data_ov017_021d83bc = var5->unknown_10_;
            data_ov017_021d83b0.unknown_c_.z += 0x2000;
            var2 = 4;
        }
        if (var2 == 0) {
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
            while (var8->GetTaskStatus(var7) == 0) {
                var8->RemoveAllLocks();
            }
            if (var8->GetDetailedTaskStatus(var7) != 2) {
                var8->RemoveTask(var7);
                var6 = 0;
            } else {
                unsigned int var9;
                void* var10;
                var8->GetLoadedFileByID(var7, &var10, &var9);
                Script var11;
                var11.Initialize();
                var11.SetOpcodeLookup(data_ov017_021d78a4);
                var11.Load(var10, var9);
                var11.Execute();
                var8->RemoveTask(var7);
                var6 = 4;
            }
        }
        if (var6 == 0) {
            return 0;
        }
    }
    if (data_ov017_021d83b0.entryId != 0) {
        GameResources* res = GetGameResources();
        InitState28_021abb68((struct Obj021abb68*)res->fieldTasks_[6], arg1);
        InsertNodeAfterHead((struct List02046a3c*)res->fieldTaskQueue_,
                            (struct Node02046a3c*)res->fieldTasks_[6]);
        int busy = func_ov017_0219ff58(res, 1, 0, 0);
        if (busy != 0) {
            return 3;
        }
        if (busy == 0) {
            Entry3f8_021ab860* e = (Entry3f8_021ab860*)GameState_GetZoneTransition(gs);
            VectorizedMemset(e, 0, sizeof(Entry3f8_021ab860));
            e->b4 = 1;
            e->b8 = 1;
            e->b9 = 1;
            e->bb = -1;
            e->w20 = -1;
            e->w24 = -1;
            e->w28 = -1;
            e->w2c = -1;
            e->h1e = -1;
            e->bc = 0;
            e->h6c = -1;
            e->entryId = data_ov017_021d83b0.entryId;
            e->vec = data_ov017_021d83bc;
            e->h1c = data_ov017_021d83b0.field_0x18;
            e->b7 = 1;
            GameState_SetZoneTransition(gs, e);
        }
        struct TailList020469b4* tail;
        unsigned char* header = (unsigned char*)res->unknown_ptr_array_3700[3];
        tail = (struct TailList020469b4*)res->fieldTaskQueue_;
        FieldTask_InitEnterZone(header, 0);
        AppendNodeToTail(tail, (struct TailNode020469b4*)header);
        *(short*)((unsigned char*)res + kTargetIdOffset) = 0;
        *(short*)((unsigned char*)res + kTargetArgOffset) = 0;
        return 3;
    }
    return 0;
}
