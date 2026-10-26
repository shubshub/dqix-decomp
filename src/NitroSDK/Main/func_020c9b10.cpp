#include <globaldefs.h>

struct Struct_020c9b10
{
    char unknown_0[0x3c];
    unsigned long unknown_3c_;
    char unknown_40_[0x80 - 0x40];
    unsigned char unknown_80_[0x74];
    unsigned char macAddress[6];
    char unknown_fa_[0x1e8 - 0xfa];
    unsigned char unknown_1e8_[8];
    char unknown_1f0_[0x390 - 0x1f0];
    unsigned long unknown_390_;
    unsigned short unknown_394_;
    char unknown_396_[2];
    unsigned short unknown_398_;
    char unknown_39a_[0x3aa - 0x39a];
    unsigned char unknown_3aa_[4];
};

#define SYSTEM_WORK ((const Struct_020c9b10*)0x027ffc00)
#define BUTTONS_XY (*(volatile unsigned short*)0x027fffa8)
#define KEYINPUT (*(volatile unsigned short*)0x04000130)
#define GXSTAT (*(volatile unsigned long*)0x04000600)
#define VCOUNT (*(volatile unsigned short*)0x04000006)

extern volatile unsigned long long data_02111640;

unsigned short GetMain16BitTimerCounter();

static inline long inline_020c94e4()
{
    return VCOUNT;
}

// USA: func_020c9b10
extern "C" ARM void func_020c9b10(unsigned long* buffer)
{
    const Struct_020c9b10* work = SYSTEM_WORK;
    const unsigned char* macAddress = work->macAddress;

    buffer[0] = (unsigned long)((inline_020c94e4() << 16) | GetMain16BitTimerCounter());
    buffer[1] = (unsigned long)(*(unsigned short*)(macAddress + 4) << 16) ^ (unsigned long)data_02111640;
    buffer[2] = (unsigned long)(data_02111640 >> 32) ^ *(unsigned long*)macAddress ^ work->unknown_3c_;
    buffer[2] ^= GXSTAT;
    buffer[3] = *(unsigned long*)&work->unknown_1e8_[0];
    buffer[4] = *(unsigned long*)&work->unknown_1e8_[4];
    buffer[5] = ((unsigned long)work->unknown_394_ << 16) ^ work->unknown_390_;
    buffer[6] = (unsigned long)((*(unsigned short*)&work->unknown_3aa_[0] << 16) | *(unsigned short*)&work->unknown_3aa_[2]);
    buffer[7] = (unsigned long)((work->unknown_398_ << 16) | (KEYINPUT | BUTTONS_XY));
}
