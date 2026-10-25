#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c;
struct Struct_0205d0e0;

struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
int WindowPane_IsReady(unsigned char* obj);

struct Struct_0205dd08 {
    char unknown_0_[0x98];
    void* unknown_98_;
    void* unknown_9c_;
};

struct Struct_0205dd08_2 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0x15];
    unsigned char unknown_c5_;
};

// USA: func_0205dd08
extern "C" ARM int func_0205dd08(struct Struct_0205dd08* arg0) {
    struct Struct_0205dd08_2* var0;
    int var1, var2;
    short var3, var4, var5, var6, var7;

    if (arg0->unknown_98_ == NULL) return 0;
    if (arg0->unknown_9c_ == NULL) return 0;
    if (g_touchInput.pressed_ == 0) return 0;

    e = (struct Rect_0205dd08*)Window_GetActivePane((struct Struct_0205d81c*)obj);
    if (e == NULL) return 0;
    if (WindowPane_IsReady((unsigned char*)e) == 0) return 0;
    if ((e->fc5 & 8) == 0) return 0;

    g_touchInput.GetTouchPoint(&var1, &var2);

    var3 = var0->unknown_ac_ * 8;
    var5 = var3 + (short)(var0->unknown_a8_ * 8);
    var4 = (short)(var0->unknown_ae_ * 8) + (short)(var0->unknown_aa_ * 8);
    var7 = (short)var1;
    var6 = (short)var2;

    if (var4 - 12 < var6 && var6 < var4) {
        if (var3 < var7 && var7 < var3 + 12) return -1;
        if (var5 - 12 < var7 && var7 < var5) return 1;
    }
    return 0;
}
