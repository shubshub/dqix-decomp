#include <globaldefs.h>
extern "C" char* func_020424ac(char*);
extern "C" int func_020d857c(signed char*, signed char*);
extern "C" int STD_GetStringLength(const char*);
extern "C" int func_02005a94(const char*);
struct Struct_020e7e5c {
    signed char* name;
    void (*unknown_4_)(signed char*, signed char**, void*, int);
};
extern Struct_020e7e5c data_020e7e5c[];
// USA: func_0206831c
extern "C" ARM void func_0206831c(void* context, signed char* input, signed char* destination) {
    signed char* output;
    if (!input || !destination) return;
    output = destination;
    while (1) {
        if (!*input) break;
        if (*input == '<') {
            signed char* end = (signed char*)func_020424ac((char*)input);
            if (end) {
                int found = 0;
                Struct_020e7e5c* tag = data_020e7e5c;
                signed char* name = input + 1;
                while (tag->name) {
                    if (func_020d857c(name, tag->name)) {
                        if (tag->unknown_4_) {
                            int index = 0;
                            int length = STD_GetStringLength((char*)tag->name);
                            signed char digit = name[length];
                            if (digit >= '1' && digit <= '9') index = func_02005a94((char*)name + length) - 1;
                            tag->unknown_4_(name, &output, context, index);
                        }
                        input = end + 1;
                        found = 1;
                        break;
                    }
                    tag++;
                }
                if (found) continue;
            }
        }
        *output = *input++;
        output++;
    }
    *output = *input;
}
