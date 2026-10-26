#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/GamecardBusOwnership.h"


struct Struct_ov031_0223b324_2 {
	void* unknown_0_;
	unsigned char pad0[0x84 - 4];
	void* unknown_84_;
	NitroHandle handle;
	unsigned short unknown_e4_;
};
struct Struct_ov031_02290d24 { Struct_ov031_0223b324_2* p; };
extern struct Struct_ov031_02290d24 data_ov031_02290d24;

extern "C" int func_ov031_0223b560(NitroVM* vm, int tag);
extern "C" int func_ov031_0223b614(NitroHandle*, const void*, unsigned int, unsigned int);
extern "C" ARM int func_ov031_0223b5c4(NitroHandle* a, void* b, unsigned int c, unsigned int d);

extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void HaltSystem(void);
extern "C" ARM void* func_ov031_0223beec(int n, int base, int stride);
extern "C" int func_020c7130(char*, const char*, ...);

extern const char data_ov031_0224c544[];
extern const char data_ov031_0224939c[];
extern const char data_ov031_0224c55c[];

struct Struct_ov031_0223b324 { unsigned int offset; unsigned int size; };

// USA: func_ov031_0223b324
extern "C" ARM void func_ov031_0223b324(void) {
	data_ov031_02290d24.p = (Struct_ov031_0223b324_2*)func_ov031_0223cf4c(0xe8, 4);

	NitroVM vm;
	NitroVM_Initialize(&vm);
	if (!NitroVM_PrepareReadFileByPath(&vm, data_ov031_0224c544))
		HaltSystem();

	data_ov031_02290d24.p->unknown_e4_ = GenerateLockOwnerID();
	void* image = (void*)vm.fileInfo.startOffset;
	Struct_ov031_0223b324 var2;
	NitroVM_ReadSync(&vm, &var2, 8);
	Struct_ov031_0223b324 var3;
	NitroVM_ReadSync(&vm, &var3, 8);
	NitroVM_FinishRead(&vm);

	NitroHandle_Initialize(&data_ov031_02290d24.p->handle);
	if (!NitroHandle_AddToHandleList(&data_ov031_02290d24.p->handle, data_ov031_0224939c, 3))
		HaltSystem();

	NitroHandle_SetOpcodeOverride(&data_ov031_02290d24.p->handle, func_ov031_0223b560, 0x602);

	if (!NitroHandle_Populate(&data_ov031_02290d24.p->handle, image,
			var3.offset, var3.size, var2.offset, var2.size,
			func_ov031_0223b5c4, func_ov031_0223b614))
		HaltSystem();

	unsigned int capacity = NitroHandle_LoadFileTables(&data_ov031_02290d24.p->handle, NULL, 0);
	data_ov031_02290d24.p->unknown_0_ = func_ov031_0223cf4c(capacity, 4);
	NitroHandle_LoadFileTables(&data_ov031_02290d24.p->handle, data_ov031_02290d24.p->unknown_0_, capacity);

	data_ov031_02290d24.p->unknown_84_ = func_ov031_0223beec(0x20, (int)data_ov031_02290d24.p + 4, 4);

	char buf[0x80];
	func_020c7130(buf, data_ov031_0224c55c, data_ov031_0224939c);
	SetROMFilesystemRoot(buf);
}
