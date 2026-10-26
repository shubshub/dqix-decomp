#include <globaldefs.h>

struct Struct_0202ba08_2;
extern "C" ARM struct Struct_0202ba08_2* func_0202ba08(struct Struct_0202ba08_2* dst, struct Struct_0202ba08_2* src);

struct Struct_0202baf4 { unsigned char v[6]; };
struct Struct_0202ae4c_2 { char v[0x20]; };
struct Struct_0202ae4c_3 { unsigned int v[0x20]; };

struct Struct_020feffc {
    unsigned short h0;
    unsigned short h2;
    struct Struct_0202baf4 unknown_4_;
    unsigned short ha;
    struct Struct_0202ae4c_2 unknown_c_;
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    struct Struct_0202ae4c_3 unknown_40_;
};

struct Struct_020fefec {
    char pad0[0xc];
    int count;
    struct Struct_020feffc records[10];
    int unknown_790_[10];
};

extern struct Struct_020feffc data_020feffc[];

// USA: func_0202baf4
extern "C" ARM void func_0202baf4(struct Struct_020fefec* obj, struct Struct_020feffc* item) {
    signed char var0 = *(signed char*)((char*)item + 0x50);
    if (var0 == 0) {
        return;
    }
    unsigned char var1 = *(unsigned char*)((char*)item + 0x4a);
    if (var1 == 0) {
        return;
    }

    int count = obj->count;
    if (count > 0) {
        int i;
        for (i = 0; i < count; i++) {
            struct Struct_020feffc* cand = (struct Struct_020feffc*)((char*)data_020feffc + i * 0xc0);
            int match = cand->unknown_4_.v[0] == item->unknown_4_.v[0] && cand->unknown_4_.v[1] == item->unknown_4_.v[1] &&
                        cand->unknown_4_.v[2] == item->unknown_4_.v[2] && cand->unknown_4_.v[3] == item->unknown_4_.v[3] &&
                        cand->unknown_4_.v[4] == item->unknown_4_.v[4] && cand->unknown_4_.v[5] == item->unknown_4_.v[5];
            if (match) {
                break;
            }
        }
        if (i != count) {
            func_0202ba08((struct Struct_0202ba08_2*)&obj->records[i], (struct Struct_0202ba08_2*)item);
            obj->unknown_790_[i] = 0xfa0;
            return;
        }
    }

    if (count >= 0xa) {
        return;
    }
    func_0202ba08((struct Struct_0202ba08_2*)&obj->records[count], (struct Struct_0202ba08_2*)item);
    obj->unknown_790_[obj->count] = 0xfa0;
    obj->count = obj->count + 1;
}
