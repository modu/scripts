#include <iostream>
#include <string>

#include "Account.h"

void pass_test(bool result, std::string test_name)
{
    std::cout<<"Test " << test_name << " ";
    if (result) 
    {
        std::cout<< "[PASSED]";
    }
    else
    {
        std::cout<< "[FAILED]";
    }
    std::cout<< "\n";
}

bool acccount_balance_test(unsigned long num_of_iter)
{
    for(int i = 0; i < num_of_iter; i++)
    {
        bool case_state = true;
        Account *ac = new Account(i*100);
        if (ac->get_Balance() != i*100)
        {
            case_state = false;
        }
        delete ac;
        if(!case_state)
        {
            return false;
        }
    }

    return true;
}

bool acccount_transfer_test()
{
    Account *ac1 = new Account();
    Account *ac2 = new Account(100);
    
    if ((!ac2->transfer_money_to(ac1, 20)) || (ac2->get_Balance() != 80) || (ac1->get_Balance() != 20))
    {
        return false;
    }
    
    if ((ac1->transfer_money_to(ac2, 30)) || (ac2->get_Balance() != 80) || (ac1->get_Balance() != 20))
    {
        return false;
    }


    return true;
}

int main(int argc, char** argv)
{
    //Account ac1;
    //Account ac2(40);
    //std::cout<< "so..." << ac1.get_Balance() << " " << ac2.get_Balance() << "\n";

    pass_test(acccount_balance_test(100), "acccount_balance_test");
    pass_test(acccount_transfer_test(), "acccount_transfer_test");

    return 0;
}