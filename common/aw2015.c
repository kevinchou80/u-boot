/*
 * pmic-core.c
 *
 * Copyright (C) 2016-2017 Realtek Semiconductor Corporation
 * Copyright (C) 2016-2017 Cheng-Yu Lee <cylee12@realtek.com>
 */
#include <common.h>
#include "../drivers/i2c/rtk_i2c-lib.h"
#include "aw2015.h"

#define AW2015_I2C_CH  5
#define AW2015_I2C_ADDR 0x64

static unsigned int aw2015_i2c_ch = AW2015_I2C_CH;
static unsigned int aw2015_addr = AW2015_I2C_ADDR;
static volatile int aw2015_i2c_init = 0;



int aw2015_init(void)
{
	if(!aw2015_i2c_init)
	{
		I2CN_Init(aw2015_i2c_ch);
		aw2015_i2c_init = 1;
	}
	return 0;
}

void aw2015_exit(void)
{
	if(aw2015_i2c_init)
	{
		aw2015_i2c_init = 0;
		I2CN_UnInit(aw2015_i2c_ch);
	}
}

int aw2015_write_reg(unsigned char reg, unsigned char val)
{
	unsigned char data[2] = { reg, val };
	int ret;

	if (!aw2015_i2c_init)
		return AW2015_ERR;

	ret = I2C_Write_EX(aw2015_i2c_ch, aw2015_addr, 2, data, NO_READ);
	if (ret) {
		return AW2015_ERR;
	}
	return 0;
}

int aw2015_read_reg(unsigned char reg, unsigned char *val)
{
	unsigned char out;
	int ret;

	ret = I2C_Write_EX(aw2015_i2c_ch, aw2015_addr, 1, &reg, NON_STOP);
	 
	ret = I2C_Read_EX(aw2015_i2c_ch, aw2015_addr, 1, &reg, 1, &out, NON_STOP);
	if (ret) {
		printf("[DBG] %s: I2C_Read_EX: ret = %d\n", __func__, ret);
		return AW2015_ERR;;
	}
	*val = out;

	return 0;
}


void aw2015_led3(void)
{
	aw2015_init();
	aw2015_write_reg(0x01, 0x01);
	aw2015_write_reg(0x06, 0x00);
	aw2015_write_reg(0x12, 0x80);
	aw2015_write_reg(0x1e, 0xff);
	aw2015_write_reg(0x07, 0x04);
}

void aw2015_led2(void)
{
	aw2015_init();
	aw2015_write_reg(0x07, 0x00);
	aw2015_write_reg(0x05, 0x00);
	aw2015_write_reg(0x11, 0x80);
	aw2015_write_reg(0x1d, 0xff);
	aw2015_write_reg(0x07, 0x02);
}

void aw2015_led2_blink(void)
{
	aw2015_init();
	aw2015_write_reg(0x07, 0x00);
	aw2015_write_reg(0x09, 0x20);
	aw2015_write_reg(0x05, 0x07);
	aw2015_write_reg(0x11, 0x80);
	aw2015_write_reg(0x07, 0x02);
	aw2015_write_reg(0x35, 0x13);
	aw2015_write_reg(0x36, 0x13);
	aw2015_write_reg(0x09, 0x02);
}
