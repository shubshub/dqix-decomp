#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Vec3 { int x, y, z; };
extern "C" short func_ov017_021a4700(struct Vec3* p0, int arg1, struct Vec3* p2);
int fix32abs(int x);

// USA: func_ov017_021a4754
extern "C" ARM short func_ov017_021a4754(Vector3fix* arg0, int arg1, Vector3fix* arg2) {
	struct Vec3* p0 = (struct Vec3*)arg0;
	struct Vec3* p2 = (struct Vec3*)arg2;
	return (short)fix32abs(func_ov017_021a4700(p0, arg1, p2));
}
