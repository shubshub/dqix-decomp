#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"

extern char data_ov001_02164d10[];

struct Struct_ov001_02158828 {
    int f0;
    unsigned char arr1[0xc];
    unsigned char arr2[0xc];
    int f1c;
    int f20;
    int f24;
    char unknown_28_[0x20];
    void* unknown_48_;
};

extern "C" ARM void func_ov001_02158828(struct Struct_ov001_02158828* obj);

struct Struct_ov001_021588e4 {
    Struct_ov001_02158828* entries;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int field_0x10;
    int unknown_14_;
    int unknown_18_;
    int field_0x1c;
    int unknown_20_;
    int unknown_24_;
    int field_0x28;
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    int timer;
    int unknown_3c_;
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    Vector3fix eye;
    Vector3fix target;
    int field_0x64;
    int unknown_68_;
    int unknown_6c_;
    int unknown_70_;
    int unknown_74_;
    int unknown_78_;
    Vector3fix unknown_7c_;
    int unknown_88_;
    int unknown_8c_;
    int unknown_90_;
    char name[0x20];
    Vector3fix unknown_b4_;
    Vector3fix unknown_c0_;
    int unknown_cc_;
    int unknown_d0_;
    int unknown_d4_;
    int unknown_d8_;
    Vector3fix unknown_dc_;
    Vector3fix unknown_e8_;
    Vector3fix unknown_f4_;
    Vector3fix unknown_100_;
    int unknown_10c_;
    Vector3fix unknown_110_;
    Vector3fix unknown_11c_;
    Vector3fix unknown_128_;
    int unknown_134_;
    Vector3fix shakeAmplitude;
    Vector3fix unknown_144_;
    Vector3fix unknown_150_;
    char unknown_15c_[0x8c4];
    void* unknown_a20_;
    int unknown_a24_;
};

// USA: func_ov001_021588e4
extern "C" ARM void func_ov001_021588e4(Struct_ov001_021588e4* cam) {
    cam->unknown_34_ = cam->unknown_30_ = 0;
    cam->timer = 0;
    cam->unknown_3c_ = 0;
    cam->unknown_40_ = 0;
    cam->unknown_44_ = 0;
    cam->unknown_48_ = 0;
    memset(&cam->eye, 0, sizeof(Vector3fix));
    memset(&cam->target, 0, sizeof(Vector3fix));
    cam->unknown_6c_ = 0;
    cam->unknown_68_ = 0;
    cam->field_0x64 = 0;
    cam->unknown_70_ = 0;
    cam->unknown_74_ = -1;
    cam->unknown_78_ = 0;
    memset(&cam->unknown_7c_, 0, sizeof(Vector3fix));
    strcpy(cam->name, data_ov001_02164d10);
    cam->unknown_90_ = 0;
    cam->unknown_8c_ = 0;
    cam->unknown_88_ = 0;
    memset(&cam->unknown_b4_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_c0_, 0, sizeof(Vector3fix));
    cam->unknown_d8_ = 0;
    cam->unknown_d4_ = 0;
    cam->unknown_cc_ = 0;
    memset(&cam->unknown_dc_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_e8_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_f4_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_100_, 0, sizeof(Vector3fix));
    cam->unknown_10c_ = 0;
    memset(&cam->unknown_110_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_11c_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_128_, 0, sizeof(Vector3fix));
    cam->unknown_134_ = 0;
    cam->unknown_a24_ = 0;
    memset(&cam->shakeAmplitude, 0, sizeof(Vector3fix));
    memset(&cam->unknown_144_, 0, sizeof(Vector3fix));
    memset(&cam->unknown_150_, 0, sizeof(Vector3fix));
    cam->unknown_8_ = 0;
    cam->unknown_c_ = 0;
    cam->field_0x10 = 0;
    cam->unknown_14_ = 0;
    cam->unknown_18_ = 0;
    cam->field_0x1c = 0;
    cam->unknown_20_ = 0;
    cam->unknown_24_ = 0;
    cam->field_0x28 = 0;
    cam->unknown_2c_ = 0;
    cam->unknown_a20_ = NULL;
    if (cam->entries == NULL || cam->unknown_4_ <= 0) {
        return;
    }
    for (int i = 0; i < cam->unknown_4_; i++) {
        func_ov001_02158828(&cam->entries[i]);
    }
}
