#include <globaldefs.h>

struct Struct_ov031_02241694;
extern "C" int func_ov031_02241480(Struct_ov031_02241694*, int, char*, int, int);

// USA: func_ov031_02241694
extern "C" ARM int func_ov031_02241694(Struct_ov031_02241694* req, int s) {
    char buf[2];
    int p;
    int var2;
    int var3 = 0;

    buf[0] = 0;
    buf[1] = 0;
    p = 0;
    while (buf[p & 1] != 13 || buf[(p - 1) & 1] != 10) {
        var2 = func_ov031_02241480(req, s, buf + (p & 1), 1, 0);
        if (var2 <= 0) return var2;
        var3 += var2;
        p++;
    }
    return var3;
}
