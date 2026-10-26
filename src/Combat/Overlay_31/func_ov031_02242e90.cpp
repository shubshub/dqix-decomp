#include <globaldefs.h>

enum Enum_ov031_02242e90 { Enum_ov031_02242e90_0 = 0, Enum_ov031_02242e90_1 = 1 };

// USA: func_ov031_02242e90
extern "C" ARM int func_ov031_02242e90(const signed char* first, const signed char* second) {
    int var0;
    Enum_ov031_02242e90 var1;
    int left;
    int right;
    goto compare;
advance:
    if (left == 0 || left == ' ') return 0;
    ++first;
    ++second;
compare:
    right = *second;
    var1 = Enum_ov031_02242e90_0;
    if (right >= 'A' && right <= 'Z') var1 = Enum_ov031_02242e90_1;
    left = *first;
    if (var1) right += 32;
    var1 = Enum_ov031_02242e90_0;
    if (left >= 'A' && left <= 'Z') var1 = Enum_ov031_02242e90_1;
    var0 = var1 ? left + 32 : left;
    if (var0 == right) goto advance;
    return -1;
}
