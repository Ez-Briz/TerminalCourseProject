#define SKIP std::cout << "\n\n"

#include "../Headers/List.h"
#include "../Headers/globalFuncs.h"
std::string path = "Resource files/";

void List::AddNew()
{
	sList* p = new sList;
	std::cout << "\t������� ID �����������: ";
	p->id = checkForInt();
	std::cout << "\t������� ��� �����������: ";
	p->name = CheckNameStr();

	std::cout << "\t������� ���� �������� ����������� (������ - XX.XX.XXXX): ";
	p->birthday = CheckDate();

	std::cout << "\t������� ���� ������ ����������� (������ - XX.XX.XXXX): ";
	p->InDate = CheckDate();

	std::cout << "\t������� ���������� ����, �� ������� ������� ����������: ";
	p->days = checkForInt();

	p->Next = NULL;
	if (Head != NULL)
	{
		p->Prev = Tail;
		Tail->Next = p;
		Tail = p;
	}
	else
	{
		p->Prev = NULL;
		Head = Tail = p;
	}
	PersonCount++;
}

void List::ShowAll()
{
	sList* p = Head;
	if (p == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	while (p)
	{
		std::cout << "\t====================================\n";
		std::cout << "\tID �����������: " << p->id << "\n";
		std::cout << "\t��� �����������: " << p->name << "\n";
		std::cout << "\t���� ������ � ���������: " << p->InDate << "\n";
		std::cout << "\t���������� ��������������� ����: " << p->days << "\n";
		std::cout << "\t====================================\n";
		p = p->Next;
	}
	SKIP;
}

void List::DellAll()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	List::~List();
	PersonCount = 0;
	std::cout << "\t������ ���������� ������� ������.";
}

List::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		if (Tail) Tail->Prev = NULL;
		delete Head;
		Head = Tail;
	}
	PersonCount = 0;
	
}

std::string List::TranslateServeses(int n, sList* p)
{	
	if (p->serves[n] == 1)
	{
		return "�����������";
	}
	else return "�� �����������";
}

void List::NewServeses()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	int serv;
	std::cout << "\t������� ��� ����������� (\"EXIT\" ��� ������): ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\t���������� �� ������.\n";
		return;
	}
	else if (p == NULL)
	{
		std::cout << "\n";
		return;
	}
	std::cout << "\t�������� ������ �� ������:\n";
	std::cout <<
		"\t=========================================================\n"
		"\t1. ��������� �������� ��� ���� � ������ - " << TranslateServeses(0, p) <<
		";\n\t2. ��������� ������� - " << TranslateServeses(1, p) <<
		";\n\t3. ��������� � �������� - " << TranslateServeses(2, p) <<
		";\n\t4. ��������� �������� ���������� ������� - " << TranslateServeses(3, p) <<
		";\n\t5. ������ �� Wi-Fi �� 5 ���� - " << TranslateServeses(4, p) <<
		".\n\t=========================================================\n"
		"\t��� �����: ";
	serv = checkForInt();
	std::cout << "\n";
	switch (serv)
	{
	case 1:
	{
		p->serves[serv - 1] = !p->serves[serv-1];
		if (p->serves[serv - 1])
			std::cout << "\t������ ���������.\n";
		else
			std::cout << "\t������ �������.\n";
		break;
	}
	case 2:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\t������ ���������.\n";
		else
			std::cout << "\t������ �������.\n";
		break;
	}
	case 3:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\t������ ���������.\n";
		else
			std::cout << "\t������ �������.\n";
		break;
	}
	case 4:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\t������ ���������.\n";
		else
			std::cout << "\t������ �������.\n";
		break;
	}
	case 5:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\t������ ���������.\n";
		else
			std::cout << "\t������ �������.\n";		
		break;
	}
	default:
	{
		std::cout << "\t������ ������ ���!.\n";
		break;
	}
	}
	std::cout << "\n";
}

void List::AddCall()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	std::cout << "\t������� ��� �����������: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\t���������� �� ������.\n";
	}
	else if (p->call != "")
	{
		std::cout << "\t� ����� ����������� ��� ���� ������ �� ����.";
	}
	else
	{
		std::cout << "\t������� ����� � ���� ������ ��������: ";
		std::getline(std::cin, p->call);
		std::cout << "\t���������� ������� �� ����.";
	}
	SKIP;
}

List::sList* List::CheckName()
{
	sList* p = Head;
	std::string checkname;
	//std::cin.ignore(1);
	std::getline(std::cin, checkname);
	if (checkname == "EXIT")
	{
		std::cout << "\n";
		return NULL;
	}
	if (p == NULL)
		return 0;
	while (p)
	{
		if (checkname == p->name)
		{
			return p;
		}
		else if (p->Next == NULL)
		{
			return 0;
		}
		p = p->Next;
	}
	return 0;
}

void List::DelCall()
	{
		if (Head == NULL)
		{
			std::cout << "\t������ ���������� ����.";
			SKIP;
			return;
		}
		std::cout << "\t������� ��� �����������: ";
		sList* p = CheckName();
		if (p == 0)
		{
			std::cout << "\t���������� �� ������.\n";
		}
		else
		{
			if (p->call != "")
			{
				p->call = "";
				std::cout << "\t������ �� ���� ���� �������.";
			}
			else
				std::cout << "\t� ����������� ��� ������� ������� �� ����.";
		}
		SKIP;
	
	}

