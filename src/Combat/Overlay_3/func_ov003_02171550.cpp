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

struct Struct_0202b2f0;
struct Struct_ov003_02171550 {
    unsigned char unknown_0_;
    char unknown_1_[Enum_ov003_02171550_1840 - 1];
    unsigned char unknown_730_;
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0202b000(void* ptr);
extern "C" void LinkSession_End(void* ptr);
int SetState2AndCall0202d6c8_0202b7ec(void* obj);
extern "C" void func_0202c360(void* self, int value);
extern "C" void LinkSession_Update(void* ptr);
void CopyBattleTailToObjField0x102c_0202c410(void* obj);
void SetField0To5AndField0x1008To1_0202b828(unsigned char* obj);
void LinkSession_RemoveMember(struct SearchStruct* obj, int value);
void LinkSession_AddMember(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(void* ptr);

// USA: func_ov003_02171550
extern "C" ARM void func_ov003_02171550(struct Struct_ov003_02171550* arg0) {
    if (!(arg0->unknown_730_ & 1)) {
        arg0->unknown_0_ = 8;
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

    SetState2AndCall0202d6c8_0202b7ec(ptr);
    func_0202c360(ptr, *(int*)((char*)c + 0x134));
    LinkSession_Update(ptr);
    CopyBattleTailToObjField0x102c_0202c410(ptr);
    SetField0To5AndField0x1008To1_0202b828((unsigned char*)ptr);
    LinkSession_RemoveMember((struct SearchStruct*)ptr, 0xf);
    LinkSession_AddMember((struct SearchStruct*)ptr, 0);
    LinkSession_UpdateMemberCount(ptr);

    *(int*)((char*)arg0 + 4) = (rand() % 4 + 2) * 500;

    *(int*)((char*)arg0 + Enum_ov003_02171550_1836) = 0;
    *(int*)((char*)arg0 + Enum_ov003_02171550_1828) = 0;
    *(int*)((char*)arg0 + Enum_ov003_02171550_1820) = 0;
#if !defined(jpn)
    *(int*)((char*)arg0 + 0x720) = 0;
#endif
    arg0->unknown_0_ = 1;
}
