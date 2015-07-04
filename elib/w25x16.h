#ifndef __W25X16_H
#define __W25X16_H
#include "ebox.h"
#include "spi.h"

////////////////////////////////////////////////////////////////////////////
//W25X16
#define FLASH_ID 0XEF14
//cmd
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 
#define W25X_ReadStatusReg		0x05 
#define W25X_WriteStatusReg		0x01 
#define W25X_ReadData			0x03 
#define W25X_FastReadData		0x0B 
#define W25X_FastReadDual		0x3B 
#define W25X_PageProgram		0x02 
#define W25X_BlockErase			0xD8 
#define W25X_SectorErase		0x20 
#define W25X_ChipErase			0xC7 
#define W25X_PowerDown			0xB9 
#define W25X_ReleasePowerDown	0xAB 
#define W25X_DeviceID			0xAB 
#define W25X_ManufactDeviceID	0x90 
#define W25X_JedecDeviceID		0x9F 
class W25X
{
	public:
		W25X(uint8_t cspin)
		{
			cs = cspin;
		}
		void begin();
		void readId(uint16_t* id);
	private:
		uint8_t cs;
		


};
#endif