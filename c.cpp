#include <string.h>                    // заголовок, объявляющий функцию strlen()
#include <iostream>
using namespace std;

int luhn(const char* card_number)   // принимаем в аргументы номер карты
{
	int len = strlen(card_number);    // узнаем длину номера карты
	int digit = 0;                    // текущая цифра в цикле (см. ниже)
	int check_digit = 0;              // переменная, которая будет хранить проверочную цифру
	int i;
	for (i = len - 1; i >= 0; --i)    // главный цикл, в процессе него вычисляется проверочная цифра
	{
		digit = card_number[i] - '0'; // переводим цифру из char в int

		if (i % 2 == 0)               // если позиция цифры чётная, то:
		{
			digit *= 2;               // умножаем цифру на 2

			if (digit > 9)            // согласно алгоритму, ни одно число не должно быть больше 9
				digit -= 9;           // второй вариант сведения к единичному разряду
		}

		check_digit += digit;         // прибавляем к check_digit номера согласно алгоритму
	}

	return check_digit % 10;    // возвращаем проверочное число, вычисленное согласно алгоритму
}

int main(){
char num[] = "4276640540250042";
char *card_num = num;
int result = luhn(card_num); 
cout<< result;
return 0;
}
