#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct SePlayer;
struct Struct_0206f81c_2;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov004_02165df4(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_020f2334;

// USA: func_020d7978
extern "C" ARM void func_020d7978() {
    SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
    GameResources* res = GetGameResources();
    TailList020469b4* list;
    unsigned char* obj = static_cast<unsigned char*>(res->fieldTasks_[20]);
    list = (TailList020469b4*)res->fieldTaskQueue_;
    func_ov017_021b2174(obj);
    func_ov017_021b2ba0((Struct_0206f81c_2*)obj, &data_020f2334);
    func_ov017_021b2bd0(obj, (int)func_ov004_02165df4, OVERLAY_ID(4));
    func_020469b4(list, (TailNode020469b4*)obj);
}
