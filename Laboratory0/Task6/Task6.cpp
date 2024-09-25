#include <iostream>
#include <string>

struct Person {

    std::string FirstName;

    std::string LastName;

    unsigned Age;
};

const int PeopleCount = 5;

Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];
    people[0] = new Person();
    people[0]->FirstName = "Casey";
    people[0]->LastName = "Aguilar";
    people[0]->Age = 30;
    
    people[1] = new Person();
    people[1]->FirstName = "Brock";
    people[1]->LastName = "Curtis";
    people[1]->Age = 19;
    
    people[2] = new Person();
    people[2]->FirstName = "Blake";
    people[2]->LastName = "Diaz";
    people[2]->Age = 21;
    
    people[3] = new Person();
    people[3]->FirstName = "Cristian";
    people[3]->LastName = "Evans";
    people[3]->Age = 55;
    
    people[4] = new Person();
    people[4]->FirstName = "Les";
    people[4]->LastName = "Foss";
    people[4]->Age = 4;

    return people;
}

void WritePerson(Person* person) {
    std::cout << "First Name: " + person->FirstName
        + "; Last Name: " + person->LastName
        + "; Age: " + std::to_string(person->Age)
        << std::endl;
}

void ClearPeople(Person** people, int count) {
    for (int i = 0; i < count; ++i) {
        delete people[i];
    }
    delete[] people;
}

void Task1_FindPersonByLastName() {
    Person** people = CreatePeopleArray();
    for (int i = 0; i < PeopleCount; i++) {
        WritePerson(people[i]);
    }

    std::string lastName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    int foundIndex = -1;

    // Реализация поиска фамилии
    for (int i = 0; i < PeopleCount; ++i) {
        if (people[i]->LastName == lastName) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        std::cout << "Could not find a person by last name: " << lastName << std::endl;
    }
    else {
        std::cout << "A person's last name "
            << lastName
            << " was found. Its index in the array is "
            << foundIndex
            << std::endl;
    }

    ClearPeople(people, PeopleCount);
}

int main() {
    Task1_FindPersonByLastName();
    return 0;
}