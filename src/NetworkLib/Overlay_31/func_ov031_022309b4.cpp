#include <globaldefs.h>

struct Struct_ov031_022309b4 {
    unsigned char pad0[0x38];
    int task;
    unsigned char unknown_3c_[6];
    unsigned char unknown_42_;
    unsigned char unknown_43_[4];
    unsigned char busy;
};
struct Struct_ov031_02290ca0_21 {
    unsigned char tag;
    unsigned char unknown_1_;
    unsigned char cursor;
    unsigned char unknown_3_;
    unsigned short pos;
    unsigned short pad6;
    Struct_ov031_022309b4* layer;
};
extern Struct_ov031_02290ca0_21 data_ov031_02290ca0;

extern "C" unsigned char* func_ov031_02235c70(void);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222f9ec(void);
extern "C" void func_ov031_022351f8(int);
extern "C" void func_ov031_022307fc(void);
extern "C" void func_ov031_022308d4(void);
extern "C" void func_ov031_0223060c(int);
extern "C" void func_ov031_022306d4(int);

// USA: func_ov031_022309b4
extern "C" ARM void func_ov031_022309b4(int dir) {
    unsigned char* base = func_ov031_02235c70();
    int result = 0;
    unsigned char tag = data_ov031_02290ca0.tag;
    if (tag == 8 && base[0xf5] == 0) {
        if (dir == 0 || dir == 2) return;
    }
    switch (tag) {
    case 0:
        if (dir == 1) data_ov031_02290ca0.tag = 11;
        else if (dir == 3) data_ov031_02290ca0.cursor++;
        else result = 2;
        break;
    case 10:
        if (dir == 1) data_ov031_02290ca0.cursor--;
        else if (dir == 3) data_ov031_02290ca0.tag = data_ov031_02290ca0.layer->unknown_42_;
        else result = 2;
        break;
    case 11:
        if (dir == 1) {
            if (data_ov031_02290ca0.layer->busy) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.layer->busy = 1;
            return;
        } else if (dir == 3) {
            data_ov031_02290ca0.tag = 0;
            data_ov031_02290ca0.cursor = 0;
            data_ov031_02290ca0.pos = 0;
            func_ov031_0222f9ec();
            func_ov031_022351f8(0);
        } else result = 2;
        break;
    case 12:
    case 13:
        data_ov031_02290ca0.layer->unknown_42_ = tag;
        if (dir == 1) {
            data_ov031_02290ca0.tag = 10;
            data_ov031_02290ca0.cursor = 3;
            data_ov031_02290ca0.pos = 0x91;
            func_ov031_0222f9ec();
            func_ov031_022351f8(0x37);
        } else if (dir == 3) {
            if (data_ov031_02290ca0.layer->busy) return;
            func_ov031_02236878(9);
            data_ov031_02290ca0.layer->busy = 1;
            return;
        } else if (tag == 12) {
            data_ov031_02290ca0.tag = 13;
        } else {
            data_ov031_02290ca0.tag = 12;
        }
        break;
    default:
        if (dir == 1) {
            if (data_ov031_02290ca0.cursor != 0) {
                data_ov031_02290ca0.cursor--;
                break;
            }
            func_ov031_02236878(0x13);
            data_ov031_02290ca0.layer->task = (int)func_ov031_0223e218(0, (void*)func_ov031_0223060c, 0, 0x78);
            return;
        } else if (dir == 3) {
            if (data_ov031_02290ca0.cursor < 3) {
                data_ov031_02290ca0.cursor++;
                break;
            }
            func_ov031_02236878(0x13);
            data_ov031_02290ca0.layer->task = (int)func_ov031_0223e218(0, (void*)func_ov031_022306d4, 0, 0x78);
            return;
        }
        result = 2;
        if (tag == 2) data_ov031_02290ca0.tag = 3;
        else if (tag == 3) data_ov031_02290ca0.tag = 2;
        else if (tag == 7) data_ov031_02290ca0.tag = 8;
        else if (tag == 8) data_ov031_02290ca0.tag = 7;
        else break;
        func_ov031_02236878(8);
        func_ov031_022307fc();
        break;
    }
    if (result == 2) return;
    func_ov031_02236878(8);
    if (result != 0) return;
    func_ov031_022308d4();
}
