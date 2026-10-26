#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c0580;
struct Struct_0206f81c_2;
struct Struct_0206f81c_5;
struct HeadList020469f8;
struct HeadNode020469f8;

extern "C" void func_ov017_021c0820(Struct_ov017_021c0580* obj);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int value);
extern "C" void func_020469f8(HeadList020469f8* list, HeadNode020469f8* node);

// USA: func_ov017_021c0580
extern "C" ARM void func_ov017_021c0580(Struct_ov017_021c0580* self, int kind, char* name, int handler) {
#if defined(jpn)
 enum {regionalOffset0=0x392c, regionalOffset1=0x34ec};
#else
 enum {regionalOffset0=0x3b4c, regionalOffset1=0x36fc};
#endif
    void* res = GetGameResources();
    HeadList020469f8* list;
    unsigned char* obj = *(unsigned char**)((char*)res + regionalOffset0);
    list = *(HeadList020469f8**)((char*)res + regionalOffset1);
    func_ov017_021c0820(self);
    *(unsigned char*)((char*)self + 0x24) = kind;
    func_ov017_021b2174(obj);
    func_ov017_021b2ba0((Struct_0206f81c_2*)obj, name);
    func_ov017_021b2bd0(obj, handler, OVERLAY_ID(4));
    func_ov017_021b2bdc((Struct_0206f81c_5*)obj, 0);
    func_020469f8(list, (HeadNode020469f8*)obj);
}
