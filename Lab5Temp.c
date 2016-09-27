#include <stdlib.h>
#include <time.h>

void pauseEnSecondes(int seconde)
{

  time_t debut, maintenant;

  debut = time(NULL);

  maintenant = time(NULL);

  while ((maintenant - debut < (double)seconde))
  {

    maintenant = time(NULL);

  }
}

int main(void)
{
  while(1){
  system("echo \"1\" > /sys/class/leds/beaglebone:green:usr0/brightness"); 
  pauseEnSecondes(1);
  system("echo \"0\" > /sys/class/leds/beaglebone:green:usr0/brightness");
  pauseEnSecondes(2);
}
}
