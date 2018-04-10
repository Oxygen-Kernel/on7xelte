#ifndef __S6E3AA2_A3XE_PARAM_H__
#define __S6E3AA2_A3XE_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e3aa2_ams474kf09.h"

#define EXTEND_BRIGHTNESS	365
#define UI_MAX_BRIGHTNESS	255
#define UI_MIN_BRIGHTNESS	0
#define UI_DEFAULT_BRIGHTNESS	128
#define NORMAL_TEMPERATURE	25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT				ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET)
#define ACL_CMD_CNT					ARRAY_SIZE(SEQ_ACL_OFF)
#define OPR_CMD_CNT					ARRAY_SIZE(SEQ_ACL_OPR_OFF)
#define ELVSS_CMD_CNT				ARRAY_SIZE(SEQ_ELVSS_SET)
#define AID_CMD_CNT					ARRAY_SIZE(SEQ_AID_SETTING)

#define LDI_REG_ELVSS				0xB5
#define LDI_REG_COORDINATE			0xA1
#define LDI_REG_DATE				LDI_REG_COORDINATE
#define LDI_REG_ID					0x04
#define LDI_REG_CHIP_ID				0xD6
#define LDI_REG_MTP					0xC8
#define LDI_REG_HBM					0xB3
#define LDI_REG_RDDPM				0x0A
#define LDI_REG_RDDSM				0x0E
#define LDI_REG_ESDERR				0xEE
#define LDI_REG_MANUFACTURE_INFO	0xC9

/* len is read length */
#define LDI_LEN_ELVSS				(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE			4
#define LDI_LEN_DATE				7
#define LDI_LEN_ID					3
#define LDI_LEN_CHIP_ID				5
#define LDI_LEN_MTP					35
#define LDI_LEN_HBM					31
#define LDI_LEN_RDDPM				1
#define LDI_LEN_RDDSM				1
#define LDI_LEN_ESDERR				1
#define LDI_LEN_MANUFACTURE_INFO	21

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	10
#define LDI_OFFSET_AOR_2	11

#define LDI_OFFSET_ELVSS_1	2	/* B5h 2nd Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	3	/* B5h 3rd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	23	/* B5h 23th Para: ELVSS Temp Compensation */
#define LDI_OFFSET_ELVSS_4	30	/* B5h 30th Para: TSET Setting */

#define LDI_OFFSET_OPR_1	1	/* B4h 1st Para: Frame Avg. */
#define LDI_OFFSET_OPR_2	2	/* B4h 2nd Para: Start Point */
#define LDI_OFFSET_OPR_3	4	/* B4h 22nd Para: ACL Percent */

#define LDI_OFFSET_ACL		1

#define LDI_GPARA_DATE		4	/* 0xA1 5th para */
#define LDI_GPARA_HBM_ELVSS	23	/* 0xB5 24th para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_MEM_ACCESS_2C[] = {
	0x2C
};

static unsigned char SEQ_MEM_ACCESS_3C[] = {
	0x3C
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00
};
#if 0
static unsigned char SEQ_PCD_SET_DET_LOW[] = {
	0xCC,
	0x5C
};
#endif
static unsigned char SEQ_ERR_FG_SETTING[] = {
	0xED,
	0x44
};

static unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x00, 0x00
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB1,
	0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00,
	0x0C
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB5,
	0xA0,
	0x1C,	/* B5h 2nd Para: MPS_CON */
	0x4A,	/* B5h 3rd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00,
	0x00,	/* B5h 23rd Para: ELVSS Temp Compensation */
	0x00,	/* B5h 24th Para: HBM Interpolation OTP */
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x19	/* B5h 30th Para: TSET Setting */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_ACL_OPR_OFF[] = {
	0xB4,
	0x40,	/* 16 Frame Avg. at ACL Off */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OPR_08P[] = {
	0xB4,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x99,	/* Start Point 60% */
	0x14,
	0x0A	/* ACL 8% */
};

static unsigned char SEQ_ACL_OPR_15P[] = {
	0xB4,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 8% (Default) */
};

static const unsigned char SEQ_TSET_SETTING_1[] = {
	0xB0,
	0x1D
};

static const unsigned char SEQ_TSET_SETTING_2[] = {
	0xB5,
	0x19
};

#ifdef CONFIG_LCD_DOZE_MODE
enum {
	ALPM_OFF,
	ALPM_ON_LOW,	/* ALPM 2 NIT */
	HLPM_ON_LOW,	/* HLPM 2 NIT */
	ALPM_ON_HIGH,	/* ALPM 60 NIT */
	HLPM_ON_HIGH,	/* HLPM 60 NIT */
	ALPM_MODE_MAX
};

static const unsigned char SEQ_SELECT_HLPM_60NIT[] = {
	0xBB,
	0x14, 0x00, 0x04, 0x0C			/* 0x14 : HLPM Mode */
};

static const unsigned char SEQ_SELECT_ALPM_60NIT[] = {
	0xBB,
	0x84, 0x00, 0x04, 0x0C			/* 0x84 : ALPM Mode */
};

static const unsigned char SEQ_SELECT_HLPM_02NIT[] = {
	0xBB,
	0x54, 0x00, 0x04, 0x0C			/* 0x54 : HLPM Mode */
};

static const unsigned char SEQ_SELECT_ALPM_02NIT[] = {
	0xBB,
	0xC4, 0x00, 0x04, 0x0C			/* 0xC4 : ALPM Mode */
};

static const unsigned char SEQ_SELECT_60NIT_ON[] = {
	0x53,
	0x02			/* 0x02 : HLPM/ALPM 60nit On */
};

static const unsigned char SEQ_SELECT_02NIT_ON[] = {
	0x53,
	0x03			/* 0x03 : HLPM/ALPM 2nit On */
};

static const unsigned char SEQ_LTPS_EQ[] = {
	0xFD,
	0x6A, 0x08, 0x06, 0x04, 0x65, 0x00, 0x00, 0x07,
	0x00, 0x00, 0xAA, 0xAA, 0xAA, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40, 0x5A, 0x80, 0x17, 0x25,
	0x6E, 0xA5, 0x55, 0x85, 0x00, 0x41, 0x01,
};

static const unsigned char SEQ_ALPM_OFF[] = {
	0x53,
	0x00
};
#endif

enum {
	ACL_STATUS_OFF,
	ACL_STATUS_ON,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_OFF,
	OPR_STATUS_08P,
	OPR_STATUS_15P,
	OPR_STATUS_MAX
};

enum {
	CAPS_OFF,
	CAPS_ON,
	CAPS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_ACL_OPR_OFF, SEQ_ACL_OPR_08P, SEQ_ACL_OPR_15P};

static unsigned char elvss_mpscon_offset_data[IBRIGHTNESS_HBM_MAX][4] = {
	[IBRIGHTNESS_002NIT] = {0xB5, 0xA0, 0x0C, 0x41},
	[IBRIGHTNESS_003NIT] = {0xB5, 0xA0, 0x0C, 0x42},
	[IBRIGHTNESS_004NIT] = {0xB5, 0xA0, 0x0C, 0x43},
	[IBRIGHTNESS_005NIT] = {0xB5, 0xA0, 0x0C, 0x44},
	[IBRIGHTNESS_006NIT] = {0xB5, 0xA0, 0x0C, 0x49},
	[IBRIGHTNESS_007NIT] = {0xB5, 0xA0, 0x0C, 0x4D},
	[IBRIGHTNESS_008NIT] = {0xB5, 0xA0, 0x0C, 0x50},
	[IBRIGHTNESS_009NIT] = {0xB5, 0xA0, 0x0C, 0x51},
	[IBRIGHTNESS_010NIT] = {0xB5, 0xA0, 0x0C, 0x51},
	[IBRIGHTNESS_011NIT] = {0xB5, 0xA0, 0x0C, 0x52},
	[IBRIGHTNESS_012NIT] = {0xB5, 0xA0, 0x0C, 0x52},
	[IBRIGHTNESS_013NIT] = {0xB5, 0xA0, 0x0C, 0x53},
	[IBRIGHTNESS_014NIT] = {0xB5, 0xA0, 0x0C, 0x53},
	[IBRIGHTNESS_015NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_016NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_017NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_019NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_020NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_021NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_022NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_024NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_025NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_027NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_029NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_030NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_032NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_034NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_037NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_039NIT] = {0xB5, 0xA0, 0x0C, 0x54},
	[IBRIGHTNESS_041NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_044NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_047NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_050NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_053NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_056NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_060NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_064NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_068NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_072NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_077NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_082NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_087NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_093NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_098NIT] = {0xB5, 0xA0, 0x1C, 0x53},
	[IBRIGHTNESS_105NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_111NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_119NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_126NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_134NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_143NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_152NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_162NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_172NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_183NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_195NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_207NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_220NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_234NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_249NIT] = {0xB5, 0xA0, 0x1C, 0x50},
	[IBRIGHTNESS_265NIT] = {0xB5, 0xA0, 0x1C, 0x50},
	[IBRIGHTNESS_282NIT] = {0xB5, 0xA0, 0x1C, 0x4F},
	[IBRIGHTNESS_300NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_316NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_333NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_350NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_357NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_365NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_372NIT] = {0xB5, 0xA0, 0x1C, 0x4C},
	[IBRIGHTNESS_380NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_387NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_395NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_403NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_412NIT] = {0xB5, 0xA0, 0x1C, 0x4A},
	[IBRIGHTNESS_420NIT] = {0xB5, 0xA0, 0x1C, 0x4A},
	[IBRIGHTNESS_443NIT] = {0xB5, 0xA0, 0x1C, 0x54},
	[IBRIGHTNESS_465NIT] = {0xB5, 0xA0, 0x1C, 0x52},
	[IBRIGHTNESS_488NIT] = {0xB5, 0xA0, 0x1C, 0x51},
	[IBRIGHTNESS_510NIT] = {0xB5, 0xA0, 0x1C, 0x4F},
	[IBRIGHTNESS_533NIT] = {0xB5, 0xA0, 0x1C, 0x4E},
	[IBRIGHTNESS_555NIT] = {0xB5, 0xA0, 0x1C, 0x4D},
	[IBRIGHTNESS_578NIT] = {0xB5, 0xA0, 0x1C, 0x4B},
	[IBRIGHTNESS_600NIT] = {0xB5, 0xA0, 0x1C, 0x4A}
};

struct elvss_otp_info {
	unsigned int	nit;
	int not_otp[TEMP_MAX];
};

struct elvss_otp_info elvss_otp_data[IBRIGHTNESS_MAX] = {
	[IBRIGHTNESS_002NIT] = {2,	{-1, -1, -1} },
};

static unsigned char AOR_TABLE[EXTEND_BRIGHTNESS + 1][AID_CMD_CNT] = {
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x0D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x06},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x03},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0xA0, 0x01},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xFF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xFD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xEF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xED},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xE3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xE1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xE0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xDF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xDD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xD6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xD3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xD1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xCF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xCD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xCC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xC3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xC1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xBF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xBD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xB8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xB3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xB2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xAF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xAD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xA6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xA1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0xA0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x9F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x9E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x9B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x98},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x94},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x91},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x8E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x8A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x86},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x83},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x7E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x7C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x79},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x77},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x74},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x72},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x70},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x6D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x6A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x66},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x63},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x5E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x59},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x54},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x4F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x4C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x49},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x45},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x42},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x3E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x3B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x37},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x34},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x32},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x31},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x2F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x2E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x28},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x21},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x1B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x14},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x13},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x11},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x10},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x0E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x07},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x80, 0x01},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xFA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xF3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xEE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xE9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xE5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xE0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xDD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xD9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xD6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xD2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xCD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xCD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xC6},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xBF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xB8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xB2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xAB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x9C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x94},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x8B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x83},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x7E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x79},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x75},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x70},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x69},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x62},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x5B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x54},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x4C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x44},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x3C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x34},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x2B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x23},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x1B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x12},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x0A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x60, 0x02},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xFA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xF2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xE1},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xD0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xBF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0xAE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x97},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x68},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x50},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x39},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x21},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x40, 0x09},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xF0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD8},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xD9},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDA},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xDC},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xC2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xB2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0xA2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x93},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x83},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x74},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x65},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x56},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x47},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x36},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x25},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x14},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x20, 0x03},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xF2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xE0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xCF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xBD},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x92},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x92},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB5},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x92},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xBB},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAF},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA3},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x98},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x98},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xB0},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA4},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x98},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xAE},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0xA2},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x97},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8B},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x91},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x86},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x93},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x8D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x86},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x80},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x7A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x73},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x6D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x66},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x5F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x58},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x51},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x4C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x47},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x42},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x3D},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x34},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x2C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x23},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1F},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x19},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x12},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x21},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1A},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x13},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x1E},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x18},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x12},
	{0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C},
	[UI_MAX_BRIGHTNESS ... EXTEND_BRIGHTNESS] = {0xB1, 0xFF, 0x20, 0x1A, 0x33, 0x5E, 0x8C, 0xB3, 0xD9, 0xFF, 0x00, 0x0C}
};

