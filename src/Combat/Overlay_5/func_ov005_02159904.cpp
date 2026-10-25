#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205c53c;
struct GridCursor;
struct Struct_0205bcdc;

struct Struct_ov005_021571d0 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x30 - 0x8];
};

struct Struct_02001aac : Struct_ov005_021571d0 {
    char unknown_30_[0x50 - 0x30];
};

struct Struct_02001aac_2 : Struct_ov005_021571d0 {
    char unknown_30_[0x40 - 0x30];
};

struct Struct_ov005_02158ed0 {
    int unknown_0_;
    Struct_02001aac unknown_4_;
    Struct_02001aac_2 unknown_54_;
    char unknown_94_[0xa0 - 0x94];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[0xb5 - 0xb2];
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[0xe10];
    char* unknown_e10_;
    char unknown_e14_[LOW_REGION(0xee0, 0xee4) - 0xe14];
    Struct_ov005_02158ed0 unknown_ee4_;
    char unknown_f9c_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4) - sizeof(Struct_ov005_02158ed0)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;

    Struct_ov005_02158ed0* inline_ov005_02158e04() { return &unknown_ee4_; }
};

void InitChannelPair0205c53c(Struct_0205c53c* s);
void GridCursor_SetDimensions(GridCursor* s, int a, int count, int mode);
void GridCursor_SetCount(GridCursor* s, int val);
void GridCursor_SelectIfValid(Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_ov005_02159a30(EquipmentMenu* self, char* buffer, int arg);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov005_02159904
extern "C" ARM void func_ov005_02159904(Struct_ov005_02153954* arg0) {
    Struct_ov005_02158ed0* var0 = arg0->inline_ov005_02158e04();
    func_0205c53c((Struct_0205c53c*)var0);
#if defined(jpn)
    if (self->slot_ >= 0 && self->slot_ < 8) {
    GridCursor_SetDimensions((GridCursor*)&window->listA_, 1, 3, 0);
    GridCursor_SetDimensions((GridCursor*)&window->listB_, 1, 3, 0);
    GridCursor_SetCount((GridCursor*)&window->listA_, 3);
    GridCursor_SetCount((GridCursor*)&window->listB_, 3);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&window->listA_, choice);
    GridCursor_SetSelectedIndex(&window->listB_, choice);
    } else {
    GridCursor_SetDimensions((GridCursor*)&window->listA_, 1, 4, 0);
    GridCursor_SetDimensions((GridCursor*)&window->listB_, 1, 4, 0);
    GridCursor_SetCount((GridCursor*)&window->listA_, 4);
    GridCursor_SetCount((GridCursor*)&window->listB_, 4);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&window->listA_, choice);
    GridCursor_SetSelectedIndex(&window->listB_, choice);
    }
#else
    int count = 4;
    if (self->slot_ >= 0 && self->slot_ < 8)
        count = 3;
    GridCursor_SetDimensions((GridCursor*)&window->listA_, 1, count, 0);
    GridCursor_SetDimensions((GridCursor*)&window->listB_, 1, count, 0);
    GridCursor_SetCount((GridCursor*)&window->listA_, count);
    GridCursor_SetCount((GridCursor*)&window->listB_, count);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&window->listA_, choice);
    GridCursor_SetSelectedIndex(&window->listB_, choice);
#endif
#if defined(jpn)
    arg0->unknown_ee4_.unknown_a0_ = 8;
    arg0->unknown_ee4_.unknown_a2_ = 7;
    arg0->unknown_ee4_.unknown_a4_ = 0xc;
    arg0->unknown_ee4_.unknown_a6_ = 9;
    arg0->unknown_ee4_.unknown_a8_ = 0xc;
    arg0->unknown_ee4_.unknown_aa_ = 8;
    arg0->unknown_ee4_.unknown_ac_ = 0xa;
    arg0->unknown_ee4_.unknown_ae_ = 0xe;
    arg0->inline_ov005_02158e04()->unknown_b7_ = 0xa;
    arg0->inline_ov005_02158e04()->unknown_b1_ = 1;
    arg0->inline_ov005_02158e04()->unknown_b5_ = 0;
    arg0->inline_ov005_02158e04()->unknown_b6_ = 0;
#else
    var0 = arg0->inline_ov005_02158e04();
    var0->unknown_a8_ = 0xc;
    var0->unknown_aa_ = 8;
    var0->unknown_ac_ = 0xa;
    var0->unknown_ae_ = 0xe;
    var0->unknown_b7_ = 0xa;
    var0->unknown_b1_ = 1;
    var0->unknown_b5_ = 0;
    var0->unknown_b6_ = 0;
#endif
    memset(arg0->unknown_e10_, 0, LOW_REGION(0x800, 0x960));
    func_ov005_02159a30(arg0, arg0->unknown_e10_, 0);
#if defined(jpn)
    Window_OpenPane(self->GetWindow(), self->textBuffer_, 0, 1, 0, 0, 0);
#else
    Window_OpenPane(window, self->textBuffer_, 0, 1, 0, 0, 0, 0);
#endif
}
