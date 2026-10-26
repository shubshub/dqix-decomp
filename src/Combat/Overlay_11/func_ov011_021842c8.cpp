#include <globaldefs.h>

// USA: func_ov011_021842c8
extern "C" ARM void* func_ov011_021842c8(unsigned char* node, unsigned int id) {
    if (*(unsigned int*)node == id) return node;
    void* result = 0;
    unsigned char* left = *(unsigned char**)(node + 0x18);
    if (left) result = func_ov011_021842c8(left, id);
    if (result) return result;
    unsigned char* right = *(unsigned char**)(node + 0x1c);
    if (right) result = func_ov011_021842c8(right, id);
    return result;
}
