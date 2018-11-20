#ifndef PAGE_MODULE_PMU_H
#define PAGE_MODULE_PMU_H

#include <include/object/Process.h>

extern Process pmu_new_process(Process process, VMModel *vm_model_pointer);

extern int pmu_halt_process(Process process,VMModel *vm_model_pointer);

extern void pmu_print_all_processes(VMModel *vm_model_pointer);

extern VMModel* pmu_free(VMModel *vm_model_pointer);


#endif


