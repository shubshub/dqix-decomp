#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x114
#else
#define REGION_FIELD 0x334
#endif

struct Struct_ov017_021bdbc0 { char pad[REGION_FIELD]; int value; };

// USA: func_ov017_021bdbc0
extern "C" ARM int func_ov017_021bdbc0(unsigned char* base) {
	Struct_ov017_021bdbc0* s = (Struct_ov017_021bdbc0*)(base + 0x4000);
	return s->value;
}
