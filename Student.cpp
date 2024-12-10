#include "Student.h"


Student::Student()
{

	cout << "Студент" << endl;
	cout << "Введите данные студента:" << endl;
	try
	{

		setType(1);

		cin.ignore(256, '\n');
		cout << "Фамилия: ";
		getline(cin, this->surename);
		cout << "Имя: ";
		getline(cin, this->name);
		cout << "Отчество: ";
		getline(cin, this->patronim);
		cout << "Специальность: ";
		getline(cin, this->specialtyName);

		cout << "Группа: ";
		cin >> this->group;

		cout << "Курс: ";
		cin >> this->year;

		cout << "Средний бал: ";
		cin >> this->score;

		setError(false);
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl; setError(true);
	}
}



Student::Student(ifstream& fin)
{

	setType(1);
	fin >> this->year
		>> this->group
		>> this->score;

	fin.ignore(256, '\n');
	getline(fin, name);
	getline(fin, surename);
	getline(fin, patronim);
	getline(fin, specialtyName);
}



Student::~Student()
{

	cout << "Деструктор" << endl;
	system("pause");
}



void Student::edit()
{


	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения" << endl
			<< "1 - имя" << endl
			<< "2 - фамилия" << endl
			<< "3 - отчество" << endl

			<< "4 - Специальнотсь" << endl
			<< "5 - Курс обучения" << endl
			<< "6 - средний бал" << endl
			<< " "; cin >> index;
		if (index < 1 || index > 6)
		{

			throw (string)"Нет такого параметра";
		}

		cout << "Текущее значение: ";
		switch (index)
		{
		case 1:

			cout << name << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			name = sTmp;
			break;

		case 2:
			cout << surename << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			surename = sTmp;
			break;
		case 3:

			cout << patronim << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			patronim = sTmp;
			break;



		case 4:

			cout << specialtyName << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			specialtyName = sTmp;
			break;
		case 5:

			cout << year << endl;
			cout << "Новое значение: ";
			cin >> iTmp;

			year = iTmp;
			break;

		case 6:
			cout << score << endl;
			cout << "Новое значение: ";
			cin >> iTmp;

			score = iTmp;
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



void Student::save(ofstream& fout)
{

	fout << getType() << endl
		<< this->year << endl
		<< this->group << endl
		<< this->score << endl
		<< this->name << endl
		<< this->surename << endl
		<< this->patronim << endl
		<< this->specialtyName << endl;
}



void Student::print(ostream& out)
{

	out << "Студент" << endl
		<< "ФИО " << surename << " " << name << " " << patronim << endl
		<< "Специальность: " << specialtyName << endl
		<< "Группа: " << group << endl
		<< "Курс: " << year << endl
		<< "Срудний балл: " << score << endl;
}
