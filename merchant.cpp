#include "merchant.h"

//Merchants function to add products

void Merchant ::add_Product_Data(list<Product> &products)
{
    Product newProduct;
    srand(time(0));
    cout << "Enter the product name : \n";
    cin >> newProduct.product_Name;
    cout << "Enter the product type : \n";
    cout << "1. Electronics\n";
    cout << "2. Clothing\n";
    cout << "3. Toys\n";
    cout << "4. Furniture\n";
    cin >> newProduct.product_Type;
    cout << "Enter the product price : \n";
    cin >> newProduct.product_Price;
    cout << "Enter the product quantity : \n";
    cin >> newProduct.product_Quantity;
    newProduct.merchant_Id = user_Id;
    newProduct.product_Id = (rand() % 1000) + 1;
    cout << "The product is added\n";
    products.push_back(newProduct);
}

//Merchants function to search for products by name

void Merchant ::search_by_Product_Name(list<Product> products)
{
    string prod_Name_Temp;
    int flag = 0;
    cout << "Enter the product name : \n";
    cin >> prod_Name_Temp;
    Product matchingProduct;
    for (std::list<Product>::iterator it = products.begin(); it != products.end(); ++it)
    {
        if (it->product_Name == prod_Name_Temp)
        {
            matchingProduct = *it;
            flag = 1;
            cout << "Product name is: " << matchingProduct.product_Name << " \n";
            cout << "Product Type is: " << matchingProduct.product_Type << " \n";
            cout << "Product Price is: " << matchingProduct.product_Price << " \n";
            cout << "Product Quantity is: " << matchingProduct.product_Quantity << " \n\n";
        } 
    }
    if (flag == 0)
    {
        cout << "No Products found\n";
    }
}

//Merchants function to search for products by type

void Merchant ::search_by_Product_Type(list<Product> products)
{
    int prod_Type_Temp;
    int flag = 0;
    cout << " Enter the product type : \n";
    cout << "1. Electronics\n";
    cout << "2. Clothing\n";
    cout << "3. Toys\n";
    cout << "4. Furniture\n";
    cin >> prod_Type_Temp;
    Product matchingProduct;
    for (std::list<Product>::iterator it = products.begin(); it != products.end(); ++it)
    {
        if (it->product_Type == prod_Type_Temp)
        {
            flag = 1;
            matchingProduct = *it;
            cout << "Product name is: " << matchingProduct.product_Name << " \n";
            cout << "Product Type is: " << matchingProduct.product_Type << " \n";
            cout << "Product Price is: " << matchingProduct.product_Price << " \n";
            cout << "Product Quantity is: " << matchingProduct.product_Quantity << " \n\n";
        }
    }
    if (flag == 0)
    {
        cout << "No Products found\n";
    }
}

//Merchants function to view products below a particular count

void Merchant ::see_Product_Below_Count(list<Product> products)
{
    int product_Count, flag = 0;
    cout << "Enter the count to search for product with quantity less than current count : \n";
    cin >> product_Count;
    Product matchingProduct;
    for (std::list<Product>::iterator it = products.begin(); it != products.end(); ++it)
    {
        if (it->product_Quantity <= product_Count)
        {
            flag = 1;
            matchingProduct = *it;
            cout << "Product name is: " << matchingProduct.product_Name << " \n";
            cout << "Product Quantity is: " << matchingProduct.product_Quantity << " \n\n";
        }
    }
    if (flag == 0)
    {
        cout << "Sufficient Products \n";
    }
}

//Merchants function to assign a product to a courier person

void Merchant ::assign_Orders_to_Courier(list<Order> *orders, int order_id, string Courier_Id)
{ 
    for (std::list<Order>::iterator it = orders->begin(); it != orders->end(); ++it)
    {
        if (it->order_Id == order_id)
        {   
            it->courier_Id = Courier_Id;
            it->delivery_Status = "Delivering";
            break;
        }
    }
 
}

//Function to display orders to be assigned for a courier person by merchant

void Merchant ::Display_unassigned_orders(list<Order> orders)
{
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->merchant_Id == user_Id && it->delivery_Status == "Ordered")
        {
            cout << "Order Id : " << it->order_Id << "\n\n";
        }
    }
}

//Function to check if the order is valid

bool Merchant ::Is_Valid_order(list<Order> orders, int order_id)
{
    bool is_valid = false;
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->merchant_Id == user_Id && it->order_Id == order_id)
        {
            is_valid = true;
            break;
        }
    }
    return is_valid;
}

//Function to display available couriers

void Merchant ::Display_couriers(list<User> users)
{
    for (std::list<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->user_Type == 3)
        {
            cout << "User Id : " << it->user_Id<<"\n\n";
        }
    }
}

//Function to check validity of the courier person

bool Merchant ::Is_valid_courier(list<User> users, string courier_id)
{
    bool is_valid = false;
    for (std::list<User>::iterator it = users.begin(); it != users.end(); ++it)
    {
        if (it->user_Id == courier_id)
        {
            is_valid = true;
            break;
        }
    }
    return is_valid;
}