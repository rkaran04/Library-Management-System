#include <bits/stdc++.h>
#include <chrono>
using namespace std;

vector<vector<string>> information;
vector<string> updates;

void read_file(string fname){ 
    vector<string> row;
    string line, word;

    fstream file (fname,ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, word, ',')) row.push_back(word);
            information.push_back(row);
        }
    }
    else cout<<"Could not open the file\n";
}
void write_file(vector<vector<string>> par, string fname){  
    fstream fout(fname,ios::out);
    for(auto x:par){
        for(auto y:x){
            fout<<y;
            if(y!=x.back()) fout<<",";
        }
        fout<<"\n";
    }

}
void write_fileappend(vector<string> par, string fname){  
    fstream fout(fname,ios::out | ios::app);
    for(auto x:par){
        fout<<x;
        if(x!=par.back()) fout<<",";
    }
    fout<<"\n";
}
void printdata(vector<vector<string>> par){
    int c=1;
    for(auto x:par){
        cout<<c<<". ";
        for(auto y:x){
            cout<<y;
            if(y!=x.back()) cout<<" | ";
        }
        c++;
        cout<<"\n";
    }
}
void printdata_notpassword(vector<vector<string>> par){
    int c=1;
    for(auto x:par){
        cout<<c<<". ";
        cout<<x[0]<<" | "<<x[1]<<" | "<<x[3]<<'\n';
        c++;
    }
}

class User{
    private:
        string password;
    public:
        string name;
        string id;
        vector<string> isbns_issued;
        void display_menu();
        void login();
        void see_all_books(string id);
        void see_issued_books(string id);
        void logout();
        void issue_book(string id, string bookname,string type_user);
        void return_book(string id,string isbncode);
        void check_available(string id, string bookname);
        int calc_fine(string id,string type_user);
        void clear_fine_amount(string id,string type_user);
        void User_add(string id);
        void User_update(string id);
        void User_delete(string id);
        void User_search(string id);
};
class Book{
    public:
        string title;
        string author;
        string isbn;
        string publication;
        int is_issued;
    void Book_request(string id,string bookname,string type_user);
    void Show_duedate(string isbn_no);
    void Book_add(string id);
    void Book_update(string id);
    void Book_delete(string id);
    void Book_search(string id);
    
};
class Student : public User{
    public:
        int Fine_amount;
        void display_student_menu(string id);
};
class Professor : public User{
    public:
        int Fine_amount;
    public:
        void display_prof_menu(string id);

};
class Librarian : public User{
    public:
        void display_lib_menu(string id);
        void see_all_users(string id);
        void see_all_books(string id);
        void add_user(string id);
        void update_user(string id);
        void delete_user(string id);
        void add_book(string id);
        void update_book(string id);
        void delete_book(string id);
        void see_issued_to_user(string id,string uid);
        void see_issued_book(string id,string isbn);
        
};

void Student :: display_student_menu(string id){
    cout<<"---------------------------------------------------------------------\n";
    cout<<"\nYou have been logged in as Student\n";
    cout<<"Press 1 to see all the books\n";
    cout<<"Press 2 to view books issued by you\n";
    cout<<"Press 3 to check if a book is available for issue or not\n";
    cout<<"Press 4 to view the fine\n";
    cout<<"Press 5 to issue a book\n";
    cout<<"Press 6 to return a book\n";
    cout<<"Press 7 to clear your fine\n";
    cout<<"Press 8 to logout\n";
    cout<<"---------------------------------------------------------------------\n";
    char c;
    cin>>c;
    string book_name,isbncode;
    Student s;
    Book b;
    switch(c){
        case '1':
            s.see_all_books(id);
            s.display_student_menu(id);
            break;
        case '2':
            s.see_issued_books(id);
            s.display_student_menu(id);
            break;
        case '3':
            cout<<"Enter the name of the book you want to check : ";
            cin.ignore();
            getline(cin,book_name);
            s.check_available(id,book_name);
            s.display_student_menu(id);
            break;
        case '4':
            s.calc_fine(id,"1");
            s.display_student_menu(id);
            break;
        case '5':
            cout<<"Enter the name of the book you want to issue : ";
            cin.ignore();
            getline(cin,book_name);
            b.Book_request(id,book_name,"1");
            s.display_student_menu(id);            
            break;
        case '6':
            cout<<"Enter the isbn code of the book you want to return : ";
            cin>>isbncode;
            s.return_book(id,isbncode);
            s.display_student_menu(id);
            break;
        case '7':
            s.clear_fine_amount(id,"1");
            s.display_student_menu(id);
            break;           
        case '8':
            logout();
            break;
    }
}

