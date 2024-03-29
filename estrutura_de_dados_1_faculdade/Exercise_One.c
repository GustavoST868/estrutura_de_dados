//libraries
#include <stdio.h>
#include <locale.h>


int main(){


//normal variables and pointers
int variable_one;
int variable_two;
int *pointer_variable_one = &variable_one;
int *pointer_variable_two = &variable_two;


//receives the values
printf("Inform two values : \n");
scanf("%d%d",&variable_one,&variable_two);


//operations
int sum = *pointer_variable_one + *pointer_variable_two;
int subtraction = *pointer_variable_one - *pointer_variable_two;
int multiplication =  *pointer_variable_one * *pointer_variable_two;
int division = *pointer_variable_one / *pointer_variable_two;

//print all
printf("\n\nResults of operations:\n\nSum = [%d]\nSubtraction = [%d]\nMultiplication = [%d]\nDivision =[%d]\n",sum,subtraction,multiplication,division);
    
return 0;
}
