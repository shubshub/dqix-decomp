#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct Struct_ov000_02169e80 {
    unsigned int unknown_0_;
    Struct_ov000_02169e80* next;
    short first;
    short second;
    int third;
};
struct Struct_ov000_02184264_4 {
    void* unknown_0_;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern Struct_ov000_02184264_4 data_ov000_02184264;
    void func_ov000_02169b78(Struct_ov000_02169e80*);
}

// USA: func_ov000_02169e80
extern "C" ARM int func_ov000_02169e80(Script::Parameter* parameters, int count)
{
    Struct_ov000_02169e80* command = static_cast<Struct_ov000_02169e80*>(
        data_ov000_02184264.allocator->Allocate(sizeof(Struct_ov000_02169e80)));
    command->unknown_0_ = 5;
    if (parameters->type == 2) {
        float value = parameters->ToFloat();
        parameters++;
        command->first = 4096.0f * value;
    } else if (parameters->type == 1) {
        int value = parameters->ToInt();
        parameters++;
        command->first = 4096.0f * (value / 1000.0f);
    }
    if (parameters->type == 2) {
        float value = parameters->ToFloat();
        parameters++;
        command->second = 4096.0f * value;
    } else if (parameters->type == 1) {
        int value = parameters->ToInt();
        parameters++;
        command->second = 4096.0f * (value / 1000.0f);
    }
    command->third = 4096.0f * parameters->ToFloat();
    func_ov000_02169b78(command);
    return 1;
}
