#pragma once
#include<ostream>
#include<exception>

namespace ISXAnyType
{

enum class Types
{
    UNDEFINED = -1,
    BOOL=0,
    UNSIGNED_CHAR=1,
    SIGNED_CHAR=2,
    WCHAR_T=3,
    SHORT_INT=4,
    UNSIGNED_SHORT_INT=5,
    INT=6,
    UNSIGNED_INT=7,
    LONG_INT=8,
    LONG_LONG_INT=9,
    UNSIGNED_LONG_INT=10,
    UNSIGNED_LONG_LONG_INT=11,
    FLOAT=12,
    DOUBLE=13,
    LONG_DOUBLE=14
};
class Error: public std::exception
{
public:
    virtual const char* what() const throw(){return "Cannot lead to type";}
};
class AnyType
{
private:
    union Type
    {
        bool bool_var;
        unsigned char unsigned_char_var;
        signed char signed_char_var;
        wchar_t wchar_t_var;
        short int short_int_var;
        unsigned short int unsigned_short_int_var;
        int int_var;
        unsigned int unsigned_int_var;
        long int long_int_var;
        long long int long_long_int_var;
        unsigned long int unsigned_long_int_var;
        unsigned long long int unsigned_long_long_int_var;
        float float_var;
        double double_var;
        long double long_double_var;
    };
    Type data;
    Types data_type;

 public:
    AnyType();
    AnyType(bool bool_var);
    AnyType(unsigned char unsigned_char_var);
    AnyType(signed char signed_char_var);
    AnyType(wchar_t wchar_t_var);
    AnyType(short int short_int_var);
    AnyType(unsigned short int unsigned_short_int_var);
    AnyType(int int_var);
    AnyType(unsigned int unsigned_int_var);
    AnyType(long int long_int_var);
    AnyType(unsigned long int unsigned_long_int_var);
    AnyType(long long int long_long_int_var);
    AnyType(unsigned long long int unsigned_long_long_int_var);
    AnyType(float float_var);
    AnyType(double double_var);
    AnyType(long double long_double_var);
    AnyType(const AnyType& any_type_obj);
    AnyType(AnyType&& any_type_obj);
    ~AnyType();

    AnyType& operator=(const AnyType& any_type_obj);
    AnyType& operator=(AnyType&& any_type_obj);
    friend std::ostream& operator<<(std::ostream& os, const AnyType& any_type_obj);

    static void Swap(AnyType& left, AnyType& right);

    bool getBool()const;
    unsigned char getUnsignedChar() const;
    signed char getSignedChar()const;
    wchar_t getWchar_t()const;
    short int getShortInt()const;
    unsigned short int getUnsignedShortInt()const;
    int getInt()const;
    unsigned int getUnsignedInt()const;
    long int getLongInt()const;
    long long int getLongLongInt()const;
    unsigned long int getUnsignedLongInt()const;
    unsigned long long int getUnsignedLongLongInt()const;
    float getFloat()const;
    double getDouble()const;
    long double getLongDouble()const;

    Types getType()const {return data_type;}
    const char* getTypeName()const;
};

}
