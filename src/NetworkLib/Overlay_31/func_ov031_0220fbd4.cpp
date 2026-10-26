#include <globaldefs.h>

struct Struct_ov031_0220fbd4_3
{
    int length_;
    unsigned int unknown_4_;
    int type_;
    int unknown_c_;
    int unknown_10_;
    char unknown_14_[0x400];
};
struct Struct_ov031_0220fbd4 { int state_; int unknown_4_; int unknown_8_; };
struct Struct_ov031_0220fbd4_2
{
    char unknown_0_[0x24];
    Struct_ov031_0220fbd4* current_;
    int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
};
extern Struct_ov031_0220fbd4_2* data_ov031_0224e580;
extern "C" void func_ov031_0220fd78(int, Struct_ov031_0220fbd4_3*);
extern "C" int func_ov031_0220fe44(int);
extern "C" int func_ov031_0220ff78(int*);
extern "C" int func_ov031_0220ff18(void*);
extern "C" void func_ov031_0220fea0(void);
extern "C" void func_ov031_0220fed8(void);

// USA: func_ov031_0220fbd4
extern "C" ARM void func_ov031_0220fbd4(void)
{
    unsigned char buffer[0x414];
    Struct_ov031_0220fbd4_3* header = (Struct_ov031_0220fbd4_3*)buffer;
    func_ov031_0220fd78(data_ov031_0224e580->current_->unknown_8_, header);
    header->length_ = 20;
    header->unknown_4_ = 0x44535359;
    header->type_ = 0xda;
    header->unknown_c_ = data_ov031_0224e580->current_->unknown_4_;
    if ((header->unknown_10_ = data_ov031_0224e580->unknown_30_) == 0)
        return;
    if (func_ov031_0220fe44((int)func_ov031_0220ff78) != 0)
    {
        if (func_ov031_0220ff18(header) != 0)
            func_ov031_0220fea0();
    }
    func_ov031_0220fed8();
}
