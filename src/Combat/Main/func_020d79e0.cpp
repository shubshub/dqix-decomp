#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct SePlayer;
struct Struct_0206f81c_2;
struct List02046a3c;
struct Node02046a3c;
struct SafeAllocator;

struct StatusMenuRequest {
    unsigned char unknown0[0x4c];
    int unknown_4c_;
};

extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_02046a3c(List02046a3c* list, Node02046a3c* node);
extern "C" void func_ov004_021633ac(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_020f233d;

// USA: func_020d79e0
extern "C" ARM void func_020d79e0(void* unused, int arg1) {
    GameResources* res = GetGameResources();
    List02046a3c* list;
    StatusMenuRequest* request = static_cast<StatusMenuRequest*>(res->fieldTasks_[20]);
    list = (List02046a3c*)res->fieldTaskQueue_;
    SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
    func_ov017_021b2174(reinterpret_cast<unsigned char*>(request));
    request->unknown_4c_ = arg1;
    func_ov017_021b2ba0((Struct_0206f81c_2*)request, &data_020f233d);
    func_ov017_021b2bd0(request, (int)func_ov004_021633ac, OVERLAY_ID(4));
    func_02046a3c(list, (Node02046a3c*)request);
}
