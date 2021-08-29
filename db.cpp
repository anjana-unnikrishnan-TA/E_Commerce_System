#include "db.h"

//Function to add new users to e-commerce system

void  db :: add_User_Data(User user)
{
    User newUser;
    cout << "Enter the user name : \n";
    cin >> newUser.user_Name;
    contact_Num:
    cout << "Enter contact number : \n";
    cin >> newUser.user_contact_Num;
    if(newUser.user_contact_Num.length() != 10)
    {
        cout << "Enter a 10 digit contact number!\n";
        goto contact_Num;
    }
    email_Id:
    cout << "Enter email : \n";
    cin >> newUser.user_email;
    
    for (std::list<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->user_email == newUser.user_email)
        {
            cout << "The entered email is already registered!\n";
            goto email_Id;
        }
        else
        {
            continue;
        }
    }
    cout << "Enter user type : \n";
    cout << "1. Merchant\n";
    cout << "2. Customer\n";
    cout << "3. Courier\n";
    cin >> newUser.user_Type;
    if(newUser.user_Type != 1 | newUser.user_Type != 2 | newUser.user_Type != 3)
    {
        cout << "Enter a valid type\n";
    }
    newUser.user_Id = newUser.user_email;
    cout << "Your userid is : " << newUser.user_Id<<endl;

    users.push_back(newUser);
}

//Function to login for an user

User db :: UserLogin(string user_Id)
{
    int flag = 0;
    User matchingUser;
    for (std::list<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->user_Id == user_Id)
        {
            flag = 1;
            matchingUser = *it;
            current_User_Id = matchingUser.user_Id;
            break;
        }
    }
    return matchingUser;
}

//db class constructor to load the user, product and order data when application starts

db :: db()
{
    loadUserData();
    loadOrderData();
    loadProductData();
}

//db class destructor to save the user, product and order data when application ends

db :: ~db()
{
    saveUserData();
    saveProductData();
    saveOrderData();
}

void db :: saveUserData()
{
    if(users.size()>0)
    {
        std::ofstream out("users.txt", ios::trunc);
        if(out)
        {
            out << users.size() << "\n";
            for (std::list<User>::iterator it = users.begin(); it != users.end(); ++it)
            {
                out << *it;
            }
        }
        out.close();
    }
}

void db :: saveProductData()
{
    if(products.size()>0)
    {
        std::ofstream out("products.txt",ios::trunc);
        if(out)
        {
            out << products.size() << endl;
            for (std::list<Product>::iterator it = products.begin(); it != products.end(); ++it)
            {
                out << *it;
            }
        }
        out.close();
    }
}

void db :: saveOrderData()
{
    if(orders.size()>0)
    {
        std::ofstream out("orders.txt",ios::trunc);
        if(out)
        {
            out << orders.size() << "\n";
            for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
            {
                out << *it;
            }
        }
        out.close();
    }
}

void db :: loadUserData()
{
    int no_of_Users;
    string line;
    std::ifstream in("users.txt");
    if(in)
    {

        users.empty();
        getline(in, line);
        no_of_Users = stoi(line);
        for (int i= 0; i < no_of_Users ; i++)
        {
            User user;
            in  >> user;
            users.push_back(user);
        }
    }
    in.close();
}

void db :: loadProductData()
{
    int no_of_Products;
    string line;
    std::ifstream in("products.txt");
    if(in)
    {
        products.empty();
        getline(in, line);
            no_of_Products = stoi(line);
            for (int i= 0; i < no_of_Products ; i++)
            {
                Product product;
                in  >> product;
                products.push_back(product);
            }
    }
    in.close();
}

void db :: loadOrderData()
{
    int no_of_Orders;
    string line;
    std::ifstream in("orders.txt");
    if(in)
    {
        orders.empty();
        getline(in, line);
            no_of_Orders = stoi(line);
            for (int i= 0; i < no_of_Orders ; i++)
            {
                Order order;
                in  >> order;
                orders.push_back(order);
            }
    }
    in.close();
}