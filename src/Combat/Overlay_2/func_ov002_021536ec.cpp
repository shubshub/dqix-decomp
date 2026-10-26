#include <globaldefs.h>

#if defined(jpn)
#define data_ov002_0216ccc4 data_ov002_0216d2e4
#endif

class Struct_ov002_021536ec {
public:
    char *f0;
};
typedef int (Struct_ov002_021536ec::*Type_ov002_021536ec)(void *arg, void *item, int mode);

struct Struct_ov002_0216ccc0 {
    short key;
    Type_ov002_021536ec fn;
};
struct Struct_ov002_021536ec_2 {
    char pad[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int keyA : 7;
    unsigned int rest : 20;
};
struct Struct_ov002_0216ccc4 {
    int ptr;
    int pad[2];
};

extern "C" void *func_02079e2c(char *p, int key);

extern "C" unsigned int data_ov002_0216d3a0[2];
extern "C" Type_ov002_021536ec __ptmf_null;
extern "C" struct Struct_ov002_0216ccc0 data_ov002_0216cce4[12];
extern "C" struct Struct_ov002_0216ccc4 data_ov002_0216cce8[12];
extern "C" struct Struct_ov002_0216ccc0 data_ov002_0216ccc0[3];
extern "C" struct Struct_ov002_0216ccc4 data_ov002_0216ccc4[3];

// USA: func_ov002_021536ec
extern "C" ARM int func_ov002_021536ec(Struct_ov002_021536ec *obj, short *arg) {
    if (obj->f0 == NULL) return 0;
    if (arg == NULL) return 0;
    struct Struct_ov002_021536ec_2 *item = (struct Struct_ov002_021536ec_2 *) func_02079e2c(obj->f0, *arg);
    if (item == NULL) return 0;
    struct Struct_ov002_0216ccc0 *tb;

    int var2 = 0;
    if (!(data_ov002_0216d3a0[1] & 1)) {
        Type_ov002_021536ec t            = __ptmf_null;
        data_ov002_0216cce4[0].fn  = t;
        data_ov002_0216cce4[11].fn = t;
        data_ov002_0216d3a0[1] |= 1;
    }
    unsigned int key = item->keyA;
    for (int i = 0; data_ov002_0216cce4[i].key >= 0; i++) {
        if (key == data_ov002_0216cce4[i].key) {
            if (data_ov002_0216cce8[i].ptr != 0) {
                var2 = (obj->*data_ov002_0216cce4[i].fn)(arg, item, 0);
            }
            break;
        }
    }

    int var6 = 0;
    if (!(data_ov002_0216d3a0[0] & 1)) {
        Type_ov002_021536ec t           = __ptmf_null;
        data_ov002_0216ccc0[0].fn = t;
        data_ov002_0216ccc0[2].fn = t;
        data_ov002_0216d3a0[0] |= 1;
    }
    unsigned int key2 = item->unknown_18_0_;
    int i;
    for (i = 0, tb = (data_ov002_0216cce4 - 3); tb[i].key >= 0; i++) {
        if (key2 == tb[i].key) {
            if (data_ov002_0216ccc4[i].ptr != 0) {
                var6 = (obj->*tb[i].fn)(arg, item, 1);
            }
            break;
        }
    }
    return (var2 || var6) ? 1 : 0;
}
