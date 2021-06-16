#include<iostream>
#include<string>
#include<cstring>
#include<Windows.h>
using namespace std;

//create structure
struct Book
{
	char book_title[100];
	char name_autor[100];
	char book_publishing[100];
	char gener_book[100];
};

void EditeBook(Book *library);
void ShowBook(Book *library, int SIZE);
void FindBook(Book *library, int SIZE);
void SortBookTitle(Book library[], int SIZE);// як параметри можна використовувати і Book *library, і Book library[]
void SortBookAuthors(Book library[], int SIZE);
void SortBookPublishing(Book library[], int SIZE);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int SIZE = 10;
	Book library[SIZE] //initialization an array of structures 
	{
		{"Чорна рада","Пантелеймон Куліш","ПРОСВІТА","Історична повість"},
		{"Чорний ворон","Василь Шкляр","ПРОМІНЬ","Історична драма"},
		{"Брама Європи","Сергій Плохій","Клуб СД","Історія"},
		{"Ялта.Ціна миру","Сергій Плохій","Клуб СД","Історія"},
		{"Стів Джобс","Волтер Айзексон","Київ","Біографія"},
		{"Мистецтво забивати","Марк Менсон","Клуб СД","Психологія"},
		{"Енеїда","Іван Котляревський","ПРОСВІТА","Поема"},
		{"Хмельниччина","Пантелеймон Куліш","ПРОСВІТА","Історична повість"},
		{"Украдене щастя","Іван Франко","ПРОМІНЬ","Психологічна драма"},
		{"Ключ","Василь Шкляр","ПРОСВІТА","Роман"}
	};
	cout << "\t\t\tL I B R A R Y" << endl;
	
	char exit;
	do
	{
		//MENU
		cout << "Select an option:" << endl;
		cout << "Press 1 - if you want to edite a book." << endl;
		cout << "Press 2 - if you want to printe books." << endl;
		cout << "Press 3 - if you want to find a book." << endl;
		cout << "Press 4 - if you want to sort the books by title." << endl;
		cout << "Press 5 - if you want to sort the books by authors" << endl;
		cout << "Press 6 - if you want to sort the books by publishing house." << endl;
		cout << "Press 0 - if you want exit." << endl;
		char option;
		cin >> option;
		switch (option)
		{
		case '1':
			EditeBook(library);
			break;
		case '2':
			ShowBook(library,SIZE);
			break;
		case '3':
			FindBook(library, SIZE);
			break;
		case '4':
			SortBookTitle(library,SIZE);
			break;
		case'5':
			SortBookAuthors(library, SIZE);
			break;
		case'6':
			SortBookPublishing(library, SIZE);
			break;
		}
		cout << "Do you want to continue? т/н\n";
		cin >> exit;
	} while (exit != 'н');

	system("pause");
	return 0;
}


void EditeBook(Book *library)
{
	int temp;
	char corect;
	char symbol[100];
	char newsymbol[100];
	
	cout << "Press 1 - if you want to edite the title of the book." << endl;
	cout << "Press 2 - if you want to edite the autor`s name." << endl;
	cout << "Press 3 - if you want to edite the publesher`s name." << endl;
	cout << "Press 4 - if you want to edite the gener name." << endl;
	cin >> corect;
	cout << "Enter the number section you want to edite: "; cin >> temp;

	switch (corect)
	{
	case '1':

		cout << "Enter the title of the book  you want to edite:" << endl;
		cin.get();
		cin.get(symbol, 100).get();

		cout << "Enter the new title of the book:" << endl;
		cin.get(newsymbol, 100).get();

		strcpy_s(library[temp - 1].book_title, newsymbol);
		break;

	case '2':

		cout << "Enter the autor`s name you want to edite:" << endl;
		cin.get();
		cin.get(symbol, 100).get();
		cout << "Enter the new autor`s name:" << endl;
		cin.get(newsymbol, 100).get();
		strcpy_s(library[temp - 1].name_autor, newsymbol);
		break;

	case '3':

		cout << "Enter the publesher`s name you want to edite:" << endl;
		cin.get();
		cin.get(symbol, 100).get();
		cout << "Enter the new publesher`s name:" << endl;
		cin.get(newsymbol, 100).get();
		strcpy_s(library[temp - 1].book_publishing, newsymbol);
		break;

	case '4':

		cout << "Enter the gener name you want to edite:" << endl;
		cin.get();
		cin.get(symbol, 100).get();
		cout << "Enter the new gener name:" << endl;
		cin.get(newsymbol, 100).get();
		strcpy_s(library[temp - 1].gener_book, newsymbol);
		break;
	}
}

