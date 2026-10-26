#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { stateOffset = 0x8c, Enum_ov004_0216ecd0_3954 = 0xc9e, Enum_ov004_0216ecd0_3955 = 0xc9f };
#else
enum { stateOffset = 0x6c, Enum_ov004_0216ecd0_3954 = 0xf72, Enum_ov004_0216ecd0_3955 = 0xf73 };
#endif

extern "C" void* Zone3D_GetInstance(void);
struct Struct_0201e828;
extern "C" void func_0201e828(Struct_0201e828*, unsigned short);
extern "C" void func_02012010(void* obj, int value);
extern "C" void func_ov017_0218d258(void* obj);

struct Struct_ov004_02171048_2 { char pad[0x4]; char* ptr; };
extern Struct_ov004_02171048_2 data_ov004_02171048;

// USA: func_ov004_0216ecd0
extern "C" ARM int func_ov004_0216ecd0(void) {
    GameState* bs = GameState::GetInstance();
    void* obj = GetGameResources();
    ClearFlags00((GameResources*)obj, -1);
    ClearFlags04((GameResources*)obj, -1);
    ClearFlags08((GameResources*)obj, -1);
    SetFlags00((GameResources*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x0));
    SetFlags04((GameResources*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x4));
    SetFlags08((GameResources*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x8));
    void* v = Zone3D_GetInstance();
    if (!v) return 0;
    struct Struct_0201e828* p = (struct Struct_0201e828*)((char*)v + stateOffset);
    if (!p) return 0;
    func_0201e828(p, *(unsigned short*)(data_ov004_02171048.ptr + 0xc));
    func_02012010(bs, 5);
    *(char*)((char*)bs + 0x7000 + Enum_ov004_0216ecd0_3954) = 1;
    *(char*)((char*)bs + 0x7000 + Enum_ov004_0216ecd0_3955) = 1;
    func_ov017_0218d258(obj);
    return 0;
}
