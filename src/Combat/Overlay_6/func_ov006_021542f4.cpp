#include <globaldefs.h>

extern "C" void func_020a2010(void* objIn);
extern "C" void Camera_SetTarget(struct Camera* obj, int a, int b, int c);
extern "C" void FollowCamera_DisableFollow(void* obj);
extern "C" void Camera_SetOrbit(void*, int, int, int);
extern "C" void Camera_Update(void*);

// USA: func_ov006_021542f4
extern "C" ARM void func_ov006_021542f4(void *obj) {
	if (!obj) return;
	func_020a2010(obj);
	Camera_SetTarget((struct Camera*)obj, 0, 0xffffe171, 0);
	Camera_SetOrbit(obj, 0, 0x2eb8, 0xa000);
	Camera_Update(obj);
	FollowCamera_DisableFollow(obj);
}
