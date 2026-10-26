#include <globaldefs.h>


// USA: func_ov031_0221e650
extern "C" THUMB int func_ov031_0221e650(const char* text) {
    int length = 0;
    if (text[length] != 0) {
        do {
            length++;
        } while (text[length] != 0);
    }
    return length;
}
