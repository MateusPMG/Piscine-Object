#include "../includes/colours.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include "../includes/account.hpp"
#include "../includes/bank.hpp"

void test1()
{
    std::cout << "test 1 \n";
    Bank bank;
    bank.createAccount(1);

    
    bank.deposit(0, 100);
    if (bank.getValue(0) == 96 && bank.getVault() == 5)
    {
        std::cout << GREEN << "1 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "1 failed!\n" << RESET;
    }

}

void test2(void)
{
    Bank bank;
    bank.createAccount(1);
    bank.deposit(0, 1000);
    bank.loan(0, 50);

    if (bank.getValue(0) == 1001 && bank.getVault() == 0)
    {
        std::cout << GREEN << "2 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "2 failed!\n" << RESET;
    
    }
    Bank bank2;
    bank2.createAccount(1);
    bank2.deposit(0, 1000);
    bank2.loan(0, 5000);
    
    if (bank2.getValue(0) == 1001 && bank2.getVault() == 0)
    {
        std::cout << RED << "2.1 failed!\n" << RESET;
    }
    else
    {
        std::cout << GREEN << "2.1 passed!\n" << RESET;
    }
}

void test3()
{
    Bank bank;
    bank.createAccount(1);
    bank.createAccount(1);

    int initialSize = bank.getNAccounts();
    bank.deleteAccount(0);
    int newSize = bank.getNAccounts();

    if (initialSize == 2 && newSize == 1)
    {
        std::cout << GREEN << "3 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test 3 failed!\n" << RESET;
    }

    bank.deposit(1, 100);
    
    if (bank.getValue(1) == 96 && bank.getVault() == 5)
    {
        std::cout << GREEN << "3.1 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "3.1 failed! : " << bank.getValue(1) << RESET;
    }

    std::cout << "Money in the bank: " << bank.getValue(0) << std::endl; 

    bank.deposit(3, 100);
    bank.createAccount(1);
	bank.createAccount(1);
	bank.createAccount(1);
	bank.printAid();
    std::cout << "Money in the bank: " << bank.getValue(2) << std::endl;

    
}

/* void test4()
{
    std::cout << CYAN << "Test: Account attributes are not modifiable from the outside...\n" << RESET;
    Account account(0, 1);
    int originalValue = account.getValue();
    account.addValue(100);

    if (account.getValue() == originalValue + 100)
    {
        std::cout << GREEN << "4 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "4 failed!\n" << RESET;
    }
} */

void test5()
{
    Bank bank;

    // Test creating 1000 accounts
    for (int i = 0; i < 1000; ++i)
    {
        bank.createAccount(1);
    }
    if (bank.getNAccounts() == 1000)
    {
        std::cout << GREEN << "Created 1000 accounts.\n" << RESET;
    }
    else
    {
        std::cout << RED << "Didnt create 1000 accounts.\n" << RESET;
    }

    try
    {
        for (long i = 0; i < static_cast<long>(INT_MAX) + 1; ++i)
        {
            bank.createAccount(1);
        }
        std::cout << GREEN << "Created more than INT_MAX accounts.\n" << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << "failed Exception: " << e.what() << "\n" << RESET;
    }
    catch (...)
    {
        std::cout << RED << "failed Unknown exception.\n" << RESET;
    }
}


int main(void)
{
    std::cout << PURPLE << "Running tests...\n" << RESET;
    
    //testAccountModificationProtection();
    test1();
    test2();
    test3();
    //test5();
    
    return (0);
}