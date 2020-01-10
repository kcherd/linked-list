#include "Header.h"

int menu(bool j)
{
	int variant;
	if (j == 0)
	{
		cout << "* * * * * * * Динамический массив * * * * * * *" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1. Вывод емкости массива\n"
			<< "2. Вывод размера массива\n"
			<< "3. Поиск элемента в массиве по индексу\n"
			<< "4. Поиск элемента в массиве по значению\n"
			<< "5. Вставка значения в конец массива\n"
			<< "6. Вставка значения в указанную позицю\n"
			<< "7. Удаление значения из массива\n"
			<< "8. Удаление значения из указанной позиции\n"
			<< "9. Изменение значения элемента\n"
			<< "10. Индекс элемента\n"
			<< "11. Очищение массива\n"
			<< "12. Проверка на пустоту\n"
			<< "0. Вывод массива на экран\n"
			<< "13. Выход из программы" << endl;
	}
	cout << " >>> ";
	cin >> variant;
	return variant;
}

int main()
{
	setlocale(LC_ALL, "rus");

	int pos, val, num;
	Array <int> arr;
	int variant = menu(0);

	while (variant != 13)
	{

		switch (variant)
		{
		case 1:
			cout << "Вывод емкости массива: " << endl;
			cout << arr.Capacity() << endl;
			break;

		case 2:
			cout << "Вывод размера массива:" << endl;
			cout << arr.Size() << endl;
			break;

		case 3:
			cout << "Поиск по массиву (индекс):" << endl;
			cout << "Введите индекс: ";
			cin >> pos;
			try
			{
				cout << arr.search_pos(pos) << endl;
			}
			catch (ArrayException &exception)
			{
				std::cerr << "An array exception occurred (" << exception.what() << ")\n";
			}
			catch (std::exception &exception)
			{
				std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
			}
			break;

		case 4:
			cout << "Поиск по массиву (значение):" << endl;
			cout << "Введите значение: ";
			cin >> val;
			cout << arr.search_val(val, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 5:
			cout << "Вставка значения в массив:" << endl;
			cout << "Введите значение: ";
			cin >> val;
			arr.push_back(val);
			break;

		case 6:
			cout << "Вставка значения по позиции:" << endl;
			cout << "Введите значение: ";
			cin >> val;
			cout << "Введите индекс: ";
			cin >> pos;
			cout << arr.push_pos(val, pos, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 7:
			cout << "Удаление значения из массива:" << endl;
			cout << "Введите значение: ";
			cin >> val;
			cout << arr.erase(val, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 8:
			cout << "Удаление значения по позиции:" << endl;
			cout << "Введите индекс: ";
			cin >> pos;
			cout << arr.erase_pos(pos, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 9:
			cout << "Изменение значения по позиции:" << endl;
			cout << "Введите значение: ";
			cin >> val;
			cout << "Введите индекс: ";
			cin >> pos;
			cout << arr.change(val, pos) << endl;
			break;

		case 10:
			cout << "Индекс заданного элемента:" << endl;
			cout << "Введите значение: ";
			cin >> val;
			try
			{
				cout << arr.idx_val(val, num) << endl;
				cout << "Num = " << num << endl;
			}
			catch (ArrayException &exception)
			{
				std::cerr << "An array exception occurred (" << exception.what() << ")\n";
			}
			catch (std::exception &exception)
			{
				std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
			}
			break;

		case 11:
			cout << "Очищение массива:" << endl;
			arr.clear();
			break;

		case 12:
			cout << "Проверка массива на пустоту:" << endl;
			cout << arr.is_empty() << endl;
			break;

		case 0:
			cout << "Вывод массива на экран:" << endl;
			arr.show();
			break;

		}
		variant = menu(1);
	}
	system("pause");
	return 0;
}
