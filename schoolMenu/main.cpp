//Author's Name: Tobenna Nwosu
//Date: February 18, 2024
//Purpose: Verify student's identity, give student a menu to select food and drink(s) from Cafe, and confirm funds!


#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <windows.h>


using namespace std;

struct Student {
    string name;
    int id;
    string gradeLevel;
    double currentMoney;

};

//Student Information
unordered_map<string, int> verifyIdentity = { {"Toby Nwosu", 1630379} ,{"Alexis Perez",1795464},{"Nya Jackson",1246667},{"Chloe Decker",1354428} };
unordered_map<string, int>studGradeLvls = { {"Junior",1630379},{"Graduate",1795464},{"Freshman",1246667},{"Sophmore",1354428} };
unordered_map<double, int>studentFunds = { {300.54,1630379},{68.24,1795464},{99.68,1246667},{5.46,1354428} };

//Menu items organized into unordered hashmaps.
unordered_map<string, double>mainFoodList = { {"French Fries (LARGE)",4.50},{"French Fries (MEDIUM)",3.00},{"French Fries (SMALL)",2.00},{"Papa Johns- Pepporoni",5.00}
,{"Papa Johns- Spinach",5.00},{"Papa Johns- Sausage",5.00},{"Pasta",4.50},{"White Rice with Stew",4.00 }, {"Fried Rice",4.00 }
, { "Tater Tots",2.00 }, { "Hamburger",2.50 }, { "Hotdog",2.50 }};
unordered_map<string, double>drinksList = { {"Bottle of Water",0.50},{"Sprite",2.00},{"Coke",2.00},{"Ice Tea",1.50}
,{"Skim Milk",1.00},{"Almond Milk",1.00},{"Chocolate Milk",1.00},{"Fanta",2.00},{"Apple Juice",1.00} };
unordered_map<string, double>dessertList = { {"Vanilla Ice Cream",1.50},{"Chocolate Ice Cream",1.50},{"Strawberry Cake",1.50},{"Chocolate-chip cookie",1.00} };
unordered_map<string, double>mealComboList = { {"French Fries (LARGE), Hamburger, Coke",7.00},{"Papa Johns- Pepporoni, Apple Juice, Vanilla Ice Cream",6.00} };

//Checks whether the student's name is in the system. Also acts like a username (Common language to the public).
void studentCheckName(string& studName) {
    bool verificationName = false;

    while (verificationName == false) {
        cout << endl;
        cout << "Please enter your Full Name: "; getline(cin, studName); cout << endl;
        for (auto verifying : verifyIdentity) {
            if (verifying.first == studName) {
                verificationName = true;
                cout << "Student Name verified!" << endl;
                break;
            }
        }
        if (verificationName == false) {
            cout << "Name is not found please try again." << endl;
        }


    }
}
//Checks whether the student's ID is in the system. Also acts like a password (Private since ID's aren't told/displayed publicly).
void studentCheckId(int& studId) {
    bool verificationId = false;
    while (verificationId == false) {
        cout << endl;
        cout << "Please enter your student ID : "; cin >> studId; cout << endl;
        for (auto verifying : verifyIdentity) {
            if (verifying.second == studId) {
                verificationId = true;
                cout << "Student ID verified!" << endl;
                cout << endl;
                break;
            }
        }
        if (verificationId == false) {
            cout << "ID is not found please try again." << endl;
        }
    }
}
//Check the student's grade level.
void studentGradeLevels(int& studId, string& gradeLvl) {
    for (auto verifying : studGradeLvls) {
        if ((verifying.second)==studId) {
            gradeLvl = verifying.first;
            break;
        }
    }
}
//Find the student's funds.

//arrays are for making it easy to select options quicker with numbers and finding the value from the keys efficiently
string mainFoodArr[] = { "French Fries (LARGE)","French Fries (MEDIUM)","White Rice with Stew","Pasta","Papa Johns- Pepporoni","French Fries (SMALL)"
,"Papa Johns- Spinach","Papa Johns- Sausage", "Hotdog" ,"Fried Rice","Tater Tots","Hamburger"};
string drinksArr[] = { "Almond Milk","Bottle of Water","Chocolate Milk", "Skim Milk","Sprite","Coke", "Ice Tea","Fanta","Apple Juice" };
string dessertArr[] = { "Vanilla Ice Cream","Chocolate Ice Cream","Chocolate-chip cookie","Strawberry Cake" };
string mealComboArr[]={"French Fries (LARGE), Hamburger, Coke", "Papa Johns- Pepporoni, Apple Juice, Vanilla Ice Cream"};
vector<string>cart;
int menuReturn;

