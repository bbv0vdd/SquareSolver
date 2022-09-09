#include "functions_square.h"
    #ifdef TEST
int main(const int argc, const char **argv)
{
    double a = 0, b = 0, c = 0; 
    double D = 0;
    double first_solution = NAN, second_solution = NAN;
    int nomber_of_solutions = 0;
    

    double x1; double x2;
    char file_name[255];
    if (argc == 1)
        strcpy(file_name, "test.txt");
    else
        strcpy(file_name, argv[1]);
    FILE *test = fopen(file_name, "r");
    int i = 0;
    while (feof(test) == 0)
    {
        fscanf(test,"%lg %lg %lg %lg %lg", &a, &b, &c, &x1, &x2);
        square(a, b, c, D, &first_solution, &second_solution, &nomber_of_solutions);
        i++;
        unit_test(x1, x2, second_solution, first_solution, i, a, b, c);
    }

    #else 
    int main()
    {
        double a = 0, b = 0, c = 0; 
        double D = 0;
        double first_solution = NAN, second_solution = NAN;
        int nomber_of_solutions = 0;
        printf ("Введите коэффициенты a, b, c\n");
        input_checking(&a, &b, &c);
        if (compare(a, 0.0) == EQUAL)
    
            line (b, c, &nomber_of_solutions, &first_solution, &second_solution);

        else
    
            square(a, b, c, D, &first_solution, &second_solution, &nomber_of_solutions);
    
        output(nomber_of_solutions, first_solution, second_solution);
    #endif

    return 0;
}



