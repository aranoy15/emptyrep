#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <string>

using namespace std;

enum class McpRegs
{
	IODIRA = 0x00,
	IODIRB = 0x01,
	IPOLA = 0x02,
	IPOLB = 0x03,
	GPINTENA = 0x04,
	GPINTENB = 0x05,
	GPIOA = 0x12,
	GPIOB = 0x13
};


int main()
{
	int fd;

	fd = wiringPiI2CSetup(0x20);
	cout << "Init result: " << fd << endl;

	if (fd == -1) {
		cout << "Error init i2c" << endl;
		return 1;
	}

	uint16_t outs = 0;
	outs = 0xFFFF;			

	cout << "Initial MCP23017" << endl;

	wiringPiI2CWriteReg8(fd, static_cast<uint8_t>( McpRegs::IODIRA), 0x00);
	wiringPiI2CWriteReg8(fd, static_cast<uint8_t>( McpRegs::IODIRB), 0x00);

	wiringPiI2CWriteReg8(fd, static_cast<uint8_t>(McpRegs::GPIOA), 0xF0);
	wiringPiI2CWriteReg8(fd, static_cast<uint8_t>(McpRegs::GPIOB), 0xFF);

	return 0;
}
