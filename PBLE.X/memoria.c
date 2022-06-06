#include "mcc_generated_files/delay.h"
#include "mcc_generated_files/pin_manager.h"

//fun��es de bit
#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define BitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define BitTst(arg,bit) ((arg) & (1<<bit)) 

#define SDA_ON()    SDA_SetDigitalInput()
#define SDA_OFF()   SDA_SetDigitalOutput(); SDA_SetLow()
#define SDA()       SDA_GetValue()
#define SDA_IN()    SDA_SetDigitalInput()
#define SDA_OUT()   SDA_SetDigitalOutput()

//Funções do pino conectado ao SCL
/*RB12_High()*/
#define SCL_ON()    SCL_SetDigitalInput(); 
#define SCL_OFF()   SCL_SetDigitalOutput(); SCL_SetLow()
#define SCL()       SCL_GetValue()
#define SCL_IN()    SCL_SetDigitalInput()
#define SCL_OUT()   SCL_SetDigitalOutput()

#define DELAY() DELAY_microseconds(3)

void i2cInit(void) {
    SDA_IN();
    SCL_IN();
    DELAY();
}

//protocolo I2C
//Condição de inicio: Rampa de decida no SDA COM SCL ligado

void startC(void) {
    i2cInit();
    DELAY();
    SDA_OFF();
    DELAY();
    SCL_OFF();
    DELAY();
}

//Condição de inicio: Rampa de subida no SCA COM SCL ligado
void stopC(void) {
    SDA_OUT();
    DELAY();
    SCL_IN();
    DELAY();
    SDA_IN();
}

//Pulso de Clock usado para validar 1 bit

void clkPulse(void) {
    SCL_ON();
    while (SCL() == 0);
    DELAY();
    SCL_OFF();
    DELAY();
}

//Quando 1 Byte é recebido deve-se ceder acesso ao pino SDA para o Slave
//Se o byte foi recebido o Slave leva SDA para nível 0, e aguarda um pulso de Clock

void checkAkB(void) {
    SDA_IN(); //Slave controla o estado do pino, Master verifica
    clkPulse();
    DELAY();
}

void writeByte(unsigned char dados) {
    char i;
    for (i = 7; i >= 0; i--) {
        if (BitTst(dados, i)) {
            SDA_ON();
        } else {
            SDA_OFF();
        }
        DELAY();
        clkPulse();
    }
}

unsigned char readByte(void) {
    char i;
    int dados;
    dados = 0;
    SDA_IN();
    for (i = 8; i >= 0; i--) {
        DELAY();
        if (SDA()) {
            BitSet(dados, i);
        } else {
            BitClr(dados, i);
        }
        clkPulse();
    }
    return dados;
}

void MEMwrite(unsigned char addr1, unsigned char addr2, unsigned char dados) {
    startC();
    writeByte(0xA0); //Endereço da memória e Escrita
    checkAkB(); //Verifica se recebeu 1 Byte
    writeByte(addr1); //Posição 1 da memoria
    checkAkB(); //Verifica se recebeu 1 Byte
    writeByte(addr2); //Posição 2 da memoria
    checkAkB(); //Verifica se recebeu 1 Byte
    writeByte(dados); //Valor a ser escrito
    checkAkB(); //Verifica se recebeu 1 Byte
    stopC();
    DELAY_microseconds(10);
}

unsigned char MEMread(unsigned char addr1, unsigned char addr2) {
    unsigned char dados;
    startC();
    writeByte(0xA0); //Endereço da memória e escrita
    checkAkB(); //Verifica se recebeu 1 Byte
    writeByte(addr1); //Posição 1 da memoria
    checkAkB(); //Verifica se recebeu 1 Byte
    writeByte(addr2); //Posição 2 da memoria
    checkAkB(); //Verifica se recebeu 1 Byte
    startC();
    writeByte(0xA1); // leitura do endereço anterior
    dados = readByte(); //Valor a ser lido
    stopC();
    DELAY_microseconds(10);
    return (dados);
}