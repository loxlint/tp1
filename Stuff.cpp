#include "Stuff.h"

Stuff::Stuff()
{

	cout << "��������" << endl; try
	{

		setType(2);

		cin.ignore(256, '\n');
		cout << "�������: ";
		getline(cin, this->surename);
		cout << "���: ";
		getline(cin, this->name);
		cout << "��������: ";
		getline(cin, this->patronim);
		cout << "���������: ";
		getline(cin, this->role);
		cout << "�������: ";
		getline(cin, this->phone);
		cout << "���������������: ";
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

	cout << "����������" << endl; system("pause");
}



void Stuff::edit()
{


	try
	{

		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "1 - �������" << endl
			<< "2 - ���" << endl
			<< "3 - ��������" << endl
			<< "4 - ���������" << endl
			<< "5 - �������" << endl
			<< "6 - ���������������" << endl
			<< ": "; cin >> index;

		if (index < 1 || index > 6)
		{

			throw (string)"��� ������ ���������";
		}

		cout << "������� ��������: "; switch (index)
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
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			patronim = sTmp;
			break;

		case 4:


			cout << role << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			role = sTmp;
			break;

		case 5:

			cout << phone << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			phone = sTmp;
			break;


		case 6:

			cout << expertise << endl;
			cout << "����� ��������: ";
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

	out << "���������" << endl
		<< "���: " << surename << " " << name << " " << patronim << endl
		<< "���������: " << this->role << endl;
	out << "�������: " << this->phone << endl
		<< "��������������: " << this->expertise << endl;
}
