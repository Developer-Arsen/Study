#include <iostream>

class Chair {
    public:
        virtual ~Chair() {}
        virtual void sit () const = 0;
};

class ModernChair : public Chair {
    public:
        void sit () const override {
            std::cout << "siting in modern chair" << std::endl;
        }
};

class ArtChair : public Chair {
    public:
        void sit () const override {
            std::cout << "siting in art chair" << std::endl;
        }
};

class Table {
    public:
        virtual ~Table() {}
        virtual void draw() const = 0;
};

class ModernTable : public Table {
    public:
        void draw() const override {
            std::cout << "drawing in modern table" << std::endl;
        }
};

class ArtTable : public Table {
    public:
        void draw() const override {
            std::cout << "drawing in Art table" << std::endl;
        }
};

class AbstractFactory {
    public:
        virtual ~AbstractFactory(){};
        virtual Chair* createChair() const = 0;
        virtual Table* createTable() const = 0;

        void logic() {
            Chair* chair  = createChair();
            Table* table  = createTable();

            chair->sit();
            table->draw();

            delete chair;
            delete table;
        }
};


class ModernFactory : public AbstractFactory {
    public:
        Chair * createChair() const override {
            return new ModernChair();
        }

        Table * createTable() const override {
            return new ModernTable();
        }
};


class ArtFactory : public AbstractFactory {
    public:
        Chair * createChair() const override {
            return new ArtChair();
        }

        Table * createTable() const override {
            return new ArtTable();
        }
};

int main () {

    AbstractFactory* factory = new ArtFactory();
    factory->logic();
}

