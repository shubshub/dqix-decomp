#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct Struct_ov000_0216aed0 {
    unsigned int unknown_0_;
    Struct_ov000_0216aed0* next;
    unsigned char unknown_8_;
    unsigned char mode;
    unsigned char value;
    unsigned char unknown_b_;
    int unknown_c_;
    int field_0x10;
    Vector3fix position;
    unsigned char unknown_20_;
};
struct Struct_ov000_02184264_4 {
    void* unknown_0_;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern Struct_ov000_02184264_4 data_ov000_02184264;
    void func_ov000_02169b78(Struct_ov000_0216aed0*);
    void __clear(void* dst, unsigned int size);
}

// USA: func_ov000_0216aed0
extern "C" ARM int func_ov000_0216aed0(Script::Parameter* parameters, int count)
{
    Struct_ov000_0216aed0* command = static_cast<Struct_ov000_0216aed0*>(
        data_ov000_02184264.allocator->Allocate(sizeof(Struct_ov000_0216aed0)));
    command->unknown_0_ = 0;
    command->next = 0;
    command->unknown_0_ = 0x2a;
    command->unknown_8_ = parameters[0].ToInt();
    Script::Parameter* second = &parameters[1];
    parameters += 2;
    command->mode = second->ToInt();
    Vector3fix position;
    __clear(&position, sizeof(position));
    int index = 0;
    command->unknown_b_ = 0;
    command->field_0x10 = 0x666;
    command->unknown_c_ = 0x1266;
    if (command->mode == 7) {
        index = parameters->ToInt();
    } else if (command->mode == 8) {
        if (count >= 3) {
            parameters = parameters->ToVec3fix(&position);
        }
        if (count >= 4) {
            index = parameters->ToInt();
        }
    } else if (command->mode == 9) {
        Script::Parameter* next = parameters->ToVec3fix(&position);
        command->unknown_20_ = 0;
        if (count >= 6) {
            command->unknown_20_ = next->ToInt() != 0;
        }
    } else if (command->mode == 11) {
        parameters = parameters->ToVec3fix(&position);
        if (count >= 6) {
            command->unknown_b_ = parameters->ToInt();
            if (count >= 7) {
                command->field_0x10 = 4096.0f * parameters[1].ToFloat();
                command->unknown_c_ = 4096.0f * parameters[2].ToFloat();
            }
        }
    } else if (count >= 3) {
        parameters->ToVec3fix(&position);
    }
    command->value = index;
    command->position = position;
    func_ov000_02169b78(command);
    return 1;
}
