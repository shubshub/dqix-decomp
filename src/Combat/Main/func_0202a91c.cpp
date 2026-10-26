#include <globaldefs.h>

struct Struct_02029634_3 {
    char unk[0x6c];
    unsigned char state;
    char unk2[0xf];
    void (*callback)(struct Struct_02029634_3*);
};

// USA: func_0202a91c
extern "C" ARM void func_0202a91c(struct Struct_02029634_3* obj) {
    if (obj->state == 1) {
        return;
    }
    obj->state = 1;
    if (obj->callback == 0) {
        return;
    }
    obj->callback(obj);
}
