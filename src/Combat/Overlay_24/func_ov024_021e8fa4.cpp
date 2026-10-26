#include <globaldefs.h>

extern "C" int func_ov000_02156068(void* obj, int val, int zero, int one);

struct Struct_ov024_021e2bd0_2 {
    char unk[0x10];
    void* field10;
};

struct Struct_ov024_021fe820 {
    short value;
    short pad;
};

extern struct Struct_ov024_021fe820 data_ov024_021fe820[];
extern struct Struct_ov024_021fe820 data_ov024_021fe822[];

// USA: func_ov024_021e8fa4
extern "C" ARM int func_ov024_021e8fa4(struct Struct_ov024_021e2bd0_2* self, int unused, int id) {
    if (id == 2) {
        int result = func_ov000_02156068(self->field10, unused, 0, 2);
        if (result != 0) {
            return 0;
        }
    }
    int idx = 0;
    while (data_ov024_021fe820[idx].value != -1) {
        if (id == data_ov024_021fe820[idx].value) {
            return data_ov024_021fe822[idx].value;
        }
        idx++;
    }
    return 0;
}
