#include <globaldefs.h>

struct Struct_0205c570;
struct GridCursor;

extern "C" int GridCursor_Update(void* obj, int v);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor* s);
extern "C" int func_ov000_021753d8(void* obj, int targetIndex);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int value);
extern "C" void func_0205d7a0(unsigned char* obj, int val);

struct Struct_ov000_0217f304 {
    char pad0[0x10];
    signed char types[8];
    signed char unknown_18_;
    char unknown_19_[0x1d - 0x19];
    signed char targetPosition;
};

struct Struct_ov000_0217f304_2 {
    char pad0[0x1c];
    signed char defaultPosition;
    char unknown_1d_[0x118 - 0x1d];
    int dirty;
    char unknown_11c_[0x188 - 0x11c];
    unsigned char cursor[0x244 - 0x188];
#if defined(jpn)
    unsigned char groupCursor[0x1f54 - 0x244];
#else
    unsigned char groupCursor[0x1d1c - 0x244];
#endif
    int unknown_1d1c_[1];
};

// USA: func_ov000_0217f304
extern "C" ARM void func_ov000_0217f304(struct Struct_ov000_0217f304_2* menu, int unused, int count, struct Struct_ov000_0217f304* cmd) {
    int position;
    if (cmd == NULL) return;
    int type = cmd->types[cmd->unknown_18_];
    if (type != 0xe && type != 0x19) return;
    GridCursor_Update(menu->groupCursor, 1);
    position = Window_GetSelectedIndex((struct Struct_0205c570*)menu->cursor);
    int group = GridCursor_GetSelectedIndex((struct GridCursor*)menu->groupCursor);
    int target = cmd->targetPosition;
    int currentGroup = func_ov000_021753d8(menu, position);
    if (type == 0x19) target = menu->defaultPosition;
    if (position != target) {
        GridCursor_SetSelectedIndex(menu->groupCursor, currentGroup);
        return;
    }
    if (group == currentGroup) return;
    int prev = -1;
    int var6 = -1;
    for (int i = 0; i < count; i++) {
        int id = menu->unknown_1d1c_[i];
        if (prev != id) {
            var6++;
            prev = id;
            if (group == var6) {
                func_0205d7a0(menu->cursor, i);
                menu->dirty = 1;
                return;
            }
        }
    }
}
