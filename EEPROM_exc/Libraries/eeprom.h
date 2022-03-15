void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);
void EEPROM_write_string(unsigned int StartAddress, char buffer[16]);
void EEPROM_read_string(unsigned int StartAddress, char buffer[16]);
