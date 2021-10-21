#ifndef ADDRESS_HPP
# define ADDRESS_HPP

# include <string>

class Address
{
    private:
        int             id;
        std::string     address;
        std::string     city;
        std::string     province;
        unsigned int    postal_code;
        Address();
    public:
        int             &getId();
        void            setId(int &_id);
        std::string     &getAddress();
        void            setAddress(std::string &_address);
        std::string     &getCity();
        void            setCity(std::string &_city);
        std::string     &getProvince();
        void            setProvince(std::string &_province);
        unsigned int    &getPostalCode();
        void            setPostalCode(unsigned int &_postal_code);
        Address(int const &id, std::string const &address, std::string const &city, std::string const &province,
        unsigned int const &postal_code);
        std::string show();
};

#endif // ADDRESS_HPP
