#include <globaldefs.h>

struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char a,
                                                                        unsigned char b);
#if defined(jpn)
enum { WindowOffset = 0xe20, Enum_ov002_0215f170_7096 = 0x1a80, TextOffset = 0x1a98, Enum_ov002_0215f170_2400 = 0x800 };
#define FINAL_ARG_0215f170
#else
enum { WindowOffset = 0x2c8 + 0xc00, Enum_ov002_0215f170_7096 = 0x1bb8, TextOffset = 0x1bd0, Enum_ov002_0215f170_2400 = 0x960 };
#define FINAL_ARG_0215f170 , 0
#endif
extern "C" void func_ov002_0215f224(char *arg0, char *arg1, int arg2);
extern "C" void func_ov002_0215be00(char *self, int a, int b, int c);
extern "C" void *memset(void *dst, int c, unsigned int n);
#if defined(jpn)
extern "C" int Window_OpenPane(char *obj, char *list, int a, int b, int c, int d, int e);
#else
extern "C" int Window_OpenPane(char *obj, char *list, int a, int b, int c, int d, int e, int f);
#endif

struct Struct_ov002_0215f170 {
    char pad[0x58];
    int n;
};

// USA: func_ov002_0215f170
extern "C" ARM int func_ov002_0215f170(char *self) {
    struct Struct_ov002_0215f170 *p = (struct Struct_ov002_0215f170 *) (self + WindowOffset) + 1;
    p--;
    int many = 0;
    if (p->n > 1) {
        many = 1;
    }
    func_0205de24((struct Struct0205de24 *) (self + WindowOffset), 0, 3);
    func_ov002_0215be00(self, *(int *) (self + Enum_ov002_0215f170_7096) & 0xff, 0x11, 1);
    memset(*(char **) (self + TextOffset), 0, Enum_ov002_0215f170_2400);
    func_ov002_0215f224(self, *(char **) (self + TextOffset), 0);
    return Window_OpenPane(self + WindowOffset, *(char **) (self + TextOffset), 0, 0, many, 1, 0 FINAL_ARG_0215f170);
}
