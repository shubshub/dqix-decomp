#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_021764f4_4098 = 0xf7e };
enum { Enum_ov003_021764f4_4094 = 0xf7a };
enum { Enum_ov003_021764f4_2204 = 0x818 };
enum { Enum_ov003_021764f4_2188 = 0x808 };
enum { Enum_ov003_021764f4_4088 = 0xf74 };
#else
enum { Enum_ov003_021764f4_4098 = 0x1002 };
enum { Enum_ov003_021764f4_4094 = 0xffe };
enum { Enum_ov003_021764f4_2204 = 0x89c };
enum { Enum_ov003_021764f4_2188 = 0x88c };
enum { Enum_ov003_021764f4_4088 = 0xff8 };
#endif

extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_0207fdcc_2;
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);

struct Struct_02081f20_2;
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);

struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8* obj);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_021764f4
extern "C" ARM int func_ov003_021764f4(unsigned char* self) {
#if defined(jpn)
    *(void**)(self + 0xf74) = self + 0xf7e;
#else
    *(void**)(self + 0xff8) = self + 0x2 + 0x1000;
#endif
    int result = 0;
    if (func_ov003_021765b4(self) != 0) {
        goto dispatch;
    }
    if (g_keyManager.TestKeysPressed(0x200) == 0) {
        goto alt;
    }
dispatch:
    SePlayer_Play(&g_sePlayer, 1, 0);
    result = -1;
    if (*(short*)(self + Enum_ov003_021764f4_4098) == 2) {
        result = 1;
    }
    goto merge;
alt:
    if (func_ov003_021766e8(self) != 0) {
        result = -1;
    }
merge:
    if (result != 0) {
        short key = *(short*)(self + Enum_ov003_021764f4_4094);
        func_0207fdcc(*(struct Struct_0207fdcc_2**)(self + Enum_ov003_021764f4_2204), key);
        func_0208203c((struct Struct_02081f20_2*)(self + Enum_ov003_021764f4_2188));
        *(void**)(self + Enum_ov003_021764f4_4088) = 0;
    }
    if (*(void**)self != 0 && result != 0) {
        func_020e25e8(*(struct Struct_020e25e8**)self);
    }
    return result;
}
