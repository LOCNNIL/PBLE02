#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/delay.h"
#include "mcc_generated_files/sccp8_compare.h"
#include "memoria.h"
#include "lcd.h"
#include "var.h"
#include "adc.h"
#include "output.h"
#include "adc.h"
#include "stateMachine.h"
#include "mcc_generated_files/tmr1.h"

void main(void) {
    //init das bibliotecas
    SYSTEM_Initialize();
    varInit();
    outputInit();

    for (;;) 
    {
        
        /*
        //Recebe a função para setar o tempo de loop
        TMR1_Period16BitSet(getTime());
        TMR1_Start();      
        
        //máquina de estados
        smLoop();
              
        while(!TMR1_GetElapsedThenClear())
        {
            TMR1_Tasks_16BitOperation();
        }
         * */
    }
}

//   // Teste do TMR
//        count++;
//        lcdCommand(0x80);
//        lcdData((count/100 + '0'));
//        lcdData(((count/10)%10 + '0'));
//        lcdData((count%10 + '0'));          
//    
//    // Teste do LCD
//    lcdInit(); 
//    //lcdCommand(0x80);
//    //lcdString("Bom dia Max!");
//    
//    // Teste da Memoria
//    MEMwrite(0,1,'U');
//    lcdCommand(0x80);
//    lcdData(MEMread(0,1));
//    UART1_Write(MEMread(0,1));  
//       
//    for (;;)
//    {                  
//        /////// busca valores da entrada analogica 1///////
//               
//        int conversion_ANA_IN1;
//
//        ADC1_ChannelSelect(ANA_IN1);
//        ADC1_Start();
//        //Provide Delay
//        for(int i=0;i <1000;i++)
//        {
//        }
//        ADC1_Stop();
//        while(!ADC1_IsConversionComplete())
//        {
//            ADC1_Tasks();   
//        }
//        conversion_ANA_IN1 = ADC1_ConversionResultGet();             
//        
//        if(conversion_ANA_IN1 > 100 && conversion_ANA_IN1 < 200) // 0,49 V < conversion < 0,97 V
//        {
//            //lcdCommand(0x80);
//            //lcdString("Alarme1!!!    ");
//        }
//        else if(conversion_ANA_IN1 > 500 && conversion_ANA_IN1 < 600) // 2,46 V < conversion < 2,94 V
//        {
//            //lcdCommand(0x80);
//            //lcdString("Alarme2!!!   ");
//        }
//        else
//        {
//            //lcdCommand(0x80);
//            //lcdString("Tudo Certo!!!");
//        }
//                
//        /////// busca valores do teclado ///////
//        int conversionTeclado;
//
//        ADC1_ChannelSelect(Teclado);
//        ADC1_Start();
//        //Provide Delay
//        for(int i=0;i <1000;i++)
//        {
//        }
//        ADC1_Stop();
//        while(!ADC1_IsConversionComplete())
//        {
//            ADC1_Tasks();   
//        }
//        conversionTeclado = ADC1_ConversionResultGet();
//        
//        if(conversionTeclado > 175 && conversionTeclado < 390)
//        {
//            //UART1_Write('1');
//            PORTA0_SetLow();    
//        }
//        else if (conversionTeclado > 390 && conversionTeclado < 478)
//        {
//            //UART1_Write('2');
//            PORTA1_SetLow();           
//        }
//        else if (conversionTeclado > 478 && conversionTeclado < 614)
//        {
//            //UART1_Write('3');
//            PORTA2_SetLow();
//        }
//        else if (conversionTeclado > 614 && conversionTeclado < 860)
//        {
//            //UART1_Write('4');
//            PORTA3_SetLow();
//        }
//        else if (conversionTeclado > 860 && conversionTeclado < 1300)
//        {
//            //UART1_Write('4');
//            PORTA0_SetLow();
//            PORTA1_SetLow();
//            PORTA2_SetLow();
//            PORTA3_SetLow();
//        }
//        else
//        {
//            //UART1_Write('5');
//            PORTA0_SetHigh();
//            PORTA1_SetHigh();
//            PORTA2_SetHigh();
//            PORTA3_SetHigh();  
//        }
//       
//        /////// busca valores do potenciometro ///////       
////        int conversionPot;
////        
////        ADC1_ChannelSelect(Pot);
////        ADC1_Start();
////        //Provide Delay
////        for(int i=0;i <1000;i++)
////        {
////        }
////        ADC1_Stop();
////        while(!ADC1_IsConversionComplete())
////        {
////            ADC1_Tasks();   
////        }
////        conversionPot = ADC1_ConversionResultGet();    
////        
////        if(conversionPot > 175 && conversionPot < 390)
////        {
////            //UART1_Write('1');
////            PORTA0_SetLow();    
////        }
////        else if (conversionPot > 390 && conversionPot < 478)
////        {
////            //UART1_Write('2');
////            PORTA1_SetLow();           
////        }
////        else if (conversionPot > 478 && conversionPot < 614)
////        {
////            //UART1_Write('3');
////            PORTA2_SetLow();
////        }
////        else if (conversionPot > 614 && conversionPot < 860)
////        {
////            //UART1_Write('4');
////            PORTA3_SetLow();
////        }
////        else if (conversionPot > 860 && conversionPot < 1300)
////        {
////            //UART1_Write('4');
////            PORTA0_SetLow();
////            PORTA1_SetLow();
////            PORTA2_SetLow();
////            PORTA3_SetLow();
////        }
////        else
////        {
////            //UART1_Write('5');
////            PORTA0_SetHigh();
////            PORTA1_SetHigh();
////            PORTA2_SetHigh();
////            PORTA3_SetHigh();  
////        }
//    }     
//}


