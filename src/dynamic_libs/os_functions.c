/****************************************************************************
 * Copyright (C) 2015
 * by Dimok
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 * must not claim that you wrote the original software. If you use
 * this software in a product, an acknowledgment in the product
 * documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 ***************************************************************************/
#include "../common/common.h"
#include "os_functions.h"

u32 coreinit_handle = 0;
// unsigned int zlib_handle = 0;

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Lib handle functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(int, OSDynLoad_Acquire, const char *rpl, u32 * handle);

EXPORT_DECL(int, OSDynLoad_FindExport, u32
		handle, int isdata, const char *symbol, void *address);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Security functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(int, OSGetSecurityLevel, void);

EXPORT_DECL(void, __OSSetCoreTrace, int core);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Thread functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(int, OSCreateThread, void *thread, s32(*callback)(s32, void * ), s32
		argc, void *args, u32
					stack, u32
					stack_size, s32
					priority, u32
					attr);

EXPORT_DECL(void, OSEnableInterrupts, void);

EXPORT_DECL(void, __OSClearAndEnableInterrupt, void);

EXPORT_DECL(int, OSIsInterruptEnabled, void);

EXPORT_DECL(int, OSIsDebuggerPresent, void);

EXPORT_DECL(void, OSRestoreInterrupts, void);

// EXPORT_DECL(bool, OSSendMessage, struct OSMessageQueue* mq, struct OSMessage* msg, s32 flags);

EXPORT_DECL(void, OSSetDABR, int, int, int, int);

EXPORT_DECL(void, OSSetIABR, int, int);

EXPORT_DECL(int, OSGetCurrentThread, void);

EXPORT_DECL(int, OSResumeThread, void *thread);

EXPORT_DECL(int, OSSleepThread, void *thread);

EXPORT_DECL(int, OSGetDefaultThread, int core);

EXPORT_DECL(int, OSWakeupThread, void *thread);

EXPORT_DECL(int, OSYieldThread, void);

EXPORT_DECL(void, OSSetThreadName, void *thread, const char *name);

EXPORT_DECL(int, OSSuspendThread, void *thread);

EXPORT_DECL(int, OSIsThreadTerminated, void *thread);

EXPORT_DECL(int, OSIsThreadSuspended, void *thread);

EXPORT_DECL(int, OSSetThreadPriority, void *thread, int priority);

EXPORT_DECL(int, OSJoinThread, void *thread, int *ret_val);

EXPORT_DECL(void, OSDetachThread, void *thread);

EXPORT_DECL(void, OSSleepTicks, u64
		ticks);

EXPORT_DECL(u64, OSGetTick, void);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Mutex functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(void, OSInitMutex, void *mutex);

EXPORT_DECL(void, OSLockMutex, void *mutex);

EXPORT_DECL(void, OSUnlockMutex, void *mutex);

EXPORT_DECL(int, OSTryLockMutex, void *mutex);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! System functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(u64, OSGetTitleID, void);

EXPORT_DECL(void, __Exit, void);

EXPORT_DECL(void, OSFatal, const char *msg);

EXPORT_DECL(void, OSSetExceptionCallback, u8 exceptionType, exception_callback callback);

EXPORT_DECL(void, OSSetExceptionCallbackEx, u8 exceptionMode, u8 exceptionType, exception_callback callback);

EXPORT_DECL(void, __OSSetInterruptHandler, u8 exceptionType, exception_callback callback);

EXPORT_DECL(void, DCFlushRange, const void *addr, u32
		length);

EXPORT_DECL(void, ICInvalidateRange, const void *addr, u32
		length);

EXPORT_DECL(void*, OSEffectiveToPhysical, const void*);

EXPORT_DECL(int, OSIsAddressValid, const void*);

EXPORT_DECL(int, __OSValidateAddressSpaceRange, int, void*, int);

EXPORT_DECL(int, __os_snprintf, char *s, int n, const char *format, ...);

EXPORT_DECL(int *, __gh_errno_ptr, void);

EXPORT_DECL(void, OSScreenInit, void);

EXPORT_DECL(void, OSScreenShutdown, void);

