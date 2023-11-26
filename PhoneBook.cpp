#include "PhoneBook.h"
#include <iostream>
using namespace std;
PhoneBook::PhoneBook() : count(0) {}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < count; i++) {
        delete contacts[i];
    }
}

void PhoneBook::addContact(Contact *contact) {
    if (count < MAX_CONTACTS) {
        contacts[count++] = contact;
        cout << "Контакт добавлен.\n";
    }
}

void PhoneBook::deleteContact(const char *fullName) {
    int index = findContactIndex(fullName);
    if (index != -1) {
        delete contacts[index];
        contacts[index] = contacts[count--];
        cout << "Контакт удален.\n";
    } else {
        cout << "Контакт не найден.\n";
    }
}

int PhoneBook::findContactIndex(const char *fullName) const {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i]->getFullName(), fullName) == 0) {
            return i;
        }
    }
    return -1;
}

void PhoneBook::displayAllContacts() const {
    for (int i = 0; i < count; i++) {
        cout << "Контакт " << i + 1 << ":\n";
        contacts[i]->displayContact();
        cout << "-------------------\n";
    }
}

void PhoneBook::saveToFile(const char *fileName) const {
    FILE *file = fopen(fileName, "wb");
    if (file != nullptr) {
        fwrite(&count, sizeof(int), 1, file);
        for (int i = 0; i < count; i++) {
            contacts[i]->saveToFile(file);
        }
        fclose(file);
    }
}

void PhoneBook::loadFromFile(const char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (file != nullptr) {
        fread(&count, sizeof(int), 1, file);
        for (int i = 0; i < count; ++i) {
            Contact *contact = new Contact("", "", "", "", "");
            contact->loadFromFile(file);
            if (strlen(contact->getFullName()) > 0) {
                addContact(contact);
            } else {
                delete contact;
            }
        }
        fclose(file);
    }
}
