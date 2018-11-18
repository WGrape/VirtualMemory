#ifndef MODULE_VMMU_H
#define MODULE_VMMU_H


extern Process vmmu_register_process(Process process,VMModel *vm_model_pointer);

extern Process vmmu_unregister_process(Process process,VMModel *vm_model_pointer);

extern VMModel* vmmu_free(VMModel *vm_model_pointer);

#endif


