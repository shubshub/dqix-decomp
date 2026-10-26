#include <globaldefs.h>

struct Struct_ov031_02249308 { unsigned short x, y; };
struct Struct_ov031_02238000 { unsigned short x, y, x2, y2; };
struct Struct_ov031_022242ec { unsigned char padding[0x1b]; signed char selection; unsigned char mode; };
extern Struct_ov031_022242ec* data_ov031_02290d10;
extern unsigned char data_ov031_02249394[];
extern Struct_ov031_02249308 data_ov031_02249364[][2];
extern unsigned char data_ov031_022492ea[][2];
extern Struct_ov031_02249308 data_ov031_02249308[];
extern signed char data_ov031_022492f4[][2];
extern signed char data_ov031_022492f5[][2];
extern "C" void func_ov031_0223cb34(Struct_ov031_02249308*, Struct_ov031_02249308*, Struct_ov031_02238000*);
extern "C" int func_ov031_0223d49c(Struct_ov031_02238000*);
extern "C" int func_ov031_0223d354(int);
extern "C" void func_ov031_022383fc(int);

// USA: func_ov031_02238000
extern "C" ARM void func_ov031_02238000() {
    Struct_ov031_02238000 range;
    int i = 0;
    int count = data_ov031_02249394[data_ov031_02290d10->mode];
    if (count > 0) do {
        unsigned char mode = data_ov031_02290d10->mode;
        func_ov031_0223cb34(&data_ov031_02249364[mode][data_ov031_022492ea[mode][i]], &data_ov031_02249308[mode], &range);
        if (func_ov031_0223d49c(&range)) {
            data_ov031_02290d10->selection = i;
            break;
        }
        ++i;
    } while (i < data_ov031_02249394[data_ov031_02290d10->mode]);
    if (func_ov031_0223d354(1)) data_ov031_02290d10->selection = data_ov031_022492f4[data_ov031_02290d10->mode][0];
    if (func_ov031_0223d354(2)) data_ov031_02290d10->selection = data_ov031_022492f5[data_ov031_02290d10->mode][0];
    Struct_ov031_022242ec* state = data_ov031_02290d10;
    int var5 = 0;
    int count2 = data_ov031_02249394[state->mode];
    if (count2 > 0) {
    int selection = state->selection;
    do {
        if (var5 == selection) {
            return func_ov031_022383fc(var5);
        }
        ++var5;
    } while (var5 < data_ov031_02249394[state->mode]);
    }
    state->selection = -1;
}
