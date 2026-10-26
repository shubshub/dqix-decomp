#include <globaldefs.h>

extern float data_020e88f8[][2];

// USA: func_02074738
extern "C" ARM float func_02074738(int row, int col) {
    float v = data_020e88f8[row][col];
    if (v < 1.0f) {
        v = 1.0f;
    }
    return v;
}
