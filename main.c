#include "main.h"
#include "usb_host.h"
#define rccahb1enR ((unsigned volatile int)0x40023830)
#define gpiodOdr ((unsigned volatile int)0x40020c14)
#define gpiodModr ((unsigned volatile int)0x40020c00)
#define gpiod 1<<3 
#define gpiodP12 1<<24 //reg
#define gpiodP13 1<<26 //reg13
#define gpiodP12on 1<<12 //on
#define gpiodP12off 0<<12 //off
#define gpiodP13on 1<<13 //on
#define gpiodP13off ~(1<<13) //off
void init_leds(){
	 rccahb1enR =gpiod;
	 gpiodModr=gpiodP12; //green led
	 gpiodModr |=gpiodP13; //orange led
}
void name(){
	turn_name_on();
	delay();
	turn_name_off();
	delay();
}
void surname(){
	turn_surname_on();
	delay();
	turn_surname_off();
	delay();
}
void turn_surname_on(){
	 gpiodOdr =gpiodP12on;

}
void turn_surname_off(){
	 gpiodOdr =gpiodP12off;

}
void turn_name_on(){
	 gpiodOdr |=gpiodP13on;

}
void turn_name_off(){
	 gpiodOdr &=gpiodP13off;

}
void delay(){
	int delay0 = 0x000FFFFF; //delay loop
	while (delay0--){
		}
}
 int main(){
init_leds();
int i;
	for(i=0;i<8;i++){
	name();
}
	for(i=0;i<4;i++){
	surname();
}

return 0;

 }
