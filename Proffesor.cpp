#include "Proffesor.h"


Proffesor::Proffesor()
{

	cout << "Профессор" << endl;
	try
	{

		setType(3);

		cin.ignore(256, '\n');
		cout << "Фамилия: ";
		getline(cin, this->surename);
		cout << "Имя: ";
		getline(cin, this->name);
		cout << "Отчество: ";
		getline(cin, this->patronim);
		cout << "Предмет который ведет: ";
		getline(cin, this->subjects);
		cout << "Группа у которой ведет: ";
		cin >> this->group;
		setError(false);
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl; setError(true);
	}
}



Proffesor::Proffesor(ifstream& fin)
{

	setType(3);
	fin >> this->group;

	fin.ignore(256, '\n');
	getline(fin, name);
	getline(fin, surename);
	getline(fin, patronim);
	getline(fin, subjects);
}



Proffesor::~Proffesor()
{
	//tut nichego
}



void Proffesor::edit()
{

	try
	{

		int index;
		int iTmp;
		string sTmp;

		cout << "Выберите что вы хотите изменить:" << endl
			<< "1 - Фамилия" << endl
			<< "2 - Имя" << endl
			<< "3 - Отчество" << endl
			<< "4 - Группа" << endl
			<< "5 - Предмет" << endl
			<< " "; cin >> index;
		if (index < 1 || index > 5)
		{

			throw (string)"Нет такого параметра";
		}

		cout << "Текущее значение: ";
		switch (index)
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
			cin >> iTmp;
			patronim = iTmp;
			break;




		case 4:
			cout << group << endl;
			cout << "Новое значение: ";
			cin >> iTmp;
			group = iTmp;
			break;

		case 5:

			cout << subjects << endl;
			cout << "Новое значение:: ";
			cin >> iTmp;
			subjects = iTmp;
			break;
		default:
			break;

		}
		setError(false);
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl;
		setError(true);
	}
}

void Proffesor::save(ofstream& fout)
{

	fout << getType() << endl
		<< this->group << endl
		<< this->name << endl
		<< this->surename << endl
		<< this->patronim << endl
		<< this->subjects << endl;

}

void Proffesor::print(ostream& out)
{

	out << "Профессор" << endl;
	out << "ФИО: " << surename << " " << name << " " << patronim << " " << endl
		<< "Группа: " << this->group << endl
		<< "Предмет: " << this->subjects << endl;
}
