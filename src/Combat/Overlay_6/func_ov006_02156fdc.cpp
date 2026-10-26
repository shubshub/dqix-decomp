#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02156fdc_2196 = 0x714 };
#else
enum { Enum_ov006_02156fdc_2196 = 0x894 };
#endif

#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_02156e54_2 {
    char unk_0[0x70];
};

extern "C" void func_02076080(Struct_ov006_02156e54_2* graphics, SafeAllocator* allocator, void* file, unsigned int size);

struct Struct_ov006_02156e54 {
    Struct_ov006_02156e54_2 graphics_;
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

struct Struct_ov006_02154614 {
    char unk_0[Enum_ov006_02156fdc_2196];
    Struct_ov006_02156e54 ingredients_[4];
    SafeAllocator unknown_a84_[4];
};

// USA: func_ov006_02156fdc
extern "C" ARM void func_ov006_02156fdc(Struct_ov006_02154614* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Struct_ov006_02156e54* ingredient = self->ingredients_;
    for (unsigned char i = 0; i < 4; i++) {
        if (ingredient->loading_) {
            if (loader->GetTaskStatus(ingredient->task_)) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(ingredient->task_, &data, &size);
                if (data != 0) {
                    self->unknown_a84_[i].Reset();
                    func_02076080(&ingredient->graphics_, &self->unknown_a84_[i], data, size);
                }
                loader->RemoveTask(ingredient->task_);
                ingredient->task_ = -1;
                ingredient->loading_ = 0;
            }
            ingredient->x_ = 0x6f;
            ingredient->y_ = -0x1a;
        }
        ingredient++;
    }
}
