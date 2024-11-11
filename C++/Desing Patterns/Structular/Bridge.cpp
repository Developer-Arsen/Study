#include <iostream>
#include <memory>

class Device
{
public:
    virtual void power() = 0;
    virtual void setVolume(int volume) = 0;
    virtual int getVolume() const = 0;
    virtual bool isPoweredOn() const = 0;
    virtual ~Device() = default;
};

class TV : public Device
{
    bool on = false;
    int volume = 50;

public:
    void power() override
    {
        on = !on;
        std::cout << "TV power: " << (on ? "ON" : "OFF") << std::endl;
    }

    void setVolume(int vol) override
    {
        volume = (vol >= 0 && vol <= 100) ? vol : volume;
        std::cout << "TV volume set to " << volume << std::endl;
    }

    int getVolume() const override
    {
        return volume;
    }

    bool isPoweredOn() const override
    {
        return on;
    }
};

class Radio : public Device
{
    bool on = false;
    int volume = 30;

public:
    void power() override
    {
        on = !on;
        std::cout << "Radio power: " << (on ? "ON" : "OFF") << std::endl;
    }

    void setVolume(int vol) override
    {
        volume = (vol >= 0 && vol <= 100) ? vol : volume;
        std::cout << "Radio volume set to " << volume << std::endl;
    }

    int getVolume() const override
    {
        return volume;
    }

    bool isPoweredOn() const override
    {
        return on;
    }
};

class RemoteControl
{
protected:
    std::shared_ptr<Device> device_;

public:
    RemoteControl(std::shared_ptr<Device> device) : device_(device) {}
    virtual void togglePower()
    {
        device_->power();
    }

    virtual void volumeUp()
    {
        device_->setVolume(device_->getVolume() + 10);
    }

    virtual void volumeDown()
    {
        device_->setVolume(device_->getVolume() - 10);
    }
};

class AdvancedRemote : public RemoteControl {
    public:
        AdvancedRemote(std::shared_ptr<Device> device) : RemoteControl(device) {}
    
    void mute () {
        std::cout << "Muting device." << std::endl;
        device_->setVolume(0);
    }
};

int main()
{
    std::shared_ptr<Device> tv = std::make_shared<TV>();

    RemoteControl* pult = new RemoteControl(tv);
    pult->togglePower();
    pult->volumeDown();
    pult->volumeUp();

    std::shared_ptr<Device> radio = std::make_shared<Radio>();
    AdvancedRemote* pult2 = new AdvancedRemote(radio);
    pult2->mute();

}