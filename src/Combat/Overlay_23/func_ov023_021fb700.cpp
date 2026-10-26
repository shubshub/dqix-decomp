#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021fb700 func_ov023_021faaa4
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern char data_ov023_021fef64[];

struct Struct_ov023_021fb700 {
    char unknown0[0x10];
    int unknown_10_;
    char unknown14[8];
    int state;
};

// USA: func_ov023_021fb700
extern "C" ARM int func_ov023_021fb700(Struct_ov023_021fb700* request, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return request->state;
    }
    char buf[0x50];
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    sprintf(buf, data_ov023_021fef64, request->unknown_10_);
    int result = loader->QueueLoadFile(buf, NULL);
    func_ov023_021f6bb0(sub, result);
    return 1;
}
