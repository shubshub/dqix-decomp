#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"
#include "Filesystem/BackgroundLoader.h"

struct BackgroundLoader;

// USA: func_0207f8bc
extern "C" ARM void func_0207f8bc(Manager0207f7f0 *self) {
	if (self->field1c >= 0) {
		BackgroundLoader *loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(self->field1c);
	}

#if !defined(jpn)
	for (int i = 0; i < 3; i++) {
		BackgroundLoader *loader = BackgroundLoader::GetInstance();
		int task = self->tasks[i];
		if (task >= 0) {
			loader->RemoveTask(task);
		}
	}
#endif

	func_0207f84c(self);
}
