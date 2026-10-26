#include <globaldefs.h>

extern "C" unsigned char func_ov031_0223607c(int);
extern "C" void* func_ov031_0223be70(int, int, int);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
struct Struct_ov031_02222ce4;
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);
struct Struct_ov031_02232678 {
    void* field0;
    void* primary[3];
    void* unknown_10_[3];
};
struct Struct_ov031_02290cc0 {
    unsigned char index;
    char unknown[3];
    Struct_ov031_02232678* items;
};
extern Struct_ov031_02290cc0 data_ov031_02290cc0;
extern const unsigned char data_ov031_02249060[4];
struct Struct_ov031_02249082 { unsigned short x, y; };
extern Struct_ov031_02249082 data_ov031_02249082[6];

// USA: func_ov031_02232678
extern "C" ARM void func_ov031_02232678(void) {
    int key;
    int index = 0;
    do {
        key = func_ov031_0223607c(index);
        if (key == 255) {
            key = 3;
        } else {
            int slot = index + 3;
            data_ov031_02290cc0.items->unknown_10_[index] = func_ov031_0223be70(0, 17, 1);
            func_ov031_0223bbd8(data_ov031_02290cc0.items->unknown_10_[index], -1,
                data_ov031_02249082[slot].x, data_ov031_02249082[slot].y);
            func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02290cc0.items->unknown_10_[index], -1, 3);
        }
        data_ov031_02290cc0.items->primary[index] = func_ov031_0223be70(0, data_ov031_02249060[key], 1);
        func_ov031_0223bbd8(data_ov031_02290cc0.items->primary[index], -1,
            data_ov031_02249082[index].x, data_ov031_02249082[index].y);
        func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02290cc0.items->primary[index], -1, 3);
        ++index;
    } while (index < 3);
}
