#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_020a171c(void* obj, int type, void* arg);

struct Struct_020a1614 {
    unsigned int unk0;
    unsigned short unk4;
    unsigned short pad6;
    void* unknown_8_;
    unsigned char* unkc;
    unsigned char unk10;
};

// USA: func_020a1614
extern "C" ARM void func_020a1614(struct Struct_020a1614* obj) {
    obj->unknown_8_ = NULL;
    memset(obj->unkc, 0, (obj->unk4 - 1) / 8 + 1);

    obj->unknown_8_ = func_020a171c(obj, 1, NULL);
    void* node = obj->unknown_8_;
    if (node != NULL) {
        while (node != NULL) {
            void* next = func_020a171c(obj, 1, NULL);
            *(void**)((char*)node + 8) = next;
            node = next;
        }
    }
    obj->unk10 = 1;
}
