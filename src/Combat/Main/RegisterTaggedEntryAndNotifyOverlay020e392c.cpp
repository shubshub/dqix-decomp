#include <globaldefs.h>
#include "GameState/GameState.h"

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Entry020e3840 {
    int f0;
    unsigned char f4, f5, f6;
};
struct SearchStruct;

struct TagValueEntry020e385c* FindEntryByTagAndValue(struct TagValueEntry020e385c* entries, int tag, int val);
struct Entry020e3840* FindFreeEntryAndReset020e38a0(struct Entry020e3840* p);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e392c
ARM void RegisterTaggedEntryAndNotifyOverlay020e392c(struct TagValueEntry020e385c* table, int tag, int val) {
    if (LinkSession_IsGuest((struct SearchStruct*)LinkSession_GetInstance())) return;
    if (FindEntryByTagAndValue(table, tag, val) != NULL) return;
    struct Entry020e3840* entry = FindFreeEntryAndReset020e38a0((struct Entry020e3840*)table);
    if (entry == NULL) return;
    GameState::GetInstance();
    entry->f4 = tag & 0xff;
    entry->f0 = val;
    func_ov017_021cebcc(3, tag & 0xff, val);
}