void Professor :: display_prof_menu(string id){
    cout<<"---------------------------------------------------------------------\n";
    cout<<"\nYou have been logged in as Student\n";
    cout<<"Press 1 to see all the books\n";
    cout<<"Press 2 to view books issued by you\n";
    cout<<"Press 3 to check if a book is available for issue or not\n";
    cout<<"Press 4 to view the fine\n";
    cout<<"Press 5 to issue a book\n";
    cout<<"Press 6 to return a book\n";
    cout<<"Press 7 to clear your fine\n";
    cout<<"Press 8 to logout\n";
    cout<<"---------------------------------------------------------------------\n";
    char c;
    cin>>c;
    string book_name,isbncode;
    Professor s;
    switch(c){
        case '1':
            s.see_all_books(id);
            s.display_prof_menu(id);
            break;
        case '2':
            s.see_issued_books(id);
            s.display_prof_menu(id);
            break;
        case '3':
            cout<<"Enter the name of the book you want to check : ";
            cin>>book_name;
            s.check_available(id,book_name);
            s.display_prof_menu(id);
            break;
        case '4':
            s.calc_fine(id,"2");
            s.display_prof_menu(id);
            break;
        case '5':
            cout<<"Enter the name of the book you want to issue : ";
            cin>>book_name;
            s.issue_book(id,book_name,"2");
            s.display_prof_menu(id);            
            break;
        case '6':
            cout<<"Enter the isbn code of the book you want to return : ";
            cin>>isbncode;
            s.return_book(id,isbncode);
            s.display_prof_menu(id);
            break;
        case '7':
            s.clear_fine_amount(id,"2");
            s.display_prof_menu(id);
            break;
        case '8':
            logout();
            break;
    }
}

