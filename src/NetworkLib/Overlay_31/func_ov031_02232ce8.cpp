#include <globaldefs.h>

extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void func_ov031_02223720(int, int, int, int);
extern unsigned char data_ov031_02290cc0;
extern short data_ov031_022490d2;
extern short data_ov031_022490d4;
extern short data_ov031_022490d6;
extern short data_ov031_022490d8;

// USA: func_ov031_02232ce8
extern "C" ARM void func_ov031_02232ce8(void) {
    unsigned char index = data_ov031_02290cc0;
    if (index < 4) {
        int idx = index * 8;
        unsigned short a = *(unsigned short*)((char*)&data_ov031_022490d2 + idx);
        unsigned short b = *(unsigned short*)((char*)&data_ov031_022490d6 + idx);
        unsigned short c = *(unsigned short*)((char*)&data_ov031_022490d4 + idx);
        unsigned short d = *(unsigned short*)((char*)&data_ov031_022490d8 + idx);
        func_ov031_022237dc(a, b, c, d);
    } else {
        int idx = index * 8;
        unsigned short a = *(unsigned short*)((char*)&data_ov031_022490d2 + idx);
        unsigned short b = *(unsigned short*)((char*)&data_ov031_022490d6 + idx);
        unsigned short c = *(unsigned short*)((char*)&data_ov031_022490d4 + idx);
        func_ov031_02223720(0, a, b, c);
    }
}
