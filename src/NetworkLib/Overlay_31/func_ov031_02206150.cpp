#include <globaldefs.h>
#include <NitroSDK/Mutex.h>

struct Struct_ov031_02206150_2 {
    unsigned char unknown_0_[0xe0];
    Mutex unknown_e0_;
};
struct Struct_ov031_02206150 {
    unsigned char unknown_0_[0x68];
    Struct_ov031_02206150_2* buffer;
    unsigned char unknown_6c_[4];
    volatile short state;
    signed char block;
    signed char kind;
};
extern "C" int func_ov031_02207180(void* v);
extern "C" int func_ov031_02206264(Struct_ov031_02206150* self, const unsigned char* source, int length, unsigned short tag, unsigned long arg4, long flags);

// USA: func_ov031_02206150
extern "C" ARM int func_ov031_02206150(Struct_ov031_02206150* self, const unsigned char* source, int length, unsigned short tag, unsigned long arg4, long flags) {
    Struct_ov031_02206150_2* buffer;
    int result;
    int var2;

    if (func_ov031_02207180(self)) return -28;
    {
        int var3 = 0;
        if (self != NULL) var3 = (self->state & 1) != 0;
        if (!var3) return -39;
    }
    {
        int stream = 1;
        signed char kind = self->kind;
        if (kind != 0 && kind != 4) stream = 0;
        if (stream) {
            if (!(self->state & 4) || (self->state & 8)) return -56;
        }
    }
    buffer = self->buffer;
    if ((flags & 4) || self->block == 0) {
        if (!TryLockMutex(&buffer->unknown_e0_)) return -6;
        var2 = 0;
    } else {
        LockMutex(&buffer->unknown_e0_);
        var2 = 1;
    }
    result = func_ov031_02206264(self, source, length, tag, arg4, var2);
    UnlockMutex(&buffer->unknown_e0_);
    return result;
}
