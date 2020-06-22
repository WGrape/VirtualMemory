#include <mmu/mmu.h>

void boot_setup();

/**
 * @function 完成底层配置
 * @param void
 * @return void
 */
void boot_setup() {

    mmu_ram_initialization();
}

/**
 * @function 初始化启动
 * @param void
 * @return void
 */
void boot_strap() {

    boot_setup();
}
