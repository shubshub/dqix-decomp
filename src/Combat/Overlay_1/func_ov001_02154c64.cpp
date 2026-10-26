#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define data_ov001_02164bd7 data_ov001_02166177
#endif
extern const char data_ov001_02164bd7[];

struct Struct_ov001_02154c64 {
    unsigned char type : 4;
    char pad1[0x8 - 0x1];
    char name[0x2c - 0x8];
    int taskId;
    char unknown_30_[0x31 - 0x30];
    unsigned char loaded;
    char unknown_32_[0x34 - 0x32];
    struct Struct_ov001_02154c64* next;
};

struct Struct_ov001_02154c64_2 {
    char pad0;
    char name[0x24 - 0x1];
    int taskId;
    struct Struct_ov001_02154c64_2* next;
    unsigned char loaded;
};

struct Struct_ov001_02154c64_3 {
#if defined(jpn)
    char pad0[0xcc];
#else
    char pad0[0xd0];
#endif
    struct Struct_ov001_02154c64* models;
    struct Struct_ov001_02154c64_2* files;
    char name[0xf4 - 0xd8];
    int taskId;
    char unknown_f8_[0x100 - 0xf8];
    unsigned char done;
};

// USA: func_ov001_02154c64
extern "C" ARM int func_ov001_02154c64(struct Struct_ov001_02154c64_3* self) {
    int count = 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Struct_ov001_02154c64* model = self->models;
    int queued = 0;

    while (model != NULL) {
        unsigned int type = model->type;
        if (!(type != 2 && type != 3 && type != 6 && type != 7 && type != 8) && model->loaded == 0) {
            if (type == 6) {
                model->taskId = loader->QueueLoadFileInGP2(data_ov001_02164bd7, model->name, NULL);
            } else {
                model->taskId = loader->QueueLoadFile(model->name, NULL);
            }
            count++;
            queued = 1;
            if (count == 5) {
                self->done = 0;
                return queued;
            }
        }
        model = model->next;
    }

    struct Struct_ov001_02154c64_2* file = self->files;
    while (file != NULL) {
        if (file->loaded == 0) {
            file->taskId = loader->QueueLoadFile(file->name, NULL);
            count++;
            queued = 1;
            if (count == 5) {
                self->done = 0;
                return queued;
            }
        }
        file = file->next;
    }

    if (self->name[0] != 0) {
        self->taskId = loader->QueueLoadFile(self->name, NULL);
        queued = 1;
    }
    self->done = 1;
    return queued;
}
