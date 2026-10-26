#include <globaldefs.h>

struct EquipmentMenu;
struct Struct_ov023_021e3134 {
    EquipmentMenu* unknown_0_;
#if defined(jpn)
    char unknown_4_[0x4e2 - 4];
#else
    char unknown1_4_[0x4e6 - 4];
#endif
    signed char state;
};

extern "C" void func_ov005_02155108(void* menu);

// USA: func_ov023_021e3184
extern "C" ARM void func_ov023_021e3184(Struct_ov023_021e3134* arg0) {
    if (arg0->state == 0) return;
    if (arg0->state == -1) return;
    EquipmentMenu* menu = arg0->unknown_0_;
    if (menu == NULL) return;
    func_ov005_02155108(menu);
}
