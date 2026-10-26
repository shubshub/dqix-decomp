#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"

#pragma optimize_for_size off

// USA: func_ov027_021dac74
extern "C" ARM CBool func_ov027_021dac74(const char* path, void* dst, int large)
{
    unsigned int capacity = large ? 0x200 : 0x20;
    char* var1 = large ? (char*)dst + 0x20 : (char*)dst;

    if (path == NULL)
        return false;

    NitroVM vm;
    NitroVM_Initialize(&vm);

    if (!NitroVM_PrepareReadFileByPath(&vm, path))
        return false;

    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
    if (capacity != size)
    {
        NitroVM_FinishRead(&vm);
        return false;
    }

    NitroVM_ReadSync(&vm, var1, capacity);
    NitroVM_FinishRead(&vm);
    return true;
}
