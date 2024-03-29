#include <stdio.h>
#include <string.h>

// cinema structure
struct cinema_ticket
{
    char name[100];
    double value;
    int idex;
};

// Define a struct with a length of 100 spaces
struct cinema_ticket ct[100];

// global variable to determine the account number
int cont = -1;

// function to store data
void Store(char *name, double value)
{
    // add 1 when creating an account
    cont++;

    // stores the data in the correct places
    strcpy(ct[cont].name, name);
    ct[cont].idex = cont;
    ct[cont].value = value;
}

void PrintDataBase()
{
    int i = 0;

    // print organization
    printf("\n\n\n");
    printf("%-5s %-15s %-10s\n", "ID", "Name", "Value");
    printf("---------------------------------\n");

    while (i <= cont) // Check against the valid index range (0 to cont)
    {
        // how the data will be display
        printf("%-5d %-15s R$ %-10.2f\n", ct[i].idex, ct[i].name, ct[i].value);

        i++;
    }

    printf("\n\n\n");
}

// calculate module
int Module(int value)
{
    if (value < 0)
    {
        return value * (-1);
    }
    else
    {
        return value;
    }
}

void Calculate_discount()
{

    int option;

    // check discount
    printf("\nWant to check if there is a discount? [1-yes/2-no]\n");
    scanf("%d", &option);

    // conditionals
    if (option == 1)
    {

        // data system
        int days = 29;
        int months = 7;
        int years = 2024;

        // used variables
        int dayp;
        int monthp;
        int yearp;

        // used variables
        int day;
        int month;
        int year;
        double years_old;

        // get informations
        printf("\nInforme the date of birth :");

        printf("Day:");
        scanf("%d", &day);

        printf("Month:");
        scanf("%d", &month);

        printf("Year:");
        scanf("%d", &year);

        // calculete years old
        dayp = Module(day - days);
        monthp = Module(month - months);
        yearp = Module(year - years);
        years_old = (dayp + (monthp * 30) + (yearp * 365)) / 365;

        // Years old conditional
        if (years_old > 12)
        {

            // criar uma função para interligar o nome da pessoa na struct com o indice e retorna-lo para modificar o valor com o desconto.
        }
        else
        {
                }
    }
    else
    {
        printf("Tanks!!!");
    }
}

int main()
{
    // names test
    char name[100] = "Gustavo";
    char name2[100] = "Gabriel";
    char name3[100] = "Bob";
    char name4[100] = "David";
    char name5[100] = "Emma";
    char name6[100] = "Frank";
    char name7[100] = "Henry";

    // store names and tickets values
    Store(name, 13);
    Store(name2, 26);
    Store(name3, 26);
    Store(name4, 13);
    Store(name5, 13);
    Store(name6, 26);
    Store(name7, 26);

    // function to print database
    PrintDataBase();

    return 0;
}
