#include <globaldefs.h>

extern "C" unsigned int MessageSystem_GetInstance();
extern "C" unsigned int func_020457e0(unsigned int);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_021884ac
extern "C" ARM unsigned int func_ov011_021884ac(unsigned int arg) {
    func_ov011_02184c68(arg, func_020457e0(MessageSystem_GetInstance()));
    return 1;
}
