#include <globaldefs.h>

struct TagValueEntry020e385c {
    unsigned int val;
    unsigned char tag;
};
struct Entry020e3840 {
    int f0;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
};

struct TagValueEntry020e385c* FindEntryByTagAndValue(struct TagValueEntry020e385c* entries, int tag, int val);
void ResetEntry020e3840(struct Entry020e3840* s);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_ov017_021cebcc(int, int, int);

// USA: func_020e3994
ARM void ResetTaggedEntryAndNotifyOverlay020e3994(struct TagValueEntry020e385c* table, int tag, int val) {
    struct TagValueEntry020e385c* entry = FindEntryByTagAndValue(table, tag, val);
    if (entry == NULL) return;
    ResetEntry020e3840((struct Entry020e3840*)entry);
    if (!LinkSession_IsHostOrSolo(LinkSession_GetInstance())) return;
    func_ov017_021cebcc(3, tag & 0xff, val);
}
