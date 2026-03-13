//#include<iostream>
//#include <string>
//using namespace std;
//
//template <class T>
//int linearSearch(T arr[], int size, T key) {
//	for (int i = 0; i < size; i++) {
//		if (arr[i] == key)
//			return i;
//	}
//	return -1;
//}
//class Item {
//public:
//	virtual void display() = 0;
//};
//class Book : public Item {
//private:
//	string title;
//	string author;
//	int pages;
//public:
//	Book() {
//		title = "unlnown";
//		author = "unknown";
//		pages = 0;
//	}
//	Book(string t, string a, int p) {
//		title = t;
//		author = a;
//		pages = p;
//	}
//	string getTitle() {
//		return title;
//	}
//	string getAuthor() {
//		return author;
//	}
//	int getPages() {
//		return pages;
//	}
//	void setTitle(string t) {
//		title = t;
//	}
//	void setAuthor(string a) {
//		author = a;
//	}
//	void setPages(int p) {
//		pages = p;
//	}
//	bool operator==(Book b) {
//		return title == b.title;
//	}
//
//	void display() {
//		cout << "Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
//	}
//
//};
//class Newspaper : public Item {
//private:
//	string name;
//	string date;
//	string edition;
//
//public:
//	Newspaper() {}
//
//	Newspaper(string n, string d, string e) {
//		name = n;
//		date = d;
//		edition = e;
//	}
//
//	string getEdition() {
//		return edition;
//	}
//
//	string getName() {
//		return name;
//	}
//	bool operator==(Newspaper n) {
//		return name == n.name;
//	}
//	void display() {
//		cout << "Name: " << name << ", Date: " << date << ", Edition: " << edition << endl;
//	}
//};
//class Library {
//private :
//	Book books[10];
//	Newspaper newspapers[10];
//	int bookcount;
//	int newspapercount;
//public:
//	Library() {
//		bookcount = 0;
//		newspapercount = 0;
//	}
//	void addBook(Book b) {
//		books[bookcount++] = b;
//	}
//	void addNewspaper(Newspaper n) {
//		newspapers[newspapercount++] = n;
//	}
//	void displayCollection(){
//		cout << "\nBooks: \n";
//		for (int i = 0; i < bookcount;i++) {
//			books[i].display();
//		}
//		cout << "\nNewspapers: \n";
//		for (int i = 0; i < newspapercount;i++) {
//			newspapers[i].display();
//		}
//	}
//	void sortBooksByPages() {
//		for (int i = 0; i < bookcount - 1;i++) {
//			int min = i;
//			for (int j = i+1; j < bookcount;j++) {
//				if (books[j].getPages() < books[min].getPages());
//				min = j;
//			}
//			swap(books[i], books[min]);
//		}
//	}
//	void sortNewspapersByEdition() {
//		for (int i = 0; i < newspapercount - 1;i++) {
//			int min = i;
//			for (int j = i + 1;j < bookcount;j++) {
//				if (newspapers[j].getEdition() > newspapers[min].getEdition());
//			}
//			swap(newspapers[i], newspapers[min]);
//		}
//	}
//	Book* searchBookByTitle(string key) {
//		Book temp(key, "", 0);
//		int index = linearSearch(books, bookcount, temp);
//		if (index != -1)
//			return &books[index];
//		return NULL;
//	}
//
//	Newspaper* searchNewspaperByName(string key) {
//		Newspaper temp(key, "", "");
//		int index = linearSearch(newspapers, newspapercount, temp);
//		if (index != -1)
//			return &newspapers[index];
//		return NULL;
//	}
//};
//
//int main() {
//	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
//	Book book2("To Kill a Mockingbird", "Harper Lee", 324);
//
//	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
//	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
//
//	Library library;
//	 
//	library.addBook(book1);
//	library.addBook(book2);
//
//	library.addNewspaper(newspaper1);
//	library.addNewspaper(newspaper2);
//
//	cout << "Before Sorting:\n";
//	library.displayCollection();
//
//	library.sortBooksByPages();
//	library.sortNewspapersByEdition();
//
//	cout << "\nAfter Sorting:\n";
//	library.displayCollection();
//
//	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
//
//	if (foundBook) {
//		cout << "\nFound Book:\n";
//		foundBook->display();
//	}
//	else {
//		cout << "\nBook not found.\n";
//	}
//
//	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
//
//	if (foundNewspaper) {
//		cout << "\nFound Newspaper:\n";
//		foundNewspaper->display();
//	}
//	else {
//		cout << "\nNewspaper not found.\n";
//	}
//
//	return 0;
//}