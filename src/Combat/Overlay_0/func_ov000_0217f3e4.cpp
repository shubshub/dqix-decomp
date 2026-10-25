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

struct Obj_0205dd08;
extern "C" int func_0205dd08(struct Obj_0205dd08* obj);
struct GridCursor;
void GridCursor_TurnPage(struct GridCursor* s, int delta);
int GridCursor_GetSelectedIndex(struct GridCursor* s);
struct Struct_0205bcdc;
void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);

struct Struct_ov000_0217f3e4_2 {
    char unknown_0_[0x50];
};

struct Struct_0205bacc_2 {
    int unknown_0_;
    Struct_ov000_0217f3e4_2 unknown_4_;
    Struct_ov000_0217f3e4_2 unknown_54_;
};

struct Struct_ov000_0217f3e4_3 {
    char unknown_0_[0x188];
    Struct_0205bacc_2 unknown_188_;
    char unknown_22c_[REGION_OFFSET_0 - 0x22c];
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[REGION_OFFSET_1 - REGION_OFFSET_2];
    unsigned char unknown_1d6e_;
    unsigned char unknown_1d6f_;
};

struct Struct_ov000_0217f3e4 {
    char unknown_0_[0x18c - sizeof(Struct_ov000_0217f3e4_2)];
    Struct_ov000_0217f3e4_2 unknown_13c_[3];
    Struct_ov000_0217f3e4_2* inline_ov000_0217f3e4(int arg0) { return &unknown_13c_[arg0]; }
};

// USA: func_ov000_0217f3e4
extern "C" ARM int func_ov000_0217f3e4(struct Struct_ov000_0217f3e4_3* arg0) {
    int var0 = func_0205dd08((struct Struct_0205dd08*)&arg0->unknown_188_);
    if (var0 == 0) {
        return 0;
    }
    Channel0217f3e4* accumulator = ((MenuChannels0217f3e4*)menu)->GetChannel(2);
    Channel0217f3e4* cursor = ((MenuChannels0217f3e4*)menu)->GetChannel(1);
    GridCursor_TurnPage((struct GridCursor*)accumulator, delta);
    int value = GridCursor_GetSelectedIndex((struct GridCursor*)accumulator);
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)cursor, value);
    switch (menu->kinds[menu->kindIndex]) {
    case 6:
        arg0->unknown_1d6e_ = var3;
        break;
    case 7:
        arg0->unknown_1d6f_ = var3;
        break;
    }
    return 1;
}
