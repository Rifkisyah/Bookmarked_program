#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

int size_title_book = 1;

void welcome_to_bookmark();
void Menu_bookmark();
void input_book();
void show_book(int size_book);
int Delete_book();
int sum_of_book();
void update_size_book();

int main()
{
    Menu_bookmark();
}

void welcome_to_bookmark()
{
    std::cout << "=============================\n" << "WELCOME TO BOOKMARK\n" << "=============================" << "\n\n ";
}

void Menu_bookmark()
{
    if (size_title_book == 0) {
        show_book(sum_of_book());
        input_book();
        system("cls");
    }

    show_book(sum_of_book());
    input_book();

    system("cls");
    Menu_bookmark();
}


void input_book()
{
    std::string input;

    std::cout << "\nInput Book Here : ";
    std::getline(std::cin, input);

    std::ofstream file_input("data.csv", std::ios::app);
    file_input << input << "\n";
    size_title_book += 1;
    file_input.close();

    if (Delete_book()){
        size_title_book = 0;
        update_size_book();   
    }
    
}


void show_book(int size_book)
{
    welcome_to_bookmark();
    std::string title;
    if(size_book == 1){
        std::cout << "Book Not Found\n\n";
    }
    

    if(size_book > 1){
        std::cout << "Book Added : \n";
        std::ifstream file_title("data.csv", std::ios::in);

        int i = 1;
        if(file_title.is_open()){
            while(std::getline(file_title, title)){
                std::istringstream ss(title);
                std::string data;
        
                while(std::getline(ss, data)){
                    std::cout << i << "). " << data;
                }
            i += 1;
            std::cout << "\n";
            }
        }else{
        std::cout << "Failed to access book";
        }
        file_title.close();
    }
}

int Delete_book()
{
    std::string option_delete;
    std::cout << "Delete book (Y/N) : ";
    std::getline(std::cin, option_delete);

    if(option_delete == "Y" || option_delete == "y"){
        system("cls");
        
        std::string deleted_title;
        std::ofstream file_deleted("data.csv", std::ios::trunc);
        file_deleted << deleted_title;
        std::cout << "Book Not Found\n\n";

    }else if(option_delete == "N" || option_delete == "n"){
        system("cls");
        show_book(size_title_book);

        return 0;
    }else{
        std::cerr << "invalid input !";
        sleep(2);
        system("cls");
        show_book(size_title_book);

        return 0;
    }
}

int sum_of_book()
{
    std::ofstream file_size_title("size_title_book.csv", std::ios::app);
    if (file_size_title.is_open()) {
        file_size_title << size_title_book << "\n";
        file_size_title.close();
    }

    return size_title_book;
}

void update_size_book()
{
    std::ofstream file_size_title_out("size_title_book.csv", std::ios::trunc);
    file_size_title_out << size_title_book;
}