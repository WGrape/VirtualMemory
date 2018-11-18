#ifndef PAGE_MODULE_PMU_H
#define PAGE_MODULE_PMU_H

extern Process pmu_new_process(Process process,VMModel vm_model);

extern Process pmu_halt_process(Process process,VMModel vm_model);

extern void pmu_print_all_processes(PCB pcb);

extern void pmu_free();


#endif


