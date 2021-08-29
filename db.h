#include <fstream>
#include "merchant.h"
#include "customer.h"
#include "courier.h"

class db 
{
    private:
        string current_User_Id;
    public:
        list<User> users;
        list<Product> products;
        list<Order> orders;

         db();
        ~db();

        void add_User_Data(User users);
        User UserLogin(string user_Id);
        void saveUserData();
        void saveProductData();
        void saveOrderData();
        void loadUserData();
        void loadOrderData();
        void loadProductData(); 
};