#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

typedef int (*Type_ov011_021862a4)(int, int, int, int, int);
typedef int (*Type_ov011_021862a4_2)(int, int, int, int);

struct Struct_ov011_021862a4 { void* fn[4]; };
struct Struct_ov011_02188914 { struct Struct_ov011_021862a4 row[2]; };
extern struct Struct_ov011_02188914 data_ov011_02188914;

// USA: func_ov011_021862a4
extern "C" ARM int func_ov011_021862a4(struct TaggedNumber02184c30* args) {
    int mode = func_ov011_02184c30(&args[0]);
    int idx = func_ov011_02184c30(&args[1]);
    int a = func_ov011_02184c30(&args[2]);
    int b = func_ov011_02184c30(&args[3]);
    int c = func_ov011_02184c30(&args[4]);
    int d = func_ov011_02184c30(&args[5]);
    int e = func_ov011_02184c30(&args[6]);

    struct Struct_ov011_02188914 table = data_ov011_02188914;
    void* fn = table.row[mode].fn[idx];
    if (idx < 2) {
        ((Type_ov011_021862a4)fn)(a, b, c, d, e);
    } else {
        ((Type_ov011_021862a4_2)fn)(a, b, c, d);
    }
    return 1;
}
