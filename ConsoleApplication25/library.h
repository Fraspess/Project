#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::to_string;
using std::cout;
using std::swap;
using std::string;
using std::endl;
using std::ofstream;
using std::cin;
using std::getline;
using std::ifstream;
using std::ios_base;



const int SIZE1 = 50;

struct Book
{
    char name[SIZE1]{};
    char author[SIZE1]{};
    char publisher[SIZE1]{};
    char genre[SIZE1]{};
      
       
};


struct Magazine
{
    char name[SIZE1]{};
    char author[SIZE1]{};
    char publisher[SIZE1]{};
};

struct NewsPaper
{
    char name[SIZE1]{};
    char year[SIZE1]{};
    
};




void printBooks(Book* library, const int& size);
void printBook(const Book& book, const string& title);
void printMagazine(const Magazine& magazine, const string& title = "======================================             ==========================================");
void printMagazines(const Magazine* magazine, const int& size, const string& title = "======================================             ==========================================");
void printMenu();
void printNewsPaper(const NewsPaper& newspaper, string title = "==========================             =========================");
void printNewsPapers(const NewsPaper* newspaper, const int& size, const string& title = "===============================         =============================");
void SaveAllBooks(const Book* books, int& bookSize, const string& filename );
void SaveAllMagazines(const Magazine* magazines, int& magazineSize, const string& filename );
void SaveAllNewspapers(const NewsPaper* newspapers, int& newsPaperSize, const string& filename);
void addBook(Book*& library, int& bookSize);
void addMagazine(Magazine*& magazines, int& magazineSize);
void addNewspaper(NewsPaper*& magazines, int& magazineSize);
void loadBooks(Book*& library, int& bookSize, const string& filename);
void loadMagazines(Magazine*& magazines, int& magazinesSize, const string& filename);
void loadNewspapers(NewsPaper*& newspapers, int& newspaperSize, const string& filename);
void sortBooks(Book* library, int bookSize);
void sortMagazines(Magazine* magazines, int magazineSize);
void sortNewspapers(NewsPaper* newspapers, int newspaperSize);
bool findBook(const Book* library, int bookSize, const string& author, const string& name);
bool findMagazine(const Magazine* magazines, int magazineSize, const string& name);
void filterBooksByAuthor(const Book* library, int bookSize, const string& author);
void filterBooksByGenre(const Book* library, int bookSize, const string& genre);
int countBooksByGenre(const Book* library, int bookSize, const string& genre);
void deleteBook(Book* library, int& bookSize);
void deleteMagazine(Magazine* magazines, int& magazineSize);
void deleteNewspaper(NewsPaper* newspapers, int& newspapersSize);
void deleteNewspaperByAyear(NewsPaper* newspapers, int& newspaperSize);





