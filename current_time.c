/* localtime example */
#include <stdio.h>
#include <time.h>

int main ()
{
  time_t rawtime;
  // pointer 
//   struct tm * timeinfo;
struct tm * grabtime;

  time ( &rawtime );
  //timeinfo = localtime ( &rawtime );
  grabtime = localtime(&rawtime);
  //asctime: converts date and time to a string
  printf ( "Current local time and date: %s", asctime (grabtime) );

  return 0;
}