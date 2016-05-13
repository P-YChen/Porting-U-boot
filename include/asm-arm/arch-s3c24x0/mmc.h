#ifndef __ARCH_MMC_H__
#define __ARCH_MMC_H__

#include <asm/arch/regs-sdi.h>

#define MMC_BLOCK_SIZE			512

#define CMD_F_RESP	0x01
#define CMD_F_RESP_LONG	0x02
#define CMD_F_RESP_R7 CMD_F_RESP

struct CSD_REG_V1 {
	uint8_t crc;
	uint8_t csd_file_format;
	uint8_t csd_write_protect; /* write protection */
					/* ---- --PT P=PERMANENT T=TEMPORARY*/
	uint8_t csd_copy;
	uint8_t csd_file_format_grp;
	uint8_t csd_write_bl_partial;
	uint8_t csd_write_bl_len;
	uint8_t csd_r2w_factor;
	uint8_t csd_wp_grp_enable;
	uint8_t csd_wp_grp_size;
	uint8_t csd_sector_size;
	uint8_t csd_erase_blk_en;
	uint8_t csd_c_size_mult;
	uint8_t csd_vdd_w_curr_max;
	uint8_t csd_vdd_w_curr_min;
	uint8_t csd_vdd_r_curr_max;
	uint8_t csd_vdd_r_curr_min;
	uint32_t csd_c_size;
	uint8_t csd_read_bl_len;
	uint16_t csd_ccc;
	uint8_t csd_tran_speed;
	uint8_t csd_nsac;
	uint8_t csd_taac;
};

struct CSD_REG_V2 {
	uint8_t csd_taac;
	uint8_t csd_nsac;
	uint8_t csd_tran_speed;
	uint16_t csd_ccc;
	uint8_t csd_read_bl_len;
	uint32_t csd_c_size;
	uint8_t csd_erase_blk_en;
	uint8_t csd_sector_size;
	uint8_t csd_wp_grp_size;
	uint8_t csd_wp_grp_enable;
	uint8_t csd_r2w_factor;
	uint8_t csd_write_bl_len;
	uint8_t csd_write_bl_partial;
	uint8_t csd_file_format_grp;
	uint8_t csd_copy;
	uint8_t csd_write_protect;
	uint8_t csd_file_format;
	uint8_t crc;
};

union CSD_REG {
	struct CSD_REG_V1 csd_reg_v1;
	struct CSD_REG_V2 csd_reg_v2;
};

struct sd_cid {
	char		pnm_0;	/* product name */
	char		oid_1;	/* OEM/application ID */
	char		oid_0;
	uint8_t		mid;	/* manufacturer ID */
	char		pnm_4;
	char		pnm_3;
	char		pnm_2;
	char		pnm_1;
	uint8_t		psn_2;	/* product serial number */
	uint8_t		psn_1;
	uint8_t		psn_0;	
	uint8_t		prv;	/* product revision */
	uint8_t		crc;	/* CRC7 checksum, b0 is unused and set to 1 */
	uint8_t		mdt_1;	
	uint8_t		mdt_0;	
	uint8_t		psn_3;	
};

struct sd_csd {
	uint8_t version;
	union CSD_REG csd;
};

#endif /* __ARCH_MMC_H__ */
