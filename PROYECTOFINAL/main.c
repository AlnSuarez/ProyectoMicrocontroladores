/**
  Generated Main Source File
  Company:
    Microchip Technology Inc.
  File Name:
    main.c
  Summary:
    This is the main file generated using MPLAB(c) Code Configurator
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC18F4550
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2015 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc.h"
#include "stdio.h"
#include "stdlib.h"
#include <xlcd.h>

#define _XTAL_FREQ 24000000ul

/*
                         Main application
 */
int changeStages(unsigned char *parameter1, unsigned char *parameter2, int enemPos);
void juego1();
void juego2();
void juego3();
int juego4();
void printscore(int score);

unsigned int ADC_Value, porcHumidity;
unsigned int ADC_Value2, Temp;
unsigned char ADC_Buffer[10];

unsigned char data0 [] = {0x04, 0x0E, 0x0E, 0x0E, 0x0E, 0x1F, 0x04, 0x00};
unsigned char data1 [] = {0x06, 0x07, 0x06, 0x06, 0x07, 0x17, 0x1F, 0x05};


void delayms(int value);
unsigned char ADC_Buffer[10];

//changeStage1

int counter = 0;

void createCharacter(unsigned char * data, unsigned char number){
    unsigned char i = 0;
    while(BusyXLCD()); 
    WriteCmdXLCD(0x40 + ((number)*8));
    for(int i = 0; i < 8; i++){
        while(BusyXLCD());
        WriteDataXLCD(data[i]);    
    }
};
void printCharacter(unsigned int number){    
    while(BusyXLCD()); 
    WriteDataXLCD(number);  
};


void main(void)
{
    
     // Initialize the device
    SYSTEM_Initialize();
    
    //Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    createCharacter(data0, 0);
    createCharacter(data1 , 1);
    
    TRISB = 0b0000000;
      
    RB0 = 1;
    juego1();
    RB0 = 0;
    RB1 = 1;
    juego2();
    RB1 = 0;
    RB2 = 1;
    juego3();
    RB2 = 0;
    RB3 = 1;
    int score = juego4();
    
    while(1){
        printscore(score);
    }
    
       
    
   
}

void printscore(int score){
    
    char buffer2[10];
    while(BusyXLCD());
    SetDDRamAddr(0x0);
    putsXLCD("tu score es de:");
    while(BusyXLCD());
    SetDDRamAddr(0x40);
    sprintf(buffer2,"%d",score);
    putsXLCD(buffer2);
}
int changeStages(unsigned char *parameter1, unsigned char *parameter2, int enemPos){
         // Initialize the device
    SYSTEM_Initialize();
    char buffer[10];
    
   
    
       while(BusyXLCD());
        SetDDRamAddr(0x0);
//        sprintf(ADC_Buffer, parameter1);
        putsXLCD(parameter1);
        while(BusyXLCD());
        SetDDRamAddr(0x0D);
        sprintf(buffer,"%d",counter);
        putsXLCD(buffer);
        while(BusyXLCD());
        SetDDRamAddr(0x40);
//        sprintf(ADC_Buffer, parameter2);
        putsXLCD(parameter2);
        
        
        int pos;
    //wait until conversion is done
        ADC_Value = ADC_GetConversion(0);
        
        if(ADC_Value <= 511){
            while(BusyXLCD());
            SetDDRamAddr(0x00);
            printCharacter(0x01);
            pos = 1;
        }
        else{
        
            while(BusyXLCD());
            SetDDRamAddr(0x40);
            printCharacter(0x01);
            pos = 2;
        }
        
        if(pos==enemPos){
            counter=counter-10;
        }
        else{
            //aquí no resta puntaje porque no chocan
        }
        
        
        
        counter = counter+1;
        return counter;
}





