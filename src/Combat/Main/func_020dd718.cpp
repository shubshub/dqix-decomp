#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field150Holder02052e14;
extern "C" short* func_02052e14(struct Field150Holder02052e14* obj);

// USA: func_020dd718
extern "C" ARM int func_020dd718(int combatantId, int value) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(bs, combatantId);
    short* list = func_02052e14((struct Field150Holder02052e14*)c);
    unsigned char i = 0;
    while (i < 10) {
        if (value == list[i]) return 1;
        i = (i + 1) & 0xff;
    }
    return 0;
}
