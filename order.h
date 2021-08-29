#ifndef   ORDER_H 
#define   ORDER_H
#include <iostream>
#include <string>
#include <list>

using namespace std;
class Order
{    
    public:
        string order_Name;
        string courier_Id;       
        int order_Id;
        string delivery_Status;
        string merchant_Id;
        string customer_Id;

        friend std::ostream & operator << (std::ostream &out, const Order & order_obj)  
        {
            out << order_obj.order_Name << "\t";
            out << order_obj.order_Id << "\t"; 
            out << order_obj.merchant_Id << "\t"; 
            out << order_obj.delivery_Status << "\t";  
            out << order_obj.courier_Id << "\t"; 
            out << order_obj.customer_Id  << endl;
            return out;
        }
        friend std::istream & operator >> (std::istream &in, Order & order_obj)
        {
            in >> order_obj.order_Name ;
            in >> order_obj.order_Id;
            in >> order_obj.merchant_Id;
            in >> order_obj.delivery_Status; 
            in >> order_obj.courier_Id;
            in >> order_obj.customer_Id;
            
            return in;
        }

        Order()
        {
            order_Name="NULL"; 
            courier_Id="NULL";
            order_Id=0;
            delivery_Status="NULL";
            merchant_Id="NULL"; 
            customer_Id="NULL";

        }
};

#endif