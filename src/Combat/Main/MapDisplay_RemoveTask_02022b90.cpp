#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

// Removes a MapDisplay load task from the BackgroundLoader and marks it empty (-1)
// Main, originally ReleaseHandle02022b90 (USA 0x02022b90, EUR 0x02022ba0, JPN 0x02022624)
extern "C" ARM void MapDisplay_RemoveTask(void* unusedSelf, int* task) {
    ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->RemoveTask((int)(*task));
    *task = -1;
}