void ShowBook(Book* library, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ". Назва книги: " << library[i].book_title << endl;
		cout << "   Автор: " << library[i].name_autor << endl;
		cout << "   Видавництво: " << library[i].book_publishing << endl;
		cout << "   Жанр: " << library[i].gener_book << endl;
	}
}

void FindBook(Book *library, int SIZE)
{
	string symbol1;
	
	cout << "Press 1 - if you want to find the autorh." << endl;
	cout << "Press 2 - if you want to find the book title." << endl;
	cout << "Press 3 - if you want to find the publishing house." << endl;
	cout << "Press 4 - if you want to find the book gener." << endl;
	char option;
	cin >> option;
	
	switch (option)
	{
	case '1':

		cout << "Enter the autor`s name:" << endl;
		cin.get();
		getline(cin, symbol1);
		
		for (int i = 0; i < SIZE; i++)
		{
			if (library[i].name_autor == symbol1)
				cout <<"Автор: "<< library[i].name_autor << "\n" <<"Назва книги: "<< library[i].book_title << "\n"
				<< "Видавництво: "<< library[i].book_publishing << "\n" <<"Жанр: "<< library[i].gener_book << endl;
		}
		break;

	case '2':

		cout << "Enter the book title:" << endl;
		cin.get();
		getline(cin, symbol1);
		for (int i = 0; i < SIZE; i++)
		{
			if (library[i].book_title == symbol1)
				cout << "Назва книги: " << library[i].book_title << "\n" << "Автор: " << library[i].name_autor << "\n"
				<< "Видавництво: " << library[i].book_publishing << "\n" << "Жанр: " << library[i].gener_book << endl;
		}
		break;

	case '3':

		cout << "Enter the publishing house:" << endl;
		cin.get();
		getline(cin, symbol1);
		for (int i = 0; i < SIZE; i++)
		{
			if(library[i].book_publishing==symbol1)
				cout << "Видавництво: " << library[i].book_publishing << "\n" << "Назва книги: " << library[i].book_title << "\n"
				<< "Автор: " << library[i].name_autor << "\n" << "Жанр: " << library[i].gener_book << endl;
		}
		break;

	case '4':

		cout << "Enter the book gener:" << endl;
		cin.get();
		getline(cin, symbol1);
		for (int i = 0; i < SIZE; i++)
		{
			if (library[i].gener_book == symbol1)
				cout << "Жанр: " << library[i].gener_book << "\n" << "Назва книги: " << library[i].book_title << "\n"
				<< "Автор: " << library[i].name_autor << "\n" << "Жанр: " << library[i].book_publishing << endl;
		}
		break;
	}
	
}


void SortBookTitle(Book library[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (library[j].book_title > library[i].book_title)
			{
				Book temp = library[j];
				library[j] = library[i];
				library[i] = temp;
			}
		}
		cout << library[i].book_title << endl;
	}
	
	
}

void SortBookAuthors(Book library[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (library[j].name_autor > library[i].name_autor)
			{
				swap(library[j], library[i]);
			}
		}
		cout << library[i].name_autor << endl;
	}
}

void SortBookPublishing(Book library[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (library[j].book_publishing > library[i].book_publishing)
			{
				Book temp = library[j];
				library[j] = library[i];
				library[i] = temp;
			}
		}
		cout << library[i].book_publishing << endl;
	}
}
