#include <globaldefs.h>

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

// Main, originally ProcessRecords0205a498 (USA 0x0205a498, EUR 0x0205a4a8, JPN 0x0205b834)
extern "C" ARM int SpriteContext_LoadArchive(void* a, struct PacRecord* b, int flag, void* d) {
    int ret;
    if (flag) {
        int count = Pac_CountFiles((struct PacRecord*)b);
        for (int i = 0; i < count; i++) {
            void* dummyOut = 0;
            int fieldOut = 0;
            void* result = Pac_GetFile(b, i, &dummyOut, &fieldOut);
            if (result) {
                SpriteContext_LoadFile(a, result, fieldOut, d);
            }
        }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
