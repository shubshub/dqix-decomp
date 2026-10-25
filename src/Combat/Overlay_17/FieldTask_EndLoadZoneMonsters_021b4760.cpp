#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj021b4760 {
	char pad[0xc];
	int fieldc;
};

// Overlay 17, originally ClearFieldcIfSet_021b4760 (USA/EUR 0x021b4760, JPN 0x021b4e50)
ARM void FieldTask_EndLoadZoneMonsters(struct Obj021b4760* self) {
	int x = (int)BackgroundLoader::GetInstance();
	if (self->fieldc <= -1) {
		return;
	}
	((BackgroundLoader*)(x))->RemoveTask((int)(self->fieldc));
	self->fieldc = -1;
}
