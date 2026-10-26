#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov023_021f7784_2 {
    int x;
    int y;
    int z;
};

class Struct_ov023_021f7784 {
public:
    virtual void v00(); virtual void inline_ov023_021f7784_15(); virtual void inline_ov023_021f7784_16(); virtual void inline_ov023_021f7784_17();
    virtual void v04(); virtual void inline_ov023_021f7784_19(); virtual void inline_ov023_021f7784_20();
    virtual void inline_ov023_021f7784_21(Struct_ov023_021f7784_2* v);
    virtual Struct_ov023_021f7784_2 inline_ov023_021f7784_22();
    virtual void inline_ov023_021f7784_23(); virtual void v10(); virtual void inline_ov023_021f7784_25(); virtual void inline_ov023_021f7784_26();
    virtual void inline_ov023_021f7784_27(); virtual void v14(); virtual void inline_ov023_021f7784_29(); virtual void inline_ov023_021f7784_30();
    virtual void inline_ov023_021f7784_31(); virtual void v18(); virtual void inline_ov023_021f7784_33(); virtual void v20();
    virtual void inline_ov023_021f7784_35(); virtual void inline_ov023_021f7784_36(); virtual void inline_ov023_021f7784_37(); virtual void v24();
    virtual void inline_ov023_021f7784_39(); virtual void inline_ov023_021f7784_40(); virtual void inline_ov023_021f7784_41(); virtual void v28();
    virtual void inline_ov023_021f7784_43(); virtual void v30(); virtual void inline_ov023_021f7784_45(); virtual void inline_ov023_021f7784_46();
    virtual void inline_ov023_021f7784_47(); virtual void v34(); virtual void inline_ov023_021f7784_49(); virtual void inline_ov023_021f7784_50();
    virtual void inline_ov023_021f7784(); virtual void v38(); virtual void inline_ov023_021f7784_3(); virtual void v40();
    virtual void inline_ov023_021f7784_5(); virtual void inline_ov023_021f7784_6(); virtual void inline_ov023_021f7784_7(); virtual void v44();
    virtual void inline_ov023_021f7784_9(); virtual void inline_ov023_021f7784_10(); virtual void inline_ov023_021f7784_11(); virtual void v48();
    virtual void inline_ov023_021f7784_13(unsigned char a, unsigned char b, unsigned char c);

    char pad4[0xc - 0x4];
    unsigned char unknown_c_;
    char pad0d[0x1c - 0xd];
    int field1c;
#if defined(jpn)
    char pad20[0x44 - 0x20];
#else
    char pad20[0x48 - 0x20];
#endif
    void* field48;
    unsigned char unknown_4c_;
    unsigned char unknown_4d_;
    unsigned char unknown_4e_;
};


// USA: func_ov023_021f7784
extern "C" ARM int func_ov023_021f7784(Struct_ov023_021f7784* obj) {
    if (obj->unknown_c_ & 0x80) {
        int count = GameState::GetInstance()->GetTickCount();
        int t = (unsigned short)count;
        Struct_ov023_021f7784_2 v = obj->inline_ov023_021f7784_22();
        int newX = v.x - (t << 11);
        v.y += t << 11;
        v.x = newX;
        if (v.x < -0x100000) v.x += 0x100000;
        if (v.y > 0x100000) v.y -= 0x100000;
        obj->inline_ov023_021f7784_21(&v);
    }

    if (obj->unknown_c_ & 0x1) {
        return obj->field1c;
    }

    if (obj->field48 != 0) {
        obj->inline_ov023_021f7784_13(obj->unknown_4c_, obj->unknown_4d_, obj->unknown_4e_);
    }

    return obj->field1c;
}
