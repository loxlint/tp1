#include "Student.h"


Student::Student()
{

	cout << "�������" << endl;
	cout << "������� ������ ��������:" << endl;
	try
	{

		setType(1);

		cin.ignore(256, '\n');
		cout << "�������: ";
		getline(cin, this->surename);
		cout << "���: ";
		getline(cin, this->name);
		cout << "��������: ";
		getline(cin, this->patronim);
		cout << "�������������: ";
		getline(cin, this->specialtyName);

		cout << "������: ";
		cin >> this->group;

		cout << "����: ";
		cin >> this->year;

		cout << "������� ���: ";
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

	cout << "����������" << endl;
	system("pause");
}



void Student::edit()
{


	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������" << endl
			<< "1 - ���" << endl
			<< "2 - �������" << endl
			<< "3 - ��������" << endl

			<< "4 - �������������" << endl
			<< "5 - ���� ��������" << endl
			<< "6 - ������� ���" << endl
			<< " "; cin >> index;
		if (index < 1 || index > 6)
		{

			throw (string)"��� ������ ���������";
		}

		cout << "������� ��������: ";
		switch (index)
		{
		case 1:

			cout << name << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			name = sTmp;
			break;

		case 2:
			cout << surename << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			surename = sTmp;
			break;
		case 3:

			cout << patronim << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			patronim = sTmp;
			break;



		case 4:

			cout << specialtyName << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			specialtyName = sTmp;
			break;
		case 5:

			cout << year << endl;
			cout << "����� ��������: ";
			cin >> iTmp;

			year = iTmp;
			break;

		case 6:
			cout << score << endl;
			cout << "����� ��������: ";
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

	out << "�������" << endl
		<< "��� " << surename << " " << name << " " << patronim << endl
		<< "�������������: " << specialtyName << endl
		<< "������: " << group << endl
		<< "����: " << year << endl
		<< "������� ����: " << score << endl;
}
