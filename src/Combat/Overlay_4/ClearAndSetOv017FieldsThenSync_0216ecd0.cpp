#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { stateOffset = 0x8c, firstFlag = 0xc9e, secondFlag = 0xc9f };
#else
enum { stateOffset = 0x6c, firstFlag = 0xf72, secondFlag = 0xf73 };
#endif

extern "C" void* Zone3D_GetInstance(void);
struct S_e828;
void SetFieldAt0x7e_0201e828(S_e828*, unsigned short);
void SetWord0x7f6c_02012010(void* obj, int value);
void SetFieldFlag17188_0218d258(void* obj);

struct Struct02171048_0216ecd0 { char pad[0x4]; char* ptr; };
extern Struct02171048_0216ecd0 data_ov004_02171048;

// USA: func_ov004_0216ecd0  (semantic: ClearAndSetOv017FieldsThenSync_0216ecd0)
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
    struct S_e828* p = (struct S_e828*)((char*)v + stateOffset);
    if (!p) return 0;
    SetFieldAt0x7e_0201e828(p, *(unsigned short*)(data_ov004_02171048.ptr + 0xc));
    SetWord0x7f6c_02012010(bs, 5);
    *(char*)((char*)bs + 0x7000 + firstFlag) = 1;
    *(char*)((char*)bs + 0x7000 + secondFlag) = 1;
    SetFieldFlag17188_0218d258(obj);
    return 0;
}
