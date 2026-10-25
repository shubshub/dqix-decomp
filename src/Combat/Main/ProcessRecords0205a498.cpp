#include <globaldefs.h>

struct PacRecord;
int Pac_CountFiles(struct PacRecord* entry);
void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

// USA: func_0205a498
ARM int ProcessRecords0205a498(void* a, struct PacRecord* b, int flag, void* d) {
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
