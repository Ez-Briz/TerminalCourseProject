#define SKIP std::cout << "\n\n"
#include "../Headers/globalFuncs.h"
#include "../Headers/List.h"
#include "../Headers/Window_Settings.h"
static int checkpass(List c);
static void changePass(List c);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List c;
	for(;;)
	{
		SetConsoleTitle(_T("Авторизация"));
		
		int user;
		int passed = NULL;
		SetColor(15, 0);
		SetWindowSize(350, 120);
		while (!passed)
		{
			
			std::cout << "Выберите аккаунт:\n"
				"1. Отдыхающий\n"
				"2. Администратор\n"
				"0. Выход\n"
				"Ваш выбор: ";
			user = checkForInt();
			switch (user)
			{
			case 1:
			{
				system("cls");
				SetWindowSize(280, 150);
				std::string avto = "Авторизация...";
				SKIP;
				std::cout << "\t";
				for (size_t i(0); i < avto.size(); i++)
				{
					if (i < 11)
					{
						std::cout << avto[i];
						continue;
					}
					Sleep(700);
					std::cout << avto[i];
				}
				Sleep(700);
				passed = 1;
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				if (!checkpass(c))
					break;
				passed = 2;
				break;
			}
			case 0:
			{
				c.~List();
				return 0;
			}
			default:
			{
				system("cls");
				std::cout << "Некорректный выбор! Попробуйте ещё раз.\n";
			}
			}
		}
		int Ichose;
		do
		{
			system("cls");
			SetConsoleTitle(_T("Главное меню"));
			if (passed == 2)
			{
				SetWindowSize(510, 415);
				AdminMenu(c.GetCount());
				Ichose = checkForInt();
				std::cout << '\n';
				system("cls");
				switch (Ichose)
				{
				case 1:
				{
					SetConsoleTitle(_T("Регистрация отдыхающего"));
					SetWindowSize(700, 300);
					c.AddNew();
					_getch();
					break;
				}
				case 2:
				{
					SetConsoleTitle(_T("Регистрация платных услуг"));
					SetWindowSize(700, 300);
					c.NewServeses();
					_getch();
					break;
				}
				case 3:
				{
					SetConsoleTitle(_T("Запись отдыхающего на приём"));
					SetWindowSize(700, 300);
					c.AddCall();
					_getch();
					break;
				}
				case 4:
				{
					SetConsoleTitle(_T("Удаление записи на приём"));
					SetWindowSize(700, 300);
					c.DelCall();
					_getch();
					break;
				}
				case 5:
				{
					SetConsoleTitle(_T("Удаление записи об отдыхающем"));
					SetWindowSize(700, 300);
					c.DelNew();
					_getch();
					break;
				}
				case 6:
				{
					SetConsoleTitle(_T("Проверка наличия записи на приём"));
					SetWindowSize(700, 300);
					c.CheckCall();
					_getch();
					break;
				}
				case 7:
				{
					SetConsoleTitle(_T("Текущий список отдыхающих"));
					SetWindowSize(750, 1000);
					c.ShowAll();
					_getch();
					break;
				}
				case 8:
				{
					SetConsoleTitle(_T("Информация о конкретном отдыхающем"));
					SetWindowSize(750, 1000);
					c.ShowCurrent();
					_getch();
					break;
				}
				case 9:
				{
					SetConsoleTitle(_T("Сохранение списка в файл"));
					SetWindowSize(1000, 300);
					c.SaveInFile();
					_getch();
					break;
				}
				case 10:
				{
					SetConsoleTitle(_T("Загрузка списка из файла"));
					SetWindowSize(1000, 200);
					c.LoadFromFile();
					_getch();
					break;
				}
				case 11:
				{
					SetConsoleTitle(_T("Очистка текущего списка"));
					SetWindowSize(750, 300);
					c.DellAll();
					_getch();
					break;
				}
				case 12:
				{
					SetConsoleTitle(_T("Смена пароля"));
					SetWindowSize(600, 200);
					changePass(c);
					break;
				}
				case 13:
				{
					SetConsoleTitle(_T("Смена стиля консоли"));
					SetWindowSize(300, 140);
					ChangeStyle();
					break;
				}
				case 14:
				{
					SetConsoleTitle(_T("Справка"));
					SetWindowSize(600, 75);
					std::cout << "Эта программа создана для облегчения работы регистратуры санатория.\nСоздатель программы: Гурко Никита, МГКЭ.";
					_getch();
					break;
				}
				case 0:
				{
					break;
				}
				default: { std::cout << "\tВыбран несуществующий пункт."; SKIP; break; }
				}
			}
			else
			{
				SetWindowSize(510, 215);
				UserMenu();
				Ichose = checkForInt();
				std::cout << '\n';
				system("cls");
				switch (Ichose)
				{
				case 1:
				{
					SetConsoleTitle(_T("Проверка наличия записи на приём"));
					SetWindowSize(700, 300);
					c.CheckCall();
					_getch();
					break;
				}
				case 2:
				{
					SetConsoleTitle(_T("Вывод информации об отдыхающем"));
					SetWindowSize(700, 300);
					c.ShowCurrent();
					_getch();
					break;
				}
				case 3:
				{
					SetConsoleTitle(_T("Вывести список платных услуг"));
					SetWindowSize(600, 200);
					ShowServeses();
					_getch();
					break;
				}
				case 4:
				{
					SetConsoleTitle(_T("Загрузка списка из файла"));
					SetWindowSize(1000, 200);
					c.LoadFromFile();
					_getch();
					break;
				}
				case 5:
				{
					SetConsoleTitle(_T("Смена стиля консоли"));
					SetWindowSize(300, 140);
					ChangeStyle();
					break;
				}
				case 6:
				{
					SetConsoleTitle(_T("Справка"));
					SetWindowSize(600, 75);
					std::cout << "Эта программа создана для облегчения работы регистратуры санатория.\nСоздатель программы: Гурко Никита, МГКЭ.";
					_getch();
					break;
				}
				case 0:
				{
					break;
				}
				default: { std::cout << "\tВыбран несуществующий пункт."; SKIP; break; }
				}
			}
		} while (Ichose != 0);
	}
}


