#include <globaldefs.h>

// USA: func_ov031_0223e38c
extern "C" ARM int func_ov031_0223e38c(char* destination, const char* source, int length) {
    int index;
    int copied = 0;
    index = 0;
    if (length > 0) do {
        int character = *source;
        if (character != 0) {
            copied++;
            source++;
            *destination++ = character;
        } else {
            *destination++ = 0;
        }
        index++;
    } while (index < length);
    return copied;
}
