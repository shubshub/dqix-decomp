#include <globaldefs.h>

struct Struct_ov031_022381c8 {
    void* unknown_0_;
    void* unknown_4_;
    void* unknown_8_[2];
    void* canvas;
    void* task;
    unsigned short unknown_18_;
    signed char count;
    signed char input;
    unsigned char type;
    unsigned char wait;
    bool unknown_1e_;
};
struct Struct_ov031_02249334 { unsigned short x, y; };
struct Struct_ov031_022492e2 { unsigned short l; unsigned short t; unsigned short r; unsigned short b; };
extern Struct_ov031_022381c8* data_ov031_02290d10;
extern const Struct_ov031_02249334 data_ov031_02249334[6];
extern unsigned char data_ov031_02249394[];
extern unsigned char data_ov031_022492ea[][2];
extern Struct_ov031_02249334 data_ov031_02249364[][2];
extern const Struct_ov031_02249334 data_ov031_0224934c[6];
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_02238370(void*, int);
extern "C" void func_ov031_0223cb1c(int, int, int, int, Struct_ov031_022492e2*);
extern "C" void func_ov031_0223cc18(int, int, const Struct_ov031_022492e2*);

// USA: func_ov031_022381c8
extern "C" ARM void func_ov031_022381c8(int y) {
    Struct_ov031_022492e2 var0;
    int var1, var2;
    int i;
    func_ov031_0223bbd8(data_ov031_02290d10->unknown_0_, -1,
        data_ov031_02249334[data_ov031_02290d10->type].x, y);
    func_ov031_0223bbd8(data_ov031_02290d10->unknown_4_, -1,
        data_ov031_02249334[data_ov031_02290d10->type].x + 8, y + 8);
    func_ov031_02238370(data_ov031_02290d10->unknown_0_, y);
    func_ov031_02238370(data_ov031_02290d10->unknown_4_, y);
    for (i = 0; i < data_ov031_02249394[data_ov031_02290d10->type]; ++i) {
        func_ov031_0223bbd8(data_ov031_02290d10->unknown_8_[i], -1,
            data_ov031_02249364[data_ov031_02290d10->type][data_ov031_022492ea[data_ov031_02290d10->type][i]].x,
            y + data_ov031_02249364[data_ov031_02290d10->type][data_ov031_022492ea[data_ov031_02290d10->type][i]].y
                - data_ov031_02249334[data_ov031_02290d10->type].y);
        func_ov031_02238370(data_ov031_02290d10->unknown_8_[i], y);
    }
    var1 = y & 0xff;
    if (var1 >= 192) {
        var1 = var2 = 0;
    } else {
        var2 = var1 + data_ov031_0224934c[data_ov031_02290d10->type].y;
    }
    if (var2 > 192) var2 = 192;
    func_ov031_0223cb1c(data_ov031_02249334[data_ov031_02290d10->type].x,
        var1, data_ov031_02249334[data_ov031_02290d10->type].x
            + data_ov031_0224934c[data_ov031_02290d10->type].x, var2, &var0);
    func_ov031_0223cc18(0, 0, &var0);
}
