#include <globaldefs.h>

#if defined(jpn)
#define func_020d2d00 func_020d47cc
#endif

struct Struct_020be604_3 {
    unsigned short unknown_0_[2];
    unsigned char unknown_4_;
    unsigned char attack;
    unsigned char decay;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
};

struct Struct_020d2d00_2 {
    unsigned char type;
    unsigned char padding;
    Struct_020be604_3 param;
};

struct Struct_020d2d00_3 {
    unsigned long unknown_0_;
    unsigned long index;
};

struct Struct_020d2d00_4 {
    unsigned char header[0x38];
    unsigned long unknown_38_;
    unsigned long unknown_3c_[1];
};

struct Struct_020d2d00_5 {
    unsigned short data[sizeof(Struct_020be604_3) / sizeof(unsigned short)];
};

struct Struct_020d2d00_6 {
    unsigned short data[sizeof(Struct_020d2d00_2) / sizeof(unsigned short)];
};

struct Struct_020d2d00_7 {
    unsigned char unknown_0_;
    unsigned char max;
    Struct_020d2d00_2 unknown_2_[1];
};

struct Struct_020d2d00 {
    unsigned char key[8];
    Struct_020d2d00_2 unknown_8_[8];
};

// USA: func_020d2d00
extern "C" ARM int func_020d2d00(const Struct_020d2d00_4* bank, Struct_020d2d00_2* inst,
    Struct_020d2d00_3* pos) {
    if (pos->unknown_0_ < bank->unknown_38_) {
        do {
            unsigned long offset = bank->unknown_3c_[pos->unknown_0_];
            inst->type = offset;
            offset >>= 8;
            switch (inst->type) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                *(Struct_020d2d00_5*)&inst->param =
                    *(const Struct_020d2d00_5*)((const unsigned char*)bank + offset);
                pos->unknown_0_++;
                return true;
            case 16: {
                const Struct_020d2d00_7* const var1 = (const Struct_020d2d00_7*)((const unsigned char*)bank + offset);
                while (pos->index < var1->max - var1->unknown_0_ + 1) {
                    *(Struct_020d2d00_6*)inst =
                        *(const Struct_020d2d00_6*)&var1->unknown_2_[pos->index];
                    pos->index++;
                    return true;
                }
                break;
            }
            case 17: {
                const Struct_020d2d00* const var2 = (const Struct_020d2d00*)((const unsigned char*)bank + offset);
                while (pos->index < 8) {
                    if (var2->key[pos->index] == 0)
                        break;
                    *(Struct_020d2d00_6*)inst =
                        *(const Struct_020d2d00_6*)&var2->unknown_8_[pos->index];
                    pos->index++;
                    return true;
                }
                break;
            }
            }
            pos->unknown_0_++;
            pos->index = 0;
        } while (pos->unknown_0_ < bank->unknown_38_);
    }
    return false;
}
