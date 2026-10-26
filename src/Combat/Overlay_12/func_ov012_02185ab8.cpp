#include <globaldefs.h>

struct Struct_ov012_02185ab8
{
#if defined(jpn)
    char unknown0[0x90];
    char window[0xd0c - 0x90];
    char unknown_d28_[0x608];
    char unknown_1314_[0x1340 - 0x1314];
#else
    char unknown0[0xac];
    char window[0xd28 - 0xac];
    char unknown_d28_[0x60c];
    char unknown_1334_[0x1370 - 0x1334];
#endif
    unsigned char step;
    unsigned char state;
};

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc*);
struct Struct_ov002_02155f4c;
extern "C" void func_ov023_021e76a8(Struct_ov002_02155f4c*);
extern "C" unsigned int func_ov023_021e6b8c(Struct_ov012_02185ab8* editor);

// USA: func_ov012_02185ab8
#if defined(jpn)
extern "C" ARM void func_ov012_02185ab8(Struct_ov012_02185ab8* editor)
#else
extern "C" ARM unsigned int func_ov012_02185ab8(Struct_ov012_02185ab8* editor)
#endif
{
    func_ov023_021e76a8((Struct_ov002_02155f4c*)editor->unknown_d28_);
    if (editor->state != 0)
        Window_TransferLayers((Obj0205d2bc*)editor->window);
#if !defined(jpn)
    return func_ov023_021e6b8c(editor);
#endif
}
