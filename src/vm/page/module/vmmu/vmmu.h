#ifndef MODULE_VMMU_H
#define MODULE_VMMU_H

#include<include/object/Process.h>

extern Process vmmu_register_process(Process process,VMModel *vm_model_pointer);

extern Process vmmu_unregister_process(Process process,VMModel *vm_model_pointer);

extern void vmmu_print_all_page_table_items(VMModel *vm_model_pointer);

extern VMModel* vmmu_free(VMModel *vm_model_pointer);

#endif


