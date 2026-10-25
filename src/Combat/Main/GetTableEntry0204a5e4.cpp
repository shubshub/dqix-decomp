#include <globaldefs.h>

#include "Graphics/Background.h"

// USA: func_0204a5e4
ARM int GetTableEntry0204a5e4(int a, int b) {
    return (int)Background_loadCharacterFunctions[a][b];
}
