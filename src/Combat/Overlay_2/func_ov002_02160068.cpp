#include "std_library_functions.h"
#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov002_02160068_3784 = 0xe20, Enum_ov002_02160068_3024 = 0xa98, Enum_ov002_02160068_3000 = 0xa80, Enum_ov002_02160068_7174 = 0x1ace, Enum_ov002_02160068_2400 = 0x800, Enum_ov002_02160068_29 = 0x1e, Enum_ov002_02160068_21 = 0x16, Enum_ov002_02160068_4 = 5 };
#define FINAL_ARG_02160068
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
enum { Enum_ov002_02160068_3784 = 0xec8, Enum_ov002_02160068_3024 = 0xbd0, Enum_ov002_02160068_3000 = 0xbb8, Enum_ov002_02160068_7174 = 0x1c06, Enum_ov002_02160068_2400 = 0x960, Enum_ov002_02160068_29 = 0x1d, Enum_ov002_02160068_21 = 0x15, Enum_ov002_02160068_4 = 4 };
#define FINAL_ARG_02160068 , 0
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif
extern "C" void func_ov002_0215be00(void *arg0, int arg1, int arg2, int arg3);
struct Struct_0205de24_2;
extern "C" void func_0205de24(struct Struct_0205de24_2 *arg0, unsigned char arg1,
                                                                        unsigned char arg2);
struct Struct_0205d81c;
void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
int Text_AppendCursorTag(char *dst, int cursor);
void AppendFieldTags021601e0(char *base, char *dst, int);

struct Struct_ov002_02160068 {
    char unknown_0_[Enum_ov002_02160068_3024];
    char *unknown_bd0_;
};
struct Struct_ov002_02160068_2 {
    char unknown_0_[Enum_ov002_02160068_3000];
    int unknown_bb8_;
};

// USA: func_ov002_02160068
extern "C" ARM void func_ov002_02160068(char *base) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + WindowOffset), 0, 3);
    func_ov002_0215be00(base, ElementId, ElementRow, 0xb);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, TextCapacity);
    AppendFieldTags021601e0(base, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + WindowOffset, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0 FINAL_ARG_02160068);

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + WindowOffset), 0, 3);
    func_ov002_0215be00(base, ((struct FieldOv02160068 *) (base + 0x1000))->field & 0xff, SecondRow, 3);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, TextCapacity);
    Text_AppendCursorTag(((struct BufOv02160068 *) (base + 0x1000))->buf, *(short *) (base + CursorOffset));
    Window_OpenPane(base + WindowOffset, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0 FINAL_ARG_02160068);

    Window_SetPanePalette((struct Struct_0205d81c *) (base + WindowOffset), ElementId, 0);
}
