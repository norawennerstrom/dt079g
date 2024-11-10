//
// Created by Nora Wennerström on 2024-09-02.
//

#include "email.h"

/*----------- email -------------*/

email::email(std::string who, std::string date, std::string subject):
who(std::move(who)), date(std::move(date)), subject(std::move(subject)) {

}

bool comp_who_date_subject::operator()(const email &lhs, const email &rhs) const {
    if(lhs.who != rhs.who) return lhs.who < rhs.who;
    if(lhs.date != rhs.date) return lhs.date < rhs.date;
    return lhs.subject < rhs.subject;
}

bool comp_date_who_subject::operator()(const email &lhs, const email &rhs) const {
    if(lhs.date != rhs.date) return lhs.date < rhs.date;
    if(lhs.who != rhs.who) return lhs.who < rhs.who;
    return lhs.subject < rhs.subject;
}

bool comp_subject_who_date::operator()(const email &lhs, const email &rhs) const {
    if(lhs.subject != rhs.subject) return lhs.subject < rhs.subject;
    if(lhs.who != rhs.who) return lhs.who < rhs.who;
    return lhs.date < rhs.date;
}

std::ostream& operator<<(std::ostream& os, const email& rhs) {
    os << "who: " << rhs.who << "\t subject: " << rhs.subject << "\t date: " << rhs.date;
    return os;
}

/*----------- mail_box -------------*/

mail_box::mail_box(size_t size): emails(std::vector<email>(size)) {}

void mail_box::add_email(const email& new_email) {
    emails.push_back(new_email);
}

void mail_box::sort_who() {
    std::sort(emails.begin(), emails.end(), comp_who_date_subject());
}

void mail_box::sort_date() {
    std::sort(emails.begin(), emails.end(), comp_date_who_subject());
}

void mail_box::sort_subject() {
    std::sort(emails.begin(), emails.end(), comp_subject_who_date());
}


