#include <iostream>

using namespace std;

class FoodOrder {
public:
    char name[30];
    int choice, pchoice, pchoice1, quantity, totalBill;

    // constructor to store totalBill to zero
    FoodOrder() : totalBill(0) {}

    void displayMenu() {
        cout << "\t\t\t----------QuickCravings Food Corner!-----------" << endl << endl;
        cout << "Please enter your name: ";


        cin.getline(name, 30);
        cout << "Hello " << name << endl;
        cout << "What would you like to order?" << endl << endl;
        // display the menu options
        cout << "\t\t\t\t--------Menu--------" << endl << endl;
        cout << "1) Pizzas" << endl;
        cout << "2) Burgers" << endl;
        cout << "3) Sandwich" << endl;
        cout << "4) Rolls" << endl;
        cout << "5) Biryani" << endl << endl;
        cout << "Please Enter your Choice: ";
        cin >> choice;
    }

    void orderPizza() {
        cout << "\n1) Meat Masala Pizza" << endl;
        cout << "2) Deep Sea Fantasy Pizza" << endl;
        cout << "3) Veggie Italiano" << endl;
        cout << "4) Meaty Onion Pizza" << endl;
        cout << "\nPlease Enter which Flavour would you like to have?:";
        cin >> pchoice;

        if (pchoice >= 1 && pchoice < 5) {
            cout << "\n1) Small Tk.250" << endl << "2) Regular Tk.500" << endl << "3) Large Tk.900" << endl;
            cout << "\nChoose Size Please:";
            cin >> pchoice1;

            if (pchoice1 >= 1 && pchoice1 <= 3) {
                cout << "\nPlease Enter Quantity: ";
                cin >> quantity;
                calculateTotalBill(choice, pchoice1);
                displayOrderDetails("Pizza");
            }
        }
    }

    void orderBurger() {
        cout << "\n1) Beef Burger Tk.180" << endl;
        cout << "2) Chicken Burger Tk.150" << endl;
        cout << "3) Zinger Burger Tk.160" << endl;
        cout << "\nPlease Enter which Burger you would like to have?: ";
        cin >> pchoice1;

        if (pchoice1 >= 1 && pchoice1 <= 3) {
            cout << "\nPlease Enter Quantity: ";
            cin >> quantity;
            calculateTotalBill(choice, pchoice1);
            displayOrderDetails("Burger");
        }
    }

    void orderSandwich() {
        cout << "\n1) Veg Sandwich Tk.240" << endl;
        cout << "2) Paneer Sandwich Tk.160" << endl;
        cout << "3) Cheese Sandwich Tk.100" << endl;
        cout << "\nPlease Enter which Sandwich you would like to have?:";
        cin >> pchoice1;

        if (pchoice1 >= 1 && pchoice1 <= 3) {
            cout << "\nPlease Enter Quantity: ";
            cin >> quantity;
            calculateTotalBill(choice, pchoice1);
            displayOrderDetails("Sandwich");
        }
    }

    void orderRoll() {
        cout << "\n1) Chicken Chatni Roll Tk.150" << endl;
        cout << "2) Veg Roll Tk.100" << endl;
        cout << "3) Chicken Mayo Roll Tk.120" << endl;
        cout << "\nPlease Enter which Roll you would like to have?: ";
        cin >> pchoice1;

        if (pchoice1 >= 1 && pchoice1 <= 3) {
            cout << "\nHow Many Rolls Do you want: ";
            cin >> quantity;
            calculateTotalBill(choice, pchoice1);
            displayOrderDetails("Roll");
        }
    }

    void orderBiryani() {
        cout << "\n1) Chicken Biryani Tk.160" << endl;
        cout << "2) Kacchi Biryani Tk.220" << endl;
        cout << "3) Beef Biryani Tk.140" << endl;
        cout << "\nPlease Enter which Biryani you would like to have?:";
        cin >> pchoice1;

        if (pchoice1 >= 1 && pchoice1 <= 3) {
            cout << "\nPlease Enter Quantity: ";
            cin >> quantity;
            calculateTotalBill(choice, pchoice1);
            displayOrderDetails("Biryani");
        }
    }

    void calculateTotalBill(int itemChoice, int sizeChoice) {
        switch (itemChoice) {
            case 1: // Pizza
                switch (sizeChoice) {
                    case 1: totalBill = 250 * quantity; break;
                    case 2: totalBill = 500 * quantity; break;
                    case 3: totalBill = 900 * quantity; break;
                    default: totalBill = 0;
                }
                break;
            case 2: // Burger
                switch (sizeChoice) {
                    case 1: totalBill = 180 * quantity; break;
                    case 2: totalBill = 150 * quantity; break;
                    case 3: totalBill = 160 * quantity; break;
                    default: totalBill = 0;
                }
                break;
            case 3: // Sandwich
                switch (sizeChoice) {
                    case 1: totalBill = 240 * quantity; break;
                    case 2: totalBill = 160 * quantity; break;
                    case 3: totalBill = 100 * quantity; break;
                    default: totalBill = 0;
                }
                break;
            case 4: // Roll
                switch (sizeChoice) {
                    case 1: totalBill = 150 * quantity; break;
                    case 2: totalBill = 100 * quantity; break;
                    case 3: totalBill = 120 * quantity; break;
                    default: totalBill = 0;
                }
                break;
            case 5: // Biryani
                switch (sizeChoice) {
                    case 1: totalBill = 160 * quantity; break;
                    case 2: totalBill = 220 * quantity; break;
                    case 3: totalBill = 140 * quantity; break;
                    default: totalBill = 0;
                }
                break;
            default: totalBill = 0;
        }
    }

    void displayOrderDetails(const char* item) {
        cout << "\t\t--------Your Order---------" << endl;
        cout << quantity << " " << item << endl;
        cout << "Your total bill is Tk." << totalBill << endl;
        cout << "Your order will be delivered in 30 minutes" << endl;
        cout << "Thank you for ordering from QuickCravings Food Corner!" << endl;
    }
};

int main() {
    char gotostart;
    do {
        FoodOrder order;
        order.displayMenu();

        switch (order.choice) {
            case 1: order.orderPizza(); break;
            case 2: order.orderBurger(); break;
            case 3: order.orderSandwich(); break;
            case 4: order.orderRoll(); break;
            case 5: order.orderBiryani(); break;
            default: break;
        }
        // if the user want to place another order
        cout << "Would you like to order anything else? Y / N:";
        cin >> gotostart;

    } while (gotostart == 'Y' || gotostart == 'y');

    return 0;
}
