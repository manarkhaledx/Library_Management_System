#include <bits/stdc++.h>
using namespace std;
class Book { //Node
public:
    string Book_name;
    string Book_type;
    string Book_language;
    double price;
    string author;
    Book* prev;
    Book* next;
};
class library { //linked list
public:
    Book* head;
    Book* tail;

    library() {  //constructor of the class
        head = NULL;
        tail = NULL;
    }

    bool isempty() {  //check if the linked list is empty or not
        return(head == NULL);
    }
    bool IsFound(string Book_name){ //check if the book is found
        bool flag=false;
        transform(Book_name.begin(),Book_name.end(),Book_name.begin(),::tolower);
        int counter1 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->Book_name == Book_name) {
                counter1++;
                flag=true;
            }
            book = book->next;
        }
        if (counter1 == 0) {
            flag=false;
        }
        return flag;
    }


    void insert_first(string Book_name, string Book_type, string Book_language, double price, string author) { //insert the book at first position
        transform(author.begin(), author.end(), author.begin(), ::tolower);
        transform(Book_name.begin(), Book_name.end(), Book_name.begin(), ::tolower);
        transform(Book_type.begin(), Book_type.end(), Book_type.begin(), ::tolower);
        transform(Book_language.begin(), Book_language.end(), Book_language.begin(), ::tolower);
        Book* newbook = new Book(); //new node
        newbook->Book_name = Book_name;
        newbook->Book_type = Book_type;
        newbook->Book_language = Book_language;
        newbook->price = price;
        newbook->author = author;
        if (isempty()) {
            head = newbook;
            tail = newbook;
            newbook->prev = NULL;
            newbook->next = NULL;
        }
        else {
            newbook->next = head;
            newbook->prev = NULL;
            head = newbook;
        }
    }

    void insert_last(string Book_name, string Book_type, string Book_language, double price, string author) //insert a book at the end of the list
    {
        transform(author.begin(), author.end(), author.begin(), ::tolower);
        transform(Book_name.begin(), Book_name.end(), Book_name.begin(), ::tolower);
        transform(Book_type.begin(), Book_type.end(), Book_type.begin(), ::tolower);
        transform(Book_language.begin(), Book_language.end(), Book_language.begin(), ::tolower);
        if (isempty())
            insert_first(Book_name, Book_type, Book_language, price, author);
        else
        {
            Book* LastBook = head;  //as temp
            Book* newBook = new Book();
            newBook->Book_name = Book_name;
            newBook->Book_type = Book_type;
            newBook->Book_language = Book_language;
            newBook->price = price;
            newBook->author = author;
            while (LastBook->next != NULL) {
                LastBook = LastBook->next;
            }
            LastBook->next = newBook;
            newBook->next = NULL;
            newBook->prev = LastBook;

        }
    }

    void insert_After(string Current_book, string Book_name1, string Book_type, string Book_language, double price, string author) { //inserts the book after the book required
        transform(author.begin(), author.end(), author.begin(), ::tolower);
        transform(Book_name1.begin(), Book_name1.end(), Book_name1.begin(), ::tolower);
        transform(Book_type.begin(), Book_type.end(), Book_type.begin(), ::tolower);
        transform(Book_language.begin(), Book_language.end(), Book_language.begin(), ::tolower);
        if (isempty())
            insert_first(Book_name1, Book_type, Book_language, price, author);
        else  if(IsFound(Current_book)){
            {
                Book* newBook = new Book();
                newBook->Book_name = Book_name1;
                newBook->Book_type = Book_type;
                newBook->Book_language = Book_language;
                newBook->price = price;
                newBook->author = author;
                Book* current = head;
                while (current != NULL && current->Book_name != Current_book) {

                    current = current->next;
                }

                newBook->next = current->next;
                newBook->prev = current;
                current->next = newBook;

            }}else {
            cout<<"          Book you're searching for isn't Found"<<endl;
        }
    }

    void update_first(string new_Book_name, string new_Book_type, string new_Book_language, double new_price, string new_author) { //update information of the first position book
        transform(new_author.begin(), new_author.end(), new_author.begin(), ::tolower);
        transform(new_Book_name.begin(), new_Book_name.end(), new_Book_name.begin(), ::tolower);
        transform(new_Book_type.begin(), new_Book_type.end(), new_Book_type.begin(), ::tolower);
        transform(new_Book_language.begin(), new_Book_language.end(), new_Book_language.begin(), ::tolower);
        if (isempty()){
            cout<<"          No book found to update"<<endl;
        }
        else {
            Book* book = head;
            book->Book_name = new_Book_name;
            book->Book_type = new_Book_type;
            book->Book_language = new_Book_language;
            book->price = new_price;
            book->author = new_author;
        }
    }

    void update_last(string new_Book_name, string new_Book_type, string new_Book_language, double new_price, string new_author) { //update information of the last position book
        transform(new_author.begin(), new_author.end(), new_author.begin(), ::tolower);
        transform(new_Book_name.begin(), new_Book_name.end(), new_Book_name.begin(), ::tolower);
        transform(new_Book_type.begin(), new_Book_type.end(), new_Book_type.begin(), ::tolower);
        transform(new_Book_language.begin(), new_Book_language.end(), new_Book_language.begin(), ::tolower);
        if (isempty()) {
            cout<<"          No book found to update"<<endl;
        }
        else {
            Book* book = head;
            while (book->next != NULL) {
                book = book->next;
            }
            book->Book_name = new_Book_name;
            book->Book_type = new_Book_type;
            book->Book_language = new_Book_language;
            book->price = new_price;
            book->author = new_author;
        }
    }

    void update_at(string replaced_book, string new_Book_name, string new_Book_type, string new_Book_language, double new_price, string new_author) { //update information of  a certain book book
        transform(new_author.begin(), new_author.end(), new_author.begin(), ::tolower);
        transform(new_Book_name.begin(), new_Book_name.end(), new_Book_name.begin(), ::tolower);
        transform(new_Book_type.begin(), new_Book_type.end(), new_Book_type.begin(), ::tolower);
        transform(new_Book_language.begin(), new_Book_language.end(), new_Book_language.begin(), ::tolower);
        if (IsFound(replaced_book)) {
            Book *book = head; //book=temp
            while (book != NULL && book->Book_name != replaced_book) {
                book = book->next;
            }
            book->Book_name = new_Book_name;
            book->Book_type = new_Book_type;
            book->Book_language = new_Book_language;
            book->price = new_price;
            book->author = new_author;
        }
        else{
            cout<<"          No book found to update with this name"<<endl;
        }

    }

    void search_by_book_name(string Book_name) { //searches for book by its name
        transform(Book_name.begin(), Book_name.end(), Book_name.begin(), ::tolower);

        cout << "-------------------------------------------\n"
                "       Search Result For Book Name         \n"
                "-------------------------------------------\n";
        int counter1 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->Book_name == Book_name) {
                cout << "        " << book->Book_name << " Books Available:" << endl;
                cout << "        " << "Book type: " << book->Book_type << endl;
                cout << "        " << "Book language: " << book->Book_language << endl;
                cout << "        " << "Book price: " << book->price << endl;
                cout << "        " << "Book author: " << book->author << endl;
                cout << endl;
                counter1++;
            }
            book = book->next;
        }
        if (counter1 == 0) {
            cout << "          Book is not found" << endl << endl;
        }
    }

    void search_by_book_type(string Book_type) { //searches for book by its type
        transform(Book_type.begin(), Book_type.end(), Book_type.begin(), ::tolower);
        cout << "-------------------------------------------\n"
                "       Search Result For Book Type         \n"
                "-------------------------------------------\n";
        int counter2 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->Book_type == Book_type) {
                cout << "        " << Book_type << " Book type Available:" << endl;
                cout << "        " << "Book name:" << book->Book_name << endl;
                cout << "        " << "Book language:" << book->Book_language << endl;
                cout << "        " << "Book price:" << book->price << endl;
                cout << "        " << "Book author:" << book->author << endl;
                cout << endl;
                counter2++;
            }
            book = book->next;
        }
        if (counter2 == 0) {
            cout << "          Book type is not found" << endl << endl;
        }
    }

    void search_by_book_language(string Book_language) { //searches for book by its language
        transform(Book_language.begin(), Book_language.end(), Book_language.begin(), ::tolower);
        cout << "-------------------------------------------\n"
                "       Search Result For Book Language     \n"
                "-------------------------------------------\n";
        int counter3 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->Book_language == Book_language) {
                cout << "        " << Book_language << " Book language Available:" << endl;
                cout << "        " << "Book name:" << book->Book_name << endl;
                cout << "        " << "Book type:" << book->Book_type << endl;
                cout << "        " << "Book price:" << book->price << endl;
                cout << "        " << "Book author:" << book->author << endl;
                cout << endl;
                counter3++;
            }
            book = book->next;
        }
        if (counter3 == 0) {
            cout << "          Book language is not found" << endl << endl;
        }
    }

    void search_by_price(double price) { //searches for book by its price
        cout << "----------------------------------------\n"
                "       Search Result For Book Price     \n"
                "----------------------------------------\n";
        int counter4 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->price == price) {
                cout << "        " << price << " $ Book Collection:" << endl;
                cout << "        " << "Book name:" << book->Book_name << endl;
                cout << "        " << "Book type:" << book->Book_type << endl;
                cout << "        " << "Book language:" << book->Book_language << endl;
                cout << "        " << "Book author:" << book->author << endl << endl;
                cout << endl;
                counter4++;
            }
            book = book->next;
        }
        if (counter4 == 0) {
            cout << "          Book price is not found" << endl << endl;
        }
    }

    void search_by_author(string author) { //searches for book by its author
        transform(author.begin(), author.end(), author.begin(), ::tolower);
        cout << "----------------------------------------\n"
                "       Search Result For Book Author    \n"
                "----------------------------------------\n";
        int counter5 = 0;
        Book* book = head; //book=temp
        while (book != NULL) {
            if (book->author == author) {
                cout << "        " << author << " Books Available:" << endl;
                cout << "        " << "Book name:" << book->Book_name << endl;
                cout << "        " << "Book type:" << book->Book_type << endl;
                cout << "        " << "Book language:" << book->Book_language << endl;
                cout << "        " << "Book price:" << book->price << endl;
                cout << endl;
                counter5++;
            }
            book = book->next;
        }
        if (counter5 == 0) {
            cout << "          Book author is not found" << endl << endl;
        }
    }

    void delete_first() {  //delete the first book
        if (isempty()) {
            return;
        }
        Book* book;
        book = head;
        if (head != NULL) {
            head = head->next;
            if (head)
                head->prev = NULL;
            delete book;
        }
    }

    void delete_end() {  //delete the last book
        if (!isempty()) {
            if (head->next == NULL) {
                head = NULL;
            }
            else {
                Book* book = head;
                while (book->next->next != NULL)
                    book = book->next;
                Book* lastbook = book->next;
                book->next = NULL;
                delete lastbook;
            }
        }
    }

    void delete_by_name(string Book_name) {  //delete a book by its name
        if (isempty())
            return;
        if (head->Book_name == Book_name)
            delete_first();
        else
        {
            Book* temp = head->next;
            while (temp != NULL) {
                if (temp->Book_name == Book_name)
                    break;
                temp = temp->next;
            }
            if (temp == NULL)
                cout << "Book not found." << endl;
            else if (temp->next == NULL)
                delete_end();
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
    void sortListWithPrice(){  //sort all book by price
        Book* current;
        Book* q;
        current = head;
        q = NULL;
        string temp_Book_name;
        string temp_Book_type;
        string temp_Book_language;
        double temp_price;
        string temp_author;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL)
            {
                q = current->next;
                while (q != NULL)
                {
                    if (current->price > q->price)
                    {
                        temp_price = current->price;
                        current->price = q->price;
                        q->price = temp_price;

                        temp_Book_name = current->Book_name;
                        current->Book_name = q->Book_name;
                        q->Book_name = temp_Book_name;

                        temp_Book_type = current->Book_type;
                        current->Book_type = q->Book_type;
                        q->Book_type = temp_Book_type;

                        temp_Book_language = current->Book_language;
                        current->Book_language = q->Book_language;
                        q->Book_language = temp_Book_language;

                        temp_author = current->author;
                        current->author = q->author;
                        q->author= temp_author;
                    }
                    q = q->next;
                }
                current = current->next;
            }
        }
    }

    void sortListWithBookName(){  //sort all books by name
        Book* current;
        Book* q;
        current = head;
        q = NULL;
        string temp_Book_name;
        string temp_Book_type;
        string temp_Book_language;
        double temp_price;
        string temp_author;
        if (head == NULL) {
            return;
        }
        else {
            while (current != NULL)
            {
                q = current->next;
                while (q != NULL)
                {
                    if (int(tolower(current->Book_name[0])) > int(tolower(q->Book_name[0])))
                    {
                        temp_price = current->price;
                        current->price = q->price;
                        q->price = temp_price;

                        temp_Book_name = current->Book_name;
                        current->Book_name = q->Book_name;
                        q->Book_name = temp_Book_name;

                        temp_Book_type = current->Book_type;
                        current->Book_type = q->Book_type;
                        q->Book_type = temp_Book_type;

                        temp_Book_language = current->Book_language;
                        current->Book_language = q->Book_language;
                        q->Book_language = temp_Book_language;

                        temp_author = current->author;
                        current->author = q->author;
                        q->author= temp_author;
                    }
                    q = q->next;
                }
                current = current->next;
            }
        }
    }

    void count() { // counts number of books
        int counter = 0;
        Book* nextBook = head;
        while (nextBook != NULL) {
            counter++;
            nextBook = nextBook->next;
        }
        cout << "--------------------------------\n";
        cout << "    NO OF BOOKS IN LIBRARY  " << counter << endl;
        cout << "--------------------------------\n" << endl << endl;
    }

    void traversal() //displays the books in the library
    {
        Book* nextBook = head;
        if (nextBook == NULL) {
            cout << "No Books are available";
        }
        else {
            // Until p is not NULL
            cout << "--------------------------------\n"
                    "       Books In Library         \n"
                    "--------------------------------\n" << endl << endl;
            while (nextBook != NULL) {
                cout << "      Book Name:" << nextBook->Book_name << "       " << endl;
                cout << "       Book Type:" << nextBook->Book_type << "       " << endl;
                cout << "       Book Language:" << nextBook->Book_language << "       " << endl;
                cout << "       Author:" << nextBook->author << "       " << endl;
                cout << "       Price:" << nextBook->price << "       " << endl << endl;
                nextBook = nextBook->next;
            }
        }
    }

};


