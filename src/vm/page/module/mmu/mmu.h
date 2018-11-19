#include <include/object/Process.h>
#include <include/object/ProcessLinkedNode.h>

#ifndef VM_PAGE_MODULE_MMU_H
#define VM_PAGE_MODULE_MMU_H

extern int* mmu_alloc_memory();

extern void mmu_collec_memory(int *p);

extern ProcessLinkedNode* mmu_alloc_process_linked_node();

extern Process mmu_load_process(Process process,VMModel *vm_model);

extern Process mmu_unload_process(Process process,VMModel *vm_model);

#endif