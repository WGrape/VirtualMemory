#ifndef VM_SEGMENT__MODULE_PMU_H
#define VM_SEGMENT__MODULE_PMU_H

#include <include/object/Process.h>

extern Process segment_pmu_new_process(Process process, VMModel *vm_model_pointer);

extern int segment_pmu_halt_process(Process process,VMModel *vm_model_pointer);

extern void segment_pmu_print_all_processes(VMModel *vm_model_pointer);

extern VMModel* segment_pmu_free(VMModel *vm_model_pointer);


#endif