void juego1(){
    int pos;
    __delay_ms(550);
    changeStages("          0","           ", 0);
    
    __delay_ms(550);
    changeStages("         0 ","           ", 0);
    __delay_ms(550);
    
    changeStages("        0  ","           ", 0);
    __delay_ms(550);
    
    changeStages("       0   ","          0", 0);
    __delay_ms(550);
    
    changeStages("      0    ","         0 ", 0);
    __delay_ms(550);
    
    changeStages("     0    0","        0  ", 0);
    __delay_ms(550);
    
    changeStages("    0    0 ","       0   ", 0);
    __delay_ms(550);
    
    changeStages("   0    0  ","      0    ", 0);
    __delay_ms(550);
    
    changeStages("  0    0   ","     0     ", 0);
    __delay_ms(550);
    
    changeStages(" 0    0    ","    0      ", 0);
    __delay_ms(550);
    
    changeStages("0    0     ","   0       ", 1);
    __delay_ms(550);
    
    changeStages("    0      ","  0       0", 0);
    __delay_ms(550);
    
    changeStages("   0       "," 0       0 ", 0);
    __delay_ms(550);
    
    changeStages("  0        ","0       0  ", 2);
    __delay_ms(550);
    
    changeStages(" 0         ","       0   ", 0);
    __delay_ms(550);
    
    changeStages("0          ","      0    ", 1);
    __delay_ms(550);
    
    changeStages("           ","     0     ", 0);
    __delay_ms(550);
    
    changeStages("           ","    0      ", 0);
    __delay_ms(550);
    
    changeStages("          0","   0       ", 0);
    __delay_ms(550);
    
    changeStages("         0 ","  0        ", 0);
    __delay_ms(550);
    
    changeStages("        0  "," 0         ", 0);
    __delay_ms(550);
    
    changeStages("       0  "," 0          ", 0);
    __delay_ms(550);
    
    changeStages("      0   ","0           ", 2);
    __delay_ms(550);
    
    changeStages("     0    ","            ", 0);
    __delay_ms(550);
    
    changeStages("    0     ","            ", 0);
    __delay_ms(550);
    
    changeStages("   0      ","            ", 0);
    __delay_ms(550);
    
    changeStages("  0       ","            ", 0);
    __delay_ms(550);
    
    changeStages(" 0        ","            ", 0);
    __delay_ms(550);
    
    changeStages("0         ","            ", 1);
    __delay_ms(550);
    
    changeStages("          ","            ", 0);
}

void juego2(){
    int pos;
    __delay_ms(400);
    changeStages("          0","           ", 0);
    
    __delay_ms(400);
    changeStages("         0 ","           ", 0);
    __delay_ms(400);
    
    changeStages("        0  ","           ", 0);
    __delay_ms(400);
    
    changeStages("       0   ","          0", 0);
    __delay_ms(400);
    
    changeStages("      0    ","         0 ", 0);
    __delay_ms(400);
    
    changeStages("     0    0","        0  ", 0);
    __delay_ms(400);
    
    changeStages("    0    0 ","       0   ", 0);
    __delay_ms(400);
    
    changeStages("   0    0  ","      0    ", 0);
    __delay_ms(400);
    
    changeStages("  0    0   ","     0     ", 0);
    __delay_ms(400);
    
    changeStages(" 0    0    ","    0      ", 0);
    __delay_ms(400);
    
    changeStages("0    0     ","   0       ", 1);
    __delay_ms(400);
    
    changeStages("    0      ","  0       0", 0);
    __delay_ms(400);
    
    changeStages("   0       "," 0       0 ", 0);
    __delay_ms(400);
    
    changeStages("  0        ","0       0  ", 2);
    __delay_ms(400);
    
    changeStages(" 0         ","       0   ", 0);
    __delay_ms(400);
    
    changeStages("0          ","      0    ", 1);
    __delay_ms(400);
    
    changeStages("           ","     0     ", 0);
    __delay_ms(400);
    
    changeStages("           ","    0      ", 0);
    __delay_ms(400);
    
    changeStages("          0","   0       ", 0);
    __delay_ms(400);
    
    changeStages("         0 ","  0        ", 0);
    __delay_ms(400);
    
    changeStages("        0  "," 0         ", 0);
    __delay_ms(400);
    
    changeStages("       0  "," 0          ", 0);
    __delay_ms(400);
    
    changeStages("      0   ","0           ", 2);
    __delay_ms(400);
    
    changeStages("     0    ","            ", 0);
    __delay_ms(400);
    
    changeStages("    0     ","            ", 0);
    __delay_ms(400);
    
    changeStages("   0      ","            ", 0);
    __delay_ms(400);
    
    changeStages("  0       ","            ", 0);
    __delay_ms(400);
    
    changeStages(" 0        ","            ", 0);
    __delay_ms(400);
    
    changeStages("0         ","            ", 1);
    __delay_ms(400);
    
    changeStages("          ","            ", 0);
}

