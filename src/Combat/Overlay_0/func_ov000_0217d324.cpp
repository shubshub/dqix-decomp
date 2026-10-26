#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x1faa, Enum_ov000_0217d324_7531 = 0x1fa3, Enum_ov000_0217d324_7528 = 0x1fa0, Enum_ov000_0217d324_7520 = 0x1f98 };
#else
enum { kFlagsOffset = 0x1d72, Enum_ov000_0217d324_7531 = 0x1d6b, Enum_ov000_0217d324_7528 = 0x1d68, Enum_ov000_0217d324_7520 = 0x1d60 };
#endif

struct Struct_0205c570;
struct SePlayer;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" struct TableEntry0217f8c0* func_ov000_0217f8c0(struct Struct0217f8c0* s);
extern "C" int func_ov000_0217c5f4(void* objRaw);
extern "C" int func_ov000_0217c594(void* objRaw, int limit);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int mode, int arg3, int arg4);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern struct SePlayer g_sePlayer;

// USA: func_ov000_0217d324
extern "C" ARM void func_ov000_0217d324(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + kFlagsOffset) |= 0x100;
    int sum = Window_GetSelectedIndex((struct Struct_0205c570*)(obj + 0x188));
    if (sum < 0) {
        sum = 0;
    }
    *(signed char*)(obj + Enum_ov000_0217d324_7531) = sum;
    if (func_ov000_0217c594(obj, 0) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        *(signed char*)(obj + Enum_ov000_0217d324_7528) = *(signed char*)(obj + Enum_ov000_0217d324_7528) + 1;
        *(unsigned char*)(obj + *(signed char*)(obj + Enum_ov000_0217d324_7528) + Enum_ov000_0217d324_7520) = 4;
        struct TableEntry0217f8c0* e = func_ov000_0217f8c0((struct Struct0217f8c0*)obj);
        func_ov000_02176634(obj, e, 4, arg1, arg2);
    } else if (func_ov000_0217c5f4(obj) != 0) {
        Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + Enum_ov000_0217d324_7528) + Enum_ov000_0217d324_7520) = 0;
        *(signed char*)(obj + Enum_ov000_0217d324_7528) = *(signed char*)(obj + Enum_ov000_0217d324_7528) - 1;
        *(signed char*)(obj + Enum_ov000_0217d324_7531) = -1;
        func_ov000_0217c638(obj, arg1, arg2);
    }
}
