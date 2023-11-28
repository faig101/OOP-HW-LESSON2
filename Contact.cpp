#include "Contact.h"
using namespace std;
Contact::Contact(const char* name, const char* home, const char* work, const char* mobile, const char* info)
        : fullName(nullptr), homePhone(nullptr), workPhone(nullptr), mobilePhone(nullptr), additionalInfo(nullptr) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    homePhone = new char[strlen(home) + 1];
    strcpy(homePhone, home);
    workPhone = new char[strlen(work) + 1];
    strcpy(workPhone, work);
    mobilePhone = new char[strlen(mobile) + 1];
    strcpy(mobilePhone, mobile);
    additionalInfo = new char[strlen(info) + 1];
    strcpy(additionalInfo, info);
}

Contact::~Contact() {
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] additionalInfo;
}

void Contact::displayContact()  {
    cout << "ФИО: " << fullName << "\n";
    cout << "Домашний телефон: " << homePhone << "\n";
    cout << "Рабочий телефон: " << workPhone << "\n";
    cout << "Мобильный телефон: " << mobilePhone << "\n";
    cout << "Дополнительная информация: " << additionalInfo << "\n";
}

const char* Contact::getFullName()  {
    return fullName;
}

void Contact::saveToFile(FILE* file)  {
    fwrite(fullName, sizeof(char), strlen(fullName) + 1, file);
    fwrite(homePhone, sizeof(char), strlen(homePhone) + 1, file);
    fwrite(workPhone, sizeof(char), strlen(workPhone) + 1, file);
    fwrite(mobilePhone, sizeof(char), strlen(mobilePhone) + 1, file);
    fwrite(additionalInfo, sizeof(char), strlen(additionalInfo) + 1, file);
}

bool Contact::loadFromFile(FILE* file) {
    if (fread(fullName, sizeof(char), 256, file) == 0) {
        return false;
    }
    fread(homePhone, sizeof(char), 15, file);
    fread(workPhone, sizeof(char), 15, file);
    fread(mobilePhone, sizeof(char), 15, file);
    fread(additionalInfo, sizeof(char), 256, file);
    return true;
}
