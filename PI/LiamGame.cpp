#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (2, INPUT); //Header 13: End Button
  pinMode (7, INPUT); //Header 7: Player 1 Button
  pinMode (0, INPUT); //Header 11: Player 2 Button
  pinMode (3, OUTPUT); //Header 15: Player 1 LED
  pinMode (1, OUTPUT); //Header 12: Player 2 LED
  pinMode (4, OUTPUT); //Header 16: Ready LED
  pinMode (5, OUTPUT); //Header 18: Set LED
  pinMode (6, OUTPUT); //Header 22: GO LED

  bool start = 1,p1=0,p2=0;

  do
  {

	if (start == 1) {
		digitalWrite (4, HIGH) ; delay (500) ;
		digitalWrite (4,  LOW) ; digitalWrite(5, HIGH) ; delay (500) ;
		digitalWrite (5,  LOW) ; digitalWrite(6, HIGH) ;
		start = 0;
	}
	else {
	p1=digitalRead (7);
	p2=digitalRead (0);
		if ((p1 == 0)&&(p2 == 1)) {
			digitalWrite (6,  LOW) ; digitalWrite(1, HIGH) ; delay (2000) ;  digitalWrite(1, LOW) ;
			start = 1;
		}
		else if ((p1 == 1)&&(p2 == 0)) {
			digitalWrite (6,  LOW) ; digitalWrite(3, HIGH) ; delay (2000) ;  digitalWrite(3, LOW) ;
			start = 1;
		}
		
	}
  }while(digitalRead (2) == 0);

digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(1, LOW);

  return 0 ;
}
