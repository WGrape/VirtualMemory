#ifndef MODULE_PMU_H
#define MODULE_PMU_H

extern void pmu_new_process(Process process);

extern void pmu_halt_process(int process_id);

extern void pmu_print_all_processes();

#endif


