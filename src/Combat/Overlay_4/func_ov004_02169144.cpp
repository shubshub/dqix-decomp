#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { stateOffset = 0x964, Enum_ov004_02169144_384 = 0, Enum_ov004_02169144_388 = 4, Enum_ov004_02169144_392 = 8, fieldOffset = 0x8c, flagOffset = 0x790, Enum_ov004_02169144_256 = 0 };
#else
enum { stateOffset = 0xb84, Enum_ov004_02169144_384 = 0x180, Enum_ov004_02169144_388 = 0x184, Enum_ov004_02169144_392 = 0x188, fieldOffset = 0x6c, flagOffset = 0x962, Enum_ov004_02169144_256 = 0x100 };
#endif

extern "C" void* Zone3D_GetInstance(void);
struct Struct_0201e828;
extern "C" void func_0201e828(Struct_0201e828*, unsigned short);
extern "C" void func_ov017_021a967c(unsigned char* self, int id);
extern "C" int MessageSystem_GetInstance(void);
extern void* data_ov004_02171030;
struct Struct_ov004_02169144 {
#if defined(jpn)
 char pad[0xc];
#else
 char pad[0x8c];
#endif
 unsigned short unknown_8c_; };

// USA: func_ov004_02169144
extern "C" ARM int func_ov004_02169144(void) {
    GameState::GetInstance();
    void* obj = GetGameResources();
    unsigned char* self = *(unsigned char**)((char*)obj + 0x3000 + stateOffset);
    ClearFlags00((GameResources*)obj, -1);
    ClearFlags04((GameResources*)obj, -1);
    ClearFlags08((GameResources*)obj, -1);
    SetFlags00((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + Enum_ov004_02169144_384));
    SetFlags04((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + Enum_ov004_02169144_388));
    SetFlags08((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + Enum_ov004_02169144_392));
    void* v = Zone3D_GetInstance();
    if (!v) return 0;
    struct Struct_0201e828* p = (struct Struct_0201e828*)((char*)v + fieldOffset);
    if (!p) return 0;
    struct Struct_ov004_02169144* var4 = (struct Struct_ov004_02169144*)((char*)data_ov004_02171030 + Enum_ov004_02169144_256);
    func_0201e828(p, var4->unknown_8c_);
    func_ov017_021a967c(self, -1);
    int g = MessageSystem_GetInstance();
    g += 0x1000;
    *(unsigned char*)(g + flagOffset) = 0;
    return 0;
}
