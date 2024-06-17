#include <iostream>
#include <string>

using namespace std;

void ex1()
{
    cout << "\r\nЗадание 1\r\n";
    
    string text;
    getline (cin, text);
    const string separators{ " ,;:.\"!?'*\n" };
    unsigned count{};
    size_t start { text.find_first_not_of(separators) };

    while (start != string::npos)
    {
        count++;
        size_t end = text.find_first_of(separators, start + 1);
        if (end == string::npos) 
        {
            end = text.length();
        }
        start = text.find_first_not_of(separators, end + 1);
    }
    
    cout << "Ответ: Текст содержит " << count << " сл.\r\n";
}

void ex2()
{
    cout << "\r\nЗадание 2\r\n";

    string people[] {"Tom", "Alice", "Sam", "Bob", "Kate"};
    cout << "Изначальный список имён: Tom, Alice, Sam, Bob, Kate\n";
    cout << "Ответ: ";
    // сортируем по возрастанию
    bool sorted {};
    do
    {
        sorted = true;      // остается true, если строки отсортированы
        string temp;   // переменная для обмена значениями
        for (unsigned i {1}; i < size(people); i++)
        {
            // если предыдущая строка больше последующей
            if (people[i-1] > people[i])
            { 
                // обмениваем значения
                temp = people[i];
                people[i] = people[i-1];
                people[i-1] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
    // вывод строк на консоль
    for (const auto person: people) 
    {
        cout << person << ", ";
    }
    
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Практика 1 | Вариант 8\r\n";
    ex1();
    ex2();
    
    return 0;
}