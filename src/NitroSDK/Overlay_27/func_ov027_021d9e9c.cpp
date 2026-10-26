#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

struct Struct_ov027_021d9e9c_3
{
    unsigned long src;
    unsigned long len;
    unsigned char* ptr;
    unsigned long state;
};

struct Struct_ov027_021d9e9c_4
{
    unsigned long unknown_0_;
    char unk_4[0xc];
    char unknown_10_[4];
    unsigned long unknown_14_;
    void* unknown_18_;
    char unk_1c[0x14];
    Struct_ov027_021d9e9c_3 list[4];
};

struct Struct_ov027_021d9e9c_5
{
    char unk_0[0x20];
    unsigned long unknown_20_;
    unsigned long unknown_24_;
    unsigned long unknown_28_;
    unsigned long unknown_2c_;
    unsigned long unknown_30_;
    unsigned long unknown_34_;
    unsigned long unknown_38_;
    unsigned long unknown_3c_;
    char unk_40[0x20];
    unsigned long unknown_60_;
    char unk_64[0x1c];
    unsigned long unknown_80_;
    char unknown_84_[0x160 - 0x84];
};

static inline const Struct_ov027_021d9e9c_5* inline_ov027_021d9e9c()
{
    return (const Struct_ov027_021d9e9c_5*)0x027ffe00;
}

struct Struct_ov027_021d9e9c
{
    unsigned long unk_0;
    unsigned long unknown_4_;
    unsigned long unknown_8_;
    unsigned long unk_c;
};

struct Struct_ov027_021d9e9c_2
{
    unsigned long top;
    unsigned char* source;
    unsigned char* destination;
    unsigned long len;
};

#define SEGMENT_BUFFER_MIN 0x164
#define SECURE_AREA_START 0x4000
#define SECURE_AREA_END 0x8000

extern "C" const unsigned long (*data_ov027_021dd8e4)[2];
extern "C" char data_ov027_021dd8e8[];

extern "C"
{
    void AutoloadCallback();
    void func_ov027_021dd104(Struct_ov027_021d9e9c_4* arg0);
    void func_ov027_021dd118(Struct_ov027_021d9e9c_4* arg0, unsigned long src, unsigned long len, void* ptr, unsigned long state);
    void func_ov027_021da314(const Struct_ov027_021d9e9c_2* area, unsigned long top, unsigned long bottom, int clear);
}

