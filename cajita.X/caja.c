 /*HECHO POR ALAN SUÁREZ*/
    #include <xc.h>
    #include <stdio.h>
    // CONFIG1H
    #pragma config FOSC = HS     // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
    // CONFIG2H
    #pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT enabled)
    // CONFIG3H
    #pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

    #define _XTAL_FREQ 4000000 


    
    void DO(int y);
    void RE(int y);
    void MI(int y);
    void FA(int y);
    void SOL(int y);
    void LA(int y);
    void SI(int y);
    void SIL(int y);
    void SILM();
    void SILC();
   


    void main(void) {
        INTCONbits.TMR0IE =1; //Enable timers interrupts
        INTCONbits.TMR0IF =0; // clear timer zero overflow flag

        T0CONbits.T08BIT =0;//MODO 8 bits
        T0CONbits.T0CS =0;// modo temporizador
        T0CONbits.PSA =0;// prescaler habilitado
        T0CONbits.T0PS = 0b110; //prescaler 1:128

        int a,b,s;//DECLARAMOS VARIABLES DE TIPO ENTERO
        TRISD = 0;//CONFIGURAMOS EL PUERTO DE COMO SALIDA
        TRISC = 0xff;//DECLARAMOS AL PUERTO C COMO SALIDA



        PORTD =0;//DECLARAMOS UNA ETIQUETA
        
        
        if(PORTCbits.RC0==1){
             
           int x = 1;
            
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           FA(x);SILC();FA(x);MI(x);SILC();MI(x);RE(x);SILC();RE(x);DO(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);RE(x);DO(x);SI(x);LA(x);SOL(x);FA(x);
        } 
        if(PORTCbits.RC1==1){
           int x = 2;
           
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           FA(x);SILC();FA(x);MI(x);SILC();MI(x);RE(x);SILC();RE(x);DO(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);RE(x);DO(x);SI(x);LA(x);SOL(x);FA(x);
        } 
        
        if(PORTCbits.RC2==1){
           int x = 3;
           
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           FA(x);SILC();FA(x);MI(x);SILC();MI(x);RE(x);SILC();RE(x);DO(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);RE(x);DO(x);SI(x);LA(x);SOL(x);FA(x);
        } 
        if(PORTCbits.RC4==1){
           int x = 4;
           
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           DO(x);SILC();DO(x);SILC();DO(x);SILC(x);FA(x);LA(x);
           FA(x);SILC();FA(x);MI(x);SILC();MI(x);RE(x);SILC();RE(x);DO(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);SILC();DO(x);SILC();DO(x);MI(x);SOL(x);
           DO(x);RE(x);DO(x);SI(x);LA(x);SOL(x);FA(x);
        } 
        
        
        
        
        }

    void SILC(){
        __delay_ms(50);
    }

    void SILM(){
        __delay_ms(400);
    }
    

    void SIL(int y){
        TMR0=y; //Cambiar el tiempo con el excel que hice
        TMR0ON = 1;

        while(TMR0IF != 1){

        }
        TMR0IF = 0;
        TMR0ON = 0;
    }

    void DO(int y){
        if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.915);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.885); 
        }
        TMR0IF = 0;
        TMR0ON = 0;
        
        
        }



    void RE(int y){
       if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.700);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.700); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
        
   
    }



    void MI(int y){
       if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.519);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.519); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
        
        
    }

    void FA(int y){
        if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.432);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.432); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
        
    }

    void SOL(int y){
       if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.275);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.275); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
       
    }

    void LA(int y){
       if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.136);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.136); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
       
    }

    void SI(int y){
       if(y==1){
            TMR0=63192;
        }
        if(y==2){
            TMR0=64364;
        }
        if(y==3){
            TMR0=65047;
        }
        if(y==4){
            TMR0=65223;
        }
        TMR0ON = 1;

        while(TMR0IF != 1){
             PORTDbits.RD0 = 1; 
             __delay_ms(1.014);
             PORTDbits.RD0 = 0; 
             __delay_ms(1.014); 
        }
        TMR0IF = 0;
        TMR0ON = 0; 
        
    }
