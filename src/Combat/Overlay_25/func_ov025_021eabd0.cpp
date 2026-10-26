#include <globaldefs.h>

extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f20(void* work);
struct Struct_ov000_0215440c;
extern "C" void* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" int func_ov025_021ed380(char* obj, unsigned short id, short val2, int type, int val3, short arg5, unsigned short arg6);

extern unsigned int data_ov025_021ef9a4;

struct Struct_ov025_021eabd0 {
    char pad0[9];
    unsigned char count;
    char padA[2];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_c_4_ : 1;
    char padD[0xd];
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
};

static inline int inline_ov000_02156cc4_2(short idx) {
    return (idx >= 0 && idx <= 3) ? 1 : 0;
}

// USA: func_ov025_021eabd0
extern "C" ARM void func_ov025_021eabd0(char* self, int party) {
    Struct_ov025_021eabd0* slot = (Struct_ov025_021eabd0*)func_ov000_02160f20(func_ov000_02160130());
    int found = -1;
    for (int i = 0; i < slot->count; i++) {
        void* node = func_ov000_021600f8((Struct_ov000_0215440c*)slot, i);
        if (node == 0) continue;
        short idx = func_ov000_0215ffa0(node);
        if (party != 0) {
            if (inline_ov000_02156cc4_2(idx) != 0) {
                found = idx;
                break;
            }
        } else {
            if (inline_ov000_02156cc4_2(idx) == 0) {
                found = idx;
                break;
            }
        }
    }
    int type = 0;
    if (party != 0 && (slot->b0 || slot->b1)) {
        type = 5;
    } else if (party == 0 && (slot->b3 || slot->unknown_c_4_)) {
        type = 5;
    }
    int inParty = (found >= 0 && found <= 3) ? 1 : 0;
    int msg = inParty != 0 ? slot->unknown_1a_ : slot->unknown_1c_;
    func_ov025_021ed380(self + 0x5e8, msg, found, type, 0, -1, 0);
    self[0x5cc] = 1;
    if (party != 0) {
        data_ov025_021ef9a4 |= 0x800;
    } else {
        data_ov025_021ef9a4 |= 0x4000;
    }
}
