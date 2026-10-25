#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#define data_ov002_0216c99d data_ov002_0216cff9
#define data_ov002_0216c99e data_ov002_0216cffa
#else
#define RG(u, j) (u)
#endif

struct Struct_0205d0e0_2;
struct Struct_0205d6a0;
struct Struct_0205d81c;
struct Struct_ov002_02156e90 {
    char unknown_0_[0xc4];
    unsigned char unknown_c4_;
};
struct Elem0205d888 *Window_GetTopPane(struct Struct0205d888 *s);
void *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void Window_ClosePane(struct Entry_0205d6a0 *e, int a);
void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
extern "C" const unsigned char data_ov002_0216c99d[];
extern "C" const unsigned char data_ov002_0216c99e[];

// USA: func_ov002_02156e90
extern "C" ARM void func_ov002_02156e90(char *base) {
    int count              = 1;
    struct Elem0205d888 *e = Window_GetTopPane((struct Struct0205d888 *) (base + RG(0xec8, 0xe20)));
    if (e != NULL) {
        for (int i = 0; i < 8; i++) {
            unsigned char k = e->key;
            unsigned char t = data_ov002_0216c99d[i * 2];
            if (t == k) {
                count = 2;
                break;
            }
            if (var3 >= RG(0x2c, 0x2f) && var3 <= RG(0x2f, 0x32)) {
                var0 = 0;
                for (unsigned char var5 = RG(0x2c, 0x2f); var5 <= RG(0x2f, 0x32); var5++) {
                    if (func_0205d81c((struct Struct_0205d81c *) (arg0 + RG(0xec8, 0xe20)), var5) != NULL) {
                        var0++;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        Window_ClosePane((struct Entry_0205d6a0 *) (base + RG(0xec8, 0xe20)), 0);
    }
    e = Window_GetTopPane((struct Struct0205d888 *) (base + RG(0xec8, 0xe20)));
    if (e == NULL) return;
    *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = e->key;
    func_ov002_02161cf0(base);
    for (int i = 0; i < 8; i++) {
        unsigned char t = data_ov002_0216c99d[i * 2];
        if (t == e->key) {
            unsigned char k = data_ov002_0216c99e[i * 2];
            FindElementByC40205d81c((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), k);
            Window_SetPanePalette((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), k, 0);
            break;
        }
    }
    func_ov002_0215b9a4(arg0, *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80)) & 0xff, 0);
}