void juego3(){
    int pos;
    __delay_ms(200);
    changeStages("          0","           ", 0);
    
    __delay_ms(200);
    changeStages("         0 ","           ", 0);
    __delay_ms(200);
    
    changeStages("        0  ","           ", 0);
    __delay_ms(200);
    
    changeStages("       0   ","          0", 0);
    __delay_ms(200);
    
    changeStages("      0    ","         0 ", 0);
    __delay_ms(200);
    
    changeStages("     0    0","        0  ", 0);
    __delay_ms(200);
    
    changeStages("    0    0 ","       0   ", 0);
    __delay_ms(200);
    
    changeStages("   0    0  ","      0    ", 0);
    __delay_ms(200);
    
    changeStages("  0    0   ","     0     ", 0);
    __delay_ms(200);
    
    changeStages(" 0    0    ","    0      ", 0);
    __delay_ms(200);
    
    changeStages("0    0     ","   0       ", 1);
    __delay_ms(200);
    
    changeStages("    0      ","  0       0", 0);
    __delay_ms(200);
    
    changeStages("   0       "," 0       0 ", 0);
    __delay_ms(200);
    
    changeStages("  0        ","0       0  ", 2);
    __delay_ms(200);
    
    changeStages(" 0         ","       0   ", 0);
    __delay_ms(200);
    
    changeStages("0          ","      0    ", 1);
    __delay_ms(200);
    
    changeStages("           ","     0     ", 0);
    __delay_ms(200);
    
    changeStages("           ","    0      ", 0);
    __delay_ms(200);
    
    changeStages("          0","   0       ", 0);
    __delay_ms(200);
    
    changeStages("         0 ","  0        ", 0);
    __delay_ms(200);
    
    changeStages("        0  "," 0         ", 0);
    __delay_ms(200);
    
    changeStages("       0  "," 0          ", 0);
    __delay_ms(200);
    
    changeStages("      0   ","0           ", 2);
    __delay_ms(200);
    
    changeStages("     0    ","            ", 0);
    __delay_ms(200);
    
    changeStages("    0     ","            ", 0);
    __delay_ms(200);
    
    changeStages("   0      ","            ", 0);
    __delay_ms(200);
    
    changeStages("  0       ","            ", 0);
    __delay_ms(200);
    
    changeStages(" 0        ","            ", 0);
    __delay_ms(200);
    
    changeStages("0         ","            ", 1);
    __delay_ms(200);
    
    changeStages("          ","            ", 0);
}

int juego4(){
    int pos;
    __delay_ms(100);
    changeStages("          0","           ", 0);
    
    __delay_ms(100);
    changeStages("         0 ","           ", 0);
    __delay_ms(100);
    
    changeStages("        0  ","           ", 0);
    __delay_ms(100);
    
    changeStages("       0   ","          0", 0);
    __delay_ms(100);
    
    changeStages("      0    ","         0 ", 0);
    __delay_ms(100);
    
    changeStages("     0    0","        0  ", 0);
    __delay_ms(100);
    
    changeStages("    0    0 ","       0   ", 0);
    __delay_ms(100);
    
    changeStages("   0    0  ","      0    ", 0);
    __delay_ms(100);
    
    changeStages("  0    0   ","     0     ", 0);
    __delay_ms(100);
    
    changeStages(" 0    0    ","    0      ", 0);
    __delay_ms(100);
    
    changeStages("0    0     ","   0       ", 1);
    __delay_ms(100);
    
    changeStages("    0      ","  0       0", 0);
    __delay_ms(100);
    
    changeStages("   0       "," 0       0 ", 0);
    __delay_ms(100);
    
    changeStages("  0        ","0       0  ", 2);
    __delay_ms(100);
    
    changeStages(" 0         ","       0   ", 0);
    __delay_ms(100);
    
    changeStages("0          ","      0    ", 1);
    __delay_ms(100);
    
    changeStages("           ","     0     ", 0);
    __delay_ms(100);
    
    changeStages("           ","    0      ", 0);
    __delay_ms(100);
    
    changeStages("          0","   0       ", 0);
    __delay_ms(100);
    
    changeStages("         0 ","  0        ", 0);
    __delay_ms(100);
    
    changeStages("        0  "," 0         ", 0);
    __delay_ms(100);
    
    changeStages("       0  "," 0          ", 0);
    __delay_ms(100);
    
    changeStages("      0   ","0           ", 2);
    __delay_ms(100);
    
    changeStages("     0    ","            ", 0);
    __delay_ms(100);
    
    changeStages("    0     ","            ", 0);
    __delay_ms(100);
    
    changeStages("   0      ","            ", 0);
    __delay_ms(100);
    
    changeStages("  0       ","            ", 0);
    __delay_ms(100);
    
    changeStages(" 0        ","            ", 0);
    __delay_ms(100);
    
    changeStages("0         ","            ", 1);
    __delay_ms(100);
    
    int score = changeStages("          ","            ", 0);
    
    return score;
}




/**
 End of File
*/