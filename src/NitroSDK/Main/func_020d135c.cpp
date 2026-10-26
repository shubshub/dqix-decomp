#include <globaldefs.h>

struct Struct_020d135c {
    unsigned long unknown_0_;
    unsigned char unknown_4_[0x9c];
    char title[12];
    unsigned long unknown_ac_;
    unsigned short unknown_b0_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_[3];
    unsigned char reserved[4];
    unsigned char unknown_bc_;
    unsigned char unknown_bd_;
    unsigned short unknown_be_;
};

struct Struct_020d135c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[3];
    unsigned char unknown_5_0_ : 1;
    unsigned char unknown_5_1_ : 1;
    unsigned short unknown_6_;
    unsigned long unknown_8_;
};

struct Struct_02112148 {
    int unknown_0_;
    volatile unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_020d135c_3 {
    int locked;
    int unknown_4_;
};

extern Struct_02112148 data_02112148;

extern "C" void func_020d14e4(unsigned short arg0, Struct_020d135c_3* lock);
extern "C" void func_020d1468(int* arg0);
extern "C" void func_020d14b0(int* arg0);
extern "C" unsigned int func_020d1540(int arg0, Struct_020d135c_3* lock);

// USA: func_020d135c
extern "C" ARM int func_020d135c() {
    int result = true;
    Struct_020d135c_3 lock;
    Struct_020d135c* header = (Struct_020d135c*)0x08000000;
    Struct_020d135c_2* info = (Struct_020d135c_2*)0x027ffc30;

    if (info->unknown_0_ == 0xffff) {
        return false;
    }
    if (info->unknown_5_1_ == true) {
        return false;
    }

    func_020d14e4(data_02112148.unknown_6_, &lock);
    {
        int var4[2];
        unsigned char var5;

        func_020d1468(var4);
        var5 = header->unknown_b2_;
        if (var5 == 0x96 && info->unknown_0_ != header->unknown_be_ ||
            var5 != 0x96 && info->unknown_0_ != *(unsigned short*)0x0801fffe ||
            info->unknown_8_ != header->unknown_ac_ && info->unknown_5_0_) {
            info->unknown_5_1_ = true;
            result = false;
        }
        func_020d14b0(var4);
    }
    func_020d1540(data_02112148.unknown_6_, &lock);
    return result;
}
