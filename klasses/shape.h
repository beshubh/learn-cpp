class Shape {
    public:
    virtual double area() const = 0;
};

class Circle: public Shape {
    public:
    Circle(double radius): _radius{radius} {};
    double area() const {
        return 3.14 * _radius * _radius;
    }
    private:
    double _radius;
};

class Rectangle: public Shape {
    public:
    Rectangle(double height, double width): _height{height}, _width{width} {};

    double area() const {
        return _width * _height;
    }
    private:
    double _width, _height;
};
