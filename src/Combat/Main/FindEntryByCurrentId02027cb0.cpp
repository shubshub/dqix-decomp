#include <globaldefs.h>

extern "C" unsigned short* Zone3D_GetInstance(void);

struct Entry_02028bd0;
extern struct Entry_02028bd0 data_020fdd44;
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

// USA: func_02027cb0
ARM struct Entry_02028bd0* FindEntryByCurrentId02027cb0(void) {
    return FindInlineEntryById(&data_020fdd44, *Zone3D_GetInstance());
}
