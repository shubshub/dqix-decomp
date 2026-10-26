#include <globaldefs.h>

struct Struct_ov000_021600f8 {
    char pad0[0x14];
    unsigned char states[3];
    unsigned char count;
};
struct Struct_ov000_0215440c {
    char pad0[6];
    short actorId;
    unsigned char field8;
    unsigned char count;
    char padA[2];
    unsigned char unknown_c_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char unknown_c_3_ : 1;
    unsigned char flag4 : 1;
    unsigned char unknown_c_5_ : 3;
    char padD[0x1a-0xd];
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
};
struct Struct_ov025_021ea604_3 {
    char pad0[0x5cc];
    unsigned char active;
    char unknown_5cd_[3];
    unsigned char blocked;
    unsigned char enabled;
    char unknown_5d2_[0x5e8-0x5d2];
    unsigned char command[1];
};
extern "C" void* func_ov000_02160130();
extern "C" Struct_ov000_0215440c* func_ov000_02160f20(void*);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" short func_ov000_0215ffa0(Struct_ov000_021600f8*);
extern "C" void func_ov025_021ed380(void*, unsigned short, short, int, int, int, int);
extern "C" void func_ov025_021ead5c(Struct_ov025_021ea604_3*, int);
extern unsigned int data_ov025_021ef9a4;

inline int inline_ov025_021dfce0_2(int id) { return id >= 0 && id <= 3; }

// USA: func_ov025_021ea958
extern "C" ARM void func_ov025_021ea958(Struct_ov025_021ea604_3* display, int party, int update, int actorId) {
    if (party && (data_ov025_021ef9a4 & 0x800)) return;
    if (!party && (data_ov025_021ef9a4 & 0x4000)) return;
    Struct_ov000_0215440c* list = func_ov000_02160f20(func_ov000_02160130());
    if (display->blocked && !display->enabled) return;
    if (party && (list->unknown_c_0_ || list->flag1)) actorId = -2;
    else if (!party && (list->unknown_c_3_ || list->flag4)) actorId = -2;
    for (int i = 0; i < list->count; i++) {
        Struct_ov000_021600f8* node = func_ov000_021600f8(list, i);
        if (node) {
            for (int j = 1; j < node->count; j++) {
                if (node->states[j] == 1 || node->states[j] == 2) return;
            }
        }
    }
    int forced = 0;
    if (actorId == -2) forced = 1;
    if (actorId < 0) {
        for (int i = 0; i < list->count; i++) {
            Struct_ov000_021600f8* node = func_ov000_021600f8(list, i);
            if (node) {
                int id = func_ov000_0215ffa0(node);
                if (party) {
                    if (inline_ov025_021dfce0_2(id)) { actorId = id; break; }
                } else if (!inline_ov025_021dfce0_2(id)) { actorId = id; break; }
            }
        }
    }
    int action = inline_ov025_021dfce0_2(actorId) ? list->unknown_1a_ : list->unknown_1c_;
    if ((action == 0xf1 || action == 0xf2) && list->actorId != actorId) return;
    int mode = 0;
    if (forced) mode = 5;
    func_ov025_021ed380(display->command, action, actorId, mode, 0, -1, 0);
    display->active = 1;
    if (update) func_ov025_021ead5c(display, party);
    if (party) data_ov025_021ef9a4 |= 0x800;
    else data_ov025_021ef9a4 |= 0x4000;
}
