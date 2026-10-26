#include <globaldefs.h>

#if defined(jpn)
#define FLAG_OFFSET_02174890 0xfba
#define CONTAINER_OFFSET_02174890 0x818
#else
#define FLAG_OFFSET_02174890 (0x1000 + 0x3e)
#define CONTAINER_OFFSET_02174890 0x89c
#endif

struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);
struct Struct_020e2834;
extern "C" void func_020e2834(struct Struct_020e2834* self);

// USA: func_ov003_02174890
extern "C" ARM void func_ov003_02174890(char* obj) {
    if (*(unsigned char*)(obj + FLAG_OFFSET_02174890) == 0) return;
    struct Struct_0207fd88* p = *(struct Struct_0207fd88**)(obj + CONTAINER_OFFSET_02174890);
    func_0207fd88(p);
    struct Struct_020e2834* self = *(struct Struct_020e2834**)obj;
    if (self == NULL) return;
    func_020e2834(self);
}
