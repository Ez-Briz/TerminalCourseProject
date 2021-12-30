#pragma once
#include "../Headers/globalFuncs.h"
#include "../Headers/Window_Settings.h"

	int checkForInt()
	{
		std::string chose;
		int Ichose;
		bool valid = true;
		while (1)
		{
			std::getline(std::cin, chose);
			if (chose == "") continue;
			for (size_t i(0); i < chose.size(); i++)
			{
				if (chose[i] < '0' || chose[i]>'9')
				{
					valid = false;
					break;
				}
				else valid = true;
			}
			if (valid)
			{
				Ichose = stoi(chose);
				break;
			}
			else
			{
				std::cout << "\n�������� ����! ������� �����.\n";
			}
		}
		return Ichose;
	}

	int checkStrForInt(std::string str)
	{
		bool valid = false;
		for (size_t i(0); i < str.length(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				valid = false;
				break;
			}
			else valid = true;
		}
		if (valid)
		{
			return stoi(str);
		}
		else return NULL;
	}

	std::string CheckDate()
	{
		std::string check;
		bool ok = false;
		while (!ok)
		{
			std::getline(std::cin, check);
			if (check.length() == 10)
			{
				if (check[2] == '.' && check[5] == '.')
				{
					int day = checkStrForInt(check.substr(0, 2));
					int month = checkStrForInt(check.substr(3, 2));
					int year = checkStrForInt(check.substr(6, 4));
					int mass[12] = { 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

					if (year <= 1800 && year >= 2100)
					{
						std::cout << "\t������� ������ ���! ���������� ��� ���.\n\t";
						continue;
					}
					if (month < 0 || month > 12)
					{
						std::cout << "\t������� ������ �����! ���������� ��� ���.\n\t";
						continue;
					}
					if (month == 2)
					{
						if (year % 4 == 0)
						{
							if (year % 100 == 0)
							{
								if (year % 400 == 0)
								{
									mass[1] = 29;
								}
								else mass[1] = 28;
							}
							else mass[1] = 29;
						}
						else mass[1] = 28;
					}
					if ((day < 0 || mass[month-1] < day))
					{
						std::cout << "\t������� ������ ����! ���������� ��� ���.\n\t";
						continue;
					}
					if (day && month && year) ok = true;
				}
				else std::cout << "\t�������� ������ ����! ���������� ��� ���.\n\t";
			}
			else std::cout << "\t�������� ����! ���������� ��� ���.\n\t";
		}
		return check;
	}

	std::string CheckNameStr()
	{
		std::string name;
		while (1)
		{
			std::getline(std::cin, name);
			if (((name[0] <= '�' && name[0] >= '�') || (name[0] <= 'Z' && name[0] >= 'A')) && (name.size() >= 2 && name.size() <= 20))
			{
				return name;
			}
			else
			{
				std::cout << "\t�������� ����! ���������� ��� ���.\n\t";
				continue;
			}
		}
	}

	void AdminMenu(int c)
	{
		std::cout << std::setw(60) <<
			"===========================================================\n"
			<< std::setw(2) << "||" << std::setw(36) << "1. ���������������� �����������;" << std::setw(22) << "||\n"
			<< std::setw(2) << "||" << std::setw(51) << "2. ��������/������� ������� ������ �����������;" << std::setw(7) << "||\n"
			<< std::setw(2) << "||" << std::setw(37) << "3. �������� ����������� �� ����;" << std::setw(21) << "||\n"
			<< std::setw(2) << "||" << std::setw(31) << "4. ������� ������ �� ����;" << std::setw(27) << "||\n"
			<< std::setw(2) << "||" << std::setw(36) << "5. ������� ������ �� ����������;" << std::setw(22) << "||\n"
			<< std::setw(60) << "||=======================================================||\n"
			<< std::setw(2) << "||" << std::setw(53) << "6. ��������� ������� ������ �� ���� �����������;" << std::setw(5) << "||\n"
			<< std::setw(2) << "||" << std::setw(50) << "7. ������� ������� ���������� ���� ����������;" << std::setw(8) << "||\n"
			<< std::setw(2) << "||" << std::setw(44) << "8. ������� ��� ���������� �� ����������;" << std::setw(14) << "||\n"
			<< std::setw(60) << "||=======================================================||\n"
			<< std::setw(2) << "||" << std::setw(50) << "9. ��������� ������� ������ ���������� � ����;" << std::setw(8) << "||\n"
			<< std::setw(2) << "||" << std::setw(45) << "10. ��������� ������ ���������� �� �����;" << std::setw(13) << "||\n"
			<< std::setw(2) << "||" << std::setw(35) << "11. �������� ������ ����������;" << std::setw(23) << "||\n"
			<< std::setw(2) << "||" << std::setw(24) << "12. �������� ������;" << std::setw(34) << "||\n"
			<< std::setw(2) << "||" << std::setw(31) << "13. �������� ����� �������;" << std::setw(27) << "||\n"
			<< std::setw(2) << "||" << std::setw(16) << "14. �������;" << std::setw(42) << "||\n"
			<< std::setw(60) << "||=======================================================||\n"
			<< std::setw(2) << "||" << std::setw(13) << "0. �����." << std::setw(45) << "||\n"
			<< std::setw(2) << "||" << std::setw(39) << "����� ���������� � ������� ������: " << std::setw(3) << c << std::setw(16) << "||\n"
			<< std::setw(60) << "||=======================================================||\n"
			<< std::setw(17) << "��� �����: " << std::setw(1);
	}

	void UserMenu()
	{
		std::cout << std::setw(60) <<
			"===========================================================\n"
			<< std::setw(2) << "||" << std::setw(53) << "1. ��������� ������� ������ �� ���� �����������;" << std::setw(5) << "||\n"
			<< std::setw(2) << "||" << std::setw(44) << "2. ������� ��� ���������� �� ����������;" << std::setw(14) << "||\n"
			<< std::setw(2) << "||" << std::setw(36) << "3. ������� ������ ������� �����;" << std::setw(22) << "||\n"
			<< std::setw(2) << "||" << std::setw(32) << "4. ��������� ������ � �����;" << std::setw(26) << "||\n"
			<< std::setw(2) << "||" << std::setw(30) << "5. �������� ����� �������;" << std::setw(28) << "||\n"
			<< std::setw(2) << "||" << std::setw(15) << "6. �������;" << std::setw(43) << "||\n"
			<< std::setw(60) << "||=======================================================||\n"
			<< std::setw(2) << "||" << std::setw(13) << "0. �����." << std::setw(45) << "||\n"
			<< std::setw(60) << "===========================================================\n"
			<< std::setw(17) << "��� �����: " << std::setw(1);
	}

	void ShowServeses()
	{
		std::cout << std::setw(60) <<
			"\t=========================================================\n" <<
			"\t1. ��������� �������� ��� ���� � ������" <<
			"\n\t2. ��������� �������" <<
			"\n\t3. ��������� � ��������" <<
			"\n\t4. ��������� �������� ���������� �������" <<
			"\n\t5. ������ �� Wi-Fi �� 5 ����" <<
			"\n\t=========================================================\n";
	}