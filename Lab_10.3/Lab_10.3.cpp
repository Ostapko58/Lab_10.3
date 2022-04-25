#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
void AutoCreat(const char* filename, const int N, string* List, string prizn, int poznach, int time1, int time2)
{
	ofstream f;
	f.open(filename);
	for (int i = 0; i < N; i++)
	{
		f << prizn;
		f << ' ';
		f << List[poznach];
		f << ' ';
		f << time1;
		f << ':';
		f << time2;
		if (i != N - 1)
		{
			f << "\n";
		}
		cout << endl;
	}
	f.close();
}

void Creat(const char* filename, const int N, string* List)
{

	ofstream f;
	f.open(filename);
	string word;
	int a, poznach;
	for (int i = 0; i < N; i++)
	{
		cin.get(); cin.sync();
		cout << "������ ���� �����������: "; cin >> word;
		do
		{
			if (word.find_first_of("0 123456789", 0) != -1)
			{
				cin.get(); cin.sync();
				word.erase(0, -1);
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ ���� �����������: "; getline(cin, word);
			}
		} while (word.find_first_of("0 123456789", 0) != -1);
		f << word;
		cout << "������ ��������: ";
		cout << " �������� (0 - ��������� , 1 - ���������� ��������, 2 - ��������� �������):";
		cin >> poznach;
		if (cin.fail() || poznach < 0 || poznach>2)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " �������� (0 - ��������� , 1 - ���������� ��������, 2 - ��������� �������): ";
				cin >> poznach;
			} while (cin.fail() || poznach < 0 || poznach>2);
		}
		f << ' ';
		f << List[poznach];
		cout << "������ ������: "; cin >> a;
		if (cin.fail() || a < 1 || a>24)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������ ������: "; cin >> a;
			} while (cin.fail() || a < 1 || a>24);
		}
		f << ' ';
		f << a;
		cout << "������ �������: "; cin >> a;
		if (cin.fail() || a < 1 || a>60)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������ �������: "; cin >> a;
			} while (cin.fail() || a < 1 || a>60);
		}
		f << ':';
		f << a;
		if (i!=N-1)
		{
			f << "\n";
		}
		cout << endl;
	}
	f.close();
}

void Add(const char* filename, const int N, string* List,bool & are_open)
{
	ofstream f;
	f.open(filename, ios::app);
	if (!f.is_open())
	{
		cout << "������ ����� �� ����"<< endl;
		are_open = false;
		return;
	}
	string word;
	int a,poznach;
	for (int i = 0; i < N; i++)
	{
		cin.get(); cin.sync();
		cout << "������ ���� �����������: "; getline(cin, word);
		do
		{
			if (word.find_first_of("0 123456789", 0) != -1)
			{
				word.erase(0, -1);
				cout << "�� ����� ����� ���, ���������� �����: " << endl;
				cout << " ������ ���� �����������: "; getline(cin, word);
			}
		} while (word.find_first_of("0 123456789", 0) != -1);
		f << "\n";
		f << word;
		cout << " �������� (0 - ��������� , 1 - ���������� ��������, 2 - ��������� �������):";
		cin >> poznach;
		if (cin.fail() || poznach < 0 || poznach>2)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " �������� (0 - ��������� , 1 - ���������� ��������, 2 - ��������� �������): ";
				cin >> poznach;
			} while (cin.fail() || poznach < 0 || poznach>2);
		}
		f << ' ';
		f << List[poznach];
		cout << "������ ������: "; cin >> a;
		if (cin.fail() || a < 1 || a>24)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������ ������: "; cin >> a;
			} while (cin.fail() || a < 1 || a>24);
		}
		cin.get(); cin.sync();
		f << ' ';
		f << a;
		cout << "������ �������: "; cin >> a;
		if (cin.fail() || a < 1 || a>60)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "�� ����� ������ �����, ���������� �����: " << endl;
				cout << " ������ �������: "; cin >> a;
			} while (cin.fail() || a < 1 || a>60);
		}
		f << ':';
		f << a;
	}
}

