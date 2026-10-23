#include <globaldefs.h>

struct Obj0204b8d0;
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
void Background_UploadMap(struct List0204b0e8*, void*);

// USA: func_ov000_02175480
ARM void DispatchAndFlush02175480(void* obj) {
    Background_DrawScreen((struct Obj0204b8d0*)((char*)obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Background_UploadMap((struct List0204b0e8*)((char*)obj + 0x8c4), 0);
}
