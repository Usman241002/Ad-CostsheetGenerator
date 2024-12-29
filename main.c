#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "adMaker.h"
#include "fileMaker.h"

int main (void) {
  int menu;

  do {
    printf("Select an option from the list: \n\n");
    printf("(1)\tCreate a folder + costsheet for a vehicle\n");
    printf("(2)\tCreate an ad for a vehicle\n");
    printf("(3)\tExit Menu\n");
    printf("\n");
    scanf("%d", &menu);
    printf("\n");

    switch (menu) {
      case 1:
        fileMaker();
        menu = 0;
        printf("\n");
        break;
      case 2:
        adMaker();
        printf("\n");
        menu = 0;
        break;
      case 3:
        menu = 4;
        break;
      default:
        printf("Error - ");
        menu = 0;
        break;
    }
  } while (menu == 0);
  return 0;
}
