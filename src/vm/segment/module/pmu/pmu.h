#ifndef VM_SEGMENT__MODULE_PMU_H
#define VM_SEGMENT__MODULE_PMU_H

#include <include/object/Process.h>
#include <vm/segment/include/object/SegmentVMModel.h>

extern Process segment_pmu_new_process(Process process, SegmentVMModel *vm_model_pointer);

extern int segment_pmu_halt_process(Process process,SegmentVMModel *vm_model_pointer);

extern void segment_pmu_print_all_processes(SegmentVMModel *vm_model_pointer);

extern SegmentVMModel* segment_pmu_free(SegmentVMModel *vm_model_pointer);


#endif


