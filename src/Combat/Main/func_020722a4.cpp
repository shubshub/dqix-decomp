#include <globaldefs.h>

struct Struct_02071ffc_5 {
    char pad0[0x10];
    unsigned int flags;
    int pad1[2];
    struct Struct_02071ffc_5* next;
};

// USA: func_020722a4
extern "C" ARM void func_020722a4(struct Struct_02071ffc_5** list, int n) {
    int i;
    int matchCount;
    int kept;
    struct Struct_02071ffc_5* var3;
    struct Struct_02071ffc_5* tail;
    struct Struct_02071ffc_5* var5;
    struct Struct_02071ffc_5* cur;
    struct Struct_02071ffc_5* last;

    if (n <= 0) return;

    var3 = *list;
    i = 0;
    matchCount = 0;
    kept = 0;
    tail = 0;
    var5 = 0;
    cur = var3;

    while (cur != 0) {
        if ((cur->flags << 9) >> 31) matchCount++;
        i++;
        last = cur;
        cur = cur->next;
        if (i == n || cur == 0) {
            if (matchCount > 0) {
                kept++;
                if (tail != 0) tail->next = var3;
                else *list = var3;
                tail = last;
            }
            i = 0;
            matchCount = 0;
            var3 = cur;
            if (var5 == 0) var5 = last;
        }
    }

    if (kept == 0) {
        if (var5 != 0) var5->next = 0;
    } else {
        if (tail != 0) tail->next = 0;
    }
}
