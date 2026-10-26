#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" ARM void func_ov000_0216f82c(unsigned char* output, const int* cell)
{
    int column = *cell % 9;
    int row = *cell / 9;
    unsigned char var2[6];
    if (row % 2 == 0) {
        if (column == 0) {
            if (row == 0) {
                var2[0] = 255;
                var2[1] = column + (row + 1) * 9;
                var2[2] = 255;
                var2[3] = column + 1 + row * 9;
                var2[4] = 255;
                var2[5] = 255;
            } else if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = 255;
                var2[3] = column + 1 + row * 9;
                var2[4] = 255;
                var2[5] = column + (row - 1) * 9;
            } else {
                var2[0] = 255;
                var2[1] = column + (row + 1) * 9;
                var2[2] = 255;
                var2[3] = column + 1 + row * 9;
                var2[4] = 255;
                var2[5] = column + (row - 1) * 9;
            }
        } else if (column == 8) {
            if (row == 0) {
                var2[0] = column - 1 + (row + 1) * 9;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = 255;
                var2[4] = 255;
                var2[5] = 255;
            } else if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = 255;
                var2[4] = column - 1 + (row - 1) * 9;
                var2[5] = 255;
            } else {
                var2[0] = column - 1 + (row + 1) * 9;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = 255;
                var2[4] = column - 1 + (row - 1) * 9;
                var2[5] = 255;
            }
        } else {
            if (row == 0) {
                var2[0] = column - 1 + (row + 1) * 9;
                var2[1] = column + (row + 1) * 9;
                var2[2] = column - 1 + row * 9;
                var2[3] = column + 1 + row * 9;
                var2[4] = 255;
                var2[5] = 255;
            } else if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = column + 1 + row * 9;
                var2[4] = column - 1 + (row - 1) * 9;
                var2[5] = column + (row - 1) * 9;
            } else {
                var2[0] = column - 1 + (row + 1) * 9;
                var2[1] = column + (row + 1) * 9;
                var2[2] = column - 1 + row * 9;
                var2[3] = column + 1 + row * 9;
                var2[4] = column - 1 + (row - 1) * 9;
                var2[5] = column + (row - 1) * 9;
            }
        }
    } else {
        if (column == 0) {
            if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = 255;
                var2[3] = column + 1 + row * 9;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            } else {
                var2[0] = column + (row + 1) * 9;
                var2[1] = column + 1 + (row + 1) * 9;
                var2[2] = 255;
                var2[3] = column + 1 + row * 9;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column == 7) {
            if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = 255;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            } else {
                var2[0] = column + (row + 1) * 9;
                var2[1] = column + 1 + (row + 1) * 9;
                var2[2] = column - 1 + row * 9;
                var2[3] = 255;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column < 7) {
            if (row == 8) {
                var2[0] = 255;
                var2[1] = 255;
                var2[2] = column - 1 + row * 9;
                var2[3] = column + 1 + row * 9;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            } else {
                var2[0] = column + (row + 1) * 9;
                var2[1] = column + 1 + (row + 1) * 9;
                var2[2] = column - 1 + row * 9;
                var2[3] = column + 1 + row * 9;
                var2[4] = column + (row - 1) * 9;
                var2[5] = column + 1 + (row - 1) * 9;
            }
        } else {
            var2[0] = 255;
            var2[1] = 255;
            var2[2] = 255;
            var2[3] = 255;
            var2[4] = 255;
            var2[5] = 255;
        }
    }
    INLINE_MEMCPY(output, var2, sizeof(var2));
}
