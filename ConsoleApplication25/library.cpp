#include "library.h"


void printMenu() {
	cout << "Меню:\n";
	cout << "1. Заповнення бази даних\n";
	cout << "2. Перегляд даних про всі джерела\n";
	cout << "3. Сортивування бази даних\n";
	cout << "4. Видалення джерела із бази даних\n";
	cout << "5. Сортування по авторам\n";
	cout << "6. Обчислення\n";
	cout << "7. Видалення газет за рік\n";
	//cout << "9. Корекція\n";
	cout << "0. Вихід\n";
}

void printBook(const Book& book, const string& title = "============================================         =========================================")
{
	cout << title << std::endl;
	cout << "Name :: \t\t " << book.name << endl;
	cout << "Author   :: \t\t" << book.author << endl;
	cout << "Publisher  :: \t\t " << book.publisher << endl;
	cout << "Genre   :: \t\t " << book.genre << endl;
	cout << endl;
}


void printBooks(Book* library, const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		printBook(library[i], "Book #" + to_string(i + 1));
	}
}


void printMagazine(const Magazine& magazine, const string& title)
{
	cout << title << endl;
	cout << "Name :: \t\t" << magazine.name << endl;
	cout << "Author :: \t\t" << magazine.author << endl;
	cout << "Publisher :: \t\t" << magazine.publisher << endl;
	cout << endl;

}


void printMagazines(const Magazine* magazine, const int& size, const string& title)
{
	for (size_t i = 0; i < size; i++)
	{
		printMagazine(magazine[i], "Magazine #" + to_string(i + 1));
	}
}


void printNewsPaper(const NewsPaper& newspaper, string title)
{
	cout << title << endl;
	cout << "Name :: \t\t" << newspaper.name << endl;
	cout << "Year :: \t\t" << newspaper.year << endl;
	cout << endl;
}


void printNewsPapers(const NewsPaper* newspaper, const int& size, const string& title)
{
	for (size_t i = 0; i < size; i++)
	{
		printNewsPaper(newspaper[i], "Newspaper #" + to_string(i + 1));
	}
}

// книжки
void SaveAllBooks(const Book* books, int& bookSize, const string& filename)
{
	ofstream saveFileBooks(filename);
	if (!saveFileBooks.is_open()) {
		cout << "Error opening file!" << endl;
	}


	for (size_t i = 0; i < bookSize; i++)
	{
		saveFileBooks.write((char*)&books[i], sizeof(Book));
	}
	saveFileBooks.close();


}


// журнали
void SaveAllMagazines(const Magazine* magazines, int& magazineSize, const string& filename)
{
	ofstream saveFileMagazines(filename);
	if (!saveFileMagazines.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}


	//saveFileMagazines << magazineSize << "\n";

	for (size_t i = 0; i < magazineSize; i++)
	{
		saveFileMagazines.write((char*)&magazines[i], sizeof(Magazine));
	}

	saveFileMagazines.close();
}

// газети
void SaveAllNewspapers(const NewsPaper* newspapers, int& newspaperSize, const string& filename)
{
	ofstream saveFileNewspapers(filename);
	if (!saveFileNewspapers.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}


	//saveFileNewspapers << newspaperSize << "\n";

	for (size_t i = 0; i < newspaperSize; i++)
	{
		saveFileNewspapers.write((char*)&newspapers[i], sizeof(NewsPaper));

	}

	saveFileNewspapers.close();
}


void addBook(Book*& books, int& bookSize)
{
	if (bookSize % 10 == 0) {
		Book* newLibrary = new Book[bookSize + 10];
		for (int i = 0; i < bookSize; i++) {
			newLibrary[i] = books[i];
		}
		delete[] books;
		books = newLibrary;
	}
	Book newBook;
	cout << "Введіть назву книжки: ";
	cin.ignore();
	cin.getline(newBook.name, SIZE1);
	cout << "Введіть автора ::  ";
	cin.getline(newBook.author, SIZE1);
	cout << "Введіть видавництво ::  ";
	cin.getline(newBook.publisher, SIZE1);
	cout << "Введіть жанр ::  ";
	cin.getline(newBook.genre, SIZE1);

	books[bookSize] = newBook;
	bookSize++;
}


