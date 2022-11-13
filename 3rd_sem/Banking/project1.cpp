#include <iostream>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
class employee
{
    string name;
    char id[10];
    int age, salary;
    float exp;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void wait();
};
void employee ::menu()
{
    int userpass();
    userpass();
    while (true)
    {
        int choice;
        char x;
        system("cls");
        cout << "\n\t\t\t-------------------------------" << endl;
        cout << "\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t 6. Exit" << endl;
        cout << "\t\t\t.................................." << endl;
        cout << " Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            wait();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            modify();
            break;
        }
        case 4:
        {
            search();
            break;
        }
        case 5:
        {
            deleted();
            break;
        }
        case 6:
        {
            cout << "\n\t\t\t  THANK YOU! \n\n";
            Sleep(3000);
            system("cls");
            exit(0);
        }
        default:
        {
            cout << "\n\n\t\t\t Invalid Choice... \n Please Try Again...\n";
        }
        }
        getch();
    }
}
void employee ::insert()
{
    system("cls");
    fstream out;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID : ";
    cin >> id;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee Salary: ";
    cin >> salary;
    cout << "\n Enter Employee Experience: ";
    cin >> exp;
    out.open("employee_record.txt", ios::app | ios::out);
    out << " " << name << " " << id << " " << age << " " << salary << " " << exp << "\n";
    out.close();
}
void employee ::display()
{
    system("cls");
    int serial = 1;
    fstream in;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    in.open("employee_record.txt", ios::in);
    if (!in)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        in.close();
    }
    else
    {
        in >> name >> id >> age >> salary >> exp;
        cout << "\n||    NAME    ||    ID     ||    AGE    ||      SALARY      ||    EXPERIENCE    ||";
        while (!in.eof())
        {
            cout << "\n";
            cout << serial++ << ". " << name << "\t  " << id << "\t\t   " << age << "\t\t  " << salary << "\t\t" << exp;
            in >> name >> id >> age >> salary >> exp;
        }
    }
    in.close();
    wait();
}
void employee ::modify()
{
    system("cls");
    char check[5];
    int found = 0;
    fstream file, file1;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("employee_record.txt", ios::in);
    file1.open("record.txt", ios::app | ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> check;

        while (!file.eof())
        {
            file >> name >> id >> age >> salary >> exp;
            if (strcmp(check, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID : ";
                cin >> id;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee salary: ";
                cin >> salary;
                cout << "\n Enter Employee Experience: ";
                cin >> exp;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << age << " " << salary << " " << exp << "\n";
                found++;
            }
            // else{
            //  file1 << " " << name << " " << id  << " " << age << " " << salary << " " << exp << "\n";
            //  }
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
    }
    file.close();
    file1.close();
    remove("employee_record.txt");
    rename("record.txt", "employee_record.txt");
    wait();
}
void employee ::search()
{
    system("cls");
    fstream in;
    char check[30];
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    in.open("employee_record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> check;
    if (!in)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        in.close();
    }
    else
    {
        while (!in.eof())
        {
            in >> name >> id >> age >> salary >> exp;

            if (strcmp(check, id) == 0)
            {
                cout << "\n---------------------\n";

                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee Salary: " << salary << "\n";
                cout << "Employee Experience: " << exp << "\n";
                cout << "---------------------\n";
            }
            in >> name >> id >> age >> salary >> exp;
        }
    }
    in.close();
    wait();
}
void employee ::deleted()
{
    system("cls");
    char check[30];
    fstream in, out;
    int found = 0;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    in.open("employee_record.txt", ios::in);
    if (!in)
    {
        cout << "\n\t\t\tNo Data is Present..";
        in.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> check;
        out.open("record.txt", ios::app | ios::out);
        while (!in.eof())
        {
            in >> name >> id >> age >> salary >> exp;

            if (strcmp(check, id) != 0)
            {
                out << " " << name << " " << id << " " << age << " " << salary << " " << exp << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        out.close();
        in.close();
        remove("employee_record.txt");
        rename("record.txt", "employee_record.txt");
        wait();
    }
}
void employee ::wait()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}
int userpass()
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int select;
    cout << "\n\nPlease Enter Value: ";
    cin >> select;
    if (select == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("ep_data.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        userpass();
    }
    else if (select == 2)
    {
        system("cls");
        file.open("ep_data.txt", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Aborted...\n\n";
                system("PAUSE");
                system("cls");
                userpass();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        userpass();
    }

    return 0;
}

int main()
{
    employee system;
    system.menu();
    return 0;
}