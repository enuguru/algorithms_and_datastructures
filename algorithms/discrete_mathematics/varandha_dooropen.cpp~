
#include <iostream>
#include <math.h>
using namespace std;

// this function tells us which door is open

bool is_door_open(const int &doornumber)
{
      double sqrt_of_doornumber = sqrt(doornumber);
      int floor_sqrt_of_doornumber = floor(sqrt_of_doornumber);
      return(floor_sqrt_of_doornumber * floor_sqrt_of_doornumber == doornumber);
}
     

int main()
{
     cout << "The doors that are open are" ;
     for(int doornumbercount = 1; doornumbercount <= 1000; doornumbercount++)
     {
        if(is_door_open(doornumbercount)) 
            cout  << " " <<  doornumbercount << " " ;
     }
     cout << endl;
}
