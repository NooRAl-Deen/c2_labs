#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Books {
    int bookId;
    string bookName;
    float bookPrice;
public:
    Books()
    {
        bookId = -1;
        bookName = "noname";
        bookPrice = 0;
    }
    Books(int bookId, string bookName, float bookPrice)
    {
        this->bookId = bookId;
        this->bookName = bookName;
        this->bookPrice = bookPrice;
    }
    void setBookId(int id)
    {
        this->bookId = id;
    }
    void setBookName(string name)
    {
        this->bookName = name;
    }
    void setBookPrice(float price)
    {
        this->bookPrice = price;
    }
    int getBookId()
    {
        return this->bookId;
    }
    string getBookName()
    {
        return this->bookName;
    }
    float getBookPrice()
    {
        return this->bookPrice;
    }
    void print()
    {
        cout << bookId << " \t " << bookName << " \t " << bookPrice << endl;
    }
};

class BookStore {
    int bookStoreId;
    string bookStoreName;
    string bookStoreCat;
    int bookStoreSize;
    Books* bookList;
public:
    BookStore()
    {
        this->bookStoreId = -1;
        this->bookStoreName = "noname";
        this->bookStoreCat = "unknown";
        this->bookStoreSize = 10;
        this->bookList = new Books[bookStoreSize];
        this->setBookStoreList();
    }
    BookStore(int bookStoreId, string bookStoreName, string bookStoreCat, int bookStoreSize)
    {
        this->bookStoreId = bookStoreId;
        this->bookStoreName = bookStoreName;
        this->bookStoreCat = bookStoreCat;
        this->bookStoreSize = bookStoreSize;
        this->bookList = new Books[bookStoreSize];
        this->setBookStoreList();
    }
    void setStoreId(int id)
    {
        this->bookStoreId = id;
    }
    void setStoreName(string name)
    {
        this->bookStoreName = name;
    }
    void setStoreCat(string cat)
    {
        this->bookStoreCat = cat;
    }
    void setStoreSize(int size)
    {
        this->bookStoreSize = size;
    }
    void setBookStoreList()
    {
        int bid;
        string bname;
        float bprice;
        for (int i = 0; i < bookStoreSize; i++)
        {
            cout << "\n- enter book " << i + 1 << " id : ";
            cin >> bid;
            this->bookList[i].setBookId(bid);
            cout << "\n- enter book "<< i + 1 <<" name : ";
            cin >> bname;
            this->bookList[i].setBookName(bname);
            cout << "\n- enter book " << i + 1 <<" price : ";
            cin >> bprice;
            this->bookList[i].setBookPrice(bprice);
        }
    }
    int getStoreId()
    {
        return this->bookStoreId;
    }
    string getStoreName()
    {
        return this->bookStoreName;
    }
    string getStoreCat()
    {
        return this->bookStoreCat;
    }
    int getStoreSize()
    {
        return this->bookStoreSize;
    }
    void print()
    {
        cout << "\n---------------------------------------------------------\n";
        cout << "## Sotre Information ##" << endl;
        cout << endl << "- Store Id : " << this->bookStoreId << endl
                     << "- Store Name : " << this->bookStoreName << endl
                     << "- Store Category : " << this->bookStoreCat << endl
                     << "- Store Size : " << this->bookStoreSize << endl << endl;
        cout << "## Books Information - Store : " << this->bookStoreName << endl << endl;
        for (int i = 0; i < bookStoreSize; i++)
        {
            cout << "- Book " << i + 1 << " : ";
            this->bookList[i].print();
        }
        cout << "---------------------------------------------------------";
    }
};

int main()
{
    BookStore storeOne(1, "store 1", "books university", 2), storeTwo;
    storeOne.print();
    storeTwo.print();
}
