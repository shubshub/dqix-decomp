#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj02094ab0 {
    unsigned char pad0[0x14];
    int handles[8];
    int field34;
    int field38;
    unsigned char pad1[0x54 - 0x3c];
    unsigned char field54;
    unsigned char unknown_55_;
    unsigned char unknown_56_;
    unsigned char unknown_57_;
    unsigned char pad2[0x61 - 0x58];
    unsigned char unknown_61_;
    unsigned char unknown_62_;
};

// Main, originally func_02094ab0 (USA 0x02094ab0, EUR 0x02094ac0, JPN 0x02095748)
extern "C" ARM void FontBankLoader_CancelLoads(struct Obj02094ab0* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if (obj->handles[i] >= 0) {
            ((BackgroundLoader*)(a))->RemoveTask((int)(obj->handles[i]));
            obj->handles[i] = -1;
        }
    }
    obj->field34 = obj->field38 = -1;
    obj->unknown_56_ = 1;
    obj->field54 = obj->unknown_55_ = obj->unknown_61_ = obj->unknown_62_ = obj->unknown_57_ = 0;
}
