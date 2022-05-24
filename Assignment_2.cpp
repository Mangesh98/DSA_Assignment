// Implement all the functions of a dictionary (ADT) using hashing and handle collisions using chaining with/without replacement. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)

#include <iostream>
#include <string.h>
using namespace std;

class HashFunction
{
private:
    int total_element = 10;
    typedef struct hashTable
    {
        long key;
        char name[10];
    } hash;
    hash h[10];

public:
    HashFunction();
    void display();
    int find(long);
    void insert();
    void Delete(long);
};

HashFunction::HashFunction()
{

    for (int i = 0; i < total_element; i++)
    {
        h[i].key = -1;
        strcpy(h[i].name, "NULL");
    }
}
int HashFunction::find(long key)
{
    for (int i = 0; i < total_element; i++)
    {
        if (h[i].key == key)
        {
            return i;
        }
    }
    return -1;
}
void HashFunction::Delete(long key)
{
    int index = find(key);
    if (index == -1)
    {
        cout << "\n\tKey Not Found !";
    }
    else
    {
        h[index].key = -1;
        strcpy(h[index].name, "NULL");
        cout << "\n\tKey Deleted Successfully ";
    }
}

void HashFunction::display()
{
    cout << "\n\t\tKey\t\tName";
    for (int i = 0; i < total_element; i++)
    {
        cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].name;
    }
}

void HashFunction::insert()
{
    char ans, name[10], tName[10];
    long tTelephone, telephone;
    int count = 0, hashKey, flag = 0;
    do
    {
        if (count >= 10)
        {
            cout << "\n\tHash Table is FULL";
            break;
        }
        cout << "\n\tEnter value of Telephone : ";
        cin >> telephone;
        cout << "\n\tEnter value of Name : ";
        cin >> name;
        hashKey = telephone % total_element;

        if (h[hashKey].key == -1)
        {
            h[hashKey].key = telephone;
            strcpy(h[hashKey].name, name);
        }
        else
        {
            if (h[hashKey].key % total_element != hashKey)
            {
                tTelephone = h[hashKey].key;
                strcpy(tName, h[hashKey].name);
                h[hashKey].key = telephone;
                strcpy(h[hashKey].name, name);

                for (int i = hashKey + 1; i < total_element; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = tTelephone;
                        strcpy(h[i].name, tName);
                        flag = 1;
                        break;
                    }
                }
                for (int i = 0; i < hashKey && flag == 0; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = tTelephone;
                        strcpy(h[i].name, tName);
                        break;
                    }
                }
            }
            else
            {
                for (int i = hashKey; i < total_element; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = telephone;
                        strcpy(h[i].name, name);
                        flag = 1;
                        break;
                    }
                }
                for (int i = 0; i < hashKey && flag == 0; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = telephone;
                        strcpy(h[i].name, name);
                        break;
                    }
                }
            }
        }
        flag = 0;
        count++;
        cout << "\n\t..... Do You Want to Insert More Key: y/n";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

int main()
{
    long k;
    int ch, index;
    char ans;
    HashFunction obj;
    do
    {
        cout << "\n\t*** Telephone (ADT) *****";
        cout << "\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\n\tEnter a Key Which You Want to Search: ";
            cin >> k;
            index = obj.find(k);
            if (index == -1)
            {
                cout << "\n\tKey Not Found";
            }
            break;
        case 4:
            cout << "\n\tEnter a Key Which You Want to Delete: ";
            cin >> k;
            obj.Delete(k);
            break;
        case 5:
            break;
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu:y/n ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}