#include "Proffesor.h"


Proffesor::Proffesor()
{

	cout << "���������" << endl;
	try
	{

		setType(3);

		cin.ignore(256, '\n');
		cout << "�������: ";
		getline(cin, this->surename);
		cout << "���: ";
		getline(cin, this->name);
		cout << "��������: ";
		getline(cin, this->patronim);
		cout << "������� ������� �����: ";
		getline(cin, this->subjects);
		cout << "������ � ������� �����: ";
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

		cout << "�������� ��� �� ������ ��������:" << endl
			<< "1 - �������" << endl
			<< "2 - ���" << endl
			<< "3 - ��������" << endl
			<< "4 - ������" << endl
			<< "5 - �������" << endl
			<< " "; cin >> index;
		if (index < 1 || index > 5)
		{

			throw (string)"��� ������ ���������";
		}

		cout << "������� ��������: ";
		switch (index)
		{
		case 1:
			cout << surename << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			surename = sTmp;
			break;


		case 2:

			cout << name << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			name = sTmp;
			break;


		case 3:


			cout << patronim << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			patronim = iTmp;
			break;




		case 4:
			cout << group << endl;
			cout << "����� ��������: ";
			cin >> iTmp;
			group = iTmp;
			break;

		case 5:

			cout << subjects << endl;
			cout << "����� ��������:: ";
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

	out << "���������" << endl;
	out << "���: " << surename << " " << name << " " << patronim << " " << endl
		<< "������: " << this->group << endl
		<< "�������: " << this->subjects << endl;
}
