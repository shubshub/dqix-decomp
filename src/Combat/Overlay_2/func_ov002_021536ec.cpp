#include <globaldefs.h>

#if defined(jpn)
#define data_ov002_0216ccc4 data_ov002_0216d2e4
#endif

class Struct_ov002_021536ec {
public:
    char *unknown_0_;
};
typedef int (Struct_ov002_021536ec::*Type_ov002_021536ec)(void *arg, void *item, int mode);

struct Struct_ov002_0216ccc0 {
    short unknown_0_;
    Type_ov002_021536ec unknown_4_;
};
struct Struct_ov002_021536ec_2 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};
struct Struct_ov002_0216ccc4 {
    int unknown_0_;
    int unknown_4_[2];
};

extern "C" void *func_02079e2c(char *arg0, int arg1);

extern "C" unsigned int data_ov002_0216d3a0[2];
extern "C" MemFn021536ec __ptmf_null;
extern "C" struct Entry021536ec data_ov002_0216cce4[12];
extern "C" struct Slot021536ec data_ov002_0216cce8[12];
extern "C" struct Entry021536ec data_ov002_0216ccc0[3];
extern "C" struct Slot021536ec data_ov002_0216ccc4[3];

// USA: func_ov002_021536ec
extern "C" ARM int func_ov002_021536ec(Struct_ov002_021536ec *arg0, short *arg1) {
    if (arg0->unknown_0_ == NULL) return 0;
    if (arg1 == NULL) return 0;
    struct Struct_ov002_021536ec_2 *var0 = (struct Struct_ov002_021536ec_2 *) func_02079e2c(arg0->unknown_0_, *arg1);
    if (var0 == NULL) return 0;
    struct Struct_ov002_0216ccc0 *var1;

    int var2 = 0;
    if (!(data_ov002_0216d3a0[1] & 1)) {
        MemFn021536ec t            = __ptmf_null;
        data_ov002_0216cce4[0].fn  = t;
        data_ov002_0216cce4[11].fn = t;
        data_ov002_0216d3a0[1] |= 1;
    }
    unsigned int var4 = var0->unknown_18_5_;
    for (int var5 = 0; data_ov002_0216cce4[var5].unknown_0_ >= 0; var5++) {
        if (var4 == data_ov002_0216cce4[var5].unknown_0_) {
            if (data_ov002_0216cce8[var5].unknown_0_ != 0) {
                var2 = (arg0->*data_ov002_0216cce4[var5].unknown_4_)(arg1, var0, 0);
            }
            break;
        }
    }

    int var6 = 0;
    if (!(data_ov002_0216d3a0[0] & 1)) {
        MemFn021536ec t           = __ptmf_null;
        data_ov002_0216ccc0[0].fn = t;
        data_ov002_0216ccc0[2].fn = t;
        data_ov002_0216d3a0[0] |= 1;
    }
    unsigned int var8 = var0->unknown_18_0_;
    int var9;
    for (var9 = 0, var1 = (data_ov002_0216cce4 - 3); var1[var9].unknown_0_ >= 0; var9++) {
        if (var8 == var1[var9].unknown_0_) {
            if (data_ov002_0216ccc4[var9].unknown_0_ != 0) {
                var6 = (arg0->*var1[var9].unknown_4_)(arg1, var0, 1);
            }
            break;
        }
    }
    return (var2 || var6) ? 1 : 0;
}
