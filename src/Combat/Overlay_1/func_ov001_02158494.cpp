#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"

struct Struct_ov001_02158494 {
    int field_0x0;
    Vector3fix amplitude;
    char unknown_10_[0xc];
    int duration;
};

struct Struct_ov001_02158494_2 {
    char unknown_0_[0x44];
    int unknown_44_;
    char unknown_48_[0x4];
    Vector3fix eye;
    Vector3fix target;
    char unknown_64_[0xd0];
    int unknown_134_;
    Vector3fix shakeAmplitude;
    Vector3fix unknown_144_;
    Vector3fix unknown_150_;
};

// USA: func_ov001_02158494
extern "C" ARM int func_ov001_02158494(Struct_ov001_02158494* cmd, Struct_ov001_02158494_2* cam) {
    int duration = cmd->duration;
    if (duration <= -1) {
        cam->unknown_134_ = 1;
        memcpy(&cam->unknown_144_, &cam->eye, sizeof(Vector3fix));
        memcpy(&cam->unknown_150_, &cam->target, sizeof(Vector3fix));
        if (cam->unknown_44_ % 4 == 0) {
            Vector3fix_Add(&cam->eye, &cmd->amplitude, &cam->eye);
            Vector3fix_Add(&cam->target, &cmd->amplitude, &cam->target);
        } else if (cam->unknown_44_ % 4 == 2) {
            Vector3fix_Subtract(&cam->eye, &cmd->amplitude, &cam->eye);
            Vector3fix_Subtract(&cam->target, &cmd->amplitude, &cam->target);
        }
        cam->unknown_44_++;
    } else {
        if (cam->unknown_44_ >= duration) {
            cam->unknown_44_ = 0;
            cam->unknown_134_ = 0;
            return 0;
        }
        if (cam->unknown_44_ <= 0) {
            cam->unknown_134_ = 1;
            memcpy(&cam->shakeAmplitude, &cmd->amplitude, sizeof(Vector3fix));
        }
        memcpy(&cam->unknown_144_, &cam->eye, sizeof(Vector3fix));
        memcpy(&cam->unknown_150_, &cam->target, sizeof(Vector3fix));
        if (cam->unknown_44_ % 4 == 0) {
            Vector3fix_Add(&cam->eye, &cam->shakeAmplitude, &cam->eye);
            Vector3fix_Add(&cam->target, &cam->shakeAmplitude, &cam->target);
        } else if (cam->unknown_44_ % 4 == 2) {
            Vector3fix_Subtract(&cam->eye, &cam->shakeAmplitude, &cam->eye);
            Vector3fix_Subtract(&cam->target, &cam->shakeAmplitude, &cam->target);
            Vector3fix decay;
            Vector3fixDivideScalar(&cmd->amplitude, cmd->duration << 12, &decay);
            Vector3fixMultiplyScalar(&decay, cam->unknown_44_ << 12, &decay);
            Vector3fix_Subtract(&decay, &cam->shakeAmplitude, &cmd->amplitude);
        }
        cam->unknown_44_++;
    }
    return 1;
}
