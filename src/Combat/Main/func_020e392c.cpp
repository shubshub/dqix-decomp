#include <globaldefs.h>
#include "GameState/GameState.h"

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Struct_020e3814 {
    int f0;
    unsigned char f4, unknown_5_, unknown_6_;
};
struct SearchStruct;

extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" struct Struct_020e3814* func_020e38a0(struct Struct_020e3814* p);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e392c
extern "C" ARM void func_020e392c(struct TagValueEntry020e385c* table, int tag, int val) {
    if (LinkSession_IsGuest((struct SearchStruct*)LinkSession_GetInstance())) return;
    if (func_020e385c(table, tag, val) != NULL) return;
    struct Struct_020e3814* entry = func_020e38a0((struct Struct_020e3814*)table);
    if (entry == NULL) return;
    GameState::GetInstance();
    entry->f4 = tag & 0xff;
    entry->f0 = val;
    func_ov017_021cebcc(3, tag & 0xff, val);
}