EXPORT_DECL(unsigned
					int, OSScreenGetBufferSizeEx, unsigned int bufferNum);

EXPORT_DECL(int, OSScreenSetBufferEx, unsigned int bufferNum, void *addr);

EXPORT_DECL(int, OSScreenClearBufferEx, unsigned int bufferNum, unsigned int temp);

EXPORT_DECL(int, OSScreenFlipBuffersEx, unsigned int bufferNum);

EXPORT_DECL(int, OSScreenPutFontEx, unsigned int bufferNum, unsigned int posX, unsigned int posY, const char *buffer);

EXPORT_DECL(int, OSScreenEnableEx, unsigned int bufferNum, int enable);

EXPORT_DECL(int, OSAllocFromSystem, unsigned int size, unsigned int align);

EXPORT_DECL(int, OSFreeToSystem, void *ptr);

EXPORT_DECL(void, DisassemblePPCRange, void *, void *, DisasmReport, DisasmGetSym, u32);

EXPORT_DECL(bool, DisassemblePPCOpcode, u32 *, char *, u32, DisasmGetSym, u32);

EXPORT_DECL(void*, OSGetSymbolName, u32, u8 *, u32);

EXPORT_DECL(int, OSIsDebuggerInitialized, void);

// EXPORT_DECL(int, compress2, char *, int*, const char *, int, int);

// !-------------

EXPORT_DECL(int, IOS_Ioctl, int fd, unsigned int request, void *input_buffer, unsigned int input_buffer_len,
			void *output_buffer, unsigned int output_buffer_len);

EXPORT_DECL(int, IOS_IoctlAsync, int fd, unsigned int request, void *input_buffer, unsigned int input_buffer_len,
			void *output_buffer, unsigned int output_buffer_len, void *cb, void *cbarg);

EXPORT_DECL(int, IOS_Open, char *path, unsigned int mode);

EXPORT_DECL(int, IOS_Close, int fd);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Memory functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_VAR(unsigned int *, pMEMAllocFromDefaultHeapEx);
EXPORT_VAR(unsigned int *, pMEMAllocFromDefaultHeap);
EXPORT_VAR(unsigned int *, pMEMFreeToDefaultHeap);

EXPORT_DECL(int, MEMGetBaseHeapHandle, int mem_arena);

EXPORT_DECL(unsigned
					int, MEMGetAllocatableSizeForFrmHeapEx, int heap, int align);

EXPORT_DECL(void *, MEMAllocFromFrmHeapEx, int heap, unsigned int size, int align);

EXPORT_DECL(void, MEMFreeToFrmHeap, int heap, int mode);

EXPORT_DECL(void *, MEMAllocFromExpHeapEx, int heap, unsigned int size, int align);

EXPORT_DECL(int, MEMCreateExpHeapEx, void *address, unsigned int size, unsigned short flags);

EXPORT_DECL(void *, MEMDestroyExpHeap, int heap);

EXPORT_DECL(void, MEMFreeToExpHeap, int heap, void *ptr);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! MCP functions
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(int, MCP_Open, void);

EXPORT_DECL(int, MCP_Close, int handle);

EXPORT_DECL(int, MCP_GetOwnTitleInfo, int handle, void *data);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Loader functions (not real rpl)
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(int, LiWaitIopComplete, int unknown_syscall_arg_r3, int *remaining_bytes);

EXPORT_DECL(int, LiWaitIopCompleteWithInterrupts, int unknown_syscall_arg_r3, int *remaining_bytes);

EXPORT_DECL(void, addr_LiWaitOneChunk, void);

EXPORT_DECL(void, addr_sgIsLoadingBuffer, void);

EXPORT_DECL(void, addr_gDynloadInitialized, void);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Kernel function addresses
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(void, addr_PrepareTitle_hook, void);

//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//! Other function addresses
//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXPORT_DECL(void, DCInvalidateRange, void *buffer, uint32_t
		length);