void User :: display_menu(){
    char c;
    cout<<"---------------------------------------------------------------------\n";
    cout<<"\n\nWelcome to the library management system!\n\n";
    cout<<"1. Press 1 to log in : \n";
    cout<<"2. Press 2 to exit\n";
    cout<<"---------------------------------------------------------------------\n";
    cin>>c;
    if(c=='1'){ //logs in a user 
        User u;
        u.login();
    }
    else{
        cout<<"Thanks for using the system !";
        exit(1);
    }
}
void User :: login(){

    string id,password;
    cout<<"Enter your id : ";
    cin>>id;
    cout<<"Enter the password : ";
    cin>>password;
    vector<string> words_in_a_row;
    string line_in_csv,word;
    fstream file("users_data.csv",ios::in);
    int count=0;
    if(file.is_open()){
        while(getline(file,line_in_csv)){
            words_in_a_row.clear();
            stringstream str(line_in_csv);
            while(getline(str,word,',')) words_in_a_row.push_back(word);
            if(words_in_a_row[1]==id){
                count=1;
                if(words_in_a_row[2]==password){
                    count++;
                    break;
                }
                else{
                    while(password!=words_in_a_row[2]){
                        cout<<"You entered the wrong password. Press 1 to reenter the password and 2 to exit\n";
                        char c;
                        cin>>c;
                        if(c=='1'){
                            cout<<"Enter the password : ";
                            cin>>password;
                            if(password==words_in_a_row[2]) count++;
                        }
                        else if(c=='2'){
                            cout<<"Exiting...";
                            return;
                        }
                        else{
                            cout<<"Please enter a valid input.\n";
                        }
                    }
                    if(count==2) break;
                }
            }
            if(count==2) break;            
        }
        if(count==0){
            cout<<"User not found\n";
            User u;
            u.display_menu();
        }
        if(count==2){

            Student s;
            Professor p;
            Librarian l;

            if(words_in_a_row[3]=="1"){
                s.display_student_menu(words_in_a_row[1]);
            }
            else if(words_in_a_row[3]=="2"){
                p.display_prof_menu(words_in_a_row[1]);
            }
            else{
                l.display_lib_menu(words_in_a_row[1]);
            }
        }
    }
}
void User :: see_all_books(string id){
    information.clear();
    cout<<"In the data below, 0 signifies that the book is not issued and 1 means that the book is issued.\n";
    read_file("books_data.csv");
    printdata(information);
    information.clear();
}
void User :: issue_book(string id,string bookname,string type_user){
    information.clear();
    int fl=0;
    if(type_user=="1"){
        int count=0;
        information.clear();
        read_file("issued_books_data.csv");
        for(int i=0;i<information.size();i++){
            if(information[i][0]==id){
                count++;
            }
        }
        information.clear();
        if(count>4){
            cout<<"You cant issue more than 5 books !\n\n";
        }
        else{
            read_file("books_data.csv");
            for(int i=0;i<information.size();i++){
                if(information[i][0]==bookname && information[i][4]=="0"){
                    fl=1;
                    cout<<"Book is available!\n";
                    information[i][4]="1";
                    updates.clear();
                    updates.push_back(id);
                    updates.push_back(bookname);
                    updates.push_back(information[i][3]);
                    updates.push_back(to_string(time(0)));
                    write_fileappend(updates,"issued_books_data.csv");
                    cout<<"Book succesfully issued\n";
                    break;
                }
            }
            if(fl==0) cout<<"Book not available\n";
            write_file(information,"books_data.csv");
            information.clear();
        }
    }
    if(type_user=="2"){
        read_file("books_data.csv");
        for(int i=0;i<information.size();i++){
            if(information[i][0]==bookname && information[i][4]=="0"){
                fl=1;
                cout<<"Book is available!\n";
                information[i][4]="1";
                updates.clear();
                updates.push_back(id);
                updates.push_back(bookname);
                updates.push_back(information[i][3]);
                updates.push_back(to_string(time(0)));
                write_fileappend(updates,"issued_books_data.csv");
                cout<<"Book succesfully issued\n";
                break;
            }
        }
        if(fl==0) cout<<"Book not available\n";
        write_file(information,"books_data.csv");
        information.clear();
    }
}
void User :: return_book(string id,string isbncode){
    information.clear();
    int fl=0;
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][2]==isbncode && information[i][0]==id){
            fl=1;
            information.erase(information.begin()+i,information.begin()+i+1);
            cout<<"Book was issued by you and is now being returned\n";
            write_file(information,"issued_books_data.csv");
            information.clear();
            read_file("books_data.csv");
            for(int i=0;i<information.size();i++){
                if(information[i][3]==isbncode) information[i][4]="0";
            }
            write_file(information,"books_data.csv");
            break;
        }
    }
    if(fl==0) cout<<"Invalid details!\n";

    information.clear();
}
void User :: see_issued_books(string id){
    int count=1;
    information.clear();
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][0]==id){
            cout<<count<<". ";
            count++;
            for(int k=0;k<information[i].size()-1;k++)
                cout<<information[i][k]<<" | ";
            time_t stamp = stoi(information[i][3]);
            tm *dateformat = localtime(&stamp);  
            cout<< dateformat->tm_mday<<"/"<<1 + dateformat->tm_mon<<"/"<<1900 + dateformat->tm_year<<"\n";
        }
    }
    if(count==0) cout<<"You haven't issued any books as of now\n\n";
    information.clear();
}
void User :: check_available(string id,string bookname){
    information.clear();
    int fl=0;
    read_file("books_data.csv");
    int count=1;
    for(int i=0;i<information.size();i++){
        if(information[i][0]==bookname && information[i][4]=="0"){
            fl=1;
            cout<<count<<". ";
            count++;
            cout<<"Book is available!\n";
            for(auto j:information[i])
                cout<<j<<" | ";
            cout<<"\n";
            break;
        }
    }
    if(fl==0) cout<<"Book not available\n";
    information.clear();
}
int User :: calc_fine(string id, string type_user){
    int fine=0;
    if(type_user=="1"){
        information.clear();
        read_file("issued_books_data.csv");
        for(int i=0;i<information.size();i++){
            if(information[i][0]==id){
                int curtime = time(0);
                int isstime = stoi(information[i][3]);
                if((curtime-isstime)/86400>30) fine+=2*((curtime-isstime)/86400 - 30);
            }
        }
        cout<<"Your fine is : "<<fine<<"\n";
        return fine;
        information.clear();
    }
    if(type_user=="2"){
        information.clear();
        read_file("issued_books_data.csv");
        for(int i=0;i<information.size();i++){
            if(information[i][0]==id){
                int curtime = time(0);
                int isstime = stoi(information[i][3]);
                if((curtime-isstime)/86400>60) fine+=5*((curtime-isstime)/86400 - 60);
            }
        }
        cout<<"Your fine is : "<<fine<<"\n";
        information.clear();
    }
    return fine;
}
void User :: logout(){
    cout<<"Logging out...\n";
    User u;
    u.display_menu();
}
void User :: clear_fine_amount(string id,string type_user){
    int a = calc_fine(id,type_user);
    if(a==0) cout<<"You have no pending dues\n";
    else cout<<"Your fine of Rupees "<<a<<" is being cleared.\n";
}
void User :: User_add(string id){
    Librarian l;
    l.add_user(id);
}
void User :: User_delete(string id){
    Librarian l;
    l.delete_user(id);
}
void User :: User_update(string id){
    Librarian l;
    l.update_user(id);
}
void User :: User_search(string id){

}

