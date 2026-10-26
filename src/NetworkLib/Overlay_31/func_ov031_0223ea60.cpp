#include <globaldefs.h>

extern const char data_ov031_0224c698[];

extern "C" int func_020c7170(char*, unsigned long, const char*, ...);

// USA: func_ov031_0223ea60
extern "C" ARM int func_ov031_0223ea60(char* destination) {
    return func_020c7170(destination, 0x21, data_ov031_0224c698, 3, 1);
}
