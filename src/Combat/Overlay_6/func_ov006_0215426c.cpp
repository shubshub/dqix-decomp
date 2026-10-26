#include <globaldefs.h>
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

extern int data_ov006_02160380[3];
extern int data_ov006_0216038c[3];

struct Struct_ov006_0215426c {
	char pad0[0x8];
	unsigned int unknown_8_;
	char pad1[0xae - 0xc];
	unsigned char unknown_ae_;
};

// USA: func_ov006_0215426c
extern "C" ARM void func_ov006_0215426c(Struct_ov006_0215426c* o) {
	if (!(o->unknown_8_ & 0x10)) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (data_ov006_02160380[i] == ((o->unknown_8_ & 0x10) ? o->unknown_ae_ : -1) && data_ov006_0216038c[i] != 0) {
			GetCurrentPositionAndDirectionMatrices((Matrix4x3*)data_ov006_0216038c[i], (Matrix3x3*)NULL);
			const Matrix4x3* obj2 = RenderConfig::GetInverseViewMatrix();
			Mat4x3_Multiply((Matrix4x3*)data_ov006_0216038c[i], obj2, (Matrix4x3*)data_ov006_0216038c[i]);
		}
	}
}
