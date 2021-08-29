#include <iostream>
#include "product.h"
#include "user.h"
#include "order.h"

using namespace std;

class Merchant : public User
{
    public:
        void add_Product_Data(list<Product>& products);
        void search_by_Product_Name(list<Product> products);
        void search_by_Product_Type(list<Product> products);
        void see_Product_Below_Count(list<Product> products);
        void assign_Orders_to_Courier(list<Order> * orders,int order_id,string courier_id);
        void Display_unassigned_orders(list<Order> orders);
        void Display_couriers(list<User> users);
        bool Is_Valid_order(list<Order> orders,int order_id);
        bool Is_valid_courier(list<User> users,string courierr_id);
};