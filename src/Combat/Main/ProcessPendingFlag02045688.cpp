#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

void ForwardToTargetOrDefault0205eabc(void*, void*, int);
extern int g_sePlayer;
extern int data_02107820;

// USA: func_02045688
ARM void MessageSystem::ProcessPendingFlag02045688() {
    if (b19b3 && b19b2) {
        ForwardToTargetOrDefault0205eabc(&g_sePlayer, &data_02107820, 0);
        b19b3 = 0;
    }
}
