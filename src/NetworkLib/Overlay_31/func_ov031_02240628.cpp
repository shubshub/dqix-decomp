#include <globaldefs.h>

struct Struct_ov031_02240628;
extern "C" void func_ov031_02240410(Struct_ov031_02240628*, int, void**, int*);
extern "C" signed char func_ov031_0224046c(Struct_ov031_02240628*, void**, int*);

// USA: func_ov031_02240628
extern "C" ARM int func_ov031_02240628(Struct_ov031_02240628* buffer, int start, int end, const signed char* name, int arg4) {
    void* var0;
    int counter;
    if (start < end) {
        func_ov031_02240410(buffer, start, &var0, &counter);
        int character = func_ov031_0224046c(buffer, &var0, &counter);
        int var3;
        int var4;
        goto compare;
        do {
            if (*name == 0 || *name == ' ' || *name == arg4 || start == end - 1) return 0;
            character = func_ov031_0224046c(buffer, &var0, &counter);
            ++start;
            ++name;
compare:
            var4 = 0;
            if (*name >= 'A' && *name <= 'Z') var4 = 1;
            var3 = var4 ? *name + 32 : *name;
            if (character >= 'A' && character <= 'Z') character += 32;
        } while (character == var3);
    }
    return -1;
}
