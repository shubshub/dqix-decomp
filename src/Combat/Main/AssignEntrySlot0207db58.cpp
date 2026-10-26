#include <globaldefs.h>

struct Entry0207d9bc;
extern struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);

extern "C" void LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" void func_ov017_021c9b90(int a, int b);

// USA: func_0207db58
ARM int AssignEntrySlot0207db58(struct Entry0207d9bc* arr, unsigned short key, char val) {
    char* entry = (char*)FindEntryByHalfword(arr, key);
    if (entry == NULL) return -1;
    if (entry[4] < 0) {
        entry[4] = val;
        LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo()) {
            func_ov017_021c9b90(key, entry[4]);
        }
    }
    return entry[4];
}
