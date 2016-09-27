#include <stdio.h>  
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
    system("echo \"67\" > /sys/class/gpio/export");
    system("echo \"out\" > /sys/class/gpio/gpio67/direction");
	system("echo \"66\" > /sys/class/gpio/export");
    system("echo \"in\" > /sys/class/gpio/gpio66/direction");

    while(1)  
    {
        system("echo \"1\" > /sys/class/gpio/gpio67/value");
		system("echo \"1\" > /sys/class/leds/beaglebone:green:usr0/brightness");
		system("message='Sortie'");
		system("echo Sortie: $message");
		system("cat /sys/class/gpio/gpio67/value");
		system("echo Entree:");
		system("cat /sys/class/gpio/gpio66/value"); 
		pauseEnSecondes(1);

        system("echo \"0\" > /sys/class/gpio/gpio67/value");
		system("echo \"0\" > /sys/class/leds/beaglebone:green:usr0/brightness");
		system("echo Sortie:");
		system("cat /sys/class/gpio/gpio67/value");
		system("echo Entree:");
		system("cat /sys/class/gpio/gpio66/value");
		pauseEnSecondes(1);
    }
    system("echo \"67\" > /sys/class/gpio/unexport");
	system("echo \"66\" > /sys/class/gpio/unexport");
    return(0);  
}