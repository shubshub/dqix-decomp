#include <globaldefs.h>
#include "NitroSDK/OverlayId.h"
#include "Resource/GameResources.h"

struct Struct_0206f81c_2;
struct Struct_0206f81c_5;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* obj, unsigned int value);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int value);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int value);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov004_021689d8(SafeAllocator* allocator, void* arg);
extern char data_ov017_021d75d0;

// USA: func_ov017_0219c520
extern "C" ARM void func_ov017_0219c520() {
#if defined(jpn)
 enum {regionalOffset0=0x392c, regionalOffset1=0x34ec};
#else
 enum {regionalOffset0=0x3b4c, regionalOffset1=0x36fc};
#endif
    void* res = GetGameResources();
    TailList020469b4* list;
    unsigned char* obj = *(unsigned char**)((char*)res + regionalOffset0);
    list = *(TailList020469b4**)((char*)res + regionalOffset1);
    func_ov017_021b2174(obj);
    func_ov017_021b2ba0((Struct_0206f81c_2*)obj, &data_ov017_021d75d0);
    func_ov017_021b2bd0(obj, (int)func_ov004_021689d8, OVERLAY_ID(4));
    func_ov017_021b2bf4((Struct_0206f81c_3*)obj, 1);
    func_ov017_021b2c0c((Struct_0206f81c_4*)obj, 1);
    func_ov017_021b2bdc((Struct_0206f81c_5*)obj, 0);
    func_020469b4(list, (TailNode020469b4*)obj);
}
