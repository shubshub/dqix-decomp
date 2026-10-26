#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02171854_1842 = 0x62e };
enum { Enum_ov003_02171854_1836 = 0x628 };
enum { Enum_ov003_02171854_1820 = 0x618 };
enum { Enum_ov003_02171854_1824 = 0x61c };
enum { Enum_ov003_02171854_1828 = 0x620 };
#else
enum { Enum_ov003_02171854_1842 = 0x732 };
enum { Enum_ov003_02171854_1836 = 0x72c };
enum { Enum_ov003_02171854_1820 = 0x71c };
enum { Enum_ov003_02171854_1824 = 0x720 };
enum { Enum_ov003_02171854_1828 = 0x724 };
#endif

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0202b000(void* obj);
extern "C" void LinkSession_End(void* p);
extern int SetStateToThreeAndDispatch0202b800(int* p);
extern "C" void func_0202c360(void* self, int value);
extern "C" void LinkSession_Update(void* obj);
void CopyBattleTailToObjField0x102c_0202c410(void* obj);

struct SearchStruct;
extern void LinkSession_RemoveMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

// USA: func_ov003_02171854
extern "C" ARM void func_ov003_02171854(char* self) {
    GameState* battle = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameObject* combatant = battle->GetProtagonist();

    int var3 = func_0202b000(var1);
    if (var3 != 0) {
        if (var3 == 3) {
            return;
        }
        LinkSession_End(search);
        self[0] = 0xa;
        return;
    }

    SetStateToThreeAndDispatch0202b800((int*)search);
    func_0202c360(search, *(int*)((char*)combatant + 0x134));
    LinkSession_Update(search);
    CopyBattleTailToObjField0x102c_0202c410(search);
    LinkSession_RemoveMember((struct SearchStruct*)search, 0xf);
    LinkSession_UpdateMemberCount(search);

    int var4 = (rand() % 4 + 2) * 500;
    *(int*)(arg0 + 4) = var4;

    *(unsigned int*)(arg0 + 4) = *(unsigned int*)(arg0 + 4) / 2 + *(unsigned int*)(arg0 + 4) / 2 * *(signed char*)(arg0 + Enum_ov003_02171854_1842) / 3;

    *(int*)(arg0 + Enum_ov003_02171854_1836) = 0;
    *(int*)(arg0 + Enum_ov003_02171854_1820) = 0;
    *(int*)(arg0 + Enum_ov003_02171854_1824) = 0;
    *(int*)(arg0 + Enum_ov003_02171854_1828) = 0;
    arg0[0] = 5;
}
