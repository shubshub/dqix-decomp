#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
void CleanCacheRange(const void* addr, unsigned int size);
extern "C" int func_020d1fb0(int a, int b);
extern "C" void func_020d2038(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
extern "C" int func_020d1f70(int a, int b, int c, int d, int e);
extern "C" int func_020d1ee4(int a, int b, int c, int d);
extern "C" void func_020d24c4(int);
extern "C" void func_ov016_0218bcc4(void);

struct Struct_ov016_0219d0c0_4 {
    #if defined(jpn)
    unsigned char pad[0x20];
#else
    unsigned char pad[0x24];
#endif
    int f24;
    unsigned char pad2[4];
    void* unknown_2c_;
    void* unknown_30_;
};
extern Struct_ov016_0219d0c0_4 data_ov016_0219d0c0;

// USA: func_ov016_0218bce8
extern "C" ARM void func_ov016_0218bce8(unsigned int id, unsigned int count) {
    unsigned int var0 = _u32_div_f(0x00ffb0ff, id);
    Struct_ov016_0219d0c0_4* g = &data_ov016_0219d0c0;

    unsigned int var2 = (g->f24 * count) << 1;
    unsigned int var3 = (count >> 6) * (var0 << 1);

    CleanCacheRange(g->unknown_30_, var2);
    CleanCacheRange(g->unknown_2c_, (g->f24 * count) << 1);
    func_020d1fb0(3, 0);

    func_020d2038(0, 1, (int)g->unknown_30_, 1,
        0, (g->f24 * count) >> 1, 0x7f, 0, var0, 0);

    func_020d2038(1, 1, (int)g->unknown_2c_, 1,
        0, (g->f24 * count) >> 1, 0x7f, 0, var0, 0x7f);

    func_020d1f70(0, var3, var3, (int)func_ov016_0218bcc4, 0);
    func_020d1ee4(3, 0, 1, 0);
    func_020d24c4(1);
}
