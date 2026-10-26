#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_022135f4_3 {
    unsigned char unknown_0_;
    unsigned char status;
    unsigned short unknown_2_;
};

struct Struct_ov031_022135f4 {
    char text[6];
    unsigned short length;
    char remaining[0xb8];
};

struct Struct_ov031_022135f4_2 {
    char unknown_0_[0x444];
    Struct_ov031_022135f4_3 unknown_444_[12];
    Struct_ov031_022135f4 records[11];
    char unknown_cb4_[0x59];
    unsigned char status;
    char unknown_d0e_[4];
    unsigned char count;
    unsigned char selected;
};

struct Struct_ov031_0224e5c4_10 {
    char unknown_0_[0x10];
    Struct_ov031_022135f4_2* state;
};

extern Struct_ov031_0224e5c4_10 data_ov031_0224e5c4;

// USA: func_ov031_022135f4
extern "C" ARM int func_ov031_022135f4() {
    unsigned char index;
    unsigned char selected;
    Struct_ov031_022135f4_2* state = data_ov031_0224e5c4.state;
    selected = state->selected;
    Struct_ov031_022135f4* records = state->records;
    Struct_ov031_022135f4* var4 = &records[(short)selected];
    if (state->status >= 6) return 1;
    unsigned char count = state->count;
    index = 0;
    if ((unsigned int)index < (unsigned int)count) do {
        if (index != selected && state->unknown_444_[index].status < 6) {
            if (strncmp(var4->text, state->records[index].text,
                    state->records[index].length) == 0) return 2;
        }
        index++;
    } while (index < count);
    return 1;
}
