#include "mcc_generated_files/pin_manager.h"
#include "Utils.h"

void pulseEnablePin() {
    E_SetHigh();
    E_SetLow();
}

void pushNibble(int value, int rs) {
    if (bitRead(value, 4)) D4_SetHigh();
    else D4_SetLow();
    if (bitRead(value, 5)) D5_SetHigh();
    else D5_SetLow();
    if (bitRead(value, 6)) D6_SetHigh();
    else D6_SetLow();
    if (bitRead(value, 7)) D7_SetHigh();
    else D7_SetLow();
    if (rs) RS_SetHigh();
    else RS_SetLow();
    pulseEnablePin();
}

void pushByte(int value, int rs) {
    int val_lower = (value << 4) &0xf0;
    int val_upper = value & 0xF0;
    pushNibble(val_upper, rs);
    pushNibble(val_lower, rs);
}

void lcdChar(int value) {
    //let pushByte worry about the intricacies of Enable, nibble order.
    pushByte(value, 1);
    delay_us(40);
}

void lcdCommand(int value) {
    pushByte(value, 0);
    delay_us(40);
    if (value == 0x01){
        delay_ms(2);
    }
}

void lcdCommand4bits(int nibble) {
    pushNibble(nibble << 4, 0);
}

void lcdInit() {
    E_SetDigitalOutput();
    RS_SetDigitalOutput();
    D4_SetDigitalOutput();
    D5_SetDigitalOutput();
    D6_SetDigitalOutput();
    D7_SetDigitalOutput();
    //LED_SetHigh();

    delay_ms(15); //15ms

    //The first 4 nibbles and timings are not in my DEM16217 SYH datasheet, but apparently are HD44780 standard...
    lcdCommand4bits(0x03);
    delay_ms(1);
    lcdCommand4bits(0x03);
    delay_ms(1); //100us
    lcdCommand4bits(0x03);
    delay_ms(5);

    // needed by the LCDs controller
    //this being 2 sets up 4-bit mode.
    lcdCommand4bits(0x02);
    delay_ms(1);

    //configura o display
    lcdCommand(0x28); //8bits, 2 linhas, 5x8
    lcdCommand(0x06); //modo incremental
    lcdCommand(0x0c); //display e cursor on, com blink
    lcdCommand(0x03); //zera tudo
    lcdCommand(0x80); //posi??o inicial
    lcdCommand(0x01); //limpar display
}

void lcdString(char msg[]) {
    unsigned char i = 0; //fancy int.  avoids compiler warning when comparing i with strlen()'s uint8_t
    while (msg[i]) {
        lcdChar(msg[i]);
        i++;
    }
}

void lcdData(unsigned char value) {
    pushByte(value, 1);
    delay_ms(2);
}

void lcdInt(int val) {
    if (val < 0) {
        val = val * (-1);
        lcdData('-');
    }
    //lcdData((val / 10000) % 10 + 48);
    lcdData((val / 1000) % 10 + 48);
    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);

}

void lcd2Dig(int val){
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);
}

void lcdUInt32(uint32_t val){
    lcdData((val / 1000000000) % 10 + 48);
    lcdData((val / 100000000) % 10 + 48);
    lcdData((val / 10000000) % 10 + 48);
    lcdData((val / 1000000) % 10 + 48);
    lcdData((val / 100000) % 10 + 48);
    lcdData((val / 10000) % 10 + 48);
    lcdData((val / 1000) % 10 + 48);
    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);
}

void lcdUInt16(uint16_t val){
    lcdData((val / 10000) % 10 + 48);
    lcdData((val / 1000) % 10 + 48);
    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);
}

void lcdUInt8(uint8_t val){
    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);
}