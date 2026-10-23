#include <globaldefs.h>
#if defined(jpn)
enum { kPrefix = 0x20 };
#else
enum { kPrefix = 0x2c };
#endif

struct Obj0204b010;

extern void Background_ClearMap(struct Obj0204b010* obj, void* p);

struct Obj0207fcb8 {
    char pad0[kPrefix];
    char* entries;
    char pad30[8];
    unsigned char count;
};

// USA: func_0207fcb8
ARM void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj) {
    unsigned char i;
    if (obj->entries != NULL) {
        for (i = 0; i < obj->count; i++) {
            Background_ClearMap((struct Obj0204b010*)(obj->entries + i * 0x20), NULL);
        }
    }
}
