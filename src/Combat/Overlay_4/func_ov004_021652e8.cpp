#include <globaldefs.h>
#include "Resource/Brightness.h"

struct Struct_ov004_02164670;
extern "C" int MessageSystem_GetInstance(void);
extern char* data_ov004_02171010;
struct Struct_ov004_021652e8 {
#if defined(jpn)
    unsigned char unknown[0x19f4];
#else
    unsigned char unknown[0x18f4];
#endif
    unsigned char unknown_18f4_;
    unsigned char unknown_18f5_;
    short page;
    short pageCount;
    unsigned char unknown_18fa_[2];
    unsigned char mode;
};
extern "C" void func_02026420(unsigned char* obj, unsigned char value);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
extern "C" int func_ov004_021651c8(void* a1);

#if defined(jpn)
enum { StatusOffset021652e8 = 0x868, Enum_ov004_021652e8_1744 = 0x4c0 };
// USA: func_ov004_021652e8
extern "C" ARM int func_ov004_02165b78(void* a1) {
#else
enum { StatusOffset021652e8 = 0x998, Enum_ov004_021652e8_1744 = 0x6d0 };
// USA: func_ov004_021652e8
extern "C" ARM int func_ov004_021652e8(void* a1) {
#endif
    struct Struct_ov004_02164670* axis = (struct Struct_ov004_02164670*)GetGameResources();
    if (!IsBrightnessZero((GameResources*)axis, false) || !IsBrightnessZero((GameResources*)axis, true)) return 0;
    if (*(void**)((char*)MessageSystem_GetInstance() + StatusOffset021652e8) != NULL) return 0;

    {
        Struct_ov004_021652e8* selection = (Struct_ov004_021652e8*)data_ov004_02171010;
        unsigned char v = selection->unknown_18f4_;
        if (v == 0) return 0;

        unsigned char* mode = &selection->mode;
        v = selection->mode;
        if (v == 0) {
            *mode = 1;
        } else if (v == 1) {
            *mode = 0;
        }

        unsigned char* fieldObj = *(unsigned char**)((char*)GetGameResources() + 0x3000 + Enum_ov004_021652e8_1744);
        unsigned char v2 = ((Struct_ov004_021652e8*)data_ov004_02171010)->mode;
        if (v2 == 1) {
            func_02026420(fieldObj, 0);
        } else if (v2 == 0) {
            func_02026420(fieldObj, 1);
        }

        func_ov004_021651c8(a1);
        SePlayer_Play(&g_sePlayer, 1, 0);
        return 0;
    }
}
