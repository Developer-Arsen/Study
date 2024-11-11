
#include <iostream>
#include <vector>

class User;

class IChatMediator {
    public:
        virtual void sendMessage(const std::string&, const User&) = 0;
        virtual void addUser(User* ) = 0;
};

class User {
    std::string name_;
    IChatMediator& mediator_;

    public:
        User(IChatMediator& mediator, const std::string& name) : mediator_(mediator) , name_(name) {}
        virtual void reciveMessage(const std::string&) const = 0;

        void sendMessage(const std::string& msg)  {
            std::cout << name_ << " sends " << msg << std::endl;

            mediator_.sendMessage(msg, *this);
        }


        std::string getName() const {
            return name_;
        }
};

class ConcreteUser : public User {
    public:
        ConcreteUser(IChatMediator& mediator, const std::string& name) : User(mediator, name) {}

        void reciveMessage(const std::string& msg) const override {
            std::cout << getName() << " recived " << msg << std::endl;
        } 
};

class ChatRoom : public IChatMediator {
    std::vector<User*> users;
    public:
        void addUser(User* obj) override {
            users.push_back(obj);
        }

        void sendMessage(const std::string& msg, const User& sender) {
            for (User * user : users) {
                if (user != &sender) {
                    user->reciveMessage(msg);
                }
            }
        }
};

int main() {
    ChatRoom * room = new ChatRoom();

    User* ars = new ConcreteUser(*room, "Ars");
    User* blo = new ConcreteUser(*room, "blo");

    room->addUser(ars);
    room->addUser(blo);

    ars->sendMessage("hello");
}

