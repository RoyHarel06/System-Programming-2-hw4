#include "Point.hpp"
#include <stdexcept>

namespace ariel
{
    Point::Point() {
        x_position = 0;
        y_position = 0;
    }
    Point::Point(double x_position, double y_position) : x_position(x_position), y_position(y_position) {
    }

    double Point::getX() const {
        return x_position;
    }
    double Point::getY() const {
        return y_position;
    }
    void Point::setX(double x_position) {
        this->x_position = x_position;
    }
    void Point::setY(double y_position) {
        this->y_position = y_position;
    }

    double Point::distance(Point other) const {
        return sqrt(pow(x_position - other.getX(), 2) + pow(y_position - other.getY(), 2));
    }

    string Point::print() const {
        return "(" + to_string(x_position) + "," + to_string(y_position) + ")";
    }

    const Point& Point::moveTowards(const Point& current, const Point& other, const double max_distance) {
        if (max_distance < 0)
            throw invalid_argument("Negative distance.");

        double current_distance = current.distance(other);
        if (current_distance <= max_distance)
            return other;

        double ratio = max_distance / current_distance;
        double new_x = current.getX() + ratio * (other.getX() - current.getX());
        double new_y = current.getY() + ratio * (other.getY() - current.getY());
        return Point(new_x, new_y);
    }
}