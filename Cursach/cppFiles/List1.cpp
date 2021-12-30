#define SKIP std::cout << "\n\n"

#include "../Headers/List.h"
#include "../Headers/globalFuncs.h"
std::string path = "Resource files/";

void List::AddNew()
{
	sList* p = new sList;
	std::cout << "\tВведите ID отдыхающего: ";
	p->id = checkForInt();
	std::cout << "\tВведите ФИО отдыхающего: ";
	p->name = CheckNameStr();

	std::cout << "\tВведите дату рождения отдыхающего (формат - XX.XX.XXXX): ";
	p->birthday = CheckDate();

	std::cout << "\tВведите дату въезда отдыхающего (формат - XX.XX.XXXX): ";
	p->InDate = CheckDate();

	std::cout << "\tВведите количество дней, на которое приехал отдыхающий: ";
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
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	while (p)
	{
		std::cout << "\t====================================\n";
		std::cout << "\tID отдыхающего: " << p->id << "\n";
		std::cout << "\tФИО отдыхающего: " << p->name << "\n";
		std::cout << "\tДата въезда в санаторий: " << p->InDate << "\n";
		std::cout << "\tКоличество оздоровительных дней: " << p->days << "\n";
		std::cout << "\t====================================\n";
		p = p->Next;
	}
	SKIP;
}

void List::DellAll()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	List::~List();
	PersonCount = 0;
	std::cout << "\tСписок отдыхающих успешно очищен.";
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
		return "приобретено";
	}
	else return "не приобретено";
}

void List::NewServeses()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	int serv;
	std::cout << "\tВведите ФИО отдыхающего (\"EXIT\" для выхода): ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\tОтдыхающий не найден.\n";
		return;
	}
	else if (p == NULL)
	{
		std::cout << "\n";
		return;
	}
	std::cout << "\tВыберите услугу из списка:\n";
	std::cout <<
		"\t=========================================================\n"
		"\t1. Посещение бассейна два раза в неделю - " << TranslateServeses(0, p) <<
		";\n\t2. Посещение массажа - " << TranslateServeses(1, p) <<
		";\n\t3. Абонемент в спортзал - " << TranslateServeses(2, p) <<
		";\n\t4. Посещение вечерних просмотров фильмов - " << TranslateServeses(3, p) <<
		";\n\t5. Пароль от Wi-Fi на 5 дней - " << TranslateServeses(4, p) <<
		".\n\t=========================================================\n"
		"\tВаш выбор: ";
	serv = checkForInt();
	std::cout << "\n";
	switch (serv)
	{
	case 1:
	{
		p->serves[serv - 1] = !p->serves[serv-1];
		if (p->serves[serv - 1])
			std::cout << "\tУслуга добавлена.\n";
		else
			std::cout << "\tУслуга удалена.\n";
		break;
	}
	case 2:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\tУслуга добавлена.\n";
		else
			std::cout << "\tУслуга удалена.\n";
		break;
	}
	case 3:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\tУслуга добавлена.\n";
		else
			std::cout << "\tУслуга удалена.\n";
		break;
	}
	case 4:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\tУслуга добавлена.\n";
		else
			std::cout << "\tУслуга удалена.\n";
		break;
	}
	case 5:
	{
		p->serves[serv - 1] = !p->serves[serv - 1];
		if (p->serves[serv - 1])
			std::cout << "\tУслуга добавлена.\n";
		else
			std::cout << "\tУслуга удалена.\n";		
		break;
	}
	default:
	{
		std::cout << "\tТакого пункта нет!.\n";
		break;
	}
	}
	std::cout << "\n";
}

void List::AddCall()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	std::cout << "\tВведите ФИО отдыхающего: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\tОтдыхающий не найден.\n";
	}
	else if (p->call != "")
	{
		std::cout << "\tУ этого отдыхающего уже есть запись на приём.";
	}
	else
	{
		std::cout << "\tВведите время и цель визита педиатра: ";
		std::getline(std::cin, p->call);
		std::cout << "\tОтдыхающий записан на приём.";
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
			std::cout << "\tСписок отдыхающих пуст.";
			SKIP;
			return;
		}
		std::cout << "\tВведите ФИО отдыхающего: ";
		sList* p = CheckName();
		if (p == 0)
		{
			std::cout << "\tОтдыхающий не найден.\n";
		}
		else
		{
			if (p->call != "")
			{
				p->call = "";
				std::cout << "\tЗапись на приём была удалена.";
			}
			else
				std::cout << "\tУ отдыхающего нет текущих записей на приём.";
		}
		SKIP;
	
	}

void List::DelNew()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	std::cout << "\tВведите ФИО отдыхающего: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\tОтдыхающий не найден.\n";
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
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	std::cout << "\tВведите ФИО отдыхающего: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\tОтдыхающий не найден.\n";
	}
	else
	{
		std::cout << "\t====================================\n";
		std::cout << "\tID отдыхающего: " << p->id << "\n";
		std::cout << "\tФИО отдыхающего: " << p->name << "\n";
		std::cout << "\tДень рождения отдыхающего: " << p->birthday << "\n";
		std::cout << "\tДата въезда в санаторий: " << p->InDate << "\n";
		if (p->call != "")
		{
			std::cout << "\tЗапись на приём: " << p->call << "\n";
		}
		else std::cout << "\tЗапись на приём отсутствует.\n";
		std::cout << "\tКоличество оздоровительных дней: " << p->days << "\n";
		std::cout << "\t====================================\n";
	}
}

void List::CheckCall()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	std::cout << "\tВведите ФИО отдыхающего: ";
	sList* p = CheckName();
	if (p == 0)
	{
		std::cout << "\tОтдыхающий не найден.\n";
	}
	else
	{
		std::cout << "\t=========================================\n";
		if (p->call != "")
		{
			std::cout << "\tОтдыхающий \"" << p->name << "\" имеет запись на приём.\n";
			std::cout << "\tЗапись: " << p->call << "\n";
		}
		else
		{
			std::cout << "\tОтдыхающий \"" << p->name << "\" не имеет записи на приём.\n";
		}
		std::cout << "\t=========================================\n";
	}
}

void List::SaveInFile()
{
	if (Head == NULL)
	{
		std::cout << "\tСписок отдыхающих пуст.";
		SKIP;
		return;
	}
	std::cout << "\tВведите имя файла, в который необходимо провести запись (\"EXIT\" для выхода): ";
	std::string filename;
	std::getline(std::cin, filename);
	if (filename == "EXIT")
	{
		std::cout << "\n";
		return;
	}
	std::ofstream fout;
	std::cout << "\tВыберите тип записи:\n\t1. Новая запись;\n\t2. Продолжение записи в тот-же файл.\n\tВаш выбор: ";
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
				std::cout << "\tЗапись в файл была успешно завершена.";
				SKIP; 
				break;
			}
			else std::cout << "\tПроизошла ошибка открытия файла.\n\tПопробуйте ещё раз: ";
		}
		else if (chk == "2")
		{
			fout.open(path + filename, std::ios::app);
			if (fout.is_open())
			{
				std::cout << "\tЗапись в файл была успешно завершена.";
				SKIP;
				break;
			}
			else std::cout << "\tПроизошла ошибка открытия файла.\n\tПопробуйте ещё раз: ";
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
	std::cout << "\tВведите имя файла, в который необходимо провести запись (\"EXIT\" для выхода): ";
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
			std::cout << "\tФайла с указанным названием не существует.\n\tПожалуйста, попробуйте ещё раз.\n\t";
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
			std::cout << "\tФайл загружен в текущий список.";
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