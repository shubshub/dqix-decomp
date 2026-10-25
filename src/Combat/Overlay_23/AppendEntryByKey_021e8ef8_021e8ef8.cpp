#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_02042428(char*, int);
#endif

struct TableA68;
extern void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int Text_Append(char* dst, const char* src);

// USA: func_ov023_021e8ef8
ARM void AppendEntryByKey_021e8ef8_021e8ef8(void* obj) {
    struct TableA68* t = *(struct TableA68**)((char*)obj + 0x5f4);
    if (!t) return;
    char* dst = *(char**)((char*)obj + 0x5d8);
#if defined(jpn)
    func_02042428(dst, 12);
    t = *(struct TableA68**)((char*)obj + 0x5f4);
#endif
    void* entry = FindEntryByKey_02072a68(t, 0x77);
    Text_Append(dst, (const char*)entry);
}
