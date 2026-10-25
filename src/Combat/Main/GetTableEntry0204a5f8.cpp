#include <globaldefs.h>

#include "Graphics/Background.h"

// USA: func_0204a5f8
ARM int GetTableEntry0204a5f8(int a, int b) {
    return (int)Background_loadScreenFunctions[a][b];
}
