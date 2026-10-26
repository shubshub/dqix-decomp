#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct Struct_ov000_0216a208 {
    unsigned int unknown_0_;
    Struct_ov000_0216a208* next;
    short id;
    short unknown_a_;
    int unknown_c_[1];
    short unknown_10_[2];
};
struct Struct_ov000_02184264_4 {
    void* unknown_0_;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern Struct_ov000_02184264_4 data_ov000_02184264;
    void func_ov000_02169b78(Struct_ov000_0216a208*);
}

// USA: func_ov000_0216a208
extern "C" ARM int func_ov000_0216a208(Script::Parameter* parameters, int count)
{
    Struct_ov000_0216a208* command = static_cast<Struct_ov000_0216a208*>(
        data_ov000_02184264.allocator->Allocate(sizeof(Struct_ov000_0216a208)));
    command->unknown_0_ = 9;
    command->id = parameters[0].ToInt();
    if (count > 1) {
        Script::Parameter* second = &parameters[1];
        parameters += 2;
        command->unknown_a_ = second->ToInt();
        int i;
        int var3;
        int var4;
        var4 = 0;
        var3 = 0;
        for (i = 0; i < count - 2; i++) {
            if (parameters->type == 1) {
                command->unknown_10_[var3] = parameters->ToInt();
                parameters++;
                var3++;
            } else if (parameters->type == 2) {
                float value = parameters->ToFloat();
                parameters++;
                command->unknown_c_[var4] = 4096.0f * value;
                var4++;
            } else if (parameters->type == 0) {
                parameters++;
            }
        }
    } else {
        command->unknown_a_ = 0;
    }
    func_ov000_02169b78(command);
    return 1;
}
