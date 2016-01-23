#ifndef SRC_PACKETIZER_H_
#define SRC_PACKETIZER_H_

#include <stdint.h>

class Packetizer {
public:
	struct Header{
		uint32_t signature;
		uint16_t length;
		uint8_t version;
		uint8_t type;
		uint32_t packetId;
		uint8_t reserved;
		uint8_t headerChecksum;
	} __attribute__((packed));
	
	enum PacketType {ECG=0};

	static const uint32_t HEADER_SIZE = sizeof(Header);
	static const uint32_t SIGNATURE = 0x41544144;
	static const uint8_t VERSION = 0;
	typedef uint16_t Checksum;

	Packetizer();
	virtual ~Packetizer();

	void startPacket(uint8_t *destBuffer, PacketType type, uint16_t length);
	void checksumBlock(uint8_t *data, int cnt);
	Checksum getChecksum();
private:


	static uint32_t packetId;
	Checksum checksum;
	void resetChecksum();
};

#endif /* SRC_PACKETIZER_H_ */