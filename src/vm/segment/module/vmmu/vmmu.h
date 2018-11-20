#ifndef VM_SEGMENT_MODULE_VMMU_H
#define VM_SEGMENT_MODULE_VMMU_H

#include<include/object/Process.h>
#include <vm/segment/include/object/SegmentVMModel.h>


extern Process segment_vmmu_register_process(Process process,SegmentVMModel *vm_model_pointer);

extern Process segment_vmmu_unregister_process(Process process,SegmentVMModel *vm_model_pointer);

extern void segment_vmmu_print_all_segment_table_items(SegmentVMModel *vm_model_pointer);

extern SegmentVMModel* segment_vmmu_free(SegmentVMModel *vm_model_pointer);

#endif


