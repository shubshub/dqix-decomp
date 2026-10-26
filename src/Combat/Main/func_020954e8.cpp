#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_02109404_4 {
    unsigned char pad[6];
    unsigned short count;
};
extern struct Struct_02109404_4 data_02109404;

// USA: func_020954e8
extern "C" ARM int func_020954e8(struct Variant02030b0c* p) {
    int v = ((Script::Parameter*)p)->ToInt();
    if (v == 0xff || v == 0) {
        return 1;
    }
    data_02109404.count++;
    return 1;
}
