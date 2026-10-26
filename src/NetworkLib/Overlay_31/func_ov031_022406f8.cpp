#include <globaldefs.h>

struct Struct_ov031_022406f8_2 {
    Struct_ov031_022406f8_2* next;
    unsigned char bytes[512];
};
struct Struct_ov031_022406f8 {
    int length;
    unsigned char unknown_4_[24];
    Struct_ov031_022406f8_2* next;
    unsigned char bytes[1024];
};
extern "C" void func_ov031_022415c8(void* destination, const void* source, unsigned int size);

// USA: func_ov031_022406f8
extern "C" ARM int func_ov031_022406f8(Struct_ov031_022406f8* buffer, unsigned char* destination, int offset, int size) {
    if (offset + size <= buffer->length) {
        if (size != 0) {
            if (offset < 1024) {
                int amount = 1024 - offset;
                if (size <= amount) amount = size;
                func_ov031_022415c8(destination, buffer->bytes + offset, amount);
                offset += amount;
                size -= amount;
                destination += amount;
            }
            if (size != 0) {
                int rest = offset - 1024;
                int var2 = rest >> 9;
                offset = rest & 511;
                int remaining = var2 - 1;
                Struct_ov031_022406f8_2* var4 = buffer->next;
                if (var2 != 0) {
                    do {
                        var4 = var4->next;
                    } while (remaining-- != 0);
                }
                if (size != 0) do {
                    int amount = 512 - offset;
                    if (size <= amount) amount = size;
                    func_ov031_022415c8(destination, var4->bytes + offset, amount);
                    offset = (offset + amount) & 511;
                    size -= amount;
                    destination += amount;
                    var4 = var4->next;
                } while (size != 0);
            }
        }
        return 1;
    }
    return 0;
}
