#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct SePlayer;
struct S021b2ba0;
struct List02046a3c;
struct Node02046a3c;
struct SafeAllocator;

struct Struct_020d79e0 {
    unsigned char unknown_0_[0x4c];
    int unknown_4c_;
};

void SePlayer_Play(SePlayer* obj, int a, int b);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void InsertNodeAfterHead(List02046a3c* list, Node02046a3c* node);
void AllocateAndCopyStruct60_021633ac(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_020f233d;

// USA: func_020d79e0
extern "C" ARM void func_020d79e0(void* unused, int selectedMember) {
    GameResources* res = GetGameResources();
    List02046a3c* list;
    StatusMenuRequest* request = static_cast<StatusMenuRequest*>(res->fieldTasks_[20]);
    list = (List02046a3c*)res->fieldTaskQueue_;
    SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
    InitObjState_021b2174(reinterpret_cast<unsigned char*>(request));
    request->selectedMember = selectedMember;
    SetNameChecked_021b2ba0((S021b2ba0*)request, &data_020f233d);
    SetFields30And34_021b2bd0(request, (int)AllocateAndCopyStruct60_021633ac, OVERLAY_ID(4));
    InsertNodeAfterHead(list, (Node02046a3c*)request);
}
