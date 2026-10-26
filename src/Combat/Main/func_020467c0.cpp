#include <globaldefs.h>

extern "C" char* func_0204673c(char* records, char* path);

struct Struct_020467c0 {
    char name[0x40];
    unsigned int unknown_40_;
    unsigned int unknown_44_;
    unsigned int unknown_48_;
};

// USA: func_020467c0
extern "C" ARM char* func_020467c0(void* records, char* path, unsigned int* outSize) {
    Struct_020467c0* record = (Struct_020467c0*)func_0204673c((char*)records, path);
    if (record == NULL) return NULL;
    if (outSize != NULL) *outSize = record->unknown_44_;
    return (char*)record + record->unknown_40_;
}
