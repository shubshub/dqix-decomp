#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02171550_1840 = 0x62c };
enum { Enum_ov003_02171550_1836 = 0x628 };
enum { Enum_ov003_02171550_1828 = 0x618 };
enum { Enum_ov003_02171550_1820 = 0x61c };
#else
enum { Enum_ov003_02171550_1840 = 0x730 };
enum { Enum_ov003_02171550_1836 = 0x72c };
enum { Enum_ov003_02171550_1828 = 0x724 };
enum { Enum_ov003_02171550_1820 = 0x71c };
#endif

struct SearchStruct;
struct Struct_ov003_02171550 {
    unsigned char field0;
    char pad1[Enum_ov003_02171550_1840 - 1];
    unsigned char unknown_730_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0202b000(void* ptr);
extern "C" void LinkSession_End(void* ptr);
extern "C" int func_0202b7ec(void* obj);
extern "C" void func_0202c360(void* self, int value);
extern "C" void LinkSession_Update(void* ptr);
extern "C" void func_0202c410(void* obj);
extern "C" void func_0202b828(unsigned char* obj);
extern "C" void LinkSession_RemoveMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_AddMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* ptr);

// USA: func_ov003_02171550
extern "C" ARM void func_ov003_02171550(struct Struct_ov003_02171550* obj) {
    if (!(obj->unknown_730_ & 1)) {
        obj->field0 = 8;
        return;
    }

    GameState* battle = GameState::GetInstance();
    void* ptr = LinkSession_GetInstance();
    GameObject* c = battle->GetProtagonist();

    int state = func_0202b000(ptr);
    if (state != 0) {
        if (state == 3) return;
        LinkSession_End(ptr);
        obj->field0 = 0xa;
        return;
    }

    func_0202b7ec(ptr);
    func_0202c360(ptr, *(int*)((char*)c + 0x134));
    LinkSession_Update(ptr);
    func_0202c410(ptr);
    func_0202b828((unsigned char*)ptr);
    LinkSession_RemoveMember((struct SearchStruct*)ptr, 0xf);
    LinkSession_AddMember((struct SearchStruct*)ptr, 0);
    LinkSession_UpdateMemberCount(ptr);

    *(int*)((char*)obj + 4) = (rand() % 4 + 2) * 500;

    *(int*)((char*)obj + Enum_ov003_02171550_1836) = 0;
    *(int*)((char*)obj + Enum_ov003_02171550_1828) = 0;
    *(int*)((char*)obj + Enum_ov003_02171550_1820) = 0;
#if !defined(jpn)
    *(int*)((char*)obj + 0x720) = 0;
#endif
    obj->field0 = 1;
}
