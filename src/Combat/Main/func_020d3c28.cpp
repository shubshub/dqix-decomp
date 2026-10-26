#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020d3c28_180 = 0xa0 };
#else
enum { Enum_020d3c28_180 = 0xb4 };
#endif

#include "Filesystem/BackgroundLoader.h"
#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_020f244c[];
#endif
extern "C" void func_020d3c84(struct Struct_020d3c28*, struct StreamHeader*, int);
#include "std_library_functions.h"

extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);

extern int data_020f22e0;
extern int data_020f22f4;

struct Struct_02061c04_12 {
    unsigned char pad[Enum_020d3c28_180];
    int fieldB4;
};

// USA: func_020d3c28
extern "C" ARM void func_020d3c28(struct Struct_02061c04_12* obj) {
    int localVar;
    int result;
    memset(obj, 0, Enum_020d3c28_180);
    obj->fieldB4 = 0;
    BackgroundLoader::AddLockGlobal();
#if defined(jpn)
    result = (int)LoadFileIntoMemory(data_020f244c, g_fileLoadBuffer, (unsigned int*)&localVar);
#else
    result = (int)ExtractFileFromGP2((const char*)&data_020f22e0, (const char*)&data_020f22f4, (unsigned int*)&localVar);
#endif
    if (result != 0) {
        func_020d3c84((struct Struct_020d3c28*)(obj), (struct StreamHeader*)(result), (int)(localVar));
    }
    BackgroundLoader::RemoveLockGlobal();
}
