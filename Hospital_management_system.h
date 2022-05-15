#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Abstract Classes  Hospital_management_system and Pure Virtual Functions
class  Hospital_management_system{


public:
    Hospital_management_system()=default;
    virtual  void create_record()=0;
    virtual  void Search()=0;
    virtual  void Update_record()=0;
    virtual  void Binary_search()=0;
    virtual  void delete_record()=0;
    virtual  void display_record()=0;
    virtual  void Help()=0;
    virtual  void Exit()=0;
    ~Hospital_management_system()=default;

};

//class patient derived class form Hospital_management_system
class patient: public Hospital_management_system{

private:

 char patient_name[20];//variable of type char, it will be for example. Char patient_name[50]
 string  id;           //variable of type string, it will be for example. String id
 int Age;              //variable of type int, it will be for example. Int age
 string Address;       //variable of type string, it will be for example. String address
 string Status;        //variable of type string, it will be for example. String status

public:

      void create_record() override{};
      void Search() override{};
      void Update_record() override{};
      void Binary_search() override{};
      void delete_record() override{};
      void display_record() override{};
      void Help() override{};
      void Exit() override{};


};
