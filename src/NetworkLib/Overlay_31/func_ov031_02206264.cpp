#include <globaldefs.h>

struct Struct_ov031_02206264_3 {
    unsigned char unknown_0_[0x48];
    int capacity;
};
struct Struct_ov031_02206264 {
    unsigned char unknown_0_[0x10c];
    Struct_ov031_02206264_3* unknown_10c_;
};
struct Struct_ov031_02206264_2 {
    unsigned char unknown_0_[0x68];
    Struct_ov031_02206264* buffer;
    unsigned char unknown_6c_[7];
    signed char mode;
};
extern "C" int func_ov031_02206368(Struct_ov031_02206264_2* self, int arg1, int max, int* out, int flags);
extern "C" int func_ov031_02206410(Struct_ov031_02206264_2* self, const unsigned char* source, int length, int offset, unsigned short tag, unsigned int arg5, int flags);

// USA: func_ov031_02206264
extern "C" ARM int func_ov031_02206264(Struct_ov031_02206264_2* self, const unsigned char* source, int length, unsigned short tag, unsigned int arg4, int flags) {
    int n;
    int total = 0;
    int capacity = self->buffer->unknown_10c_->capacity;
    int var3;
    int offset;

    if (self->mode == 1) {
        if (length > capacity - 42) return total - 35;
        var3 = length;
    } else {
        var3 = capacity - 54;
        if (length <= var3) var3 = length;
    }
    while (length > 0) {
        n = func_ov031_02206368(self, length, var3, &offset, flags);
        if (n > 0) {
            if (func_ov031_02206410(self, source, n, offset, tag, arg4, flags) <= 0) return -6;
            source += n;
            length -= n;
            total += n;
        }
        if (!(flags & 1)) {
            if (n > 0) break;
            return -6;
        }
    }
    return total;
}