// USA: func_ov027_021d9e9c
extern "C" ARM int func_ov027_021d9e9c(NitroVM* file, void* buffer, unsigned long len)
{
    int ret = false;
    if (len >= SEGMENT_BUFFER_MIN)
    {
        int var1 = false;
        unsigned long rest = len;
        unsigned char* p = (unsigned char*)buffer;
        Struct_ov027_021d9e9c_4* cache = NULL;
        Struct_ov027_021d9e9c* var5 = NULL;
        Struct_ov027_021d9e9c_5* header = (Struct_ov027_021d9e9c_5*)buffer;
        int top;
        unsigned long var8;
        NitroVM var9;

        p += sizeof(Struct_ov027_021d9e9c_5);
        rest -= sizeof(Struct_ov027_021d9e9c_5);

        if (file != NULL)
        {
            top = file->fileInfo.unknown_c_ - file->fileInfo.startOffset;
            if (NitroVM_ReadSync(file, header, sizeof(Struct_ov027_021d9e9c_5)) < (int)sizeof(Struct_ov027_021d9e9c_5))
                rest = 0;
            var8 = header->unknown_80_;
            if (var8 == 0)
                var8 = 0x01000000;
        }
        else
        {
            var8 = inline_ov027_021d9e9c()->unknown_80_;
            if (var8 == 0)
                var8 = 0x01000000;
            var1 = true;
            NitroVM_Initialize(&var9);
            NitroVM_PrepareRead(&var9, NitroHandle_FindBySignature(data_ov027_021dd8e8, 3), 0, var8 + 0x88,
                                (unsigned int)-1);
            file = &var9;
            top = file->fileInfo.unknown_c_ - file->fileInfo.startOffset;
            VectorizedInvertedMemcpy(inline_ov027_021d9e9c(), header, sizeof(Struct_ov027_021d9e9c_5));
            header->unknown_60_ |= 0x406000;
        }

        if (rest >= 0x88)
        {
            NitroVM_Seek(file, top + var8, 0);
            NitroVM_ReadSync(file, p, 0x88);
            p += 0x88;
            rest -= 0x88;
        }
        else
        {
            rest = 0;
        }

        if (rest >= sizeof(Struct_ov027_021d9e9c_4))
        {
            cache = (Struct_ov027_021d9e9c_4*)p;
            func_ov027_021dd104(cache);
            p += sizeof(Struct_ov027_021d9e9c_4);
            rest -= sizeof(Struct_ov027_021d9e9c_4);
            func_ov027_021dd118(cache, 0, sizeof(Struct_ov027_021d9e9c_5), header, 3);
            {
                int length;
                const char* name = (const char*)file->linkedHandle;
                for (length = 0; length < 3 && name[length] != '\0'; ++length)
                {
                }
                VectorizedInvertedMemcpy(name, cache->unknown_10_, length);
                cache->unknown_14_ = length;
                cache->unknown_18_ = (void*)name;
            }
        }
        else
        {
            rest = 0;
        }

        if (rest >= 0x10)
        {
            var5 = (Struct_ov027_021d9e9c*)p;
            var5->unk_0 = 0;
            var5->unknown_4_ = header->unknown_20_ + (top + file->fileInfo.startOffset);
            var5->unknown_8_ = header->unknown_30_ + (top + file->fileInfo.startOffset);
            p += 0x10;
            rest -= 0x10;
        }
        else
        {
            rest = 0;
        }

        if (rest >= header->unknown_2c_ + header->unknown_3c_)
        {
            const int base = file->fileInfo.startOffset;
            NitroVM_Seek(file, var5->unknown_4_ - base, 0);
            NitroVM_ReadSync(file, p, header->unknown_2c_);
            func_ov027_021dd118(cache, var5->unknown_4_, header->unknown_2c_, p, 3);
            const unsigned long var13 = header->unknown_2c_;
            NitroVM_Seek(file, var5->unknown_8_ - base, 0);
            NitroVM_ReadSync(file, p + var13, header->unknown_3c_);
            func_ov027_021dd118(cache, var5->unknown_8_, header->unknown_3c_, p + var13, 3);
            ret = true;
        }
        else if (rest >= 0xcc00)
        {
            unsigned long offset;
            const unsigned long base = file->fileInfo.startOffset;
            offset = var5->unknown_4_;
            NitroVM_Seek(file, offset - base, 0);
            NitroVM_ReadSync(file, p, 0x4400);
            func_ov027_021dd118(cache, offset, 0x4400, p, 3);
            p += 0x4400;
            offset += 0x4400;
            NitroVM_Seek(file, offset - base, 0);
            NitroVM_ReadSync(file, p, 0x4400);
            func_ov027_021dd118(cache, offset, 0x4400, p, 2);
            p += 0x4400;
            offset += 0x4400;
            NitroVM_Seek(file, offset - base, 0);
            NitroVM_ReadSync(file, p, 0x4400);
            func_ov027_021dd118(cache, offset, 0x4400, p, 2);
            ret = true;
        }

        NitroVM_Seek(file, top, 0);

        if (var1)
        {
            NitroVM_FinishRead(&var9);
            if (ret)
            {
                Struct_ov027_021d9e9c_2 area;
                const unsigned long(*range)[2] = data_ov027_021dd8e4;
                area.top = header->unknown_20_;
                area.source = (unsigned char*)(header->unknown_28_ - header->unknown_20_);
                area.destination = cache->list[1].ptr - header->unknown_20_;
                area.len = len;
                func_ov027_021da314(&area, SECURE_AREA_START, SECURE_AREA_END, true);
                if ((*range)[1] != 0)
                {
                    do
                    {
                        func_ov027_021da314(&area, (*range)[0], (*range)[0] + (*range)[1], false);
                    } while ((*++range)[1] != 0);
                }
                unsigned char* dst = cache->list[1].ptr;
                dst += (unsigned long)AutoloadCallback - header->unknown_28_;
                *(unsigned long*)dst = 0xe12fff1e;
            }
        }
        if (ret)
            CleanInvalidateCacheRange(buffer, len);
    }
    return ret;
}
