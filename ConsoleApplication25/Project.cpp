
#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
#include "windows.h"
using namespace std;




int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int SIZE2 = 50;
    int bookSize = 0;

    string SaveBooks = "savedBooks.txt";
    string SaveMagazines = "savedMagazines.txt";
    string SaveNewspapers = "savedNewsPaper.txt";

    Book* library = nullptr; /*= new Book[SIZE2]
    {
        {"The Hidden Kingdom", "Alex Johnson", "Sunset Publishing", "Fantasy"},
        {"Tech Innovations Monthly", "Sara Parker", "Global Media", "Technology"},
        {"Mysterious Oceans", "Lily Adams", "Aqua Books", "Adventure"},
        {"Tales of the Ancient World", "Marcus Green", "History Press", "History"},
        {"Cosmic Explorations", "Nina Cole", "Galaxy Publishing", "Science Fiction"},
        {"Modern Cooking", "Emily Roberts", "Kitchen Chronicles", "Cooking"},
        {"Fitness for All", "James Strong", "Healthy Living", "Fitness"}, 
        {"Art of the Future", "Sophia White", "Creative Minds", "Art"},
        {"Travel the World", "Olivia Walker", "Wanderlust Publications", "Travel"},
        {"Swords of Empire", "Robert Ryan", "Trotting Fox Press", "Fantasy"}
    };*/
    int magazineSize = 0;
    Magazine* magazines = nullptr;/* = new Magazine[SIZE2]
    {
        {"Fashion Weekly", "Emma Stone", "Trendsetters Publishing"},
        {"Tech Today", "Max Harper", "Innovation Press"},
        {"Healthy Living", "Jane Doe", "Wellness Publishing"},
        {"Sports Illustrated", "Michael Lee", "Sports Media"},
        {"Travel Monthly", "Sophia White", "Explorer Publishing"}
    };*/
    int newspaperSize = 0;
    NewsPaper* newspapers= nullptr; /*new NewsPaper[SIZE2]
    {
        {"Daily News Tribune", "Metro Publishing"},
        {"The Global Times", "Global Press"},
        {"Morning Herald", "Sunrise Media"}
    }*/







    // загрузка всього
    loadBooks(library, bookSize,SaveBooks);
    loadMagazines(magazines, magazineSize,SaveMagazines);
    loadNewspapers(newspapers, newspaperSize,SaveNewspapers);
    
    int choiceadd = 0;
    int choice = 1;
    while(choice !=0)
    {

        printMenu();
        cout << "Введіть номер дії: ";
        cin >> choice;
        

        string genre;
        string author, bookName;

        switch (choice) {
        case 1:
            cout << "Що ви хочете додати?\n1 - книга \n2 - газета\n3 - журнал\n0 - вихід і збереження\n";
            cin >> choiceadd;
            switch (choiceadd) {
            case 1:
                addBook(library, bookSize);
                break;
            case 2:
                addNewspaper(newspapers, newspaperSize);
                break;
            case 3:
                addMagazine(magazines, magazineSize);
                break;
            case 0:
                break;
            default:
                cout << "Невірний вибір.\n";
                break;
            }
            break;

        case 2:
            cout << "Books:\n";
            printBooks(library, bookSize);
            cout << "\nMagazines:\n";
            printMagazines(magazines, magazineSize);
            cout << "\nNewspapers:\n";
            printNewsPapers(newspapers, newspaperSize);
            break;

        case 3:
        {
            int choiceSort;
            cout << "Відсортувати :\n1 - книжки\n2 - газети\n3 - журнали" << endl;
            cin >> choiceSort;
            if (choiceSort == 1)
            {
            sortBooks(library, bookSize);
            printBooks(library, bookSize);
            }
            if (choiceSort == 2)
            {
            sortNewspapers(newspapers, newspaperSize);
            printNewsPapers(newspapers, magazineSize);
            }
            if (choiceSort == 3)
            {
            sortMagazines(magazines, magazineSize);
            printMagazines(magazines, magazineSize);              
            }
            break;
        }

        case 4:
        {
            int choiceDelete;
            cout << "Що ви хочете видалити?\n 1 - книгу\n2 - газету\n3 - журнал" << endl;
            cin >> choiceDelete;
            if (choiceDelete == 1)
            {
            deleteBook(library, bookSize);
            }
            if (choiceDelete == 2)
            {
                deleteNewspaper(newspapers, newspaperSize);
            }
            if (choiceDelete == 3)
            {
                deleteMagazine(magazines, magazineSize);
            }
            break;

        }

        case 5:
            cout << "Введіть автора для вибірки: ";
            cin >> author;
            filterBooksByAuthor(library, bookSize, author);
            break;

        case 6: 
            {
            cout << "Введіть категорію для обчислення: ";
            cin >> genre;
            int count1 = countBooksByGenre(library, bookSize, genre);
            cout << "Кількість книг в категорії " << genre << ": " << count1 << endl;
            break;
        }
        case 7:
        {
            deleteNewspaperByAyear(newspapers, newspaperSize);

        }

        case 0:
    cout << "Вихід з програми.\n";
    SaveAllBooks(library, bookSize, SaveBooks);
    SaveAllMagazines(magazines, magazineSize, SaveMagazines);
    SaveAllNewspapers(newspapers, newspaperSize, SaveNewspapers);
    break;

        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
        cout << "Нажміть enter щоб продовжити " << endl;
        cin.get();
    } while (choice != 0);

    delete[] library;
    delete[] magazines;
    delete[] newspapers;


}
