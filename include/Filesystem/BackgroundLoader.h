#pragma once

#include "ExtendedNitroVM.h"
#include "../NitroSDK/ProcessorContext.h"
#include "../Memory/SafeAllocator.h"

// sizeof == 0x794 == 1940 bytes. This struct is passed as the first
// parameter to various functions in the 0202fxxx range, and an instance
// of it is constructed in overlay 33's bss section (at 0x022a2a2c, usa).
// It does stuff related to file loading, a layer on top of ExtendedNitroVM.
// A pointer to this instance is then held at 0x02104308 (usa)
struct BackgroundLoader
{
    BackgroundLoader() { InitializeOrReset(); }
    ~BackgroundLoader() { InitializeOrReset(); }

    // sizeof == 0x44 == 68 bytes
    struct Task
    {
        char outerFilename_[0x18];
        char innerFilename_[0x18];
        short taskID_; // unrelated to nitro file ID or cache index
        char status_ : 4;
        char type_ : 4;
        unsigned char containerDirectoryIndex_; // this is indexing directories within data/
        SafeAllocator* externalAllocator_;
        void* pFileData;
        unsigned int fileLengthOrOverlayID_;
        struct ScratchSpaceAllocation {
            unsigned short firstWord_;
            unsigned short numWords_;
        }; 
        ScratchSpaceAllocation scratchAlloc_;

        // usa: _ZN16BackgroundLoader4Task14ZeroInitializeEv
        void ZeroInitialize();
        // usa: _ZN16BackgroundLoader4Task15GetFullFilenameEPc
        bool GetFullFilename(char* outBuffer);
    };

    enum TaskStatus
    {
        TaskStatus_Invalid = -1,
        TaskStatus_Unallocated = 0,
        TaskStatus_InFlight = 1,
        TaskStatus_Complete = 2,
        TaskStatus_DecompressionFailed = 3,
        TaskStatus_LoadFileFailed = 4,
        // if a fence task is in the queue, no later tasks will be processed
        // until all prior tasks have been removed / freed. Not sure why this
        // is a status and not a task type, but oh well
        TaskStatus_Fence = 5,
    };

    enum TaskType
    {
        TaskType_LoadFileDefault = 0, // seems to be regular file
        TaskType_LoadGP1 = 1, // only used in one place
        TaskType_LoadFromGP2 = 2,
        TaskType_LoadOverlay = 3, // never called in practice?
        TaskType_UnloadOverlay = 4, // never called in practice?
    };

    // I wanted to implement this as a pointer to a function pointer, but it
    // didn't match, whereas virtual stuff did. This is offset 0.
    virtual int Process() = 0;

    // points to 0x022a2a08, which in turn points to the function
    // func_ov_033_022a21a8. The context's execution repeatedly calls this function
    ProcessorContext context_;
    ExtendedNitroVM reader_;
    // The scratch space is used for two purposes. On the left, we have block-based
    // allocation, roughly like HPXEAllocator, used for files loaded without
    // a SafeAllocator, and on the right we have an arena that grows leftward
    // used by the processing thread to store GP2-related metadata. (Note that
    // only one archive's worth of metadata is ever in the arena at a time)
    void* scratchSpace_;
    volatile unsigned int scratchSpaceSize_;
    volatile int rightmostAllocationByte_;
    volatile unsigned int scratchRightArenaUsage_;
    // I think this is just for benchmarking / debugging, I don't see any reads
    // from it. It holds the maximum recorded value of (rightmostAllocationByte
    // + scratchRightArenaUsage), i.e. maximum historical memory usage.
    // It's initialized to 0x10000 (64k, 1/3 of the size used in practice).
    int unknown_120_;
    volatile int numPendingTasks_;
    Task queuedTasks_[24];
    // like a refcount, but works by going << 1 and | 1 to increment, >> 1 to decrement.
    // While nonzero, the processing thread will not do any tasks. This is useful
    // if e.g. you want to load a file into the same scratch space (see e.g.
    // DetailedTreasureMapData::LoadLegacyBossStats())
    volatile unsigned int processLockBits_;
    volatile int flags_78c_0_ : 1;
    volatile int flags_78c_1_ : 1;
    // might be something like 'scratch space allocation is up to date'
    volatile int flags_78c_2_ : 1;
    volatile int flags_78c_3_ : 1;
    volatile int flagMaybeGP2OperationInFlight_ : 1;
    int unknown_790_;