static int checkpass(List c)
{
	std::string checkpass;
	SetWindowSize(400, 100);
	int a;
	std::string lastmsg = "\n\tВведите пароль: ";
	
	while (1)
	{
		std::cout << lastmsg;
		for (int count = 0;;)
		{
			a = _getch();
			
			if (a == '\b')
			{
				if (checkpass.empty())
				{
					continue;
				}
				count--;
				system("cls");
				checkpass.pop_back();
				std::cout << lastmsg;
				for (int l = 0; l < count; l++)
				{
					std::cout << '*';
				}
			}
			else if (a == '\r') break;
			else if ((a > 'z') || (a < 'A'))
			{
				continue;
			}
			else
			{
				count++;
				checkpass.push_back(a);
				std::cout << '*';
			}
		}
		if (checkpass == "EXIT")
		{
			system("cls");
			return 0;
		}
		
		if (checkpass == c.GetPass())
		{
			system("cls");
			SetWindowSize(280, 150);
			std::string avto = "Авторизация...";
			SKIP;
			//std::cout << "\tАвторизация...";
			std::cout << "\t";
			for (size_t i(0); i < avto.size(); i++)
			{
				if (i < 11)
				{
					std::cout << avto[i];
					continue;
				}
				Sleep(700);
				std::cout << avto[i];
			}
			Sleep(700);
			system("cls");
			return 1;
		}
			
		else {
			system("cls");
			SetWindowSize(600, 120);
			checkpass.clear();
			lastmsg = "\n\tНеверный пароль! Попробуйте ещё раз (\"EXIT\" для выхода).\n\tВведите пароль: ";
		}
	}
}

static void changePass(List c)
{
	std::string newpass;
	bool flag = true;
	while (1)
	{
		while (1)
		{
			std::cout << "Введите старый пароль (\"EXIT\" для выхода): ";	
			std::string oldpass;
			std::getline(std::cin, oldpass);
			if (oldpass == "EXIT")
			{
				return;
			}
			else if (oldpass == c.GetPass())
			{
				break;
			}
			else std::cout << "Неверный пароль! Попробуйте ещё раз.\n";
		}
		std::cout << "Введите новый пароль: ";
		std::getline(std::cin, newpass);
		for (size_t i(0); i < newpass.size(); i++)
		{
			if (newpass[i] < 'A' || newpass[i] > 'z')
			{
				flag = false;
				system("cls");
				std::cout << "Указан некорректный пароль.\n";
			}
		}
		if (flag)
		{
			c.SetPass(newpass);
			break;
		}
	}	
}