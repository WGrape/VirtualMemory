#include <include/object/Process.h>
#include <vm/page/include/object/ProcessLinkedNode.h>

#ifndef VM_PAGE_MODULE_MMU_H
#define VM_PAGE_MODULE_MMU_H

extern int* mmu_alloc_memory();
extern void mmu_collec_memory(int *p);

extern Process mmu_load_process(Process process,VMModel *vm_model);
extern Process mmu_unload_process(Process process,VMModel *vm_model);

extern ProcessLinkedNode* mmu_alloc_process_linked_node();
extern ProcessLinkedNode* mmu_collec_process_linked_node(ProcessLinkedNode *p);

extern PageTableItemLinkedNode* mmu_alloc_page_table_item_linked_node();
extern PageTableItemLinkedNode* mmu_collec_page_table_item_linked_node(PageTableItemLinkedNode *p);

extern VMModel* mmu_free(VMModel *vm_model_pointer);



#endif