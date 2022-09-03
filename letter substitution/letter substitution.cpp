#include <iostream>
#include <string>
using namespace std;

//Проверка на вводимые символы (only ASCII Code)
bool check(string s) {
    if (s == "") { // отсекаем пустую строку
        return false;
    }
    for (int i = 0; i < s.length(); i++) { // идем по символам и проверяем принадлежность к кодировке
        if (s[i] >= ' ' && s[i] <= '~')
            continue;
        else
            cout << "Unacceptable symbols\n"; return false;

    }
    return true;
}

//Функция замены символов
string Swap(string s) {

    for (int i = 0; i < s.length(); i++) { // идем по символам
        //Ищем символ с начала строки и с конца, если есть совпадение и это не одно и тот же символ, то
        if (s.find((char)tolower(s[i])) != s.rfind((char)tolower(s[i]))) { 
            //пробегаемся по строке и заменяем все похожие символы
            for (int j = i + 1; j < s.length(); j++) {
                if ((char)tolower(s[i]) == (char)tolower(s[j])) {
                    s.replace(j, 1, ")");
                }
                s.replace(i, 1, ")");
            }
        }
        else // если символ один, то заменяем его на другой знак
            s.replace(i, 1, "(");
    }
    return s;
}

int main()
{
    string Slovo; // наша строка
    while (!check(Slovo)) { //проверка ввода
        cout << "Enter a sentence using latin letters and symbols:\n";
        cin >> Slovo;
    }

    Slovo = Swap(Slovo); // замена символов
    cout << "Result:" << Slovo;
}