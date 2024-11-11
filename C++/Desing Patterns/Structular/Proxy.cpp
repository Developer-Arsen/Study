#include <iostream>
#include <memory>

class IImage {
public:
    virtual void display() = 0;
    virtual ~IImage() = default;
};

class RealImage : public IImage {
    std::string filename_;
    public:
        RealImage(const std::string& filename) : filename_(filename) {
            loadFromDisk();
        };


        void display () override {
            std::cout << "Displaying " << filename_ << std::endl;
        }

    private:
    void loadFromDisk() {
        std::cout << "Loading " << filename_ << " from disk..." << std::endl;
    }
};

class ProxyImage : public IImage {
    std::string filename_;
    std::unique_ptr<IImage> realImage;

    public:
        ProxyImage(const std::string& filename) : filename_(filename) {}

        void display() override {
            if (!realImage) {
                realImage = std::make_unique<RealImage>(filename_);
            }
            realImage->display();
        }
};

int main() {
    std::unique_ptr<IImage> image = std::make_unique<ProxyImage>("sample.jpg");

    // Image will be loaded from disk only when display is called
    std::cout << "Calling display for the first time:" << std::endl;
    image->display();

    std::cout << "\nCalling display for the second time:" << std::endl;
    image->display();  // Image won't be loaded again

    return 0;
}