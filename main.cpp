#include "PhoneBook.h"

int main() {
    PhoneBook myPhoneBook;
    Contact *contact1 = new Contact("Фаиг Ибрагимов", "123-456-7890", "111-222-3333", "987-654-3210","Салам Алейкум");
    Contact *contact2 = new Contact("Фаиги Ибрагимови", "555-555-5555", "666-666-6666", "777-777-7777", "Человек");
    myPhoneBook.addContact(contact1);
    myPhoneBook.addContact(contact2);
    myPhoneBook.displayAllContacts();
    myPhoneBook.saveToFile("contacts.dat");
    myPhoneBook.deleteContact("Фаиг Ибрагимов");
    myPhoneBook.displayAllContacts();
    myPhoneBook.loadFromFile("contacts.dat");
    myPhoneBook.displayAllContacts();

    return 0;
}
