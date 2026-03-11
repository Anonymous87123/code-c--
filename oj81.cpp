#include<bits/stdc++.h>
using namespace std;
class Book{
    private:
        double price;
        int number;
        string author;
        string ISBN;
        string bookname;
    public:
        Book(string name,double initprice,int initnumber,string initauthor,string initISBN){
            bookname=name;
            price=initprice;
            number=initnumber;
            author=initauthor;
            ISBN=initISBN;
        }
        string getBookname(){
            return bookname;
        }
        double getPrice(){
            return price;
        }
        int getNumber(){
            return number;
        }
        string getAuthor(){
            return author;
        }
        string getISBN(){
            return ISBN;
        }
};
class Library{
    public:
        vector<Book> books;
        void addBook(string name,double initprice,int initnumber,string initauthor,string initISBN){
            Book book(name,initprice,initnumber,initauthor,initISBN);
            books.push_back(book);
        }
        void displayBooks(){
            for(auto&book:books){
                cout<<"书名: "<<book.getBookname()<<", 价格: "<<book.getPrice()<<", 存书数量: "<<book.getNumber()<<", 作者: "<<book.getAuthor()<<", ISBN: "<<book.getISBN()<<endl;
            }
        }
        void removeBook(string ISBN){
            for(auto it=books.begin();it!=books.end();++it){
                if(it->getISBN()==ISBN){
                    books.erase(it);
                    break;
                }
            }
        }
};
int main() {
	Library library;
	library.addBook("C++ Primer", 99.9, 3, "Stanley B. Lippman", "1234567890123");
	library.addBook("Effective Modern C++", 59.9, 5, "Scott Meyers", "1234567890124");
	cout << "图书馆当前藏书：" << endl;
	library.displayBooks(); // 显示所有图书信息
	library.removeBook("1234567890123"); // 删除一本图书
	cout << "删除后图书馆藏书：" << endl;
	library.displayBooks(); // 再次显示所有图书信息
	return 0;
}