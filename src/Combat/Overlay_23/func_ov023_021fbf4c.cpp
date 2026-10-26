#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov023_021fbf4c
{
    int unk_0;
    SafeAllocator allocator_;
};

struct Struct_02000c9c_74
{
    char unk_0[0x18];
};

class Struct_ov023_021fbf4c_2
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short unknown_8_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* unknown_14_;
    void* unknown_18_;
    int state_;
    SafeAllocator allocator_;
    Struct_02000c9c_74 names_;
    int unknown_4c_;

    virtual void inline_ov023_021fbf4c(void* script);
};

struct Struct_ov023_021fbf4c_3;

extern "C" double _dadd(double a, double b);
extern "C" unsigned int func_0200af90(double value);
extern "C" Struct_ov023_021fbf4c_3* func_ov011_021849c8(void* script);
extern "C" int func_ov023_021f6bb8(Struct_ov023_021fbf4c_3* objects);
extern "C" void func_ov023_021f6bb0(Struct_ov023_021fbf4c_3* objects, int task);
extern "C" Struct_ov023_021fbf4c* func_ov011_021845f8(void* script, int heap);
extern "C" void func_020de888(Struct_02000c9c_74* names, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void func_020dea64(Struct_02000c9c_74* names, SafeAllocator* allocator, void* file, unsigned int size,
                              unsigned char* arg4, int count);

// USA: func_ov023_021fbf4c
extern "C" ARM int func_ov023_021fbf4c(Struct_ov023_021fbf4c_2* self, void* script)
{
#if defined(jpn)
 enum {regionalOffset0=0x19000};
#else
 enum {regionalOffset0=0x1a000};
#endif
    Struct_ov023_021fbf4c* heap;
    Struct_ov023_021fbf4c_3* objects = func_ov011_021849c8(script);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int task = func_ov023_021f6bb8(objects);
    if (loader->GetTaskStatus(task))
    {
        if (loader->GetDetailedTaskStatus(task) == 2)
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(task, &file, &size);
            heap = func_ov011_021845f8(script, self->unknown_8_);
            if (heap == NULL)
            {
                loader->RemoveTask(task);
                func_ov023_021f6bb0(objects, -1);
                return 2;
            }
            if (self->unknown_4c_ == 0)
            {
                self->allocator_.CreateTypeA(heap->allocator_.Allocate(regionalOffset0), regionalOffset0);
                self->allocator_.Reset();
                func_020de888(&self->names_, &self->allocator_, file, size);
            }
            else
            {
                unsigned int bytes = 0;
                short count = 0;
                unsigned char var8[12] = {0};
                if (self->unknown_4c_ & 1)
                {
#if defined(jpn)
                    bytes += 0x12c00;
#else
                    bytes = func_0200af90(_dadd(bytes, 79872.0));
#endif

                    for (short i = 0; i <= 7; i++)
                        var8[count++] = i;
                }
                if (self->unknown_4c_ & 2)
                {
#if defined(jpn)
                    bytes += 0x1c00;
#else
                    bytes = func_0200af90(_dadd(bytes, 7987.2));
#endif

                    var8[count++] = 8;
                }
                if (self->unknown_4c_ & 4)
                {
#if defined(jpn)
                    bytes += 0x1400;
#else
                    bytes = func_0200af90(_dadd(bytes, 4915.2));
#endif

                    var8[count++] = 9;
                }
                if (self->unknown_4c_ & 8)
                {
#if defined(jpn)
                    bytes += 0x4000;
#else
                    bytes = func_0200af90(_dadd(bytes, 15872.0));
#endif

                    var8[count++] = 11;
                }
                if (bytes > regionalOffset0)
                    bytes = regionalOffset0;
                self->allocator_.CreateTypeA(heap->allocator_.Allocate(bytes), bytes);
                self->allocator_.Reset();
                func_020dea64(&self->names_, &self->allocator_, file, size, var8, count);
            }
        }
        loader->RemoveTask(task);
        func_ov023_021f6bb0(objects, -1);
        return 2;
    }
    return self->state_;
}
