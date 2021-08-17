#include<iostream>
using namespace std;

class User
{
    private:
        char user_Name[20];
        double contact_Num;
        char email[30];
        int user_Type;
        int user_Id;
    public:
        void get_User_Data(); 
        void get_Name();
        void get_Usertype();
        void set_UserId();
        void registeration();
        void login();
        void add_User();
};
void User::add_User()
{
    // ofstream out("file.dat", ios::app | ios::binary);
    // obj.get_User_Data(); 
    // out.write((char *)&obj, sizeof(obj));
    // out.close();
}

class Product
{
    private:
        char product_Name[20];
        char prod_Type[20];
        double prod_Price;
        int count;
    public:
        void get_Product_Data();
        void put_Product_Data();
        void get_Product_Name();
        void get_Product_Type();
        void get_Product_Price();
        void get_Product_Count();
        void add_Product();

};
void Product::add_Product()
{
    // ofstream out("file.dat", ios::app | ios::binary);
    // obj.get_Product_Data();
    // out.write((char *)&obj, sizeof(obj));
    // out.close();
}

class Order
{
    private:
        char order_Status[20];
    public:
        void display_Order_Status();
        void order_Cancellation();
        void order_Placement();
        void cancelled_Orders_List();     
        void pending_Orders_List();
        void completed_Orders_List();
        void add_Order();
};
void Order::add_Order()
{
    // ofstream out("file.dat", ios::app | ios::binary);
    // obj.get_Product_Data();
    // out.write((char *)&obj, sizeof(obj));
    // out.close();
}

class Merchant
{
    public:
        void add_Product();
        void search_Product();
        void list_Product_Count();
        void assign_Courier_Person();
        //inherit cancelled_Orders_List(); and display_Order_Status(); from order class

};

class Customer
{
    public:
        void customer_Search_Product();
        void buy_Product();
        void cancel_Order();
        //inherit display_Order_Status(); from order class
};

class Courier_Person
{
    public:
        void update_Order_Status();
        //inherit assign_Courier_Person(); from merchant class and, pending_Orders_List(); , completed_Orders_List(); from order class
};