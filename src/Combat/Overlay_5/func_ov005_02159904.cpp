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
    int unk_0;
    int active_;
    char unk_8[0x30 - 0x8];
};

struct Struct_02001aac : Struct_ov005_021571d0 {
    char unknown30[0x50 - 0x30];
};

struct Struct_02001aac_2 : Struct_ov005_021571d0 {
    char unknown30[0x40 - 0x30];
};

struct Struct_ov005_02158ed0 {
    int unk_0;
    Struct_02001aac listA_;
    Struct_02001aac_2 listB_;
    char unknown94[0xa0 - 0x94];
    short unknown_a0_;
    short unknown_a2_;
    short tileX;
    short tileY;
    short x_;
    short y_;
    short width_;
    short height_;
    char unk_b0;
    unsigned char visible_;
    char unknown_b2_[0xb5 - 0xb2];
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
};

struct EquipmentMenu {
    char unk_0[0xe10];
    char* textBuffer_;
    char unknown_e14_[LOW_REGION(0xee0, 0xee4) - 0xe14];
    Struct_ov005_02158ed0 window_;
    char unknown_f9c_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4) - sizeof(Struct_ov005_02158ed0)];
    signed char slot_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char unknown_3ddf_;

    Struct_ov005_02158ed0* GetWindow() { return &window_; }
};

extern "C" void func_0205c53c(Struct_0205c53c* s);
extern "C" void GridCursor_SetDimensions(GridCursor* s, int a, int count, int mode);
extern "C" void GridCursor_SetCount(GridCursor* s, int val);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_ov005_02159a30(EquipmentMenu* self, char* buffer, int arg);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov005_02159904
extern "C" ARM void func_ov005_02159904(EquipmentMenu* self) {
    Struct_ov005_02158ed0* window = self->GetWindow();
    func_0205c53c((Struct_0205c53c*)window);
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
    self->window_.unknown_a0_ = 8;
    self->window_.unknown_a2_ = 7;
    self->window_.tileX = 0xc;
    self->window_.tileY = 9;
    self->window_.x_ = 0xc;
    self->window_.y_ = 8;
    self->window_.width_ = 0xa;
    self->window_.height_ = 0xe;
    self->GetWindow()->unknown_b7_ = 0xa;
    self->GetWindow()->visible_ = 1;
    self->GetWindow()->unknown_b5_ = 0;
    self->GetWindow()->unknown_b6_ = 0;
#else
    window = self->GetWindow();
    window->x_ = 0xc;
    window->y_ = 8;
    window->width_ = 0xa;
    window->height_ = 0xe;
    window->unknown_b7_ = 0xa;
    window->visible_ = 1;
    window->unknown_b5_ = 0;
    window->unknown_b6_ = 0;
#endif
    memset(self->textBuffer_, 0, LOW_REGION(0x800, 0x960));
    func_ov005_02159a30(self, self->textBuffer_, 0);
#if defined(jpn)
    Window_OpenPane(self->GetWindow(), self->textBuffer_, 0, 1, 0, 0, 0);
#else
    Window_OpenPane(window, self->textBuffer_, 0, 1, 0, 0, 0, 0);
#endif
}
