#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov017_021c235c
extern "C" ARM void func_ov017_021c235c(char* self) {
	int list = (int)BackgroundLoader::GetInstance();
	short v = *(short*)(self + 8);
	if (v > -1) ((BackgroundLoader*)(list))->RemoveTask((int)(v));
}
