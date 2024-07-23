#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct expenseentry {
    char descrip[30];
    unsigned int amount;
};

typedef struct expenseentry EE;

int getmonth();

void getexpentry(EE *ee) {
    printf("\nEnter the amount (in Rs. and integer only) : ");
    scanf("%u", &ee->amount);
    printf("\nEnter the description (upto 30 characters) : ");
    scanf("%s", &ee->descrip);
}

void addentry(EE ee) {
    int day, month, year;
    FILE *exl;
    exl = fopen("expenselist.CSV", "a");

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    day = tm_info->tm_mday;
    month = tm_info->tm_mon + 1;
    year = tm_info->tm_year + 1900;

    fprintf(exl, "\n%s,%u,%d,%d,%d", ee.descrip, ee.amount, day, month, year);
    fclose(exl);
}

void printallexp() {
    char line[60];
    EE e;
    char *sp;
    int n = 0;
    int ta, d, m, y;
    long unsigned int total = 0;
    FILE *exl;
    exl = fopen("expenselist.CSV", "r");

    if (exl == NULL) {
        printf("\nERROR while opening expense file!!!");
    } else {
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        printf("\n DESCRIPTION\t\t|\tAMOUNT\t\t|\tDATE");
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        while (fgets(line, 60, exl) != NULL) {
            sp = strtok(line, ",");
            strcpy(e.descrip, sp);
            sp = strtok(NULL, ",");
            ta = atoi(sp);
            sp = strtok(NULL, ",");
            d = atoi(sp);
            sp = strtok(NULL, ",");
            m = atoi(sp);
            sp = strtok(NULL, ",");
            y = atoi(sp);

            n++;
            total += ta;
            if (strlen(e.descrip) < 8) {
                printf("\n%s\t\t\t|\t", e.descrip);
                if (ta > 999999)
                    printf("%u\t|\t", ta);
                else
                    printf("%u\t\t|\t", ta);
                printf("%d/%d/%d", d, m, y);
            } else if (strlen(e.descrip) > 23) {
                printf("\n%s\t", e.descrip);
                if (ta > 999999)
                    printf("%u\t|\t", ta);
                else
                    printf("%u\t\t|\t", ta);
                printf("%d/%d/%d", d, m, y);
            } else if (strlen(e.descrip) > 15) {
                printf("\n%s\t|\t", e.descrip);
                if (ta > 999999)
                    printf("%u\t\t", ta);
                else
                    printf("%u\t\t|\t", ta);
                printf("%d/%d/%d", d, m, y);
            } else if (strlen(e.descrip) > 7) {
                printf("\n%s\t\t|\t", e.descrip);
                if (ta > 999999)
                    printf("%u\t\t", ta);
                else
                    printf("%u\t\t|\t", ta);
                printf("%d/%d/%d", d, m, y);
            }
        }
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        printf("\nTOTAL NUMBER OF EXPENSE ENTRIES STORED : %d", n);
        printf("\nTOTAL EXPENSE TILL NOW : %d", total);
    }
    printf("\n");
    fclose(exl);
    exl = 0;
}

void printmonthexp(int month) {
    char line[60];
    EE e;
    char *sp;
    int n = 0;
    int ta, d, m, y;
    long unsigned int total = 0;
    FILE *exl;
    exl = fopen("expenselist.CSV", "r");

    if (exl == NULL) {
        printf("\nERROR while opening expense file!!!");
    } else {
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        printf("\n DESCRIPTION\t\t|\tAMOUNT\t\t|\tDATE");
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        while (fgets(line, 60, exl) != NULL) {
            sp = strtok(line, ",");
            strcpy(e.descrip, sp);
            sp = strtok(NULL, ",");
            ta = atoi(sp);
            sp = strtok(NULL, ",");
            d = atoi(sp);
            sp = strtok(NULL, ",");
            m = atoi(sp);
            sp = strtok(NULL, ",");
            y = atoi(sp);

            if (m == month) {
                n++;
                total += ta;
                if (strlen(e.descrip) < 8) {
                    printf("\n%s\t\t\t|\t", e.descrip);
                    if (ta > 999999)
                        printf("%u\t|\t", ta);
                    else
                        printf("%u\t\t|\t", ta);
                    printf("%d/%d/%d", d, m, y);
                } else if (strlen(e.descrip) > 23) {
                    printf("\n%s\t", e.descrip);
                    if (ta > 999999)
                        printf("%u\t|\t", ta);
                    else
                        printf("%u\t\t|\t", ta);
                    printf("%d/%d/%d", d, m, y);
                } else if (strlen(e.descrip) > 15) {
                    printf("\n%s\t|\t", e.descrip);
                    if (ta > 999999)
                        printf("%u\t\t", ta);
                    else
                        printf("%u\t\t|\t", ta);
                    printf("%d/%d/%d", d, m, y);
                } else if (strlen(e.descrip) > 7) {
                    printf("\n%s\t\t|\t", e.descrip);
                    if (ta > 999999)
                        printf("%u\t|\t", ta);
                    else
                        printf("%u\t\t|\t", ta);
                    printf("%d/%d/%d", d, m, y);
                }
            }
        }
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
               "- - - - -");
        printf("\nTOTAL NUMBER OF EXPENSE ENTRIES STORED : %d", n);
        printf("\nTOTAL EXPENSE TILL NOW : %d", total);
        printf("\n");
    }
    fclose(exl);
    exl = 0;
}

