#include "square.h"

double line(double b, double c, int* nomber_of_solutions, double* first_solution, double* second_solution)
{ 
    assert(second_solution != NULL);
    assert(first_solution != NULL);
    assert(nomber_of_solutions != NULL);
    assert(isfinite(b) == 1);
    assert(isfinite(c) == 1);

    if (compare(b, 0.0) == EQUAL && compare(c, 0.0) == EQUAL)
    {
        *nomber_of_solutions = INF_ROOTS;
        *first_solution = INFINITY;
        *second_solution = INFINITY;
    }

    else if (compare(b, 0.0) == EQUAL)
    {
        *nomber_of_solutions = 0;
        *first_solution = NAN;
        *second_solution = NAN;
    }     

    else
    {
        *first_solution = -c / b;
        *nomber_of_solutions = 1;
        *second_solution = *first_solution;
    }
    
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

double square(double a, double b, double c, double D, double* first_solution, double* second_solution, int* nomber_of_solutions)

{
    assert(first_solution != NULL);
    assert(second_solution != NULL);
    assert(nomber_of_solutions != NULL);
    assert(isfinite(a) == 1);
    assert(isfinite(b) == 1);
    assert(isfinite(c) == 1);
    if (a==0)
        line(b, c, nomber_of_solutions, first_solution, second_solution);
    else
    {
        discriminant(a, b, c, &D);
        if (discriminant(a, b, c, &D) == 1)
        {
            *first_solution = (-b - D) / (2 * a);
            *second_solution = (-b + D) / (2 * a);

            if(compare(*first_solution, *second_solution) == EQUAL)

                *nomber_of_solutions = 1;

            else

                *nomber_of_solutions = 2;

        }
        else
        {
            *first_solution = NAN;
            *second_solution = NAN;
        }
    }
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bool discriminant(double a, double b, double c, double* D)
{
    assert(D != NULL);
    *D = b * b - 4 * a * c;
    if (compare(*D, 0.0) == LESS)

        return 0;

    else 
    {
        *D = sqrt(*D);
        return 1;
    }

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

double output(int nomber_of_solutions, double first_solution, double second_solution)
{
    if (nomber_of_solutions == 0)
    
        printf("Решений нет\n");

    else if (nomber_of_solutions == 1)
    {
        printf("Корень уравнения\n");
        printf("%lf\n", first_solution);
    }
    else if (nomber_of_solutions == 2)
    {
        printf("Корни уравнения:\n");
        printf("%lf %lf\n", first_solution, second_solution);
    }
    else
         
        printf("Решение - любое число\n");

    return 0;   
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void input_checking (double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    int check = scanf("%lg %lg %lg", a, b, c);  

    while(check != 3)
    {   
        printf("Неверный ввод\n");
        while(getchar() != '\n')
        {
        }
        check = scanf("%lg %lg %lg", a, b, c);
    }
    return;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

double compare(double x, double y)
{
    if (fabs(x-y) <= EPSILON) 
    
        return EQUAL;
    
    else if (x-y > EPSILON)
    
        return MORE;
    
    else
    
        return LESS;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void unit_test(double x1, double x2, double second_solution, double first_solution, int i, double a, double b, double c)
{
    if ( ( (x1 == first_solution) && (x2 == second_solution) ) || ( (isnan(x1) == 1) && (isnan(x2) == 1) && (isnan(first_solution) == 1) && (isnan(second_solution) == 1) ) || ( (x1 == second_solution) && (x2 == first_solution) ) ) 
        {
            printf("Программа работает коректно\n"); 
            printf("%lg %lg %lg %lg\n", first_solution, second_solution, x1, x2);
        }

        else
        {
            printf("Ошибка в тесте, %d\n", i+1); 
            printf("%lg %lg %lg\n", a, b, c);
            printf("Выдаёт:");
            printf("%lg %lg\n", first_solution, second_solution);
            printf("Должен выдавать:");
            printf("%lg %lg\n", x1, x2);
            
        }
}