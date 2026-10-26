#include <globaldefs.h>

#if defined(jpn)
#define func_020965c0 func_jpn_02098210
#endif

struct Struct_02069d08_2 { unsigned char pad[0xac]; unsigned char tbl[0xcc]; };

// USA: func_020965c0
extern "C" ARM unsigned char func_020965c0(struct Struct_02069d08_2 *s, unsigned int val) {
    int i;
    if (val < 0xcc) {
        for (i = 0; i < 0xcc; i++) {
            if (s->tbl[i] == val) {
                return i;
            }
        }
    }
    return 0xff;
}