void InitAcquireOS(void) {
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Lib handle functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	EXPORT_FUNC_WRITE(OSDynLoad_Acquire, (int (*)(const char *, unsigned *)) OS_SPECIFICS->addr_OSDynLoad_Acquire);
	EXPORT_FUNC_WRITE(OSDynLoad_FindExport,
					  (int (*)(u32, int, const char *, void *)) OS_SPECIFICS->addr_OSDynLoad_FindExport);

	OSDynLoad_Acquire("coreinit.rpl", &coreinit_handle);
	// OSDynLoad_Acquire("zlib125.rpl", &zlib_handle);
}

void InitOSFunctionPointers(void) {
	unsigned int *funcPointer = 0;

	InitAcquireOS();

	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Security functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, OSGetSecurityLevel);
	OS_FIND_EXPORT(coreinit_handle, __OSSetCoreTrace);
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! System functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, OSFatal);
	OS_FIND_EXPORT(coreinit_handle, OSGetTitleID);
	OS_FIND_EXPORT(coreinit_handle, OSSetExceptionCallback);
	OS_FIND_EXPORT(coreinit_handle, OSSetExceptionCallbackEx);
	OS_FIND_EXPORT(coreinit_handle, __OSSetInterruptHandler);
	OS_FIND_EXPORT(coreinit_handle, DCFlushRange);
	OS_FIND_EXPORT(coreinit_handle, ICInvalidateRange);
	OS_FIND_EXPORT(coreinit_handle, OSEffectiveToPhysical);
	OS_FIND_EXPORT(coreinit_handle, OSIsAddressValid);
	OS_FIND_EXPORT(coreinit_handle, __OSValidateAddressSpaceRange);
	// OS_FIND_EXPORT(coreinit_handle, );
	OS_FIND_EXPORT(coreinit_handle, __os_snprintf);
	OS_FIND_EXPORT(coreinit_handle, __gh_errno_ptr);
	OS_FIND_EXPORT(coreinit_handle, OSAllocFromSystem);
	OS_FIND_EXPORT(coreinit_handle, OSFreeToSystem);
	OS_FIND_EXPORT(coreinit_handle, DisassemblePPCRange);
	OS_FIND_EXPORT(coreinit_handle, DisassemblePPCOpcode);
	OS_FIND_EXPORT(coreinit_handle, OSGetSymbolName);
	OS_FIND_EXPORT(coreinit_handle, OSIsDebuggerInitialized);
	// OS_FIND_EXPORT(zlib_handle, compress2);

	OSDynLoad_FindExport(coreinit_handle, 0, "_Exit", &__Exit);

	OS_FIND_EXPORT(coreinit_handle, OSScreenInit);
	OS_FIND_EXPORT(coreinit_handle, OSScreenShutdown);
	OS_FIND_EXPORT(coreinit_handle, OSScreenGetBufferSizeEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenSetBufferEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenClearBufferEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenFlipBuffersEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenPutFontEx);
	OS_FIND_EXPORT(coreinit_handle, OSScreenEnableEx);
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Thread functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, OSEnableInterrupts);
	OS_FIND_EXPORT(coreinit_handle, __OSClearAndEnableInterrupt);
	OS_FIND_EXPORT(coreinit_handle, OSIsInterruptEnabled);
	OS_FIND_EXPORT(coreinit_handle, OSIsDebuggerPresent);
	OS_FIND_EXPORT(coreinit_handle, OSRestoreInterrupts);
	// OS_FIND_EXPORT(coreinit_handle, OSSendMessage);
	OS_FIND_EXPORT(coreinit_handle, OSSetDABR);
	OS_FIND_EXPORT(coreinit_handle, OSSetIABR);
	OS_FIND_EXPORT(coreinit_handle, OSGetCurrentThread);
	OS_FIND_EXPORT(coreinit_handle, OSCreateThread);
	OS_FIND_EXPORT(coreinit_handle, OSResumeThread);
	OS_FIND_EXPORT(coreinit_handle, OSSleepThread);
	OS_FIND_EXPORT(coreinit_handle, OSGetDefaultThread);
	OS_FIND_EXPORT(coreinit_handle, OSWakeupThread);
	OS_FIND_EXPORT(coreinit_handle, OSSetThreadName);
	OS_FIND_EXPORT(coreinit_handle, OSYieldThread);
	OS_FIND_EXPORT(coreinit_handle, OSSuspendThread);
	OS_FIND_EXPORT(coreinit_handle, OSIsThreadTerminated);
	OS_FIND_EXPORT(coreinit_handle, OSIsThreadSuspended);
	OS_FIND_EXPORT(coreinit_handle, OSJoinThread);
	OS_FIND_EXPORT(coreinit_handle, OSSetThreadPriority);
	OS_FIND_EXPORT(coreinit_handle, OSDetachThread);
	OS_FIND_EXPORT(coreinit_handle, OSSleepTicks);
	OS_FIND_EXPORT(coreinit_handle, OSGetTick);
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Mutex functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, OSInitMutex);
	OS_FIND_EXPORT(coreinit_handle, OSLockMutex);
	OS_FIND_EXPORT(coreinit_handle, OSUnlockMutex);
	OS_FIND_EXPORT(coreinit_handle, OSTryLockMutex);
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! MCP functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, MCP_Open);
	OS_FIND_EXPORT(coreinit_handle, MCP_Close);
	OS_FIND_EXPORT(coreinit_handle, MCP_GetOwnTitleInfo);

	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Memory functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OSDynLoad_FindExport(coreinit_handle, 1, "MEMAllocFromDefaultHeapEx", &pMEMAllocFromDefaultHeapEx);
	OSDynLoad_FindExport(coreinit_handle, 1, "MEMAllocFromDefaultHeap", &pMEMAllocFromDefaultHeap);
	OSDynLoad_FindExport(coreinit_handle, 1, "MEMFreeToDefaultHeap", &pMEMFreeToDefaultHeap);

	OS_FIND_EXPORT(coreinit_handle, MEMGetBaseHeapHandle);
	OS_FIND_EXPORT(coreinit_handle, MEMGetAllocatableSizeForFrmHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMAllocFromFrmHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMFreeToFrmHeap);
	OS_FIND_EXPORT(coreinit_handle, MEMAllocFromExpHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMCreateExpHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMDestroyExpHeap);
	OS_FIND_EXPORT(coreinit_handle, MEMFreeToExpHeap);

	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Other function addresses
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	OS_FIND_EXPORT(coreinit_handle, DCInvalidateRange);

	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//! Special non library functions
	//!----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (OS_FIRMWARE == 532 || OS_FIRMWARE == 540) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100FFA4);                // loader.elf
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100FE90);  // loader.elf
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010007EC);              // loader.elf
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF18558);           // kernel.elf

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19D00);           // loader.elf
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE13C3C);         // loader.elf
	} else if (OS_FIRMWARE == 500 || OS_FIRMWARE == 510) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100FBC4);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100FAB0);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010007EC);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF18534);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19D00);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE13C3C);
	} else if (OS_FIRMWARE == 410) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100F78C);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100F678);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010007F8);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF166DC);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19CC0);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE13BFC);
	} else if (OS_FIRMWARE == 400) //same for 402 and 403
	{
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100F78C);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100F678);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010007F8);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF15E70);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19CC0);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE13BFC);
	} else if (OS_FIRMWARE == 550) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x01010180);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0101006C);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x0100080C);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF184E4);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19E80);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE13DBC);
	} else if (OS_FIRMWARE == 310) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100C4E4);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100C3D4);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010004D8);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF15A0C);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19340);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE1329C);
	} else if (OS_FIRMWARE == 300) {
		EXPORT_FUNC_WRITE(LiWaitIopComplete, (int (*)(int, int *)) 0x0100C4E4);
		EXPORT_FUNC_WRITE(LiWaitIopCompleteWithInterrupts, (int (*)(int, int *)) 0x0100C3D4);
		EXPORT_FUNC_WRITE(addr_LiWaitOneChunk, (int (*)(int, int *)) 0x010004D8);
		EXPORT_FUNC_WRITE(addr_PrepareTitle_hook, (int (*)(int, int *)) 0xFFF15974);

		EXPORT_FUNC_WRITE(addr_sgIsLoadingBuffer, (int (*)(int, int *)) 0xEFE19340);
		EXPORT_FUNC_WRITE(addr_gDynloadInitialized, (int (*)(int, int *)) 0xEFE1329C);
	} else {
		OSFatal("Missing all OS specific addresses.");
	}
}
