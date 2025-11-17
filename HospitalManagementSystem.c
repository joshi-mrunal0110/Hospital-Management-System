#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

// ANSI color codes
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_BROWN "\x1b[33;2m"
#define ANSI_COLOR_RESET "\x1b[0m"

struct patient
{
    int id;
    char patientName[50];
    char patientAddress[50];
    char disease[50];
    char date[12];
} p;

struct doctor
{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
} d;

FILE *fp;

void admitPatient()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("patient.txt", "ab");

    printf("Enter Patient id: ");
    scanf("%d", &p.id);

    printf("Enter Patient name: ");
    fflush(stdin);
    gets(p.patientName);

    printf("Enter Patient Address: ");
    fflush(stdin);
    gets(p.patientAddress);

    printf("Enter Patient Disease: ");
    fflush(stdin);
    gets(p.disease);

    printf(ANSI_COLOR_GREEN "\nPatient Added Successfully\n" ANSI_COLOR_RESET);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void patientList()
{

    system("cls");
    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Patient Name", "Address", "Disease", "Date");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patient.txt", "rb");
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf(ANSI_COLOR_MAGENTA "%-10d %-30s %-30s %-20s %s\n", p.id, p.patientName, p.patientAddress, p.disease, p.date ,ANSI_COLOR_RESET);
    }

    fclose(fp);
}

void dischargePatient()
{
    int id, f = 0;
    system("cls");
    printf("<== Discharge Patient ==>\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {

        if (id == p.id)
        {
            f = 1;
        }
        else
        {
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if (f == 1)
    {
        printf(ANSI_COLOR_GREEN "\n\nPatient Discharged Successfully.\n" ANSI_COLOR_RESET);
    }
    else
    {
        printf(ANSI_COLOR_RED "\n\nRecord Not Found !\n" ANSI_COLOR_RESET);
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");
}

void addDoctor()
{

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    int f = 0;

    system("cls");
    printf("<== Add Doctor ==>\n\n");

    fp = fopen("doctor.txt", "ab");

    printf("Enter Doctor id: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    fflush(stdin);
    gets(d.name);

    printf("Enter Doctor Address: ");
    fflush(stdin);
    gets(d.address);

    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);

    printf(ANSI_COLOR_GREEN "\nDoctor Added Successfully\n\n" ANSI_COLOR_RESET);

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}

void doctorList()
{
    system("cls");
    printf("<== Doctor List ==>\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Address", "Specialize", "Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.address, d.specialize, d.date);
    }

    fclose(fp);
}

int main()
{

    int ch;

    while (1)
    {
        system("cls");
        printf(ANSI_COLOR_CYAN "<== Hospital Management System ==>\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "1.Admit Patient\n");
        printf("2.Patient List\n");
        printf("3.Discharge Patient\n");
        printf("4.Add Doctor\n");
        printf("5.Doctors List\n");
        printf("0.Exit\n\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "Enter your choice: " ANSI_COLOR_RESET);
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            exit(0);

        case 1:
            admitPatient();
            break;

        case 2:
            patientList();
            break;

        case 3:
            dischargePatient();
            break;

        case 4:
            addDoctor();
            break;

        case 5:
            doctorList();
            break;

        default:
            printf(ANSI_COLOR_RED "Invalid Choice...\n\n" ANSI_COLOR_RESET);
        }
        printf(ANSI_COLOR_BROWN "\n\nPress Any Key To Continue..." ANSI_COLOR_RESET);
        getch();
    }

    return 0;
}