void List::DelNew()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	std::cout << "\t������� ��� �����������: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\t���������� �� ������.\n";
	}
	else
	{
		if ((p == Head) && (Head->Next)) 
		{
			sList* temp = Head;
			Head = Head->Next;
			Head->Prev = NULL;
			delete temp;
			return;
		}
		else if ((p == Head) && (Head == Tail)) 
		{
			Head->Next = NULL;
			Head->Prev = NULL;
			Head = NULL;
			delete Tail;
			Tail = NULL;
			return;
		}
		if (p == Tail)
		{
			sList* temp = Tail;
			Tail = Tail->Prev;
			Tail->Next = NULL;
			delete temp;
			return;
		}
		sList* temp = p, * temp2;
		temp2 = temp;
		temp2->Prev->Next = temp2->Next;
		temp2->Next->Prev = temp2->Prev;
		delete temp;
	}	
	PersonCount--;
}

void List::ShowCurrent()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	std::cout << "\t������� ��� �����������: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\t���������� �� ������.\n";
	}
	else
	{
		std::cout << "\t====================================\n";
		std::cout << "\tID �����������: " << p->id << "\n";
		std::cout << "\t��� �����������: " << p->name << "\n";
		std::cout << "\t���� �������� �����������: " << p->birthday << "\n";
		std::cout << "\t���� ������ � ���������: " << p->InDate << "\n";
		if (p->call != "")
		{
			std::cout << "\t������ �� ����: " << p->call << "\n";
		}
		else std::cout << "\t������ �� ���� �����������.\n";
		std::cout << "\t���������� ��������������� ����: " << p->days << "\n";
		std::cout << "\t====================================\n";
	}
}

void List::CheckCall()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	std::cout << "\t������� ��� �����������: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\t���������� �� ������.\n";
	}
	else
	{
		std::cout << "\t=========================================\n";
		if (p->call != "")
		{
			std::cout << "\t���������� \"" << p->name << "\" ����� ������ �� ����.\n";
			std::cout << "\t������: " << p->call << "\n";
		}
		else
		{
			std::cout << "\t���������� \"" << p->name << "\" �� ����� ������ �� ����.\n";
		}
		std::cout << "\t=========================================\n";
	}
}

void List::SaveInFile()
{
	if (Head == NULL)
	{
		std::cout << "\t������ ���������� ����.";
		SKIP;
		return;
	}
	std::cout << "\t������� ��� �����, � ������� ���������� �������� ������ (\"EXIT\" ��� ������): ";
	std::string filename;
	std::getline(std::cin, filename);
	if (filename == "EXIT")
	{
		std::cout << "\n";
		return;
	}
	std::ofstream fout;
	std::cout << "\t�������� ��� ������:\n\t1. ����� ������;\n\t2. ����������� ������ � ���-�� ����.\n\t��� �����: ";
	std::string chk;
	while (1)
	{
		std::getline(std::cin, chk);
		if (chk == "EXIT")
		{
			std::cout << "\n";
			return;
		}
		if (chk == "1")
		{
			fout.open(path + filename);
			if (fout.is_open())
			{
				std::cout << "\t������ � ���� ���� ������� ���������.";
				SKIP; 
				break;
			}
			else std::cout << "\t��������� ������ �������� �����.\n\t���������� ��� ���: ";
		}
		else if (chk == "2")
		{
			fout.open(path + filename, std::ios::app);
			if (fout.is_open())
			{
				std::cout << "\t������ � ���� ���� ������� ���������.";
				SKIP;
				break;
			}
			else std::cout << "\t��������� ������ �������� �����.\n\t���������� ��� ���: ";
		}
	}
	sList* p = Head;
	while (p)
	{
		fout << p->id << "\n" << p->name << "\n" << p->birthday << "\n" << p->InDate <<
			"\n" << p->days << "\n" << p->call << "\n" <<
			p->serves[0] << " " << p->serves[1] << " " << p->serves[2] << " " << p->serves[3] << " " << p->serves[4] <<
			 "\n==============\n";
		p = p->Next;
	}
	fout.close();
}

void List::LoadFromFile()
{
	std::string filename;
	PersonCount = 0;
	List::~List();
	std::cout << "\t������� ��� �����, � ������� ���������� �������� ������ (\"EXIT\" ��� ������): ";
	while (1)
	{
		std::getline(std::cin, filename);
		if (filename == "EXIT")
		{
			std::cout << "\n";
			return;
		}
		std::ifstream fin;
		fin.open(path + filename);
		if (!fin.is_open())
		{
			std::cout << "\t����� � ��������� ��������� �� ����������.\n\t����������, ���������� ��� ���.\n\t";
			continue;
		}
		else
		{
			while (!fin.eof())
			{
				sList* p = new sList;
				std::string tempid;
				std::getline(fin, tempid);
				p->id = stoi(tempid);
				std::getline(fin, p->name);
				std::getline(fin, p->birthday);
				std::getline(fin, p->InDate);
				fin >> p->days;
				std::getline(fin, p->call);
				fin >> p->serves[0] >> p->serves[1] >> p->serves[2] >> p->serves[3] >> p->serves[4];
				fin.ignore(1);
				getline(fin, tempid);
				fin.ignore(1);
				p->Next = NULL;
				if (Head != NULL)
				{
					p->Prev = Tail;
					Tail->Next = p;
					Tail = p;
					PersonCount++;
				}
				else
				{
					p->Prev = NULL;
					Head = Tail = p;
					PersonCount++;
				}
			}
			std::cout << "\t���� �������� � ������� ������.";
			fin.close();
			SKIP;
			break;
		}
	}
} 

std::string List::GetPass()
{
	std::ifstream fin;
	fin.open("Resource Files/Standart Settings/Standart Settings.txt");
	std::getline(fin, Admin_Password);
	fin.close();
	return Admin_Password;
}

void List::SetPass(std::string newpass)
{
	std::ofstream fout;
	fout.open("Resource Files/Standart Settings/Standart Settings.txt");
	Admin_Password = newpass;
	fout << Admin_Password;
	fout.close();
}