#include <globaldefs.h>

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);

// USA: func_0205a498
ARM int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d) {
    int ret;
    if (flag) {
        int count = Pac_CountFiles((struct ActiveEntry02046900*)b);
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