void Book :: Show_duedate(string isbn){
    information.clear();
    string uid;
    time_t stamp;
    read_file("issued_books_data.csv");
    int fl=0;
    for(int i=0;i<information.size();i++){
        if(information[i][2]==isbn){
            fl=1;
            uid = information[i][0];
            stamp = stoi(information[i][3]);
            break;
        }
    }
    information.clear();
    int days=30;
    read_file("users_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][1]==uid){
            if(information[i][3]=="1")
                days=30;
            else
                days=60;
            break;
        }
    }
    stamp+=days*86400;
    tm *due_time = localtime(&stamp);  
    if(fl==0) cout<<"Book was not issued!\n";
    else{
        cout<<"Due date of the book is : ";
        cout<< due_time->tm_mday<<"/"<<1 + due_time->tm_mon<<"/"<<1900 + due_time->tm_year<<"\n";
    }
}
void Book :: Book_request(string id,string bookname,string type_user){
    User u;
    u.issue_book(id,bookname,type_user);
}
void Book :: Book_add(string id){
    Librarian l;
    l.add_book(id);
}
void Book :: Book_delete(string id){
    Librarian l;
    l.delete_book(id);
}
void Book :: Book_update(string id){
    Librarian l;
    l.update_book(id);
}
void Book :: Book_search(string id){

}

