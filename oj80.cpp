#include<bits/stdc++.h>
using namespace std;
class BankAccount{
    private:
        double balance;
        string accountNumber;
    public:
        BankAccount(string accNum, double initbalance)
            : accountNumber(accNum), balance(initbalance) {}
        void deposit(double amount){
            if(amount>0)balance+=amount;
        }
        bool withdraw(double amount){
            if(amount>0 && amount<=balance){
                balance-=amount;
                return true;
            }
            return false;
        }
        double getBalance(){
            return balance;
        }
        string getAccountNumber(){
            return accountNumber;
        }
};
class Bank{
    public:
        vector<BankAccount>accounts;
        void addAccount(string accNum, double initbalance){
            accounts.push_back(BankAccount(accNum,initbalance));
        }
        bool deleteAccount(string accNum){
            for(auto it=accounts.begin();it!=accounts.end();it++){
                if(it->getAccountNumber()==accNum){
                    accounts.erase(it);
                    return true;
                }
            }
            return false;
        }
        void getAllAccountInfo(){
            for(auto&acc:accounts){
                cout<<"账号: "<<acc.getAccountNumber()<<", 余额: "<<acc.getBalance()<<endl;
            }
        }
};
int main() {
	Bank bank;
	bank.addAccount("123456", 1000.0);
	bank.addAccount("789012", 2000.0);
	bank.getAllAccountInfo(); // 输出所有账户信息
	for (auto& account : bank.accounts) {
		if (account.getAccountNumber() == "123456") {
			account.deposit(500.0); // 向账号 123456 存款 500
			if (account.withdraw(200.0)) { // 从账号 123456 取款 200
				cout << "取款成功" << endl;
			}
			else {
				cout << "取款失败" << endl;
			}
			break;
		}
	}
	bank.getAllAccountInfo(); // 再次输出所有账户信息
	if (bank.deleteAccount("789012")) { // 删除账号 789012
		cout << "账号删除成功" << endl;
	}
	else {
		cout << "账号删除失败" << endl;
	}
	bank.getAllAccountInfo(); // 输出所有账户信息
	return 0;
}