#include <globaldefs.h>

struct Struct_ov031_02241060_2 {
    Struct_ov031_02241060_2* next;
};

struct Struct_ov031_02241060 {
    char padding0[0x10];
    void* unknown_10_;
    void* unknown_14_;
    char unknown_18_[4];
    Struct_ov031_02241060_2* head;
};

extern "C" void (*data_ov031_02290fc8)(void*);

// USA: func_ov031_02241060
extern "C" ARM void func_ov031_02241060(Struct_ov031_02241060* buffer) {
    Struct_ov031_02241060_2* node = buffer->head;
    if (node != NULL) {
        do {
            Struct_ov031_02241060_2* next = node->next;
            data_ov031_02290fc8(node);
            buffer->head = next;
        } while ((node = buffer->head) != NULL);
    }
    if (buffer->unknown_10_ != NULL) data_ov031_02290fc8(buffer->unknown_10_);
    if (buffer->unknown_14_ != NULL) data_ov031_02290fc8(buffer->unknown_14_);
    data_ov031_02290fc8(buffer);
}
