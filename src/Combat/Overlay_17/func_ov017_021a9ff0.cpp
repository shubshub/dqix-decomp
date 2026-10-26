#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/OverlayId.h"

struct Struct_0206f81c_2;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_020469f8;
struct Struct_020469f8_2;
struct SafeAllocator;
struct GameResources;
struct Struct_020213fc;

void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void SetBrightness(GameResources* resources, int brightness, int frames);
void MapDisplay_SetHoldSubScreenDark(SetFlagStruct* obj, int value);
void CopyGlobalBlockAndDispatch_02165df4(SafeAllocator* allocator, void* arg);
extern char data_ov017_021d7831;

// USA: func_ov017_021a9ff0
extern "C" ARM void func_ov017_021a9ff0(int arg0) {
#if defined(jpn)
 enum {Enum_ov017_021a9ff0_15180=0x392c, Enum_ov017_021a9ff0_14076=0x34ec};
#else
 enum {Enum_ov017_021a9ff0_15180=0x3b4c, Enum_ov017_021a9ff0_14076=0x36fc};
#endif
    GameResources* res = GameState::GetInstance()->GetResources();
    SetFlagStruct* flags;
    void* list;
    unsigned char* obj;
    obj = *(unsigned char**)((char*)res + regionalOffset0);
#if defined(jpn)
    var1 = *(Struct_020213fc**)((char*)var0 + 0x34c0);
#else
    var1 = *(Struct_020213fc**)((char*)var0 + 0x36d0);
#endif
    var2 = *(void**)((char*)var0 + Enum_ov017_021a9ff0_14076);
    func_ov017_021b2174(var3);
    func_ov017_021b2ba0((Struct_0206f81c_2*)var3, &data_ov017_021d7831);
    func_ov017_021b2bd0(var3, (int)func_ov004_02165df4, OVERLAY_ID(4));
    if (arg0) {
        func_020469f8((Struct_020469f8*)var2, (Struct_020469f8_2*)var3);
    } else {
        func_020469b4((Struct_0201bdac_2*)var2, (Struct_0201bdac*)var3);
    }
    SetBrightness(res, -16, 0x19);
    MapDisplay_SetHoldSubScreenDark(flags, 1);
}