void Librarian :: display_lib_menu(string id){
    cout<<"---------------------------------------------------------------------\n";
    cout<<"\nWelcome "<<id<<"! You are logged in as librarian.\n\n";
    cout<<"Press 1 to add a user\n";
    cout<<"Press 2 to update a user\n";
    cout<<"Press 3 to delete a user\n";
    cout<<"Press 4 to add a book\n";
    cout<<"Press 5 to update a book\n";
    cout<<"Press 6 to delete a book\n";
    cout<<"Press 7 to see all books issued to a particular user\n";
    cout<<"Press 8 to see which book is issued to which user\n";
    cout<<"Press 9 to view all users\n";
    cout<<"Press 0 to view all books\n";
    cout<<"Press d to show due date of a book\n";
    cout<<"Press l to logout\n";
    cout<<"---------------------------------------------------------------------\n";
    char c;
    cin>>c;
    Librarian l;
    Book b;
    User u;
    string isbn,uid;
    switch(c){
        case '1':
            u.User_add(id);
            l.display_lib_menu(id);
            break;
        case '2':
            u.User_update(id);
            l.display_lib_menu(id);
            break;
        case '3':
            u.User_delete(id);
            l.display_lib_menu(id);
            break;
        case '4':
            b.Book_add(id);
            l.display_lib_menu(id);
            break;
        case '5':
            b.Book_update(id);
            l.display_lib_menu(id);
            break;
        case '6':
            b.Book_delete(id);
            l.display_lib_menu(id);
            break;
        case '7':
            cout<<"Enter the id of the user : ";
            cin>>uid;
            l.see_issued_to_user(id,uid);
            l.display_lib_menu(id);
            break;
        case '8':
            cout<<"Enter the isbn number of the book : ";
            cin>>isbn;
            l.see_issued_book(id,isbn);
            l.display_lib_menu(id);
            break;
        case '9':
            l.see_all_users(id);
            l.display_lib_menu(id);
            break;
        case '0':
            l.see_all_books(id);
            l.display_lib_menu(id);
            break;
        case 'd':
            cout<<"Enter the isbn number of the book : ";
            cin>>isbn;
            b.Show_duedate(isbn);
            l.display_lib_menu(id);
            break;
        case 'l':
            logout();
            l.display_lib_menu(id);
            break;
    }
}

