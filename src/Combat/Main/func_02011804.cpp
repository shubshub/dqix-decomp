#include <globaldefs.h>

struct GameState;
extern "C" ARM int func_020ac78c(void* dst);

// USA: func_02011804
extern "C" ARM unsigned char func_02011804(GameState* gameState) {
    unsigned char buf;
    func_020ac78c(&buf);
    return buf;
}
