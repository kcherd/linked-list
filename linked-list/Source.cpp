#include "Header.h"

int menu(bool j)
{
	int variant;
	if (j == 0)
	{
		cout << "* * * * * * * ������������ ������ * * * * * * *" << endl;
		cout << "�������� ��������:" << endl;
		cout << "1. ����� ������� �������\n"
			<< "2. ����� ������� �������\n"
			<< "3. ����� �������� � ������� �� �������\n"
			<< "4. ����� �������� � ������� �� ��������\n"
			<< "5. ������� �������� � ����� �������\n"
			<< "6. ������� �������� � ��������� ������\n"
			<< "7. �������� �������� �� �������\n"
			<< "8. �������� �������� �� ��������� �������\n"
			<< "9. ��������� �������� ��������\n"
			<< "10. ������ ��������\n"
			<< "11. �������� �������\n"
			<< "12. �������� �� �������\n"
			<< "0. ����� ������� �� �����\n"
			<< "13. ����� �� ���������" << endl;
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
			cout << "����� ������� �������: " << endl;
			cout << arr.Capacity() << endl;
			break;

		case 2:
			cout << "����� ������� �������:" << endl;
			cout << arr.Size() << endl;
			break;

		case 3:
			cout << "����� �� ������� (������):" << endl;
			cout << "������� ������: ";
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
			cout << "����� �� ������� (��������):" << endl;
			cout << "������� ��������: ";
			cin >> val;
			cout << arr.search_val(val, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 5:
			cout << "������� �������� � ������:" << endl;
			cout << "������� ��������: ";
			cin >> val;
			arr.push_back(val);
			break;

		case 6:
			cout << "������� �������� �� �������:" << endl;
			cout << "������� ��������: ";
			cin >> val;
			cout << "������� ������: ";
			cin >> pos;
			cout << arr.push_pos(val, pos, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 7:
			cout << "�������� �������� �� �������:" << endl;
			cout << "������� ��������: ";
			cin >> val;
			cout << arr.erase(val, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 8:
			cout << "�������� �������� �� �������:" << endl;
			cout << "������� ������: ";
			cin >> pos;
			cout << arr.erase_pos(pos, num) << endl;
			cout << "Num = " << num << endl;
			break;

		case 9:
			cout << "��������� �������� �� �������:" << endl;
			cout << "������� ��������: ";
			cin >> val;
			cout << "������� ������: ";
			cin >> pos;
			cout << arr.change(val, pos) << endl;
			break;

		case 10:
			cout << "������ ��������� ��������:" << endl;
			cout << "������� ��������: ";
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
			cout << "�������� �������:" << endl;
			arr.clear();
			break;

		case 12:
			cout << "�������� ������� �� �������:" << endl;
			cout << arr.is_empty() << endl;
			break;

		case 0:
			cout << "����� ������� �� �����:" << endl;
			arr.show();
			break;

		}
		variant = menu(1);
	}
	system("pause");
	return 0;
}
