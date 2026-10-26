#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021716f8_1828 = 0x620 };
enum { Enum_ov003_021716f8_1572 = 0x624 };
enum { Enum_ov003_021716f8_1576 = 0x628 };
#else
enum { Enum_ov003_021716f8_1828 = 0x724 };
enum { Enum_ov003_021716f8_1832 = 0x728 };
enum { Enum_ov003_021716f8_1836 = 0x72c };
#endif

#if defined(jpn)
extern "C" void func_ov003_021714f0(void*);
#endif
#include "GameState/GameState.h"

struct Struct_ov003_021714f0;
extern "C" void func_ov003_02172518(struct Struct_ov003_021714f0* obj, int flag);
extern "C" void LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void);

struct Struct_ov003_021716f8 {
    char pad0[0x34c];
    int unknown_34c_;
    char unknown_350_[Enum_ov003_021716f8_1828 - 0x350];
    int unknown_724_;
    char unknown_728_[4];
    unsigned int unknown_72c_;
};

// USA: func_ov003_021716f8
extern "C" ARM void func_ov003_021716f8(struct Struct_ov003_021716f8* obj) {
    unsigned char* b = (unsigned char*)obj;

    if (obj->unknown_724_ != 0) {
#if defined(jpn)
        func_ov003_021714f0(obj);
#else
        int flag = ((unsigned int)obj->unknown_34c_ >> 31) ? 1 : 0;
        func_ov003_02172518((struct Struct_ov003_021714f0*)obj, flag);
#endif
        b[0] = 3;
    }

    obj->unknown_72c_ += GameState::GetInstance()->GetEffectiveDeltaTime();
    if (obj->unknown_72c_ <= 0xbb8) return;

    LinkSession_GetInstance();
    LinkSession_End();
    b[0] = 4;
}
