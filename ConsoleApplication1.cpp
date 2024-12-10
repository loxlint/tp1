#include <iostream> 
#include "Keeper.h" 
#include "windows.h" 
using namespace std;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Keeper Konten;
	int menu;
	do
	{

		system("cls");

		cout << "Данных в массиве - " << Konten.getSize() << endl

			<< "1 - добавить" << endl
			<< "2 - удалить" << endl
			<< "3 - сохранить в файле" << endl
			<< "4 - загрузить из файла" << endl
			<< "5 - изменить" << endl
			<< "6 - вывести" << endl
			<< "0 - выход" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:

			Konten.add();
			break;
		case 2:

			Konten.del();
			break;

		case 3:

			Konten.save();
			break;

		case 4:

			Konten.load();
			break;


		case 5:

			Konten.edit();
			break;


		case 6:

			cout << Konten;
			break;



		case 0:
			return 0;

		default:
			break;

		}
	} while (true);
}

