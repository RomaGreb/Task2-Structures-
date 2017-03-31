#include "AnyType.h"

namespace ISXAnyType
{

AnyType::AnyType(): data_type(Types::UNDEFINED)
{
}

AnyType::AnyType(const AnyType& any_type_obj)
{
    data_type = any_type_obj.data_type;
    data = any_type_obj.data;
}

AnyType::AnyType(AnyType&& any_type_obj)
{
    this->data = std::move(any_type_obj.data);
    this->data_type = std::move(any_type_obj.data_type);
    any_type_obj.data_type = Types::UNDEFINED;
}

AnyType::AnyType(bool bool_var): data_type(Types::BOOL)
{
    data.bool_var = bool_var;
}

AnyType::AnyType(signed char signed_char_var): data_type(Types::SIGNED_CHAR)
{
    data.signed_char_var = signed_char_var;
}

AnyType::AnyType(unsigned char unsigned_char_var):data_type(Types::UNSIGNED_CHAR)
{
    data.unsigned_char_var = unsigned_char_var;
}

AnyType::AnyType(wchar_t wchar_t_var): data_type(Types::WCHAR_T)
{
    data.wchar_t_var = wchar_t_var;
}

AnyType::AnyType(short int short_int_var): data_type(Types::SHORT_INT)
{
    data.short_int_var = short_int_var;
}

AnyType::AnyType(unsigned short int unsigned_short_int_var): data_type(Types::UNSIGNED_SHORT_INT)
{
    data.unsigned_short_int_var = unsigned_short_int_var;
}

AnyType::AnyType(int int_var): data_type(Types::INT)
{
    data.int_var = int_var;
}

AnyType::AnyType(unsigned int unsigned_int_var): data_type(Types::UNSIGNED_INT)
{
    data.unsigned_int_var = unsigned_int_var;
}

AnyType::AnyType(long int long_int_var): data_type(Types::LONG_INT)
{
    data.long_int_var = long_int_var;
}

AnyType::AnyType(long long int long_long_int_var): data_type(Types::LONG_LONG_INT)
{
    data.long_long_int_var = long_long_int_var;
}

AnyType::AnyType(unsigned long int unsigned_long_int_var): data_type(Types::UNSIGNED_LONG_INT)
{
    data.unsigned_long_int_var = unsigned_long_int_var;
}

AnyType::AnyType(unsigned long long int unsigned_long_long_var): data_type(Types::UNSIGNED_LONG_LONG_INT)
{
    data.unsigned_long_long_int_var = unsigned_long_long_var;
}

AnyType::AnyType(float float_var): data_type(Types::FLOAT)
{
    data.float_var = float_var;
}

AnyType::AnyType(double double_var): data_type(Types::DOUBLE)
{
    data.double_var = double_var;
}

AnyType::AnyType(long double long_double_var): data_type(Types::LONG_DOUBLE)
{
    data.long_double_var = long_double_var;
}

AnyType::~AnyType()
{
}

void AnyType::Swap(AnyType& left, AnyType& right)
{
    std::swap(left.data_type, right.data_type);
    std::swap(left.data, right.data);
}

AnyType& AnyType::operator=(const AnyType& any_type_obj)
{
    if(this != &any_type_obj)
    {
        AnyType copy_obj(any_type_obj);
        Swap(copy_obj,*this);
    }
    return *this;
}

AnyType& AnyType::operator =(AnyType&& right)
{
    if(this != &right)
    {
        this->data = std::move(right.data);
        this->data_type = std::move(right.data_type);
        right.data_type = Types::UNDEFINED;
    }
    return *this;
}

const char* AnyType::getTypeName()const
{
    switch(data_type)
    {
        case (Types::BOOL): return "bool";
        case (Types::SIGNED_CHAR): return "signed char";
        case (Types::UNSIGNED_CHAR): return "unsigned char";
        case (Types::WCHAR_T): return "wchar_t";
        case (Types::SHORT_INT): return "short int";
        case (Types::UNSIGNED_SHORT_INT): return "unsigned short int";
        case (Types::INT): return "int";
        case (Types::UNSIGNED_INT): return "unsigned int";
        case (Types::LONG_INT): return "long int";
        case (Types::LONG_LONG_INT): return "long long int";
        case (Types::UNSIGNED_LONG_INT): return "unsigned long int";
        case (Types::UNSIGNED_LONG_LONG_INT): return "unsigned long long int";
        case (Types::FLOAT): return "float";
        case (Types::DOUBLE): return "double";
        case (Types::LONG_DOUBLE): return "long double";
        default: return "type undefined";
    }
}

bool AnyType::getBool()const
{
    if(data_type != Types::BOOL)
        throw Error();
    return data.bool_var;
}

signed char AnyType::getSignedChar()const
{
    if(data_type != Types::SIGNED_CHAR)
        throw Error();
    return data.signed_char_var;
}

unsigned char AnyType::getUnsignedChar()const
{
    if(data_type != Types::UNSIGNED_CHAR)
        throw Error();
    return data.unsigned_char_var;
}

wchar_t AnyType::getWchar_t()const
{
    if(data_type != Types::WCHAR_T)
        throw Error();
    return data.wchar_t_var;
}

short int AnyType::getShortInt()const
{
    if(data_type != Types::SHORT_INT)
        throw Error();
    return data.short_int_var;
}

unsigned short int AnyType::getUnsignedShortInt()const
{
    if(data_type != Types::UNSIGNED_SHORT_INT)
        throw Error();
    return data.unsigned_short_int_var;
}

int AnyType::getInt()const
{
    if(data_type != Types::INT)
        throw Error();
    return data.int_var;
}

unsigned int AnyType::getUnsignedInt()const
{
    if(data_type != Types::UNSIGNED_INT)
        throw Error();
    return data.unsigned_int_var;
}

long int AnyType::getLongInt()const
{
    if(data_type != Types::LONG_INT)
        throw Error();
    return data.long_int_var;
}

long long int AnyType::getLongLongInt()const
{
    if(data_type != Types::LONG_LONG_INT)
        throw Error();
    return data.long_long_int_var;
}

unsigned long int AnyType::getUnsignedLongInt()const
{
    if(data_type != Types::UNSIGNED_LONG_INT)
        throw Error();
    return data.unsigned_long_int_var;
}

unsigned long long int AnyType::getUnsignedLongLongInt()const
{
    if(data_type != Types::UNSIGNED_LONG_LONG_INT)
        throw Error();
    return data.unsigned_long_long_int_var;
}

float AnyType::getFloat()const
{
    if(data_type != Types::FLOAT)
        throw Error();
    return data.float_var;
}

double AnyType::getDouble()const
{
    if(data_type != Types::DOUBLE)
        throw Error();
    return data.double_var;
}

long double AnyType::getLongDouble()const
{
    if(data_type != Types::LONG_DOUBLE)
        throw Error();
    return data.long_double_var;
}

std::ostream& operator<<(std::ostream& os, const AnyType& any_type_obj)
{
    os << any_type_obj.getTypeName() << ' ';
    switch(any_type_obj.getType())
    {
        case (Types::BOOL): return os << any_type_obj.data.bool_var;
        case (Types::SIGNED_CHAR): return os << any_type_obj.data.signed_char_var;
        case (Types::UNSIGNED_CHAR): return os << any_type_obj.data.unsigned_char_var;
        case (Types::WCHAR_T): return os << any_type_obj.data.wchar_t_var;
        case (Types::SHORT_INT): return os << any_type_obj.data.short_int_var;
        case (Types::UNSIGNED_SHORT_INT): return os << any_type_obj.data.unsigned_short_int_var;
        case (Types::INT): return os << any_type_obj.data.int_var;
        case (Types::UNSIGNED_INT): return os << any_type_obj.data.unsigned_int_var;
        case (Types::LONG_INT): return os << any_type_obj.data.long_int_var;
        case (Types::UNSIGNED_LONG_INT): return os << any_type_obj.data.unsigned_long_int_var;
        case (Types::FLOAT): return os << any_type_obj.data.float_var;
        case (Types::DOUBLE): return os << any_type_obj.data.double_var;
        case (Types::LONG_DOUBLE): return os << any_type_obj.data.long_double_var;
        default: return os << "Cannot show data";
    }
}

}

