#include <globaldefs.h>

extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_0223ca40(void* obj, int unused);
extern "C" void func_ov031_0223caec(void* ptr);
extern "C" void func_ov031_0222c45c(int, int);
extern "C" void func_ov031_0222c5d4(int, int);
extern "C" void func_ov031_0222c660(void);

struct Struct_ov031_0222c3b4 {
    unsigned char pad[0xc];
    void* unknown_c_;
    unsigned char pad2[0x51 - 0x10];
    unsigned char unknown_51_;
};
struct Struct_ov031_02290c8c_10 {
    unsigned char pad[2];
    unsigned short field2;
    Struct_ov031_0222c3b4* field4;
};
extern Struct_ov031_02290c8c_10 data_ov031_02290c8c;

// USA: func_ov031_0222c3b4
extern "C" ARM void func_ov031_0222c3b4(void) {
    int count = FastIntDivide(data_ov031_02290c8c.field2, 0x1c);
    int n = data_ov031_02290c8c.field4->unknown_51_;
    func_ov031_0223ca40(data_ov031_02290c8c.field4->unknown_c_, 0);
    if (n > 5) n = 5;

    int a = count;
    int i = 0;
    if (n > 0) {
        do {
            func_ov031_0222c45c(a, i);
            i++;
            a++;
        } while (i < n);
    }
    int b = count;
    int j = 0;
    if (n > 0) {
        do {
            func_ov031_0222c5d4(b, j);
            j++;
            b++;
        } while (j < n);
    }

    func_ov031_0223caec(data_ov031_02290c8c.field4->unknown_c_);
    func_ov031_0222c660();
}
