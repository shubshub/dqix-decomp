#include <globaldefs.h>

extern "C" void Background_CopyScreenRect(void*, void*, int, int, int, int, int, int, int, int);

struct Obj0204b878 {
    char pad[0x14];
    void* field14;
};

// USA: func_0204b878
ARM void CallFunc0204b620IfField0x14_0204b878(struct Obj0204b878* obj, int a2, int a3, int a4,
                                              short a5, short a6, short a7, short a8, unsigned short a9) {
    if (obj->field14 != NULL) {
        Background_CopyScreenRect(obj, obj->field14, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}