    // usa: _ZN16BackgroundLoader11GetInstanceEv
    static BackgroundLoader* GetInstance();
    // usa: _ZN16BackgroundLoader21FreeAllocationsGlobalEv
    static void FreeAllocationsGlobal();
    // usa: _ZN16BackgroundLoader13AddLockGlobalEv
    static void AddLockGlobal();
    // usa: _ZN16BackgroundLoader16RemoveLockGlobalEv
    static void RemoveLockGlobal();

    // usa: _ZN16BackgroundLoader17InitializeOrResetEv
    void InitializeOrReset();
    // usa: _ZN16BackgroundLoader8PopulateEPvji
    void Populate(void* scratchSpace, unsigned int scratchSize, int relativePrio);
    // usa: _ZN16BackgroundLoader7SuspendEv
    void Suspend();
    // usa: _ZN16BackgroundLoader7AddLockEv
    void AddLock();
    // usa: _ZN16BackgroundLoader10RemoveLockEv
    void RemoveLock();
    // usa: _ZN16BackgroundLoader14RemoveAllLocksEv
    void RemoveAllLocks();
    // usa: _ZN16BackgroundLoader13QueueFileTaskEPKciS1_P13SafeAllocator
    // If alloc is not null, the file will be loaded into dynamically allocated
    // memory from the allocator, otherwise, the scratch space will be used
    int QueueFileTask(const char* filename, int type, const char* innerFile, SafeAllocator* alloc);
    // usa: _ZN16BackgroundLoader16QueueOverlayTaskEjb
    // Queues a load or unload of an overlay.
    int QueueOverlayTask(unsigned int id, bool load);

    // usa: _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator
    int QueueLoadFile(const char* filename, SafeAllocator* alloc);
    // usa: _ZN16BackgroundLoader12QueueLoadGP1EPKcP13SafeAllocator
    int QueueLoadGP1(const char* filename, SafeAllocator* alloc);
    // usa: _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator
    int QueueLoadFileInGP2(const char* gp2, const char* innerFile, SafeAllocator* alloc);
    // usa: _ZN16BackgroundLoader16QueueLoadOverlayEj
    int QueueLoadOverlay(unsigned int id);
    // usa: _ZN16BackgroundLoader8AddFenceEv
    void AddFence();

    // usa: _ZN16BackgroundLoader13GetTaskStatusEi
    // -1 = failed, 0 = underway/queued maybe?, 1 = successfully completed
    int GetTaskStatus(int taskID);
    // usa: _ZN16BackgroundLoader6IsIdleEv
    int IsIdle();
    // usa: _ZN16BackgroundLoader21GetDetailedTaskStatusEi
    int GetDetailedTaskStatus(int taskID);

    // usa: _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj
    void GetLoadedFileByID(int taskID, void** outPtr, unsigned int* outLength);
    // usa: _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj
    // returns the ID of the task that loaded this file, or -1 if not loaded.
    int GetLoadedFileByName(const char* name, void** outPtr, unsigned int* outLength);
    // usa: _ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj
    // returns the ID of the task that loaded this file, or -1 if not loaded.
    int GetLoadedFileInArchive(const char* archive, const char* innerFile, void** outPtr, unsigned int* outLength);

    // usa: _ZN16BackgroundLoader10ClearQueueEv
    void ClearQueue();
    // usa: _ZN16BackgroundLoader15FreeAllocationsEv
    void FreeAllocations();
    // usa: _ZN16BackgroundLoader10RemoveTaskEi
    void RemoveTask(int taskID);

    // implicitly created: _ZN16BackgroundLoader4TaskaSERKS0_ = Task::operator=(const Task&)

    // usa: _ZN16BackgroundLoader17GetNumQueuedTasksEv
    int GetNumQueuedTasks();
    // usa: _ZN16BackgroundLoader15GetTaskFilenameEiPc
    // returns true if a task of the specified id was found
    bool GetTaskFilename(int taskID, char* outBuffer);

protected:
    // usa: _ZN16BackgroundLoader22AllocateInScratchSpaceEPNS_4Task22ScratchSpaceAllocationEj
    void* AllocateInScratchSpace(Task::ScratchSpaceAllocation* output, unsigned int allocSize);
    // usa: _ZN16BackgroundLoader16FreeScratchSpaceEPNS_4Task22ScratchSpaceAllocationE
    bool FreeScratchSpace(Task::ScratchSpaceAllocation* block);
    // usa: _ZN16BackgroundLoader15RefreshCountersEv
    void RefreshCounters();
};