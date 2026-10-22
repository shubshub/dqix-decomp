#include <globaldefs.h>

struct Obj0205eb08;
void ForwardAndCopyB8ToC0_0205eb08(struct Obj0205eb08* obj);

extern struct Obj0205eb08 g_sePlayer;

// USA: func_ov001_02163994
ARM int ForwardAndCopyB8ToC0Wrapper_02163994(void) {
    ForwardAndCopyB8ToC0_0205eb08(&g_sePlayer);
    return 1;
}
