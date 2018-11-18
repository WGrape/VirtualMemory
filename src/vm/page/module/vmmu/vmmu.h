#ifndef MODULE_VMMU_H
#define MODULE_VMMU_H


extern Process vmmu_register_process(Process process,VMModel vm_model);

extern Process vmmu_unregister_process(Process process,VMModel vm_model);

extern void vmmu_free();

#endif