void addMagazine(Magazine*& magazines, int& magazineSize)
{
	if (magazineSize % 5 == 0) {
		Magazine* newLibrary = new Magazine[magazineSize + 10];
		for (int i = 0; i < magazineSize; i++) {
			newLibrary[i] = magazines[i];
		}
		delete[] magazines;
		magazines = newLibrary;
	}
	Magazine newMagazine;
	cout << "Введіть назву журнала ::  ";
	cin.ignore();
	cin.getline(newMagazine.name, SIZE1);
	cout << "Введіть автора ::  ";
	cin.getline(newMagazine.author, SIZE1);
	cout << "Введіть видавництво ::  ";
	cin.getline(newMagazine.publisher, SIZE1);

	magazines[magazineSize] = newMagazine;
	magazineSize++;
}

void addNewspaper(NewsPaper*& newspapers, int& newspaperSize)
{
	NewsPaper* newLibrary = new NewsPaper[newspaperSize + 1];

	for (int i = 0; i < newspaperSize; i++)
	{
		newLibrary[i] = newspapers[i];
	}
	delete[] newspapers;
	newspapers = newLibrary;
	NewsPaper newNewspaper;
	cin.ignore();
	cout << "Введіть назву газети ::  ";
	cin.getline(newNewspaper.name, SIZE1);
	cout << "Введіть рік газети ::  ";
	cin.getline(newNewspaper.year, SIZE1);

	newspapers[newspaperSize] = newNewspaper;
	newspaperSize++;
}






