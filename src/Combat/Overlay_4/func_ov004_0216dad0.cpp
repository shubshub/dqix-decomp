#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" int func_020ab9c0(int flag);

extern "C" int func_020ab5d4(void* buf, int a, int b, void* out);

struct Struct_ov004_02171034_6 {
    unsigned char mode;
    unsigned char f1;
    unsigned char f2;
    unsigned char status;
    unsigned char f4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned short id;
    unsigned char unknown_a_[2];
    void* fc;
    void* buf;
};
extern Struct_ov004_02171034_6 data_ov004_02171034;

// USA: func_ov004_0216dad0
extern "C" ARM int func_ov004_0216dad0(void) {
    GameState* gs = GameState::GetInstance();
    func_02012028(gs, 1);
    data_ov004_02171034.status = 0;
    data_ov004_02171034.mode = 0;
    int s0 = func_020ab9c0(0);
    int s1 = func_020ab9c0(1);
    if (s0 == 1 || s1 == 1) {
        data_ov004_02171034.status = 6;
        return 0;
    }
    if (s1 == 4) {
        data_ov004_02171034.status = 0;
        if (s0 == 3) {
            data_ov004_02171034.mode = 1;
        }
        return 0;
    }
    if (s1 == 2) {
        data_ov004_02171034.status = 7;
        return 0;
    }
    if (s0 == 2) {
        data_ov004_02171034.status = 4;
        return 0;
    }
    if (s0 == 0) {
        data_ov004_02171034.status = 1;
    } else if (s0 == 3) {
        data_ov004_02171034.status = 2;
    }
    if (data_ov004_02171034.status == 1) {
        unsigned char info[3];
        if (func_020ab5d4(data_ov004_02171034.buf, 0, 0, info) == 0) {
            unsigned char v = gs->unknown_5cc8_;
            if (v == 0) {
                data_ov004_02171034.status = 6;
            } else if (v == 2) {
                data_ov004_02171034.status = 4;
            }
            return 0;
        }
        data_ov004_02171034.id = *(unsigned short*)info;
        data_ov004_02171034.unknown_7_ = info[2];
        data_ov004_02171034.unknown_6_ = info[3];
    }
    return 0;
}
