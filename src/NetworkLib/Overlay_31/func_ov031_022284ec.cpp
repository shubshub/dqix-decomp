#include <globaldefs.h>

extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
extern unsigned char data_ov031_02290c50;
extern short data_ov031_02248d9e;
extern short data_ov031_02248da0;
extern short data_ov031_02248da2;
extern short data_ov031_02248da4;

// USA: func_ov031_022284ec
extern "C" ARM void func_ov031_022284ec(int type) {
    if (type == 1 || type == 3) {
        return;
    }
    data_ov031_02290c50 ^= 1;
    func_ov031_02236878(8);
    int idx = data_ov031_02290c50 * 8;
    unsigned short a = *(unsigned short*)((char*)&data_ov031_02248d9e + idx);
    unsigned short b = *(unsigned short*)((char*)&data_ov031_02248da2 + idx);
    unsigned short c = *(unsigned short*)((char*)&data_ov031_02248da0 + idx);
    unsigned short d = *(unsigned short*)((char*)&data_ov031_02248da4 + idx);
    func_ov031_022237dc(a, b, c, d);
}
