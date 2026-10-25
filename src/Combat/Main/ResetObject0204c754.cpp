#include <globaldefs.h>
void Forward0204acd0(struct BackgroundScreen*);

extern "C" void WindowPane_Init(void*);

struct Obj0204c754 {
    char pad0[0xc8];
    char fieldc8;
};

// USA: func_0204c754
ARM void ResetObject0204c754(struct Obj0204c754* obj) {
    Forward0204acd0((struct BackgroundScreen*)(&obj->fieldc8));
    WindowPane_Init(obj);
}