/* platform brightness <-> acl opr and percent */
static unsigned int brightness_opr_table[ACL_STATUS_MAX][EXTEND_BRIGHTNESS + 1] = {
	{
		[0 ... UI_MAX_BRIGHTNESS - 1]	= OPR_STATUS_15P,
		[UI_MAX_BRIGHTNESS ... 281]		= OPR_STATUS_OFF,	/* 420 */
		[282 ... EXTEND_BRIGHTNESS]		= OPR_STATUS_08P
	}, {
		[0 ... 281]						= OPR_STATUS_15P,
		[282 ... EXTEND_BRIGHTNESS]		= OPR_STATUS_08P
	}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 0] =		IBRIGHTNESS_002NIT,
	[1 ... 4] =		IBRIGHTNESS_003NIT,
	[5 ... 8] =		IBRIGHTNESS_004NIT,
	[9 ... 12] =		IBRIGHTNESS_005NIT,
	[13 ... 16] =		IBRIGHTNESS_006NIT,
	[17 ... 20] =		IBRIGHTNESS_007NIT,
	[21 ... 24] =		IBRIGHTNESS_008NIT,
	[25 ... 28] =		IBRIGHTNESS_009NIT,
	[29 ... 32] =		IBRIGHTNESS_010NIT,
	[33 ... 36] =		IBRIGHTNESS_011NIT,
	[37 ... 40] =		IBRIGHTNESS_012NIT,
	[41 ... 44] =		IBRIGHTNESS_013NIT,
	[45 ... 48] =		IBRIGHTNESS_014NIT,
	[49 ... 52] =		IBRIGHTNESS_015NIT,
	[53 ... 56] =		IBRIGHTNESS_016NIT,
	[57 ... 60] =		IBRIGHTNESS_017NIT,
	[61 ... 64] =		IBRIGHTNESS_019NIT,
	[65 ... 68] =		IBRIGHTNESS_020NIT,
	[69 ... 72] =		IBRIGHTNESS_021NIT,
	[73 ... 76] =		IBRIGHTNESS_022NIT,
	[77 ... 80] =		IBRIGHTNESS_024NIT,
	[81 ... 84] =		IBRIGHTNESS_025NIT,
	[85 ... 88] =		IBRIGHTNESS_027NIT,
	[89 ... 92] =		IBRIGHTNESS_029NIT,
	[93 ... 96] =		IBRIGHTNESS_030NIT,
	[97 ... 100] =		IBRIGHTNESS_032NIT,
	[101 ... 104] =		IBRIGHTNESS_034NIT,
	[105 ... 108] =		IBRIGHTNESS_037NIT,
	[109 ... 112] =		IBRIGHTNESS_039NIT,
	[113 ... 116] =		IBRIGHTNESS_041NIT,
	[117 ... 120] =		IBRIGHTNESS_044NIT,
	[121 ... 124] =		IBRIGHTNESS_047NIT,
	[125 ... 128] =		IBRIGHTNESS_050NIT,
	[129 ... 130] =		IBRIGHTNESS_053NIT,
	[131 ... 132] =		IBRIGHTNESS_056NIT,
	[133 ... 134] =		IBRIGHTNESS_060NIT,
	[135 ... 136] =		IBRIGHTNESS_064NIT,
	[137 ... 138] =		IBRIGHTNESS_068NIT,
	[139 ... 140] =		IBRIGHTNESS_072NIT,
	[141 ... 142] =		IBRIGHTNESS_077NIT,
	[143 ... 144] =		IBRIGHTNESS_082NIT,
	[145 ... 146] =		IBRIGHTNESS_087NIT,
	[147 ... 148] =		IBRIGHTNESS_093NIT,
	[149 ... 150] =		IBRIGHTNESS_098NIT,
	[151 ... 152] =		IBRIGHTNESS_105NIT,
	[153 ... 154] =		IBRIGHTNESS_111NIT,
	[155 ... 156] =		IBRIGHTNESS_119NIT,
	[157 ... 158] =		IBRIGHTNESS_126NIT,
	[159 ... 160] =		IBRIGHTNESS_134NIT,
	[161 ... 162] = 	IBRIGHTNESS_143NIT,
	[163 ... 164] = 	IBRIGHTNESS_152NIT,
	[165 ... 166] = 	IBRIGHTNESS_162NIT,
	[167 ... 168] = 	IBRIGHTNESS_172NIT,
	[169 ... 170] = 	IBRIGHTNESS_183NIT,
	[171 ... 174] = 	IBRIGHTNESS_195NIT,
	[175 ... 178] = 	IBRIGHTNESS_207NIT,
	[179 ... 182] = 	IBRIGHTNESS_220NIT,
	[183 ... 186] = 	IBRIGHTNESS_234NIT,
	[187 ... 190] = 	IBRIGHTNESS_249NIT,
	[191 ... 194] = 	IBRIGHTNESS_265NIT,
	[195 ... 198] = 	IBRIGHTNESS_282NIT,
	[199 ... 204] = 	IBRIGHTNESS_300NIT,
	[205 ... 209] = 	IBRIGHTNESS_316NIT,
	[210 ... 214] = 	IBRIGHTNESS_333NIT,
	[215 ... 219] = 	IBRIGHTNESS_350NIT,
	[220 ... 223] = 	IBRIGHTNESS_357NIT,
	[224 ... 227] = 	IBRIGHTNESS_365NIT,
	[228 ... 230] = 	IBRIGHTNESS_372NIT,
	[231 ... 234] = 	IBRIGHTNESS_380NIT,
	[235 ... 238] = 	IBRIGHTNESS_387NIT,
	[239 ... 242] = 	IBRIGHTNESS_395NIT,
	[243 ... 246] = 	IBRIGHTNESS_403NIT,
	[247 ... 250] = 	IBRIGHTNESS_412NIT,
	[251 ... 255] = 	IBRIGHTNESS_420NIT,
	[256 ... 281] =		IBRIGHTNESS_443NIT,
	[282 ... 295] =		IBRIGHTNESS_465NIT,
	[296 ... 309] =		IBRIGHTNESS_488NIT,
	[310 ... 323] =		IBRIGHTNESS_510NIT,
	[324 ... 336] =		IBRIGHTNESS_533NIT,
	[337 ... 350] =		IBRIGHTNESS_555NIT,
	[351 ... 364] =		IBRIGHTNESS_578NIT,
	[EXTEND_BRIGHTNESS ... EXTEND_BRIGHTNESS] =		IBRIGHTNESS_600NIT
};
#endif /* __S6E3AA2_A3XE_PARAM_H__ */
