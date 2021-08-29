#ifndef   USER_H 
#define   USER_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

class User
{
public:
    string user_Name;
    string user_contact_Num;
    string user_email;
    int user_Type;
    string user_Id;

public:
    friend std::ostream & operator << (std::ostream &out, const User & user_obj)
    {
        out << user_obj.user_Id << "\t"; 
        out << user_obj.user_Name << "\t";
        out << user_obj.user_contact_Num << "\t";
        out << user_obj.user_email << "\t"; 
        out << user_obj.user_Type<<endl;
        return out;
    }

    friend std::istream & operator >> (std::istream &in, User & user_obj)
    {
        in >> user_obj.user_Id ;
        in >> user_obj.user_Name ;
        in >> user_obj.user_contact_Num; 
        in >> user_obj.user_email;
        in >> user_obj.user_Type;
        return in;
    }
};

#endif