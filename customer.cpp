#include "customer.h"

//Customer function to search for a product and buy it

void Customer ::search_Product(list<Product> *products, list<Order> *orders)
{
    int type_choice;
    int flag = 0, choice, continue_Choice = 2;
    do
    {
        cout << "Select from Product Types : \n";
        cout << "1. Electronics\n";
        cout << "2. Clothing\n";
        cout << "3. Toys\n";
        cout << "4. Furniture\n";
        cin >> type_choice;
        Product matchingProduct;
        for (std::list<Product>::iterator it = products->begin(); it != products->end(); ++it)
        {
            if (it->product_Type == type_choice)
            {
                flag = 1;
                matchingProduct = *it;
                cout << matchingProduct.product_Name << "\n";
            }
        }
        if (flag == 0)
        {
            cout << "No results found\n";
        }
        else
        {
            string name_Choice;

            cout << "Enter the name of product : \n";
            cin >> name_Choice;
            for (std::list<Product>::iterator it = products->begin(); it != products->end(); ++it)
            {
                if (it->product_Name == name_Choice)
                {
                    matchingProduct = *it;
                    cout << "The Product name is : " << matchingProduct.product_Name << "\n";
                    cout << "The Product Price is : " << matchingProduct.product_Price << " \n";
                    cout << "The Product Quantity is : " << matchingProduct.product_Quantity << " \n\n";
                    cout << "Do you want to buy this product ?\n";
                    cout << "1. Yes\n";
                    cout << "2. No\n";
                    cin >> choice;
                    if (choice == 1)
                    {
                        it->product_Quantity -= 1;
                        order_Placed(matchingProduct, orders);
                    }
                    else
                    {
                        cout << "Do you want to search for another product ?\n";
                        cout << "1. Yes\n";
                        cout << "2. No\n";
                        cin >> continue_Choice;
                    }
                }
            }
        }
    } while (continue_Choice == 1);
}

//Function to push back new order details 

void Customer ::order_Placed(Product product, list<Order> *orders)
{
    Order newOrder;
    srand(time(0));
    newOrder.customer_Id = user_Id; 
    newOrder.order_Id = (rand() % 1000) + 1;
    newOrder.order_Name = product.product_Name;
    newOrder.merchant_Id = product.merchant_Id;
    newOrder.delivery_Status = "Ordered";
    orders->push_back(newOrder);
}

//Customer function to cancel an order

void Customer ::cancel_Order(list<Order> *orders, list<Product>* products)
{
    int temp_Product_Id;
    int flag = 0;
    list_Ordered_Products(*orders);
    cout << "Enter the product id you wish to cancel : \n";
    cin >> temp_Product_Id;
    for (std::list<Order>::iterator it = orders->begin(); it != orders->end(); ++it)
    {
        if (it->order_Id == temp_Product_Id)
        {
            flag = 1;
            it->delivery_Status = "Cancelled";
            product_Count_Increment(it->order_Name, products);
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

//Function to increment product quantity after cancellation

void Customer :: product_Count_Increment(string order_Name, list<Product> *products)
{
    for (std::list<Product>::iterator it = products->begin(); it != products->end(); ++it)
    {
        if (it->product_Name == order_Name)
        {
            it->product_Quantity += 1;
            break;
        }
    }
}

//Function to list ordered products

void Customer :: list_Ordered_Products(list<Order> orders)
{
    int flag = 0;
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->delivery_Status == "Ordered" || it->delivery_Status == "Delivering")
        {
            flag = 1;
            cout << "Product Name : " << it->order_Name << "\n";    
            cout << "Product ID : " << it->order_Id << "\n";
            cout << "Order Status : " << it->delivery_Status << "\n\n";
        }
    }
    if (flag == 0)
    {
        cout << "No orders found\n";
    }
}

//Customer function to view the order status

void Customer ::order_Status(list<Order> orders)
{
    string temp_Customer_Id;
    int flag = 0;
    temp_Customer_Id = user_Id;
    for (std::list<Order>::iterator it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->customer_Id == temp_Customer_Id)
        {
            flag = 1;
            cout << "Product Name : " << it->order_Name << "\n";    
            cout << "Product ID : " << it->order_Id << "\n";
            cout << "Order Status : " << it->delivery_Status << "\n\n";
        }
    }
    if (flag == 0)
    {
        cout << "No orders found\n";
    }
}