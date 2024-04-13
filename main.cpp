#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class protocol {
    private:
        std::string sender;
        std::string receiver;
        std::string amount;

    public:
        protocol(std::string sender, std::string receiver, std::string amount) {
            this->sender = sender;
            this->receiver = receiver;
            this->amount = amount;
        }

        std::string showProtocol() {
            return sender + " paid " + receiver + " " + amount + "$";
        }
};

class Ledger {
    private:
        std::vector<protocol> protocols;

    public:
        void addProtocol(protocol p) {
            protocols.push_back(p);
        }

        void showProtocols() {
            for (int i = 0; i < protocols.size(); i++) {
                std::cout << protocols[i].showProtocol() << std::endl;
            }
        }
};

void addingProtocol(Ledger *ledger) {
    std::string sender;
   std::string receiver;
    std::string amount;

    std::cout << "enter sender name: ";
    std::cin >> sender;
    std::cout << "enter receiver name: ";
    std::cin >> receiver;
    std::cout << "enter amount: ";
    std::cin >> amount;

    protocol p(sender, receiver, amount);
    ledger->addProtocol(p);
}


int main() {
    Ledger ledger;

    bool cont = true;
    while(cont) {
        int choice;

        std::cout << "what would you like to do:-" << std::endl;
        std::cout << "  1)show protocols" << std::endl;
        std::cout << "  2)add a protocol" << std::endl;
        std::cout << "  3)exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "showing protocols" << std::endl;
                ledger.showProtocols();
                break;
            case 2:
                std::cout << "adding a protocol" << std::endl;
                addingProtocol(&ledger);
                break;
            case 3:
                std::cout << "exiting" << std::endl;
                cont = false;
                break;
            default:
                std::cout << "invalid choice" << std::endl;
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}
