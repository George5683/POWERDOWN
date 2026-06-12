#include <string>

class remote{
    protected:
    std::string Brand;
    remote(std::string brandname);

public:
    virtual ~remote();
    virtual void TV_ON() = 0;
    virtual void TV_OFF() = 0;
    virtual void TV_VOL_UP() = 0;
    virtual void TV_VOL_DOWN() = 0;
    virtual void TV_CH_UP() = 0;
    virtual void TV_CH_DOWN() = 0;
    virtual void TV_MUTE() = 0;
    virtual void TV_0() = 0;
    virtual void TV_1() = 0;
    virtual void TV_2() = 0;
    virtual void TV_3() = 0;
    virtual void TV_4() = 0;
    virtual void TV_5() = 0;
    virtual void TV_6() = 0;
    virtual void TV_7() = 0;
    virtual void TV_8() = 0;
    virtual void TV_9() = 0;
    std::string getBrand() const;
};

class Samsung : public remote{
    private:

    public:
        Samsung();
        ~Samsung();

        void TV_ON() override;
        void TV_OFF() override;
        void TV_VOL_UP() override;
        void TV_VOL_DOWN() override;
        void TV_CH_UP() override;
        void TV_CH_DOWN() override;
        void TV_MUTE() override;
        void TV_0() override;
        void TV_1() override;
        void TV_2() override;
        void TV_3() override;
        void TV_4() override;
        void TV_5() override;
        void TV_6() override;
        void TV_7() override;
        void TV_8() override;
        void TV_9() override;

};

class LG : public remote{
    private:

    public:
        LG();
        ~LG();

        void TV_ON() override;
        void TV_OFF() override;
        void TV_VOL_UP() override;
        void TV_VOL_DOWN() override;
        void TV_CH_UP() override;
        void TV_CH_DOWN() override;
        void TV_MUTE() override;
        void TV_0() override;
        void TV_1() override;
        void TV_2() override;
        void TV_3() override;
        void TV_4() override;
        void TV_5() override;
        void TV_6() override;
        void TV_7() override;
        void TV_8() override;
        void TV_9() override;

};