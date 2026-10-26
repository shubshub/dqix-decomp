#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

extern "C" void func_0205eabc(void*, void*, int);
extern int g_sePlayer;
extern int data_02107820;

// USA: func_02045688
ARM void MessageSystem::func_02045688() {
    if (unknown_19b3_ && unknown_19b2_) {
        func_0205eabc(&g_sePlayer, &data_02107820, 0);
        unknown_19b3_ = 0;
    }
}
