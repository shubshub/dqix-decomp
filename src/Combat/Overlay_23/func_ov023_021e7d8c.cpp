#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0205d81c;
struct MessageSystem;

struct Struct_ov023_021e7d8c {
    char pad0[0x78];
    char window_[0x5d8 - 0x78];
    char* text_;
};

typedef void (Struct_ov023_021e7d8c::*Type_ov023_021e7d8c)();

struct Struct_ov023_021fd7cc {
    Type_ov023_021e7d8c unknown_0_[3];
};

struct Struct_ov023_021e7d8c_2 {
    short v[3];
};

struct Struct_ov023_021fd75c {
    char pad0[0x32];
    Struct_ov023_021e7d8c_2 y;
    char unknown_38_[0x6c - 0x38];
};

extern Struct_ov023_021fd7cc data_ov023_021fd7cc;
extern Struct_ov023_021fd75c data_ov023_021fd75c;

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void Window_SetPanePalette(Struct_0205d81c* window, int index, int value);

extern "C" {
void func_02046380(MessageSystem* messages);
void func_ov023_021e7cec(Struct_ov023_021e7d8c* self, int id, short x, short y);
void Window_OpenPane(void* window, char* text, int a, int b, int c, int d, int e, int f);
}

// USA: func_ov023_021e7d8c
extern "C" ARM void func_ov023_021e7d8c(Struct_ov023_021e7d8c* self)
{
    MessageSystem* messages = MessageSystem_GetInstance();
    Type_ov023_021e7d8c var1[3];
    *(Struct_ov023_021fd7cc*)var1 = data_ov023_021fd7cc;
    short y[3];
    *(Struct_ov023_021e7d8c_2*)y = data_ov023_021fd75c.y;
    for (unsigned char i = 0; i < 3; i++)
    {
        func_02046380(messages);
        func_ov023_021e7cec(self, i, 2, y[i]);
        memset(self->text_, 0, 0x960);
        (self->*var1[i])();
        Window_OpenPane(self->window_, self->text_, 0, 0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 3; i++)
        Window_SetPanePalette((Struct_0205d81c*)self->window_, (unsigned char)i, 0);
}
