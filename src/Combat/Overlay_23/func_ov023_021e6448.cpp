#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c;
struct Struct_0205c4a8;
struct Struct_0205bb84;
struct Struct_0205bcdc;

struct Struct_ov023_021e6448 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_ov023_021e6448_2 {
    char unknown_0_[0x50];
};

struct Struct_ov023_021e6448_3 {
    char unknown_0_[0x4];
    Struct_ov023_021e6448_2 unknown_4_[2];
};

static inline Struct_ov023_021e6448_2* inline_ov017_021c6d50_4(Struct_ov023_021e6448_3* arg0, int arg1) { return &arg0->unknown_4_[arg1]; }

struct Struct_ov023_021e6448_4 {
#if defined(jpn)
    char unknown_0_[0x90];
#else
    char unknown1_0_[0xac];
#endif

    Struct_ov023_021e6448_3 unknown_ac_;
#if defined(jpn)
    char unknown_134_[0x1341 - 0x90 - sizeof(Struct_ov023_021e6448_3)];
#else
    char unknown_150_[0x1371 - 0xac - sizeof(Struct_ov023_021e6448_3)];
#endif

    unsigned char unknown_1371_;
#if defined(jpn)
    char unknown_1342_[0x1360 - 0x1342];
#else
    char unknown_1372_[0x1398 - 0x1372];
#endif

    int unknown_1398_;
};

int SelectField0x8Or0x58ByFlags_0205c6e4(unsigned char* obj);
Element_021e6448* FindElementByC40205d81c(Struct_0205d81c* s, int key);
void AdvanceWrappedAccumulator0205c4a8(Struct_0205c4a8* s, int delta);
int GridCursor_GetSelectedIndex(Struct_0205bb84* s);
void SetIndexIfValid0205bcdc(Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);

// USA: func_ov023_021e6448
extern "C" ARM int func_ov023_021e6448(Struct_ov023_021e6448_4* arg0) {
    if (func_0205c6e4((unsigned char*)&arg0->unknown_ac_) <= 1)
        return 0;
    if (g_touchInput.pressed_ != 0) {
        int var0, var1;
        g_touchInput.GetTouchPoint(&var0, &var1);
        Struct_ov023_021e6448* var2 = func_0205d81c((Struct_0205d81c*)&arg0->unknown_ac_, arg0->unknown_1371_);
        if (var2 != NULL) {
            short var3 = var2->unknown_ac_;
            short var4 = var2->unknown_ae_;
            short var5 = var2->unknown_aa_;
            var3 += var2->unknown_a8_;
            var4 += var5;
            var4 <<= 3;
            if (var4 - 16 <= var1 && var1 < var4) {
                Struct_ov023_021e6448_2* var6 = inline_ov017_021c6d50_4(&arg0->unknown_ac_, 1);
                short var7 = var2->unknown_ac_ << 3;
                if (var0 >= var7 && var0 < var7 + 16) {
                    func_0205c4a8((Struct_0205c4a8*)var6, -1);
                    arg0->unknown_1398_ = 1;
                }
                var3 <<= 3;
                if (var3 - 16 <= var0 && var0 < var3) {
                    func_0205c4a8((Struct_0205c4a8*)var6, 1);
                    arg0->unknown_1398_ = 1;
                }
                int index = GridCursor_GetSelectedIndex((Struct_0205bb84*)scroll);
                SetIndexIfValid0205bcdc((Struct_0205bcdc*)&self->list_.states[0], index);
                GridCursor_SetSelectedIndex(&self->list_.states[1], index);
            }
            return 1;
        }
    }
    return 0;
}
