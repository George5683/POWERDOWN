#include <string>

class remote{
    private:

    protected:
    std::string Brand;

    public:
        remote(std::string brandname);
        virtual ~remote();
        std::string getBrand() const;

};

class Samsung : public remote{
    private:

    public:
        Samsung();
        ~Samsung();
};

class LG : public remote{
    private:

    public:
        LG();
        ~LG();
};