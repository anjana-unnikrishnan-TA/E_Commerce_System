#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Product
{
public:
    int product_Id;
    string product_Name;
    int product_Type;
    double product_Price;
    int product_Quantity;
    string merchant_Id;

    friend std::ostream &operator<<(std::ostream &out, const Product &product_obj)
    {
        out << product_obj.product_Name << "\t";
        out << product_obj.product_Type << "\t";
        out << product_obj.product_Price << "\t";
        out << product_obj.product_Quantity << "\t";
        out << product_obj.merchant_Id << "\t";
        out << product_obj.product_Id << endl;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Product &product_obj)
    {
        in >> product_obj.product_Name;
        in >> product_obj.product_Type;
        in >> product_obj.product_Price;
        in >> product_obj.product_Quantity;
        in >> product_obj.merchant_Id;
        in >> product_obj.product_Id;

        return in;
    }
    Product()
    {
        product_Id = 0;
        product_Name = "NULL";
        product_Type = 0;
        product_Price = 0;
        product_Quantity = 0;
        merchant_Id = "NULL";
    }
};

#endif