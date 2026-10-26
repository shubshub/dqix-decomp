#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov001_02156108_140 = 0x4c };
#else
enum { Enum_ov001_02156108_140 = 0x8c };
#endif

extern "C" char* MessageSystem_GetInstance(void);
extern "C" void func_0208beb4(unsigned char* obj);
extern "C" void func_0208bb78(void* obj, int count);
struct Struct_0208ba54;
extern "C" void func_0208ba54(struct Struct_0208ba54*);
extern "C" int func_ov001_02153948(unsigned short arg);

struct Struct_ov001_02156108 {
    char pad0[0xa];
    unsigned short unknown_a_;
    char pad1[0x42];
    unsigned short unknown_4e_;
    unsigned short unknown_50_;
#if defined(jpn)
    char pad2[0xa8];
#else
    char pad2[0xac];
#endif
    unsigned char unknown_fe_;
    char pad3[0x21];
    void* unknown_120_;
};

// USA: func_ov001_02156108
extern "C" ARM int func_ov001_02156108(struct Struct_ov001_02156108* self) {
    GameState* battle = GameState::GetInstance();
    char* g6 = MessageSystem_GetInstance();
    unsigned int* var2 = (unsigned int*)((int)GetGameResources());

    if ((self->unknown_50_ & 0x2) || (self->unknown_50_ & 0x8)) {
        void* ptr = self->unknown_120_;
        if (ptr) {
            if (*(short*)((char*)ptr + 0xd2) >= 0) {
                func_0208beb4((unsigned char*)ptr);
                unsigned int scaleCount = battle->GetTickCount();
                func_0208bb78(self->unknown_120_, scaleCount);
                return self->unknown_a_;
            }
            func_0208ba54((struct Struct_0208ba54*)ptr);
        }
        *(int*)(g6 + Enum_ov001_02156108_140) = 0;
        self->unknown_120_ = 0;
    }

    if (TestFlags00((GameResources*)var2, 0x1000) == 0) {
        FontBankLoader* val = FontBankLoader_GetInstance();
        func_02094b40(val);
        FontBankLoader_CancelLoads(val);
        func_02094b34(val, 0x6f, 0x1388, 1, 1);
    }
    self->unknown_fe_ = 0;
    func_ov001_02153948(self->unknown_4e_);
    return 0xb;
}
