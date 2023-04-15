/*
 * APIs & helper macros for PMIC
 *
 * Copyright (C) 2016-2017 Realtek Semiconductor Corporation
 * Copyright (C) 2016-2017 Cheng-Yu Lee <cylee12@realtek.com>
 */
#ifndef __AW2015_H__
#define __AW2015_H__

/********************************************************************************
 * error code 
 ********************************************************************************/
#define AW2015_OK    0
#define AW2015_ERR  -1

int aw2015_init(void);
void aw2015_exit(void);
int aw2015_write_reg(unsigned char reg, unsigned char val);
int aw2015_read_reg(unsigned char reg, unsigned char *val);
void aw2015_led3(void);
#endif
