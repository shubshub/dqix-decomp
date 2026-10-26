#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int, int, void*, int, int, int, int);
// USA: func_02098f70
extern "C" void func_02098f70(int* cursor, void* data, int size, int advance) {
    char** cur = (char**)cursor;
    int base = MessageSystem_GetInstance();
    memcpy(*cur, (void*)size, advance);
    *cur += advance;
    MessageSystem_FormatText(base, 0xc, data, *(int*)cur, 0xe3, 0, 1);
    *cur += strlen(*cur);
}
