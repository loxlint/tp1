#include "Stuff.h"

Stuff::Stuff()
{

	cout << "Персонал" << endl; try
	{

		setType(2);

		cin.ignore(256, '\n');
		cout << "Фамилия: ";
		getline(cin, this->surename);
		cout << "Имя: ";
		getline(cin, this->name);
		cout << "Отчество: ";
		getline(cin, this->patronim);
		cout << "Должность: ";
		getline(cin, this->role);
		cout << "Телефон: ";
		getline(cin, this->phone);
		cout << "Ответственность: ";
		getline(cin, this->expertise);
		setError(false);
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl; setError(true);
	}
}



Stuff::Stuff(ifstream& fin)
{

	setType(2);
	fin.ignore(256, '\n');
	getline(fin, surename);
	getline(fin, name);
	getline(fin, patronim);
	getline(fin, role);
	getline(fin, phone);
	getline(fin, expertise);
}



Stuff::~Stuff()
{

	cout << "Деструктор" << endl; system("pause");
}



void Stuff::edit()
{


	try
	{

		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "1 - Фамилия" << endl
			<< "2 - Имя" << endl
			<< "3 - Отчество" << endl
			<< "4 - Должность" << endl
			<< "5 - Телефон" << endl
			<< "6 - Ответственность" << endl
			<< ": "; cin >> index;

		if (index < 1 || index > 6)
		{

			throw (string)"Нет такого параметра";
		}

		cout << "Текущее значение: "; switch (index)
		{
		case 1:
			cout << surename << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);

			surename = sTmp;
			break;
		case 2:
			cout << name << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			name = sTmp;
			break;

		case 3:
			cout << patronim << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			patronim = sTmp;
			break;

		case 4:


			cout << role << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			role = sTmp;
			break;

		case 5:

			cout << phone << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			phone = sTmp;
			break;


		case 6:

			cout << expertise << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			expertise = sTmp;
			break;
		default:
			break;

		}
		setError(false);
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl; setError(true);
	}
}



void Stuff::save(ofstream& fout)
{

	fout << getType() << endl
		<< this->name << endl
		<< this->surename << endl
		<< this->patronim << endl
		<< this->role << endl
		<< this->phone << endl
		<< this->expertise << endl;
}



void Stuff::print(ostream& out)
{

	out << "Сотрудник" << endl
		<< "ФИО: " << surename << " " << name << " " << patronim << endl
		<< "Должность: " << this->role << endl;
	out << "Телефон: " << this->phone << endl
		<< "Ответсвенность: " << this->expertise << endl;
}
