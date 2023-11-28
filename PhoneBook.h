#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 100;
    Contact *contacts[MAX_CONTACTS];
    int count;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact(Contact *contact);
    void deleteContact(const char *fullName);
    int findContactIndex(const char *fullName) ;
    void displayAllContacts() ;
    void saveToFile(const char *fileName) ;
    void loadFromFile(const char *fileName);
};

#endif // PHONEBOOK_H
