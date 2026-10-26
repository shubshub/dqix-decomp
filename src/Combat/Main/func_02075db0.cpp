#include <globaldefs.h>

extern "C" int func_02075df4(void* obj, int a, int b, int c);

struct Struct_02075db0 {
    char pad0[0x24];
    int** rows;
    char pad1[0x34];
    unsigned short unknown_5c_;
    char pad2[0x2];
    int unknown_60_;
    int unknown_64_;
};

// USA: func_02075db0
extern "C" ARM int func_02075db0(struct Struct_02075db0* s, int a, int b) {
    int** rows;
    int* row;
    if (s->unknown_5c_ == 0) return 0;
    rows = s->rows;
    if (rows == NULL) return 0;
    row = rows[s->unknown_64_];
    return func_02075df4(s, row[s->unknown_60_], a, b);
}
