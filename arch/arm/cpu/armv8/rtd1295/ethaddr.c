
#include <linux/string.h>
#include <asm/arch/cpu.h>
#include <stdarg.h>
#include <vsprintf.h>

/*
 * Generate primary MAC address
 */
void gen_primary_mac(char *value)
{
	unsigned int sn = get_rtd129x_cpu_sn();
	sprintf(value, "02:%02x:%02x:%02x:%02x:20",
		sn & 0xff, (sn >> 8) & 0xff, (sn >> 16) & 0xff, (sn >> 24) & 0xff);
}
