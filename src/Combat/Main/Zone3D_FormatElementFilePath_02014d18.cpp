#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_020ef1de[];  // "ARC:/%s"
extern const char data_020ef1e6[];  // "."

// Main, originally FormatFilenameAndSetExtension02014d18 (USA 0x02014d18, EUR 0x02014d28, JPN 0x02014ae4)
ARM void Zone3D_FormatElementFilePath(int name, char* extension, char* path) {
    sprintf(path, data_020ef1de, name);
    char* dot = strrchr(path, '.');
    if (dot != NULL) {
        strcpy(dot + 1, extension);
    } else {
        strcat(path, data_020ef1e6);
        strcat(path, extension);
    }
}
