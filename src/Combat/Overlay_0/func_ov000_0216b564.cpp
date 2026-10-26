#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct Struct_ov000_0216b564 {
    unsigned int unknown_0_;
    Struct_ov000_0216b564* next;
    unsigned int unknown_8_0_ : 1;
    unsigned int primary : 15;
    unsigned int unknown_a_0_ : 1;
    unsigned int unknown_a_1_ : 1;
    unsigned int unknown_a_2_ : 14;
    unsigned int unknown_c_0_ : 15;
    unsigned int unknown_d_7_ : 17;
};
struct Struct_ov000_02184264_4 {
    void* unknown_0_;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern Struct_ov000_02184264_4 data_ov000_02184264;
    void func_ov000_02169b78(Struct_ov000_0216b564*);
}

extern "C" ARM int func_ov000_0216b564(Script::Parameter* parameters, int count)
{
    Struct_ov000_0216b564* command = static_cast<Struct_ov000_0216b564*>(
        data_ov000_02184264.allocator->Allocate(sizeof(Struct_ov000_0216b564)));
    if (!command)
        return 0;
    command->unknown_0_ = 0;
    command->next = NULL;
    command->unknown_0_ = 0x37;
    int primary = parameters[0].ToInt();
    if (primary < 0) {
        command->unknown_8_0_ = 0;
    } else if (primary == 0) {
        command->unknown_8_0_ = 1;
        command->primary = 1;
    } else {
        command->unknown_8_0_ = 1;
        command->primary = primary;
    }
    command->unknown_a_0_ = 1;
    command->unknown_a_1_ = 0;
    command->unknown_c_0_ = 0;
    if (count >= 2) {
        int var2 = parameters[1].ToInt();
        if (var2 >= 0) {
            command->unknown_a_0_ = 0;
            command->unknown_a_1_ = 1;
            command->unknown_c_0_ = var2;
        } else if (var2 != -2) {
            command->unknown_a_0_ = 0;
            command->unknown_a_1_ = 0;
            command->unknown_c_0_ = 0;
        }
    }
    func_ov000_02169b78(command);
    return 1;
}
