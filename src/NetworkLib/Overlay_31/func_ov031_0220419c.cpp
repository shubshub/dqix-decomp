#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02203fdc(void* buf, int n, int* out);
extern "C" ARM void* func_ov031_02204168(int value, unsigned int end, void* dst, unsigned int start);
extern "C" int func_ov031_02203a84(int param0, int param1);

extern unsigned char data_ov031_0224ced6[];

struct Struct_ov031_0224c980_13 {
    unsigned char pad1[0x34];
    unsigned int field34;
};
extern Struct_ov031_0224c980_13 data_ov031_0224c980;

// USA: func_ov031_0220419c
extern "C" ARM int func_ov031_0220419c(void) {
    int var0;
    unsigned char* buf = data_ov031_0224ced6;
    unsigned char* var2 = func_ov031_02203fdc(buf, 1, &var0);
    if (data_ov031_0224c980.field34 != 0) {
        var2[0] = 0x32;
        var2[1] = 4;
        var2[2] = (unsigned char)((unsigned short)(data_ov031_0224c980.field34 >> 16) >> 8);
        var2[3] = (unsigned char)(data_ov031_0224c980.field34 >> 16);
        var2[4] = (unsigned char)((unsigned short)data_ov031_0224c980.field34 >> 8);
        var2[5] = (unsigned char)data_ov031_0224c980.field34;
        var2 += 6;
    }
    var2[0] = 0xff;
    unsigned char* dst = (unsigned char*)func_ov031_02204168(0, 0x12c, var2 + 1, (unsigned int)((var2 + 1) - buf));
    func_ov031_02203a84((int)buf, (int)(dst - buf));
    return var0;
}
