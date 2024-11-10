#include "email.h"

int main() {
    auto mb = mail_box(3);

    mb.add_email(email("akademibokhandeln","2024-11-10","vi firar singles day!"));
    mb.add_email(email("kivra", "2024-10-01", "nytt brev från skatteverket i kivra"));
    mb.add_email(email("hyresgästföreningen","2023-11-10","nyheter för dig som bor i hyresrätt"));
    mb.add_email(email("kulturama", "2022-11-04", "på gång på kulturama!"));
    mb.add_email(email("mitthem","2023-11-06","hyresfaktura mitthem"));

    show(mb);

    std::cout << "\nsort who\n";
    mb.sort_who();
    show(mb);

    std::cout << "\nsort subject\n";
    mb.sort_subject();
    show(mb);

    std::cout << "\nsort date\n";
    mb.sort_date();
    show(mb);
}
