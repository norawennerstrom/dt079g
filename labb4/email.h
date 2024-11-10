//
// Created by Nora Wennerström on 2024-09-02.
//

#ifndef LABB4_EMAIL_H
#define LABB4_EMAIL_H
#include <string>
#include <vector>
#include <iostream>

/*----------- email -------------*/

struct comp_who_date_subject;
struct comp_date_who_subject;
struct comp_subject_who_date;

class email {
public:
    explicit email(std::string who = "", std::string date = "", std::string subject = "");//construct

    friend std::ostream& operator<<(std::ostream& os, const email& rhs);//<<overload

    friend comp_who_date_subject;
    friend comp_date_who_subject;
    friend comp_subject_who_date;

private:
    std::string who;
    std::string date; // åååå-mm-dd
    std::string subject;
};

// 3 comp friend structs
struct comp_who_date_subject {
    bool operator()(const email& lhs, const email& rhs) const;
};

struct comp_date_who_subject {
    bool operator()(const email& lhs, const email& rhs) const;
};

struct comp_subject_who_date {
    bool operator()(const email& lhs, const email& rhs) const;
};

// overloaded friend <<
std::ostream& operator<<(std::ostream& os, const email& rhs);

/*----------- mail_box -------------*/

class mail_box {
public:
    explicit mail_box(size_t size = 0);

    size_t size() { return emails.size(); }

    std::vector<email>::iterator begin() { return emails.begin(); }
    std::vector<email>::iterator end() { return emails.end(); }

    void add_email(const email& new_email);

    void sort_who();
    void sort_date();
    void sort_subject();
private:
    std::vector<email> emails;
};

// global function template show
template<class T>
void show(T mail_box) {
    for(auto& email : mail_box) {
        std::cout << email << '\n';
    }
}


#endif //LABB4_EMAIL_H
