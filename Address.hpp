#ifndef ADDRESS_HPP
# define ADDRESS_HPP

# include <string>

class Address
{
    private:
        int _id;
        std::string     _address;
        std::string     _city;
        std::string     _province;
        unsigned int    _postal_code;
        Address();
    public:
        int         &getId();
        void        setId(int &id);
        std::string &getAddress();
        void        setAddress(std::string &address);
        std::string &getCity();
        void        setCity(std::string &city);
        std::string &getProvince();
        void        setProvince(std::string &province);
        std::string &getPostalCode();
        void        setPostalCode(std::string &postal_code);
        Address(int id, std::string address, std::string city, std::string province,
        std::string postal_code);
        std::string show();
};

#endif // ADDRESS_HPP
