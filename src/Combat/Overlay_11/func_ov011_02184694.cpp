#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_ov017_021959b4(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);
extern "C" void func_ov011_021848a8(void* obj);
struct Struct_ov011_02184694_2;
extern "C" void func_ov011_02184a84(struct Struct_ov011_02184694_2* obj);
extern "C" void func_ov011_02184ae4(void* obj);
extern "C" void func_ov023_021f68dc(void* list, void* obj);
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_ov011_02184770(void* obj);

struct Struct_ov011_02184694 {
    char pad[0x1cc];
    unsigned char unknown_1cc_;
    unsigned char unknown_1cd_;
};

// USA: func_ov011_02184694
extern "C" ARM int func_ov011_02184694(Struct_ov011_02184694* obj) {
    int ctx = (int)GetGameResources();
    LinkSession_GetInstance();
    if (obj->unknown_1cd_ == 0) {
        int flag = func_ov017_021959b4();
        if (flag) {
            obj->unknown_1cd_ = 1;
            if (ctx) {
                SetBrightness((GameResources*)ctx, -16, 10);
            }
        }
        func_ov011_021848a8(obj);
        func_ov011_02184a84((struct Struct_ov011_02184694_2*)obj);
        func_ov011_02184ae4(obj);
        func_ov023_021f68dc((char*)obj + 0x118, obj);
    } else if (ctx != 0 && !IsBrightnessTransitionActive((GameResources*)ctx)) {
        func_ov011_02184770(obj);
        obj->unknown_1cc_ = 1;
    }
    return obj->unknown_1cc_ == 0;
}
