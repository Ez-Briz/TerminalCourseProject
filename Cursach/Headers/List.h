#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <iomanip>
#include <conio.h>

class List                             
{
    struct sList {
        std::string name;
        int id = 0;
        std::string birthday;
        std::string InDate;
        int days = 0;
        bool serves[5]{ 0,0,0,0,0 };
        std::string call = "";
        sList* Next = nullptr, * Prev = nullptr;
    };
    sList* Head, *Tail;
    std::string Admin_Password = "";
    int PersonCount;
public:
    List()
    {
        PersonCount = 0;
        std::ifstream fin;
        fin.open("Resource Files/Standart Settings/Standart Settings.txt");
        if (!fin.is_open())
        {
            _mkdir("Resource Files");
            _mkdir("Resource Files/Standart Settings");
            fin.open("Resource Files/Standart Settings/Standart Settings.txt");
        }
        else
            std::getline(fin, Admin_Password);
        if (Admin_Password == "")
        {
            std::ofstream fout;
            fout.open("Resource Files/Standart Settings/Standart Settings.txt");
            fout << "Admin";
            Admin_Password = "Admin";
            fout.close();
        }
        Head = NULL, Tail = NULL; 
    };
    ~List();
    void ShowAll();
    void AddNew();
    void NewServeses();
    void AddCall();
    sList* CheckName();
    void DelCall();
    void DelNew();
    void ShowCurrent();
    void CheckCall();
    void SaveInFile();
    void LoadFromFile();
    void DellAll();
    std::string TranslateServeses(int, sList*);
    void SetPass(std::string);

    std::string GetPass();
    int GetCount() { return PersonCount; }
};

#endif