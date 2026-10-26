#include <globaldefs.h>
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0x1a98, Enum_ov002_0215b9a4_7116 = 0x1a94, Enum_ov002_0215b9a4_7096 = 0x1a80, Enum_ov002_0215b9a4_2400 = 0x800, Enum_ov002_0215b9a4_44 = 47 };
#define data_ov002_0216cfac data_ov002_0216d618
#define data_ov002_0216d3b0 data_ov002_0216db30
#define data_ov002_0216cae8 data_ov002_0216d0f0
#define data_ov002_0216caec data_ov002_0216d0f4
#else
enum { WindowOffset = 0xec8, TextOffset = 0x1bd0, Enum_ov002_0215b9a4_7116 = 0x1bcc, Enum_ov002_0215b9a4_7096 = 0x1bb8, Enum_ov002_0215b9a4_2400 = 0x960, Enum_ov002_0215b9a4_44 = 44 };
#endif

class Struct_ov002_0215b9a4 {
public:
    unsigned char unknown0[WindowOffset];
    CreationWindow window;
    unsigned char unknown_f84_[Enum_ov002_0215b9a4_7096 - WindowOffset - sizeof(CreationWindow)];
    int mode;
    unsigned char unknown_1bbc_[Enum_ov002_0215b9a4_7116 - Enum_ov002_0215b9a4_7096 - sizeof(int)];
    int dirty;
    void* text;
};

typedef void (Struct_ov002_0215b9a4::*Type_ov002_0215b9a4)(void *buf, int flag);

struct Struct_ov002_0216cae8 {
    int a;
    int b;
};

extern Type_ov002_0215b9a4 data_ov002_0216cfac[Enum_ov002_0215b9a4_44];
extern unsigned int data_ov002_0216d3b0[2];
extern Type_ov002_0215b9a4 __ptmf_null;
extern Struct_ov002_0216cae8 data_ov002_0216cae8[];
extern Struct_ov002_0216cae8 data_ov002_0216caec[];

extern "C" void *memset(void *dst, int value, unsigned int length);
struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xc4];
    unsigned char key;
    unsigned char flags;
    unsigned char unknownC6[0xe0 - 0xc6];
};
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c*, int);

// USA: func_ov002_0215b9a4
// JPN: func_ov002_0215cb1c
extern "C" ARM void func_ov002_0215b9a4(Struct_ov002_0215b9a4 *self, unsigned char key, int flag) {
    Elem_0205d81c* elem = func_0205d81c(((Struct_0205d81c*)(&self->window)), key);
    if (elem == 0) {
        return;
    }
    if (flag) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    int var1 = 0;
    if (elem->flags & 2) {
        var1 = 1;
    }
    memset(self->text, 0, Enum_ov002_0215b9a4_2400);
    if (!(data_ov002_0216d3b0[1] & 1)) {
        Type_ov002_0215b9a4 var2      = __ptmf_null;
        data_ov002_0216cfac[0]  = var2;
#if defined(jpn)
        data_ov002_0216cfac[24] = var2;
        data_ov002_0216cfac[31] = var2;
        data_ov002_0216cfac[34] = var2;
        data_ov002_0216cfac[35] = var2;
        data_ov002_0216cfac[39] = var2;
        data_ov002_0216cfac[43] = var2;
        data_ov002_0216cfac[44] = var2;
        data_ov002_0216cfac[45] = var2;
        data_ov002_0216cfac[46] = var2;
#else
        data_ov002_0216cfac[23] = var2;
        data_ov002_0216cfac[30] = var2;
        data_ov002_0216cfac[36] = var2;
        data_ov002_0216cfac[40] = var2;
        data_ov002_0216cfac[41] = var2;
        data_ov002_0216cfac[42] = var2;
        data_ov002_0216cfac[43] = var2;
#endif
        data_ov002_0216d3b0[1] |= 1;
    }
    if (data_ov002_0216cfac[key] == 0) {
        return;
    }
    (self->*data_ov002_0216cfac[key])(self->text, var1);
    Window_SetPaneText(((StructA0205d5d0*)(&self->window)), key, ((int)(self->text)),
#if defined(jpn)
                             1);
#else
                             0, 0);
#endif
    if (self->dirty == 0) {
        return;
    }
    for (int i = 0; data_ov002_0216cae8[i].a >= 0; i++) {
        if (self->mode == data_ov002_0216cae8[i].a) {
            int page = data_ov002_0216caec[i].a;
            memset(self->text, 0, Enum_ov002_0215b9a4_2400);
            if (data_ov002_0216cfac[page] == 0) {
                break;
            }
            (self->*data_ov002_0216cfac[page])(self->text, var1);
            Window_SetPaneText(((StructA0205d5d0*)(&self->window)), static_cast<unsigned char>(page), ((int)(self->text)),
#if defined(jpn)
                                     1);
#else
                                     0, 0);
#endif
        }
    }
    self->dirty = 0;
}

#if defined(jpn)
#undef data_ov002_0216cfac
#undef data_ov002_0216d3b0
#undef data_ov002_0216cae8
#undef data_ov002_0216caec
#endif
