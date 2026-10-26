#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1f98
#define REGION_OFFSET_1 0x1fa6
#define REGION_OFFSET_2 0x1fa1
#else
#define REGION_OFFSET_0 0x1d60
#define REGION_OFFSET_1 0x1d6e
#define REGION_OFFSET_2 0x1d69
#endif

struct Struct_0205dd08;
extern "C" int func_0205dd08(struct Struct_0205dd08* obj);
struct GridCursor;
extern "C" void GridCursor_TurnPage(struct GridCursor* s, int delta);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor* s);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);

struct Struct_ov000_0217f3e4_2 {
    char data[0x50];
};

struct Struct_0205bacc_2 {
    int header;
    Struct_ov000_0217f3e4_2 cursor;
    Struct_ov000_0217f3e4_2 accumulator;
};

struct Struct_ov000_0217f3e4_3 {
    char pad0[0x188];
    Struct_0205bacc_2 list;
    char pad1[REGION_OFFSET_0 - 0x22c];
    signed char kinds[8];
    signed char unknown_1d68_;
    char pad2[REGION_OFFSET_1 - REGION_OFFSET_2];
    unsigned char unknown_1d6e_;
    unsigned char unknown_1d6f_;
};

struct Struct_ov000_0217f3e4 {
    char pad0[0x18c - sizeof(Struct_ov000_0217f3e4_2)];
    Struct_ov000_0217f3e4_2 unknown_13c_[3];
    Struct_ov000_0217f3e4_2* inline_ov000_0217f3e4(int i) { return &unknown_13c_[i]; }
};

// USA: func_ov000_0217f3e4
extern "C" ARM int func_ov000_0217f3e4(struct Struct_ov000_0217f3e4_3* menu) {
    int delta = func_0205dd08((struct Struct_0205dd08*)&menu->list);
    if (delta == 0) {
        return 0;
    }
    Struct_ov000_0217f3e4_2* accumulator = ((Struct_ov000_0217f3e4*)menu)->inline_ov000_0217f3e4(2);
    Struct_ov000_0217f3e4_2* cursor = ((Struct_ov000_0217f3e4*)menu)->inline_ov000_0217f3e4(1);
    GridCursor_TurnPage((struct GridCursor*)accumulator, delta);
    int value = GridCursor_GetSelectedIndex((struct GridCursor*)accumulator);
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)cursor, value);
    switch (menu->kinds[menu->unknown_1d68_]) {
    case 6:
        menu->unknown_1d6e_ = value;
        break;
    case 7:
        menu->unknown_1d6f_ = value;
        break;
    }
    return 1;
}
