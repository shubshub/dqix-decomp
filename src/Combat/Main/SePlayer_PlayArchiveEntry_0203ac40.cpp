#include <globaldefs.h>

int ReturnFalse020d84ec(void);
void* SetGlobalContext02110370_020bd42c(void* value);
int TrySetActionFromListEntry_020be7a8(void* obj, int id, int index);

// Main, originally func_0203ac40 (USA 0x0203ac40, EUR 0x0203ac50, JPN 0x0203a698)
extern "C" ARM int SePlayer_PlayArchiveEntry(void* obj, int a, int b, void* c) {
    char* p = (char*)obj;
    if (ReturnFalse020d84ec()) {
        *(unsigned short*)(p + 0xac) = (unsigned short)a;
        *(unsigned short*)(p + 0xae) = (unsigned short)b;
        return 1;
    }
    int result = 0;
    if (*(int*)p != 0) {
        SetGlobalContext02110370_020bd42c(p + 0x4);
        if (c != 0) {
            if (TrySetActionFromListEntry_020be7a8(c, a, b) != 0) result = 1;
        } else {
            if (TrySetActionFromListEntry_020be7a8(p + 0x98, a, b) != 0) result = 1;
        }
    }
    return result;
}
