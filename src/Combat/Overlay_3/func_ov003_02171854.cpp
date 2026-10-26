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
extern "C" int func_0202b800(int* p);
extern "C" void func_0202c360(void* self, int value);
extern "C" void LinkSession_Update(void* obj);
extern "C" void func_0202c410(void* obj);

struct SearchStruct;
extern "C" void LinkSession_RemoveMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

// USA: func_ov003_02171854
extern "C" ARM void func_ov003_02171854(char* self) {
    GameState* battle = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameObject* combatant = battle->GetProtagonist();

    int r = func_0202b000(search);
    if (r != 0) {
        if (r == 3) {
            return;
        }
        LinkSession_End(search);
        self[0] = 0xa;
        return;
    }

    func_0202b800((int*)search);
    func_0202c360(search, *(int*)((char*)combatant + 0x134));
    LinkSession_Update(search);
    func_0202c410(search);
    LinkSession_RemoveMember((struct SearchStruct*)search, 0xf);
    LinkSession_UpdateMemberCount(search);

    int v = (rand() % 4 + 2) * 500;
    *(int*)(self + 4) = v;

    *(unsigned int*)(self + 4) = *(unsigned int*)(self + 4) / 2 + *(unsigned int*)(self + 4) / 2 * *(signed char*)(self + Enum_ov003_02171854_1842) / 3;

    *(int*)(self + Enum_ov003_02171854_1836) = 0;
    *(int*)(self + Enum_ov003_02171854_1820) = 0;
    *(int*)(self + Enum_ov003_02171854_1824) = 0;
    *(int*)(self + Enum_ov003_02171854_1828) = 0;
    self[0] = 5;
}
