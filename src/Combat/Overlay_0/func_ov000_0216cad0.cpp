#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct Struct_ov000_0216cad0 {
    unsigned int unknown_0_;
    Struct_ov000_0216cad0* next;
    short x;
    short y;
    short z;
    unsigned char type;
};
struct Struct_ov000_02184264_4 {
    void* unknown_0_;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern Struct_ov000_02184264_4 data_ov000_02184264;
    void func_ov000_02169b78(Struct_ov000_0216cad0*);
}

// USA: func_ov000_0216cad0
extern "C" ARM int func_ov000_0216cad0(Script::Parameter* parameters, int count)
{
    Struct_ov000_0216cad0* command = static_cast<Struct_ov000_0216cad0*>(
        data_ov000_02184264.allocator->Allocate(sizeof(Struct_ov000_0216cad0)));
    if (command == NULL) {
        return 0;
    }
    memset(command, 0, sizeof(Struct_ov000_0216cad0));
    int type = parameters->ToInt();
    parameters++;
    command->type = type;
    switch (type & 0xff) {
    case 0:
    case 2:
        command->x = 4096.0f * parameters[0].ToFloat();
        command->y = 4096.0f * parameters[1].ToFloat();
        command->z = 4096.0f * parameters[2].ToFloat();
        break;
    case 1:
    case 4:
        command->x = 0x28f;
        command->y = 0x1000;
        command->z = 0;
        if (count >= 2) {
            float scale = parameters->ToFloat();
            parameters++;
            command->x = FIX32_MULTIPLY(command->x, (int)(4096.0f * scale));
        }
        if (count >= 3) {
            float y = parameters->ToFloat();
            parameters++;
            command->y = 4096.0f * y;
        }
        if (count >= 4) {
            command->z = parameters->ToInt() << 12;
        }
        break;
    case 3:
        command->x = 1;
        command->y = 0;
        command->z = 0;
        if (count >= 2) {
            command->x = 4096.0f * parameters->ToFloat();
        }
        break;
    }
    command->unknown_0_ = 0x76;
    func_ov000_02169b78(command);
    return 1;
}
