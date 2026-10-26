#include <globaldefs.h>

#include <NitroSDK/Matrix.h>

struct Struct_ov001_021570b4_2 {
    int unknown_0_;
    int duration;
    fix32_t unknown_8_[3];
    fix32_t unknown_14_[3];
    fix32_t unknown_20_[3];
    fix32_t constant[3];
};

struct Struct_ov001_021570b4 {
    Struct_ov001_021570b4_2 unknown_0_[16];
    int unknown_380_;
    int unknown_384_;
    fix32_t unknown_388_;
    fix32_t position[3];
    fix32_t unknown_398_;
};

static inline fix32_t inline_ov001_021570b4(fix32_t lhs, fix32_t rhs) {
    return FIX32_MULTIPLY(lhs, rhs);
}

// USA: func_ov001_021570b4
extern "C" ARM int func_ov001_021570b4(void *receiver) {
    Struct_ov001_021570b4 *path = static_cast<Struct_ov001_021570b4 *>(receiver);
    if (path->unknown_380_ <= 1) {
        return 1;
    }
    if (path->unknown_398_ <= 0) {
        return 1;
    }

    Vector3fix previous;
    Vector3fix next;
    do {
        path->unknown_388_ += 0x199;
        if (path->unknown_388_ >=
            (path->unknown_0_[path->unknown_384_].unknown_0_ + path->unknown_0_[path->unknown_384_].duration) << 12)
        {
            ++path->unknown_384_;
            if (path->unknown_384_ >= path->unknown_380_) {
                for (int axis = 0; axis < 3; ++axis) {
                    path->position[axis] = path->unknown_0_[path->unknown_380_ - 1].constant[axis];
                }
                path->unknown_384_ = path->unknown_380_ - 1;
                path->unknown_388_ =
                    (path->unknown_0_[path->unknown_384_].unknown_0_ + path->unknown_0_[path->unknown_384_].duration + 100)
                    << 12;
                return 1;
            }
        }

        fix32_t progress = fix32_Divide(path->unknown_388_ - (path->unknown_0_[path->unknown_384_].unknown_0_ << 12),
                                        path->unknown_0_[path->unknown_384_].duration << 12);
        fix32_t var5  = inline_ov001_021570b4(progress, progress);
        fix32_t var6    = inline_ov001_021570b4(var5, progress);
        previous.x       = path->position[0];
        next.x           = inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_8_[0], var6) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_14_[0], var5) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_20_[0], progress) +
                 path->unknown_0_[path->unknown_384_].constant[0];
        previous.y = path->position[1];
        next.y     = inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_8_[1], var6) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_14_[1], var5) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_20_[1], progress) +
                 path->unknown_0_[path->unknown_384_].constant[1];
        previous.z = path->position[2];
        next.z     = inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_8_[2], var6) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_14_[2], var5) +
                 inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_20_[2], progress) +
                 path->unknown_0_[path->unknown_384_].constant[2];
    } while (Vector3fix_Distance(&previous, &next) < path->unknown_398_);
    path->position[0] = next.x;
    path->position[1] = next.y;
    path->position[2] = next.z;
    return 0;
}

// USA: func_ov001_021573c0
extern "C" ARM int func_ov001_021573c0(void *receiver) {
    int axis;
    fix32_t var1;
    fix32_t var2;
    Struct_ov001_021570b4 *path = static_cast<Struct_ov001_021570b4 *>(receiver);
    if (path->unknown_380_ <= 1) {
        return 1;
    }

    path->unknown_388_ += 0x1000;
    if (path->unknown_388_ >= (path->unknown_0_[path->unknown_384_].unknown_0_ + path->unknown_0_[path->unknown_384_].duration)
                                 << 12)
    {
        ++path->unknown_384_;
        if (path->unknown_384_ >= path->unknown_380_) {
            for (axis = 0; axis < 3; ++axis) {
                path->position[axis] = path->unknown_0_[path->unknown_380_ - 1].constant[axis];
            }
            path->unknown_384_ = path->unknown_380_ - 1;
            path->unknown_388_ =
                (path->unknown_0_[path->unknown_384_].unknown_0_ + path->unknown_0_[path->unknown_384_].duration + 100) << 12;
            return 1;
        }
    }

    fix32_t progress = fix32_Divide(path->unknown_388_ - (path->unknown_0_[path->unknown_384_].unknown_0_ << 12),
                                    path->unknown_0_[path->unknown_384_].duration << 12);
    var1          = inline_ov001_021570b4(progress, progress);
    var2            = inline_ov001_021570b4(var1, progress);
    for (axis = 0; axis < 3; ++axis) {
        path->position[axis] = inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_8_[axis], var2) +
                               inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_14_[axis], var1) +
                               inline_ov001_021570b4(path->unknown_0_[path->unknown_384_].unknown_20_[axis], progress) +
                               path->unknown_0_[path->unknown_384_].constant[axis];
    }
    return 0;
}
