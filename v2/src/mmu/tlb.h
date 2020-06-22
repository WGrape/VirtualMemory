#ifndef MODULE_TLB_H
#define MODULE_TLB_H

/*
 * 定义TLB缓存
 */

void flush_tlb_all(void);

/*
 * This interface flushes an entire user address space from the tlb
 */
void flush_tlb_mm(struct mm_struct *mm);

/*
 * remove the PAGE_SIZE sized translation from the TLB.
 */
void flush_tlb_page(struct vm_area_struct *vma, unsigned long addr);

/*
 * The software page tables for address space 'mm' for virtual addresses
 * in the range 'start' to 'end-1' are being torn down
 */
void flush_tlb_pgtables(struct mm_struct *mm, unsigned long start, unsigned long end)

#endif