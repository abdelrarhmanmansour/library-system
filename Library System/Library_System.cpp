//Project[Alex_Library]:




#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int arr_id[10];
string arr_title[10];
string arr_author[10];
bool arr_availability[10];
int counter=0;
void Add_book()
{
    cout << "Enter an ID: ";
    cin >> arr_id[counter];
    cout << "Enter a Title: ";
    cin >> arr_title[counter];
    cout << "Enter a Author: ";
    cin >> arr_author[counter];
    arr_availability[counter]=true;
    counter++;
    cout << "Book Add successfully\n";
    cout << endl;
}
int Search_book(int id)
{
    for(int i=0; i<counter; i++)
    {
        if(arr_id[i]==id)
        {
            return i;
        }
        else
        {
            return -1; 
        }
    }
}
void Update_book()
{
    cout << "Please enter an ID: ";
    int id;
    cin >> id;
    int index= Search_book(id);
    if(index!=-1)
    {
        cout << "Enter a title: ";
        cin >> arr_title[index];
        cout << "Enter a Author: ";
        cin >> arr_author[index];
        cout << "Book update successfully\n";
    }
    else
    {
        cout << "Book not found\n";
    }
}
void Remove_book()
{
    cout << "Please enter an ID: ";
    int id;
    cin >> id;
    int index= Search_book(id);
    if(index!=-1)
    {
        for(int i=index; i<counter-1; i++)
        {
            arr_id[i]=arr_id[i+1];
            arr_title[i]=arr_title[i+1];
            arr_author[i]=arr_author[i+1];
            arr_availability[i]=arr_availability[i+1];
        }
        counter--; 
        cout << "Book Removed successfully\n";
    }
    else
    {
        cout << "Book not found\n";
    }
}
void Return_book()
{
    cout << "Please enter an ID: ";
    int id;
    cin >> id;
    int index= Search_book(id);
    if(index!=-1)
    {
        if(!arr_availability[index]) // Borrowed;
        {
            arr_availability[index]=true; // available;
            cout << "Book returned successfully\n";
        }
    }
    else
    {
        cout << "Book not found\n";
    }
}
void Borrow_book()
{
    cout << "Please enter an ID: ";
    int id;
    cin >> id;
    int index= Search_book(id);
    if(index!=-1)
    {
        if(arr_availability[index])
        {
            arr_availability[index]=false;
            cout << "Book Borrowed successfully\n";
        }
        else
        {
            cout << "Book was borrowed\n";
        }
    }
    else
    {
        cout << "Book not found\n";
    }
}
void Display_books()
{
    if(counter==0)
    {
        cout << "there are not books here\n";
    }
    for(int i=0; i<counter; i++)
    {
        cout << "ID: " << arr_id[i] << ",Title: " << arr_title[i] << ",Author: " << arr_author[i]<< ",availability: " << (arr_availability[i] ? "Available" : "Borrowed") << endl;
    }
}
int main()
{
    cout << "Hello to my Library System:\n";
    cout << endl;
    int number;
    do
    {
        cout << "1/Add book\n";
        cout << "2/Update book\n";
        cout << "3/Remove book\n";
        cout << "4/Borrow book\n";
        cout << "5/Return book\n";
        cout << "6/Display book\n";
        cout << "choice a number: ";
        cin >> number;
        switch(number)
        {
        case 1:
            Add_book();
            break;
        case 2:
            Update_book();
            break;
        case 3:
            Remove_book();
            break;
        case 4:
            Borrow_book();
            break;
        case 5:
            Return_book();
            break;
        case 6:
            Display_books();
            break;
        case 7 :
            cout << "Exit\n";
            break;
        default :
            cout << "Bye\n";
        }
    }
    while(number!=7);
}

