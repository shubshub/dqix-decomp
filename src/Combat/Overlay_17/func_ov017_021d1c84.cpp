#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d1c84_10164 = 0x27f4, Enum_ov017_021d1c84_10166 = 0x27f6 };
#else
enum { Enum_ov017_021d1c84_10164 = 0x27b4, Enum_ov017_021d1c84_10166 = 0x27b6 };
#endif

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void* Zone3D_GetInstance(void);

struct Struct_ov017_021d1c84 { unsigned char pad[4]; unsigned char field4; unsigned char field5; };

// USA: func_ov017_021d1c84
extern "C" ARM void func_ov017_021d1c84(int unused0, Struct_ov017_021d1c84* obj, int unused1, int arg3, struct SearchStruct0202c1a4* search) {
	if (LinkSession_GetOwnSlot(search) == 0) return;
	unsigned char* base = (unsigned char*)Zone3D_GetInstance();
	*(unsigned short*)(base + Enum_ov017_021d1c84_10164) = obj->field4;
	*(unsigned short*)(base + Enum_ov017_021d1c84_10166) = obj->field5;
}
