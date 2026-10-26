#include <globaldefs.h>

struct Struct_ov031_02248f78 {
    unsigned char indices[14];
};
struct Struct_ov031_02249002 {
    unsigned short first;
    unsigned short second;
    unsigned short third;
    unsigned short unknown_6_;
};
struct Struct_ov031_02290ca0_20 {
    unsigned char selection;
    unsigned char padding1;
    unsigned char row;
    unsigned char unknown_3_;
    unsigned short offset;
    unsigned char unknown_6_[2];
    void* layer;
};
extern const Struct_ov031_02248f78 data_ov031_02248f78;
extern const Struct_ov031_02249002 data_ov031_02249002[];
extern Struct_ov031_02290ca0_20 data_ov031_02290ca0;
extern "C" void func_ov031_02223720(int, int, int, int);

// USA: func_ov031_022307fc
extern "C" ARM void func_ov031_022307fc(void) {
    Struct_ov031_02248f78 var0 = data_ov031_02248f78;
    int index = var0.indices[data_ov031_02290ca0.selection];
    if (index >= 3) {
        func_ov031_02223720(3, data_ov031_02249002[index].first,
            data_ov031_02249002[index].third, data_ov031_02249002[index].second);
        return;
    }
    Struct_ov031_02249002 position = data_ov031_02249002[index];
    position.second += data_ov031_02290ca0.row * 29;
    func_ov031_02223720(1, position.first, position.third, position.second);
}
