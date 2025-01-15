#include <iostream>
#include <string>
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    std::string withdraw(double amount) {
        if (amount > balance)//if withdrawal more than balance
        {
            return "withdrawal unsuccessful insufficient balance.\n";//return fail statement
        }
        balance -= amount;//take withdrawal from balance
        return "withdrawal succesful!, New blanace $: " + std::to_string(balance)+"\n";//returnn success statement
    }
};
class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }


    bool tempCheck(int tempLimit) 
    {
        if (currentTemperature < tempLimit) {
            return true;
        }
        else {
            return false;
        }
    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        if (isAvailable)//if books available
        {
            std::cout << "Book borrowed successfully." << std::endl;
            isAvailable = false;
        }
        else//if book isnt available
        {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }

    void returnBook() {
        isAvailable = true;
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        // Violates Tell, Don't Ask
        book.borrowBook();

    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        if (health > 0)//if player is alive
        {
            health -= damage;
            std::cout << "player took damage!\n";
        }
        else
            std::cout << "player has no health\n";//if player is daed
    }

    void useAmmo() {
        if (ammo > 0 && health > 0)//if player is alive and has ammo
        {
            std::cout << "Player attacked and used ammo." << std::endl;
            ammo--;
        }

        else if (health > 0)//if player is alive and doesnt have ammo
            std::cout<<"player has no ammo";
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        player.takeDamage(10);
        player.useAmmo();
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);

    // Violation of Tell, Don't Ask
    std::cout << account.withdraw(500);

    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    HeatingSystem heating;

    if (thermostat.tempCheck(20)) 
    {
        heating.turnOn();
    }
    else {
        heating.turnOff(); 
    }
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
