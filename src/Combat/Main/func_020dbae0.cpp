#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct Struct_020db894;
struct Struct_020db264;
struct Struct_020db3f4_3;
struct Struct_020db5ec_2;
struct Struct_020db3f4;

void RefreshSlots0x5cFromCallbacks(Obj020db964* obj);
int Overlay_IsLoaded(unsigned int idx);
extern "C" void func_020db894(void* obj);
int GetSwapBitIfFlag54Clear(Struct020db9a8* obj);
extern "C" void func_020db3f4(Obj020db3f4* obj);
void VCountIrq_PushDisable(void);
void RunFlaggedCallback020db844(Actor020db844* a, int b, int c, int d);
void InitCombatantVisualState_020db264(void* obj, int arg1, int arg2, int arg3, int arg4);
extern "C" void VCountIrq_PopDisable(void);
void ProcessDisplayDispatch020db5ec(DisplayDispatchObj020db5ec* obj);
void InitFlag0x28FromOverlay_020db814(void*);

// USA: func_020dbae0
extern "C" ARM void func_020dbae0(void* obj) {
    char* p = (char*)obj;
    RefreshSlots0x5cFromCallbacks((Obj020db964*)obj);
    if (!Overlay_IsLoaded(OVERLAY_ID(17))) {
        return;
    }
    void* var1 = GetGameResources();
    if (*(unsigned char*)(var0 + 0x50) == 0 || var1 == NULL) {
        func_020db894(arg0);
        return;
    }
    if (*(unsigned char*)(var0 + 0x52) == 0) {
        short var2 = *(short*)(var0 + 0x68);
        if (var2 < 0) {
            return;
        }
        if (var2 > 0) {
            *(short*)(var0 + 0x68) = var2 - 1;
            func_020db894(arg0);
            return;
        }
    }
    int var3 = func_020db9a8((Struct_020db264*)arg0);
    if (*(unsigned char*)(var0 + 0x51) == 0) {
        *(short*)(var0 + 0x6a) = *(short*)(var0 + 0x66);
        func_020db3f4((Struct_020db3f4*)arg0);
    } else {
        if (swapBit != *(unsigned char*)(p + 0x3c)) {
            VCountIrq_PushDisable();
            RunFlaggedCallback020db844((Actor020db844*)obj, *(unsigned char*)(p + 0x3c), *(short*)(p + 0x66), 0);
            short target = *(short*)(p + 0x6a);
            unsigned char a = *(unsigned char*)(p + 0x50);
            unsigned char b = *(unsigned char*)(p + 0x52);
            unsigned char c = *(unsigned char*)(p + 0x53);
            unsigned char d = *(unsigned char*)(p + 0x54);
            func_020db894(obj);
            *(short*)(p + 0x68) = 0;
            *(unsigned char*)(p + 0x3c) = swapBit;
            *(short*)(p + 0x6a) = *(short*)(p + 0x66) = target;
            InitCombatantVisualState_020db264(obj, a, b, c, d);
            VCountIrq_PopDisable();
            return;
        }
        func_020db5ec((Struct_020db5ec_2*)arg0);
    }
    func_020db814(arg0);
}
