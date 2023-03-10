#include <stdbool.h> // для типа bool            
#include <string.h> // для strlen()
#include <stdio.h>
bool checkLuhn(const char* card_number) // принимаем в аргументы номер карты
{
    int len = strlen(card_number);      // узнаем длину номера карты
    int number = 0;                     // текущая цифра в цикле (см. ниже)
    int sum = 0;                        // переменная, которая будет хранить проверочную сумму цифр

    for(int i = 0; i < len; i++)        // главный цикл, в процессе которого проверяется валидность номера карты
    {
        number = card_number[i] - '0';  // переводим цифру из char в int

        if((i & 1) == 0)                // если позиция цифры чётная, то:
        {
            number *= 2;                // умножаем цифру на 2

            if(number > 9)              // согласно алгоритму, ни одно число не должно быть больше 9
            {
                number -= 9;            // второй вариант сведения к единичному разряду
            }
        }

        sum += number;                  // прибавляем к sum номера согласно алгоритму

        if(sum >= 10)                   // если сумма больше либо 10
        {
            sum -= 10;                  // вычитаем из суммы 10, т. к. последняя цифра не изменится
        }
    }    return sum == 0;                    // вернуть, равна ли последняя цифра нулю
}

int main()
{
 char num[] = "4276640540250042";
 char* card_num = num;
 int result = checkLuhn(card_num);
 printf("%d\n", result);
 return 0;
}
