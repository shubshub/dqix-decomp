#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

struct Struct_0201f894 {
    struct Variant02030b0c items[6];
};

// USA: func_0201f894
extern "C" ARM int func_0201f894(struct Struct_0201f894* s) {
    ((Script::Parameter*)&s->items[0])->ToInt();
    ((Script::Parameter*)&s->items[1])->ToInt();
    ((Script::Parameter*)&s->items[2])->ToInt();
    ((Script::Parameter*)&s->items[3])->ToInt();
    ((Script::Parameter*)&s->items[4])->ToInt();
    ((Script::Parameter*)&s->items[5])->ToInt();
    return 1;
}
