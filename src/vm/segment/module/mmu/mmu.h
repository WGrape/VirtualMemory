#ifndef VM_SEGMENT_MODULE_MMU_H
#define VM_SEGMENT_MODULE_MMU_H

#include <include/object/Process.h>
#include <vm/segment/include/object/SegmentProcessLinkedNode.h>
#include <vm/segment/include/object/SegmentTableItemLinkedNode.h>
#include <vm/segment/include/object/SegmentVMModel.h>


extern int* segment_mmu_alloc_memory();
extern void segment_mmu_collec_memory(int *p);

extern Process segment_mmu_load_process(Process process,SegmentVMModel *vm_model);
extern Process segment_mmu_unload_process(Process process,SegmentVMModel *vm_model);
extern SegmentVMModel* segment_mmu_free(SegmentVMModel *vm_model_pointer);


extern SegmentProcessLinkedNode* segment_mmu_alloc_process_linked_node();
extern SegmentProcessLinkedNode* segment_mmu_collec_process_linked_node(SegmentProcessLinkedNode *p);

extern SegmentTableItemLinkedNode* segment_mmu_alloc_segment_table_item_linked_node();
extern SegmentTableItemLinkedNode* segment_mmu_collec_segment_table_item_linked_node(SegmentTableItemLinkedNode *p);


#endif