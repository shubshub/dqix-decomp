#include <globaldefs.h>
char* FindUnescapedAngleBracket_020424ac(char*);
int IsPrefixMatch020d857c(signed char*, signed char*);
int STD_GetStringLength(const char*);
extern "C" int func_02005a94(const char*);
struct Struct_020e7e5c {
    signed char* unknown_0_;
    void (*unknown_4_)(signed char*, signed char**, void*, int);
};
extern Struct_020e7e5c data_020e7e5c[];
// USA: func_0206831c
extern "C" ARM void func_0206831c(void* arg0, signed char* arg1, signed char* arg2) {
    signed char* var0;
    if (!arg1 || !arg2) return;
    var0 = arg2;
    while (1) {
        if (!*input) break;
        if (*input == '<') {
            signed char* end = (signed char*)FindUnescapedAngleBracket_020424ac((char*)input);
            if (end) {
                int found = 0;
                Tag0206831c* tag = data_020e7e5c;
                signed char* name = input + 1;
                while (tag->name) {
                    if (IsPrefixMatch020d857c(name, tag->name)) {
                        if (tag->expand) {
                            int index = 0;
                            int length = STD_GetStringLength((char*)tag->name);
                            signed char digit = name[length];
                            if (digit >= '1' && digit <= '9') index = func_02005a94((char*)name + length) - 1;
                            tag->expand(name, &output, context, index);
                        }
                        arg1 = var1 + 1;
                        var2 = 1;
                        break;
                    }
                    var3++;
                }
                if (var2) continue;
            }
        }
        *var0 = *arg1++;
        var0++;
    }
    *var0 = *arg1;
}
