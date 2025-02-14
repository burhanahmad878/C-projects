#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string Full_Name;
    string phone_number;
    int contactid;
};

void addContact(Contact contacts[], int &size)
{
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, contacts[size].Full_Name);

    cout << "Enter phone number: ";
    getline(cin, contacts[size].phone_number);

    contacts[size].contactid = size + 1;
    size++;
    cout << "Contact added successfully!\n";
}

void showContact(Contact contacts[], int &size)
{
    cout << "\t ContactID \t Name \t\t    PhoneNumber " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\t " << contacts[i].contactid << "\t \t\t " << contacts[i].Full_Name << " \t\t\t " << contacts[i].phone_number << endl;
    }
}

void showbyname(Contact contacts[], int &size)
{
    string name;
    cout << "Enter name " << endl;
    cin >> name;
    bool isFound = false;
    for (int i = 0; i < size; i++)
    {
        if (contacts[i].Full_Name.find(name) != string::npos)
        {
            cout << "\t " << contacts[i].contactid << "\t \t\t " << contacts[i].Full_Name << " \t\t\t " << contacts[i].phone_number << endl;
            isFound = true;
        }
    }

    if (isFound == false)
    {
        cout << "Contact not found " << endl;
    }
}

void showbyid(Contact contacts[], int &size)
{
    int id;
    cout << "Enter contactId " << endl;
    cin >> id;

    cout << "\t " << contacts[id - 1].contactid << "\t \t\t " << contacts[id - 1].Full_Name << " \t\t\t " << contacts[id - 1].phone_number << endl;
}

void removeContact(Contact contacts[], int &size, int target)
{

    cout << "Do you want to remove this contact " << endl;
    cout << "1- yes " << endl;
    cout << "2 - No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            if (contacts[i].contactid != target)
            {
                contacts[index].Full_Name = contacts[i].Full_Name;
                contacts[index].phone_number = contacts[i].phone_number;
                contacts[index].contactid = contacts[i].contactid;

                index++;
            }

            size = index;
        }
    }
    else
    {
        return;
    }
}

int main()
{
    Contact contacts[1000];

    int size = 0;
    int gsize = 0;
    int choice = -1;
    cout << "...</ Contact Management system.../>" << endl;

    while (choice != 0)
    {
        cout << " Click Anyone of the following \n 1 : Add \n 2 : contact list \n 3 : Remove \n 4 : Search \n 0 : Exit \n " << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addContact(contacts, size);

            break;
        case 2:
            showContact(contacts, size);
            break;
        case 3:
        {
            string name;
            cout << "Enter name " << endl;
            cin >> name;
            int targetid;
            for (int i = 0; i < size; i++)
            {
                if (contacts[i].Full_Name.find(name) != string::npos)
                {
                    cout << "\t " << contacts[i].contactid << "\t \t\t " << contacts[i].Full_Name << " \t\t\t " << contacts[i].phone_number << endl;
                    targetid = contacts[i].contactid;
                }
            }
            removeContact(contacts, size, targetid);
        }
        break;
        case 4:
        {
            int user_choice;
            while (user_choice != 0)
            {
                cout << "1 : Search by ID " << endl;
                cout << "2 : Search by Name" << endl;
                cout << "0 : Back" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    showbyid(contacts, size);
                    break;

                case 2:
                    showbyname(contacts, size);
                    break;

                default:
                    break;
                }
            }
        }

        break;

        default:
            cout << "Exiting program. Thank you!\n";
            break;
        }
    }
    return 0;
}
