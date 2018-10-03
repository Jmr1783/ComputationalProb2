#include <iostream>
#include <iomanip>
//#include <wiringPi.h>

using namespace std;

//----------PINS----------------

#define Seg1 22
#define Seg2 23
#define Seg3 24
#define Seg4 25
#define a 6
#define b 5
#define c 4
#define d 3
#define e 2
#define f 1
#define g 0

// declaration section
class Display
{
    private:
        int time_ms;
    public:
        Display (int time = 1){time_ms = time;}
        void showData(bool *Letter,bool *segSelect);
        void shiftArray(bool *segSelect);
        void manipulator_GPIO(bool *Letter,bool *segSelect);
        void setup_wiringPI();
};
// end of declaration section

// implementation section

void Display::showData(bool *Letter,bool *segSelect) {

    for(int i=0;i<7;i++){
        cout << *(Letter+i) << ' ' ;
    }
    cout << " ";
    for(int j=0;j<4;j++){
        cout << *(segSelect+j) << ' ' ;
    }
}

/* void Display::setup_wiringPI(){
    wiringPiSetup();
    pinMode(Seg1,OUTPUT);
    pinMode(Seg2,OUTPUT);
    pinMode(Seg3,OUTPUT);
    pinMode(Seg4,OUTPUT);
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
    pinMode(D,OUTPUT);
    pinMode(E,OUTPUT);
    pinMode(F,OUTPUT);
    pinMode(G,OUTPUT);
} */

void Display::manipulator_GPIO(bool *Letter,bool *segSelect) {
/*     digitalWrite(Seg1,*(Letter+0));
    digitalWrite(Seg2,*(Letter+1));
    digitalWrite(Seg3,*(Letter+2));
    digitalWrite(Seg4,*(Letter+3));
    digitalWrite(A,*(segSelect+0));
    digitalWrite(B,*(segSelect+1));
    digitalWrite(C,*(segSelect+2));
    digitalWrite(D,*(segSelect+3));
    digitalWrite(E,*(segSelect+4));
    digitalWrite(F,*(segSelect+5));
    digitalWrite(G,*(segSelect+6)); */
	


    cout <<(*(Letter+0))<< " ";
    cout <<(*(Letter+1))<< " ";
    cout <<(*(Letter+2))<< " ";
    cout <<(*(Letter+3))<< " ";
    cout <<(*(Letter+4))<< " ";
    cout <<(*(Letter+5))<< " ";
    cout <<(*(Letter+6))<< "  ";
    cout <<(*(segSelect+0))<< " ";
    cout <<(*(segSelect+1))<< " ";
    cout <<(*(segSelect+2))<< " ";
	cout <<(*(segSelect+3))<< " ";
	
}

void Display::shiftArray(bool *segSelect){
    bool temp = *(segSelect+(sizeof(segSelect)-1));
    for(int j=(sizeof(segSelect)-1);j>=0;j--){
             *(segSelect+(j+1))=*(segSelect+j);
        }
     *(segSelect)= temp;
}

int main (void)
{

  Display vend;
  //vend.setup_wiringPI();

  //-----------------1D/2D Arrays------------------------
  bool A[]={1,1,1,0,1,1,1}
      ,C[]={0,1,1,1,0,0,1}
      ,D[]={1,0,1,1,1,1,0}
      ,E[]={1,1,1,1,0,0,1}
      ,H[]={0,1,1,0,1,1,1}
      ,I[]={0,0,0,0,1,1,0}
      ,L[]={0,0,0,1,1,1,0}
      ,O[]={1,1,1,1,1,1,0}
      ,R[]={1,0,1,0,0,0,0}
      ,S[]={1,0,1,1,0,1,1}
      ,SPACE[]={0,0,0,0,0,0,0};
  bool segSelect[4]={1,0,0,0};
  char msg[] = {'I','C','E','_','C','O','L','D','_','S','O','D','A','_','S','O','L','D','_','H','E','R','E'};
  //-----------------Pointers------------------------
  bool *Letter[] = {I,C,E,SPACE,C,O,L,D,SPACE,S,O,D,A,SPACE,S,O,L,D,SPACE,H,E,R,E};
  bool *segSelectPtr;
  segSelectPtr = &segSelect[0];
  //-----------------integer Vars--------------------
  int startIndex=0,goToIndex=3;
  int rows = sizeof(Letter)/sizeof(Letter[0]);
  int cnt = 0,cycles=1;

//-----------------Display Code----------------------
for (int i = 0; i <= (rows-4) ; i++)
{
    cout << "----------START----------" << endl;
    for (int i = 0; i < cycles; i++)
    {
        for (int i = startIndex; i <= goToIndex; i++)
        {
              vend.showData(Letter[i],segSelectPtr);
              cout <<msg[i]<<" WINDOWS"<<endl;
              cout << endl;
              vend.manipulator_GPIO(Letter[i],segSelectPtr);
              vend.shiftArray(segSelectPtr);
              cout <<msg[i]<<"  PI"<<endl<<endl;
        }
    }
    startIndex+=1,goToIndex+=1;
    cnt+=1;
    cout << "CNT: " <<cnt<< endl;
}

  return 0 ;
}
