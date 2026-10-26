#include <globaldefs.h>
#if defined(jpn)
#define func_ov005_0215916c func_ov005_0215a688
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov005_02158e04 func_ov005_0215a36c
#endif

struct MenuElement {
    char unk_0[0xc5];
    unsigned char flags_;
};

struct EquipmentMenu {
    char unk_0[LOW_REGION(0xee0, 0xee4)];
    char window_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char slot_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char unknown_3ddf_;

    char* GetWindow() { return window_; }
};

struct Struct_0205d81c;
extern "C" MenuElement* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsReady(unsigned char*);
extern "C" void TouchGrid_SetTouchedCell(void* p, int value);
extern "C" unsigned char Window_Update(void* window, int arg);
extern "C" void func_ov005_02158f80(EquipmentMenu* self);
extern "C" void func_ov005_0215916c(EquipmentMenu* self);
extern "C" void func_ov005_02159208(EquipmentMenu* self);
extern "C" void func_ov005_02159274(EquipmentMenu* self);
extern "C" void func_ov005_02159850(EquipmentMenu* self);
extern "C" void func_ov005_02158ed0(EquipmentMenu* self);

// USA: func_ov005_02158e04
extern "C" ARM void func_ov005_02158e04(EquipmentMenu* self, int arg) {
    MenuElement* elem = Window_GetActivePane((Struct_0205d81c*)self->window_);
    if (elem != NULL && WindowPane_IsReady((unsigned char*)elem) && !(elem->flags_ & 2))
        TouchGrid_SetTouchedCell(self->GetWindow() + 4, -1);
    self->menuResult_ = Window_Update(self->window_, arg);
    switch (self->unknown_3ddf_) {
    case 0:
        func_ov005_02158f80(self);
        break;
    case 1:
        func_ov005_0215916c(self);
        break;
    case 2:
        func_ov005_02159208(self);
        break;
    case 3:
        func_ov005_02159274(self);
        break;
    case 4:
        func_ov005_02159850(self);
        break;
    }
    func_ov005_02158ed0(self);
}
