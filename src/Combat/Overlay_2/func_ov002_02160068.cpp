#include "std_library_functions.h"
#include <globaldefs.h>

#if defined(jpn)
enum { WindowOffset = 0xe20, TextOffset = 0xa98, Enum_ov002_02160068_3000 = 0xa80, CursorOffset = 0x1ace, Enum_ov002_02160068_2400 = 0x800, ElementId = 0x1e, Enum_ov002_02160068_21 = 0x16, Enum_ov002_02160068_4 = 5 };
#define FINAL_ARG_02160068
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
enum { WindowOffset = 0xec8, TextOffset = 0xbd0, Enum_ov002_02160068_3000 = 0xbb8, CursorOffset = 0x1c06, Enum_ov002_02160068_2400 = 0x960, ElementId = 0x1d, Enum_ov002_02160068_21 = 0x15, Enum_ov002_02160068_4 = 4 };
#define FINAL_ARG_02160068 , 0
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" void func_ov002_021601e0(char *base, char *dst, int);

struct BufOv02160068 {
    char pad[TextOffset];
    char *buf;
};
struct Struct_ov002_02160068_2 {
    char pad[Enum_ov002_02160068_3000];
    int field;
};

// USA: func_ov002_02160068
extern "C" ARM void func_ov002_02160068(char *base) {
    func_0205de24((struct Struct0205de24 *) (base + WindowOffset), 0, 3);
    func_ov002_0215be00(base, ElementId, Enum_ov002_02160068_21, 0xb);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, Enum_ov002_02160068_2400);
    func_ov002_021601e0(base, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + WindowOffset, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0 FINAL_ARG_02160068);

    func_0205de24((struct Struct0205de24 *) (base + WindowOffset), 0, 3);
    func_ov002_0215be00(base, ((struct Struct_ov002_02160068_2 *) (base + 0x1000))->field & 0xff, Enum_ov002_02160068_4, 3);
    memset(((struct BufOv02160068 *) (base + 0x1000))->buf, 0, Enum_ov002_02160068_2400);
    Text_AppendCursorTag(((struct BufOv02160068 *) (base + 0x1000))->buf, *(short *) (base + CursorOffset));
    Window_OpenPane(base + WindowOffset, ((struct BufOv02160068 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0 FINAL_ARG_02160068);

    Window_SetPanePalette((struct Struct_0205d81c *) (base + WindowOffset), ElementId, 0);
}
