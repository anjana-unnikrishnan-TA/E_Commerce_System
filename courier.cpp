#include "courier.h"

//Couriers Function to view the orders assigned to them for delivery

void Courier :: list_assigned_Orders(list<Order> orders)
{
    int flag = 0;
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
        {
        if (it->courier_Id == user_Id && it->delivery_Status == "Delivering")
        {
        flag = 1;
        cout << "Customer ID : " << it->customer_Id << "\n"; 
        cout << "Order ID : " << it->order_Id <<"\n";
        cout << "Order Status : " << it->delivery_Status << "\n";
        }
    }
    cout << "\n";
    if (flag == 0)
    {
    cout << "No orders assigned\n";
    }
}

//Couriers Function to update the status for an order after delivery

void Courier :: order_status_Update(list<Order>* orders)
{
    string temp_Cutomer_Id;
    int flag = 0;
    list_assigned_Orders(*orders);
    cout << "Enter the customer Id whose status is to be updated : \n";
    cin >> temp_Cutomer_Id;
    for (std::list<Order>::iterator it = orders->begin(); it != orders->end(); ++it)
    {
        if (it->customer_Id == temp_Cutomer_Id)
        {
            flag = 1;
            it->delivery_Status = "Delivered";     
            break;
        }
    }
    if (flag == 0)
    {
        cout << "No status change\n";
    }
    else
    {
        cout << "Status Changed\n";
    }
}

//Couriers function to list the pending and completed deliveries

void Courier :: list_Orders(list<Order> orders)
{
    string temp_Courier_Id;
    int flag = 0;
    temp_Courier_Id = user_Id;
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->courier_Id == temp_Courier_Id)
        {
            flag = 1;
            cout << "Customer ID : " << it->customer_Id << "\n"; 
            cout << "Order ID : " << it->order_Id <<"\n";
            cout << "Order Status : " << it->delivery_Status << "\n";
        }
    }
    cout << "\n";
    if (flag == 0)
    {
        cout << "No orders assigned\n";
    }
}