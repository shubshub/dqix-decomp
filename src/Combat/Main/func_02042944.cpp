#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_02042804(void*, const char*, int*, int*);
extern char data_020f0079;
extern char data_020f007c;
extern int Font_characterTables[];
extern int data_02107834[];
extern int data_02107830[];
extern int data_02107838[];

// USA: func_02042944
extern "C" ARM void func_02042944(void* arg0) {
    BackgroundLoader::AddLockGlobal();
    func_02042804(obj, &data_020f0079, Font_characterTables, data_02107834);
    func_02042804(obj, &data_020f007c, data_02107830, data_02107838);
    BackgroundLoader::RemoveLockGlobal();
}
