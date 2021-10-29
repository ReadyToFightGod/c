#ifndef UNTITLED6_DOP_H
#define UNTITLED6_DOP_H
#include <iostream>
#include <math.h>
class Figure{
public:
    virtual void Perimeter() = 0;
    virtual void Area() = 0;
    virtual void Figure_info() = 0;
};

class Ellipse: public Figure{
public:
    explicit Ellipse(const double& a, const double& b , const std::string& name): a(a), b(b), name(name) {}

    virtual void Figure_info() override{
        std::cout << "My name is "<< name << " and I am an Ellipse! My equation is (x/"
        << a << ")^2 + (y/" << b <<")^2 = 1" << std::endl;
    }
    virtual void Perimeter() override{
        std::cout << "My perimeter is: "<< 4 * (3.14 * a * b + a - b)/(a + b) << std::endl;
    }
    virtual void Area() override{
        std::cout << "My area is: " << 3.14 * a * b << std::endl;
    }
private:
    double a, b;
protected:
    std::string name;
};

class Circle: public Ellipse{
public:
    explicit Circle(const double& r, const std::string& name): r(r), Ellipse(r, r, name){}

    void Figure_info() final{
        std::cout << "I am "<< name << " and I am a Circle! My equation is x^2 + y^2 = 1\n "
                                       "My radius is "<< r << std::endl;
    }
    void Perimeter() final{
        std::cout<<"My perimeter is: "<<2 * 3.14 * r << std::endl;
    }
    void Area() final{
        std::cout << "My area is: "<<3.14 * r * r <<std::endl;
    }
private:
    double r;
};

class Polygon: public Figure{
public:
    explicit Polygon(const int& n,const std::string& name): n(n),name(name){}

    virtual void Figure_info() override{
        std::cout << "My name is "<< name<<" and I am a Polygon! I have " << n << " sides" <<std::endl;
    }
private:
    int n;
protected:
    std::string name;
};

class Triangle: public Polygon{
public:
    explicit Triangle(const double& a1, const double& a2, const double& a3,
                      const std::string& name): a1(a1),a2(a2),a3(a3), Polygon(3,name){}

    void Figure_info() final{
        std::cout << "I am " << name << " and I am a Triangle! My sides are equal to "<<
        a1 << " " << a2 << " " << a3 <<std::endl;
    }
    void Perimeter() final{
        std::cout << "My perimeter is: " << a1 + a2 + a3 << std::endl;
    }
    void Area() final{
        std::cout<< "My area is: "<< sqrt((a1+a2+a3)*(a1+a2-a3)*(a1-a2+a3)*(a2+a3-a1))/4 << std::endl;
    }
private:
    double a1, a2, a3;
};

class Quadrangle: public Polygon{
public:
    explicit Quadrangle(const double& a1, const double& a2,
                        const double& a3, const double& a4, const std::string& name): a1(a1),a2(a2),a3(a3),a4(a4),
                        Polygon(4,name){}
    virtual void Figure_info() override{
        std::cout << "Hi, I am "<<name<<" and I am a Quadrangle! "
                                        "My sides are equal to "<< a1 << ", "
                                        << a2 << ", " << a3 << ", " << a4 << std::endl;
    }
    virtual void Perimeter() final{
        std::cout << "My perimeter is: " << a1 + a2 + a3 + a4 << std::endl;
    }
    virtual void Area() final{
        std::cout<<"My area is: "<< sqrt((-a1+a2+a3+a4)*(a1+a2+a3-a4)*(a1+a2-a3+a4)*(a1-a2+a3+a4))/4 <<std::endl;
    }
protected:
    double a1, a2, a3, a4;
};

class Rectangle: public Quadrangle{
public:
    explicit Rectangle(const double& a1, const double& a2, const std::string& name):
    Quadrangle(a1, a2, a1, a2, name){}
    virtual void Figure_info() final{
        std::cout << "I am " << name << " and I am a Rectangle! "
                                        "My sides are equal to "<< a1 << ", " << a2 << std::endl;
    }
};

class Square: public Quadrangle{
public:
    explicit Square(const double& a1,const std::string& name): Quadrangle(a1, a1, a1, a1, name){}
    void Figure_info() final{
        std::cout << "I am " << name << " and I am a Square. My side is equal to " << a1 << std::endl;
    }
};
#endif //UNTITLED6_DOP_H
