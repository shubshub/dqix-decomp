#include <globaldefs.h>

struct Struct_ov002_0215624c_11;
extern "C" void func_0205de24(struct Struct_ov002_0215624c_11 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
#if defined(jpn)
enum { Enum_ov002_0215f170_3784 = 0xe20, Enum_ov002_0215f170_7096 = 0x1a80, Enum_ov002_0215f170_7120 = 0x1a98, Enum_ov002_0215f170_2400 = 0x800 };
#define FINAL_ARG_0215f170
#else
enum { Enum_ov002_0215f170_3784 = 0x2c8 + 0xc00, Enum_ov002_0215f170_7096 = 0x1bb8, Enum_ov002_0215f170_7120 = 0x1bd0, Enum_ov002_0215f170_2400 = 0x960 };
#define FINAL_ARG_0215f170 , 0
#endif
extern "C" void func_ov002_0215f224(char *arg0, char *arg1, int arg2);
extern "C" void func_ov002_0215be00(char *arg0, int arg1, int arg2, int arg3);
extern "C" void *memset(void *arg0, int arg1, unsigned int arg2);
#if defined(jpn)
extern "C" int Window_OpenPane(char *obj, char *list, int a, int b, int c, int d, int e);
#else
extern "C" int Window_OpenPane(char *obj, char *list, int a, int b, int c, int d, int e, int f);
#endif

struct Struct_ov002_0215f170 {
    char unknown_0_[0x58];
    int unknown_58_;
};

// USA: func_ov002_0215f170
extern "C" ARM int func_ov002_0215f170(char *arg0) {
    struct Struct_ov002_0215f170 *var0 = (struct Struct_ov002_0215f170 *) (arg0 + Enum_ov002_0215f170_3784) + 1;
    var0--;
    int var1 = 0;
    if (var0->unknown_58_ > 1) {
        var1 = 1;
    }
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (self + WindowOffset), 0, 3);
    func_ov002_0215be00(self, *(int *) (self + FieldOffset) & 0xff, 0x11, 1);
    memset(*(char **) (self + TextOffset), 0, TextCapacity);
    AppendEntryList_0215f224(self, *(char **) (self + TextOffset), 0);
    return Window_OpenPane(self + WindowOffset, *(char **) (self + TextOffset), 0, 0, many, 1, 0 FINAL_ARG_0215f170);
}
