#ifndef VM_SEGMENT_MODULE_VMMU_H
#define VM_SEGMENT_MODULE_VMMU_H

#include<include/object/Process.h>

extern Process segment_vmmu_register_process(Process process,VMModel *vm_model_pointer);

extern Process segment_vmmu_unregister_process(Process process,VMModel *vm_model_pointer);

extern void segment_vmmu_print_all_segment_table_items(VMModel *vm_model_pointer);

extern VMModel* segment_vmmu_free(VMModel *vm_model_pointer);

#endif


