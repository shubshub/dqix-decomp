#pragma once

struct MessageSystem;

extern "C" void func_02065990(MessageSystem* window, int ticks);
extern "C" void func_02043040(MessageSystem* window);
extern "C" void func_020430b0(MessageSystem* window);

#if defined(jpn)
extern "C" int func_02069430(void* unused, unsigned short token);
extern "C" int func_02069444(void* unused, unsigned short token);
#else
extern "C" bool func_02044494(void* unused, void* token);
extern "C" int func_02044420(void* unused, void* token);
#endif
