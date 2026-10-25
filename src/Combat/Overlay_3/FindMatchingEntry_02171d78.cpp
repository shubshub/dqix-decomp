#include <globaldefs.h>

int AllBytesZero_02171df0(unsigned char* arr);
extern "C" int memcmp(void* a, void* b, int n);

struct Entry02171d78 { char data[6]; unsigned char flag; char pad; };

// USA: func_ov003_02171d78  (semantic: FindMatchingEntry_02171d78)
extern "C" ARM int func_ov003_02171d78(void* list, unsigned char* key) {
    if (key == 0) goto ret0;
    if (AllBytesZero_02171df0(key) != 0) {
ret0:
        return 0;
    }
    {
        Entry02171d78* entry = (Entry02171d78*)((char*)list + 8);
        for (int i = 0; i < 0x32; i++, entry++) {
            if (entry->flag != 0) {
                if (memcmp(entry, key, 6) == 0) return 1;
            }
        }
    }
    return 0;
}
