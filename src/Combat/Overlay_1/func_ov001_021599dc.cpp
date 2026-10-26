#include <globaldefs.h>

struct Struct_ov001_021599dc { char pad[0x10]; int limit; };
struct Struct_ov001_021599dc_2 { char pad[0x50]; int count; };

// USA: func_ov001_021599dc
extern "C" ARM int func_ov001_021599dc(Struct_ov001_021599dc* arg0, Struct_ov001_021599dc_2* cnt) {
    int cur = cnt->count;
    int max = arg0->limit;
    if (cur >= max) {
        cnt->count = 0;
        return 0;
    }
    cnt->count = cur + 1;
    return 1;
}
