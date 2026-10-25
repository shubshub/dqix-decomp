#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { stateOffset = 0x964, bits0 = 0, bits4 = 4, bits8 = 8, fieldOffset = 0x8c, flagOffset = 0x790, fieldBase = 0 };
#else
enum { stateOffset = 0xb84, bits0 = 0x180, bits4 = 0x184, bits8 = 0x188, fieldOffset = 0x6c, flagOffset = 0x962, fieldBase = 0x100 };
#endif

extern "C" void* Zone3D_GetInstance(void);
struct S_e828;
void SetFieldAt0x7e_0201e828(S_e828*, unsigned short);
extern "C" void func_ov017_021a967c(unsigned char* self, int id);
int MessageSystem_GetInstance(void);
extern void* data_ov004_02171030;
struct FieldGroup02171030At100 {
#if defined(jpn)
 char pad[0xc];
#else
 char pad[0x8c];
#endif
 unsigned short field8c; };

// USA: func_ov004_02169144  (semantic: ResetOv017FieldsAndClearFlag_02169144)
extern "C" ARM int func_ov004_02169144(void) {
    GameState::GetInstance();
    void* obj = GetGameResources();
    unsigned char* self = *(unsigned char**)((char*)obj + 0x3000 + stateOffset);
    ClearFlags00((GameResources*)obj, -1);
    ClearFlags04((GameResources*)obj, -1);
    ClearFlags08((GameResources*)obj, -1);
    SetFlags00((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits0));
    SetFlags04((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits4));
    SetFlags08((GameResources*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits8));
    void* v = Zone3D_GetInstance();
    if (!v) return 0;
    struct S_e828* p = (struct S_e828*)((char*)v + fieldOffset);
    if (!p) return 0;
    struct FieldGroup02171030At100* s100 = (struct FieldGroup02171030At100*)((char*)data_ov004_02171030 + fieldBase);
    SetFieldAt0x7e_0201e828(p, s100->field8c);
    func_ov017_021a967c(self, -1);
    int g = MessageSystem_GetInstance();
    g += 0x1000;
    *(unsigned char*)(g + flagOffset) = 0;
    return 0;
}
