#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>

struct Struct_ov006_02153a78 {
    short unknown_0_[2];
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
};
struct Struct_ov006_0215759c { char unknown_0_[0x18]; short item; };
struct Struct_ov006_0215759c_2 { SafeAllocator allocator; char operation[0x24]; };
extern "C" {
extern "C" void* GameState_GetParty(GameState*);
extern "C" void ItemTable_Construct(void*);
extern "C" void func_0207cbe8(void*);
void func_0207d300(void*, short, signed char, int);
extern "C" void func_0207cc0c(void*);
extern "C" void func_02086d88(void*, short);
}
extern "C" ARM void func_ov006_0215759c(Struct_ov006_0215759c* state, Struct_ov006_02153a78* arg1, unsigned int count)
{
    GameState* game = GameState::GetInstance();
    void* inventory = GameState_GetParty(game);
    Struct_ov006_0215759c_2 context;
    context.allocator.ResetAllocatorPointer();
    ItemTable_Construct(context.operation);
    func_0207cbe8(&context);
    func_0207cbe8(&context);
    func_0207d300(&context, state->item, (signed char)count, 0);
    func_0207cc0c(&context);
    for (unsigned char var3 = 0; var3 < count; var3++) {
        for (unsigned char ingredient = 0; ingredient < arg1->unknown_a_0_; ingredient++) func_02086d88(inventory, arg1->unknown_4_);
        for (unsigned char ingredient = 0; ingredient < arg1->unknown_a_4_; ingredient++) func_02086d88(inventory, arg1->unknown_6_);
        for (unsigned char ingredient = 0; ingredient < arg1->unknown_b_0_; ingredient++) func_02086d88(inventory, arg1->unknown_8_);
    }
}
