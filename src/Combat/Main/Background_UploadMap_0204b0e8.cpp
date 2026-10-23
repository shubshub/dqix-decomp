#include <globaldefs.h>

extern "C" void Background_FlushMap(void*, int);
extern "C" void Background_TransferMap(void*, int);

struct List0204b0e8 {
    char pad0[0x14];
    void* field14;
};

// Main, originally FlushAndDispatchList0204b0e8 (USA 0x0204b0e8, EUR 0x0204b0f8, JPN 0x0204bf08)
ARM void Background_UploadMap(struct List0204b0e8* obj, void* buf) {
    if (buf == NULL) buf = obj->field14;
    if (buf == NULL) return;
    Background_FlushMap(obj, (int)buf);
    Background_TransferMap(obj, (int)buf);
}