void loadBooks(Book*& library, int& bookSize, const string& filename)
{

	ifstream loadFileBooks(filename);
	if (!loadFileBooks.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	if (library != nullptr) {

		delete[] library;
		library = nullptr;
	}
	bookSize = 0;

	loadFileBooks.seekg(0, ios_base::end);
	if (loadFileBooks.tellg() == 0)
		return;

	bookSize = loadFileBooks.tellg() / sizeof(Book);
	loadFileBooks.seekg(0);

	

	library = new Book[bookSize];

	for (size_t i = 0; i < bookSize; i++)
	{
		loadFileBooks.read((char*)&library[i], sizeof(Book));
	}

	loadFileBooks.close();
	cout << "Books loaded: " << bookSize << endl;
}

void loadMagazines(Magazine*& magazines, int& magazineSize, const string& filename) {
	ifstream loadFileMagazines(filename);
	if (!loadFileMagazines.is_open()) {
		cout << "Error opening file!" << endl;
		return;
	}
	if (magazines != nullptr)
	{
	delete[] magazines;
	magazines = nullptr;
	}
	magazineSize = 0;

	loadFileMagazines.seekg(0, ios_base::end);
	if (loadFileMagazines.tellg() == 0)
		return;

	magazineSize = loadFileMagazines.tellg() / sizeof(Magazine);
	loadFileMagazines.seekg(0);

	magazines = new Magazine[magazineSize];
	for (size_t i = 0; i < magazineSize; i++)
	{
	loadFileMagazines.read((char*)&magazines[i], sizeof(Magazine));
	}

	loadFileMagazines.close();
	cout << "Magazines loaded: " << magazineSize << endl;
}


void loadNewspapers(NewsPaper*& newspapers, int& newspaperSize, const string& filename)
{
	ifstream loadFileNewspapers(filename);
	if (!loadFileNewspapers.is_open()) {
		cout << "Error opening file!" << endl;
		return;
	}
	if (newspapers != nullptr)
	{
	delete[] newspapers;
	newspapers = nullptr;
	}
	newspaperSize = 0;

	loadFileNewspapers.seekg(0, ios_base::end);
	if (loadFileNewspapers.tellg() == 0)
		return;

	newspaperSize = loadFileNewspapers.tellg() / sizeof(NewsPaper);
	loadFileNewspapers.seekg(0);

	loadFileNewspapers.clear();

	newspapers = new NewsPaper[newspaperSize];

	for (size_t i = 0; i < newspaperSize; i++)
	{
		loadFileNewspapers.read((char*)&newspapers[i], sizeof(NewsPaper));
	}

	loadFileNewspapers.close();
	cout << "Newspapers loaded: " << newspaperSize << endl;
}





void sortBooks(Book* library, int bookSize)
{
	for (int i = 0; i < bookSize - 1; i++) {
		for (int j = 0; j < bookSize - i - 1; j++) {
			if (strcmp(library[j].name, library[j + 1].name) > 0) 
			{
				Book temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}


void sortMagazines(Magazine* magazines, int magazineSize) {
	for (int i = 0; i < magazineSize - 1; i++) {
		for (int j = 0; j < magazineSize - i - 1; j++) {
			if (strcmp(magazines[j].name, magazines[j + 1].name) > 0)
			{
				Magazine temp = magazines[j];
				magazines[j] = magazines[j + 1];
				magazines[j + 1] = temp;
			}
		}
	}
}


void sortNewspapers(NewsPaper* newspapers, int newspaperSize) {
	for (int i = 0; i < newspaperSize - 1; i++) {
		for (int j = 0; j < newspaperSize - i - 1; j++) {
			if (strcmp(newspapers[j].name, newspapers[j + 1].name) > 0)
			{
				NewsPaper temp = newspapers[j];
				newspapers[j] = newspapers[j + 1];
				newspapers[j + 1] = temp;
			}
		}
	}
}

bool findBook(const Book* library, int bookSize, const string& author, const string& name)
{
	for (int i = 0; i < bookSize; i++) {
		if (library[i].author == author && library[i].name == name) {
			return true;
		}
	}
	return false;
}

bool findMagazine(const Magazine* magazines, int magazineSize, const string& name)
{
	for (int i = 0; i < magazineSize; i++) {
		if (magazines[i].name == name) {
			return true;
		}
	}
	return false;
}

void filterBooksByAuthor(const Book* library, int bookSize, const string& author)
{
	for (int i = 0; i < bookSize; i++) {
		if (library[i].author == author) {
			printBook(library[i]);
		}
	}
}


void filterBooksByGenre(const Book* library, int bookSize, const string& genre)
{
	for (int i = 0; i < bookSize; i++) {
		if (library[i].genre == genre) {
			printBook(library[i]);
		}
	}
}

int countBooksByGenre(const Book* library, int bookSize, const string& genre)
{
	int count = 0;
	for (int i = 0; i < bookSize; i++) {
		if (library[i].genre == genre) {
			count++;
		}
	}
	return count;
}

void deleteBook(Book* library, int& bookSize)
{
	char bookName[SIZE1];
	cout << "Введіть назву книги для видалення: ";
	cin.ignore(); 
	cin.getline(bookName, SIZE1);

	for (int i = 0; i < bookSize; i++) {
		if (strcmp(library[i].name, bookName) == 0) {
			for (int j = i; j < bookSize - 1; j++) {
				library[j] = library[j + 1];
			}
			bookSize--; 
			cout << "Книга '" << bookName << "' була видалена." << endl;
			return;
		}
	}
	cout << "Книга з назвою '" << bookName << "' не знайдена." << endl;
}
void deleteMagazine(Magazine* magazines, int& magazineSize)
{
	char MagazineName[SIZE1];
	cout << "Введіть назву журналу для видалення: ";
	cin.ignore(); 
	cin.getline(MagazineName, SIZE1);

	for (int i = 0; i < magazineSize; i++) {
		if (strcmp(magazines[i].name, MagazineName) == 0) 
		{
			for (int j = i; j < magazineSize - 1; j++) 
			{
				magazines[j] = magazines[j + 1];
			}
			magazineSize--; 
			cout << "Журнал '" << MagazineName << "' була видалена." << endl;
			return;
		}
	}
	cout << "Журнал з назвою '" << MagazineName << "' не знайдена." << endl;
}
void deleteNewspaper(NewsPaper* newspapers, int& newspapersSize)
{
	char NewspaperName[SIZE1];
	cout << "Введіть назву газети для видалення: ";
	cin.ignore(); 
	cin.getline(NewspaperName, SIZE1);

	for (int i = 0; i < newspapersSize; i++) {
		if (strcmp(newspapers[i].name, NewspaperName) == 0) 
		{
			for (int j = i; j < newspapersSize - 1; j++)
			{
				newspapers[j] = newspapers[j + 1];
			}
			newspapersSize--; 
			cout << "Газета '" << NewspaperName << "' була видалена." << endl;
			return;
		}
	}
	cout << "Газета з назвою '" << NewspaperName << "' не знайдена." << endl;
}



void deleteNewspaperByAyear(NewsPaper* newspapers, int& newspaperSize) {
	char newspaperYear[SIZE1];
	cout << "Введіть рік газети для видалення :: " << endl;
	cin.ignore();
	cin.getline(newspaperYear, SIZE1);

	bool found = false; 
	for (size_t i = 0; i < newspaperSize; i++)
	{
		if (strcmp(newspapers[i].year, newspaperYear) == 0)
		{
			found = true; 

			for (size_t j = i; j < newspaperSize - 1; j++) 
			{
				newspapers[j] = newspapers[j + 1];
			}
			newspaperSize--; 
			i--;
		}
	}

	if (found) {
		cout << "Газети " << newspaperYear << " були видалені" << endl;
	}
	else {
		cout << "Газети " << newspaperYear << " не знайдені" << endl;
	}
}












