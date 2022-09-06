#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <cstring>



enum NUMBER_OF_ROOTS
{
    ZERO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
};
enum COMPARE 
{
    EQUAL = 0,
    MORE = 1,
    LESS = 2,
};
const double EPSILON = 1e-5;
/*!
    @brief Данная функция рассматривает случай, когда а = 0, то есть уравнение становится линейным

    Данная функция рассматривает случай, когда а = 0, то есть уравнение становится линейным, и вычисляет его корень (при его наличии) и количество корней уравнения (0, 1, бесконечно много)
    @param[in] b коэффициент при х
    @param[in] c свободный член уравнения
    @param[out] first_solution первый корень уравнения
    @param[out] second_solution второй корень уравнения
    @param[out] nomder_of_solutions количество корней уравнения
    @param[in] NUMBER_OF_ROOTS глобальные переменные, связанные с количеством корней уравнения
    @param[in] COMPARE глобальные переменные, связанные cо сравниванием чисел типа double
    @param[in] EPSILON значение разницы между числами типа double, меньше которого числа считаются равными
*/
double line(double b, double c, int* nomber_of_solutions, double* first_solution, double* second_solution);
/*!
    @brief Данная функция рассмотривает случай, когда уравнения является квадратным

    Данная функция рассмотривает случай, когда уравнения является квадратным, принимая на входе его коэффициенты, она вычисляет корни данного уравнения и их количество (0, 1, 2)
    @param[in] a коэффициент при x^2
    @param[in] b коэффициент при х
    @param[in] c свободный член уравнения
    @param[out] first_solution первый корень уравнения
    @param[out] second_solution второй корень уравнения
    @param[out] nomder_of_solutions количество корней уравнения
*/
double square(double a, double b, double c, double D, double* first_solution, double* second_solution, int* nomber_of_solutions);
/*!
    @brief Данная функция выводит на экран корни уравнения

    Данная функиция получает на входе корни уравнения и их количество. 
    В случае, когда корней нет, она выводит на экран: "Решений нет".
    В случае, когда уравнений имеет единственный корень, она выводит на экран: "Корень уравнения: р", где р это корень уравнения.
    В случае, когда корня два, она вывадит на экран: "Корни уравнения: p, q", где p и q это корни уравнения.
    В случае, когда любое число является корнем уравнения, она выводит на экран: "Любое число".
    @param[in] nomber_of_solutions количество корней уравнения (0, 1, 2, )
    @param[in] first_solution первый корень уравнения
    @param[in] second_solution второй корень уравнения
*/
double output(int nomber_of_solutions, double first_solution, double second_solution);
/*!
    @brief Данная функция проверяет корректны ли введённые данные и вызывает их повторный ввод, если это не так.

    Данная функция получает на входе количество корректно введённых коэфициентов, если это количество не равно 3, то есть не все коэффициенты введены корректно, 
    функция очищает входной буффер и вызывает повторный ввод до тех пор, пока все 3 коэффициента не будут введены корректно.
    @param[in] a коэффициент при x^2
    @param[in] b коэффициент при х
    @param[in] c свободный член уравнения
    @param[in] cheak количество корректно введённых коэффициентов 
    @param[out] a корректный коэффициент при x^2
    @param[out] b корректный коэффициент при х
    @param[out] c корректный свободный член уравнения
*/
void input_checking (double* a, double* b, double* c);

/*!
    Сравнивает 2 числа типа double с точностью digits знаков после запятой

    Данная функция полцчает на входе 2 числа типа double после чего сравновает их между собой с точностью digits знаков после запятой.
    Если модуль их разности меньше точности, функция выдаёт EQUAL.
    Если разность первого и второго больше точности, функция выдаёт MORE.
    В остальных случаях функция выдаёт LESS.
    @param[in] x Первое число
    @param[in] y Второе число
*/
double compare(double x, double y);
/*!
    @brief  Данная функция вычисляет дискриминант квадратного уравнения

    Данная функция принимает на входе коэффициенты a, b, c, вычисляет дискриминант уравнения и на выходе возвращает его значение преременной D.
    @param[in] a коэффициент при x^2
    @param[in] b коэффициент при х
    @param[in] c свободный член уравнения
    @param[out] D дискриминант уравнения
*/
bool discriminant(double a, double b, double c, double* D);
/*!
    @brief 

    @param[in] first_solution первый корень уравнения, выдаваемый программой
    @param[in] second_solution второй корень уравнения, выдаваемый программой 
    @param[in] x1 первый корень уравнения(верный)
    @param[in] x2 второй корень уравнения(верный) 
*/
void unit_test(double x1, double x2, double second_solution, double first_solution, int i, double a, double b, double c);