void studentMoney(int& studId, double& money) {
    for (auto verifying : studentFunds) {
        if ((verifying.second) == studId) {
            money = verifying.first;
            break;
        }
    }
}
//Displays a particular menu for the main food.
void mainFood(double& cost,int& menuReturn) {
    int list = 0;
    int pick;
    double itemPrice=0;
    int itemChoice;
    cout << endl;
    cout << "Here is the menu for our main food:" << endl;
    for (auto food : mainFoodList) {
        list++;
        cout << "\n\t\t\t [" << list << "] " << food.first << ": $";
        cout<<fixed<<setprecision(2) << setw(5)<<food.second << endl;
    }
    cout << endl;
    cout << "Would you like to select an item from this list? ('0' for No and '1'for Yes) "; cin>>pick; cout << endl;
    if (pick==1) {
        cout << "Please choose 1 item from the menu by typing in a number: " << endl;
        cin >> itemChoice;
        itemChoice = itemChoice - 1;
        cout << "Item Chosen: " << mainFoodArr[itemChoice] << endl;
        for (auto price : mainFoodList) {
            if (mainFoodArr[itemChoice] == price.first) {
                itemPrice = price.second;
                break;
            }
        }
        cout << "The price of this item is $" << fixed << setprecision(2) << itemPrice << ". Are you sure you want it? ('0' for No and '1'for Yes) ";cin>>pick; cout << endl;
        if (pick==1) {
            cost = itemPrice + cost;
            cout << endl;
            cart.push_back(mainFoodArr[itemChoice]);
            cout << "Item added to cart." << endl;
            cout << "Total Price: $" << fixed << setprecision(2) << cost << endl;
            cout << "Do you want anything else from this particular menu? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
            if (pick==1) {
                mainFood(cost,menuReturn);
            }
            else if (pick==0) {
                cout << "Understood, this menu will now close." << endl;
                menuReturn = 1;
            }
        }
        else if (pick==0) {
            cout << "Understood, this menu will now close." << endl;
            menuReturn = 1;
        }
    }
    else if (pick==0) {
        cout << endl;
        cout << "Ok. Heading back to Main Menu!" << endl;
        menuReturn = 1;
    }
}
//Displays a paricular menu for the drinks.
void drinks(double& cost, int& menuReturn) {
    int list = 0;
    int pick;
    double itemPrice = 0;
    int itemChoice;
    cout << endl;
    cout << "Here is the menu for our drinks:" << endl;
    for (auto food : drinksList) {
        list++;
        cout << "\n\t\t\t [" << list << "] " << food.first << ": $";
        cout << fixed << setprecision(2) << setw(5) << food.second << endl;
    }
    cout << endl;
    cout << "Would you like to select an item from this list? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
    if (pick == 1) {
        cout << "Please choose 1 item from the menu by typing in a number: " << endl;
        cin >> itemChoice;
        itemChoice = itemChoice - 1;
        cout << "Item Chosen: " << drinksArr[itemChoice] << endl;
        for (auto price : drinksList) {
            if (drinksArr[itemChoice] == price.first) {
                itemPrice = price.second;
                break;
            }
        }
        cout << "The price of this item is $" << fixed << setprecision(2) << itemPrice << ". Are you sure you want it? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
        if (pick == 1) {
            cost = itemPrice + cost;
            cout << endl;
            cart.push_back(drinksArr[itemChoice]);
            cout << "Item added to cart." << endl;
            cout << "Total Price: $" << fixed << setprecision(2) << cost << endl;
            cout << "Do you want anything else from this particular menu? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
            if (pick == 1) {
                drinks(cost, menuReturn);
            }
            else if (pick == 0) {
                cout << "Understood, this menu will now close." << endl;
                menuReturn = 1;
            }
        }
        else if (pick == 0) {
            cout << "Understood, this menu will now close." << endl;
            menuReturn = 1;
        }
    }
    else if (pick == 0) {
        cout << endl;
        cout << "Ok. Heading back to Main Menu!" << endl;
        menuReturn = 1;
    }
}
//Displays a particular menu for the desserts.
void desserts(double& cost, int& menuReturn) {
    int list = 0;
    int pick;
    double itemPrice = 0;
    int itemChoice;
    cout << endl;
    cout << "Here is the menu for our desserts:" << endl;
    for (auto food : dessertList) {
        list++;
        cout << "\n\t\t\t [" << list << "] " << food.first << ": $";
        cout << fixed << setprecision(2) << setw(5) << food.second << endl;
    }
    cout << endl;
    cout << "Would you like to select an item from this list? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
    if (pick == 1) {
        cout << "Please choose 1 item from the menu by typing in a number: " << endl;
        cin >> itemChoice;
        itemChoice = itemChoice - 1;
        cout << "Item Chosen: " << dessertArr[itemChoice] << endl;
        for (auto price : dessertList) {
            if (dessertArr[itemChoice] == price.first) {
                itemPrice = price.second;
                break;
            }
        }
        cout << "The price of this item is $" << fixed << setprecision(2) << itemPrice << ". Are you sure you want it? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
        if (pick == 1) {
            cost = itemPrice + cost;
            cout << endl;
            cart.push_back(dessertArr[itemChoice]);
            cout << "Item added to cart." << endl;
            cout << "Total Price: $" << fixed << setprecision(2) << cost << endl;
            cout << "Do you want anything else from this particular menu? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
            if (pick == 1) {
                desserts(cost, menuReturn);
            }
            else if (pick == 0) {
                cout << "Understood, this menu will now close." << endl;
                menuReturn = 1;
            }
        }
        else if (pick == 0) {
            cout << "Understood, this menu will now close." << endl;
            menuReturn = 1;
        }
    }
    else if (pick == 0) {
        cout << endl;
        cout << "Ok. Heading back to Main Menu!" << endl;
        menuReturn = 1;
    }
}
//Displays a particuar menu for the meal combos.
void mealCombo(double& cost, int& menuReturn) {
    int list = 0;
    int pick;
    double itemPrice = 0;
    int itemChoice;
    cout << endl;
    cout << "Here is the menu for our meal combos:" << endl;
    for (auto food : mealComboList) {
        list++;
        cout << "\n\t\t\t [" << list << "] " << food.first << ": $";
        cout << fixed << setprecision(2) << setw(5) << food.second << endl;
    }
    cout << endl;
    cout << "Would you like to select an item from this list? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
    if (pick == 1) {
        cout << "Please choose 1 item from the menu by typing in a number: " << endl;
        cin >> itemChoice;
        itemChoice = itemChoice - 1;
        cout << "Item Chosen: " << mealComboArr[itemChoice] << endl;
        for (auto price : mealComboList) {
            if (mealComboArr[itemChoice] == price.first) {
                itemPrice = price.second;
                break;
            }
        }
        cout << "The price of this item is $" << fixed << setprecision(2) << itemPrice << ". Are you sure you want it? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
        if (pick == 1) {
            cost = itemPrice + cost;
            cout << endl;
            cart.push_back(mealComboArr[itemChoice]);
            cout << "Item added to cart." << endl;
            cout << "Total Price: $" << fixed << setprecision(2) << cost << endl;
            cout << "Do you want anything else from this particular menu? ('0' for No and '1'for Yes) "; cin >> pick; cout << endl;
            if (pick == 1) {
                mealCombo(cost, menuReturn);
            }
            else if (pick == 0) {
                cout << "Understood, this menu will now close." << endl;
                menuReturn = 1;
            }
        }
        else if (pick == 0) {
            cout << "Understood, this menu will now close." << endl;
            menuReturn = 1;
        }
    }
    else if (pick == 0) {
        cout << endl;
        cout << "Ok. Heading back to Main Menu!" << endl;
        menuReturn = 1;
    }
}
//Student pays for the items.
void checkout(double& cost, Student& stud) {
    int question;
    int cartIndex = 1;
    int deleteIndex;
    cout << endl;
    cout << "This is the checkout room. Here, you can purchase your chosen items with your available funds." << endl;
    cout << "Of course, the transaction won't go through if the total cost is over your current funds." << endl;
    cout << "If they're over your funds, then you have the option to remove certain items from your cart." << endl;
    cout << "Feel free to head back over to the Main Menu if you wish to add more items to your cart." << endl;
    cout << "Here are the items you have chosen to purchase:" << endl;
    cout << endl;
    for (auto item : cart) {
        if (item != "") {
            cout << "\n\t\t\t [" << cartIndex << "] " << item << endl;
            cartIndex++;
        }
        else {
            break;
        }
    }
    cout << endl;
    cout << "Once again the total cost for the items is $" << fixed << setprecision(2) << cost << endl;
    cout << "Your current funds is $" << stud.currentMoney << endl;
    cout << "Would you like to finalize transaction ('1'), delete items from cart,('2'), or add more to cart('3')? "; cin >> question; cout << endl;
    if (question == 2) {
        double removePrice = 0;
        cout << "Type in what number associated to the item you would like to remove from the cart: " << endl; cin >> deleteIndex; cout << endl;
        cout << "New updated cart: " << endl;
        cartIndex = 1;
        string removeItem = cart[deleteIndex - 1];
        for (auto decreaseCost : mainFoodList) {
            if (removeItem == decreaseCost.first) {
                removePrice = decreaseCost.second;
            }
        }
        for (auto decreaseCost : drinksList) {
            if (removeItem == decreaseCost.first) {
                removePrice = decreaseCost.second;
            }
        }
        for (auto decreaseCost : dessertList) {
            if (removeItem == decreaseCost.first) {
                removePrice = decreaseCost.second;
            }
        }
        for (auto decreaseCost : mealComboList) {
            if (removeItem == decreaseCost.first) {
                removePrice = decreaseCost.second;
            }
        }
        cost = cost - removePrice;
        cart.erase(cart.begin() + (deleteIndex - 1));
        for (auto newCart : cart) {
            cout << "\n\t\t\t [" << cartIndex << "] " << newCart << endl;
            cartIndex++;
        }
        cout << "New total cost: $" << cost << endl;
        menuReturn = 1;
    }
    else if (question == 3) {
        menuReturn = 1;
    }
    else if (question == 1) {
        double balance = stud.currentMoney - cost;
        if (balance >= 0){
            system("Color A");
            cout << "Congratulation! Your transaction went through successfully. Your new available funds is $" << balance << endl;
            cout << "Thank you for dining at UT Dallas Cafe!" << endl;
        }
        else if (balance < 0) {
            cout << endl;
            cout << endl;
            system("Color C");
            cout << "Sorry, you don't have enough to purchase your items. You can edit your cart if you want to remove any items." << endl;
            checkout(cost, stud);
        }
    }
}
//Displays the main menu where students can select and purchase items with their money.
void mainMenu(double& cost,int& menuReturn,Student& stud) {
    menuReturn = 0;
    int choice;
    cout << "\n\t\t\t [1] Main Food";
    cout << "\n\t\t\t [2] Drinks";
    cout << "\n\t\t\t [3] Desserts";
    cout << "\n\t\t\t [4] Meal Combo";
    cout << "\n\t\t\t [5] Final Checkout";
    cout << endl;
    cout << "Please type in your menu choice: "; cin >> choice; cout << endl;
    if (choice == 1) {
        mainFood(cost,menuReturn);
        if (menuReturn == 1) {
            mainMenu(cost, menuReturn,stud);
        }
    }
    else if (choice == 2) {
        drinks(cost, menuReturn);
        if (menuReturn == 1) {
            mainMenu(cost, menuReturn,stud);
        }
    }
    else if (choice == 3) {
        desserts(cost, menuReturn);
        if (menuReturn == 1) {
            mainMenu(cost, menuReturn,stud);
        }
    }
    else if (choice == 4) {
        mealCombo(cost, menuReturn);
        if (menuReturn == 1) {
            mainMenu(cost, menuReturn,stud);
        }
    }
   else if (choice == 5) {
        checkout(cost, stud);
        if (menuReturn == 1) {
            mainMenu(cost, menuReturn, stud);
        }
    }
}

    
int main() {
        string studName, gradeLvl;
        int studId = 0;
        double money,cost=0;

        cout << "Hello and Welcome to UT Dallas Cafe!" << endl;
        cout << "Here, you can purchase food and drink(s) if you have the proper funds to do so!" << endl;
        cout << "Before you can select your choices, we would to verify your identity first." << endl;

        studentCheckName(studName);
        studentCheckId(studId);
        studentGradeLevels(studId, gradeLvl);
        studentMoney(studId, money);
        cout << "Both Student Name and ID have been verified!" << endl;

        Student stud = { studName,studId,gradeLvl,money};
        cout << endl;
        cout << "Student Name:        " << stud.name << endl;
        cout << "Student ID:          " << stud.id << endl;
        cout << "Current Grade Level: " << stud.gradeLevel << endl;
        cout << "Current Funds:       $" <<stud.currentMoney<< endl;

        cout << "Here at UT Dallas, our meals are considerably cheap and delicious!" << endl;
        cout << "You have a choice to pick the main food, desserts/snacks, drinks, or even a meal combo!" << endl;

        mainMenu(cost,menuReturn,stud);

}
