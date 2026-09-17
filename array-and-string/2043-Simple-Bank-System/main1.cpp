#include <cassert>
#include <vector>

using namespace std;

class Bank {
    vector<long long> balance;
    int n;
public:
    Bank(vector<long long>& balance) : balance(balance), n(balance.size()) {}
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money; balance[account2 - 1] += money; return true;
    }
    bool deposit(int account, long long money) {
        if (account > n) return false;
        balance[account - 1] += money; return true;
    }
    bool withdraw(int account, long long money) {
        if (account > n || balance[account - 1] < money) return false;
        balance[account - 1] -= money; return true;
    }
};

int main()
{
    vector<long long> balance1 = {10, 100, 20, 50, 30};
    Bank bank(balance1);
    assert(bank.withdraw(3, 10));
    assert(bank.transfer(5, 1, 20));
    assert(bank.deposit(5, 20));
    assert(!bank.transfer(3, 4, 15));
    assert(!bank.withdraw(10, 50));
    return 0;
}