void printtotalexp() {
    int ch, m;
    printf("\nDo you want all expense till now ?(1)\nOR\nExpense of a "
           "particular month ?(2)");
    printf("\nEnter yout choice 1/2 (integer number only) : ");
    scanf("%d", &ch);
    char line[60];
    char *sp;
    int ta = 0, n = 0;
    long unsigned int total = 0;
    FILE *exl;
    exl = fopen("expenselist.CSV", "r");

    if (exl == NULL) {
        printf("\nERROR while opening expense file!!!");
    } else {
        switch (ch) {
        case 1: {
            while (fgets(line, 60, exl) != NULL) {
                sp = strtok(line, ",");
                sp = strtok(NULL, ",");
                ta = atoi(sp);
                total += ta;
            }
            printf("\nTOTAL EXPENSE TILL NOW : %d", total);
            break;
        }
        case 2: {
            int d, m;
            int mnt = getmonth();
            while (fgets(line, 60, exl) != NULL) {
                sp = strtok(line, ",");
                sp = strtok(NULL, ",");
                ta = atoi(sp);
                sp = strtok(NULL, ",");
                d = atoi(sp);
                sp = strtok(NULL, ",");
                m = atoi(sp);
                if (m == mnt)
                    total += ta;
            }
            printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - "
                   "- - - - - - -");
            printf("\nTOTAL EXPENSE IN MONTH %d : %d", mnt, total);
        }
        }
    }
    printf("\n");
    fclose(exl);
    exl = 0;
}

int getmonth() {
    int month;
    printf("List of month :");
    printf("\n1.JAN\t2.FEB\t3.MAR\t4.APR");
    printf("\n5.MAY\t6.JUN\t7.JUL\t8.AUG");
    printf("\n9.SEP\t10.OCT\t11.NOV\t12.DEC");
    printf("\nEnter the month number (integer number only): ");
    scanf("%d", &month);
    return month;
}

void headerprint() {
    printf("\n*****************************************************************"
           "**************************************************************");
    printf(
        "  \n \t \t \t\t \t KONKAN GYANPEETH COLLEGE OF ENGINEERING KARJAT\n");

    printf("*******************************************************************"
           "************************************************************\n");
    printf("______                               _   _____                     "
           "            _____              _             \n");
    printf("| ___ \\                             | | |  ___|                   "
           "            |_   _|            | |            \n");
    printf("| |_/ /__ _ __ ___  ___  _ __   __ _| | | |____  ___ __   ___ _ __ "
           " ___  ___    | |_ __ __ _  ___| | _____ _ __ \n");
    printf("|  __/ _ \\ '__/ __|/ _ \\| '_ \\ / _` | | |  __\\ \\/ / '_ \\ / _ "
           "\\ '_ \\/ __|/ _ \\   | | '__/ _` |/ __| |/ / _ \\ '__|\n");
    printf("| | |  __/ |  \\__ \\ (_) | | | | (_| | | | |___>  <| |_) |  __/ | "
           "| \\__ \\  __/   | | | | (_| | (__|   <  __/ |   \n");
    printf("\\_|  \\___|_|  |___/\\___/|_| |_|\\__,_|_| \\____/_/\\_\\ .__/ "
           "\\___|_| |_|___/\\___|   \\_/_|  \\__,_|\\___|_|\\_\\___|_|   \n");
    printf("                                                  | |              "
           "                                             \n");
    printf("                                                  |_|              "
           "                                             \n");
    printf("-------------------------------------------------------------------"
           "------------------------------------------------------------\n");

    printf("\nProject by :\n");
    printf("\tVINAYAK LAD ->( 27 )\n");
    printf("\tKAUSTUBH RAJE ->( 49 )\n");
    printf("\tMAYUR SAVDEKAR ->( 55 )\n");
    printf("\tTANUSH TAMBE ->( 60 )\n");
    printf("\n");

    time_t t;
    time(&t);
    printf(" DATE AND TIME : %s", ctime(&t));
    printf("\n*****************************************************************"
           "**************************************************************");
}

void footerprint() {
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nTHANK YOU FOR USING THE PERSONAL EXPENSE TRACKER !");
    printf("\n    WE HOPE YOU KEEP TRACKING YOUR FINANCES !");
    printf("\n\t       HAVE A NICE DAY !");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void printmenu() {
    printf("\nM E N U of operations : ");
    printf("\n1. Add new Expense entry\t\t2. View all expense till now");
    printf("\n3. View expense of a month\t\t4. Get total expense");
    printf("\n5. Save & exit");
}

void main() {
    int ch = 1, c;
    EE ee;
    FILE *exl;
    exl = fopen("expenselist.CSV", "a");

    headerprint();
    printmenu();
    while (ch) {
        printf("\nEnter your choice of operation (integer number only) : ");
        scanf("%d", &c);
        switch (c) {
        case 1: {
            getexpentry(&ee);
            addentry(ee);
            printf("\nExpense added successfully !\n");
            break;
        }
        case 2: {
            printallexp();
            printf("\nAll expense printed successfully !\n");
            break;
        }

        case 3: {
            int m = getmonth();
            printmonthexp(m);
            break;
        }

        case 4: {
            printtotalexp();
            break;
        }
        case 5: {
            ch = 0;
            break;
        }
        default:
            printf("\nPlease enter VALID CHOICE... and try again");
        }
    }
    fclose(exl);
    exl = 0;
    footerprint();
}