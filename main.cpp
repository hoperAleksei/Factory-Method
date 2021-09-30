#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

enum COLOR {
    RED,
    GREEN,
    BLUE,
    BLACK,
    GRAY,
    WHITE,
    YELLOW,
    ORANGE,
};

string getColor(COLOR color) {
    switch (color) {
        case COLOR::RED:
            return "RED";
        case COLOR::GREEN:
            return "GREEN";
        case COLOR::BLUE:
            return "BLUE";
        case COLOR::BLACK:
            return "BLACK";
        case COLOR::GRAY:
            return "GRAY";
        case COLOR::WHITE:
            return "WHITE";
        case COLOR::YELLOW:
            return "YELLOW";
        case COLOR::ORANGE:
            return "ORANGE";
    }
}

enum CATEGORY {
    basketball,
    football,
    volleyball,
    tennis,
    athletic,
};

string getCategory(CATEGORY category) {
    switch (category) {
        case CATEGORY ::basketball:
            return "basketball";
        case CATEGORY ::football:
            return  "football";
        case CATEGORY ::volleyball:
            return "volleyball";
        case CATEGORY ::tennis:
            return "tennis";
        case CATEGORY ::athletic:
            return "athletic";
    }
}

class Sneakers {
    string firm;
    string model;
    CATEGORY category;
    unsigned short prise;
    COLOR color;
public:
    Sneakers(const string &firm, const string &model, CATEGORY category, COLOR color, unsigned short prise) :
    firm(firm), model(model), category(category), color(color), prise(prise) {
    }

    const string &getFirm() const {
        return firm;
    }

    const string &getModel() const {
        return model;
    }

    CATEGORY getCategory1() const {
        return category;
    }

    COLOR getColor() const {
        return color;
    }

    string getDescription() const {
        return firm + " " + model + " " + ::getCategory(category) + " " + ::getColor(color) + " " + to_string(prise);
    }

    static Sneakers *createBasketballNikeLebron() {
        return new Sneakers("Nike", "Lebron Soldier", CATEGORY::basketball, COLOR::YELLOW, 12000);
    }

    static Sneakers *createFootballAdidasMercurial() {
        return new Sneakers("Adidas", "Mercurial", CATEGORY::football, COLOR::RED, 4000);
    }

    static Sneakers *createVolleyballAsicsNetburner() {
        return new Sneakers("Asics", "Netburner", CATEGORY::volleyball, COLOR::GREEN, 6000);
    }
};

class SneakersList {
private:
    vector<const Sneakers *> sneakers;
public:
    void add(Sneakers &goods) {
        sneakers.push_back(&goods);
    }

    void print() {
        unsigned short size = sneakers.size();
        if (size == 0)
            cout << "Ваша корзинка заполнена.";
        else
            for (unsigned short i = 0; i < size; i++)
                cout << i+1 << ". " << sneakers[i]->getDescription() << endl;
    }
};

int main() {
    SneakersList sneakersList;

    sneakersList.add(*Sneakers::createBasketballNikeLebron());
    sneakersList.add(*Sneakers::createFootballAdidasMercurial());
    sneakersList.add(*Sneakers::createVolleyballAsicsNetburner());

    sneakersList.print();
}