#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205bb84;

extern "C" int GridCursor_Update(void* obj, int v);
int Window_GetSelectedIndex(struct Struct_0205c570* s);
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
extern "C" int func_ov000_021753d8(void* obj, int targetIndex);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int value);
extern "C" void func_0205d7a0(unsigned char* obj, int val);

struct Struct_ov000_0217f304 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1d - 0x19];
    signed char unknown_1d_;
};

struct Struct_ov000_0217f304_2 {
    char unknown_0_[0x1c];
    signed char unknown_1c_;
    char unknown_1d_[0x118 - 0x1d];
    int unknown_118_;
    char unknown_11c_[0x188 - 0x11c];
    unsigned char unknown_188_[0x244 - 0x188];
#if defined(jpn)
    unsigned char unknown_244_[0x1f54 - 0x244];
#else
    unsigned char unknown_244_[0x1d1c - 0x244];
#endif
    int unknown_1d1c_[1];
};

// USA: func_ov000_0217f304
extern "C" ARM void func_ov000_0217f304(struct Menu_0217f304* menu, int unused, int count, struct Command_0217f304* cmd) {
    int position;
    if (cmd == NULL) return;
    int type = cmd->types[cmd->typeIndex];
    if (type != 0xe && type != 0x19) return;
    GridCursor_Update(menu->groupCursor, 1);
    position = Window_GetSelectedIndex((struct Struct_0205c570*)menu->cursor);
    int group = GridCursor_GetSelectedIndex((struct Struct_0205bb84*)menu->groupCursor);
    int target = cmd->targetPosition;
    int currentGroup = func_ov000_021753d8(menu, position);
    if (type == 0x19) target = menu->defaultPosition;
    if (position != target) {
        GridCursor_SetSelectedIndex(menu->groupCursor, currentGroup);
        return;
    }
    if (var2 == var4) return;
    int var5 = -1;
    int var6 = -1;
    for (int var7 = 0; var7 < arg2; var7++) {
        int var8 = arg0->unknown_1d1c_[var7];
        if (var5 != var8) {
            var6++;
            var5 = var8;
            if (var2 == var6) {
                func_0205d7a0(arg0->unknown_188_, var7);
                arg0->unknown_118_ = 1;
                return;
            }
        }
    }
}