int main() {
    library Library; //make object of library
    string book_name, author_name, book_type, book_language;
    double price;
    string current_book;
    Library.insert_last("c++", "science", "english", 18, "james");
    Library.insert_last("100_day", "horror", "arabic", 25, "emilia");
    Library.insert_last("learn_spanish_easily", "language", "spanish", 10, "bill");
    Library.insert_last("data_structure", "science", "english", 30, "khaled");
    Library.insert_last("1980", "historical", "latin", 14, "pon");

    cout << "Login as Admin or user ?" << endl;
    string name;
    do {
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name != "admin" && name != "user") {
            cout << "Please enter a valid Choice" << endl;
        }
    } while (name != "admin" && name != "user");
    bool success = false;
    if (name == "admin") { // admin access
        string password;
        int attemps = 0;
        int counter = 2;

        do { //checks for admin password
            cout << "Please enter password" << endl;
            getline(cin, password);
            transform(password.begin(), password.end(), password.begin(), ::tolower);
            if (password == "admin") {
                cout << "success!" << endl;
                success = true;
                break;
            } else {
                cout << "Wrong password , you have " << counter << " attempts left" << endl;
                counter--;
                attemps++;
                if (counter == -1) {
                    cout << "          <<Access Denied>>         " << endl;
                    return 0;
                }
            }
        } while (attemps <= 3);
    }

    if (success) { //admin view list
        while (true) {
            cout << "---------------------------------------------" << endl;
            cout << "           Welcome to Our Library            " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       Select one of the following           " << endl;
            cout << "   1: Add a new book                         " << endl;
            cout << "   2: Search for a book                      " << endl;
            cout << "   3: Edit a book                            " << endl;
            cout << "   4: Delete a book                          " << endl;
            cout << "   5: Sort all books                         " << endl;
            cout << "   6: Display all books                      " << endl;
            cout << "   7: Exit                                   " << endl;

            cout << "\nEnter your Choice:\n";
            int choice;
            while (!(cin >> choice && choice <= 7 && choice >= 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "please Enter a Valid Choice" << endl;
            }

            if (choice == 1) { //add a new book list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Add First                              " << endl;
                cout << "   2: Add last                               " << endl;
                cout << "   3: Add at position                        " << endl;
                cout << "\nEnter your Choice:\n";
                int choice1;
                while (!(cin >> choice1 && choice1 <= 3 && choice1 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                cout << "Enter Book name: " << endl;
                cin >> book_name;
                cout << "Enter Book type: " << endl;
                cin >> book_type;
                cout << "Enter Book language: " << endl;
                cin >> book_language;
                cout << "Enter Price: " << endl;
                while (!(cin >> price && price >= 0)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Price" << endl;
                }
                cout << "Enter author name: " << endl;
                cin >> author_name;
                if (choice1 == 1) {
                    Library.insert_first(book_name, book_type, book_language, price, author_name);
                } else if (choice1 == 2) {
                    Library.insert_last(book_name, book_type, book_language, price, author_name);
                } else if (choice1 == 3) {
                    cout << "Enter current book: " << endl;
                    cin >> current_book;
                    Library.insert_After(current_book, book_name, book_type, book_language, price, author_name);
                }
            }

            else if (choice == 2) { //search_by_book list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Search by book name                    " << endl;
                cout << "   2: Search by book type                    " << endl;
                cout << "   3: Search by book language                " << endl;
                cout << "   4: Search by book price                   " << endl;
                cout << "   5: Search by book author                  " << endl;
                cout << "\nEnter your Choice:\n";
                int choice2;
                while (!(cin >> choice2 && choice2 <= 5 && choice2 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                if (choice2 == 1) {
                    cout << "Enter book name: " << endl;
                    cin >> book_name;
                    Library.search_by_book_name(book_name);
                } else if (choice2 == 2) {
                    cout << "Enter book type: " << endl;
                    cin >> book_type;
                    Library.search_by_book_type(book_type);
                } else if (choice2 == 3) {
                    cout << "Enter book language: " << endl;
                    cin >> book_language;
                    Library.search_by_book_language(book_language);
                } else if (choice2 == 4) {
                    cout << "Enter book price: " << endl;
                    while (!(cin >> price && price >= 0)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "please Enter a Valid Price" << endl;
                    }
                    Library.search_by_price(price);
                } else if (choice2 == 5) {
                    cout << "Enter author name: " << endl;
                    cin >> author_name;
                    Library.search_by_author(author_name);
                }
            }

            else if (choice == 3) { //modifying a book list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Edit first book                        " << endl;
                cout << "   2: Edit last book                         " << endl;
                cout << "   3: Edit a certain book                    " << endl;
                cout << "\nEnter your Choice:\n";
                int choice3;
                while (!(cin >> choice3 && choice3 <= 3 && choice3 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                cout << "Enter Book name: " << endl;
                cin >> book_name;
                cout << "Enter Book type: " << endl;
                cin >> book_type;
                cout << "Enter Book language: " << endl;
                cin >> book_language;
                cout << "Enter Price: " << endl;
                while (!(cin >> price && price >= 0)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Price" << endl;
                }
                cout << "Enter author name: " << endl;
                cin >> author_name;
                if (choice3 == 1) {
                    Library.update_first(book_name, book_type, book_language, price, author_name);
                } else if (choice3 == 2) {
                    Library.update_last(book_name, book_type, book_language, price, author_name);
                } else if (choice3 == 3) {
                    cout << "Enter current book: " << endl;
                    cin >> current_book;
                    Library.update_at(current_book, book_name, book_type, book_language, price, author_name);
                }
            }

            else if (choice == 4) { //deleting a book list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Delete first book                      " << endl;
                cout << "   2: Delete last book                       " << endl;
                cout << "   3: Delete a certain book                  " << endl;
                cout << "\nEnter your Choice:\n";
                int choice4;
                while (!(cin >> choice4 && choice4 <= 3 && choice4 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                if (choice4 == 1) {
                    Library.delete_first();
                } else if (choice4 == 2) {
                    Library.delete_end();
                } else if (choice4 == 3) {
                    cout << "Enter book name: " << endl;
                    cin >> book_name;
                    Library.delete_by_name(book_name);
                }
            }

             else if (choice == 5) { //sorting list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Sort by price                          " << endl;
                cout << "   2: Sort by book name                      " << endl;
                cout << "\nEnter your Choice:\n";
                int choice5;
                while (!(cin >> choice5 && choice5 <= 2 && choice5 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                if (choice5 == 1) {
                    Library.sortListWithPrice();
                    Library.traversal();
                } else if (choice5 == 2) {
                    Library.sortListWithBookName();
                    Library.traversal();
                }

            }

            else if (choice == 6) { //display list
                Library.traversal();
            }

            else if (choice == 7) { //quit the program
                exit(0);
            }
        }
    } else if (name == "user") { //user access
        cout << "What is your name ?" << endl;
        string Client_name;
        getline(cin, Client_name);
        cout << "Hello," << Client_name << endl;
        while (true) { // main list
            cout << "---------------------------------------------" << endl;
            cout << "           Welcome to Our Library            " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "       Select one of the following           " << endl;
            cout << "   1: Search for a book                      " << endl;
            cout << "   2: Sort all books                         " << endl;
            cout << "   3: Display all books                      " << endl;
            cout << "   4: Exit                                   " << endl;

            cout << "\nEnter your Choice:\n";
            int choice;
            while (!(cin >> choice && choice <= 4 && choice >= 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "please Enter a Valid Choice" << endl;
            }

            if (choice == 1) { //search_by_book list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Search by book name                    " << endl;
                cout << "   2: Search by book type                    " << endl;
                cout << "   3: Search by book language                " << endl;
                cout << "   4: Search by book price                   " << endl;
                cout << "   5: Search by book author                  " << endl;
                cout << "\nEnter your Choice:\n";
                int choice1;
                while (!(cin >> choice1 && choice1 <= 5 && choice1 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                if (choice1 == 1) {
                    cout << "Enter book name: " << endl;
                    cin >> book_name;
                    Library.search_by_book_name(book_name);
                } else if (choice1 == 2) {
                    cout << "Enter book type: " << endl;
                    cin >> book_type;
                    Library.search_by_book_type(book_type);
                } else if (choice1 == 3) {
                    cout << "Enter book language: " << endl;
                    cin >> book_language;
                    Library.search_by_book_language(book_language);
                } else if (choice1 == 4) {
                    cout << "Enter book price: " << endl;
                    while (!(cin >> choice && choice >= 0)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "please Enter a Valid Price" << endl;
                    }
                    Library.search_by_price(price);
                } else if (choice1 == 5) {
                    cout << "Enter author name: " << endl;
                    cin >> author_name;
                    Library.search_by_author(author_name);
                }
            }

            else if (choice == 2) { //sort list
                cout << "---------------------------------------------" << endl;
                cout << "       Select one of the following           " << endl;
                cout << "---------------------------------------------" << endl;
                cout << "   1: Sort by price                          " << endl;
                cout << "   2: Sort by book name                      " << endl;
                cout << "\nEnter your Choice:\n";
                int choice2;
                while (!(cin >> choice2 && choice2 <= 2 && choice2 >= 1)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "please Enter a Valid Choice" << endl;
                }
                if (choice2 == 1) {
                    Library.sortListWithPrice();
                    Library.traversal();
                } else if (choice2 == 2) {
                    Library.sortListWithBookName();
                    Library.traversal();
                }
            }

            else if (choice == 3) { //displays books
                Library.traversal();
            }

            else if (choice == 4) { //quit the program
                exit(0);
            }
        }
    }
}