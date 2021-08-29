#include <iostream>
#include "product.h"
#include "user.h"
#include "order.h"

using namespace std;

class Courier : public User
{
    public:
        void list_assigned_Orders(list<Order> orders);
        void order_status_Update(list<Order>* orders);
        void list_Orders(list<Order> orders);
};