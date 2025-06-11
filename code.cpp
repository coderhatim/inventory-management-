#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class data
{
protected:
    int id, count;
    float sp, cp;
    string name, supplier;

    void add_file()
    {
        ofstream file("data.txt", ios::app);
        if (file.is_open())
        {
            file << id << ",";
            file << name << ",";
            file << count << ",";
            file << sp << ",";
            file << cp << ",";
            file << supplier << endl;
            cout << "---------------------------" << endl;
            cout << "Product added to data successfully!" << endl;
            cout << "---------------------------" << endl;
            file.close();
        }
        else
        {
            cout << "---------------------------" << endl;
            cout << "Unable to open file" << endl;
            cout << "---------------------------" << endl;
        }
    }

public:
    int index;
    void view_data()
    {
        ifstream file("data.txt");
        if (!file.is_open())
        {
            cout << "---------------------------" << endl;
            cout << "Error opening file!" << endl;
            cout << "---------------------------" << endl;
            return;
        }
        string line;
        cout << "---------------------------" << endl;
        cout << "ID\tName\tSup\tCp\tSp\tCount\n";
        cout << "-------------------------------------------------------------\n";
        while (getline(file, line))
        {
            stringstream ss(line);
            string id, name, supplier, cp, sp, count;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, count, ',');
            getline(ss, sp, ',');
            getline(ss, cp, ',');
            getline(ss, supplier, ',');
            cout << id << "\t" << name << "\t" << supplier << "\t" << cp << "\t" << sp << "\t" << count << endl;
        }
        cout << "---------------------------" << endl;
        file.close();
    }
    void display()
    {
        cout << "---------------------------" << endl;
        cout << "Product ID: " << id << endl;
        cout << "Product Name: " << name << endl;
        cout << "Supplier Name: " << supplier << endl;
        cout << "Cost Price: " << cp << endl;
        cout << "Selling Price: " << sp << endl;
        cout << "Count: " << count << endl;
        cout << "---------------------------" << endl;
    }

    void update(string id, string name, string seller, string cp, string sp, string count)
    {
        this->id = stoi(id);
        this->name = name;
        this->count = stoi(count);
        this->sp = stof(sp);
        this->cp = stof(cp);
        this->supplier = seller;
    }
    void change_delete(int ind, int x)
    {
        ifstream mainFile("data.txt");
        ofstream dummyFile("temp.txt");
        string line;
        int lineToEdit = ind;
        int currentLine = 1;
        if (!mainFile.is_open() || !dummyFile.is_open())
        {
            cout << "---------------------------" << endl;
            cout << "Error opening files." << endl;
            cout << "---------------------------" << endl;
            return;
        }

        while (getline(mainFile, line))
        {
            if (currentLine == lineToEdit)
            {
                if (x == 1)
                {
                    dummyFile << id << ",";
                    dummyFile << name << ",";
                    dummyFile << count << ",";
                    dummyFile << sp << ",";
                    dummyFile << cp << ",";
                    dummyFile << supplier << endl;
                }
                if (x == 2)
                {
                    currentLine++;
                    continue;
                }
            }
            else
            {
                dummyFile << line << endl;
            }
            currentLine++;
        }
        mainFile.close();
        dummyFile.close();

        ifstream dummyRead("temp.txt");
        ofstream mainFileOut("data.txt");

        while (getline(dummyRead, line))
        {
            mainFileOut << line << endl;
        }

        dummyRead.close();
        mainFileOut.close();
        cout << "---------------------------" << endl;
        cout << "File updated successfully." << endl;
        cout << "---------------------------" << endl;
        return;
    }
    void change(int ind)
    {
        cout << "---------------------------" << endl;
        cout << "Enter the field to change (1: ID, 2: Name, 3: Supplier, 4: Cost Price, 5: Selling Price, 6: Count): ";
        int choice;
        cin >> choice;
        cout << "Enter new value: ";
        string newValue;
        cin >> newValue;
        if (choice == 1)
        {
            id = stoi(newValue);
        }
        else if (choice == 2)
        {
            name = newValue;
        }
        else if (choice == 3)
        {
            supplier = newValue;
        }
        else if (choice == 4)
        {
            cp = stof(newValue);
        }
        else if (choice == 5)
        {
            sp = stof(newValue);
        }
        else if (choice == 6)
        {
            count = stoi(newValue);
        }
        else
        {
            cout << "Invalid choice!" << endl;
            return;
        }
        change_delete(ind, 1);
        return;
    }
    void change_or_delete(int ind)
    {
        cout << "---------------------------" << endl;
        cout << "Enter 1 to change, 2 to delete, 3 to return: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            change(ind);
        }
        else if (choice == 2)
        {
            change_delete(ind, 2);
            cout << "Product deleted successfully!" << endl;
        }
        else if (choice == 3)
        {
            return;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
        cout << "---------------------------" << endl;
    }
    void search_file(int x, string data, char choose)
    {
        index = 0;
        ifstream file("data.txt");
        string line;
        if (!file.is_open())
        {
            cout << "---------------------------" << endl;
            cout << "Error opening file!" << endl;
            cout << "---------------------------" << endl;
            return;
        }

        while (getline(file, line))
        {
            index++;
            stringstream ss(line);
            string id, name, count, sp, cp, seller;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, count, ',');
            getline(ss, sp, ',');
            getline(ss, cp, ',');
            getline(ss, seller, ',');

            if (x == 1 && id == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
            else if (x == 2 && name == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
            else if (x == 3 && seller == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
            else if (x == 4 && cp == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
            else if (x == 5 && sp == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
            else if (x == 6 && count == data)
            {
                update(id, name, seller, cp, sp, count);
                cout << "---------------------------" << endl;
                cout << "Product found!" << endl;
                display();
                if (choose == 's')
                {
                    return;
                }
                change_or_delete(index);
                break;
            }
        }
        file.close();
    }
    void search(char choose)
    {
        cout << "---------------------------" << endl;
        cout << "Enter search criteria (1: ID, 2: Name, 3: Supplier, 4: Cost Price, 5: Selling Price, 6: Count): ";
        int choice;
        cin >> choice;
        cout << "Enter search data: ";
        string data;
        cin >> data;
        search_file(choice, data, choose);
    }
    void add_product()
    {
        cout << "---------------------------" << endl;
        cout << "Enter product id: ";
        cin >> id;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter supplier name: ";
        cin >> supplier;
        cout << "Enter cost price: ";
        cin >> cp;
        cout << "Enter selling price: ";
        cin >> sp;
        cout << "Enter count: ";
        cin >> count;
        add_file();
    }
};

class admin : public data
{
public:
    void selecta()
    {
        cout << "---------------------------" << endl;
        cout << "1. Add Product\n2. Search Product\n5. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            add_product();
        }
        else if (choice == 2)
        {
            search('a');
        }
        else if (choice == 5)
        {
            return;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
        selecta();
    }
};
class staff : public data
{
public:
    void select()
    {
        cout << "---------------------------" << endl;
        cout << "1. View Data\n2. Search Product\n3. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            view_data();
        }
        else if (choice == 2)
        {
            search('s');
        }
        else if (choice == 3)
        {
            cout << "Exiting..." << endl;
            return;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
        select();
    }
};

int main()
{
    admin a;
    staff s;
    while (true)
    {
        cout << "---------------------------" << endl;
        cout << "1. Admin Menu\n2. Staff Menu\n3. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            a.selecta();
        }
        else if (choice == 2)
        {
            s.select();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
}
