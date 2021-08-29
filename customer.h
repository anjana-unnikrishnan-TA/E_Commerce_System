#ifndef   CUSTOMER_H 
#define   CUSTOMER_H
#include <iostream>
#include "user.h"
#include "product.h"
#include "order.h"

using namespace std;

class Customer : public User
{
    public:
        void search_Product(list<Product>* products, list<Order>* orders);
        void order_Status(list<Order> orders);
        void cancel_Order(list<Order>* orders, list<Product>* products);
        void list_Ordered_Products(list<Order> orders);
        void order_Placed(Product product, list<Order>* orders);
        void product_Count_Increment(string order_Name, list<Product>* products);
};
#endif
