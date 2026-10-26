#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020e5204;
extern "C" int func_020e5204(void* arg0, struct Struct_020e5204* p);

extern "C" void* func_020e53bc(void* a, void* b, void* out, void* fn);

struct Container020e0310 {
    unsigned int w[3];
};
extern "C" void* func_020e52a0(struct Container020e0310* arr, int key);

// USA: func_020e5334
extern "C" ARM void* func_020e5334(void* buf, void* b, void* c, int idx) {
    struct Container020e0310 local;
    int out;
    void* p;
    if (buf == NULL || b == NULL || c == NULL || idx < 0) return NULL;
    memset(&local, 0, sizeof(local));
    func_020e53bc(&local, b, &out, (void*)func_020e5204);
    p = func_020e52a0(&local, idx);
    if (p == NULL) return NULL;
    memcpy(buf, p, sizeof(local));
    return buf;
}
