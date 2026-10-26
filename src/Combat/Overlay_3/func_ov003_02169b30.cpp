#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02169b30_1257 = 0x4e5 };
enum { kRegionValueE4_E0 = 0xe0 };
enum { Enum_ov003_02169b30_1439 = 0x59b };
enum { Enum_ov003_02169b30_1261 = 0x4e9 };
enum { Enum_ov003_02169b30_1258 = 0x4e6 };
#else
enum { Enum_ov003_02169b30_1257 = 0x4e9 };
enum { kRegionValueE4_E0 = 0xe4 };
enum { Enum_ov003_02169b30_1439 = 0x59f };
enum { Enum_ov003_02169b30_1261 = 0x4ed };
enum { Enum_ov003_02169b30_1258 = 0x4ea };
#endif


extern "C" void func_ov003_02169594(void* obj);
extern "C" int func_ov003_0216950c(void* obj);
extern "C" void func_ov003_0216a974(void* obj, int mode, int flag);
extern "C" void func_ov003_0216aa28(void* obj);

extern "C" void func_0205cef8(void* obj);
extern "C" void func_0205cf04(void* obj);
extern "C" void func_0205cf10(void* obj);

struct Struct_0205cf1c;
extern "C" void func_0205cf1c(struct Struct_0205cf1c* s);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern "C" int func_ov003_02169554(void* obj);

extern int g_sePlayer;

// USA: func_ov003_02169b30
extern "C" ARM int func_ov003_02169b30(void* p) {
    char* obj = (char*)p;
    unsigned char state = *(unsigned char*)(obj + Enum_ov003_02169b30_1257);
    if (state == 0) {
        func_ov003_02169594(obj);
        func_0205cef8(obj + kRegionValueE4_E0);
        func_0205cf04(obj + kRegionValueE4_E0);
        *(unsigned char*)(obj + Enum_ov003_02169b30_1257) = *(unsigned char*)(obj + Enum_ov003_02169b30_1257) + 1;
    } else if (state == 1) {
        *(unsigned char*)(obj + Enum_ov003_02169b30_1439) |= 1;
        int e = Window_GetSelectedIndex((struct Struct_0205c570*)(obj + kRegionValueE4_E0));
        *(unsigned char*)(obj + Enum_ov003_02169b30_1261) = (unsigned char)e;
        if (func_ov003_0216950c(obj) != 0) {
            func_ov003_0216a974(obj, 1, 1);
            *(unsigned char*)(obj + Enum_ov003_02169b30_1439) &= ~1;
            func_ov003_0216aa28(obj);
            *(unsigned char*)(obj + Enum_ov003_02169b30_1258) = 0;
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
            func_0205cf10(obj + kRegionValueE4_E0);
            func_0205cf1c((struct Struct_0205cf1c*)(obj + kRegionValueE4_E0));
            *(unsigned char*)(obj + Enum_ov003_02169b30_1257) = 0;
            return *(signed char*)(obj + Enum_ov003_02169b30_1261);
        } else {
            if (func_ov003_02169554(obj) != 0) {
                *(unsigned char*)(obj + Enum_ov003_02169b30_1439) &= ~1;
                func_0205cf10(obj + kRegionValueE4_E0);
                func_0205cf1c((struct Struct_0205cf1c*)(obj + kRegionValueE4_E0));
                *(unsigned char*)(obj + Enum_ov003_02169b30_1257) = 0;
                return -2;
            }
        }
    }
    return -1;
}
