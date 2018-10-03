#include <wiringPi.h> // gpio library
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

  int start = 1;

  do
  {

	if (start = 1) { //blink seq start
		digitalWrite (4, HIGH) ; delay (500) ;
		digitalWrite (4,  LOW) ; digitalWrite(5, HIGH) ; delay (500) ;
		digitalWrite (5,  LOW) ; digitalWrite(6, HIGH) ; delay (500) ;
		start = 0;
	}
	else {
		if (digitalRead (7) = 1) { // Player 1 hits
			digitalWrite (6,  LOW) ; digitalWrite(3, HIGH) ; delay (2000) ;
			start = 1;
		}
		if (digitalRead (0) = 1) { //player 2 hits
			digitalWrite (6,  LOW) ; digitalWrite(1, HIGH) ; delay (2000) ;
			start = 1;
		}
	}
  }while(digitalRead (2) = 0); // end switch is hit

  return 0 ;
}
