#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void fileMaker(void) {
  char make[50], model[50], reg[100], folderName[100], fileName[100];
  char path[100], purchaseDate[20], loc[2];
  int dd, mm, yyyy, del, cost, delCost, total;
  FILE *fp;

  printf("Reg: ");
  scanf("%s", reg);
  printf("Enter the Make and Model of the Vehicle: ");
  scanf("%s %s", make, model);

  printf("Date of purchase: ");
  scanf("%d/%d/%d", &dd, &mm, &yyyy);

  printf("Cost: ");
  scanf("%d", &cost);

  do {
    printf("Delivery location: \n");
    printf("(1)\tPB\n");
    printf("(2)\tWL\n");
    printf("(3)\tWV\n");
    printf("(4)\tMM\n");
    printf("(5)\tNT\n");
    printf("(6)\tDB\n");
    printf("(7)\tN/A\n");
    scanf("%d", &del);

    switch (del) {
      default:
        printf("Error - Please choose a number from the list \n");
        del = 0;
        break;
      case 1:
        delCost = 20;
        strcpy(loc, "PB");
        break;
      case 2:
        delCost = 40;
        strcpy(loc, "WL");
        break;
      case 3:
        delCost = 40;
        strcpy(loc, "WV");
        break;
      case 4:
        delCost = 40;
        strcpy(loc, "MM");
        break;
      case 5:
        delCost = 65;
        strcpy(loc, "NT");
        break;
      case 6:
        delCost = 65;
        strcpy(loc, "DB");
        break;
      case 7:
        delCost = 0;
        break;
    }
  } while (del == 0);

  total = cost + delCost;

  snprintf(folderName, sizeof folderName, "COSTSHEETS\\%s %s %s", make, model, reg);
  mkdir(folderName);

  snprintf(fileName, sizeof fileName, "COST %s", reg);
  snprintf(path, sizeof path, "%s\\%s", folderName, fileName);

  fp = fopen(path, "w");
  if (fp == NULL) {
    printf("Error creating Costsheet \n");
  } else {
    fprintf(fp, "COST %s \n\n", reg);
    fprintf(fp, "DATE\t\t\t£££\t\tMISC\n");
    fprintf(fp, "%d/%d/%d\t\t%d\t\tCOST\n", dd, mm, yyyy, cost);
    if (delCost != 0) {
      fprintf(fp, "\t\t\t%d\t\tDEL %s\n", delCost, loc);
    }
    fprintf(fp, "\n");
    fprintf(fp, "\t\t\t%d\t\tTOTAL \n\n", total);
    fprintf(fp, "\t\t\t\t\tSOLD \n");
    fprintf(fp, "\t\t\t\t\tPROFIT \n");
  }
  fclose(fp);
}
