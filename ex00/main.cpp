#include "colours.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include "bank.hpp"

void testAddMoneyViaBankOnly()
{
    std::cout << CYAN << "Test: Adding money to an account can only be done via the bank...\n" << RESET;
    Bank bank;
    bank.createAccount(1);

    // Attempt to add money directly (should not be possible in a protected class)
    // Direct modification is not allowed, so we modify through the bank
    bank.deposit(0, 100);
    if (bank.getValue(0) == 96 && bank.getVault() == 5)
    {
        std::cout << GREEN << "Test passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test failed!\n" << RESET;
    }

    // Attempt to modify account directly (should not be possible)
    // This test checks the encapsulation indirectly by only allowing bank modification
    // If encapsulation is broken, manual setting would be possible
}

void testGiveLoan(void)
{
    std::cout << CYAN << "Test: Bank can give a loan within its funds...\n" << RESET;
    Bank bank;
    bank.createAccount(1);
    bank.deposit(0, 1000);
    bank.loan(0, 50);

    if (bank.getValue(0) == 1001 && bank.getVault() == 0)
    {
        std::cout << GREEN << "Test passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test failed!\n" << RESET;
    
    }

    // Test giving loan exceeding liquidity
    std::cout << CYAN << "Test: Bank cannot give a loan exceeding its funds...\n" << RESET;
    Bank bank2;
    bank2.createAccount(1);
    bank2.deposit(0, 1000);
    bank2.loan(0, 5000);
    
    if (bank2.getValue(0) == 1001 && bank2.getVault() == 0)
    {
        std::cout << RED << "Test failed!\n" << RESET;
    }
    else
    {
        std::cout << GREEN << "Test passed!\n" << RESET;
    }
}

void testCreateDeleteModifyAccounts()
{
    std::cout << CYAN << "Test: Bank can create, delete, and modify accounts...\n" << RESET;
    Bank bank;
    bank.createAccount(1);
    bank.createAccount(1);

    int initialSize = bank.getNAccounts();
    bank.deleteAccount(0);
    int newSize = bank.getNAccounts();

    if (initialSize == 2 && newSize == 1)
    {
        std::cout << GREEN << "Test 1 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test 1 failed!\n" << RESET;
    }

    // Test modifying account
    bank.deposit(1, 100);
    
    if (bank.getValue(1) == 96 && bank.getVault() == 5)
    {
        std::cout << GREEN << "Test 2 passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test 2 failed! : " << bank.getValue(1) << RESET;
    }

    std::cout << "Money in the bank: " << bank.getValue(0) << std::endl; 

    // test add money to not exist account
    bank.deposit(3, 100);

    // change id of account
    bank.createAccount(1);
    std::cout << "Money in the bank: " << bank.getValue(2) << std::endl;

    
}

/* void testAccountModificationProtection()
{
    std::cout << CYAN << "Test: Account attributes are not modifiable from the outside...\n" << RESET;
    Account account(0, 1);
    int originalValue = account.getValue();

    // Attempt to modify account value directly
    account.addValue(100); // This is the only way to modify it

    if (account.getValue() == originalValue + 100)
    {
        std::cout << GREEN << "Test passed!\n" << RESET;
    }
    else
    {
        std::cout << RED << "Test failed!\n" << RESET;
    }
} */

int main(void)
{
    std::cout << PURPLE << "Running tests...\n" << RESET;

    // Encapsulation test
/*     TestEncapsulation tester;
    tester.testAccount();
    tester.testBank(); */
    
    //testAccountModificationProtection();
    testCreateDeleteModifyAccounts();
    testGiveLoan();
    testAddMoneyViaBankOnly();
    
    return (0);
}