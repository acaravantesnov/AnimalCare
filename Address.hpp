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
        Address(int const &_id, std::string const &_address, std::string const &_city, std::string const &_province,
        unsigned int const &_postal_code);
        std::string show();
};

#endif // ADDRESS_HPP
