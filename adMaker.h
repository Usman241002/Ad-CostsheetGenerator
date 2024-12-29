#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void adMaker(void) {
  char make[50], model[50], reg[8], mot_date[10];
  char folderName[100], fileName[100], path[100], path_fol[100];
  char fuel, gearbox, partex, cat, alloy, service_history, mirrors, windows, heated, folding, brake, sensors, f_sensors;
  char pound = 156, remote, aux, usb, bluetooth, music, controls, cruise, ac, cupholder, leather, heat_seats, nav;
  char camera;
  int mileage, year, owners, gears, dd, mm, yyyy, tax, wheel, keys;
  float cc;
  FILE *fp;

  printf("Reg: ");
  scanf("%s", reg);
  printf("Enter the Make and Model of the Vehicle: ");
  scanf("%s %s", make, model);

  snprintf(folderName, sizeof folderName, "ADS\\%s %s %s", make, model, reg);
  mkdir(folderName);

  printf("Mileage: ");
  scanf("%d", &mileage);
  printf("Engine size: ");
  scanf("%f", &cc);

  do {
    printf("Catergory [X/N/S]: ");
    scanf(" %c", &cat);
    if ((cat != 'X') && (cat != 'x') && (cat != 'N') && (cat != 'n') && (cat != 'S') && (cat != 's')) {
      printf("Error : Please choose [X/N/S] \n");
    }
  } while ((cat != 'X') && (cat != 'x') && (cat != 'N') && (cat != 'n') && (cat != 'S') && (cat != 's'));

  printf("No. of Owners: ");
  scanf("%d", &owners);

  printf("MOT expiry (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &dd, &mm, &yyyy);

  snprintf(mot_date, sizeof mot_date, "%d/%d/%d", dd, mm, yyyy);

  printf("Road tax: %c", pound);
  scanf("%d", &tax);

  do {
    printf("Petrol or Diesel? [p/d]: ");
    scanf(" %c", &fuel);
    if ((fuel != 'P') && (fuel != 'p') && (fuel != 'D') && (fuel != 'd')) {
      printf("Error : Please choose [a/m] \n");
    }
  } while ((fuel != 'P') && (fuel != 'p') && (fuel != 'D') && (fuel != 'd'));

  printf("No. of keys: ");
  scanf("%d", &keys);
  if (keys >= 2) {
    do {
      printf("Remote central locking? [y/n]: ");
      scanf(" %c", &remote);
      if ((remote != 'Y') && (remote != 'y') && (remote != 'N') && (remote != 'n')) {
        printf("Error : Please choose [y/n] \n");
      }
    } while ((remote != 'Y') && (remote != 'y') && (remote != 'N') && (remote != 'n'));

  }

  do {
    printf("Automatic or Manual? [a/m]: ");
    scanf(" %c", &gearbox);
    if ((gearbox != 'A') && (gearbox != 'a') && (gearbox != 'M') && (gearbox != 'm')) {
      printf("Error : Please choose [a/m] \n");
    } else if ((gearbox == 'M') || (gearbox == 'm')) {
      printf("No. of gears: ");
      scanf("%d", &gears);
    }
  } while ((gearbox != 'A') && (gearbox != 'a') && (gearbox != 'M') && (gearbox != 'm'));

  do {
    printf("Is the vehicle Part exchange? [y/n]: ");
    scanf(" %c", &partex);
    if ((partex != 'Y') && (partex != 'y') && (partex != 'N') && (partex != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((partex != 'Y') && (partex != 'y') && (partex != 'N') && (partex != 'n'));

  do {
    printf("Service History [F/P/N]: ");
    scanf(" %c", &service_history);
    if ((service_history != 'F') && (service_history != 'f') && (service_history != 'N') && (service_history != 'n') && (service_history != 'P') && (service_history != 'p')) {
      printf("Error : Please choose [F/P/N] \n");
    }
  } while ((service_history != 'F') && (service_history != 'f') && (service_history != 'N') && (service_history != 'n') && (service_history != 'P') && (service_history != 'p'));

  do {
    printf("Leather Interior? [F/H/N]: ");
    scanf(" %c", &leather);

    if ((leather != 'F') && (leather != 'f') && (leather != 'H') && (leather != 'h') && (leather != 'N') && (leather != 'n')) {
      printf("Error : Please choose [y/n] \n");
    } else if ((leather == 'F') || (leather == 'f') || (leather == 'H') || (leather == 'h')) {
      do {
        printf("Heated Seats? [y/n]: ");
        scanf(" %c", &heat_seats);
        if ((heat_seats != 'Y') && (heat_seats != 'y') && (heat_seats != 'N') && (heat_seats != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((heat_seats != 'Y') && (heat_seats != 'y') && (heat_seats != 'N') && (heat_seats != 'n'));
    }
  } while ((leather != 'F') && (leather != 'f') && (leather != 'H') && (leather != 'h') && (leather != 'N') && (leather != 'n'));

  do {
    printf("Navigation? [y/n]: ");
    scanf(" %c", &nav);
    if ((nav != 'Y') && (nav != 'y') && (nav != 'N') && (nav != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((nav != 'Y') && (nav != 'y') && (nav != 'N') && (nav != 'n'));

  do {
    printf("Electric Handbrake? [y/n]: ");
    scanf(" %c", &brake);
    if ((brake != 'Y') && (brake != 'y') && (brake != 'N') && (brake != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((brake != 'Y') && (brake != 'y') && (brake != 'N') && (brake != 'n'));

  do {
    printf("Reverse Parking Camera? [y/n]: ");
    scanf(" %c", &camera);
    if ((camera != 'Y') && (camera != 'y') && (camera != 'N') && (camera != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((camera != 'Y') && (camera != 'y') && (camera != 'N') && (camera != 'n'));

  do {
    printf("Parking Sensors? [y/n]: ");
    scanf(" %c", &sensors);

    if ((sensors != 'Y') && (sensors != 'y') && (sensors != 'N') && (sensors != 'n')) {
      printf("Error : Please choose [y/n] \n");
    } else if ((sensors == 'Y') || (sensors == 'y')) {
      do {
        printf("Front Parking Sensors? [y/n]: ");
        scanf(" %c", &f_sensors);
        if ((f_sensors != 'Y') && (f_sensors != 'y') && (f_sensors != 'N') && (f_sensors != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((f_sensors != 'Y') && (f_sensors != 'y') && (f_sensors != 'N') && (f_sensors != 'n'));
    }
  } while ((sensors != 'Y') && (sensors != 'y') && (sensors != 'N') && (sensors != 'n'));

  do {
    printf("Steering mounted controls? [y/n]: ");
    scanf(" %c", &controls);

    if ((controls != 'Y') && (controls != 'y') && (controls != 'N') && (controls != 'n')) {
      printf("Error : Please choose [y/n] \n");
    } else if ((controls == 'Y') || (controls == 'y')) {
      do {
        printf("Cruise control? [y/n]: ");
        scanf(" %c", &cruise);
        if ((cruise != 'Y') && (cruise != 'y') && (cruise != 'N') && (cruise != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((cruise != 'Y') && (cruise != 'y') && (cruise != 'N') && (cruise != 'n'));
    }
  } while ((controls != 'Y') && (controls != 'y') && (controls != 'N') && (controls != 'n'));

  do {
    printf("Aux input? [y/n]: ");
    scanf(" %c", &aux);
    if ((aux != 'Y') && (aux != 'y') && (aux != 'N') && (aux != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((aux != 'Y') && (aux != 'y') && (aux != 'N') && (aux != 'n'));

  do {
    printf("USB input? [y/n]: ");
    scanf(" %c", &usb);
    if ((usb != 'Y') && (usb != 'y') && (usb != 'N') && (usb != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((usb != 'Y') && (usb != 'y') && (usb != 'N') && (usb != 'n'));

  do {
    printf("Bluetooth Phone Connectivity? [y/n]: ");
    scanf(" %c", &bluetooth);

    if ((bluetooth != 'Y') && (bluetooth != 'y') && (bluetooth != 'N') && (bluetooth != 'n')) {
      printf("Error : Please choose [y/n] \n");
    } else if ((bluetooth == 'Y') || (bluetooth == 'y')) {
      do {
        printf("Bluetooth Music? [y/n]: ");
        scanf(" %c", &music);
        if ((music != 'Y') && (music != 'y') && (music != 'N') && (music != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((music != 'Y') && (music != 'y') && (music != 'N') && (music != 'n'));
    }
  } while ((bluetooth != 'Y') && (bluetooth != 'y') && (bluetooth != 'N') && (bluetooth != 'n'));

  do {
    printf("Front AND back electric windows? [y/n]: ");
    scanf(" %c", &windows);
    if ((windows != 'Y') && (windows != 'y') && (windows != 'N') && (windows != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((windows != 'Y') && (windows != 'y') && (windows != 'N') && (windows != 'n'));

  do {
    printf("Electric mirrors? [y/n]: ");
    scanf(" %c", &mirrors);

    if ((mirrors != 'Y') && (mirrors != 'y') && (mirrors != 'N') && (mirrors != 'n')) {
      printf("Error : Please choose [y/n] \n");
    } else if ((mirrors == 'Y') || (mirrors == 'y')) {
      do {
        printf("Folding? [y/n]: ");
        scanf(" %c", &folding);
        if ((folding != 'Y') && (folding != 'y') && (folding != 'N') && (folding != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((folding != 'Y') && (folding != 'y') && (folding != 'N') && (folding != 'n'));

      do {
        printf("Heated? [y/n]: ");
        scanf(" %c", &heated);
        if ((heated != 'Y') && (heated != 'y') && (heated != 'N') && (heated != 'n')) {
          printf("Error : Please choose [y/n] \n");
        }
      } while ((heated != 'Y') && (heated != 'y') && (heated != 'N') && (heated != 'n'));
    }
  } while ((mirrors != 'Y') && (mirrors != 'y') && (mirrors != 'N') && (mirrors != 'n'));

  printf("Size of wheel: ");
  scanf("%d", &wheel);

  do {
    printf("Alloy wheels? [y/n]: ");
    scanf(" %c", &alloy);
    if ((alloy != 'Y') && (alloy != 'y') && (alloy != 'N') && (alloy != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((alloy != 'Y') && (alloy != 'y') && (alloy != 'N') && (alloy != 'n'));

  do {
    printf("Air conditioning? [y/n]: ");
    scanf(" %c", &ac);
    if ((ac != 'Y') && (ac != 'y') && (ac != 'N') && (ac != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((ac != 'Y') && (ac != 'y') && (ac != 'N') && (ac != 'n'));

  do {
    printf("Cup Holders? [y/n]: ");
    scanf(" %c", &cupholder);
    if ((cupholder != 'Y') && (cupholder != 'y') && (cupholder != 'N') && (cupholder != 'n')) {
      printf("Error : Please choose [y/n] \n");
    }
  } while ((cupholder != 'Y') && (cupholder != 'y') && (cupholder != 'N') && (cupholder != 'n'));

  snprintf(fileName, sizeof fileName, "AD %s", reg);
  snprintf(path, sizeof path, "%s\\%s", folderName, fileName);

  fp = fopen(path, "w");
  if (fp == NULL) {
    printf("Error opening file, \n\n");
  } else {
    if ((partex == 'Y') || (partex == 'y')) {
      fprintf(fp, "+ + + PART EXCHANGE TO CLEAR + + +, \n\n");
    }

    if ((cat == 'X') || (cat == 'x')) {
    fprintf(fp, "HPI CLEAR WITH A FULL UP TO DATE REPORT, \n\n");
    } else if ((cat == 'N') || (cat == 'n')) {
    fprintf(fp, "RECORDED CATERGORY N, \n\n");
    } else if ((cat == 'S') || (cat == 's')) {
    fprintf(fp, "RECORDED CATERGORY S, \n\n");
  }

    fprintf(fp, "WARRANTED %dK MILES WITH ", mileage / 1000);
    if ((service_history == 'F') || (service_history == 'f')) {
    fprintf(fp, "FULL SERVICE HISTORY, \n\n");
    } else if ((service_history == 'P') || (service_history == 'p')) {
    fprintf(fp, "PART SERVICE HISTORY, \n\n");
    } else if ((service_history == 'N') || (service_history == 'n')) {
    fprintf(fp, "A FULL VOSA HISTORY PRINTOUT, \n\n");
  }

    if (owners <= 4) {
      if (owners <= 1) {
        fprintf(fp, "+ + + %d OWNER + + +, \n\n", owners);
      } else if (owners <= 2) {
        fprintf(fp, "+ %d PREVIOUS OWNER +, \n\n", owners - 1);
      } else if (owners <= 3){
        fprintf(fp, "+ %d PREVIOUS OWNERS +, \n\n", owners - 1);
      } else {
        fprintf(fp, "%d PREVIOUS OWNERS, \n\n", owners - 1);
      }
    }

    fprintf(fp, "%.1fL ", cc);
    if ((fuel == 'P') || fuel == 'p') {
      fprintf(fp, "PETROL ");
    } else if ((fuel == 'D') || fuel == 'd') {
      fprintf(fp, "DIESEL ");
    }
    fprintf(fp, "ENGINE WITH A");
    if ((gearbox == 'M') || (gearbox == 'm')) {
      fprintf(fp, " %d SPEED MANUAL GEARBOX ", gears);
    } else if ((gearbox == 'A') || (gearbox == 'a')) {
      fprintf(fp, "N AUTOMATIC GEARBOX ");
    }
    fprintf(fp, "WHICH WITHOUT A DOUBT PULLS WELL IN ALL GEARS, \n\n");

    fprintf(fp, "MOT EXPIRES: %s, \n\n", mot_date);
    if (tax < 300) {
      if (tax <= 30) {
        fprintf(fp, "+ £%d ROAD TAX FOR THE YEAR +, \n\n", tax);
      } else {
          fprintf(fp, "£%d ROAD TAX FOR THE YEAR, \n\n", tax);
      }
    }

    if (keys > 1) {
      fprintf(fp, "%d", keys);
      if ((remote == 'Y') || (remote == 'y')) {
        fprintf(fp, " REMOTE CENTRAL LOCKING");
      }
      fprintf(fp, " KEYS, \n\n");
    }

    if ((camera == 'Y') || (camera == 'y')) {
      fprintf(fp, "REVERSE PARKING CAMERA, \n\n");
    }

    if ((sensors == 'Y') || (sensors == 'y')) {
      if ((f_sensors == 'Y') || (f_sensors == 'y')) {
        fprintf(fp, "FRONT AND REAR ");
      } else if ((f_sensors == 'N') || (f_sensors == 'n')) {
        fprintf(fp, "REVERSE ");
      }
      fprintf(fp, "PARKING SENSORS, \n\n");
    }

    if ((nav == 'Y') || (nav == 'y')) {
      fprintf(fp, "BUILT IN NAVIGATION SYSTEM, \n\n");
    }

    fprintf(fp, "BUILT-IN ENTERTAINMENT SYSTEM WITH RADIO/CD AND MP3 ");
    if ((aux == 'Y') || (aux == 'y') || (usb == 'Y') || (usb == 'y')) {
      fprintf(fp, "WITH ");
      if (((aux == 'Y') || (aux == 'y')) && ((usb == 'Y') || (usb == 'y'))) {
        fprintf(fp, "AUX/USB INPUT, \n\n");
      } else if (((aux == 'Y') || (aux == 'y')) && ((usb == 'N') || (usb == 'n'))) {
        fprintf(fp, "AUX INPUT, \n\n");
      } else if (((aux == 'N') || (aux == 'n')) && ((usb == 'Y') || (usb == 'y'))) {
        fprintf(fp, "USB INPUT, \n\n");
      }
    } else {
        fprintf(fp, ", \n\n");
    }

    if ((bluetooth == 'Y') || (bluetooth == 'y')) {
      fprintf(fp, "BLUETOOTH READY FOR TELEPHONE CALLS ");
      if ((music == 'Y') || (music == 'y')) {
        fprintf(fp, "AND TO STREAM MUSIC DIRECTLY OFF YOUR SMARTPHONE ");
      }
      fprintf(fp, ", \n\n");
    }

    if ((controls == 'Y') || (controls == 'y')) {
      fprintf(fp, "STEERING MOUNTED CONTROLS, \n\n");
      if ((cruise == 'Y') || (cruise == 'y')) {
        fprintf(fp, "CRUISE CONTROL WITH A SPEED SET LIMITER, \n\n");
      }
    }

    if ((leather == 'F') || (leather == 'f') || (leather == 'H') || (leather == 'h')) {
      if ((leather == 'H') || (leather == 'h')) {
        fprintf(fp, "HALF ");
      } else if ((leather == 'F') || (leather == 'f')) {
        fprintf(fp, "FULL ");
      }
      fprintf(fp, "LEATHER INTERIOR ");
      if ((heat_seats == 'Y') || (heat_seats == 'y')) {
        fprintf(fp, "WITH FRONT HEATED SEATS ");
      }
      fprintf(fp, ", \n\n");
    }

    if ((brake == 'Y') || (brake == 'y')) {
      fprintf(fp, "ELECTRIC HAND BRAKE, \n\n");
    }

    if ((windows == 'Y') || (windows == 'y')) {
      fprintf(fp, "FRONT AND BACK ELECTRIC WINDOWS, \n\n");
    } else if ((windows == 'N') || (windows == 'n')) {
      fprintf(fp, "ELECTRIC WINDOWS, \n\n");
    }

    if ((mirrors == 'Y') || (mirrors == 'y')) {
      if ((heated == 'Y') || (heated == 'y')) {
        fprintf(fp, "HEATED ");
      }
      fprintf(fp, "ELECTRIC ");
      if ((folding == 'Y') || (folding == 'y')) {
        fprintf(fp, "FOLDING ");
      }
      fprintf(fp, "MIRRORS, \n\n");
    }

    if ((ac == 'Y') || (ac == 'y')) {
      fprintf(fp, "AIR CONDITIONING, \n\n");
    }

    if ((cupholder == 'Y') || (cupholder == 'y')) {
      fprintf(fp, "CUPHOLDERS, \n\n");
    }

    fprintf(fp, "%d INCH ", wheel);
    if ((alloy == 'Y') || (alloy == 'y')) {
      fprintf(fp, "ALLOY ");
    }
    fprintf(fp, "WHEELS, \n\n");

    fprintf(fp, "THIS %s HAS A SMOOTH DRIVE WITH NO KNOCKS BANGS SQUEAKS OR RATTLES AND WITH NO FAULTS ON THE DASHBOARD,, \n\n", model);
    fprintf(fp, "SECURE THIS VEHICLE TODAY WITH A £100 DEPOSIT, \n\n");
    fprintf(fp, "WE TAKE ANY CAR IN PART EXCHANGE AT TRADE VALUE, \n\n");
    fprintf(fp, "ANY INDEPENDENT INSPECTIONS ARE WELCOME, \n\n");
    fprintf(fp, "DELIVERY CAN BE ARRANGED NATIONWIDE FOR AN EXTRA COST ONCE THE FUNDS HAVE BEEN CLEARED FOR THE PURCHASED VEHICLE WHICH WE AIM TO DELIVER WITHIN 24 HOUR OF PURCHASE, \n\n");
    fprintf(fp, "PLEASE CALL FOR VIEWING, TEST DRIVES OR ANY FURTHER QUESTIONS, \n\n");
    fprintf(fp, "MOBILE: 0730 508 1597, \n\n");
    fprintf(fp, "+ + + WE ARE OPEN 7 DAYS A WEEK + + + \n\n");
  }
  fclose(fp);
}
