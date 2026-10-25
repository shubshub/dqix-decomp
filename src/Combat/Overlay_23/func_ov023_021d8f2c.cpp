#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

extern "C" void func_ov023_021d921c(void* arg0, int arg1, int arg2, int arg3);

extern "C" void func_ov023_021d9290(void* arg0, void* arg1, unsigned char arg2);

struct Struct_0205d5d0;
// USA: func_ov023_021d8f2c
extern "C" ARM int func_ov023_021d8f2c(char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021d8f2c_2400=0x800};
#else
 enum {Enum_ov023_021d8f2c_2400=0x960};
#endif
    int var0 = GameState::GetInstance()->GetTickCount();
    if (var0 == 0) var0 = 1;
    unsigned char var1 = *(unsigned char*)(arg0 + 0x11c);

    if (step == 0) {
        Window_ClosePane((struct Entry_0205d6a0*)(obj + 0x20), 1);
        int next = *(unsigned char*)(obj + 0x11c) + 1;
        *(unsigned char*)(obj + 0x11c) = (unsigned char)next;
        return next;
    }
    if (var1 == 1) {
        *(unsigned char*)(arg0 + 0x118) = 1;
        *(unsigned char*)(arg0 + 0x11d) = 5;
        *(unsigned char*)(arg0 + 0x119) = 0;
        unsigned char* var3 = (unsigned char*)(arg0 + 0x119);
        int var4;
        for (var4 = 0; var4 < 4; var4++) {
            if (*(int*)(arg0 + var4 * 4 + 0xdc) != 0) {
                *var3 = *var3 + 1;
            }
        }
        int var5 = 0xc;
        switch (*(unsigned char*)(arg0 + 0x119)) {
            case 1:
                var5 = 5;
                break;
            case 2:
                var5 = 7;
                break;
            case 3:
                var5 = 0xa;
                break;
            case 4:
                var5 = 0xc;
                break;
            case 0:
                *(unsigned char*)(arg0 + 0x118) = 4;
                var5 = 5;
                break;
        }
        memset(*(void**)(arg0 + 4), 0, Enum_ov023_021d8f2c_2400);
        func_ov023_021d9290(arg0, *(void**)(arg0 + 4), *(unsigned char*)(arg0 + 0x118));
        func_ov023_021d921c(arg0, *(int*)(arg0 + 4), 0x18, var5);
        int var6 = *(unsigned char*)(arg0 + 0x11c) + 1;
        *(unsigned char*)(arg0 + 0x11c) = (unsigned char)var6;
        return var6;
    }
    if (var1 != 2) return var0;

    signed char var7 = *(signed char*)(arg0 + 0x11d);
    if (var7 > 0) {
        int var8 = var7 - (signed char)var0;
        *(unsigned char*)(arg0 + 0x11d) = (unsigned char)var8;
        return var8;
    }

    *(unsigned char*)(arg0 + 0x11d) = 5;
    *(unsigned char*)(arg0 + 0x118) = *(unsigned char*)(arg0 + 0x118) + 1;
    memset(*(void**)(arg0 + 4), 0, Enum_ov023_021d8f2c_2400);
    func_ov023_021d9290(arg0, *(void**)(arg0 + 4), *(unsigned char*)(arg0 + 0x118));
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)(obj + 0x20), 0, *(int*)(obj + 4), 1, 0);
#endif

    if (*(unsigned char*)(arg0 + 0x118) == 4) {
        int var9 = *(unsigned char*)(arg0 + 0x11c) + 1;
        *(unsigned char*)(arg0 + 0x11c) = (unsigned char)var9;
        return var9;
    }
    return *(unsigned char*)(arg0 + 0x118);
}
