#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"

int NitroVM_ReadSync(NitroVM* vm, void* dst, int capacity);
int NitroVM_Seek(NitroVM* vm, int position, int whence);

struct Struct_020bd7c4 {
    unsigned long offset;
    unsigned long size;
    void* mem;
    unsigned long reserved;
};

struct Struct_020bd7c4_2 {
    unsigned long kind;
    unsigned long unknown_4_;
    unsigned long count;
    Struct_020bd7c4 files[1];
};

struct Struct_020bd7c4_3 {
    char header[0x34];
    NitroVM file;
    char unknown_7c_[8];
    Struct_020bd7c4_2* unknown_84_;
    void* symbol;
    void* info;
    long unknown_90_;
};

extern Struct_020bd7c4_3* data_02110370;

// USA: func_020bd7c4
extern "C" ARM long func_020bd7c4(unsigned long arg0, void* buffer, long size, long offset) {
    long total;
    long var1;
    long var2;
    Struct_020bd7c4_3* var3;
    long result;

    var3 = data_02110370;
    if (arg0 >= var3->unknown_84_->count)
        return -1;

    const Struct_020bd7c4* file = &var3->unknown_84_->files[arg0];

    var1 = var3->unknown_90_;
    if (var1 == 0)
        var1 = size;

    total = 0;
    if (total < size) do {
        var2 = size - total;
        if (var2 > var1)
            var2 = var1;
        if (var2 > file->size - offset)
            var2 = (long)(file->size - offset);
        if (var2 == 0)
            break;

        if (!NitroVM_Seek(&var3->file, (long)(file->offset + offset), 0))
            return -1;

        result = NitroVM_ReadSync(&var3->file, buffer, var2);
        if (result < 0)
            return result;

        total += result;
        offset += result;
        buffer = (unsigned char*)buffer + result;
    } while (total < size);
    return total;
}
