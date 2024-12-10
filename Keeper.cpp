#include "Keeper.h"
#include <fstream>
using namespace std;

Keeper::Keeper()
{

	this->data = nullptr;

	this->size = 0;
}



Keeper::~Keeper()
{

	delete[] data;
}



int Keeper::getSize()
{

	return size;
}



void Keeper::add()
{

	int type; // ��� ���������� 
	try
	{

		cout << "�������� " << endl
			<< "1 - �������" << endl
			<< "2 - ���������" << endl
			<< "3 - ���������" << endl
			<< ": ";
		cin >> type;


		University** tmp = new University * [size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}

		switch (type)
		{
		case 1:
			tmp[size] = new Student;
			break;
		case 2:
			tmp[size] = new Stuff;
			break;
		case 3:
			tmp[size] = new Proffesor;
			break;
		default:
			break;
		}
		if (tmp[size]->isError())
		{

			cout << "������" << endl;
			system("pause");
			return;
		}
		size++;

		if (data)
			delete[] data;
		data = tmp;
		cout << "���������� �������" << endl; system("pause");
	}

	catch (string err)
	{

		cout << "������: " + err << endl;
		system("pause");
	}
}



void Keeper::add(int _type, ifstream& fin)
{

	University** tmp = new University * [size + 1];
	for (int i = 0; i < size; i++)
	{

		tmp[i] = data[i];
	}

	switch (_type)
	{
	case 1:
		tmp[size] = new Student(fin);
		break;
	case 2:
		tmp[size] = new Stuff(fin);
		break;
	case 3:
		tmp[size] = new Proffesor(fin);
		break;
	default:
		break;

	}
	size++;
	if (data)
		delete[] data;
	data = tmp;
}



void Keeper::edit()
{

	int index;
	if (!size)
	{
		cout << "������ ����" << endl;
		system("pause");
		return;

	}
	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << " - ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "�������" << endl;
				break;
			case 2:
				cout << "���������" << endl;
				break;
			case 3:
				cout << "���������" << endl;
				break;
			default:
				break;
			}
		}

		cout << "�������� ����� ������� ������ ��������: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"���������� �������� �� ����������";
		data[index]->edit();
		cout << "��������� ���������" << endl;
		system("pause");
	}

	catch (string err)
	{

		cout << "������: " + err << endl;
		system("pause");
	}
}



void Keeper::del()
{

	int index;
	if (!size)
	{

		cout << "������ ����" << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size; i++)
		{


			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "�������" << endl;
				break;
			case 2:
				cout << "���������" << endl;
				break;
			case 3:
				cout << "���������" << endl;
				break;
			default:
				break;
			}
		}

		cout << "�������� ����� ������� ������ �������: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"��������� ������� �� ����������";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "������� ������" << endl;
			size--;
			system("pause");
			return;
		}

		University** tmp = new University * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{

			if (index == i)
				continue;
			tmp[j] = data[i];
		}

		delete[] data;
		data = tmp;
		size--;
		cout << "������� ������" << endl;
		system("pause");
	}

	catch (string err)
	{

		cout << "ERROR: " + err << endl;
		system("pause");
	}
}

void Keeper::save()
{

	ofstream fout("output.txt");

	for (int i = 0; i < size; i++)
	{

		data[i]->save(fout);
	}

	fout.close();
	cout << "��������� ���������� � �����" << endl;
	system("pause");
}



void Keeper::load()
{

	ifstream fin("output.txt");
	if (fin.fail())
	{

		cout << "���� ����" << endl; system("pause");
		return;
	}

	int type = 0;
	while (fin)
	{

		fin >> type;
		if (fin.peek() == -1)
		{

			break;
		}

		add(type, fin);
	}

	fin.close();
	cout << "������ ��������� �� �����" << endl;

	system("pause");
}

ostream& operator<<(ostream& out, Keeper& obj)
{

	if (!obj.size)
	{

		cout << "������ ����" << endl;
		system("pause");
		return out;
	}

	for (int i = 0; i < obj.size; i++)
	{

		obj.data[i]->print(out);
	}

	system("pause"); return out;
}
