#include "Word.h"

//функция чтения слов из файла
map<string, string> readfile(string &FileName) {
	map<string, string> rus_eng;

	std::ifstream fin(FileName, std::ios_base::in);
	string buff_word;
	if (!fin.is_open())
	{
		fin.close();
		cout << "\x1b[1;31;47mОШИБКА - ФАЙЛ НЕ ОТКРЫТ!!!\x1b[0;32;4m\n";
		rus_eng = { {"0", "0"} };
		return rus_eng;
	}
	else {
		while (fin >> buff_word)
		{
			string name_key = buff_word;
			fin >> buff_word;
			rus_eng[name_key] = buff_word;
		}
		fin.close();
		return rus_eng;
	}
} 


//функция записи в файл
void writefile(string &FileName, map<string, string> &wordbook)
{
	std::ofstream fout(FileName, std::ios_base::app);
	fout << endl;
	for (auto const& elem: wordbook)
	{
		fout << elem.first << " " << elem.second << endl;

	}
	fout.close();
}

//функция обнуления файла 
void writefile_nul(string &FileName)
{
	std::ofstream fout(FileName, std::ios_base::out | std::ios_base::trunc);
	fout << endl;
	for (auto const& elem : words)
	{
		fout << elem.first << " " << elem.second << endl;
	}
	fout.close();
}
//функция сравнения слов
bool checkword(string rus, string eng) {
	return (rus == eng);
}

