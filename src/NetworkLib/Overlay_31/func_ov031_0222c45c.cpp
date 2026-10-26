#include <globaldefs.h>
#include <NitroSDK/Memory.h>

struct Struct_020b1d70;
extern "C" ARM int func_ov031_0223dd34(unsigned char* s, int len);
extern "C" void func_ov031_0223c8d4(Struct_020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx);

struct Struct_ov031_0222c45c {
    unsigned char name[0x20];
    unsigned char unknown_20_[0xa];
};
struct Struct_ov031_0222c45c_2 {
    Struct_ov031_0222c45c* entries;
    void* unknown_4_;
    void* unknown_8_;
    Struct_020b1d70* unknown_c_;
    unsigned char unknown_10_[0x41];
    unsigned char count;
};
struct Struct_ov031_02290c8c_11 {
    unsigned char field_0;
    unsigned char unknown_1_[3];
    Struct_ov031_0222c45c_2* manager;
};
extern Struct_ov031_02290c8c_11 data_ov031_02290c8c;

// USA: func_ov031_0222c45c
extern "C" ARM void func_ov031_0222c45c(int idx, int row) {
    unsigned short buf[0x11];
    int len = func_ov031_0223dd34(data_ov031_02290c8c.manager->entries[idx].name, 0x20);
    int y = row * 0x1c;
    if (idx >= data_ov031_02290c8c.manager->count) return;
    if (len <= 0x10) y += 6;
    VectorizedMemset(buf, 0, sizeof(buf));
    int n = len <= 0x10 ? len : 0x10;
    int i;
    for (i = 0; i < n; i++) {
        buf[i] = data_ov031_02290c8c.manager->entries[idx].name[i];
    }
    func_ov031_0223c8d4(data_ov031_02290c8c.manager->unknown_c_, 10, y, 2, 10, buf, 1);
    if (len <= 0x10) return;
    VectorizedMemset(buf, 0, sizeof(buf));
    len -= 0x10;
    for (i = 0; i < len; i++) {
        buf[i] = data_ov031_02290c8c.manager->entries[idx].name[i + 0x10];
    }
    func_ov031_0223c8d4(data_ov031_02290c8c.manager->unknown_c_, 10, y + 0xc, 2, 10, buf, 1);
}
