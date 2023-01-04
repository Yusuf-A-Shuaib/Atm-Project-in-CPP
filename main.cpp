#include <iostream>


using namespace std;


void showMenu(){
    cout << "-------Menu-------" << endl;
    cout << "|1. Check balance|" << endl;
    cout << "|2. Deposit      |" << endl;
    cout << "|3. Withdraw     |" << endl;
    cout << "|4. Transfer     |" << endl;
    cout << "|5. Terminate    |" << endl;
    cout << "-----------------" << endl;
}

int main(){



    int operation = 0;
    long long tAcc[5] = {2014245110, 3447588019, 432, 233, 492};
    double balance = 275060.27;
    double withdrawCharges = 7.25;
    double transferCharges = 10.75;
    double balanceCharges = 0.25;
    string name[5] = {"Sodiq Moshood", "Yusuf Shuaib", "Portable Baby", "Nana", "shuaib"};
    string bank[5] = {"Kuda", "FCMB", "ZAZU", "OGBA", "IDAN"};
    string receiverName = "default";
    string Bankname;



    do{
        showMenu();
        cout << "Select Operation: " ;
        cin >> operation;

        system("cls");

        switch(operation){
            case 1:
                cout << "Balance is $" << balance << endl;
                break;

            case 2:
                double deposit;
                cout << "Enter Deposit amount:-> ";
                cin >> deposit;
                balance = balance + deposit;
                cout << "Deposit successful balance: $" << balance << endl;
                break;
            
            case 3:
                double withdraw;
                double fixed;
                cout << "Note: This transaction incures charges of $" << withdrawCharges << endl;
                cout << "Enter withdraw amount:-> ";
                cin >> withdraw;
                fixed = balance - 57.25;
                if (withdraw > fixed){
                    cout << "Insufficient fund" << endl;
                } else{
                    cout << "You have successfully withdrawn" << endl;
                    double NewBalance = balance - withdrawCharges;
                    balance = NewBalance - withdraw;
                    cout << "Balance is $" << balance << endl;
                }
                break;
            
            case 4:
                double transfer;
                long long account;
                double checkBalance;
                int bankOperation;

                cout << "Note: This transaction incures charges of $" << transferCharges << endl;
                cout << "Enter transfer amount:-> ";
                cin >> transfer;

                cout << "Enter account number:-> ";
                cin >> account;

                cout << "-------BANK-------" << endl;
                cout << "|1. Kuda Bank    |" << endl;
                cout << "|2. FCMB         |" << endl;
                cout << "|3. Zazu Bank    |" << endl;
                cout << "|4. Ogba Bank    |" << endl;
                cout << "|5. Idan MFB     |" << endl;
                cout << "-----------------" << endl;

                cout << "Select option (1-5): " << endl;
                cin >> bankOperation;


                if (bankOperation == 1){
                    Bankname = bank[0];
                    if (account != tAcc[0]){
                        cout << "Invalid Bank" << endl;
                        break;
                    }
                } else if (bankOperation == 2){
                    Bankname = bank[1];
                    if (account != tAcc[1]){
                        cout << "Invalid Bank" << endl;
                        break;
                    }
                } else if (bankOperation == 3){
                    Bankname = bank[2];
                    if (account != tAcc[2]){
                        cout << "Invalid Bank" << endl;
                        break;
                    }
                } else if (bankOperation == 4){
                    Bankname = bank[3];
                    if (account != tAcc[3]){
                        cout << "Invalid Bank" << endl;
                        break;
                    }
                } else if (bankOperation == 5){
                    Bankname = bank[4];
                    if (account != tAcc[4]){
                        cout << "Invalid Bank" << endl;
                        break;
                    }
                } else{
                    cout << "Invalid operation" << endl;
                    break;
                }
                for (int i = 0; i < 5; i++){
                    if (tAcc[i] == account){
                        cout << "Account found!" << endl;
                        receiverName = name[i];
                        break;
                    }
                }
                if (receiverName == "default"){
                    cout << "account not found!" << endl;
                };
                char result;
                cout << "Are you sure you want to transfer to " << receiverName << " (Y/N): " ;
                cin >> result;
                if(result == 'N' || result == 'n'){
                    break;
                }else if (result == 'Y' || result == 'y'){
                    checkBalance = balance - transferCharges;
                    if (transfer > checkBalance){
                        cout << "Insufficient fund" << endl;
                    } else{
                        cout << "You have successfully transferred $" << transfer << " to " << receiverName << " " << Bankname << endl;
                        balance = checkBalance - transfer;
                        cout << "Balance is $" << balance << endl;
                    }
                }else{
                    cout << "Invalid operation" << endl;
                }
                
                break;
            default: 
                break;

        }

    } while (operation != 5);

    return 0;
}