void Librarian :: see_all_users(string id){
    information.clear();
    read_file("users_data.csv");
    cout<<"Below are all the users. 1 at the end signifies a student, 2 means a professor and 3 means a librarian \n\n";
    cout<<"The data is given in the form of student,username,type of user.\n\n";
    printdata_notpassword(information);
    information.clear();
}
void Librarian :: see_all_books(string id){
    information.clear();
    read_file("books_data.csv");
    cout<<"Below are all the books. 1 at the end signifies a student, 2 means a professor and 3 means a librarian \n\n";
    cout<<"The data is given in the form of book name,author,pubisher,isbn number,and is_issued(1 if book is issued).\n\n";
    printdata(information);
    information.clear();
}
void Librarian :: add_user(string id){
    cout<<"Please enter the details of the new user : \n";
    string _name,_id,_password,_type;
    cout<<"Enter name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter id : ";
    cin>>_id;
    cout<<"Enter password : ";
    cin>>_password;
    cout<<"Enter type of the user : 1 if student, 2 if professor, 3 if librarian : ";
    cin>>_type;
    fstream fout("users_data.csv",ios::out | ios::app);
    fout<<name<<","<<_id<<","<<_password<<","<<_type<<'\n';
    cout<<"New user has been added.\n";
}
void Librarian :: add_book(string id){
    cout<<"Please enter the details of the new book : \n";
    string title,author,isbn,publisher;
    cout<<"Enter title: ";
    cin.ignore();
    getline(cin,title);
    cout<<"Enter author : ";
    cin>>author;
    cout<<"Enter isbn : ";
    cin>>isbn;
    cout<<"Enter name of publisher : ";
    cin>>publisher;
    fstream fout("books_data.csv",ios::out | ios::app);
    fout<<title<<","<<author<<","<<isbn<<","<<publisher<<",0"<<'\n';
    cout<<"New book has been added.\n";
}
void Librarian :: delete_book(string id){
    string isbnno;
    cout<<"Enter the isbn number of the book : ";
    cin>>isbnno;
    information.clear();
    int found=0;
    read_file("books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][3]==isbnno){
            found=1;
            information.erase(information.begin()+i,information.begin()+i+1);
            break;
        }
    }
    write_file(information,"books_data.csv");
    information.clear();
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][2]==isbnno){
            information.erase(information.begin()+i,information.begin()+i+1);
            break;
        }
    }
    write_file(information,"issued_books_data.csv");
    information.clear();
    if(found==0) cout<<"Book not found.\n";
}
void Librarian :: delete_user(string id){
    string uid;
    cout<<"Enter the user id of the user : ";
    cin>>uid;
    information.clear();
    int found=0;
    read_file("users_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][1]==uid){
            found=1;
            information.erase(information.begin()+i,information.begin()+i+1);
            break;
        }
    }
    write_file(information,"users_data.csv");
    information.clear();
    vector<string> isbns;
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][0]==uid){
            isbns.push_back(information[i][2]);
            information.erase(information.begin()+i,information.begin()+i+1);
            break;
        }
    }
    write_file(information,"issued_books_data.csv");
    information.clear();

    read_file("books_data.csv");
    for(int i=0;i<information.size();i++){
        for(int j=0;j<isbns.size();j++){
            if(isbns[j]==information[i][3]){
                information[i][4]="0";
            }
        }
    }
    write_file(information,"books_data.csv");
    if(found==0) cout<<"User not found.\n";
}
void Librarian :: update_user(string id){
    string upid;
    cout<<"Enter the id of the user you want to update : ";
    cin>>upid;
    cout<<"Enter the serial number of the field you want to update : \n";
    cout<<"1. Password\n";
    cout<<"2. Name of the User\n";
    char c;
    cin>>c;
    information.clear();
    int fl=0;
    read_file("users_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][1]==upid){
            fl=1;
            string new_field;
            cout<<"Enter the new value of the field : ";
            cin.ignore();
            getline(cin,new_field);
            if(c=='1'){
                information[i][2]=new_field;
            }
            else if(c=='2'){
                information[i][0]=new_field;
            }
            else{
                cout<<"Invalid input!\n\n";
            }
            break;
        }
    }
    cout<<"User updated\n";
    write_file(information,"users_data.csv");
    information.clear();
    if(fl==0) cout<<"User was not found.\n\n";
}
void Librarian :: update_book(string id){
    string isbn_no;
    cout<<"Enter the isbn number of the book you want to update : ";
    cin>>isbn_no;
    cout<<"Enter the serial number of the field you want to update : \n";
    cout<<"1. Name of the Book\n";
    cout<<"2. Name of the Author\n";
    cout<<"3. Name of the Publisher\n";
    char c;
    cin>>c;
    information.clear();
    int fl=0;
    string new_field;
    read_file("books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][3]==isbn_no){
            fl=1;
            cout<<"Enter the new value of the field : ";
            cin.ignore();
            getline(cin,new_field);
            if(c=='1'){
                information[i][0]=new_field;
            }
            else if(c=='2'){
                information[i][1]=new_field;
            }
            else if(c=='3'){
                information[i][2]=new_field;
            }
            else{
                cout<<"Invalid input!\n\n";
            }
            break;
        }
    }
    write_file(information,"books_data.csv");
    information.clear();
    
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][2]==isbn_no){
            fl=1;
            if(c=='1'){
                information[i][1]=new_field;
            }
            break;
        }
    }
    cout<<"Book updated\n";
    write_file(information,"issued_books_data.csv");

    if(fl==0) cout<<"Book was not found.\n\n";
}
void Librarian :: see_issued_to_user(string id,string uid){
    vector <string> isbns;
    information.clear();
    int count=1;
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        if(information[i][0]==uid){
            isbns.push_back(information[i][2]);
        }
    }
    information.clear();
    if(isbns.size()==0) cout<<"No book is issued to this user.\n\n";
    else{
        read_file("books_data.csv");
        for(int d=0;d<isbns.size();d++){
            for(int i=0;i<information.size();i++){
                if(information[i][3]==isbns[d]){
                    cout<<count<<". ";
                    count++;
                    for(auto y:information[i]){
                        if(y!=information[i].back())
                            cout<<y<<" | ";
                        else
                            cout<<y<<"\n";
                    }
                }
            }
        }
        information.clear();
    }
}
void Librarian :: see_issued_book(string id,string isbn){
    information.clear();
    int coun=0;
    read_file("issued_books_data.csv");
    for(int i=0;i<information.size();i++){
        coun=1;
        if(information[i][2]==isbn){
            cout<<"Book with id "<<isbn<<" and name "<<information[i][1]<<" is issued to user with id : "<<information[i][0]<<"\n";
        }
    }
    if(coun==0) cout<<"Book has not been issued to anyone.\n\n";
}

int main(){
    User temp;
    temp.display_menu();
    return 0;
}
