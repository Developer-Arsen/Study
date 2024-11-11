#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class IDevice
{
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
    virtual std::string getDeviceType() const = 0;
};

class SmartDevice : public IDevice
{
protected:
    std::string m_deviceType;
    bool m_status;

public:
    SmartDevice() {};
    SmartDevice(const std::string &str)
    {
        m_deviceType = str;
        m_status = false;
    }

    void turnOn()
    {
    }
    void turnOff()
    {
    }
    bool isOn() const
    {
        return m_status;
    }

    std::string getDeviceType() const
    {
        return m_deviceType;
    }

    virtual void displayInfo() const = 0;
};

class Light : public SmartDevice
{

public:
    Light() : SmartDevice("Light")
    {
    }

    void turnOn()
    {
        m_status = true;
    }

    void turnOff()
    {
        m_status = false;
    }

    void displayInfo() const
    {
        std::string text{m_status ? "On" : "off"};
        cout << "Light is switched :" << text << endl;
    }
};

class Thermostat : public SmartDevice
{
private:
    double m_temp;
    double m_def_temp = 20;

public:
    Thermostat() {};
    ~Thermostat() {};

    void displayInfo() const
    {
        cout << "Temp is" << m_temp << endl;
    }

    void setTemp(double newVal)
    {
        m_temp = newVal;
    }

    void turnOn()
    {
        m_temp = m_def_temp;
        m_status = true;
    }

    void turnOff()
    {
        m_status = false;
    }
};

class Automat
{
private:
    std::vector<SmartDevice *> m_devices;

public:
    void addDevice(SmartDevice *device)
    {
        m_devices.push_back(device);
    }

    void turnOnAllDevices() const
    {
        for (size_t i = 0; i < m_devices.size(); ++i)
        {
            m_devices[i]->turnOn();
        }
    }

    void displayAllDevices() const
    {
        for (size_t i = 0; i < m_devices.size(); ++i)
        {
            m_devices[i]->displayInfo();
        }
    }
};

int main()
{
    Light *a = new Light();
    Thermostat *ther = new Thermostat();

    Automat automat;
    automat.addDevice(a);
    automat.addDevice(ther);
    automat.turnOnAllDevices();
    automat.displayAllDevices();

    int b = "val";
}