#include <globaldefs.h>

struct TaggedNumber02184c30 { unsigned int a, b; };
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30*);
struct Struct_ov011_02188934 { unsigned int w[8]; };
extern Struct_ov011_02188934 data_ov011_02188934;
#define CALL(x) func_ov011_02184c30(x)

// USA: func_ov011_02186440
extern "C" ARM int func_ov011_02186440(struct TaggedNumber02184c30* obj, int count) {
    Struct_ov011_02188934 rows;
    int idx = CALL(obj++);
    rows = data_ov011_02188934;
    unsigned int* fn = &rows.w[idx * 4];
    count--;
    while (count != 0) {
        int v = CALL(obj++);
        unsigned int f = *fn++;
        ((void (*)(int))f)(v);
        count--;
    }
    return 1;
}
