#include <iostream>
#include <string>
#include <optional>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Person{
public:
    string m_surname;
    string m_name;
    optional <string> m_father;

    bool operator<(const Person& rhs){
        return tie(m_surname, m_name, m_father) < (rhs.m_surname, rhs.m_name, rhs.m_father);
    }

    bool operator==(const Person& rhs){
        return tie(m_surname, m_name, m_father) == (rhs.m_surname, rhs.m_name, rhs.m_father);

    }

    friend ostream& operator<<(ostream& ostOut, const Person& Current){
        ostOut << Current.m_surname << " " << Current.m_name << " ";
        if (Current.m_father)
            ostOut << *Current.m_father << " ";
        return ostOut;
    }
};

struct PhoneNumber{
    int m_country;
    int m_city;
    string m_number;
    optional <int> m_addition;

    bool operator<(const PhoneNumber& rhs){
        return tie(m_country, m_city, m_number, m_addition) < (rhs.m_country, rhs.m_city, rhs.m_number, rhs.m_addition);
    }
    friend ostream& operator<<(ostream& ostOut, const PhoneNumber& current){
        ostOut << "+" << current.m_country << " ( " << current.m_city << " ) " << current.m_number << " ";
        if (current.m_addition)
            ostOut << *current.m_addition;
        return ostOut;
    }
};
class PhoneBook {
    if (file.is_open()){
        pair<Person, PhoneNumber> m_pair;

        while (!file.eof()) {
            getline(file, m_surname, ' ');
            getline(file, m_name, ' ');
            getline(file, m_father, ' ');

            if (m_father == "-")
                father = nullopt;
            else
                father = m_father;

            m_pair.first = Person(m_surname, m_name, father);

            getline(file, m_country, '(');
            getline(file, m_city, ')');
            getline(file, m_number, ' ');
            getline(file, m_addition, '\n');

            if (m_addition == "-")
                addition = nullopt;
            else
                addition = m_addition;

            m_pair.second = PhoneNumber(m_country, m_city, m_number, addition)

            PhoneBook.push_back(m_pair);
        }
    }
};
    void SortByName(){
        sort(PhoneBook.begin(), PhoneBook.end(), [](const auto& rhs, const auto& lhs))
        return tie (lhs.surname, lhs.name, lhs.father) < (rhs.surname, rhs.name, rhs.father);
    };

    void SortByPhone(){
        sort(PhoneBook.begin(), PhoneBook.end(), [](const auto& rhs, const auto& lhs))
        return tie (lhs.country, lhs.city, lhs.number, lhs.addition) < (rhs.country, rhs.city, rhs.number, rhs.addition);
    };
};
int main() {
    ifstream file("../PhoneBook.txt");
    PhoneBook book (file);
    cout << book;
    book.SortByPhone();
    cout << book;
    book.SortByName();
    cout << book;
    return 0;
}
