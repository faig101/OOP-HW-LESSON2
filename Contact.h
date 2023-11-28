#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
private:
    char* fullName;
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info);
    ~Contact();
    void displayContact() ;
    const char* getFullName() ;
    void saveToFile(FILE* file) ;
    bool loadFromFile(FILE* file);
};

#endif // CONTACT_H
