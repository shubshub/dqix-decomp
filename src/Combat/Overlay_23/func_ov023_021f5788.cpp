#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);

struct Struct_ov023_021fff08_4 { char unknown0[0x10]; const char* text; };
extern struct Struct_ov023_021fff08_4 data_ov023_021fff08;

// USA: func_ov023_021f5788
extern "C" ARM int func_ov023_021f5788(void* obj) {
    Script::Parameter* params = (Script::Parameter*)obj;
#if defined(jpn)
    data_ov023_021fff08.text = params[0].ToString();
#else
    int a = params[0].ToInt();
    int b = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());
    if (a == b) {
        data_ov023_021fff08.text = params[1].ToString();
    }
#endif
    return 1;
}
