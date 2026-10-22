#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern int g_sePlayer;
extern int data_02107820;

// USA: func_020455f8
ARM void MessageSystem::HandleStateChange020455f8() {
    if (b19b3 == 1 || b19b2 == 0) {
        return;
    }
    switch (state) {
        case 0:
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xa, (int)&data_02107820);
            break;
        case 1:
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xc, (int)&data_02107820);
            break;
        case 2:
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xb, (int)&data_02107820);
            break;
    }
    b19b3 = 1;
}
