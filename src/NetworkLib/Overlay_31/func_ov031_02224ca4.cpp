#include <globaldefs.h>

struct Struct_020b0a1c {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov031_022489c0 {
    unsigned short x;
    unsigned short y;
};
struct Struct_ov031_022489cc {
    unsigned char n[5];
};
struct Struct_ov031_02224ca4 {
    void* field0[3][4];
    Struct_020b0a1c* unknown_30_[47];
    Struct_020b0a1c* unknown_ec_[4];
    void* unknown_fc_[2];
    void* unknown_104_[4];
};

extern Struct_ov031_02224ca4* data_ov031_02250bfc;
extern const Struct_ov031_022489c0 data_ov031_022489c0 = {0x1c, 2};
extern const Struct_ov031_022489c0 data_ov031_022489c4 = {0x78, 0x12};
extern const Struct_ov031_022489c0 data_ov031_022489c8 = {0x11, 0x12};
extern const Struct_ov031_022489cc data_ov031_022489cc = {{0, 0, 0, 0, 2}};
extern const Struct_ov031_022489cc data_ov031_022489d1 = {{12, 12, 12, 11, 0}};
extern const Struct_ov031_022489cc data_ov031_022489d6 = {{1, 1, 1, 1, 0}};
extern const Struct_ov031_022489c0 data_ov031_02248a0c[47];
extern const Struct_ov031_022489c0 data_ov031_022489e4[4];
extern const Struct_ov031_022489c0 data_ov031_022489dc[2];

extern "C" void func_ov031_0223ca54(void* a, int b, int c, void* d, int e);
extern "C" int FastIntModulus(int arg0, int arg1);
extern "C" void func_ov031_0223bab4(void* obj, int index, int val, int zero);
extern "C" void func_ov031_0223bbd8(void* obj, int idx, int a, int b);

static inline void inline_020b0a1c(Struct_020b0a1c* oam) {
    oam->unknown_0_ &= 0xc1fffcff;
}

static inline void inline_ov031_02224ca4(Struct_020b0a1c* oam, unsigned int arg1, unsigned int arg2) {
    oam->unknown_0_ = (oam->unknown_0_ & 0xfe00ff00) | arg2 | arg1;
}

// USA: func_ov031_02224ca4
extern "C" ARM void func_ov031_02224ca4(int mode, int index, int y) {
    Struct_ov031_022489cc first = data_ov031_022489d1;
    Struct_ov031_022489cc second = data_ov031_022489d6;
    Struct_ov031_022489cc last = data_ov031_022489cc;
    int base = index * 12;
    int m;
    int k;
    int i;
    int j;

    {
        const unsigned char* cnt = &first.n[index];
        k = base;
        i = 0;
        if (i < *cnt) {
            unsigned char var9 = y;
            do {
                inline_020b0a1c(data_ov031_02250bfc->unknown_30_[k]);
                inline_ov031_02224ca4(data_ov031_02250bfc->unknown_30_[k], (unsigned int)data_ov031_02248a0c[k].x << 23 >> 7, var9);
                i++;
                k++;
            } while (i < *cnt);
        }
    }
    if (index < 4) {
        Struct_ov031_02224ca4* obj = data_ov031_02250bfc;
        func_ov031_0223ca54(obj->field0[mode][index], data_ov031_02248a0c[base].x, y, obj->unknown_104_[index], 2);
    }
    m = FastIntModulus(index + 3, 4);
    {
        const unsigned char* cnt = &second.n[index];
        i = 0;
        if (i < *cnt) {
            unsigned char var12 = y;
            do {
                inline_020b0a1c(data_ov031_02250bfc->unknown_ec_[m]);
                inline_ov031_02224ca4(data_ov031_02250bfc->unknown_ec_[m], (unsigned int)data_ov031_022489e4[m].x << 23 >> 7, var12);
                i++;
            } while (i < *cnt);
        }
    }
    {
        const unsigned char* cnt = &last.n[index];
        j = 0;
        if (j < *cnt) {
            do {
                func_ov031_0223bab4(data_ov031_02250bfc->unknown_fc_[j], -1, 0, 0);
                func_ov031_0223bbd8(data_ov031_02250bfc->unknown_fc_[j], -1, data_ov031_022489dc[j].x, y);
                j++;
            } while (j < *cnt);
        }
    }
}
