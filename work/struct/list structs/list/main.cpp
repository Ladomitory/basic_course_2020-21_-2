#include <iostream>

using namespace std;

struct list
{
    int value;
    struct list *next = NULL;
};

class listclass
{
    private:
        int value;
        struct list *next = NULL;
}
/*
Получить доступ к k-му элементу списка, проанализировать
и/или изменить значения его полей.

Включить новый узел перед k- м.

Исключить k-й узел.

Объединить два или более линейных списков в один.

Разбить линейный список на два или более линейных
списков.

Сделать копию линейного списка.

Определить количество узлов.

Выполнить сортировку в возрастающем порядке по
некоторым значениям полей в узлах.

Найти в списке узел с заданным значением в некотором
поле.
*/

struct list * merge(struct list *l1, struct list *l2) //слияние сприсков l1 и l2
{
    struct list *al; //ans list
    while (l1->next != NULL || l2->next != NULL)
    {
        if (l1->value >= l2->value)
        {

        }
    }
}