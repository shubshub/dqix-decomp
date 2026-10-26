#include <globaldefs.h>

extern "C" void func_ov031_022280a0(void);
extern "C" void func_ov031_02223998(int idx);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void *func_ov031_022373b4(int);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void func_ov031_022274c0(int v);
extern unsigned char data_ov031_02290c50;
extern short data_ov031_02248d9e;
extern short data_ov031_02248da0;
extern short data_ov031_02248da2;
extern short data_ov031_02248da4;
extern "C" void func_ov031_0222818c(void);

// USA: func_ov031_02228024
extern "C" ARM void func_ov031_02228024(void) {
    func_ov031_022280a0();
    func_ov031_02223998(0);
    func_ov031_0222336c(0x2e, -1, 0);
    func_ov031_022373b4(4);

    int idx = data_ov031_02290c50 * 8;
    unsigned short a = *(unsigned short*)((char*)&data_ov031_02248d9e + idx);
    unsigned short b = *(unsigned short*)((char*)&data_ov031_02248da2 + idx);
    unsigned short c = *(unsigned short*)((char*)&data_ov031_02248da0 + idx);
    unsigned short d = *(unsigned short*)((char*)&data_ov031_02248da4 + idx);
    func_ov031_022237dc(a, b, c, d);

    func_ov031_022274c0((int)func_ov031_0222818c);
}
