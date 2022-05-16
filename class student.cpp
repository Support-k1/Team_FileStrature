#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student {
public:
    int id;
    char name[20];
    float GPA;
    char addr[50];
    student() {};
    student(int id, const char* name, float GPA, const char* addr) {
        this->id = id;
        strcpy_s(this->name, name);
        this->GPA = GPA;
        strcpy_s(this->addr, addr);
    }
    void info() {
        cout << "ID: " << id << "\tName: " << name << "\tGPA: " << GPA << "\tAddr: " << addr << '\n';
    }

};

void add(student obj) {
    
    fstream file;
    file.open("details.txt", ios::binary | ios::app | ios::out);
    int start = file.tellp();

    file << obj.id;
    file.put('$');

    file.write((char*)&obj.name, 20);
    file.put('$');


    file << obj.GPA;
    file.put('$');

    file.write((char*)&obj.addr, 50);
    file.put('$');

    int end = file.tellp();
    int l = end - start;
    file.seekp((long)-l, ios::end);
    short lenght = l;
    file.write((char*)&lenght, sizeof(short));
    file.close();
}

void read() {
    ifstream file("details.txt", ios::binary | ios::out);
    short langht;
    student obj;
    char s;
    int i = 0;


    do {
        if (i++)
            obj.info();



        langht = sizeof(short);
        file.read((char*)&langht, sizeof(short));

        file >> obj.id;
        file >> s;

        file.read(obj.name, 20);
        file >> s;

        file >> obj.GPA;
        file >> s;

        file.read(obj.addr, 50);
        file >> s;




    } while (!file.eof());
    file.clear();
    file.close();
}

void research(int id) {

    ifstream file("details.txt", ios::binary | ios::out);
    short langht;
    student obj;
    char s;


    do {
        langht = sizeof(short);
        file.read((char*)&langht, sizeof(short));

        file >> obj.id;
        file >> s;

        file.read(obj.name, 20);
        file >> s;

        file >> obj.GPA;
        file >> s;

        file.read(obj.addr, 50);
        file >> s;
        if (obj.id == id)
        {
            obj.info();
            file.clear();
            file.close();
            break;
        }

    } while (!file.eof());
}
void update(student obj, int id) {
    ifstream file("details.txt", ios::binary);
    ofstream temp("temp.txt", ios::app | ios::binary);
    short lenght;
    student obj2;
    char s;

    do {
        lenght = sizeof(short);
        file.read((char*)&lenght, sizeof(short));

        file >> obj2.id;
        file >> s;

        file.read(obj2.name, 20);
        file >> s;

        file >> obj2.GPA;
        file >> s;

        file.read(obj2.addr, 50);
        file >> s;
        if (obj2.id == id)
        {
            obj2 = obj;
        }
        temp.write((char*)&lenght, sizeof(short));
        temp << obj2.id;
        temp.put('$');

        temp.write((char*)&obj2.name, 20);
        temp.put('$');


        temp << obj2.GPA;
        temp.put('$');

        temp.write((char*)&obj2.addr, 50);
        temp.put('$');

    } while (!file.eof());
    
    file.close();
    remove("details.txt");
    rename("temp.txt","details.txt");
    temp.close();
}
void del(int id) {
    ifstream file("details.txt", ios::binary);
    fstream temp("temp.txt", ios::app | ios::binary);
    short lenght;
    student obj;
    char s;
    do {
        lenght = sizeof(short);
        file.read((char*)&lenght, sizeof(short));

        file >> obj.id;
        file >> s;

        file.read(obj.name, 20);
        file >> s;

        file >> obj.GPA;
        file >> s;

        file.read(obj.addr, 50);
        if (obj.id == id)
        {
            continue;
        }
        temp.write((char*)&lenght, sizeof(short));
        temp << obj.id;
        temp.put('$');

        temp.write((char*)&obj.name, 20);
        temp.put('$');


        temp << obj.GPA;
        temp.put('$');

        temp.write((char*)&obj.addr, 50);
        temp.put('$');


    } while (!file.eof());
    file.close();
    remove("details.txt");
    rename("temp.txt","details.txt");
    temp.close();
}
int main() {
    student a(1, "ahmed", 2.9, "fayoum");
    student b(2, "hazam", 2.9, "fayoum");
    student c(3, "yousef", 2.9, "fayoum");
    student n(4, "dr.ahmed", 4.0, "Giza");
    add(a);
    add(c);
    add(n);
    add(b);
    //del(1);
    ///del(1);
   

    cout << "-------------------------------------" << endl;
    read();
    cout << "\n\n\nNO_RTE\n\n\n";
}
