#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "db.h"

using namespace std;

// This is a function that lists the merchant functions like adding a product, assigining orders to couriers etc.

void MerchantMenu(db *db_Obj, User user)
{
    Merchant merchant_Obj;
    merchant_Obj.user_Id = user.user_Id;
    int M_choice, search_Type;
    do
    {
        cout << "\n\n***********************************\n";
        cout << "\tMERCHANT MENU\n";
        cout << "***********************************\n";
        cout << "\t1. Add Product\n";
        cout << "\t2. Search Product\n";
        cout << "\t3. List Product Count\n";
        cout << "\t4. Assign Order\n";
        cout << "\t5. Exit\n\n";
        cout << "Enter your choice :\n";
        cin >> M_choice;
        switch (M_choice)
        {
        case 1:
            merchant_Obj.add_Product_Data(db_Obj->products);
            break;

        case 2:
            cout << "Do you want to search by Name or Type of product ?\n";
            cout << "1. Search by Name\n";
            cout << "2. Search by Type\n";
            cin >> search_Type;
            if (search_Type == 1)
            {
                merchant_Obj.search_by_Product_Name(db_Obj->products);
            }
            else
            {
                merchant_Obj.search_by_Product_Type(db_Obj->products);
            }
            break;
        case 3:
            merchant_Obj.see_Product_Below_Count(db_Obj->products);
            break;
        case 4:
        {
            int order_Id;
            string courier_id;
            bool Valid_Order, Valid_courier;

            merchant_Obj.Display_unassigned_orders(db_Obj->orders);
            cout << "Select Order to be assigned : \n";
            cin >> order_Id;
            Valid_Order = merchant_Obj.Is_Valid_order(db_Obj->orders, order_Id);
            if (Valid_Order)
            {
                merchant_Obj.Display_couriers(db_Obj->users);
                cout << "Enter the courier person to be assigned : \n";
                cin >> courier_id;
                
                Valid_courier = merchant_Obj.Is_valid_courier(db_Obj->users, courier_id);
                if (Valid_courier)
                {
                    merchant_Obj.assign_Orders_to_Courier(&db_Obj->orders, order_Id, courier_id);
                }
                else
                {
                    cout << "Invalid courier Id\n";
                }
            }
            else
            {
                cout << "Invalid Order\n";
            }
            break;
        }
        case 5:
            cout << "Exiting\n";
            break;
        default:
            cout << "Wrong choice\n";
        }
    } while (M_choice != 5);
}

// This is a function that lists the customer functions like buying a product, canceling products etc.

void CustomerMenu(db *db_Obj, User user)
{
    Customer customer_Obj;
    customer_Obj.user_Id = user.user_Id;
    int C_choice;
    do
    {
        cout << "\n\n***********************************\n";
        cout << "\tCUSTOMER MENU\n";
        cout << "***********************************\n";
        cout << "\t1. Buy Product\n";
        cout << "\t2. Cancel Orders\n";
        cout << "\t3. Order Status\n";
        cout << "\t4. Exit\n\n";
        cout << "Enter your choice : \n";
        cin >> C_choice;
        switch (C_choice)
        {
        case 1:
            customer_Obj.search_Product(&db_Obj->products, &db_Obj->orders);
            break;

        case 2:
            customer_Obj.cancel_Order(&db_Obj->orders, &db_Obj->products);
            break;

        case 3:
            customer_Obj.order_Status(db_Obj->orders);
            break;

        case 4:
            cout << "Exiting\n";
            break;

        default:
            cout << "Wrong choice\n";
        }
    } while (C_choice != 4);
}

// This is a function that lists the courier functions like update order status.

void CourierMenu(db *db_Obj, User user)
{
    Courier courier_Obj;
    courier_Obj.user_Id = user.user_Id;
    int Co_choice;
    do
    {
        cout << "\n\n***********************************\n";
        cout << "\tCOURIER MENU\n";
        cout << "***********************************\n";
        cout << "\t1. List of Assigned Orders\n";
        cout << "\t2. Update the Order status\n";
        cout << "\t3. See the list of pending and completed delivery\n";
        cout << "\t4. Exit\n\n";
        cout << "\nEnter your choice:\n";
        cin >> Co_choice;
        switch (Co_choice)
        {
        case 1:
            courier_Obj.list_assigned_Orders(db_Obj->orders);
            break;

        case 2:
            courier_Obj.order_status_Update(&db_Obj->orders);
            break;

        case 3:
            courier_Obj.list_Orders(db_Obj->orders);
            break;

        case 4:
            cout << "Exiting\n";
            break;

        default:
            cout << "Wrong choice\n";
        }
    } while (Co_choice != 4);
}

int main()
{
    db db_Obj;
    int choice;
    do
    {
        User user;
        Product product;
        string ID;
        cout << "\n\n***********************************\n";
        cout << "\tE-COMMERCE SYSTEM\n";
        cout << "***********************************\n";
        cout << "\t1. Sign Up\n";
        cout << "\t2. Login in\n";
        cout << "\t3. Exit\n\n";
        cout << "Enter the choice : \n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            db_Obj.add_User_Data(user);
            break;

        case 2:
            cout << "Enter User ID to login : \n";
            cin >> ID;
            user = db_Obj.UserLogin(ID);
            if(user.user_Id.size()== 0)
            {
                cout<<"Invalid User\n";
                continue;
            }
            switch (user.user_Type)
            {
            case 1:
                cout << "Merchant\n";
                MerchantMenu(&db_Obj, user);
                break;
            case 2:
                cout << "Customer\n";
                CustomerMenu(&db_Obj, user);
                break;
            case 3:
                cout << "Courier\n";
                CourierMenu(&db_Obj, user);
                break;
            default:
                cout << "User dosen't exist\n";
            }
            break;
        case 3:
            cout << "\nexiting\n";
            break;

        default:
            cout << "Wrong choice\n";
        }

    } while (choice != 3);
}