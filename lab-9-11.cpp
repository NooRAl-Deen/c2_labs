#include <iostream>

using namespace std;

struct Book {
    int id;
    char name[30];
    float price;
};

struct BookStore {
    int id;
    char name[30];
    char category[30];
    int size;
    Book* books = new Book[size];
};

void addBook(BookStore store, int &cnt, int arrOfBooksId[])
{
    bool flag = false;
    if (cnt == store.size)
    {
        cout << "\n- Store is Full\n";
    }
    else {
        cout << "\n- Enter Id Number (" << cnt + 1 << ") Of Book : ";
        cin >> store.books[cnt].id;
        arrOfBooksId[cnt] = store.books[cnt].id;
        for (int i = 0; i < cnt; i++)
        {
            if (arrOfBooksId[i] == store.books[cnt].id)
            {
                cout << "\n- Book Already Exist.\n";
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "\n- Enter Name Number (" << cnt + 1 << ") Of Book : ";
            cin >> store.books[cnt].name;
            cout << "\n- Enter Price Number (" << cnt + 1 << ") Of Book : ";
            cin >> store.books[cnt].price;
        }
        else {
            cnt--;
        }
        cnt++;
    }
}

void findBookFromStore(BookStore store, Book searchedBook)
{
    bool flag = true;
    for (int i = 0; i < store.size; i++)
    {
        if (strcmp(store.books[i].name, searchedBook.name) == 0)
        {
            cout << "\n- " << store.books[i].id << " " << store.books[i].name << " " << store.books[i].price << endl;
            flag = false;
        }
    }
    if (flag)
    {
        cout << "\n- Book Not Found.\n";
    }
}


void displayBooks(BookStore store, int &cnt)
{
    if (cnt == 0)
    {
        cout << "\n- Store Empty.\n";
    }
    else {
        for (int i = 0; i < cnt; i++)
        {
            cout << "\n" << i + 1 << "- " << store.books[i].id << " " << store.books[i].name << " " << store.books[i].price << endl;
        }
    }
}

void swapBooks(Book &b1, Book &b2)
{
    Book tmp;
    tmp.id = b1.id;
    strcpy_s(tmp.name, b1.name);
    tmp.price = b1.price;
    b1.id = b2.id;
    strcpy_s(b1.name, b2.name);
    b1.price = b2.price;
    b2.id = tmp.id;
    strcpy_s(b2.name, tmp.name);
    b2.price = tmp.price;
}

void sortBookStore(BookStore &store)
{
    for (int i = 0; i < store.size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < store.size; j++)
        {
            if (store.books[minIndex].id > store.books[j].id)
            {
                minIndex = j;
            }
        }
        swapBooks(store.books[i], store.books[minIndex]);
    }
    cout << "\n- Books are Sorted.\n";
}

int main()
{
    BookStore store1 = { 1, "Store1", "University Books", 3 };
    int choice, arrOfBooksId[100], cnt = 0;
    char nameOfBook[30];
    Book bk = { 0, "", 0 };
    while (true)
    {
        cout << "\n1 - Add New Book.\n"
             << "2 - Show All Books.\n"
             << "3 - Show Book By Name.\n"
             << "4 - Sort.\n"
             << "5 - Exit.\n"
             << "\n- Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addBook(store1, cnt, arrOfBooksId);
            break;
        case 2:
            displayBooks(store1, cnt);
            break;
        case 3:
            cout << "\n- Enter Name Of Book : ";
            cin >> nameOfBook;
            strcpy_s(bk.name, nameOfBook);
            findBookFromStore(store1, bk);
            break;
        case 4:
            sortBookStore(store1);
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "\n- Invalid Choice.\n";
            break;
        }
    }
}