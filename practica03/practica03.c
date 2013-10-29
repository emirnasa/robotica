#include <16f877a.h>
#fuses XT,NOWDT, PUT, NOWRT
#use delay(clock=20000000)
#include <lcd.c>
Int32 pulsos;
#use fast_io(B)
#INT_EXT
        
ext_isr()
{
    if ((input(PIN_B0)==1)&(input(PIN_B1)==0))
    {
    	pulsos = pulsos+1;
    }
    if ((input(PIN_B0)==1)&(input(PIN_B1)==1))
    {
    	pulsos = pulsos-1;
    }
    
    lcd_gotoxy(1,1);
    printf(lcd_putc,"Pulsos=%Ld",pulsos); 
}
    
void main() {
   pulsos = 0;
   set_tris_B(0x01); 
   port_b_pullups(TRUE);
   enable_interrupts(int_ext);
   ext_int_edge(L_to_H);
   enable_interrupts(GLOBAL);
   lcd_init(); //Esta es la primera instrucción para inicializar el lcd
   
   while(TRUE) 
   {
	   
   }
}
    
         
