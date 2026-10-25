#include <globaldefs.h>
#include <NitroSDK/Matrix.h>
#include <NitroSDK/NSBXX/RenderConfig.h>

#if defined(jpn)
#define func_0208b610 func_0208bf04
#endif

void RenderConfig_SetObjectRotation(void* rotation);
fix32_t fix32cos(int x);
fix32_t fix32sin(int x);
extern "C" void func_0208b548(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, unsigned int arg7);
extern "C" ARM void func_0208b588(unsigned int arg0, unsigned int arg1, unsigned int arg2,
                                  unsigned int arg3, unsigned int arg4, unsigned int arg5);

// USA: func_0208b610
extern "C" ARM void func_0208b610(Vector3fix v, unsigned short p, int a, int b, int c, short d) {
    RenderConfig::SetObjectPosition(&v);
    fix32_t cosine = fix32cos(d);
    fix32_t sine = fix32sin(d);
    Matrix3x3 rot;
    Mat3x3_WriteRotationY(&rot, sine, cosine);
    RenderConfig_SetObjectRotation(&rot);
    Vector3fix scale;
    scale.x = a;
    scale.y = b;
    scale.z = c;
    RenderConfig::SetObjectScale(&scale);
    RenderConfig::SubmitToFifo();
    func_0208b548(0, 0, 1, 1, 0, 0, 0, 0);
    func_0208b588(0, 0, 3, 0, 0, 0);
    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = arg1;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x04000504 = 0;
}