void Print(const char* filename, string* List,bool & are_open)
{
	ifstream f(filename);
	if (!f.is_open())
	{
		cout << "������ ����� �� ����"<< endl;
		are_open = false;
		return;
	}
	string line;
	while (getline(f, line))
	{
		cout << line << endl;
	}
}

void Pisla(const char* filename, string* List,bool & are_open)
{
	fstream f(filename);
	if (!f.is_open())
	{
		cout << "������ ����� �� ����" << endl;
		are_open = false;
		return;
	}
	int pos1,pos2;
	int tmp[2],tmp2[2];
	string line,s;
	cout << " ������ ������� ��� ���:\n������: "; cin >> tmp[0];
	if (cin.fail() || tmp[0] < 1 || tmp[0]>24)
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "�� ����� ����� ���, ���������� �����: " << endl;
			cout << " ������: "; cin >> tmp[0];
		} while (cin.fail() || tmp[0] < 1 || tmp[0]>24);
	}
	cin.get(); cin.sync();
	cout << "�������: "; cin >> tmp[1];
	if (cin.fail() || tmp[1] < 1 || tmp[1]>60)
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "�� ����� ����� ���, ���������� �����: " << endl;
			cout << " �������: "; cin >> tmp[1];
		} while (cin.fail() || tmp[1] < 1 || tmp[1]>60);
	}
	cout << endl;
	cout << "������ �����, �� �������� ���� ��������� ����:" << endl;
	while (getline(f, line))
	{
		pos1=line.find_last_of(':')-2;
		if (line[pos1]==' ')
		{
			pos1++;
		}
		pos2 = line.find_last_of(':') + 1;
		
		tmp2[0] = stoi(line.substr(pos1, 2));
		tmp2[1] = stoi(line.substr(pos2, 2));
		if ((tmp2[0]>tmp[0])||(tmp2[0]==tmp[0]&&tmp2[1]>tmp[1]))
		{
			cout << line << endl;
		}
	}
	f.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[60];
	int N;
	bool are_open;
	string List[] =
		{
			"���������",
			"���������� ��������",
			"��������� �������"
		};

	char word2[254];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� ����" << endl;
		cout << " [2] - ������� ��� �����" << endl;
		cout << " [3] - ��������� �������� ����" << endl;
		cout << " [4] - ������� ����������, �� �������� ���� ����������� ����" << endl;
		cout << " [0] - �����" << endl << endl;
		cout << "������ �����: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cout << "������ ������� ��������: "; cin >> N;
			if (cin.fail() || N<1)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ ������� ��������: "; cin >> N;
				} while (cin.fail() || N < 1);
			}
			cout << "������ ����� �����: "; cin >> filename;
			Creat(filename, N, List);
			break;
		case 2:
			do
			{
				cout << "������ ����� �����: "; cin >> filename;
				are_open = true;
				Print(filename, List,are_open);
			} while (!are_open);
			break;
		case 3:
			cout << "������ ������� �������� ��� ����������: "; cin >> N;
			if (cin.fail() || N < 1)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "�� ����� ����� ���, ���������� �����: " << endl;
					cout << " ������ ������� �������� ��� ����������: "; cin >> N;
				} while (cin.fail() || N < 1);
			}
			do
			{
				cout << "������ ����� �����: "; cin >> filename;
				are_open = true;
				Add(filename, N, List,are_open);
			} while (!are_open);
			break;
		case 4:
			do
			{
				cout << "������ ����� �����: "; cin >> filename;
				are_open = true;
				Pisla(filename, List,are_open);
			} while (!are_open);

			break;
		case 0:
			break;
		default:
			cout << "�� ����� ������������ �����!" << endl;
		}
	} while (menuItem != 0);

	return 0;
}