//перевод строки в строку из прописных букв
void uppercase_string(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

//проверка ввод неотрицательного целого числа
int check()
{
	int input_user = 0;

	while (true)
	{
		std::cin >> input_user;

		if (std::cin.fail() || input_user < 0)
		{
			std::cout << "\x1b[1;31mError Type!!!" << std::endl;
			//сбрасываем флаг ошибки
			std::cin.clear();

			//очищаем буфер обмена ввода
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите целое положительное число!!!\x1b[0;32m -> ";

			//пропуск данной итерации
			continue;
		}

		if (input_user >= 0)
		{
			return input_user;
		}
	}
}

void interface_menu() {
	cout << "\x1b[0;32;47m#####################################################\n"
		<< "#                                                   #\n"
		<< "#                                                   #\n"
		<< "#\x1b[5;31;47mПОМОЩНИК В ЗАУЧИВАНИИ (АНГЛИЙСКИХ) СЛОВ НАИЗУСТЬ!!!\x1b[0;32;47m#\n"
		<< "#  \x1b[1;35;47mСоздатель: https://t.me/channel_A111\x1b[0;32;47m             #\n"
		<< "#                                                   #\n"
		<< "#####################################################\x1b[0;37;40m\n";

	cout << "\x1b[0;32;47m#############################################################\n"
		<< "#  \x1b[0;31;47mДоступные функции:\x1b[0;32;47m                                       #\n"
		<< "#       \x1b[0;31;47m1) Запись слов;\x1b[0;32;47m                                     #\n"
		<< "#       \x1b[0;31;47m2) Вывод списка слов;\x1b[0;32;47m                               #\n"
		<< "#       \x1b[0;31;47m3) Проверка на знание слов (EN -> RU);\x1b[0;32;47m              #\n"
		<< "#       \x1b[0;31;47m4) Проверка на знание слов (RU -> EN);\x1b[0;32;47m              #\n"
		<< "#       \x1b[0;31;47m5) Сброс к списку слов по умолчанию (безвозвратный)\x1b[0;32;47m #\n"
		<< "#############################################################\x1b[0;37;40m\n";
}

//интерфейс
void interface_programm()
{
	while (true) {
		string file_name = "RU_EN.txt";
		interface_menu();
		cout << "\x1b[0;32mВвод: ";
		string user_output;
		cout << "\x1b[0;33m";
		std::getline(cin, user_output);
		cout << "\x1b[0;32m";

		uppercase_string(user_output);


		cout << "Предполагаемый ввод: \x1b[0;31m\"" << user_output << "\"\n\x1b[0;32m";

		if (user_output == "1")
		{
			map<string, string> ru_en;
			while (true) {
				cout << "\x1b[0;32mВведите русское слово (\x1b[0;31mвыйти - \"выход\"\x1b[0;32m): \x1b[0;33m";
				string word_ru;
				cin >> word_ru;
				uppercase_string(word_ru);
				cout << "\x1b[0;32mПредполагаемый ввод: \x1b[0;31m\"" << word_ru << "\"\n\x1b[0;32m";
				if (word_ru == "выход")
				{
					cout << "\x1b[0;31mВыход - успешно!!!\x1b[0;32m" << endl;
					writefile(file_name, ru_en);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
					break;
				}

				cout << "\x1b[0;32mВведите английское слово (\x1b[0;31mвыйти - \"выход\"\x1b[0;32m): \x1b[0;33m";
				string word_en;
				cin >> word_en;
				uppercase_string(word_en);
				cout << "\x1b[0;32mПредполагаемый ввод: \x1b[0;31m\"" << word_en << "\"\n\x1b[0;32m";
				if (word_en == "выход")
				{
					cout << "\x1b[0;31mВыход - успешно!!!\x1b[0;32m" << endl;
					writefile(file_name, ru_en);
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
					break;
				}
				ru_en[word_ru] = word_en;
			}
			continue;
		}
		if (user_output == "2")
		{
			map<string, string> ru_en = readfile(file_name);
			int counter = 0;
			for (auto& elem : ru_en)
			{
				cout << "\x1b[0;33m" << elem.first << "\x1b[0;31m --> \x1b[0;32m" << elem.second << endl;
				counter+=1;
			}
			cout << "\n\x1b[0;33mКоличество слов в списке: \x1b[0;34m" << counter << "\x1b[0;32m" << endl << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (user_output == "3")
		{
			map<string, string> ru_en = readfile(file_name);
			int y1 = 0;
			int y2 = 0;
			short number_attempts = 0;

			cout << "\x1b[0;32mВведите диапазон слов (от \x1b[0;33m1\x1b[0;32m до \x1b[0;33m" << ru_en.size() << "\x1b[0;32m): \n\t\tот -> \x1b[0;33m";
			y1 = check() - 1;
			cout << "\x1b[0;32m\t\tдо -> \x1b[0;33m";
			y2 = check() - 1;
			cout << "\x1b[0;32m\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (y2 >= ru_en.size() || y2 < 0)
			{
				y2 = static_cast<int>(ru_en.size() - 1);
			}
			if (y1 >= ru_en.size() || y1 < 0)
			{
				y1 = 0;
			}

			cout << "\x1b[0;32mДиапазон от \x1b[0;33m" << y1+1 << "\x1b[0;32m до \x1b[0;33m" << y2+1 << endl;

			start_3:
			int limit = 0;
			int counter = 0;
			int number = 0;
			for (const auto& elem : ru_en)
			{

				if (limit >= y1 && limit <= y2)
				{
					number += 1;
					cout << "\x1b[0;32m" << elem.second << "\x1b[0;34m --введите перевод \x1b[0;31m(выйти -> \"выход_из\")\x1b[0;34m--> \x1b[0;33m";
					string user_answer;
					cin >> user_answer;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					uppercase_string(user_answer);

					if (user_answer == "выход_из")
					{
						cout << "\x1b[0;31mВыход - успешно!!!\x1b[0;32m" << endl;
						system("pause");
						system("cls");
						break;
					}

					if (user_answer == elem.first)
					{
						cout << "\t\x1b[0;32mВерно! (+1)" << endl;
						counter += 1;
					}
					else
					{
						cout << "\t\x1b[0;31mНеверно! (верно -> \x1b[0;33m" << elem.first << "\x1b[0;31m)\x1b[0;32m" << endl;
					}
					if (limit == y2)
					{
						number_attempts += 1;
						cout << "\n\x1b[0;35mРезультат (попытка \x1b[0;32m№" << number_attempts << "\x1b[0;35m): \x1b[0;33m" << counter << "\x1b[0;35m/\x1b[0;33m" << number << "\x1b[0;32m\n\n";
						cout << "------------------------------------------------------\n";
						goto start_3;
					}
				}
				limit += 1;
			}
			continue;
		}
		if (user_output == "4")
		{
			map<string, string> ru_en = readfile(file_name);
			int y1 = 0;
			int y2 = 0;
			short number_attempts = 0;

			cout << "\x1b[0;32mВведите диапазон слов (от \x1b[0;33m1\x1b[0;32m до \x1b[0;33m" << ru_en.size() << "\x1b[0;32m): \n\t\tот -> \x1b[0;33m";
			y1 = check() - 1;
			cout << "\x1b[0;32m\t\tдо -> \x1b[0;33m";
			y2 = check() - 1;
			cout << "\x1b[0;32m\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (y2 >= ru_en.size() || y2 < 0)
			{
				y2 = static_cast<int>(ru_en.size() - 1);
			}
			if (y1 >= ru_en.size() || y1 < 0)
			{
				y1 = 0;
			}

			cout << "\x1b[0;32mДиапазон от \x1b[0;33m" << y1 + 1 << "\x1b[0;32m до \x1b[0;33m" << y2 + 1 << endl;

		start_4:
			int limit = 0;
			int counter = 0;
			int number = 0;
			for (const auto& elem : ru_en)
			{

				if (limit >= y1 && limit <= y2)
				{
					number += 1;
					cout << "\x1b[0;32m" << elem.first << "\x1b[0;34m --введите перевод \x1b[0;31m(выйти -> \"выход_из\")\x1b[0;34m--> \x1b[0;33m";
					string user_answer;
					cin >> user_answer;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					uppercase_string(user_answer);

					if (user_answer == "выход_из")
					{
						cout << "\x1b[0;31mВыход - успешно!!!\x1b[0;32m" << endl;
						system("pause");
						system("cls");
						break;
					}

					if (user_answer == elem.second)
					{
						cout << "\t\x1b[0;32mВерно! (+1)" << endl;
						counter += 1;
					}
					else
					{
						cout << "\t\x1b[0;31mНеверно! (верно -> \x1b[0;33m" << elem.second << "\x1b[0;31m)\x1b[0;32m" << endl;
					}
					if (limit == y2)
					{
						number_attempts += 1;
						cout << "\n\x1b[0;35mРезультат (попытка \x1b[0;32m№" << number_attempts << "\x1b[0;35m): \x1b[0;33m" << counter << "\x1b[0;35m/\x1b[0;33m" << number << "\x1b[0;32m\n\n";
						cout << "------------------------------------------------------\n";
						goto start_4;
					}
				}
				limit += 1;
			}
			continue;
		}
		if (user_output == "5")
		{
			writefile_nul(file_name);
			cout << "\x1b[0;32;40mУспешно!\n";
			system("pause");
			system("cls");
			continue;
		}
			cout << "\x1b[1;31;47mНЕВЕРНЫЙ ВВОД!!!\x1b[0;32;40m\n";
			system("pause");
			system("cls");
	}
}


int main() {
	SetConsoleTitleW(L"CheKnowAnglish");
	setlocale(LC_ALL, "Russian");
	system("chcp 1251>nul");
	interface_programm();

	return 0;
}
