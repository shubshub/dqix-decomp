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

struct Struct_ov005_02158e04 {
    char unknown_0_[0xc5];
    unsigned char unknown_c5_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[LOW_REGION(0xee0, 0xee4)];
    char unknown_ee4_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;

    char* inline_ov005_02158e04() { return unknown_ee4_; }
};

struct Struct_0205d81c;
MenuElement* FindElementForFieldB0_0205d8c4(Struct_0205d81c*);
int IsField0x9cEqual3_0204c7cc(unsigned char*);
void SetFieldAt0x30_0205bc24(void* p, int value);
extern "C" unsigned char Window_Update(void* window, int arg);
extern "C" void func_ov005_02158f80(EquipmentMenu* self);
extern "C" void func_ov005_0215916c(EquipmentMenu* self);
extern "C" void func_ov005_02159208(EquipmentMenu* self);
extern "C" void func_ov005_02159274(EquipmentMenu* self);
extern "C" void func_ov005_02159850(EquipmentMenu* self);
extern "C" void func_ov005_02158ed0(EquipmentMenu* self);

// USA: func_ov005_02158e04
extern "C" ARM void func_ov005_02158e04(EquipmentMenu* self, int arg) {
    MenuElement* elem = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)self->window_);
    if (elem != NULL && IsField0x9cEqual3_0204c7cc((unsigned char*)elem) && !(elem->flags_ & 2))
        SetFieldAt0x30_0205bc24(self->GetWindow() + 4, -1);
    self->menuResult_ = Window_Update(self->window_, arg);
    switch (self->menuState_) {
    case 0:
        func_ov005_02158f80(arg0);
        break;
    case 1:
        func_ov005_0215916c(arg0);
        break;
    case 2:
        func_ov005_02159208(arg0);
        break;
    case 3:
        func_ov005_02159274(arg0);
        break;
    case 4:
        func_ov005_02159850(arg0);
        break;
    }
    func_ov005_02158ed0(arg0);
}
