#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov011_021849d8(void* p);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02185600
extern "C" ARM int func_ov011_02185600(unsigned int obj) {
    int key = func_ov011_021849d8(func_ov017_021b2164());
    int r = (int)BackgroundLoader::GetInstance();
    int x = ((BackgroundLoader*)(r))->GetTaskStatus((int)(key));
    func_ov011_02184c68(obj, x == 0);
    return 1;
}
